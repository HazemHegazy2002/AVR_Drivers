/*
 * timer0.h
 *
 *  Created on: 10 Aug 2024
 *      Author: user
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#include "gpio.h"
#include "avr/interrupt.h"

typedef enum{
	overflow_mode,
	compare_mode,
	PWM_mode
}mode_t;

typedef enum{
	OC0_DISCONNECTED,
	OC0_TOGGLE,
	OC0_CLEAR,
	OC0_SET

}OComode_t;

typedef enum{
	Timeroff,
	Div_1=1,
	Div_8,
	Div_64,
	Div_256,
	Div_1024,
}prescalartimer_t;


typedef struct{

	void (*Timer0_interruptHandler)(void);
	uint8 preloadvalue;
	uint8 comparevalue;
	mode_t modetype;
	prescalartimer_t timerprescalar;
	OComode_t OCtype;
	uint8 dutycycle_percentage;
}timer0_t;

void Timer_initialize(const timer0_t* timerobj );
void Timer_Deinitialize(const timer0_t* timerobj );
void Timer_writevalue(const timer0_t* timerobj,uint8 value);
uint8 Timer_readvalue(const timer0_t* timerobj,uint8 value);
void Timer_PWMchangeduty(uint8 precentage);



#endif /* TIMER0_H_ */
