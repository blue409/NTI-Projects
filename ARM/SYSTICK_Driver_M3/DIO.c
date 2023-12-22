/*
 * DIO.c
 *
 *  Created on: Nov 6, 2023
 *  Author: dell
 ********************************************************/
#include "DIO_interface.h"
#include "common_macros.h"

void GPIO_voidSetPinDirection(uint8 port, uint8 pin, uint8 Direction)
{
    switch(port)
    {
      case PORTA:
    	    if(pin<8){
    	    	 GPIOA_CRL &= mask_mode<<(pin*4);
    	    	 GPIOA_CRL ^= Direction<<((pin*4));
    	     }else{
      	    	 GPIOA_CRH &= mask_mode<<(pin*4);
       	    	 GPIOA_CRH ^= Direction<<((pin*4));
    	    	 }
    	  break;
      case PORTB:
    	  if(pin<8){
  	    	 GPIOB_CRL &= mask_mode<<(pin*4);
  	    	 GPIOB_CRL ^= Direction<<((pin*4));
  	     }else{
    	     GPIOB_CRH &= mask_mode<<(pin*4);
     	     GPIOB_CRH ^= Direction<<((pin*4));
  	    	 }
    	  break;
      case PORTC:
    	  if(pin<8){
  	    	 GPIOC_CRL &= mask_mode<<(pin*4);
  	    	 GPIOC_CRL ^= Direction<<((pin*4));
  	     }else{
    	     GPIOC_CRH &= mask_mode<<(pin*4);
     	     GPIOC_CRH ^= Direction<<((pin*4));
  	    	 }
    	  break;
      default:
    	  break;
    }
}


void GPIO_voidSetPinValue(uint8 port, uint8 pin, uint8 Value)
{
	switch(port)
	    {
	      case PORTA:
	    	  switch(Value)
	    	  {
	    	     case GPIO_HIGH:
	    	    	 SET_BIT(GPIOA_ODR,pin);
	    	    	 break;
	    	     case GPIO_LOW:
	    	    	 CLEAR_BIT(GPIOA_ODR,pin);
	    	    	 break;
	    	  }
	    	  break;
	      case PORTB:
	    	  switch(Value)
	    	  {
	    	     case GPIO_HIGH:
	    	    	 SET_BIT(GPIOB_ODR,pin);
	    	    	 break;
	    	     case GPIO_LOW:
	    	    	 CLEAR_BIT(GPIOB_ODR,pin);
	    	    	 break;
	    	  }
	    	  break;
	      case PORTC:
	    	  switch(Value)
	    	  {
	    	     case GPIO_HIGH:
	    	    	 SET_BIT(GPIOC_ODR,pin);
	    	    	 break;
	    	     case GPIO_LOW:
	    	    	 CLEAR_BIT(GPIOC_ODR,pin);
	    	    	 break;
	    	  }
	    	  break;
	      default:
	    	  break;
	    }
}

uint8 GPIO_u8GetPinValue(uint8 port, uint8 pin)
{
	switch(port)
	    {
	      case PORTA:
	    	 return GET_BIT(GPIOA_IDR,pin);
	    	 break;
	      case PORTB:
	    	 return GET_BIT(GPIOB_IDR,pin);
	    	 break;
	      case PORTC:
	    	  return GET_BIT(GPIOC_IDR,pin);
	    	 break;
        }
	return E_NOK ;
}

void GPIO_voidSetPortnDirection(uint8 port, uint8 Direction)
{
	switch (port)
		{
			case PORTA:
				GPIOA_CRL &= MASK_32BIT;
				GPIOA_CRL ^= ((Direction<<0) | (Direction<<1*4) | (Direction<<2*4) | (Direction<<3*4) | (Direction<<4*4)
						   | (Direction<<5*4) | (Direction<<6*4) | (Direction<<7*4));
				GPIOA_CRH &= MASK_32BIT;
				GPIOA_CRH ^= ((Direction<<0) | (Direction<<1*4) | (Direction<<2*4) | (Direction<<3*4) | (Direction<<4*4)
						   | (Direction<<5*4) | (Direction<<6*4) | (Direction<<7*4));
				break;

			case PORTB:
				GPIOB_CRL &= MASK_32BIT;
				GPIOB_CRL ^= ((Direction<<0) | (Direction<<1*4) | (Direction<<2*4) | (Direction<<3*4) | (Direction<<4*4)
						   | (Direction<<5*4) | (Direction<<6*4) | (Direction<<7*4));
				GPIOB_CRH &= MASK_32BIT;
				GPIOB_CRH ^= ((Direction<<0) | (Direction<<1*4) | (Direction<<2*4) | (Direction<<3*4) | (Direction<<4*4)
						   | (Direction<<5*4) | (Direction<<6*4) | (Direction<<7*4));
				break;

			case PORTC:
				GPIOC_CRL &= MASK_32BIT;
				GPIOC_CRL ^= ((Direction<<0) | (Direction<<1*4) | (Direction<<2*4) | (Direction<<3*4) | (Direction<<4*4)
						   | (Direction<<5*4) | (Direction<<6*4) | (Direction<<7*4));
				GPIOC_CRH &= MASK_32BIT;
				GPIOC_CRH ^= ((Direction<<0) | (Direction<<1*4) | (Direction<<2*4) | (Direction<<3*4) | (Direction<<4*4)
						   | (Direction<<5*4) | (Direction<<6*4) | (Direction<<7*4));
				break;
		}
}

void GPIO_voidSetPORTValue(uint8 port, uint16 Value)
{
	switch(port)
	{
		case PORTA:
			GPIOA_ODR = 0;
			GPIOA_ODR |= Value;
			break;
		case PORTB:
			GPIOB_ODR = 0;
			GPIOB_ODR |= Value;
			break;
		case PORTC:
			GPIOC_ODR = 0;
			GPIOC_ODR |= Value;
			break;

	}
}

void GPIO_voidTogglePin(uint8 port, uint8 pin)
{
	switch(port)
		{
			case PORTA:
				TOGGLE_BIT(GPIOA_ODR, pin);
				break;
			case PORTB:
				TOGGLE_BIT(GPIOB_ODR, pin);
				break;
			case PORTC:
				TOGGLE_BIT(GPIOC_ODR, pin);
				break;
		}
}
