/*
 * seven_segment.h
 *
 *  Created on: Oct 21, 2023
 *  Author: Menna Sayed
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <avr/io.h>
#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

/* ProtoTypes*/
void SevenSegmentCommonAnode_INIT(void);
void SevenSegmentCommonAnode(u8 num, u8 EN);
void set_int0(void);
void set_int1(void);

#endif /* SEVEN_SEGMENT_H_ */
