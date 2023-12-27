/*
 * LCD.c
 *
 *  Created on: Oct 22, 2023
 *      Author: dell
 *****************************************************/
#include "LCD.h"
#include <util/delay.h>
#include <stdlib.h>

void LCD_Init(void)
{
	DIO_setupPinDirection(PORTA_ID , PIN3_ID , PIN_OUTPUT); /* RS*/
	DIO_setupPinDirection(PORTA_ID , PIN2_ID , PIN_OUTPUT); /* EN */

	DIO_setupPinDirection(PORTB_ID , PIN0_ID , PIN_OUTPUT);
	DIO_setupPinDirection(PORTB_ID , PIN1_ID , PIN_OUTPUT); /*  */
	DIO_setupPinDirection(PORTB_ID , PIN2_ID , PIN_OUTPUT); /* */
	DIO_setupPinDirection(PORTB_ID , PIN4_ID , PIN_OUTPUT); /*  */

	 LCD_SendCommand(LCD_CURSOR_HOME);//0x02
	 _delay_ms(2);
	 LCD_SendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);//0x28 /* use 2-line lcd + 4-bit Data Mode + 5*7 dot display Mode */
	 _delay_ms(4);

//	 LCD_SendCommand(0x0C);/*Disp ON Cursor OFF*/
	 LCD_SendCommand(LCD_CURSOR_ON);//(0x02) /* cursor off */
	 _delay_ms(2);
	 LCD_SendCommand(0x06);
	 LCD_SendCommand(LCD_CLR );//(0x01) /* clear LCD at the beginning */
	 _delay_ms(500);
}
void LCD_SendCommand(uint8 command)
{
	DIO_writePin(PORTA_ID , LCD_RS_PIN_ID  , 0);
	DIO_writePin(PORTA_ID ,LCD_E_PIN_ID  , 1);	//set
	 _delay_ms(2);
	 DIO_writePin(PORTB_ID ,PIN0_ID ,GET_BIT(command,PIN4_ID));
	 DIO_writePin(PORTB_ID ,PIN1_ID ,GET_BIT(command,PIN5_ID));
	 DIO_writePin(PORTB_ID ,PIN2_ID ,GET_BIT(command,PIN6_ID));
	 DIO_writePin(PORTB_ID ,PIN4_ID ,GET_BIT(command,PIN7_ID));
//	 _delay_ms(2);
	 DIO_writePin(PORTA_ID , LCD_E_PIN_ID  , 0);	//clear
	 _delay_ms(2);
	 DIO_writePin(PORTA_ID , LCD_E_PIN_ID  , 1);	//set
	 _delay_ms(2);
	 DIO_writePin(PORTB_ID ,PIN0_ID ,GET_BIT(command,PIN0_ID));
	 DIO_writePin(PORTB_ID ,PIN1_ID ,GET_BIT(command,PIN1_ID));
	 DIO_writePin(PORTB_ID ,PIN2_ID ,GET_BIT(command,PIN2_ID));
	 DIO_writePin(PORTB_ID ,PIN4_ID ,GET_BIT(command,PIN3_ID));

	DIO_writePin(PORTA_ID , LCD_E_PIN_ID  , 0);	//clear
	_delay_ms(2);
	DIO_writePin(PORTA_ID ,LCD_E_PIN_ID  , 1);
	_delay_ms(2);
}

void LCD_SendData(uint8 Data)
{
	DIO_writePin(PORTA_ID , PIN3_ID , 1);
	DIO_writePin(PORTA_ID , PIN2_ID , 1);	//set
	 _delay_ms(2);
	 DIO_writePin(PORTB_ID ,PIN0_ID ,GET_BIT(Data,PIN4_ID));
	 DIO_writePin(PORTB_ID ,PIN1_ID ,GET_BIT(Data,PIN5_ID));
	 DIO_writePin(PORTB_ID ,PIN2_ID ,GET_BIT(Data,PIN6_ID));
	 DIO_writePin(PORTB_ID ,PIN4_ID ,GET_BIT(Data,PIN7_ID));

	 DIO_writePin(PORTA_ID , PIN2_ID , 0);	//clear
	 _delay_ms(2);
	 DIO_writePin(PORTA_ID , PIN2_ID , 1);	//set
	_delay_ms(2);
	DIO_writePin(PORTB_ID ,PIN0_ID ,GET_BIT(Data,PIN0_ID));
	DIO_writePin(PORTB_ID ,PIN1_ID ,GET_BIT(Data,PIN1_ID));
	DIO_writePin(PORTB_ID ,PIN2_ID ,GET_BIT(Data,PIN2_ID));
	DIO_writePin(PORTB_ID ,PIN4_ID ,GET_BIT(Data,PIN3_ID));

	DIO_writePin(PORTA_ID , PIN2_ID , 0);	//clear
	_delay_ms(2);
	DIO_writePin(PORTA_ID ,LCD_E_PIN_ID  , 1);
	_delay_ms(2);
}

void LCD_GoTo(uint8 line,uint8 col)
{
	uint8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(line)
	{
		case 0:
			lcd_memory_address=col;
				break;
		case 1:
			lcd_memory_address=col+0x40;
				break;
		case 2:
			lcd_memory_address=col+0x14;
				break;
		case 3:
			lcd_memory_address=col+0x54;
				break;

	}
	/* Move the LCD cursor to this specific address */
	LCD_SendCommand(lcd_memory_address | LCD_SET_DDRAM_ADDRESS);
}

void LCD_SendChar(uint8 character)
{
//	LCD_GoTo(line, col);
	LCD_SendData(character);

}

void LCD_SendString(const uint8 *str)
{
	uint8 i = 0;
		while(str[i])
		{
			LCD_SendChar(str[i]);
			i++;
		}
}

void LCD_clearScreen(void)
{
	LCD_SendCommand(LCD_CLR); /* Send clear display command */
}

void LCD_defineCustomChar(uint8_t location, const uint8_t charMap[8]) {
	LCD_SendCommand(LCD_Start_CGRAM_ADDRESS + (location * 8));  //command for writting in CGRAM
    for (uint8_t i = 0; i < 8; i++) {
    	LCD_SendData(charMap[i]);
    }
}

void LCD_integerTostring(uint16 num)
{
	char holdstr[16];
	itoa(num,holdstr,10);  //to convert num into string and store it in holdstr,,,10 =base of decimal no.
	LCD_SendString(holdstr);
}



