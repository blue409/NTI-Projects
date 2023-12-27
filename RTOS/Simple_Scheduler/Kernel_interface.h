/*
 * Kernel_interface.h
 *
 *  Created on: Nov 20, 2023
 *      Author: dell
 */

#ifndef KERNEL_INTERFACE_H_
#define KERNEL_INTERFACE_H_
#include "Kernel_Ptivate.h"

#define SUSPEND_TASK 1
#define RESUME_TASK 2

void RTOS_KERNEL_voidStartScheduling(void);
uint8 RTOS_KERNEL_voidCreateTask(uint8 TaskPriority,uint16 TaskPriodicity,void(*ptrToFun)(void));
void RTOS_KERNEL_voidDeleteTask(uint8 TaskPriority);
void RTOS_KERNEL_voidSuspendTask(uint8 TaskPriority);
void RTOS_KERNEL_voidResumeTask(uint8 TaskPriority);

#endif /* KERNEL_INTERFACE_H_ */
