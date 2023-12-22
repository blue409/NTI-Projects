#ifndef RCC_PRIV_H
#define	RCC_PRIV_H
#include "std_types.h"
typedef struct
{
	volatile uint32 CR;
	volatile uint32 CFGR;
	volatile uint32 CIR;
	volatile uint32 APB2RSTR;
	volatile uint32 APB1RSTR;
	volatile uint32 AHBENR;
	volatile uint32 APB2ENR;
	volatile uint32 APB1ENR;
	volatile uint32 BDCR;
	volatile uint32 CSR;
	
}RCC;

#define MRCC	((volatile RCC * )0x40021000)

#endif
