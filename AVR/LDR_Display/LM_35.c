/*
 * LM_35.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Menna Sayed
 */
#include "LM_35.h"
#include "ADC.h"

uint8 LM35_GetTemperature(void){

uint8 Temp =0;
uint16 adc_value=0;

adc_value = ADC_readChannel(Sensor_Pin_ID );  //to get adc value of sensor pin connected on one of ADC pins

float volt=((int)adc_value)*(5.0/1024.0);
uint8 temp = (uint8)(volt/0.01); //try this also

//Temp = (uint8)((uint32)(adc_value*5.0)/((1023.0)*0.01));//try this
//Temp = (uint8)((float32)(adc_value*5.0)/((1023.0)*0.01));//try this

//Temp = (uint8)((uint32)(adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT)/(ADC_MAX_VALUE*SENSOR_MAX_VOLT_VALUE));  //elly eshta3'alet

 return (temp-7);
}
