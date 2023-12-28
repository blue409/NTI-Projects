 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.c
 *
 * Description: Source file for the Keypad driver
 *
 * Author: Menna Sayed
 *
 *******************************************************************************/
//#include "common_macros.h" /* To use the macros like SET_BIT */
#include "keypad.h"

extern uint16 number;
/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
 *******************************************************************************/
static uint8 colum_pins[4]={KEYPAD_FIRST_COLUMN_PIN_ID,KEYPAD_SECOND_COLUMN_PIN_ID,KEYPAD_THIRD_COLUMN_PIN_ID,KEYPAD_FOURTH_COLUMN_PIN_ID};
static uint8 rows_pins[4]={ KEYPAD_FIRST_ROW_PIN_ID,KEYPAD_SECOND_ROW_PIN_ID ,KEYPAD_THIRD_ROW_PIN_ID,KEYPAD_FOURTH_ROW_PIN_ID};


#if (KEYPAD_NUM_COLS == 3)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x3 keypad
 */
static uint8 KEYPAD_4x3_adjustKeyNumber(uint8 button_number);
#elif (KEYPAD_NUM_COLS == 4)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x4 keypad
 */
static uint8 KEYPAD_4x4_adjustKeyNumber(uint8 button_number);
#endif

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void KEYPAD_INIT(void)
{
	DIO_setupPinDirection(KEYPAD_COL_PORT_ID,KEYPAD_FIRST_COLUMN_PIN_ID,PIN_INPUT);
	DIO_setupPinDirection(KEYPAD_COL_PORT_ID,KEYPAD_SECOND_COLUMN_PIN_ID,PIN_INPUT);
	DIO_setupPinDirection(KEYPAD_COL_PORT_ID,KEYPAD_THIRD_COLUMN_PIN_ID,PIN_INPUT);
	DIO_setupPinDirection(KEYPAD_COL_PORT_ID,KEYPAD_FOURTH_COLUMN_PIN_ID,PIN_INPUT);

	DIO_setupPinDirection(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID,PIN_OUTPUT);
	DIO_setupPinDirection(KEYPAD_ROW_PORT_ID,KEYPAD_SECOND_ROW_PIN_ID,PIN_OUTPUT);
	DIO_setupPinDirection(KEYPAD_ROW_PORT_ID,KEYPAD_THIRD_ROW_PIN_ID ,PIN_OUTPUT);
	DIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_FOURTH_ROW_PIN_ID,PIN_OUTPUT);

}

uint8 KEYPAD_getPressedKey(void)
{
	uint8 col,row;
	uint8 button_num =0;
	uint8 pin_read;
		 DIO_writePin(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID,  LOGIC_HIGH);
		 DIO_writePin(KEYPAD_ROW_PORT_ID, KEYPAD_SECOND_ROW_PIN_ID, LOGIC_HIGH);
		 DIO_writePin(KEYPAD_ROW_PORT_ID, KEYPAD_THIRD_ROW_PIN_ID,  LOGIC_HIGH);
		 DIO_writePin(KEYPAD_ROW_PORT_ID, KEYPAD_FOURTH_ROW_PIN_ID, LOGIC_HIGH);
    for(row=0;row<KEYPAD_NUM_ROWS;row++)
    {
		 DIO_writePin(KEYPAD_ROW_PORT_ID, rows_pins[row], LOGIC_LOW);
         for(col=0;col<KEYPAD_NUM_COLS;col++)
         {
        	 DIO_readPin(KEYPAD_COL_PORT_ID,colum_pins[col],&pin_read);
        	 if(pin_read== LOGIC_LOW)
        	 {
        		 _delay_ms(50);
        		 DIO_readPin(KEYPAD_COL_PORT_ID,colum_pins[col],&pin_read);
        		 if(pin_read== LOGIC_LOW) //for debouncing
        		 {
                  button_num=(4*row)+1+col;  //no from 1 to 16
                  DIO_writePin(KEYPAD_ROW_PORT_ID, rows_pins[row], LOGIC_HIGH); //to make it off ..if returned here
                  return KEYPAD_4x4_adjustKeyNumber(button_num);
        		 }
          	 }
         }
         DIO_writePin(KEYPAD_ROW_PORT_ID, rows_pins[row], LOGIC_HIGH); //make the row off to cont. the loop
    }
    return KEYPAD_4x4_adjustKeyNumber(button_num);
}

#if (KEYPAD_NUM_COLS == 3)

/*
 * Description :
 * Update the keypad pressed button value with the correct one in keypad 4x3 shape
 */
static uint8 KEYPAD_4x3_adjustKeyNumber(uint8 button_number)
{
	uint8 keypad_button = 0;
	switch(button_number)
	{
		case 10: keypad_button = '*'; // ASCII Code of *
				 break;
		case 11: keypad_button = 0;
				 break;		
		case 12: keypad_button = '#'; // ASCII Code of #
				 break;
		default: keypad_button = button_number;
				break;
	}
	return keypad_button;
} 

#elif (KEYPAD_NUM_COLS == 4)

/*
 * Description :
 * Update the keypad pressed button value with the correct one in keypad 4x4 shape
 */
static uint8 KEYPAD_4x4_adjustKeyNumber(uint8 button_number)
{
	uint8 keypad_button = 0;
	switch(button_number)
	{
		case 1: keypad_button = '7';
		        number = 7;
				break;
		case 2: keypad_button = '8';
		        number=8;
				break;
		case 3: keypad_button = '9';
		        number=9;
				break;
		case 4: keypad_button = '%'; // ASCII Code of %
		        number=12;
				break;
		case 5: keypad_button = '4';
		        number=4;
				break;
		case 6: keypad_button = '5';
		        number =5;
				break;
		case 7: keypad_button = '6';
		        number=6;
				break;
		case 8: keypad_button = '*'; /* ASCII Code of '*' */
		        number=13;
				break;		
		case 9: keypad_button = '1';
		        number=1;
				break;
		case 10: keypad_button = '2';
		         number=2;
				break;
		case 11: keypad_button = '3';
		         number=3;
				break;
		case 12: keypad_button = '-'; /* ASCII Code of '-' */
		         number=14;
				break;
		case 13: keypad_button = ' ';  /* ASCII of Enter */
		         number = 17;
				break;			
		case 14: keypad_button = '0';
		         number=0;
				break;
		case 15: keypad_button = '='; /* ASCII Code of '=' */
		        number=15;
				break;
		case 16: keypad_button = '+'; /* ASCII Code of '+' */
		        number=16;
				break;
		default: keypad_button = 17;//button_number;
				break;
	}
	return keypad_button;
} 

#endif
