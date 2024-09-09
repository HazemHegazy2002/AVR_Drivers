/*
 * motor.h
 *
 *  Created on: 6 Aug 2024
 *      Author: user
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "gpio.h"

#define DCMOTOR_ON  	1
#define DCMOTOR_OFF 	1


typedef struct{

	uint8 MotorPort1;
	uint8 MotorPin1;
	uint8 MotorPort2;
	uint8 MotorPin2;

}motor_t;

void motor_Intialize(const motor_t* motor_obj);
void motor_moveRight(const motor_t* motor_obj);
void motor_moveLeft(const motor_t* motor_obj);
void motor_moveStop(const motor_t* motor_obj);




#endif /* MOTOR_H_ */
