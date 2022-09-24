/*
 * dcmotor.c
 *
 * Created: 5/22/2022 4:47:15 AM
 *  Author: Dasith
 */ 
#include "dcmotor.h"

void initDCMotors(){
	DDRB |= (1<<PB0) | (1<<PB1);
}

void rotateDCMotors(int direction)
{
	if (direction != 0)
	{
		// Rotate DC motor Clockwise ?
		PORTB &= ~(1 << PB0);
		PORTB |= (1 << PB1);
	}
	else
	{
		// Else rotate DC motor Counterclockwise
		PORTB |= (1 << PB0);
		PORTB &= ~(1 << PB1);
	}
}

void stopDCMotors()
{
	// stop Rotation DC motor
	PORTB &= ~(1 << PB0);
	PORTB &= ~(1 << PB1);
}