/*
 * UART.h
 *
 * Created: 6/18/2017 8:10:30 PM
 *  Author: MOHAMED YOUSEF
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <util/delay.h>

typedef unsigned char byte;

void UART_init(void);
void UART_send_char(byte);
byte UART_recieve_char(void);

#endif /* UART_H_ */