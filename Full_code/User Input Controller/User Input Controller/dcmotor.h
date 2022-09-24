/*
 * dcmotor.h
 *
 * Created: 5/22/2022 5:07:32 AM
 *  Author: Dasith
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include <avr/io.h>

void initDCMotor();
void rotateMotor();
void stopMotor();
void setMotorSpeed(int bladeMotorSpeed);

#endif /* DCMOTOR_H_ */