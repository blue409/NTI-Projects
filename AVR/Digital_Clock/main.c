/********************************************************************************
 * main.c
 *
 *Created on:  Oct 29, 2023
 *Description: Digital clock that can be adjusted
 *Author:      Menna Sayed
 ******************************************************************************/
#include "Timer0_Driver.h"
#include "GIE.h"
#include "seven_segment.h"
#include "ext.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void App(void);
void Normal_clock(void);
void blinking_hours_clock(void);
void blinking_min_clock(void);
/*******************************************************************************
 *                             static variables (private)                           *
 *******************************************************************************/
static uint8 seconds=0;
static uint8 minutes=40;
static uint8 hours=3;
/*******************************************************************************
 *                             global variables                            *
 *******************************************************************************/
 uint8 button1_flag=0;  //for blinking the 7-segment and selecting which one to be configured
 uint8 button2_flag=0;  //for incrementing the selected 7-segment

int main()
{
//	DIO_setupPinDirection(PORTA_ID,PIN5_ID,PIN_OUTPUT);
//	DIO_writePin(PORTA_ID,PIN5_ID,LOGIC_LOW);
//	config_struc_sync config ={normal,5,0};
//	Timer0_init_sync(&config);

	DIO_setupPinDirection(PORTD_ID,PIN2_ID,PIN_INPUT);  //button 1........INT0
    DIO_setupPinDirection(PORTD_ID,PIN3_ID,PIN_INPUT);	//button 2........INT1
    DIO_setupPinDirection(PORTC_ID,PIN2_ID,PIN_OUTPUT);

	EXTINT_ConfigType conf={Int0,RISING_Edge};
	EXTINT_ConfigType confi={Int1,RISING_Edge};
	config_struc config ={normal,5,0,F_64};       //for configuring the timer0

	SevenSegmentCommonAnode_Init();               /*put in proteus not gate before the 4 enable pins*/
	EXTI_Init( &conf);
	EXTI_Init( &confi);

	Timer0_setCallBack(App);
	Timer0_init_Async(&config);
	Global_InterruptEnable();

	while(1)
	{

		if(button1_flag > 0)
		{
			switch(button1_flag)
			{
			case 1:   /*First button1 press*/
				Timer0_DeInit();
				blinking_hours_clock();  //blinking hours part
                if(button2_flag >0){button2_flag=0;hours++;}
				break;
			case 2:  /*Second button1 press*/
				Timer0_DeInit();
				blinking_min_clock();    //blinking min part
				if(button2_flag >0){button2_flag=0;minutes++;}
				break;
			case 3: /*Third button1 press*/
			default:
				button1_flag=0;            //goto normal mode
				button2_flag=0;
//		        TCCR0 |= (F_64) ;          //re enable the automatic clock behaviour
		        Timer0_init_Async(&config);//start the timer again
		        _delay_ms(500);
				break;
			}
		}
		else
		{
		   Normal_clock();                     /********ordinary clock function**********/
		}
	}

	return 0;
}
                     //note : we can pass the static variables by refrence to this function (APP) but they will nolonger be static instead they will be externed in timer0.h file
                     //void App(uint8*seconds,uint8*minutes,uint8*hours)
void App(void)       //called every 1 sec...through callback concept
{
	DIO_togglePin(PORTC_ID,PIN2_ID);

	seconds++;

	if(seconds>=60)
	{
		seconds = 0;
		minutes++;
	}

	if((minutes)>=60)
	{
		minutes = 0;
		hours++;
	}

}

void Normal_clock(void)
{
	if(minutes > 9)
	{
		SevenSegmentCommonAnode((minutes/10),3);//tens
//		_delay_ms(5);//kit
		_delay_ms(80);//prot
		SevenSegmentCommonAnode((uint8)(minutes-((minutes/10)*10)),4);   //to display unints part of the minutes
//		_delay_ms(5);//kit
		_delay_ms(80);//prot
	}
	else
	{
		SevenSegmentCommonAnode(minutes,4);//units
//	    _delay_ms(5);   //kit
		_delay_ms(80);//prot 80
		SevenSegmentCommonAnode(0,3);//tens
//		_delay_ms(5);  //kit
		_delay_ms(80);//prot 80
	}
	if(hours>9)
	{
		SevenSegmentCommonAnode((hours/10),1);//tens
//		_delay_ms(5);  //kit
		_delay_ms(6);//prot
		SevenSegmentCommonAnode((hours-((hours/10)*10)),2);    //to display the units part of the hours
//		_delay_ms(5);  //kit
		_delay_ms(6);//prot
	}
	else
	{
		SevenSegmentCommonAnode(hours,2);//units
//				_delay_ms(5);//kit
				_delay_ms(6);//prot  90
		SevenSegmentCommonAnode(0,1);//tens
//		    	_delay_ms(5);//kit
				_delay_ms(6);//prot  90
	}


}

void blinking_hours_clock(void)    //showing hours part only when adjusting them
{
	if(minutes > 9)
	{
		SevenSegmentCommonAnode((minutes/10),3);//tens
//		_delay_ms(5);//kit
//		_delay_ms(8);
		SevenSegmentCommonAnode((minutes-((minutes/10) *10)),4);   //to display the units part of the minutes
//		_delay_ms(5);//kit
//		_delay_ms(8);
	}
	else
	{
		SevenSegmentCommonAnode( minutes,4);//units
//		_delay_ms(5);
//		_delay_ms(8);
		SevenSegmentCommonAnode(0,3);//tens
//		_delay_ms(5);
//		_delay_ms(8);
	}

	if(hours>9)
	{
		SevenSegmentCommonAnode((hours/10),1);//tens
//		_delay_ms(5);//kit
		_delay_ms(8);
		SevenSegmentCommonAnode((hours-((hours/10) *10)),2);    //to display the units part of the hours
//		_delay_ms(5);//kit
		_delay_ms(8);
	}
	else
	{
		SevenSegmentCommonAnode(hours,2);//units
//		_delay_ms(5);//kit
		_delay_ms(8);
		SevenSegmentCommonAnode(0,1);//tens
//		_delay_ms(5);//kit
		_delay_ms(8);
	}

}

void blinking_min_clock(void)          //showing min part only when adjusting them
{

	if(hours>9)
	{
		SevenSegmentCommonAnode((hours/10),1);//tens
//		_delay_ms(5);//kit
		SevenSegmentCommonAnode((hours-((hours/10) *10)),2);    //to display the units part of the hours
//		_delay_ms(5);//kit
	}
	else
	{
		SevenSegmentCommonAnode(hours,2);//units
//		_delay_ms(5);//kit
		SevenSegmentCommonAnode(0,1);//tens
//		_delay_ms(5);//kit
	}

	if(minutes > 9)
	{
		SevenSegmentCommonAnode((minutes/10),3);//tens
	//		_delay_ms(5);//kit
		_delay_ms(8);//20
		SevenSegmentCommonAnode((minutes-((minutes/10) *10)),4);   //to display the units part of the minutes
	//		_delay_ms(5);//kit
		_delay_ms(8);//20
	}
	else
	{
		SevenSegmentCommonAnode( minutes,4);//units
	//		_delay_ms(5);//kit
		_delay_ms(8);//10
		SevenSegmentCommonAnode(0,3);//tens
	//		_delay_ms(5);//kit
		_delay_ms(8);//10
	}
	_delay_ms(50);
}


