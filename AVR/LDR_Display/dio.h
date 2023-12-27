 /******************************************************************************
 *
 * Module: DIO
 *
 * File Name: dio.h
 *
 * Description: Header file for the AVR GPIO driver
 *
 * Author: Menna Sayed
 *
 *******************************************************************************/

#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"
#include "common_macros.h"
#include <avr/io.h>        /* To use the IO Ports Registers */

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request + returns E_NOK.
 */
uint8 DIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
uint8 DIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);

/*
 * Description :
 * Read and return the value of the required pin in the sent variable to the func, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return E_NOK.
 */
uint8 DIO_readPin(uint8 port_num, uint8 pin_num,uint8* pin_value);

/*
 * Description :
 * toggels the value of the required pin.
 * If the input port number is not correct, The function will return E_NOK.
 */
uint8 DIO_togglePin(uint8 port_num,uint8 pin_num);

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
uint8 DIO_setupPortDirection(uint8 port_num, uint8 direction);

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
uint8 DIO_writePort(uint8 port_num, uint8 value);

/*
 * Description :
 * Read and return the value of the required port in the sent variable to the func.
 * If the input port number is not correct, The function will return E_NOK.
 */
uint8 DIO_readPort(uint8 port_num,uint8* value);

#endif /* GPIO_H_ */
