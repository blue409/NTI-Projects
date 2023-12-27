/*
 * ADC.c
 *
 *  Created on: Oct 2, 2021
 *  Author: Menna Sayed
 *
 ***********************************************************************************/

#include "ADC.h"
#include "common_macros.h"//aktby .h
#include "LM_35.h"


void ADC_init(const ADC_ConfigType* Config_ptr){

	ADMUX=0;
	switch(Config_ptr->ref_volt)
	{
	case 3:                   /*internal vref..2.56v*/
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
	case 0:                    /* Aref...External voltage*/
		break;
	case 1:                    /*avcc .. 5v*/
		SET_BIT(ADMUX,REFS0);
		break;
	}
	ADCSRA =0;
	switch(Config_ptr->Prescaler)            //selecting the prescaler
	{
	case 0:
		break;
	case 1:
		SET_BIT(ADCSRA,ADPS0);
		break;
	case 2:
		SET_BIT(ADCSRA,ADPS1);
		break;
	case 3:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		break;
	case 4:
		SET_BIT(ADCSRA,ADPS2);
		break;
	case 5:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS2);
		break;
	case 6:
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
	case 7:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
	}
	SET_BIT(ADCSRA,ADEN);   //ADC enable
	CLEAR_BIT(ADCSRA,ADIE);  //to disable interrupt

}
uint16 ADC_readChannel(uint8 ch_num){

ch_num &= 0x07;                /*for making sure that the entered no is only 3 bits*/
ADMUX &= 0xE0;                  /*for clearing the first 5 bits in the reg */
ADMUX |= ch_num;                /*inserting channel num in admux reg*/
SET_BIT(ADCSRA,ADSC);           /*START CONVERSION*/
while(BIT_IS_CLEAR(ADCSRA,ADIF));   /*polling till the flag is set*/
SET_BIT(ADCSRA,ADIF);            /*for clearing the flag after conversion*/
return ADC;                      /*to read the value after the conversion from adc data reg.*/
}

void ADC_readChannel_INT(uint8 ch_num){
	ch_num &= 0x07;                /*for making sure that the entered no is only 3 bits*/
	ADMUX &= 0xE0;                  /*for clearing the first 5 bits in the reg */
	ADMUX |= ch_num;                /*inserting channel num in admux reg*/
	SET_BIT(ADCSRA,ADSC);           /*START CONVERSION*/

}


void ADC_StartConversion(void)
{
	SET_BIT(ADCSRA,ADSC);           /*START CONVERSION*/
}

void ADC_InterruptEnable(void)
{
	SET_BIT(ADCSRA,ADIE);       //to enable interrupt

}

void ADC_InterruptDisable(void)
{
	CLEAR_BIT(ADCSRA,ADIE);      //to disable interrupt
}

void __vector_16(void)
{
	CLEAR_BIT(ADCSRA,ADIE);      //to disable interrupt
 /* reading to be put on LCD */
	DIO_togglePin(PORTB,PIN7_ID);
	_delay_ms(1000);
	LCD_GoTo(2,1);
	 _delay_ms(2);
	 LCD_SendString("LDR : ");
	 LCD_integerTostring((1023-ADC)/10);
	 LCD_SendChar('%');
//	 LCD_GoTo(0,1);
//	 _delay_ms(2);
//	 LCD_SendString("TEMP : ");
//	 LCD_integerTostring(LM35_GetTemperature());
	 _delay_ms(4000);
	 SET_BIT(ADCSRA,ADIF);       /*for clearing the flag after conversion*/
	 SET_BIT(ADCSRA,ADIE);       //to enable interrupt
	 SET_BIT(ADCSRA,ADSC);           /*START CONVERSION*/ // so that we dont need to write it in while loop
}

void ADC_SetCallBack(void(*ptrf)(void))
{
	pointer_to_func=ptrf;
}





