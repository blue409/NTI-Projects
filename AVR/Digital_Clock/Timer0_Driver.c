/*
 *  Timer0_Driver.c
 *  Description:This driver for timer 0 and supports two modes compare mode and normal mode
 *  Created on: Oct 31, 2021
 *  Author: Menna Sayed
 **********************************************************************************************************/
#include "common_macros.h"
#include "Timer0_Driver.h"

/**********************************************************************************************************/

//config_struct config_str ={normal,0,0,F_1};  /*for compare mode just write here compare instead of normal also*/

/***********************************************************************************************************/
 void (*g_CallBack_ptr)(void) = NULL_PTR;              //pointer used to hold address of a function
// extern uint8 seconds;
// extern uint8 minutes;
// extern uint8 hours;
/***********************************************************************************************************/
 ISR(TIMER0_OVF_vect)                          /*if the normal mode is on and this interrupt will be generated */
  {
	 static uint32 count=0;

	 if(count>=1000)
	 {
          if(g_CallBack_ptr != NULL_PTR)
          {
//        	DIO_togglePin(PORTC_ID,PIN2_ID);
        	count=0;
          	g_CallBack_ptr();                                    /***
          	                                   if interrupt ocurred and g_CallBack_ptr is pointing to a function ..
          	                                      then we call this function through this general call back pointer.
          	                                                     ****/

          SET_BIT(TIFR,TOV0);//clear flag
          }

	}else{
	      count++;
	      SET_BIT(TIFR,TOV0);//clear flag
        }

  }

 ISR(TIMER0_COMP_vect)                        /*if the compare mode is on.. this interrupt will be generated */
  {
      if(g_CallBack_ptr != NULL_PTR)
      {
/*      	g_CallBack_ptr();                                    /***
      	                                   if interrupt ocurred and g_CallBack_ptr is pointing to a function ..
      	                                      then we call this function through this general call back pointer.
      	                                                    ****/
     }

  }


void Timer0_init_Async(config_struc*str)
{
	TCCR0=0;                                   /*initial value for setting the bits correctly*/
    SET_BIT(TCCR0,FOC0);                       /*since the two modes are not pwm*/
    TCCR0 |= ((str->mode)<<WGM01) ;            /*for mode selection*/

                                                  /*if normal mode*/
  if(str->mode == normal)
    {
        TCNT0 = str->initial_val;

        TIMSK =0;
        SET_BIT(TIMSK,TOIE0);                    /*for enabling the interrupt in normal mode*/

        TCCR0 |= (str->presc) ;                   /*setting the prescaler*/

    }
 else{                                               /*if compare mode*/
    TCNT0 = str->initial_val;

    OCR0 = str->compare_val;

    TIMSK =0;

    SET_BIT(TIMSK,OCIE0);                            /*for enabling the interrupt in compare mode*/

    TCCR0 |= (str->presc) ;

      }

}

void Timer0_init_sync(config_struc_sync* str)      //polling
{
	TCCR0=0;                                   /*initial value for setting the bits correctly*/
    SET_BIT(TCCR0,FOC0);                       /*since the two modes are not pwm*/
    TCCR0 |= ((str->mode)<<WGM01) ;            /*for mode selection*/

                                                  /*if normal mode*/
    if(str->mode == normal)
    {

        TCNT0 = str->initial_val;

        TIMSK =0;

        CLEAR_BIT(TIMSK,TOIE0);                    /*for enabling the interrupt in normal mode*/

//        TCCR0 |= (str->presc) ;                   /*setting the prescaler*/


    }


 else{                                               /*if compare mode*/
    TCNT0 = str->initial_val;

    OCR0 = str->compare_val;

    TIMSK =0;

    CLEAR_BIT(TIMSK,OCIE0);                            /*for enabling the interrupt in compare mode*/

//    TCCR0 |= (str->presc) ;

      }

}

/*
 * Used To stop the Timer
 * */
void Timer0_DeInit(void)
{

	TCCR0 = 0;
	TCNT0 =0;
	OCR0 = 0;
	TIMSK = 0;

}

void Delay_ms_sync(uint32 time)
{
	uint32 counter=0;
	start_synch( Presc_sync);       //for starting the timer counting
	while(counter<time){
	while(GET_BIT(TIFR,TOV0)==0);
	counter++;
	SET_BIT(TIFR,TOV0);//clear flag
	}
}

/* Function used to call another function when ISR is being executed
 * takes address of a function(its name) as input parameter
 *                                                              */

void Timer0_setCallBack(void(*ptr_func)(void))
{

	g_CallBack_ptr = ptr_func;

}


void start_synch(uint8 presc)
{

	TCCR0 |= (presc) ;
}




