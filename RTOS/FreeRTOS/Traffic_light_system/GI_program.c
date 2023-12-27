/*
 * GI_program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Kareem Hussein
 */

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "GI_interface.h"
#include "GI_register.h"

void GI_voidEnable(void)
{
	SET_BIT(SREG,I);
}


void GI_voidDisable(void)
{
   CLR_BIT(SREG,I);	
}
