/*
 * UART.c
 *
 * Created: 6/18/2017 8:10:17 PM
 *  Author: MOHAMED YOUSEF
 */ 

#include "UART.h"

void UART_init(void){
	//set baud rate 9600 --> 0x33 --> 51
	UBRRL = 0x33;
	UBRRH = 0;
	
	//set UCSRA (udr enable , no parity , no frame error, all complete = 0)
	UCSRA = 0x00;
	
	//set UCSRB (just enable tx and rx)
	UCSRB = 0x18;
	
	//set UCSRC (just char size = 8 --> 011 for ucsz0/1/2) don't forget to choose URSEL -> 1 for UCSRC not UBRRH 
	UCSRC = 0x86;
}

void UART_send_char(byte data){
	while(!(UCSRA & (1<<UDRE)));
	UDR=data;
	_delay_ms(10);
}

byte UART_recieve_char(void){
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}
