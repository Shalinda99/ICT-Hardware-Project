/*
 * DC.c
 *
 * Created: 5/12/2022 11:07:13 AM
 * Author : asus
 */ 

#define F_CPU 16000000UL
#define START 1
#define STOP 4
#define HIGH_SPEED 2
#define LOW_SPEED 3


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "dcmotor.h"
#include "usart.h"

int8_t static volatile receivedData;


ISR(USART_RXC_vect){
	receivedData=UDR;
	if(receivedData==START){
		rotateMotor();
	}else if(receivedData==STOP){
		stopMotor();
	}else if(receivedData==HIGH_SPEED){
		setMotorSpeed(255);
	}else if(receivedData==LOW_SPEED){
		setMotorSpeed(100);
	}
}

int main()
{
	initDCMotor();
	initUSART(9600);
	sei();
	
	while(1){
		
	}
}

