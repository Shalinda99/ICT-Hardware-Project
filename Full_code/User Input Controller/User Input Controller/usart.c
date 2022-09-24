/*
 * usart.c
 *
 * Created: 5/22/2022 5:28:37 AM
 *  Author: Dasith
 */ 

#include "usart.h"

void initUSART(){
	
	DDRD |= 1 << PIND1;//pin1 of portD as OUTPUT

	DDRD &= ~(1 << PIND0);//pin0 of portD as INPUT
	
	int UBBRValue = 25;//AS described before setting baud rate

	//Put the upper part of the baud number here (bits 8 to 11)

	UBRRH = (unsigned char) (UBBRValue >> 8);

	//Put the remaining part of the baud number here

	UBRRL = (unsigned char) UBBRValue;

	//Enable the receiver, transmitter and receiver interrupt
	UCSRB = (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);

	//Set 2 stop bits and data bit length is 8-bit

	UCSRC = (1 << USBS) | (3 << UCSZ0);
	
}


void sendData(uint8_t byte){
	while (! (UCSRA & (1 << UDRE)) );

	{
		UDR = byte;//once transmitter is ready sent eight bit data
	}
	// Get that data out here!
	_delay_ms(5);
}