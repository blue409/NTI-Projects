 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Menna Sayed
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_types.h"
#include "dio.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                  4
#define KEYPAD_NUM_ROWS                  4

/* Keypad Port Configurations */
#define KEYPAD_PORT_ID                    PORTA_ID  //if the col and rows are connected to the same port
#define KEYPAD_ROW_PORT_ID                PORTC_ID
#define KEYPAD_COL_PORT_ID                PORTD_ID

#define KEYPAD_FIRST_ROW_PIN_ID           PIN5_ID
#define KEYPAD_SECOND_ROW_PIN_ID          PIN4_ID
#define KEYPAD_THIRD_ROW_PIN_ID           PIN3_ID
#define KEYPAD_FOURTH_ROW_PIN_ID          PIN2_ID

#define KEYPAD_FIRST_COLUMN_PIN_ID        PIN7_ID
#define KEYPAD_SECOND_COLUMN_PIN_ID       PIN6_ID
#define KEYPAD_THIRD_COLUMN_PIN_ID        PIN5_ID
#define KEYPAD_FOURTH_COLUMN_PIN_ID       PIN3_ID

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED             LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED            LOGIC_HIGH



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Get the Keypad pressed button
 */
void KEYPAD_INIT(void);
uint8 KEYPAD_getPressedKey(void);

#endif /* KEYPAD_H_ */
