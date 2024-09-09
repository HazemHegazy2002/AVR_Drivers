/*
 * keypad.h
 *
 *  Created on: 5 Aug 2024
 *      Author: user
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "gpio.h"
#include <util/delay.h>


#define KEYPADROWS      4
#define KEYPADCOLUMNS   4


typedef struct{
	 uint8 rowpins[KEYPADROWS];
	 uint8 rowports[KEYPADROWS];
	 uint8 columnpins[KEYPADCOLUMNS];
	 uint8 columnports[KEYPADCOLUMNS];
}keypad_t;


void keypad_intialize(const keypad_t *keypad_obj);
uint8 keypad_getvalue(const keypad_t *keypad_obj);



#endif /* KEYPAD_H_ */
