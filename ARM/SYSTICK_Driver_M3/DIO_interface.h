#ifndef		DIO_INTERFACE_H
#define		DIO_INTERFACE_H

#include "DIO_private.h"

#define		PORTA			0
#define		PORTB			1
#define		PORTC			2

#define		PIN0			0
#define		PIN1			1
#define		PIN2			2
#define		PIN3			3
#define		PIN4			4
#define		PIN5			5
#define		PIN6			6
#define		PIN7			7
#define		PIN8			8
#define		PIN9			9
#define		PIN10			10
#define		PIN11			11
#define		PIN12			12
#define		PIN13			13
#define		PIN14			14
#define		PIN15			15


#define		GPIO_HIGH		1
#define		GPIO_LOW		0

//#define PIN_INPUT         0
//#define PIN_OUTPUT        1

#define mask_mode       0b0000
#define MASK_32BIT		0b00000000000000000000000000000000


#define		GPIO_INPUT_ANALOG				0b0000
#define		GPIO_INPUT_FLOAT				0b0100
#define		GPIO_INPUT_PULL_UP_DOWN			0b1000

#define		GPIO_OUTPUT_10MHZ_PP			0b0001
#define		GPIO_OUTPUT_10MHZ_OD			0b0101
#define		GPIO_OUTPUT_10MHZ_AFPP			0b1001
#define		GPIO_OUTPUT_10MHZ_AFOD			0b1101

#define		GPIO_OUTPUT_2MHZ_PP				0b0010
#define		GPIO_OUTPUT_2MHZ_OD				0b0110
#define		GPIO_OUTPUT_2MHZ_AFPP			0b1010
#define		GPIO_OUTPUT_2MHZ_AFOD			0b1110

#define		GPIO_OUTPUT_50MHZ_PP			0b0011
#define		GPIO_OUTPUT_50MHZ_OD			0b0111
#define		GPIO_OUTPUT_50MHZ_AFPP			0b1011
#define		GPIO_OUTPUT_50MHZ_AFOD			0b1111


void GPIO_voidSetPinDirection(uint8 port, uint8 pin, uint8 Direction);
void GPIO_voidSetPinValue(uint8 port, uint8 pin, uint8 Value);
uint8 GPIO_u8GetPinValue(uint8 port, uint8 pin);
void GPIO_voidSetPortnDirection(uint8 port, uint8 Direction);
void GPIO_voidSetPORTValue(uint8 port, uint16 Value);
void GPIO_voidTogglePin(uint8 port, uint8 pin);


#endif
