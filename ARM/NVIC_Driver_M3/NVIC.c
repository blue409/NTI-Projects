/**
 * @headerfile STD_TYPES.h
 */
#include "STD_TYPES.h"
//#include "DIO_interface.h"
/**
 * @headerfile DNVIC.h
 */
#include "NVIC.h"

typedef struct
{
	uint32 ISER[8];
	uint32 Reserved[24];
	uint32 ICER[8];
	uint32 Reserved1[24];
	uint32 ISPR[8];
	uint32 Reserved2[24];
	uint32 ICPR[8];
	uint32 Reserved3[24];
	uint32 IABR[8];
	uint32 Reserved4[56];
	uint8 IPR[240];
}NVIC_t;

/**
 * @brief NV pointer to struct NVIC_t
 */
NVIC_t* NV=NVIC_BASE_ADDRESS;

uint8 DNVIC_EnableIRQ(uint8 IRQn)
{
	//or	NV->ISER[IRQn/32] |= 1<<IRQn%32; //better method
	uint8 Local_u8ErrorState = E_OK;
	if(IRQn<32)
	{

		NV->ISER[0] |= (1<<IRQn);
	}else if((31<IRQn)&&(IRQn<64))
	{
		NV->ISER[1] |= (1<<(IRQn-32));
	}else if((IRQn>64)&&(IRQn<67))
	{
		NV->ISER[2] |= (1<<(IRQn-64));
	}else
	{
		Local_u8ErrorState = E_NOK;
	}

  return Local_u8ErrorState;
}


uint8 DNVIC_DisableIRQ(uint8 IRQn)
{
	uint8  Local_u8ErrorState = E_OK;
	if(IRQn<32)
	{
		NV->ICER[0] |= (1<<IRQn);
	}else if((31<IRQn)&&(IRQn<64))
	{
		NV->ICER[1] |= (1<<(IRQn-32));
	}else if((IRQn>64)&&(IRQn<67))
	{
		NV->ICER[2] |= (1<<(IRQn-64));
	}else
	{
		Local_u8ErrorState = E_NOK;
	}

  return Local_u8ErrorState;
}

uint8 DNVIC_SetPendingIRQ (uint8 IRQn)
{
	uint8  Local_u8ErrorState = E_OK;
	if(IRQn<32)
	{
		NV->ISPR[0] |= (1<<IRQn);
	}else if((31<IRQn)&&(IRQn<64))
	{
		NV->ISPR[1] |= (1<<(IRQn-32));
	}else if((IRQn>64)&&(IRQn<67))
	{
		NV->ISPR[2] |= (1<<(IRQn-64));
	}else
	{
		Local_u8ErrorState = E_NOK;
	}

  return Local_u8ErrorState;
}

uint8 DNVIC_ClearPendingIRQ (uint8 IRQn)
{
	uint8  Local_u8ErrorState = E_OK;
	if(IRQn<32)
	{
		NV->ICPR[0] |= (1<<IRQn);
	}else if((31<IRQn)&&(IRQn<64))
	{
		NV->ICPR[1] |= (1<<(IRQn-32));
	}else if((IRQn>64)&&(IRQn<67))
	{
		NV->ICPR[2] |= (1<<(IRQn-64));
	}else
	{
		Local_u8ErrorState = E_NOK;
	}

  return Local_u8ErrorState;
}

uint8 DNVIC_GetPendingIRQ (uint8 IRQn, uint8 *Val)
{
	uint8  Local_u8ErrorState = E_OK;
	if(IRQn<32)
	{
		*Val = GET_BIT(NV->ICPR[0],IRQn); //NV->ICPR[0] |= (1<<IRQn);
	}else if((31<IRQn)&&(IRQn<64))
	{
		*Val = GET_BIT(NV->ICPR[1],(IRQn-32));//NV->ICPR[1] |= (1<<(IRQn-32));
	}else if((IRQn>64)&&(IRQn<67))
	{
		*Val = GET_BIT(NV->ICPR[2],(IRQn-64));//NV->ICPR[2] |= (1<<(IRQn-64));
	}
	else
	{
		Local_u8ErrorState = E_NOK;
	}

  return Local_u8ErrorState;
}

uint8 DNVIC_GetActive (uint8 IRQn, uint8 *Val)
{
	uint8  Local_u8ErrorState = E_OK;
	if(IRQn<32)
	{
		*Val = GET_BIT(NV->IABR[0],IRQn); //NV->ICPR[0] |= (1<<IRQn);
	}else if((31<IRQn)&&(IRQn<64))
	{
		*Val = GET_BIT(NV->IABR[1],(IRQn-32));//NV->ICPR[1] |= (1<<(IRQn-32));
	}else if((IRQn>64)&&(IRQn<67))
	{
		*Val = GET_BIT(NV->IABR[2],(IRQn-64));//NV->ICPR[2] |= (1<<(IRQn-64));
	}
	else
	{
		Local_u8ErrorState = E_NOK;
	}


  return Local_u8ErrorState;
}

uint8 DNVIC_SetPriorityGrouping(uint32 priority_grouping)
{
	SCB_AIRCR = PASSWORD_MASK;                                     //To enable writing to this register
	SCB_AIRCR |= (priority_grouping);                              //To write the no that indicates how many groups and subgroups we will have
    return E_OK;
}

uint8 DNVIC_SetPriority (uint8 IRQn, uint8 group, uint8 subgroup)   //changed param for ease of use
{
	 NV->IPR[IRQn] |= GET_IRQ_PRIORITY(group,subgroup);           //IPR is byte accessible
	 return E_OK;
}

uint8 DNVIC_GetPriority (uint8 IRQn, uint8 *priority)
{
    *priority = (NV->IPR[IRQn])>>4;
}
/* must develop after reading ch7 and ending the task needed */
void DNVIC_voidDisableAllPeripherals(void)
{
	NV->ISER[0] = DISABLE_ALL_INT;
	NV->ISER[1] = DISABLE_ALL_INT;
}


void DNVIC_voidEnableAllPeripherals(void)
{
	NV->ISER[0] = ENABLE_ALL_INT;
	NV->ISER[1] = ENABLE_ALL_INT;
	
}

inline void DNVIC_voidDisableAllFaults(void)
{
	//__asm("cpsid f");
}


inline void DNVIC_voidEnableAllFaults(void)
{
	//__asm("cpsie f");
}

inline void DNVIC_voidSetBASEPRI(uint8 priority)
{
//  __asm("MOV R6,#priority \n \t"
//	    "MSR BASEPRI,R6\n");
////	  __set_BASEPRI(priority);
}
void DNVIC_voidChangeVectorOffset (uint32 offset)
{
	SCB_VTOR |= ((offset & 0x3FFFFF)<<9);   //mask to ensure the last 2 bits remain zerors
}

void DNVIC_voidSysReset(void)
{
	SET_BIT(SCB_AIRCR,2);
}




