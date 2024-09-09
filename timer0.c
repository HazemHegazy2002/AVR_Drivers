#include "timer0.h"

static void (*tmr0_InterruptHandler_ovf)(void) = NULL;
static void (*tmr0_InterruptHandler_cmp)(void) = NULL;

void Timer_initialize(const timer0_t* timerobj) {
    SET_BIT(SREG, 7);  // Enable global interrupts
    if (timerobj->modetype == overflow_mode) {
        TCNT0 = timerobj->preloadvalue;
        SET_BIT(TCCR0, FOC0);
        CLEAR_BIT(TCCR0, WGM00);
        CLEAR_BIT(TCCR0, WGM01);
        CLEAR_BIT(TCCR0, COM00);
        CLEAR_BIT(TCCR0, COM01);
        tmr0_InterruptHandler_ovf = timerobj->Timer0_interruptHandler;
        SET_BIT(TIMSK, TOIE0);  // Enable Timer0 overflow interrupt

    } else if (timerobj->modetype == compare_mode) {
        TCNT0 = timerobj->preloadvalue;
        SET_BIT(TCCR0, FOC0);
        SET_BIT(TCCR0, WGM01);  // Set CTC mode
        CLEAR_BIT(TCCR0, WGM00);
        SET_BIT(DDRB, 3);
        CLEAR_BIT(PORTB,3);
        OCR0=timerobj->comparevalue;
        TCCR0 = (TCCR0 & 0xcf) | ((timerobj->OCtype) << 4);
        SET_BIT(TIMSK, OCIE0);  // Enable Timer0 compare match interrupt
        tmr0_InterruptHandler_cmp = timerobj->Timer0_interruptHandler;
    }
    else if(timerobj->modetype == PWM_mode){

    	TCNT0 = 0;
    	SET_BIT(DDRB, 3);
    	OCR0=(timerobj->dutycycle_percentage)*0.01*255;
    	CLEAR_BIT(TCCR0,FOC0);
    	SET_BIT(TCCR0, WGM01);
    	SET_BIT(TCCR0, WGM00);
        CLEAR_BIT(TCCR0, COM00);
        SET_BIT(TCCR0, COM01);

    }

    TCCR0 = (TCCR0 & 0xf8) | (timerobj->timerprescalar);  // Set prescaler
}

void Timer_Deinitialize(const timer0_t* timerobj) {
    TCCR0 = (TCCR0 & 0xf8) | (Timeroff);
    CLEAR_BIT(TIMSK, TOIE0);
}

void Timer_writevalue(const timer0_t* timerobj, uint8 value) {
    TCNT0 = value;
}

uint8 Timer_readvalue(const timer0_t* timerobj, uint8 value) {
    return TCNT0;
}
void Timer_PWMchangeduty(uint8 precentage){
	OCR0=(precentage)*0.01*255;
}

ISR(TIMER0_OVF_vect) {
    if (tmr0_InterruptHandler_ovf) {
        tmr0_InterruptHandler_ovf();
    }
}

ISR(TIMER0_COMP_vect) {
    if (tmr0_InterruptHandler_cmp) {
        tmr0_InterruptHandler_cmp();
    }
}
