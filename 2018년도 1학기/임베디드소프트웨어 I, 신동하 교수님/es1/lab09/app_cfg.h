/*
*********************************************************************************************************
*
*                                             EXAMPLE CODE
*
*                          (c) Copyright 2003-2006; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*
*               Knowledge of the source code may NOT be used to develop a similar product.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                       APPLICATION CONFIGURATION
*
*                                             ARM 1176JZF-S
*
* Filename      : app_cfg.h
* Version       : V1.00
* Programmer(s) : Jean J. Labrosse
*********************************************************************************************************
*/

#ifndef __APP_CFG_H__
#define __APP_CFG_H__

/*
*********************************************************************************************************
*                                       ADDITIONAL uC/MODULE ENABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                            TASK PRIORITIES
*********************************************************************************************************
*/

#define  OS_TASK_TMR_PRIO             3
#define  APP_TASK_PROBE_PRIO          4
#define  APP_TASK_GRAPH_PRIO          5
#define  APP_TASK_START_PRIO          6
#define  APP_TASK_STACKS_PRIO         7
#define  APP_TASK_FACTORIAL_PRIO      8


/*
*********************************************************************************************************
*                                            TASK STACK SIZES
*********************************************************************************************************
*/

#define  APP_TASK_START_STK_SIZE     200
#define  APP_TASK_GRAPH_STK_SIZE     200
#define  APP_TASK_STACKS_STK_SIZE    200
#define  APP_TASK_FACTORIAL_STK_SIZE 200




#endif
