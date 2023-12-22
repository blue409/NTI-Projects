/*
 * ext.h
 *  Description:Header file for the AVR External Interrupts driver
 *  Created on: Oct 27, 2023
 *  Author:     Menna Sayed
 *****************************************************************************/

#include "dio.h"
#include <avr/interrupt.h>

#ifndef EXT_H_
#define EXT_H_

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum{Int0,Int1,Int2}INTNUM;

typedef enum{LOW_Level,IOC,FALLING_Edge,RISING_Edge}SenseMode;

typedef struct{
	INTNUM INT_num;
	SenseMode Mode;   /*value from 0..to..7  corresponds to definit prescaler value*/

}EXTINT_ConfigType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

//void __vector_1(void) __attribute__((signal , used));

void EXTI_Init(const EXTINT_ConfigType*  Config_ptr);
void EXTI_Enable(uint8 int_num);
void EXTI_Disable(uint8 int_num);
void EXTI_SetCallBack(void(*ptrf)(void));

#endif /* EXT_H_ */
