/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

//#include "std_types.h"
#include "common_macros.h"

#include "RCC_int.h"
#include "RCC_cconfig.h"


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize RCC	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void MRCC_voidInit(void)
{
	
		
		#if 	CLOCK_TYPE == HSI
		               /* internal 8 MHZ RC oscillator  */
	 	 	 	SET_BIT(MRCC->CR,CR_HSION );          /*	HSI clock enable	*/
				
				while(GET_BIT(MRCC->CR,CR_HSIRDY)==0);/*	HSI Ready Flag		        */

				CLEAR_BIT(MRCC->CFGR,0);              /*HSI selected as system clock ---sw */
				CLEAR_BIT(MRCC->CFGR,1);
                                                      /*  TODO:Reading SWS flag            */
		
		#elif	CLOCK_TYPE == HSE
				SET_BIT(MRCC->CR,CR_HSEON );          /*	HSE clock enable				*/
				
				while(GET_BIT(MRCC->CR,CR_HSERDY)==0);/*	HSE Ready Flag					*/
				
				SET_BIT(MRCC->CFGR,0);                /*HSE selected as system clock		*/
				CLEAR_BIT(MRCC->CFGR,1);
			
				
		#elif	CLOCK_TYPE == PLL    /*zawdy el pll check*/

		/*PLL multiplication factor*/		
		#if CLOCK_FACTOR == MULTIPLY_BY_2
		 CLEAR_BIT(MCRR->CFGR,18);
		 CLEAR_BIT(MCRR->CFGR,19);
		 CLEAR_BIT(MCRR->CFGR,20);
		 CLEAR_BIT(MCRR->CFGR,21);
		#elif CLOCK_FACTOR == MULTIPLY_BY_3
		 SET_BIT(MCRR->CFGR,18);
		 CLEAR_BIT(MCRR->CFGR,19);
		 CLEAR_BIT(MCRR->CFGR,20);
		 CLEAR_BIT(MCRR->CFGR,21);
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_4
		 CLEAR_BIT(MCRR->CFGR,18);
		 SET_BIT(MCRR->CFGR,19);
		 CLEAR_BIT(MCRR->CFGR,20);
		 CLEAR_BIT(MCRR->CFGR,21);
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_5
		 SET_BIT(MCRR->CFGR,18);
		 SET_BIT(MCRR->CFGR,19);
		 CLEAR_BIT(MCRR->CFGR,20);
		 CLEAR_BIT(MCRR->CFGR,21);
		
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_6
		 CLEAR_BIT(MCRR->CFGR,18);
		 CLEAR_BIT(MCRR->CFGR,19);
		 SET_BIT(MCRR->CFGR,20);
		 CLEAR_BIT(MCRR->CFGR,21);
		
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_7
		 SET_BIT(MCRR->CFGR,18);
		 CLEAR_BIT(MCRR->CFGR,19);
		 SET_BIT(MCRR->CFGR,20);
		 CLEAR_BIT(MCRR->CFGR,21);
		#elif CLOCK_FACTOR == MULTIPLY_BY_8
		 CLEAR_BIT(MCRR->CFGR,18);
		 SET_BIT(MCRR->CFGR,19);
		 SET_BIT(MCRR->CFGR,20);
		 CLEAR_BIT(MCRR->CFGR,21);
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_9
		 SET_BIT(MCRR->CFGR,18);
		 SET_BIT(MCRR->CFGR,19);
		 SET_BIT(MCRR->CFGR,20);
		 CLEAR_BIT(MCRR->CFGR,21);
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_10
		 CLEAR_BIT(MCRR->CFGR,18);
		 CLEAR_BIT(MCRR->CFGR,19);
		 CLEAR_BIT(MCRR->CFGR,20);
		 SET_BIT(MCRR->CFGR,21);
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_11
		 SET_BIT(MCRR->CFGR,18);
		 CLEAR_BIT(MCRR->CFGR,19);
		 CLEAR_BIT(MCRR->CFGR,20);
		 SET_BIT(MCRR->CFGR,21);
		
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_12
		 CLEAR_BIT(MCRR->CFGR,18);
		 SET_BIT(MCRR->CFGR,19);
		 CLEAR_BIT(MCRR->CFGR,20);
		 SET_BIT(MCRR->CFGR,21);
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_13
		 SET_BIT(MCRR->CFGR,18);
		 SET_BIT(MCRR->CFGR,19);
		 CLEAR_BIT(MCRR->CFGR,20);
		 SET_BIT(MCRR->CFGR,21);
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_14
		 CLEAR_BIT(MCRR->CFGR,18);
		 CLEAR_BIT(MCRR->CFGR,19);
		 SET_BIT(MCRR->CFGR,20);
		 SET_BIT(MCRR->CFGR,21);
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_15
		 SET_BIT(MCRR->CFGR,18);
		 CLEAR_BIT(MCRR->CFGR,19);
		 SET_BIT(MCRR->CFGR,20);
		 SET_BIT(MCRR->CFGR,21);
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_16
		 CLEAR_BIT(MCRR->CFGR,18);
		 SET_BIT(MCRR->CFGR,19);
		 SET_BIT(MCRR->CFGR,20);
		 SET_BIT(MCRR->CFGR,21);
		
		#else
			#warning	"Wrong Multiplication factor!"
		
		#endif
		
					#if 	PLL_SOURCE	==	PLL_HSI_DIVIDED_BY_2
							CLEAR_BIT(MRCC->CFGR,CFGR_PLLSRC);/*PLL entry clock source is HSI divdided by 2		*/
							
					#elif	PLL_SOURCE	==	PLL_HSE
							SET_BIT(MRCC->CFGR,CFGR_PLLSRC);  /*PLL entry clock source is HSE						*/
							
							CLEAR_BIT(MRCC->CFGR,CFGR_PLLXTPRE);/*HSE divider for PLL entry : clock not divided 	*/
							
					#elif	PLL_SOURCE	==	PLL_HSE_DIVIDED_BY_2
							SET_BIT(MRCC->CFGR,CFGR_PLLSRC);/*PLL entry clock source is HSE						*/
							
							SET_BIT(MRCC->CFGR,CFGR_PLLXTPRE);/*HSE divider for PLL entry : clock divided		 	*/
						
					#endif
		
					SET_BIT(MRCC->CR,CR_PLLON);           /*	PLL clock enable				*/
					while(GET_BIT(MRCC->CR,CR_PLLRDY)==0);/*	PLL Ready Flag					*/
					/*	The PLL output frequency must not exceed 72 MHz */
					CLEAR_BIT(MRCC->CFGR,0);             /*PLL selected as system clock		*/
					SET_BIT(MRCC->CFGR,1);

				
		#else
			
			#error		"Wrong Clock System type congiguration!"
		
		#endif
		/*FOR Clock Security System				*/
		#if		CLOCK_SECURITY_SYSTEM	==	OFF
				
		
		#elif	CLOCK_SECURITY_SYSTEM	==	ON
				
		#else
				#warning	"Wrong clock security system configuration choice!"
		#endif
		
}

ErrorStatus MRCC_enumSetPeripheralClock(uint8 Copy_u8PeripheralBus , uint8 Copy_u8PeripheralName , uint8 Copy_u8PeripheralState )
{
	ErrorStatus	LOC_enumstate = ES_OK ;
	switch( Copy_u8PeripheralState )
	{
		case	RCC_ENABLE 	:
							switch( Copy_u8PeripheralBus )
							{	
								case AHB  :	SET_BIT( MRCC->AHBENR  , Copy_u8PeripheralName  );break;
								case APB1 :	SET_BIT( MRCC->APB1ENR , Copy_u8PeripheralName  );break;
								case APB2 : SET_BIT(MRCC->APB2ENR  , Copy_u8PeripheralName  );break;
								default	  :	break;
							}
							break;
		case	RCC_DISABLE :	
							switch( Copy_u8PeripheralBus )
							{	
								case AHB  :	CLEAR_BIT( MRCC->AHBENR  , Copy_u8PeripheralName   );
								break;
								case APB1 :	CLEAR_BIT(  MRCC->APB1ENR , Copy_u8PeripheralName );
								break;
								case APB2 : CLEAR_BIT( MRCC->APB2ENR  , Copy_u8PeripheralName  );
								break;
								default	  :	
								break;
							}
							break;
		case	RCC_RESET	:	
							switch( Copy_u8PeripheralBus )
							{	
								case APB1 :	SET_BIT( MRCC->APB1RSTR , Copy_u8PeripheralName   );break;
								case APB2 : SET_BIT( MRCC->APB2RSTR , Copy_u8PeripheralName );break;
								default	  :	break;
							}
							break;
	}

	return LOC_enumstate;
}
