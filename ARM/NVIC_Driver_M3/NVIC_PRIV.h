#ifndef DNVIC_PRIV_H_
#define DNVIC_PRIV_H_


/**
 * @def 	NVIC_BASE_ADDRESS
 * @brief 	NVIC peripheral base address 
 */
#define NVIC_BASE_ADDRESS  ((NVIC_t*) 0XE000E100)
/**
 * @def 	SCB_AIRCR
 * @brief 	NVIC Application Interrupt and Reset Control Register 
 */
#define SCB_AIRCR *((volatile uint32*) 0XE000ED0C)

/**
 * @def 	SCB_VTOR
 * @brief 	Vector Table Offset register
 */
#define SCB_VTOR  *((volatile uint32*) 0xE000ED08)


/**
 * @typedef		NVIC_t 
 * @brief		Struct of All Registers in NVIC Driver	
 */
//typedef struct
//{
//	uint32 ISER[8];
//	uint32 Reserved[24];
//	uint32 ICER[8];
//	uint32 Reserved1[24];
//	uint32 ISPR[8];
//	uint32 Reserved2[24];
//	uint32 ICPR[8];
//	uint32 Reserved3[24];
//	uint32 IABR[8];
//	uint32 Reserved4[56];
//	uint8 IPR[240];
//}NVIC_t;
//
///**
// * @brief NV pointer to struct NVIC_t
// */
//NVIC_t* NV=NVIC_BASE_ADDRESS;

#endif
