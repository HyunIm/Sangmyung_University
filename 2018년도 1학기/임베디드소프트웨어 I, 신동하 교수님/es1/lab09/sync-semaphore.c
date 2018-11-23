// ======================================================================
// File: sync-semaphore.c
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

OS_EVENT *Sem1;
OS_EVENT *Sem2;
OS_EVENT *Sem3;

// ======================================================================

void Task1(void *pdata);
void Task2(void *pdata);
void Task3(void *pdata);

// ======================================================================

int main(void)
{
  OSInit();

  Sem1 = OSSemCreate(1);
  Sem2 = OSSemCreate(1);
  Sem3 = OSSemCreate(1);

  OSTaskCreate(Task1, (void *) 0, &TaskStk[0][TASK_STK_SIZE - 1], 11);
  OSTaskCreate(Task2, (void *) 0, &TaskStk[1][TASK_STK_SIZE - 1], 12);
  OSTaskCreate(Task3, (void *) 0, &TaskStk[2][TASK_STK_SIZE - 1], 13);

  OSStart();

  return 0;
}

// ======================================================================

void Task1(void *pdata)
{
  INT8U err;

  TIMER_enable();

  UART_clear();
  UART_printf("Hexa-decimal adder! (using semaphores)\n\n");
  
  while(201511054) {
	  OSSemPend(Sem3, 0, &err);
	  UART_puts("? ");
	  var1 = UART_gethex();
	  UART_puts("? ");
	  var2 = UART_gethex();
	  OSSemPost(Sem1);
  }

}

// ======================================================================

void Task2(void *pdata)
{
  INT8U err;

  while(201511054) {
	  OSSemPend(Sem1, 0, &err);
	  sum = var1 + var2;
	  OSSemPost(Sem2);
  }
}

// ======================================================================

void Task3(void *pdata)
{
  INT8U err;

  while(201511054) {
	  OSSemPend(Sem2, 0, &err);
	  UART_printf("0x%x + 0x%x = 0x%x\n\n", var1, var2, sum);
	  OSSemPost(Sem3);
  }
}

// ======================================================================
