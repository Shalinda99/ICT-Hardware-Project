/*
 * Motor controller.c
 *
 * Created: 5/22/2022 3:43:10 AM
 * Author : Dasith Rathnasinghe
 */ 

#define F_CPU 16000000UL
#define START 1
#define STOP 0
#define HIGH_SPEED 2
#define LOW_SPEED 3

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>
#include <stdio.h>
#include "ultrasonic.h"
#include "usart.h"
#include "dcmotor.h"
#include "stepper.h"

int static volatile ult1_distance;
int static volatile ult2_distance;
int static volatile ult3_distance;
int wasteBinDistanceZ = 10;
int wasteBinDistanceX = 20;
int minLen=4;
int maxRadius=25;
int receivedData;
int isInputDataRecevied=0;
int static volatile  rounds;
int static volatile  length;

ISR(USART_RXC_vect){
	receivedData=UDR;
	isInputDataRecevied=1;
}

int main(void)
{
	int isMetal;
	initUltrasonic();
	initUSART();
	initSteppers();
	sei(); //enable global interrupts
	while (1)
	{
		while (!(PIND & 1 << PD4)); // Wait until pipe place

		if (PINB & 1 << PB5){ // Change DC motor speed
			// metal
			isMetal = 1;
			sendData(HIGH_SPEED);
			
			}else{
			// PVC
			isMetal = 0;
			sendData(LOW_SPEED);
		}

		// TODO USART send message

		// tight clutches1&2
		// Check ultrasonic sensor output
		ult2_distance = getUltrasonic_2_Distance();
		ult3_distance = getUltrasonic_3_Distance();
		// move both clutches forward until ultrasonic output smallest number
		//TODO move simultaneously
		rotateStepper_1_and_2((ult2_distance-3),(ult3_distance-3));

		// move clutches through rail to align

		if ((PIND & 1 << PD5) && (PIND & 1 << PD6)){ // if both Ir sensor-2,3 are detected pipe
			rotateDCMotors(1);
			while (PIND & 1 << PD6);
			stopDCMotors();
		}
		else if (!(PIND & 1 << PD5) && !(PIND & 1 << PD6)){ // else if both Ir sensor-2,3 are not detected pipe
			rotateDCMotors(0);
			while (!(PIND & 1 << PD5));
			stopDCMotors();
		}

		while(!isInputDataRecevied);//get length value from user input
		length=receivedData;
		isInputDataRecevied=0;
		
		while(!isInputDataRecevied);//get unit value from user input
		rounds=receivedData;
		isInputDataRecevied=0;

		// repeat cutting process(loop rounds time)
		for (int i = 0; i < rounds; i++)
		{
			//rotate stepper motor2 and 1 backwards
			rotateStepper_1_and_2(-maxRadius,-maxRadius);
			// move pipe forward according to the calculated length
			rotateDCMotors(0);
			while(getUltrasonic_1_Distance()>3);
			// Check ultrasonic sensor output
			ult2_distance = getUltrasonic_2_Distance();
			ult3_distance = getUltrasonic_3_Distance();
			//rotate stepper motor2 and 1 forward
			rotateStepper_1_and_2((ult2_distance-3),(ult3_distance-3));

			// get ultrasonic1 output distance (distance1)
			ult1_distance=getUltrasonic_1_Distance();
			// move clutches though rail until ult1_distance-instantDistance==length
			rotateDCMotors(1);
			while((getUltrasonic_1_Distance()-ult1_distance)<length)
			stopDCMotors();
			// rotate stepper motor3 forward
			rotateStepper_3(maxRadius);
			// pipe cutting process
			// start rotating cutting blade DC motor
			sendData(START);
			// rotate stepper motor4
			rotateStepper_4(1);
			rotateStepper_4(0);
			rotateStepper_3(-maxRadius);
			sendData(STOP);
		}

		// check if leftover pipe is waste or not
		if (!(PIND & 1 << PD4)){
			// get ultrasonic1 output distance (distance1)
			ult1_distance=getUltrasonic_1_Distance();
			// move both clutches backward though rail
			rotateDCMotors(0);
			while (getUltrasonic_1_Distance()-ult1_distance > wasteBinDistanceZ)
			;
			stopDCMotors();
			if (isMetal){
				// move clutch1 backward && clutch2 forward
				rotateStepper_1_and_2(-wasteBinDistanceX,wasteBinDistanceX);
				// when position correctly, drop wastage
				rotateStepper_2(-wasteBinDistanceX);
				rotateStepper_1(wasteBinDistanceX);
				}else{
				// move clutch2 backward && clutch1 forward
				rotateStepper_1_and_2(wasteBinDistanceX,-wasteBinDistanceX);
				// when position correctly, drop wastage
				rotateStepper_1(-wasteBinDistanceX);
				rotateStepper_2(wasteBinDistanceX);
			}
		}
	}
}


