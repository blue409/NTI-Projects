#ifndef		RCC_INT_H
#define		RCC_INT_H
#include "RCC_reg.h"

void MRCC_voidInit(void);
ErrorStatus MRCC_enumSetPeripheralClock(uint8 Copy_u8PeripheralBus , uint8 Copy_u8PeripheralName , uint8 Copy_u8PeripheralState );

typedef enum{   //pass this in Copy_u8PeripheralName
	DMA1EN_ID,
	DMA2EN_ID,
	SRAMEN_ID,

}RCC_u8PeripheralName_AHB;

//typedef enum{   //pass this in Copy_u8PeripheralName
//
//}RCC_u8PeripheralName_APB1;

typedef enum{   //pass this in Copy_u8PeripheralName
	AFIOEN_ID,
	IOPAEN_ID=2,
	IOPBEN_ID,
	IOPCEN_ID,
	IOPDEN_ID,
	IOPEEN_ID,
	IOPFEN_ID,
	IOPGEN_ID,
	ADC1EN_ID,
	ADC2EN_ID,
	TIM1EN_ID,
	SPI1EN_ID,
	TIM8EN_ID,
	USART1EN_ID,
	ADC3EN_ID,
	TIM9EN_ID=19,
	TIM10EN_ID,
	TIM11EN_ID,

}RCC_u8PeripheralName_APB2;


#define		AHB										1
#define		APB1									2
#define		APB2									3

/*       RCC_CR Register bits       */
#define     CR_HSION                                0
#define     CR_HSIRDY                               1
#define     CR_HSEON                                16
#define     CR_HSERDY                               17
#define     CR_PLLON                                24
#define     CR_PLLRDY                               25

/*       RCC_CFGR Register bits       */
#define     CFGR_PLLSRC                             16
#define     CFGR_PLLXTPRE                           17

#define		RCC_ENABLE								1
#define		RCC_DISABLE								2
#define		RCC_RESET								3

#define		GPIOA									2
#define		GPIOB									3
#define		GPIOC									4

#define		HSI										1										
#define		HSE										2										
#define		PLL_HSI_DIVIDED_BY_2					3							
#define		PLL_HSE									4		
#define		PLL_HSE_DIVIDED_BY_2					5
#define		HSEPYPASS								6
#define		PLL										7


#define		NO_CLOCK_FACTOR							0  
#define		DIVIDED_BY_2							1 	
#define		MULTIPLY_BY_2							2		
#define		MULTIPLY_BY_3							3		
#define		MULTIPLY_BY_4							4		
#define		MULTIPLY_BY_5							5
#define		MULTIPLY_BY_6							6	
#define		MULTIPLY_BY_7							7		
#define		MULTIPLY_BY_8							8								
#define		MULTIPLY_BY_9							9							
#define		MULTIPLY_BY_10							10							
#define		MULTIPLY_BY_11							11							
#define		MULTIPLY_BY_12							12							
#define		MULTIPLY_BY_13							13							
#define		MULTIPLY_BY_14							14							
#define		MULTIPLY_BY_15							15							
#define		MULTIPLY_BY_16							16	

#endif
