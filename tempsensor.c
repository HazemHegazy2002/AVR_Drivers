/*
 * tempsensor.c
 *
 *  Created on: 11 Aug 2024
 *      Author: user
 */


#include "tempsensor.h"


uint8 LM35_getTemperature(const adc_t* adc_obj)
{
	uint8 temp_value = 0;

	uint16 adc_value = adc_GetConversionResult(adc_obj);

	/* Read ADC channel where the temperature sensor is connected */
	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*5)/(1023*SENSOR_MAX_VOLT_VALUE));\
	return temp_value;

}
