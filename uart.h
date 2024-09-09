/*
 * uart.h
 *
 *  Created on: 11 Aug 2024
 *      Author: user
 */

#ifndef UART_H_
#define UART_H_

#include "gpio.h"




void UART_init(uint16 baud_rate);
uint8 UART_RecieveByteBlocking(void);
void UART_SendByteBlocking(uint8 value);
void UART_sendString(const uint8 *Str);
void UART_recieveString(uint8 *Str);



#endif /* UART_H_ */
