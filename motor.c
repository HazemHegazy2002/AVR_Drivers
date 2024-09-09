/*
 * motor.c
 *
 *  Created on: 6 Aug 2024
 *      Author: user
 */


#include "motor.h"


void motor_Intialize(const motor_t* motor_obj){

	GPIO_setupPinDirection(motor_obj->MotorPort1,motor_obj->MotorPin1,PIN_OUTPUT);
	GPIO_setupPinDirection(motor_obj->MotorPort2,motor_obj->MotorPin2,PIN_OUTPUT);

}
void motor_moveRight(const motor_t* motor_obj){
	GPIO_writePin(motor_obj->MotorPort1,motor_obj->MotorPin1,GPIO_HIGH);
	GPIO_writePin(motor_obj->MotorPort2,motor_obj->MotorPin2,GPIO_LOW);


}
void motor_moveLeft(const motor_t* motor_obj){
	GPIO_writePin(motor_obj->MotorPort1,motor_obj->MotorPin1,GPIO_LOW);
	GPIO_writePin(motor_obj->MotorPort2,motor_obj->MotorPin2,GPIO_HIGH);

}
void motor_moveStop(const motor_t* motor_obj){
	GPIO_writePin(motor_obj->MotorPort1,motor_obj->MotorPin1,GPIO_LOW);
	GPIO_writePin(motor_obj->MotorPort2,motor_obj->MotorPin2,GPIO_LOW);

}
