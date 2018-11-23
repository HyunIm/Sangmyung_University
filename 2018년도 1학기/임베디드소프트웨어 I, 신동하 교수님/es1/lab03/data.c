// ======================================================================
// File: data.c
// Author : 임현 (201511054@sangmyung.kr)
// Since : 2018 - 04 - 10
// ======================================================================

#include <uart.h>

// ======================================================================

extern unsigned int _bss_start, _bss_end;

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
  // Section data
  UART_printf("==================================================\n");
  UART_printf("Section data:\n");

  UART_printf("&i=%x,\t\t i=%x\n", &i, i);	// 전역 변수 i의 주소 및 값
  UART_printf("&j=%x,\t\t j=%x\n", &j, j);	// 전역 변수 j의 주소 및 값

  // Section bss
  UART_printf("==================================================\n");
  UART_printf("Section bss:\n");

  // bss section의 시작 및 끝 주소 출력
  UART_printf("_bss_start=%x,\t _bss_end=%x\n", _bss_start, _bss_end);
  // 전역 변수 array[0], array[1023]의 주소 출력
  UART_printf("&array[0]=%x,\t &array[1023]=%x\n", &array[0], &array[1023]);
  // 전역 변수 array[0], array[1]의 값 출력
  UART_printf("array[0]=%d,\t\t array[1]=%d\n", array[0], array[1]);
  // 전역 변수 array[1022], array[1023]의 값 출력
  UART_printf("array[1022]=%d,\t\t array[1023]=%d\n", array[1022], array[1023]);

  UART_printf("==================================================\n");

  fun1();
  fun2();

  return 0;
}

// Memory map에서 section lab data와 lab bss는 0x82000000부터 0xA0000000까지
// section text와 rodata를 다 쓰고 쓰여지기 때문에 820011ac부터 시작하는 것이
// 올바른 결과 입니다
// 또한 c언어 표준에서 초기화 되지 않은 전역 변수는 모두 0으로 초기화 되므로
// 0이 출력되는 것이 올바른 결과 입니다.

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
