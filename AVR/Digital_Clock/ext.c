/*
 * ext.c
 *
 *  Created on: Oct 27, 2023
 *  Author:     Menna Sayed
 *************************************************************************/
#include "ext.h"

extern uint8 button1_flag;
extern uint8 button2_flag;

void (*pointer_to_func)(void)=NULL_PTR;  /*For Call Back*/


void EXTI_Init(const EXTINT_ConfigType* Config_ptr)
{
	switch(Config_ptr->INT_num)
	{
	case 0:
	 switch(Config_ptr->Mode)
		{
		case FALLING_Edge:
			  SET_BIT(MCUCR, ISC00);
			  SET_BIT(MCUCR, ISC01);
			break;
		case RISING_Edge:
			  CLEAR_BIT(MCUCR, ISC00);
			  SET_BIT(MCUCR, ISC01);
			break;
		case IOC:
			  SET_BIT(MCUCR, ISC00);
			  CLEAR_BIT(MCUCR, ISC01);
			break;
		case LOW_Level:
			  CLEAR_BIT(MCUCR, ISC00);
			  CLEAR_BIT(MCUCR, ISC01);
			break;
		}
	   SET_BIT(GIFR, INTF0);  /*Clear flag*/
       SET_BIT(GICR, INT0);	//enable INT0
 //      CLEAR_BIT(GICR, INT1);	//disable INT1
 //      CLEAR_BIT(GICR, INT2);	//disable INT2
	  break;
	case 1:
		switch(Config_ptr->Mode)
		{
		case FALLING_Edge:
			CLEAR_BIT(MCUCR, ISC10);
			  SET_BIT(MCUCR,  ISC11);
			break;
		case RISING_Edge:
			  SET_BIT(MCUCR, ISC10);
			  SET_BIT(MCUCR,  ISC11);
			break;
		case IOC:
			  SET_BIT(MCUCR, ISC10);
			  CLEAR_BIT(MCUCR,  ISC11);
			break;
		case LOW_Level:
			  CLEAR_BIT(MCUCR, ISC10);
			  CLEAR_BIT(MCUCR,  ISC11);
			break;
		}
	    SET_BIT(GIFR, INTF1);  /*Clear flag*/
	    SET_BIT(GICR, INT1);	//enable INT1
//	    CLEAR_BIT(GICR, INT0);	//disable INT0
//	    CLEAR_BIT(GICR, INT2);	//disable INT2
	  break;
	case 2:
		switch(Config_ptr->Mode)
		{
		case FALLING_Edge:
			CLEAR_BIT(MCUCR, ISC2);
			break;
		case RISING_Edge:
		    SET_BIT(MCUCR, ISC2);
			break;
		}
		 SET_BIT(GIFR, INTF2);  /*Clear flag*/
	     SET_BIT(GICR, INT2);	//enable INT2
//	     CLEAR_BIT(GICR, INT1);	//disable INT1
//	     CLEAR_BIT(GICR, INT0);	//disable INT0
		break;
	}


}

void EXTI_Enable(uint8 int_num)
{
	switch(int_num)
	{
	case 0:
	   SET_BIT(GICR, INT0);	//enable INT0
	   break;
	case 1:
	   SET_BIT(GICR, INT1);	//enable INT1
	   break;
	case 2:
	   SET_BIT(GICR, INT2);	//enable INT2
	   break;
	}
}
void EXTI_Disable(uint8 int_num)
{
	switch(int_num)
	{
	case 0:
	   CLEAR_BIT(GICR, INT0);	//disable INT0
	   break;
	case 1:
	   CLEAR_BIT(GICR, INT1);	//disable INT1
	   break;
	case 2:
	   CLEAR_BIT(GICR, INT2);	//disable INT2
	   break;
	}
}

void EXTI_SetCallBack(void(*ptrf)(void))
{
	pointer_to_func=ptrf;
}

ISR(INT0_vect){

//    pointer_to_func(); no necessity for callback func now
	++button1_flag;
	_delay_ms(30);          //for debouncing
	CLEAR_BIT(GIFR,INTF0);   //clearing the flag
}

ISR(INT1_vect){
	 ++button2_flag;
	_delay_ms(30);          //for debouncing
	CLEAR_BIT(GIFR,INTF1);   //clearing the flag
}

