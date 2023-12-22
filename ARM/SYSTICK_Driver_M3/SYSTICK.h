#ifndef _SYSTICK_INT_H_
#define _SYSTICK_INT_H_
#include "Systick_priv.h"

#define SYSTICK_ENABLE   0x00000001
#define SYSTICK_DISABLE  0xFFFFFFFE

#define OK       0
#define NOT_OK   1

#define SYSTICK_CLK_AHB  	   0x00000004
#define SYSTICK_CLK_AHB_DIV_8  0x00000000
#define SYSTICK_CLEAR_COUNTER  0x000000


#define SYSTICK_TICK_INT_ENABLE  0x00000002
#define SYSTICK_TICK_INT_DISABLE 0x00000000

typedef void (*systickcbf_t ) (void);
//void SysTick_Handler(void) __attribute__((interrupt));

uint8 SYSTICK_Init(void);
uint8 SYSTICK_Start(void);
uint8 SYSTICK_Stop(void);
void SYSTICK_SetCallback(systickcbf_t cbf);
uint8 SYSTICK_SetTime_ms(uint32 time_ms,uint32 clk);
uint8 SYSTICK_SetTime_us(uint32 time_us,uint32 clk);
//uint8 SYSTICK_SetPrescale (uint32 prescale);

#endif 
