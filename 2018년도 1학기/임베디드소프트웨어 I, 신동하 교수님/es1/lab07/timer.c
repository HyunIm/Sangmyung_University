// ======================================================================
// File: timer.c
// ======================================================================

#include <uart.h>
#include "handlers.h"

// ======================================================================

extern volatile unsigned int clock;

// ======================================================================

extern char *get_current_mode(void);
extern void TIMER_init(void);
extern void TIMER_enable(void);
extern void TIMER_disable(void);

// ======================================================================

int main(int argc, char *argv[])
{
  char input[80];

  for (;;) {
    UART_printf("========================================\n");
    UART_printf("Timer Interrupt (%s mode)\n", get_current_mode());
    UART_printf("========================================\n");
    UART_printf("1. Initialize timer1\n");
    UART_printf("2. Enable timer1\n");
    UART_printf("3. Disable timer1\n");
    UART_printf("4. Print clock\n");
    UART_printf("5. Quit\n");
    UART_printf("Select one: ");

    UART_gets(input);
    UART_printf("\n");
    if ((input[0] == '1') && (input[1] == '\0')) {	// 1. Initialize timer1
      UART_printf("clock=%d\n", clock);
      TIMER_init();
      clock = 0;
    } else if ((input[0] == '2') && (input[1] == '\0')) {	// 2. Enable timer1
      UART_printf("clock=%d\n", clock);
      TIMER_enable();
    } else if ((input[0] == '3') && (input[1] == '\0')) {	// 3. Disable timer1
      TIMER_disable();
      UART_printf("clock=%d\n", clock);
    } else if ((input[0] == '4') && (input[1] == '\0')) {	// 4. Print clock
      UART_printf("clock=%d\n", clock);
    } else if ((input[0] == '5') && (input[1] == '\0')) {	// 5. Quit
      TIMER_disable();
      break;
    } else {
      UART_printf("Wrong selection!\n");
    }
    UART_printf("\n");
  }

  return 0;
}

// ======================================================================
