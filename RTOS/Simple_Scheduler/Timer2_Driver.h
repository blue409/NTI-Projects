/*
 * Timer2_Driver.c
 *
 * Author: dell
* AVR
 *  Timer2_Driver.h
 *  Description:This driver for timer 0 and supports two modes compare mode and normal mode
 *  Created on:  Nov 19, 2023
 *  Author: Menna Sayed
 **********************************************************************************************************/

#ifndef TIMER2_DRIVER_H_
#define TIMER2_DRIVER_H_

#include "std_types.h"
#include "dio.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define F_CPU         16000000

typedef enum
{
	normal_2,compare_2
}Mode;

typedef enum
{
   no_clock,F_1,F_8,F_64,F_256,F_1024
}Prescaler;
typedef struct
{

	Mode mode;
	uint8 initial_val;
	uint8 compare_val;
	Prescaler presc;
}config_struc;                      /*To be used with Async function (Interrupt)*/

typedef struct
{

	Mode mode;
	uint8 initial_val;
	uint8 compare_val;
//	Prescaler presc;  //specify it in the #define below and it will reflect in start_sync func
}config_struc_sync;

#define  Presc_sync2    F_64

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void Timer2_init_Async(config_struc*);

void Timer2_init_sync(config_struc_sync*);

void Timer2_setCallBack(void(*ptr_func)(void));

void Timer2_DeInit(void);

void start_synch_2(uint8 presc);              /*only used with init_synch (for timer with polling) */

void Delay_ms_sync_2(uint32 time);            /*this func called in the main.c...only used with init_synch (for timer with polling) */



#endif /* TIMER2_DRIVER_H_ */
