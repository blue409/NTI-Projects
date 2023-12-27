/*
 * Kernel_Ptivate.h
 *
 *  Created on: Nov 20, 2023
 *  Author: Menna Sayed
 */

#ifndef KERNEL_PTIVATE_H_
#define KERNEL_PTIVATE_H_
#include "std_types.h"



typedef struct
{
	uint16 priodicity;
	void(*pTaskFun)(void);
    uint8 TaskState;
}Task_t;

static void private_voidscheduler(void);

#endif /* KERNEL_PTIVATE_H_ */
