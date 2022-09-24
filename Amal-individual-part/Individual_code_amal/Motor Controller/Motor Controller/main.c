/*
 * Motor Controller.c
 *
 * Created: 6/12/2022 6:50:44 PM
 * Author : Dasith
 */ 

#define F_CPU 16000000UL
#define START 1
#define STOP 4
#define HIGH_SPEED 2
#define LOW_SPEED 3

#include <avr/io.h>
#include <util/delay.h>
#include "stepper.h"
#include "usart.h"

int static volatile isMetal;


int main(void)
{
	initUSART(9600);
	initSteppers();
    /* Replace with your application code */
    while (1) 
    {
		if (PINB & 1 << PB5){ // Change DC motor speed
			// metal
			isMetal = 1;
			sendData(HIGH_SPEED);
			
			}else{
			// PVC
			isMetal = 0;
			sendData(LOW_SPEED);
		}
		
		int rounds=3;
		
		// repeat cutting process(loop rounds time)
		for (int i = 0; i < rounds; i++)
		{
			/*//rotate stepper motor2 and 1 backwards
			// move pipe forward according to the calculated length
			//rotate stepper motor2 and 1 forward
			// rotate stepper motor3 forward
			// get ultrasonic1 output distance (distance1)
			// move clutches though rail until ult1_distance-instantDistance==length
			// rotate stepper motor3 forward
			// pipe cutting process
			*/
			// start rotating cutting blade DC motor
			sendData(START);
			// rotate stepper motor4
			rotateStepper_4(1);
			_delay_ms(1000);
			rotateStepper_4(0);
			sendData(STOP);
			_delay_ms(10000);
		}
		
    }
}

