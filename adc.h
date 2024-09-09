/*
 * adc.h
 *
 *  Created on: 6 Aug 2024
 *      Author: user
 */

#ifndef ADC_H_
#define ADC_H_
#include "gpio.h"
#include "avr/interrupt.h"
#include <stdio.h>
#include <stdlib.h>

#define ADC_ENABLE_()    (SET_BIT(ADCSRA,ADEN))
#define ADC_DISABLE_()   (CLEAR_BIT(ADCSRA,ADEN))
#define ADC_START_()      (SET_BIT(ADCSRA,ADSC))




typedef enum{

	INTERRUPT_ENABLED,
	INTERRUPT_DISABLED

}interrupt_t;

typedef enum{

	VOLTAGEREFERENCE_AVCC,
	VOLTAGEREFERENCE_ENABLED,
	VOLTAGEREFERENCE_INTERNAL

}voltagereference_t;

typedef enum{

	ADC_DIV2,
	ADC_DIV2_repeated,
	ADC_DIV4,
	ADC_DIV8,
	ADC_DIV16,
	ADC_DIV32,
	ADC_DIV64,
	ADC_DIV128,

}Prescalar_t;


typedef enum{
	ADC0_,
	ADC1_,
	ADC2_,
	ADC3_,
	ADC4_,
	ADC5_,
	ADC6_,
	ADC7_,

}channel_t;

typedef struct{

	void (*ADC_InterruptHandler) (void);
	interrupt_t interruptOption;
	channel_t ADC_channel;
	voltagereference_t referenceoption;
	Prescalar_t Prescalar_adc;

}adc_t;


void adc_intialize(const adc_t* adc_obj);
void adc_Deintialize(const adc_t* adc_obj);
void adc_SelectChannel(const adc_t* adc_obj,channel_t channel);
void adc_StartConversion(const adc_t* adc_obj);
uint8 adc_IsConversionDone(const adc_t* adc_obj);
uint16 adc_GetConversionResult(const adc_t* adc_obj);
uint16 adc_GetConversionResultBlocking(const adc_t* adc_obj,channel_t channel);
void adc_startConversionInterrupt(const adc_t* adc_obj,channel_t channel);





#endif /* ADC_H_ */
