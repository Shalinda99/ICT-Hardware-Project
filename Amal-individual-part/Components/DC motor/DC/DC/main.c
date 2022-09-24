/*
 * DC.c
 *
 * Created: 5/12/2022 11:07:13 AM
 * Author : asus
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "dcmotor.h"

int main()
{
	initDCMotor();
	_delay_ms(2000);
	rotateMotor();
	_delay_ms(2000);
	stopMotor();
	_delay_ms(2000);
	setMotorSpeed(10);
	rotateMotor();
	_delay_ms(2000);
	stopMotor();
	_delay_ms(2000);	
}

