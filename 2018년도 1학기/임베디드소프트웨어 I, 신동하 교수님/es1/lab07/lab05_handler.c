// ======================================================================
// File: handlers.c
// Author : 임현 (201511054@sangmyung.kr)
// Since : 2018 - 05 - 01
// ======================================================================

#include <uart.h>

// ======================================================================

// 현재 모드의 CPSR을 보고 알아내는 함수
char *get_current_mode(void);
// prefetch abort interrupt의 pc값을 저장하는 외부 변수 (exception.c에 있음)
extern unsigned int prefetch_abort_pc_save;

// ======================================================================
// exception handler for undefined instruction

void handle_undefined_instruction(unsigned int *sp, unsigned int spsr)
{
  // exception이 발생한 곳의 PC 값
  // *(sp + 13) - 1 해준 이유
  // 	-> (stmfd  sp!, {r0-r12, lr}) 즉 lr값은 r0-r12까지 전부 더 한
  //	   *(sp + 13)에 위치해있고, 그 lr에서 +4에 위치되어있는 값이 pc값
  // (unsigned int *)을 적어준 이유 : 강제 형 변환
  unsigned int * pc = (unsigned int *)*(sp + 13) - 1;
  // exception이 발생한 곳의 instruction 값 (즉 pc가 가르키는 메모리에 저장된 값)
  unsigned int inst = *pc;

  // 발생한 exception 이름을 출력하고, 현재 mode를 CPSR을 보고 알아내어 출력
  UART_printf("Undefined instruction, mode=%s\n", get_current_mode());

  // exception 발생 시 저장된 LR 및 SPSR과 exception이 발생한 곳의 PC 및 instruction 값 출력
  // lr = pc + 1인 이유
  //	-> pc + 1 = *(sp + 13) 이기 때문
  //	   즉, 스택에 14번째 저장되어 있는 값
  UART_printf("lr=%08x, spsr=%08x, pc=%8x, inst=%8x\n", pc + 1, spsr, pc, inst);
}

// ======================================================================
// exception handler for software interrupt

void handle_software_interrupt(unsigned int *sp, unsigned int spsr)
{
  unsigned int * pc = (unsigned int *)*(sp + 13) - 1;
  unsigned int inst = *pc;
  // SWI instruction의 인수 값
  // inst와 0x00ffffff를 & 해준 이유
  //	-> inst의 형식이 앞 2글자를 제외하고 인수를 표현하기 때문
  unsigned int arg = (inst & 0x00ffffff);

  UART_printf("Software interrupt, mode=%s\n", get_current_mode());

  UART_printf("lr=%08x, spsr=%08x, pc=%8x, inst=%8x, arg=%d\n", pc + 1, spsr, pc, inst, arg);
}

// ======================================================================
// exception handler for prefetch abort

void handle_prefetch_abort(unsigned int *sp, unsigned int spsr)
{
  unsigned int * pc = (unsigned int *)*(sp + 13) - 1;
  unsigned int * new_lr = (unsigned int *)prefetch_abort_pc_save + 4;

  UART_printf("Prefetch abort, mode=%s\n", get_current_mode());

  UART_printf("lr=%08x, spsr=%08x, pc=%08x, new lr=%8x\n", pc + 1, spsr, pc, new_lr);

  // lr에 new_lr 값을 넣어줌
  *(sp + 13) = (unsigned int)new_lr;
}

// ======================================================================
// exception handler for data abort

void handle_data_abort(unsigned int *sp, unsigned int spsr)
{
  // Data abort는 abort된 instruction 주소 +8이지만 -1만 해준 이유
  // 	-> asm코드에서 이미 lr = lr - 4를 해줬음
  unsigned int * pc = (unsigned int *)*(sp + 13) - 1;
  unsigned int inst = *pc;

  UART_printf("Data abort, mode=%s\n", get_current_mode());

  UART_printf("lr=%08x, spsr=%08x, pc=%8x, inst=%8x\n", pc + 1, spsr, pc, inst);
}

// ======================================================================
// exception handler for interrupt

void handle_irq(unsigned int *sp, unsigned int spsr)
{
  UART_printf("IRQ, mode=%s\n", get_current_mode());
}

// ======================================================================
// exception handler for fast interrupt

void handle_fiq(unsigned int *sp, unsigned int spsr)
{
  UART_printf("FIQ, mode=%s\n", get_current_mode());
}

// ======================================================================

char *get_current_mode(void)
{
	unsigned int mode;

	// save cpsr to mode
	asm volatile ("	mrs	%0, cpsr":"=r"(mode):);

	mode = mode & 0x0000001f;
				// M[4:0]	Mode
	if (mode == 0x10)	// 0b10000	User
		return "usr";
	else if (mode == 0x11)	// 0b10001	FIQ
		return "fiq";
	else if (mode == 0x12)	// 0b10010	IRQ
		return "irq";
	else if (mode == 0x13)	// 0b10011	Supervisor
		return "svc";
	else if (mode == 0x17)	// 0b10111	Abort
		return "abt";
	else if (mode == 0x1b)	// 0b11011	Undefined
		return "und";
	else if (mode == 0x1f)	// 0b11111	System
		return "sys";
	else
		return "err";
}

// ======================================================================
