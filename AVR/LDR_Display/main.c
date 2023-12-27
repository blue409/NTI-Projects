/*
 * main.c
 *
 *  Created on: Oct 24, 2023
 *  Author: Menna Sayed
 ******************************************************/
#include "LCD.h"
#include "ADC.h"
#include "LM_35.h"
#include "GIE.h"


int main(){

 _delay_ms(400);
 LCD_Init();
 _delay_ms(2);
 DIO_setupPinDirection(PORTB,PIN7_ID,PIN_OUTPUT);
 DIO_writePin(PORTB,PIN7_ID,LOGIC_LOW);
 _delay_ms(5000);
ADC_ConfigType ADC_Config={AVCC,F_8};
ADC_init(&ADC_Config);
Global_InterruptEnable();
ADC_InterruptEnable();
ADC_readChannel_INT(0);
_delay_ms(4000);




 while(1){



 }


return 0;
}


/*
  /LM35 Reading /
 LCD_GoTo(0,1);
 _delay_ms(2);
 LCD_SendString("TEMP : ");
 LCD_integerTostring(LM35_GetTemperature());
 _delay_ms(4000);
/*LDR APP/
 LCD_GoTo(2,1);
 _delay_ms(2);
 LCD_SendString("LDR : ");
 LCD_integerTostring(ADC_readChannel(0));
 _delay_ms(4000);
 *
 * */

