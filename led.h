/*
 * led.h
 *
 *  Created on: Aug 5, 2024
 *      Author: Hazem
 */

#ifndef LED_H_
#define LED_H_

#include <avr/io.h>
#include "gpio.h"

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */
typedef enum{
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct{
    uint8 port_name;
    uint8 pin;
    uint8 led_status;
}led_t;

/* Section: Function Declarations */
void led_initialize(const led_t *led);
void led_turn_on(const led_t *led);
void led_turn_off(const led_t *led);
void led_turn_toggle(const led_t *led);

#endif /* LED_H_ */
