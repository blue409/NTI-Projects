/*
 * main.c
 *
 *  Created on: Nov 19, 2023
 *  Author: Menna Sayed
 */
#include "Timer2_Driver.h"
#include "GIE.h"
#include "Kernel_interface.h"

void App1(void);
void App2(void);
void App3(void);


int main(void)
{
	 DIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_OUTPUT);//Red
	 DIO_setupPinDirection(PORTA_ID,PIN4_ID,PIN_OUTPUT);//Green
	 DIO_setupPinDirection(PORTA_ID,PIN5_ID,PIN_OUTPUT);//Blue

	 RTOS_KERNEL_voidCreateTask(0,250,App1);
	 RTOS_KERNEL_voidCreateTask(1,2000,App2);
	 RTOS_KERNEL_voidCreateTask(2,5000,App3);

//	 RTOS_KERNEL_voidDeleteTask(2);
	 RTOS_KERNEL_voidStartScheduling();
	while(1)
	{
           /*Scheduler sNever EnTer Here*/
	}
	return 0;
}

void App1(void)       //called every 1 sec...through callback concept
{
	DIO_togglePin(PORTB_ID,PIN7_ID);
}
void App2(void)
{
	DIO_togglePin(PORTA_ID,PIN4_ID);
	RTOS_KERNEL_voidSuspendTask(0);
}
void App3(void)
{
	DIO_togglePin(PORTA_ID,PIN5_ID);
//	RTOS_KERNEL_voidDeleteTask(2);//self delete after one time
//	RTOS_KERNEL_voidDeleteTask(0);//Deleting another Task
	RTOS_KERNEL_voidResumeTask(0);
}

