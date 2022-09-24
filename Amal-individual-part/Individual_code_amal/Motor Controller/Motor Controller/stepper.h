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
void rotateStepper_4(int direction);

#endif /* STEPPER_H_ */