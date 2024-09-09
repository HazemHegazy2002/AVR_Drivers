/*
 * tempsensor.h
 *
 *  Created on: 11 Aug 2024
 *      Author: user
 */

#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

#include "gpio.h"
#include "adc.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(const adc_t* adc_obj);




#endif /* TEMPSENSOR_H_ */
