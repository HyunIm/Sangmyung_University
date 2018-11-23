// ======================================================================
// File: sync-delay.c
// Author : 임현 (201511054@sangmyung.kr)
// Since : 2018 - 06 - 05
// ======================================================================

#include <includes.h>
#include <uart.h>

// ======================================================================

#define N_TASKS		3
#define TASK_STK_SIZE	512

// ======================================================================

OS_STK TaskStk[N_TASKS][TASK_STK_SIZE];

int var1, var2;
int sum;

// ======================================================================

void Task1(void *pdata);
void Task2(void *pdata);
void Task3(void *pdata);

// ======================================================================

int main(void)
{
  OSInit();

  OSTaskCreate(Task1, (void *) 0, &TaskStk[0][TASK_STK_SIZE - 1], 11);
  OSTaskCreate(Task2, (void *) 0, &TaskStk[1][TASK_STK_SIZE - 1], 12);
  OSTaskCreate(Task3, (void *) 0, &TaskStk[2][TASK_STK_SIZE - 1], 13);

  OSStart();

  return 0;
}

// ======================================================================

void Task1(void *pdata)
{
  TIMER_enable();		// The first Task should call this.

  UART_clear();
  UART_printf("Hexa-decimal adder! (using delay)\n\n");
  
  while(201511054) {
	  UART_puts("? ");
	  var1 = UART_gethex();
	  UART_puts("? ");
	  var2 = UART_gethex();
	  
	  OSTimeDly(10);
  }
}

// ======================================================================

void Task2(void *pdata)
{
  while(201511054) {
	  sum = var1 + var2;
	  
	  OSTimeDly(10);
  }
}

// ======================================================================

void Task3(void *pdata)
{
  while(201511054) {
	  UART_printf("0x%x + 0x%x = 0x%x\n\n", var1, var2, sum);
	  
	  OSTimeDly(10);
  }
}

// ======================================================================
