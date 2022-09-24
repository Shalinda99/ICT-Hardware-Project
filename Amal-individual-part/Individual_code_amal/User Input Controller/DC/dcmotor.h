/*
 * dcmotor.h
 *
 * Created: 5/23/2022 11:17:12 PM
 *  Author: Dasith
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void initDCMotor();
void setMotorSpeed(int bladeMotorSpeed);
void rotateMotor();
void stopMotor();

#endif /* DCMOTOR_H_ */