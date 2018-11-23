// ======================================================================
// File: swi.c
// ======================================================================

#include <uart.h>

// ======================================================================

void svc_to_usr_mode(void);
void get_and_print_vbar(void);
extern char *get_current_mode(void);

// ======================================================================

int main(int argc, char *argv[])
{
  char input[80];

  svc_to_usr_mode();            // We start at usr mode.

  for (;;) {
    UART_printf("========================================\n");
    UART_printf("SWI Programming (mode=%s)\n", get_current_mode());
    UART_printf("========================================\n");
    UART_printf("1. Get VBAR\n");
    UART_printf("2. Get VBAR via SWI\n");
    UART_printf("3. Quit\n");
    UART_printf("Select one: ");

    UART_gets(input);
    UART_printf("\n");
    if ((input[0] == '1') && (input[1] == '\0')) {	// 1. on usr mode
      get_and_print_vbar();
    } else if ((input[0] == '2') && (input[1] == '\0')) {	// 2. via SWI
      asm volatile ("	swi	0");
    } else if ((input[0] == '3') && (input[1] == '\0')) {	// 3. Quit
      UART_printf("Can't return to u-boot from usr mode!\n");
    } else {
      UART_printf("Wrong selection!\n");
    }
    UART_printf("\n");
  }

  return 0;
}

// ======================================================================

void svc_to_usr_mode(void)
{
  ...
}

// ======================================================================

void get_and_print_vbar(void)
{
  ...
}

// ======================================================================
