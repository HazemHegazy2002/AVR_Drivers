/*
 * led.c
 *
 *  Created on: Aug 5, 2024
 *      Author: Hazem
 */
#include "led.h"

void led_initialize(const led_t *led){

	GPIO_setupPinDirection(led->port_name,led->pin,PIN_OUTPUT);
	GPIO_writePin(led->port_name,led->pin,led->led_status);
}
void led_turn_on(const led_t *led){

	GPIO_writePin(led->port_name,led->pin,GPIO_HIGH);


}
void led_turn_off(const led_t *led){

	GPIO_writePin(led->port_name,led->pin,GPIO_LOW);

}
void led_turn_toggle(const led_t *led){
	GPIO_togglePin(led->port_name,led->pin);
}

