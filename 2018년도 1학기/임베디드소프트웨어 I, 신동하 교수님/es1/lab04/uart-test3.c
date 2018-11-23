// ======================================================================
// File: uart-test3.c
// ======================================================================

#include "uart.h"

// ======================================================================

int main(void)
{
  char *ptr = "Hello world!";
  char *np = 0;
  int i = 5;
  unsigned int bs = sizeof(int) * 8;
  int mi;
  char buf[80];

  mi = (1 << (bs - 1)) + 1;
  UART_printf("%s\n", ptr);
  UART_printf("%s is null pointer\n", np);
  UART_printf("%d = 5\n", i);
  UART_printf("%d = - max int\n", mi);
  UART_printf("char %c = 'a'\n", 'a');
  UART_printf("hex %x = ff\n", 0xff);
  UART_printf("hex %02x = 00\n", 0);
  UART_printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
  UART_printf("%d %s(s)%", 0, "message");
  UART_printf("\n");
  UART_printf("%d %s(s) with %%\n", 0, "message");
  UART_sprintf(buf, "justif: \"%-10s\"\n", "left");
  UART_printf("%s", buf);
  UART_sprintf(buf, "justif: \"%10s\"\n", "right");
  UART_printf("%s", buf);
  UART_sprintf(buf, " 3: %04d zero padded\n", 3);
  UART_printf("%s", buf);
  UART_sprintf(buf, " 3: %-4d left justif.\n", 3);
  UART_printf("%s", buf);
  UART_sprintf(buf, " 3: %4d right justif.\n", 3);
  UART_printf("%s", buf);
  UART_sprintf(buf, "-3: %04d zero padded\n", -3);
  UART_printf("%s", buf);
  UART_sprintf(buf, "-3: %-4d left justif.\n", -3);
  UART_printf("%s", buf);
  UART_sprintf(buf, "-3: %4d right justif.\n", -3);
  UART_printf("%s", buf);

  return 0;
}

// ======================================================================
