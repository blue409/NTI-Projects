/*
 * DIO_program.c
 *
 *  Created on: Dec 31, 2022
 *      Author: AMIT
 */


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"


void DIO_voidInit(void)
{
	/*Set Initial Directions FOR Pins */
	DDRA = CONC(DIO_PA7_INITIAL_DIRECTION,DIO_PA6_INITIAL_DIRECTION,DIO_PA5_INITIAL_DIRECTION,DIO_PA4_INITIAL_DIRECTION,
	            DIO_PA3_INITIAL_DIRECTION,DIO_PA2_INITIAL_DIRECTION,DIO_PA1_INITIAL_DIRECTION,DIO_PA0_INITIAL_DIRECTION);
				
	DDRB = CONC(DIO_PB7_INITIAL_DIRECTION,DIO_PB6_INITIAL_DIRECTION,DIO_PB5_INITIAL_DIRECTION,DIO_PB4_INITIAL_DIRECTION,
	            DIO_PB3_INITIAL_DIRECTION,DIO_PB2_INITIAL_DIRECTION,DIO_PB1_INITIAL_DIRECTION,DIO_PB0_INITIAL_DIRECTION);
				
	DDRC = CONC(DIO_PC7_INITIAL_DIRECTION,DIO_PC6_INITIAL_DIRECTION,DIO_PC5_INITIAL_DIRECTION,DIO_PC4_INITIAL_DIRECTION,
	            DIO_PC3_INITIAL_DIRECTION,DIO_PC2_INITIAL_DIRECTION,DIO_PC1_INITIAL_DIRECTION,DIO_PC0_INITIAL_DIRECTION);
				
    DDRD = CONC(DIO_PD7_INITIAL_DIRECTION,DIO_PD6_INITIAL_DIRECTION,DIO_PD5_INITIAL_DIRECTION,DIO_PD4_INITIAL_DIRECTION,
	            DIO_PD3_INITIAL_DIRECTION,DIO_PD2_INITIAL_DIRECTION,DIO_PD1_INITIAL_DIRECTION,DIO_PD0_INITIAL_DIRECTION);
				
	/*Set Initial Values FOR Pins */
	PORTA = CONC(DIO_PA7_INITIAL_VALUE,DIO_PA6_INITIAL_VALUE,DIO_PA5_INITIAL_VALUE,DIO_PA4_INITIAL_VALUE,
	             DIO_PA3_INITIAL_VALUE,DIO_PA2_INITIAL_VALUE,DIO_PA1_INITIAL_VALUE,DIO_PA0_INITIAL_VALUE);
																								   
	PORTB = CONC(DIO_PB7_INITIAL_VALUE,DIO_PB6_INITIAL_VALUE,DIO_PB5_INITIAL_VALUE,DIO_PB4_INITIAL_VALUE,
	             DIO_PB3_INITIAL_VALUE,DIO_PB2_INITIAL_VALUE,DIO_PB1_INITIAL_VALUE,DIO_PB0_INITIAL_VALUE);
																								   
	PORTC = CONC(DIO_PC7_INITIAL_VALUE,DIO_PC6_INITIAL_VALUE,DIO_PC5_INITIAL_VALUE,DIO_PC4_INITIAL_VALUE,
	             DIO_PC3_INITIAL_VALUE,DIO_PC2_INITIAL_VALUE,DIO_PC1_INITIAL_VALUE,DIO_PC0_INITIAL_VALUE);
																								   
    PORTD = CONC(DIO_PD7_INITIAL_VALUE,DIO_PD6_INITIAL_VALUE,DIO_PD5_INITIAL_VALUE,DIO_PD4_INITIAL_VALUE,
	             DIO_PD3_INITIAL_VALUE,DIO_PD2_INITIAL_VALUE,DIO_PD1_INITIAL_VALUE,DIO_PD0_INITIAL_VALUE);
}

void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8  copy_u8PinDirection)
{
	if((copy_u8PortId<=3)&&(copy_u8PinId<=7)&&((DIO_PIN_OUTPUT==copy_u8PinDirection)||(DIO_PIN_INPUT==copy_u8PinDirection)))
	{
		switch(copy_u8PortId)
		{
		case DIO_PORTA:
			if(DIO_PIN_OUTPUT == copy_u8PinDirection)
			{
				SET_BIT(DDRA,copy_u8PinId);
			}
			else
			{
				CLR_BIT(DDRA,copy_u8PinId);
			}
			break;

		case DIO_PORTB:
			if(DIO_PIN_OUTPUT == copy_u8PinDirection)
			{
				SET_BIT(DDRB,copy_u8PinId);
			}
			else
			{
				CLR_BIT(DDRB,copy_u8PinId);
			}
			break;

		case DIO_PORTC:
			if(DIO_PIN_OUTPUT == copy_u8PinDirection)
			{
				SET_BIT(DDRC,copy_u8PinId);
			}
			else
			{
				CLR_BIT(DDRC,copy_u8PinId);
			}
			break;

		case DIO_PORTD:
			if(DIO_PIN_OUTPUT == copy_u8PinDirection)
			{
				SET_BIT(DDRD,copy_u8PinId);
			}
			else
			{
				CLR_BIT(DDRD,copy_u8PinId);
			}
			break;
		}
	}

	else
	{
		// Do Nothing
	}
}


void DIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8  copy_u8PinValue)
{
	switch(copy_u8PortId)
	{
	case DIO_PORTA:
		if(DIO_PIN_HIGH == copy_u8PinValue)
		{
			SET_BIT(PORTA,copy_u8PinId);
		}
		else
		{
			CLR_BIT(PORTA,copy_u8PinId);
		}
		break;

	case DIO_PORTB:
		if(DIO_PIN_HIGH == copy_u8PinValue)
		{
			SET_BIT(PORTB,copy_u8PinId);
		}
		else
		{
			CLR_BIT(PORTB,copy_u8PinId);
		}
		break;

	case DIO_PORTC:
		if(DIO_PIN_HIGH == copy_u8PinValue)
		{
			SET_BIT(PORTC,copy_u8PinId);
		}
		else
		{
			CLR_BIT(PORTC,copy_u8PinId);
		}
		break;

	case DIO_PORTD:
		if(DIO_PIN_HIGH == copy_u8PinValue)
		{
			SET_BIT(PORTD,copy_u8PinId);
		}
		else
		{
			CLR_BIT(PORTD,copy_u8PinId);
		}
		break;
	}
}


void DIO_voidGetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue)
{
	switch(copy_u8PortId)
	{
	case DIO_PORTA:
		*copy_pu8PinValue = GET_BIT(PINA,copy_u8PinId);
		break;

	case DIO_PORTB:
		*copy_pu8PinValue = GET_BIT(PINB,copy_u8PinId);
		break;

	case DIO_PORTC:
		*copy_pu8PinValue = GET_BIT(PINC,copy_u8PinId);
		break;

	case DIO_PORTD:
		*copy_pu8PinValue = GET_BIT(PIND,copy_u8PinId);
		break;
	}
}


void DIO_voidTogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
	case DIO_PORTA:
		TOG_BIT(PORTA,copy_u8PinId);
		break;

	case DIO_PORTB:
		TOG_BIT(PORTB,copy_u8PinId);
		break;

	case DIO_PORTC:
		TOG_BIT(PORTC,copy_u8PinId);
		break;

	case DIO_PORTD:
		TOG_BIT(PORTD,copy_u8PinId);
		break;
	}
}


void DIO_voidActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
	case DIO_PORTA:
		SET_BIT(PORTA,copy_u8PinId);
		break;

	case DIO_PORTB:
		SET_BIT(PORTB,copy_u8PinId);
		break;

	case DIO_PORTC:
		SET_BIT(PORTC,copy_u8PinId);
		break;

	case DIO_PORTD:
		SET_BIT(PORTD,copy_u8PinId);
		break;
	}
}


/* Port Apis */
void DIO_voidSetPortDirection(u8 copy_u8PortId, u8  copy_u8PortDirection)
{
	if((copy_u8PortId<=3) && ((DIO_PORT_OUTPUT == copy_u8PortDirection) || (DIO_PORT_INPUT == copy_u8PortDirection)))
	{
		switch(copy_u8PortId)
		{
		case 0:
			if(DIO_PORT_OUTPUT == copy_u8PortDirection)
			{
				DDRA = 0xff;
			}
			else
			{
				DDRA = 0x00;
			}
			break;

		case 1:
			if(DIO_PORT_OUTPUT == copy_u8PortDirection)
			{
				DDRB = 0xff;
			}
			else
			{
				DDRB = 0x00;
			}
			break;

		case 2:
			if(DIO_PORT_OUTPUT == copy_u8PortDirection)
			{
				DDRC = 0xff;
			}
			else
			{
				DDRC = 0x00;
			}
			break;

		case 3:
			if(DIO_PORT_OUTPUT == copy_u8PortDirection)
			{
				DDRD = 0xff;
			}
			else
			{
				DDRD = 0x00;
			}
			break;
		}
	}
}


void DIO_voidSetPortValue(u8 copy_u8PortId, u8  copy_u8PortValue)
{
	if(copy_u8PortId<=3)
	{
		switch(copy_u8PortId)
		{
		case 0:
			PORTA = copy_u8PortValue;
			break;

		case 1:
			PORTB = copy_u8PortValue;
			break;

		case 2:
			PORTC = copy_u8PortValue;
			break;

		case 3:
			PORTD = copy_u8PortValue;
			break;
		}
	}
}


void DIO_voidGetPortValue(u8 copy_u8PortId, u8* copy_pu8PortValue)
{
	if((copy_u8PortId<=3) && (copy_pu8PortValue != NULL))
	{
		switch(copy_u8PortId)
		{
		case 0:
			*copy_pu8PortValue = PINA;
			break;

		case 1:
			*copy_pu8PortValue = PINB;
			break;

		case 2:
			*copy_pu8PortValue = PINC;
			break;

		case 3:
			*copy_pu8PortValue = PIND;
			break;
		}
	}
}


void DIO_voidTogglePortValue(u8 copy_u8PortId)
{
	if(copy_u8PortId<=3)
	{
		switch(copy_u8PortId)
		{
		case 0:
			PORTA = ~PORTA;
			break;

		case 1:
			PORTB = ~PORTB;
			break;

		case 2:
			PORTC = ~PORTC;
			break;

		case 3:
			PORTD = ~PORTD;
			break;
		}
	}
}


void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId)
{
	if(copy_u8PortId<=3)
	{
		switch(copy_u8PortId)
		{
		case 0:
			PORTA = 0xff;
			break;

		case 1:
			PORTB = 0xff;
			break;

		case 2:
			PORTC = 0xff;
			break;

		case 3:
			PORTD = 0xff;
			break;
		}
	}
}
