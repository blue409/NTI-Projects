/*
 * LCD.h
 *
 *  Created on: Oct 22, 2023
 *      Author: dell
 */

#ifndef LCD_H_
#define LCD_H_

#include "dio.h"


#define LCD_FIRST_DATA_PIN_ID         PIN0_ID

/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 PORTA_ID
#define LCD_RS_PIN_ID                  PIN3_ID

#define LCD_RW_PORT_ID                 PORTD_ID
#define LCD_RW_PIN_ID                  PIN2_ID

#define LCD_E_PORT_ID                  PORTA_ID
#define LCD_E_PIN_ID                   PIN2_ID

#define LCD_DATA_PORT_ID               PORTB_ID

/* LCD Commands*/

#define LCD_CONFIG_WORD             (0x30)

#define LCD_CLR                     (0x01)

#define LCD_CURSOR_HOME             (0x02)

#define LCD_SET_ENTRY_MODE          (0x40)
#define LCD_INCREMENT_CURSOR        (0x02)
#define LCD_DECREMENT_CURSOR        (0x00)
#define LCD_DISPLAY_SHIFT_ON        (0x01)
#define LCD_DISPLAY_SHIFT_OFF       (0x00)
#define LCD_TWO_LINES_FOUR_BITS_MODE (0x28)

#define LCD_DISPLAY_CONTROL         (0x08)
#define LCD_DISPLAY_ON              (0x04)
#define LCD_DISPLAY_OFF             (0x00)
#define LCD_CURSOR_ON               (0x02)
#define LCD_CURSOR_OFF              (0x00)
#define LCD_CURSOR_BLINK_ON         (0x01)
#define LCD_CURSOR_BLINK_OFF        (0x00)

#define LCD_CURSOR_DISPLAY_CONTROL  (0x10)
#define LCD_SHIFT_CURSOR            (0x00)
#define LCD_SHIFT_DISPLAY           (0x08)
#define LCD_SHIFT_LEFT              (0x00)
#define LCD_SHIFT_RIGHT             (0x04)

#define LCD_FUNCTION_SET            (0x20)
#define LCD_DATA_LENGTH_4           (0x00)
#define LCD_DATA_LENGTH_8           (0x10)
#define LCD_ONE_LINE                (0x00)
#define LCD_TWO_LINES               (0x08)
#define LCD_SMALL_FONT              (0x00)
#define LCD_LARGE_FONT              (0x04)

#define LCD_Start_CGRAM_ADDRESS       (0x40)

#define LCD_SET_DDRAM_ADDRESS       (0x80)

#define LCD_DDRAM_LINE_SIZE         (0x28)
#define LCD_DDRAM_LINE_2_ADDRESS    (0x40)

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_Init(void);
void LCD_SendCommand(uint8 command);
void LCD_SendData(uint8 Data);
void LCD_SendChar(uint8 character);
void LCD_SendString(const uint8 * str);
void LCD_GoTo(uint8 line,uint8 column);
void LCD_clearScreen(void);
void LCD_integerTostring(uint16 num);
void LCD_defineCustomChar(uint8 location, const uint8 charMap[8]); /* Defines new customised char and stores it in lcd CGROM...charMap is from https://maxpromer.github.io/LCD-Character-Creator */

#endif /* LCD_H_ */
