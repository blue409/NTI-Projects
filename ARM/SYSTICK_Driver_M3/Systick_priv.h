#ifndef _SYSTICK_PRIV_H_
#define _SYSTICK_PRIV_H_
#include "std_types.h"

#define STK_CTRL	*((volatile uint32*)0xE000E010)
#define STK_LOAD	*((volatile uint32*)0xE000E014)
#define STK_VAL		*((volatile uint32*)0xE000E018)

#endif

