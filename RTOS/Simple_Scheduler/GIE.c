/*
 * GIE.c
 *
 *  Created on: Oct 27, 2023
 *      Author: dell
 */
#include "GIE.h"


void Global_InterruptEnable(void)
{
	SET_BIT(SREG,Ibit);
}


void Global_InterruptDisable(void)
{
	CLEAR_BIT(SREG,Ibit);
}
