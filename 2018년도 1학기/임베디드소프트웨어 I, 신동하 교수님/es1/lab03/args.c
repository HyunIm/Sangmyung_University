// ======================================================================
// File: args.c
// Author : 임현 (201511054@sangmyung.kr)
// Since : 2018 - 04 - 10
// ======================================================================

#include <uart.h>

// ======================================================================

char *hello = "Hello!";		// The string is in rodata section.
char *bye = "Bye!";		// The string is in rodata section.

unsigned int i = 0x12345678;	// i is in data section.
unsigned int j = 0x90abcdef;	// j is in data section.

unsigned int array[1024];	// array[1024] is in bss section.

// ======================================================================

int fun1(void);			// function fun1 that main calls.
int fun2(void);			// function fun2 that main calls.

// ======================================================================

int main(int argc, char *argv[])
{
  int i;	// for 문을 위한 지역 변수 선언

  // Arguments
  UART_printf("==================================================\n");
  UART_printf("Arguments:\n");

  // printf는 UART 함수 사용
  UART_printf("argc=%d\n", argc);	// 명령행 인수 개수 출력
  for (i = 0; i < argc; i++)	// 배열의 시작은 0이니 0부터 argc-1까지 출력
	  UART_printf("argv[%d]=%s\n", i, argv[i]);

  UART_printf("==================================================\n");

  fun1();
  fun2();

  return 7;	// 정수 7을 return
}

// u-boot에서 main으로 Argument를 보내줌

// ======================================================================

int fun1(void)
{
  int x[1000];

  x[0] = 0;
  x[1] = x[0];

  return 0;
}

// ======================================================================

int fun2(void)
{
  int y[2000];

  y[0] = 0;
  y[1] = y[0];

  return 0;
}

// ======================================================================
