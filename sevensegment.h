/*
 * sevensegment.h
 *
 *  Created on: 5 Aug 2024
 *      Author: user
 */

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_


//In case of common Anode use the 7447 Decoder
//In case of common Anode use the 7448 Decoder




#include "gpio.h"



typedef enum{

	SEGMENT_COMMON_ANODE,
	SEGMENT_COMMON_CATHOD
}segmentconnection_t;

typedef struct{

	uint8 SegmentPins[4];
	uint8 SegmentPort[4];
	segmentconnection_t segment_type;
}segment_t;


void seven_segment_intialize(const segment_t *seg);
void seven_segment_write_number(const segment_t *seg,uint8 number);




#endif /* SEVENSEGMENT_H_ */
