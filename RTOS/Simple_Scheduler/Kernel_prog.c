/*
 * Kernel_prog.c
 *
 *  Created on: Nov 20, 2023
 *  Author: Menna Sayed
 */
#include"Kernel_interface.h"
#include"Kernel_config.h"
#include"Kernel_Ptivate.h"
#include "Timer2_Driver.h"
#include "GIE.h"

static Task_t private_arrayOfTasks[RTOS_KERNEL_NUM_TASKS];

void RTOS_KERNEL_voidStartScheduling(void)
{
	config_struc config ={compare_2,0,249,F_64};  //Rtos Tick 1ms
	Timer2_init_Async(&config);
	Timer2_setCallBack(private_voidscheduler);

	Global_InterruptEnable();
}
uint8 RTOS_KERNEL_voidCreateTask(uint8 TaskPriority,uint16 TaskPriodicity,void(*ptrToFun)(void))
{
	uint8 Locale_ErrorState = E_OK;
   if((TaskPriority < RTOS_KERNEL_NUM_TASKS)&&(ptrToFun != NULL_PTR)&&(private_arrayOfTasks[TaskPriority].pTaskFun == NULL_PTR))
   {
	   private_arrayOfTasks[TaskPriority].priodicity=TaskPriodicity;
	   private_arrayOfTasks[TaskPriority].pTaskFun = ptrToFun;
	   private_arrayOfTasks[TaskPriority].TaskState = RESUME_TASK;
   }
   else
   {
	   Locale_ErrorState = E_NOK;
   }
   return Locale_ErrorState;
}
static void private_voidscheduler(void)
{
   static uint16 Locale_u16TickCount=0;
   Locale_u16TickCount++;
   uint8 i;
   for(i=0;i<RTOS_KERNEL_NUM_TASKS;i++)
   {
      if((Locale_u16TickCount % (private_arrayOfTasks[i].priodicity)==0)&&(private_arrayOfTasks[i].pTaskFun!= NULL_PTR)&&(private_arrayOfTasks[i].TaskState== RESUME_TASK))  //mn moda3afatha (baky el kesma b zero
      {
           /*Call Task Func*/
    	  private_arrayOfTasks[i].pTaskFun();

      }else
      {

      }
   }
}

void RTOS_KERNEL_voidDeleteTask(uint8 TaskPriority)
{
	if(TaskPriority < RTOS_KERNEL_NUM_TASKS )
	{
		private_arrayOfTasks[TaskPriority].pTaskFun= NULL_PTR;
	}
}

void RTOS_KERNEL_voidSuspendTask(uint8 TaskPriority)
{
	if(TaskPriority < RTOS_KERNEL_NUM_TASKS )
	{
		private_arrayOfTasks[TaskPriority].TaskState = SUSPEND_TASK;
	}
}

void RTOS_KERNEL_voidResumeTask(uint8 TaskPriority)
{
	if(TaskPriority < RTOS_KERNEL_NUM_TASKS )
		{
			private_arrayOfTasks[TaskPriority].TaskState = RESUME_TASK;
		}
}
