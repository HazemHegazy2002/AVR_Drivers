/*
 * interruptsbuttons.c
 *
 *  Created on: 8 Aug 2024
 *      Author: user
 */

#include "interruptsbuttons.h"

static void (*button_InterruptHandler_INT0)(void)=NULL;
static void (*button_InterruptHandler_INT1)(void)=NULL;
static void (*button_InterruptHandler_INT2)(void)=NULL;
static void interruptpinconfigure(const interruptbutton_t* interruptbutton_obj);
static void interruptedgeconfigure(const interruptbutton_t* interruptbutton_obj);








void interruptbutton_intialize(const interruptbutton_t* interruptbutton_obj){
	SET_BIT(SREG,7);
	interruptedgeconfigure(interruptbutton_obj);
	interruptpinconfigure(interruptbutton_obj);

}
void interruptbutton_Deintialize(const interruptbutton_t* interruptbutton_obj){

	CLEAR_BIT(GICR,INT0);
	CLEAR_BIT(GICR,INT1);
	CLEAR_BIT(GICR,INT2);
}

static void interruptpinconfigure(const interruptbutton_t* interruptbutton_obj)
{
	switch(interruptbutton_obj->interruptsouretyoe)
	{
	case INTERRUPT_INT0:
		button_InterruptHandler_INT0=interruptbutton_obj->interruptbutton_Handler;
		CLEAR_BIT(DDRD,2);
		SET_BIT(GIFR,INTF0);
		SET_BIT(GICR,INT0);
		break;
	case INTERRUPT_INT1:
		button_InterruptHandler_INT1=interruptbutton_obj->interruptbutton_Handler;
		CLEAR_BIT(DDRD,3);
		SET_BIT(GIFR,INTF1);
		SET_BIT(GICR,INT1);
		break;
	case INTERRUPT_INT2:
		button_InterruptHandler_INT2=interruptbutton_obj->interruptbutton_Handler;
		CLEAR_BIT(DDRB,2);
		SET_BIT(GIFR,INTF2);
		SET_BIT(GICR,INT2);

		break;
	default:;

	}

}

static void interruptedgeconfigure(const interruptbutton_t* interruptbutton_obj)
{
	switch(interruptbutton_obj->interruptsouretyoe)
	{
	case INTERRUPT_INT0:
		if(interruptbutton_obj->edgetype==FALLING_EDGE)
		{
			SET_BIT(MCUCR,ISC01);
			CLEAR_BIT(MCUCR,ISC00);
		}
		else if(interruptbutton_obj->edgetype==RISING_EDGE)
		{
			SET_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
		}
		break;
	case INTERRUPT_INT1:
		if(interruptbutton_obj->edgetype==FALLING_EDGE)
		{
			SET_BIT(MCUCR,ISC11);
			CLEAR_BIT(MCUCR,ISC10);

		}
		else if(interruptbutton_obj->edgetype==RISING_EDGE)
		{
			SET_BIT(MCUCR,ISC11);
			SET_BIT(MCUCR,ISC10);

		}
		break;
	case INTERRUPT_INT2:
		if(interruptbutton_obj->edgetype==FALLING_EDGE)
		{
			CLEAR_BIT(MCUCR,ISC2);

		}
		else if(interruptbutton_obj->edgetype==RISING_EDGE)
		{
			SET_BIT(MCUCR,ISC2);

		}
		break;
	default:;

	}

}

ISR(INT0_vect)
{
	if(button_InterruptHandler_INT0)
	{
		button_InterruptHandler_INT0();
	}

}
ISR(INT1_vect)
{
	if(button_InterruptHandler_INT1)
	{
		button_InterruptHandler_INT1();
	}

}
ISR(INT2_vect)
{
	if(button_InterruptHandler_INT2)
	{
		button_InterruptHandler_INT2();
	}

}
