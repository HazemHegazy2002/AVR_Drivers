/*
 * sevensegment.c
 *
 *  Created on: 5 Aug 2024
 *      Author: user
 */


#include "sevensegment.h"

void seven_segment_intialize(const segment_t *seg){
	GPIO_setupPinDirection(seg->SegmentPort[0],seg->SegmentPins[0],PIN_OUTPUT);
	GPIO_setupPinDirection(seg->SegmentPort[1],seg->SegmentPins[1],PIN_OUTPUT);
	GPIO_setupPinDirection(seg->SegmentPort[2],seg->SegmentPins[2],PIN_OUTPUT);
	GPIO_setupPinDirection(seg->SegmentPort[3],seg->SegmentPins[3],PIN_OUTPUT);

}
void seven_segment_write_number(const segment_t *seg,uint8 number){

	GPIO_writePin(seg->SegmentPort[0],seg->SegmentPins[0],(number) & BITMASK);
	GPIO_writePin(seg->SegmentPort[1],seg->SegmentPins[1],(number>>1) & BITMASK);
	GPIO_writePin(seg->SegmentPort[2],seg->SegmentPins[2],(number>>2) & BITMASK);
	GPIO_writePin(seg->SegmentPort[3],seg->SegmentPins[3],(number>>3) & BITMASK);

}
