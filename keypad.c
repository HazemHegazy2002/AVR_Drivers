/*
 * keypad.c
 *
 *  Created on: 5 Aug 2024
 *      Author: user
 */



#include "keypad.h"

static const uint8 btn_values[KEYPADROWS][KEYPADCOLUMNS]={   {'7','8','9','/'}
,{'4','5','6','*'}
,{'1','2','3','-'}
,{'#','0','=','+'}
};

void keypad_intialize(const keypad_t *keypad_obj){
	uint8 row_counter=0,column_counter=0;
	for(row_counter=0;row_counter<KEYPADROWS;row_counter++){
	GPIO_setupPinDirection(keypad_obj->rowports[row_counter],keypad_obj->rowpins[row_counter],PIN_INPUT);
	}

	for(column_counter=0;column_counter<KEYPADCOLUMNS;column_counter++){
		GPIO_setupPinDirection(keypad_obj->columnports[column_counter],keypad_obj->columnpins[column_counter],PIN_INPUT);
	}

}

uint8 keypad_getvalue(const keypad_t *keypad_obj){

	while(1)
	{

		uint8 row_counter=0,counter,column_counter=0;
		uint8 value;
		for(row_counter=0;row_counter<KEYPADROWS;row_counter++)
		{
			GPIO_setupPinDirection(keypad_obj->rowports[row_counter],keypad_obj->rowpins[row_counter],PIN_OUTPUT);
			GPIO_writePin(keypad_obj->rowports[row_counter],keypad_obj->rowpins[row_counter],GPIO_LOW);
			for(column_counter=0;column_counter<KEYPADCOLUMNS;column_counter++)
			{
				value=GPIO_readPin(keypad_obj->columnports[column_counter],keypad_obj->columnpins[column_counter]);
				if(value==GPIO_LOW)
				{
					return btn_values[row_counter][column_counter];

				}

			}

			GPIO_setupPinDirection(keypad_obj->rowports[row_counter],keypad_obj->rowpins[row_counter],PIN_INPUT);
			_delay_ms(5);




		}

	}


}
