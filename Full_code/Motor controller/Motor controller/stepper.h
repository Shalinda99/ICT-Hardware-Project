/*
 * stepper.h
 *
 * Created: 5/22/2022 4:53:02 AM
 *  Author: Dasith
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

void initSteppers();
void rotateStepper_1(int distance);
void rotateStepper_2(int distance);
void rotateStepper_3(int distance);
void rotateStepper_4(int direction);
void rotateStepper_1_and_2(int Stepper_1_Distance,int Stepper_2_Distance);

#endif /* STEPPER_H_ */