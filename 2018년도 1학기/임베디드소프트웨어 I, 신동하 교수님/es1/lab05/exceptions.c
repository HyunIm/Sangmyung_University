// ======================================================================
// File: exceptions.c
// ======================================================================

#include <uart.h>

// ======================================================================

unsigned int prefetch_abort_pc_save;
extern char *get_current_mode(void);

// ======================================================================

int main(int argc, char *argv[])
{
  char input[80];

  for (;;) {
    UART_printf("========================================\n");
    UART_printf("Exceptions (mode=%s)\n", get_current_mode());
    UART_printf("========================================\n");
    UART_printf("1. Undefined instruction\n");
    UART_printf("2. Software interrupt\n");
    UART_printf("3. Prefetch abort\n");
    UART_printf("4. Data abort\n");
    UART_printf("5. Quit\n");
    UART_printf("Select one: ");

    UART_gets(input);
    UART_printf("\n");
    if ((input[0] == '1') && (input[1] == '\0')) {	// 1. Undefined instruction
      asm volatile ("	mcr	p0, #0, r0, c0, c0, #0");
    } else if ((input[0] == '2') && (input[1] == '\0')) {	// 2. Software interrupt
      asm volatile ("	swi	7");
    } else if ((input[0] == '3') && (input[1] == '\0')) {	// 3. Prefetch abort
      asm volatile ("	mov	%0, pc":"=r" (prefetch_abort_pc_save):);
      asm volatile ("   mov     pc, #0");
      asm volatile ("   nop");
      asm volatile ("   nop");
      asm volatile ("   nop");
      asm volatile ("   nop");
    } else if ((input[0] == '4') && (input[1] == '\0')) {	// 4. Data abort
      unsigned int data_abort_address = 0;
      asm volatile ("	ldr	%0, [%0, #0x0]"::"r" (data_abort_address));
    } else if ((input[0] == '5') && (input[1] == '\0')) {	// 5. Quit
      break;
    } else {
      UART_printf("Wrong selection!\n");
    }
    UART_printf("\n");
  }

  return 0;
}

// ======================================================================
