// ======================================================================
// File: tasks-statistic.c
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
void TaskStatDisp(void);

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

  OSStatInit();

  for (i = 0; i < N_TASKS; i++) {
	  TaskData[i] = '0' + i;
	  OSTaskCreate(Task, (void *)&TaskData[i], &TaskStk[i][TASK_STK_SIZE - 1], i + 11);
  }

  UART_clear();

  while(201511054) {
	  UART_goto(0, 0);
	  UART_puts("LAB-08: tasks-statistics.c");

	  TaskStatDisp();

	  OSTimeDlyHMSM(0, 0, 1, 0);
  }
}

// ======================================================================

void Task(void *pdata)
{
  INT8U err;

  while(201511054) {
	  OSSemPend(RandomSem, 0, &err);
	  UART_goto(myrandom(80), myrandom(20) + 2);
	  UART_putc(*(char *)pdata);
	  OSSemPost(RandomSem);

	  OSTimeDly(5);
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

void TaskStatDisp(void)
{
  UART_goto(0, 23);

  UART_puts("#Tasks: ");
  UART_printf("%d", OSTaskCtr);

  UART_puts(", CPU Usage(%): ");
  UART_printf("%d", OSCPUUsage);

  UART_puts(", #CtxSW/Sec: ");
  UART_printf("%d", OSCtxSwCtr);
  OSCtxSwCtr = 0;
}

// ======================================================================
