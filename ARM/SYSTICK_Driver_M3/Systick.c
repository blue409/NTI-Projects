
#include "SYSTICK_config.h"
#include <math.h>

static uint32 Num_of_overflows=0;  // for more than 1 second
static uint32 counter=0;

systickcbf_t APPcbf = NULL_PTR ;

uint8 SYSTICK_Init(void)
{
	/* CLK source and interrupt enable */
	STK_CTRL |= SYSTICK_CLK_AHB  ;       //AHB/8
	STK_VAL = SYSTICK_CLEAR_COUNTER;        //clearing the counter
	STK_CTRL |= SYSTICK_TICK_INT_ENABLE;   // Intt Enable
	STK_CTRL &= SYSTICK_DISABLE;
	return E_OK;
}
uint8 SYSTICK_Start(void)
{
	/* enable counter */
//	STK_VAL = SYSTICK_CLEAR_COUNTER;      //clearing the counter
	STK_CTRL |= SYSTICK_ENABLE;
//or	SET_BIT(STK_CTRL,0);
	return E_OK;
}
uint8 SYSTICK_Stop(void)
{
	/* disable counter */
	STK_CTRL &= SYSTICK_DISABLE;
//or	CLEAR_BIT(STK_CTRL,0);
	return E_OK;
}
void SYSTICK_SetCallback(systickcbf_t cbf)
{
	/* callback function */
	APPcbf = cbf;

}
uint8 SYSTICK_SetTime_ms(uint32 time_us,uint32 clk)  //SYSTICK_SetTime_ms(1000,8000000)
{
	/* disable Systick
	 * add value to STK LOAD
	 * clear couter reg. and Enable systick
	 *
	 * use this EQ: N = Tov * (Fcpu/Presc )
	 * Tov in ms
	 * clk of systick = (Fcpu/Presc ) in HZ */

	uint32 var =(time_us/1000)*clk;
	STK_LOAD = var;

	return E_OK;
}
void SysTick_Handler(void)  //called at least every 1ms or 1us
{
	/* clear The intt flag by clearing the counter reg*/
   if(counter>=Num_of_overflows-1)
   {
		if(APPcbf != NULL_PTR)
		{
		  APPcbf();              //call the call back function
		}
		counter =0;
   }else{
	   counter++;
   }

//	STK_VAL = SYSTICK_CLEAR_COUNTER;
}
uint8 SYSTICK_SetTime(uint32 time_s,uint32 clk)   //SYSTICK_SetTime(5000,8000000)
{
	/*
	 * use this EQ: N = Tov * (Fcpu/Presc )
	 * Tov in us
	 * clk of systick = (Fcpu/Presc ) in HZ
	 */
	Num_of_overflows = time_s/1000;

	SYSTICK_SetTime_ms(1000,clk);  //one second

	//	uint32 var =(float32)time_us *(float32)clk*(float32)0.000001;
	return E_OK;
}
