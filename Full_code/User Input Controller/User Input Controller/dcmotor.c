/*
 * dcmotor.c
 *
 * Created: 5/22/2022 5:07:24 AM
 *  Author: Dasith
 */ 

#include "dcmotor.h"

void initDCMotor(){
	DDRB |= (1 << PB3) | (1<<PB2) | (1<<PB1);
	TCCR0  = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS00);
	OCR0 = 255;
}
void setMotorSpeed(int bladeMotorSpeed){
	OCR0 = bladeMotorSpeed;
}

void rotateMotor(){
	PORTB |=(1<<PB1);
}
void stopMotor(){
	PORTB &=~(1<<PB1);
}