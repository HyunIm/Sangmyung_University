// ======================================================================
// File: os_timer.h
// ======================================================================

#ifndef _OS_TIMER_H_
#define _OS_TIMER_H_

void TIMER_init(void);
void TIMER_enable(void);
void TIMER_disable(void);

void OS_CPU_IRQ_ISR_Handler(void);
void OS_CPU_FIQ_ISR_Handler(void);

#endif

// ======================================================================
