// ======================================================================
// File: text.c
// Author : 임현 (201511054@sangmyung.kr)
// Since : 2018 - 04 - 10
// ======================================================================

#include <uart.h>

// ======================================================================

extern unsigned int _start;

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
  // Section text
  UART_printf("==================================================\n");
  UART_printf("Section text:\n");

  UART_printf("&_start=%x\n", &_start);	// text section의 시작 주소 출력
  UART_printf("main=%x\n", main);	// 함수 main의 시작 주소 출력
  UART_printf("fun1=%x\n", fun1);	// 함수 fun1의 시작 주소 출력
  UART_printf("fun2=%x\n", fun2);	// 함수 fun2의 시작 주소 출력

  // Section rodata
  UART_printf("==================================================\n");
  UART_printf("Section rodata:\n");

  UART_printf("hello=%x,\t *hello=%s\n", hello, hello);	// char *hello 시작 주소 및 값 출력 
  UART_printf("bye=%x,\t *bye=%s\n", bye, bye);	// char *bye 시작 주소 및 값 출력

  UART_printf("==================================================\n");

  fun1();
  fun2();

  return 0;
}

// Memory map이 0x82000000부터 0xA0000000까지 lab text 영역부터 채워지므로 82000000부터 채워지는 것이 맞습니다.
// 또한 text 영역 다음 영역은 rodata 영역이므로 section rodata도 올바르게 출력 되었습니다.

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
