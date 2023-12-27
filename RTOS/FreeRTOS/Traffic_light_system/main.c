/*
 * main.c
 *
 *  Created on:  Dec 3 , 2023
 *  Author: dell
 */

/*MCAL*/

/*FreeRTOS*/
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "seven_segment.h" 
#define F_CPU 16000000

void SS_DISP(u8 second);
void COUNTER_States(void*pvParameters);
void RED_LIGHT(void*pvParameters);
void YELLOW_LIGHT(void*pvParameters);
void GREEN_LIGHT(void* pvParameters);

#define TASK1_PRIORITY 1
#define TASK2_PRIORITY 2
#define TASK3_PRIORITY 3
#define TASK4_PRIORITY 4

/*TASK HANDLES*/
TaskHandle_t xTask1_H = NULL;
TaskHandle_t xTask2_H = NULL;
TaskHandle_t xTask3_H = NULL;
TaskHandle_t xTask4_H = NULL;

u8 Reverse_flag = 0;
u8 seconds = 90;
u8 Total_sec_counter = 0;

SemaphoreHandle_t xSemaphore_Seconds = NULL;

int main()
{
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);//Red
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN4, DIO_PIN_OUTPUT); //yellow
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN5, DIO_PIN_OUTPUT);//green
	DIO_voidSetPortDirection(DIO_PORTC,DIO_PORT_OUTPUT);
	
	SevenSegmentCommonAnode_INIT();
//	vSemaphoreCreateBinary(xSemaphore_Seconds);
	xSemaphore_Seconds = xSemaphoreCreateMutex();
	
	xTaskCreate(COUNTER_States,(const char*)"COUNT",1000,NULL,TASK1_PRIORITY,&xTask1_H);
	xTaskCreate(RED_LIGHT,(const char*)"RED",800,NULL,TASK2_PRIORITY,&xTask2_H);
	xTaskCreate(YELLOW_LIGHT,(const char*)"YELLO",800,NULL,TASK4_PRIORITY,&xTask3_H);
	xTaskCreate(GREEN_LIGHT,(const char*)"GREEN",800,NULL,TASK3_PRIORITY,&xTask4_H);

	 vTaskStartScheduler();

    while(1)
    {
    	/* Never Enters Here */
    }

 return 0;
}


void COUNTER_States(void* pvParameters)
{
	vTaskDelay(1000);
	if( xSemaphore_Seconds != NULL )
	{
//		if( xSemaphoreTake(xSemaphore_Seconds, ( TickType_t ) 50 ) == pdTRUE )
//		{
		xSemaphoreTake(xSemaphore_Seconds, ( TickType_t ) portMAX_DELAY );
//		{
          if(Total_sec_counter == 0)
           {
        	   seconds=90; //RED STATE
           }
          if(Total_sec_counter == 91)
		  {
		     seconds=60; //GREEN STATE
		  }
          if(Total_sec_counter == 152)
		  {
		   seconds=10; //Yellow STATE
		  }
          if(Total_sec_counter == 163)
		  {
		   seconds=90; //RED STATE---re enter
		   Total_sec_counter = 0;
		  }
          seconds--;
          Total_sec_counter++;
		  xSemaphoreGive(xSemaphore_Seconds);
//		}
//		else
//		{
			/* We could not obtain the semaphore and can therefore not access the shared resource safely. */
//		}
	 // }
	}
	else
	{
		DIO_voidSetPinValue(DIO_PORTC, DIO_PIN7, 1);  //check
	}
    while(1)
    {
    //	DIO_voidSetPortValue(DIO_PORTC,Total_sec_counter);
    //	vTaskDelay(20);
    }
}

void RED_LIGHT(void* pvParameters)       //called every 1 sec...through callback concept
{
//	vTaskDelay(120);                     //Task Periodicity
	while(1)
	{
		if( xSemaphore_Seconds != NULL )
		{
			if( xSemaphoreTake(xSemaphore_Seconds, ( TickType_t ) 5 ) == pdTRUE )
			{
				if( Total_sec_counter < 91)
				{
					DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, 1);
					SS_DISP(seconds);
					vTaskDelay(20);
			    }
				else
				{
					DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, 0);
					CLR_BIT(PORTB, 7);
					DIO_voidSetPortValue(DIO_PORTC,Total_sec_counter);
				//	vTaskDelay(10);
				}
			  xSemaphoreGive(xSemaphore_Seconds);
			}
			else
			{

			}
		}

	}
}
void YELLOW_LIGHT(void* pvParameters)
{
	vTaskDelay(100);
	//vTaskDelay(120);
	while(1)
	{
		if( xSemaphore_Seconds != NULL )
		{
			if( xSemaphoreTake(xSemaphore_Seconds, ( TickType_t ) 5 ) == pdTRUE )
			{
				if((Total_sec_counter >=152)&&(Total_sec_counter < 163))
				{
				    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN4, 1);
				    vTaskDelay(20);
					SS_DISP(seconds);

				}
				else
				{
					DIO_voidSetPinValue(DIO_PORTA, DIO_PIN4, 0);
					CLR_BIT(PORTA, 4);
				//	 vTaskDelay(20);
				}
				xSemaphoreGive(xSemaphore_Seconds );
			}
			else
			{

			}
		}

	}
}
void GREEN_LIGHT(void* pvParameters)
{
	vTaskDelay(200);
	//vTaskDelay(120);
	while(1)
	{
		if( xSemaphore_Seconds != NULL )
		{
			if( xSemaphoreTake(xSemaphore_Seconds, ( TickType_t ) 5 ) == pdTRUE )
			{
				if((Total_sec_counter >=91)&&(Total_sec_counter < 152))
				{	
					DIO_voidSetPinValue(DIO_PORTA, DIO_PIN5, 1);
					SS_DISP(seconds);
					vTaskDelay(20);
				}
				else
				{
					DIO_voidSetPinValue(DIO_PORTA, DIO_PIN5, 0);
					CLR_BIT(PORTA, 5);
				//	vTaskDelay(20);
				}
				xSemaphoreGive(xSemaphore_Seconds );
			}
			else
			{

			}
		}

	}
}

void SS_DISP(u8 second)
{
	 if(second>9)
	 {
		 SevenSegmentCommonAnode((u8)(second-((second/10)*10)),1); //units
		 vTaskDelay(8);
		 SevenSegmentCommonAnode(second/10,2);//tens
		 vTaskDelay(8);

	 }else
	 {
		 SevenSegmentCommonAnode(second,1);//units
		 SevenSegmentCommonAnode(0,2);//tens
		// vTaskDelay(80);
	 }

}

/*
 * void COUNTER_States(void* pvParameters)
{
	vTaskDelay(500);
	if( xSemaphore_Seconds != NULL )
	{
		if( xSemaphoreTake(xSemaphore_Seconds, ( TickType_t ) 30 ) == pdTRUE )
		{

			if((Total_sec_counter >=0) && (Total_sec_counter < 91) && (Reverse_flag == 0))  //Red  (0 <= Total_sec_counter < 91)
			{
				if (Total_sec_counter == 0)
				{
					seconds = 90;
				}
			}

			if((Total_sec_counter >=91)&&(Total_sec_counter < 101) && (Reverse_flag == 0))  //Yellow (91 <= Total_sec_counter < 101)
			{
				if (Total_sec_counter == 91)
				{
					seconds = 10;
				}
			}

			if((Total_sec_counter >=101)&&(Total_sec_counter < 161) && (Reverse_flag == 0)) //Green  (101 <= Total_sec_counter < 161)
			{
				if (Total_sec_counter == 101)
				{
					seconds = 60;
				}
			}
			seconds --;                   //decrement seconds
			if (Reverse_flag == 0)        // going Red --> Yellow -->Green
			{
				Total_sec_counter ++;
			}
			else if (Reverse_flag == 1)   // going Yellow --> Red --> Yellow -->Green
			{
				Total_sec_counter --;
			}

			if (Total_sec_counter >= 160)
			{
				Reverse_flag = 1;
				Total_sec_counter = 100;
				seconds = 10;
			}
			if ((Total_sec_counter == 91) && (Reverse_flag == 1))
			{
				Total_sec_counter = 0;
				Reverse_flag = 0;
			}
		xSemaphoreGive(xSemaphore_Seconds);
		}
		else
		{
			/* We could not obtain the semaphore and can therefore not access the shared resource safely.
		}
	}
}
 * */

