/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *  Author: Menna Sayed
 ************************************************************/

#include <util/delay.h>
#include "LCD.h"
#include "keypad.h"

uint16 number=0;
uint8  Op_sign=0;
uint16  num2=0;
uint16 num1=0;

uint16 operation_result(uint8 num);

int main()
{
	KEYPAD_INIT();
	LCD_Init();
	LCD_GoTo(0,1);
	_delay_ms(500);
	LCD_clearScreen();
	_delay_ms(500);
	LCD_SendString("CalCULATOR...");
	_delay_ms(1000);
	 LCD_GoTo(2,1);
	 _delay_ms(500);
	while(1)
	{
	 LCD_GoTo(2,1);
	 _delay_ms(50);
	 LCD_SendChar(KEYPAD_getPressedKey());
         num1=number;
         LCD_SendChar(KEYPAD_getPressedKey());
         Op_sign=number;
         LCD_SendChar(KEYPAD_getPressedKey());
         num2=number;
         LCD_SendChar(KEYPAD_getPressedKey());//= sign
         LCD_integerTostring(operation_result(Op_sign));
         _delay_ms(8000);

	}


	return 0;
}

uint16 operation_result(uint8 num)
{
	switch(num)
	{
	case 16:
		return (num1+num2);
		break;
	case 14:
		return (num1-num2);
		break;
	case 13:
		return (num1*num2);
		break;
	case 12:
		return ((float32)(num1/num2));
		break;
	}
	return E_NOK;
}

