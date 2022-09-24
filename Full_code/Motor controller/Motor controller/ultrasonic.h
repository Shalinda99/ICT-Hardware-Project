/*
 * ultasonic.h
 *
 * Created: 5/22/2022 4:32:55 AM
 *  Author: Dasith
 */ 


#ifndef ULTASONIC_H_
#define ULTASONIC_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

void initUltrasonic();
int getUltrasonic_1_Distance();
int getUltrasonic_2_Distance();
int getUltrasonic_3_Distance();

#endif /* ULTASONIC_H_ */