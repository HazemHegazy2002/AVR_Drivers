/*
 * interruptsbuttons.h
 *
 *  Created on: 8 Aug 2024
 *      Author: user
 */

#ifndef INTERRUPTSBUTTONS_H_
#define INTERRUPTSBUTTONS_H_

#include "gpio.h"
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum{
	FALLING_EDGE,
	RISING_EDGE
}edge_t;

typedef enum{
	INTERRUPT_INT0,
	INTERRUPT_INT1,
	INTERRUPT_INT2
}interruptsource_t;

typedef struct{

	void (*interruptbutton_Handler) (void);
	interruptsource_t interruptsouretyoe;
	edge_t edgetype;

}interruptbutton_t;

void interruptbutton_intialize(const interruptbutton_t* interruptbutton_obj);
void interruptbutton_Deintialize(const interruptbutton_t* interruptbutton_obj);




#endif /* INTERRUPTSBUTTONS_H_ */
