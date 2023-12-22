/*
 * seven_segment.h
 *
 *  Description: 7-segment Driver
 *  Created on: Oct 21, 2023
 *  Author:     Menna Sayed
 *******************************************************************************/
#include "dio.h"
#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void SevenSegmentCommonAnode_Init(void);

void SevenSegmentCommonAnode( uint8 num,uint8 EN);  /*num: written number on it , EN: selected 7-segment*/


#endif /* SEVEN_SEGMENT_H_ */
