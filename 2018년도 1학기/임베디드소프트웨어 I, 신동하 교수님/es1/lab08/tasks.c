// ======================================================================
// File: tasks.c
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
  /**
    * @title : OSTaskCreate(void (*task)(void *pd), void *pdata, OS_STK *ptos, INT8U prio)
    * @param : 
    	- task : 수행할 태스크에 대응하는 함수로 이 함수의 return 값의 type은 void이고 인수의 type은 void * 이다.
	- pdata : 태스크 함수의 인수이다. type은 void * 이다.
	- ptos : 태스크 스택의 top 주소이다.
	- prio : 태스크의 우선순위이다.
    */
  OSTaskCreate(TaskStart, (void *) 0, &TaskStartStk[TASK_STK_SIZE - 1], 10);

  OSStart();

  return 0;
}

// ======================================================================

void TaskStart(void *pdata)
{
  INT8U i;

  TIMER_enable();		// The first Task should call this.

  for (i = 0; i < N_TASKS; i++) {
	  TaskData[i] = '0' + i;
	  OSTaskCreate(Task, (void *)&TaskData[i], &TaskStk[i][TASK_STK_SIZE - 1], i + 11);
  }

  UART_clear();

  while(201511054) {
	  // UART_goto 함수
	  UART_goto(0, 0);
	  // UART_printf(const char *format, ...)
	  UART_puts("LAB-08: tasks.c");

	  // OSTimeDlyHMSM(INT8U hours, INT8U minutes, INT*U seconds, INT8U milli)
	  // 이 태스크를 1초 지연시킴
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

	  // 이 태스크를 5 ticks 만큼 지연시킴
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
