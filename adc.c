/*
 * adc.c
 *
 *  Created on: 6 Aug 2024
 *      Author: user
 */



#include "adc.h"

static void (*adc_InterruptHandler)(void)=NULL;
static void adc_reference_configure(const adc_t* adc_obj);


void adc_intialize(const adc_t* adc_obj){

	//ADC_DISABLE_();
	adc_SelectChannel(adc_obj,adc_obj->ADC_channel);
	ADCSRA=((adc_obj->Prescalar_adc)&0x07)|(ADCSRA&0xF8);
	if(adc_obj->interruptOption==INTERRUPT_ENABLED)
	{
		SET_BIT(ADCSRA,ADIE);
		SET_BIT(SREG,7);
		SET_BIT(ADCSRA,ADIF);
		adc_InterruptHandler=adc_obj->ADC_InterruptHandler;
	}
	adc_reference_configure(adc_obj);
	CLEAR_BIT(ADMUX,ADLAR);
	ADC_ENABLE_();

}
void adc_Deintialize(const adc_t* adc_obj){
	ADC_DISABLE_();
	CLEAR_BIT(ADCSRA,ADIE);

}
void adc_SelectChannel(const adc_t* adc_obj,channel_t channel){
	ADMUX =(channel&0x1F)|(ADMUX&0xE0);
	switch(channel)
	{
	case ADC0_:
		CLEAR_BIT(DDRA,0);
		break;
	case ADC1_:
		CLEAR_BIT(DDRA,1);
		break;
	case ADC2_:
		CLEAR_BIT(DDRA,2);
		break;
	case ADC3_:
		CLEAR_BIT(DDRA,3);
		break;
	case ADC4_:
		CLEAR_BIT(DDRA,4);
		break;
	case ADC5_:
		CLEAR_BIT(DDRA,5);
		break;
	case ADC6_:
		CLEAR_BIT(DDRA,6);
		break;
	case ADC7_:
		CLEAR_BIT(DDRA,7);
		break;
	}
}
void adc_StartConversion(const adc_t* adc_obj){
	SET_BIT(ADCSRA,ADSC);
}
uint8 adc_IsConversionDone(const adc_t* adc_obj){
	return (!(GET_BIT(ADCSRA,ADSC)));

}
uint16 adc_GetConversionResult(const adc_t* adc_obj){
	return ADC;
}
uint16 adc_GetConversionResultBlocking(const adc_t* adc_obj,channel_t channel){
	adc_SelectChannel(adc_obj,channel);
	adc_StartConversion(adc_obj);
	while((ADCSRA&(1<<ADIF))==0);
	return ADC;
}
void adc_startConversionInterrupt(const adc_t* adc_obj,channel_t channel){
	SET_BIT(ADCSRA,ADIF);
	adc_SelectChannel(adc_obj,channel);
	adc_StartConversion(adc_obj);

}
static void adc_reference_configure(const adc_t* adc_obj){

	switch(adc_obj->referenceoption)
	{
	case VOLTAGEREFERENCE_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
	case VOLTAGEREFERENCE_ENABLED:
		CLEAR_BIT(ADMUX,REFS1);
		CLEAR_BIT(ADMUX,REFS0);
		break;
	case VOLTAGEREFERENCE_INTERNAL:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	default:;


	}
}

ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	if(adc_InterruptHandler)
	{
		adc_InterruptHandler();
	}
}





