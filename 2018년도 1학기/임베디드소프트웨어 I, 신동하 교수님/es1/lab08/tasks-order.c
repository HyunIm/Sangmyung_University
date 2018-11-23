// ======================================================================
// File: tasks-order.c
// Author : 임현 (201511054@sangmyung.kr)
// Since : 2018 - 05 - 22
// ======================================================================

#include <includes.h>
#include <uart.h>

// ======================================================================

#define N_TASKS		10
#define TASK_STK_SIZE	512

// ======================================================================

OS_STK TaskStk[N_TASKS][TASK_STK_SIZE];
OS_STK TaskStartStk[TASK_STK_SIZE];

char TaskData[N_TASKS];

OS_EVENT *RandomSem;

// ======================================================================

void TaskStart(void *data);
void Task(void *data);
unsigned short myrandom(unsigned short);

// ======================================================================

int main(void)
{
  OSInit();

  RandomSem = OSSemCreate(1);

  OSTaskCreate(TaskStart, (void *) 0, &TaskStartStk[TASK_STK_SIZE - 1], 10);

  OSStart();

  return 0;
}

// ======================================================================

void TaskStart(void *pdata)
{
  unsigned char i;

  TIMER_enable();		// The first Task should call this.

  for (i = 0; i < N_TASKS; i++) {
	  TaskData[i] = i;
	  OSTaskCreate(Task, (void *)&TaskData[i], &TaskStk[i][TASK_STK_SIZE - 1], i + 11);
  }

  UART_clear();

  while(201511054) {
	  UART_goto(0, 0);
	  UART_puts("LAB-08: tasks-order.c");

	  OSTimeDlyHMSM(0, 0, 1, 0);
  }
}

// ======================================================================

void Task(void *pdata)
{
  INT8U err;

  while(201511054) {
	  OSSemPend(RandomSem, 0, &err);
	  UART_goto(0, *(char *)pdata + 2);
	  UART_printf("task=%d, x=%02d, y=%02d\n", *(char *)pdata, myrandom(80), myrandom(20));
	  OSSemPost(RandomSem);
	  
	  OSTimeDlyHMSM(0, 0, 1, 0);
  }
}

// ======================================================================

unsigned short myrandom(unsigned short n)
{
  static unsigned int rand = 0;

  rand = rand * 1103515245 + 12345;
  return (unsigned short) ((rand / 65536) % n);
}

// ======================================================================
