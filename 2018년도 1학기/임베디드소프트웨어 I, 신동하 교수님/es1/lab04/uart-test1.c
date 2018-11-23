// ======================================================================
// File: uart-test1.c
// ======================================================================

#include "uart.h"

// ======================================================================

int main(void)
{
  unsigned int x;
  char buf[512];

  UART_puts("If you type a character, it will be printed: ");
  UART_gets(buf);
  UART_putc((int) buf[0]);
  UART_printf("\n");

  UART_puts("If you type a hexa-decimal number, it will be printed: ");
  x = UART_gethex();
  UART_printf("%08x\n", x);

  UART_puts("If you type a line of characters, it will be printed: ");
  UART_gets(buf);
  UART_printf("%s\n", buf);

  return 0;
}

// ======================================================================
