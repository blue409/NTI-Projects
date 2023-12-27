/*
 *  Timer0_Driver.c
 *  Description:This driver for timer 0 and supports two modes compare mode and normal mode
 *  Created on: Oct 31, 2021
 *  Author: Menna Sayed
 **********************************************************************************************************/
#include "common_macros.h"
#include "Timer2_Driver.h"

/**********************************************************************************************************/

//config_struct config_str ={normal,0,0,F_1};  /*for compare mode just write here compare instead of normal also*/

/***********************************************************************************************************/
 static void (*prv_CallBack_ptr)(void) = NULL_PTR;              //pointer used to hold address of a function
// extern uint8 seconds;
// extern uint8 minutes;
// extern uint8 hours;
/***********************************************************************************************************/
 ISR(TIMER2_OVF_vect)                          /*if the normal mode is on and this interrupt will be generated */
  {
	 static uint32 count=0;

	 if(count>=1000)
	 {
          if(prv_CallBack_ptr != NULL_PTR)
          {
//        	DIO_togglePin(PORTC_ID,PIN2_ID);
        	count=0;
          	prv_CallBack_ptr();                                    /***
          	                                   if interrupt ocurred and g_CallBack_ptr is pointing to a function ..
          	                                      then we call this function through this general call back pointer.
          	                                                     ****/

          SET_BIT(TIFR,TOV2);//clear flag
          }

	}else{
	      count++;
	      SET_BIT(TIFR,TOV2);//clear flag
        }

  }

 ISR(TIMER2_COMP_vect)                        /*if the compare mode is on.. this interrupt will be generated */
  {

      if(prv_CallBack_ptr != NULL_PTR)
      {

            prv_CallBack_ptr();
            SET_BIT(TIFR,OCF2);//clear flag
      }
     else
	 {
	      SET_BIT(TIFR,OCF2);//clear flag
	 }
  }


void Timer2_init_Async(config_struc*str)//intt
{
	TCCR2=0;                                   /*initial value for setting the bits correctly*/
    SET_BIT(TCCR2,FOC2);                       /*since the two modes are not pwm*/
    TCCR2 |= ((str->mode)<<WGM21) ;            /*for mode selection*/

                                                  /*if normal mode*/
  if(str->mode == normal_2)
    {
        TCNT2 = str->initial_val;

        TIMSK =0;
        SET_BIT(TIMSK,TOIE2);                    /*for enabling the interrupt in normal mode*/

        TCCR2 |= (str->presc) ;                   /*setting the prescaler*/

    }
 else{                                               /*if compare mode*/
    TCNT2 = str->initial_val;

    OCR2 = str->compare_val;

    TIMSK =0;

    SET_BIT(TIMSK,OCIE2);                            /*for enabling the interrupt in compare mode*/

    TCCR2 |= (str->presc) ;

      }

}

void Timer2_init_sync(config_struc_sync* str)      //polling
{
	TCCR2=0;                                   /*initial value for setting the bits correctly*/
    SET_BIT(TCCR2,FOC2);                       /*since the two modes are not pwm*/
    TCCR2 |= ((str->mode)<<WGM21) ;            /*for mode selection*/

                                                  /*if normal mode*/
    if(str->mode == normal_2)
    {

        TCNT2 = str->initial_val;

        TIMSK =0;

        CLEAR_BIT(TIMSK,TOIE2);                    /*for enabling the interrupt in normal mode*/

//        TCCR0 |= (str->presc) ;                   /*setting the prescaler*/

   }
  else{                                               /*if compare mode*/
      TCNT2 = str->initial_val;

      OCR2 = str->compare_val;

      TIMSK =0;

      CLEAR_BIT(TIMSK,OCIE2);                            /*for enabling the interrupt in compare mode*/

//    TCCR0 |= (str->presc) ;

      }

}

/*
 * Used To stop the Timer
 * */
void Timer2_DeInit(void)
{

	TCCR2 = 0;
	TCNT2 =0;
	OCR2 = 0;
	TIMSK = 0;

}

void Delay_ms_sync_2(uint32 time)
{
	uint32 counter=0;
	start_synch_2(Presc_sync2);       //for starting the timer counting
	while(counter<time){
	while(GET_BIT(TIFR,TOV2)==0);
	counter++;
	SET_BIT(TIFR,TOV2);//clear flag
	}
}

/* Function used to call another function when ISR is being executed
 * takes address of a function(its name) as input parameter
 *                                                              */

void Timer2_setCallBack(void(*ptr_func)(void))
{

	prv_CallBack_ptr = ptr_func;

}


void start_synch_2(uint8 presc)
{

	TCCR2 |= (presc) ;
}

