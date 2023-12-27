/*
 * LM_35.h
 *
 *  Created on: Oct 11, 2021
 *  Author: Menna Sayed
 */

#ifndef LM_35_H_
#define LM_35_H_

#include "std_types.h"

/************************************Sensor Pins***********************************/
#define Sensor_Pin_ID               1
#define SENSOR_MAX_VOLT_VALUE      1.5
#define SENSOR_MAX_TEMPERATURE     150

/************************************Prototypes***********************************/
uint8 LM35_GetTemperature(void);


#endif /* LM_35_H_ */
