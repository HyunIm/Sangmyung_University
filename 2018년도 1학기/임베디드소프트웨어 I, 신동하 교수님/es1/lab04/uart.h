// ======================================================================
// File: uart.h
// Note that only UART1 of BeagleBone is used here!
// ======================================================================

#ifndef _UART_H_
#define _UART_H_

int UART_getc(void);		// Read a character from UART
int UART_getc_noblock(void);	// Read a character from UART (no bloking)
unsigned int UART_gethex(void);	// Read 8 characters hexadecimal number
char *UART_gets(char *str);	// Read a line

int UART_putc(int c);		// Write a character to UART
int UART_puts(const char *s);	// Write a string to UART
void UART_clear(void);		// Write VT100 clear screen string to UART
void UART_goto(int x, int y);	// Write a string to go to VT100 screen at (x,y)
int UART_sprintf(char *out, const char *format, ...);	// sprintf()
int UART_printf(const char *format, ...);	// printf()

#endif

// ======================================================================
