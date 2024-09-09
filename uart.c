/*
 * uart.c
 *
 *  Created on: 11 Aug 2024
 *      Author: user
 */


#include "uart.h"
#include "gpio.h"
#include "avr/interrupt.h"



void UART_init(uint16 baud_rate)
{
	uint16 ubrr_value=0;
	SET_BIT(UCSRA,U2X);
	CLEAR_BIT(UCSRB,RXCIE);
	CLEAR_BIT(UCSRB,TXCIE);
	CLEAR_BIT(UCSRB,UDRIE);
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	CLEAR_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC,URSEL);
	CLEAR_BIT(UCSRC,UMSEL);
	CLEAR_BIT(UCSRC,UPM0);
	CLEAR_BIT(UCSRC,UPM1);
	CLEAR_BIT(UCSRC,USBS);
	SET_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);
	CLEAR_BIT(UCSRC,UCPOL);
	ubrr_value = (uint16)(((F_CPU / (baud_rate * 8UL))) - 1);
	UBRRL = ubrr_value;			/* Load lower 8-bits of the baud rate */
	UBRRH = (ubrr_value >> 8);

}
uint8 UART_RecieveByteBlocking(void){
	while(!(GET_BIT(UCSRA,RXC)));
	return UDR;

}
void UART_SendByteBlocking(uint8 value){
	while(!(GET_BIT(UCSRA,UDRE)));
	UDR=value;

}
void UART_sendString(const uint8 *Str){
	uint8 string_counter=0;
	while(Str[string_counter]!='\0')
	{
		UART_SendByteBlocking(Str[string_counter]);
		string_counter++;
	}



}
void UART_recieveString(uint8 *Str) {
    uint8 string_counter = 0;
    uint8 received_char;

    while (1) {
        received_char = UART_RecieveByteBlocking();
        if (received_char == '#') { // Stop at '#'
            break;
        }
        Str[string_counter++] = received_char;
    }
    Str[string_counter] = '\0'; // Null-terminate the string
}
