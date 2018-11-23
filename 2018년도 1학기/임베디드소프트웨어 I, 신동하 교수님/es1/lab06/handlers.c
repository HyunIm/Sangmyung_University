// ======================================================================
// File: handlers.c
// ======================================================================

#include <uart.h>

// ======================================================================

char *get_current_mode(void);
extern void get_and_print_vbar(void);

// ======================================================================
// exception handler for undefined instruction

void handle_undefined_instruction(unsigned int *sp, unsigned int spsr)
{
  ...

  UART_printf("Undefined instruction, mode=%s\n", get_current_mode());

  ...
}

// ======================================================================
// exception handler for software interrupt

void handle_software_interrupt(unsigned int *sp, unsigned int spsr)
{
  get_and_print_vbar();

  return;
}

// ======================================================================
// exception handler for prefetch abort

void handle_prefetch_abort(unsigned int *sp, unsigned int spsr)
{
  ...

  UART_printf("Prefetch abort, mode=%s\n", get_current_mode());

  ...
}

// ======================================================================
// exception handler for data abort

void handle_data_abort(unsigned int *sp, unsigned int spsr)
{
  ...

  UART_printf("Data abort, mode=%s\n", get_current_mode());

  ...
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
  ...
}

// ======================================================================
