/*
 * usart.c
 *
 * Created: 5/22/2022 5:28:37 AM
 *  Author: Dasith
 */ 

#include "usart.h"

void initUSART(long USART_BAUDRATE){
	
	DDRD |= 1 << PIND1;//pin1 of portD as OUTPUT
	

	//Put the upper part of the baud number here (bits 8 to 11)

	UBRRH = (unsigned char) (BAUD_PRESCALE(USART_BAUDRATE) >> 8);

	//Put the remaining part of the baud number here

	UBRRL = (unsigned char) BAUD_PRESCALE(USART_BAUDRATE);

	//Enable the receiver, transmitter
	UCSRB = (1 << RXEN) | (1 << TXEN) | (1<<RXCIE);

	//Set 2 stop bits and data bit length is 8-bit

	UCSRC = (1 << USBS) | (1 << UCSZ0) | (1<<UCSZ1);
	
}

void sendData(uint8_t byte){
	while (! (UCSRA & (1 << UDRE)) );

	{
		UDR = byte;//once transmitter is ready sent eight bit data
	}
	// Get that data out here!
	_delay_ms(5);
}