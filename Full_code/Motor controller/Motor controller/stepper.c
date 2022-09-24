/*
 * stepper.c
 *
 * Created: 5/22/2022 4:50:59 AM
 *  Author: Dasith
 */ 

#include "stepper.h"

void initSteppers(){
	DDRA = 0xFF;
	DDRC = 0xFF;
}

void rotateStepper_1(int distance)
{
	// clockwise-1
	// Counterclockwise-0
	// 1 distance unit = 1 rotating

	int period;
	period = 100;
	if (distance>0)
	{
		for (int i = 0; i <distance; i++)
		{
			PORTA = 0x03;
			_delay_ms(period);
			PORTA = 0x06;
			_delay_ms(period);
			PORTA = 0x0c;
			_delay_ms(period);
			PORTA = 0x09;
			_delay_ms(period);
			PORTA = 0x03;
			_delay_ms(period);
		}
	}
	else
	{
		for (int i = 0; i < abs(distance); i++)
		{
			PORTA = 0x03;
			_delay_ms(period);
			PORTA = 0x09;
			_delay_ms(period);
			PORTA = 0x0c;
			_delay_ms(period);
			PORTA = 0x06;
			_delay_ms(period);
			PORTA = 0x03;
			_delay_ms(period);
		}
	}
}

void rotateStepper_2(int distance){
	// clockwise-1
	// Counterclockwise-0
	// 1 distance unit = 1 rotating

	int period;
	period = 100;
	if (distance>0)
	{
		/* Rotate  clockwise */
		for (int i = 0; i <distance; i++)
		{
			PORTA = 0x30;
			_delay_ms(period);
			PORTA = 0x60;
			_delay_ms(period);
			PORTA = 0xc0;
			_delay_ms(period);
			PORTA = 0x90;
			_delay_ms(period);
			PORTA = 0x30;
			_delay_ms(period);
		}

		_delay_ms(10);
	}
	else
	{
		/* Rotate  Counterclockwise  */
		for (int i = 0; i < abs(distance); i++)
		{
			PORTA = 0x30;
			_delay_ms(period);
			PORTA = 0x90;
			_delay_ms(period);
			PORTA = 0xc0;
			_delay_ms(period);
			PORTA = 0x60;
			_delay_ms(period);
			PORTA = 0x30;
			_delay_ms(period);
		}

		_delay_ms(10);
	}
}

void rotateStepper_3(int distance){
	// clockwise-1
	// Counterclockwise-0
	// 1 distance unit = 1 rotating

	int period;
	period = 100;
	if (distance>0)
	{
		/* Rotate  clockwise */
		for(int i=0;i<distance;i++)
		{
			PORTC = 0x03;
			_delay_ms(period);
			PORTC = 0x06;
			_delay_ms(period);
			PORTC = 0x0c;
			_delay_ms(period);
			PORTC = 0x09;
			_delay_ms(period);
			PORTC = 0x03;
			_delay_ms(period);
		}

		_delay_ms(10);
	}
	else
	{
		/* Rotate  Counterclockwise  */
		for (int i = 0; i < abs(distance); i++)
		{
			PORTC = 0x03;
			_delay_ms(period);
			PORTC = 0x09;
			_delay_ms(period);
			PORTC = 0x0c;
			_delay_ms(period);
			PORTC = 0x06;
			_delay_ms(period);
			PORTC = 0x03;
			_delay_ms(period);
		}

		_delay_ms(10);
	}
}

void rotateStepper_4(int direction){
	// clockwise-1
	// Counterclockwise-0
	// 1 distance unit = 1 rotating

	int period;
	period = 100;
	if (direction == 1)
	{
		/* Rotate  clockwise */
		PORTC = 0x30;
		_delay_ms(period);
		PORTC = 0x60;
		_delay_ms(period);
	}
	else
	{
		/* Rotate  Counterclockwise  */
		PORTC = 0x60;
		_delay_ms(period);
		PORTC = 0x30;
		_delay_ms(period);
	}
}

void rotateStepper_1_and_2(int Stepper_1_Distance,int Stepper_2_Distance){
	int period;
	period = 100;
	
	if(Stepper_1_Distance>0&&Stepper_2_Distance>0){
		int defference=abs(Stepper_1_Distance-Stepper_2_Distance);
		if (Stepper_1_Distance>Stepper_2_Distance){
			for (int i = 0; i <Stepper_2_Distance; i++)
			{
				PORTA = 0x33;
				_delay_ms(period);
				PORTA = 0x66;
				_delay_ms(period);
				PORTA = 0xcc;
				_delay_ms(period);
				PORTA = 0x99;
				_delay_ms(period);
				PORTA = 0x33;
				_delay_ms(period);
			}
			_delay_ms(10);
			
			for (int i = 0; i <defference; i++)
			{
				PORTA = 0x03;
				_delay_ms(period);
				PORTA = 0x06;
				_delay_ms(period);
				PORTA = 0x0c;
				_delay_ms(period);
				PORTA = 0x09;
				_delay_ms(period);
				PORTA = 0x03;
				_delay_ms(period);
			}
			_delay_ms(10);
			
		}else  if(Stepper_2_Distance>Stepper_1_Distance){
			for (int i = 0; i <Stepper_1_Distance; i++)
			{
				PORTA = 0x33;
				_delay_ms(period);
				PORTA = 0x66;
				_delay_ms(period);
				PORTA = 0xcc;
				_delay_ms(period);
				PORTA = 0x99;
				_delay_ms(period);
				PORTA = 0x33;
				_delay_ms(period);
			}
			_delay_ms(10);
			
			for (int i = 0; i <defference; i++)
			{
				PORTA = 0x30;
				_delay_ms(period);
				PORTA = 0x60;
				_delay_ms(period);
				PORTA = 0xc0;
				_delay_ms(period);
				PORTA = 0x90;
				_delay_ms(period);
				PORTA = 0x30;
				_delay_ms(period);
			}
			_delay_ms(10);
			
		}else{
			for (int i = 0; i <Stepper_1_Distance; i++){
				PORTA = 0x33;
				_delay_ms(period);
				PORTA = 0x66;
				_delay_ms(period);
				PORTA = 0xcc;
				_delay_ms(period);
				PORTA = 0x99;
				_delay_ms(period);
				PORTA = 0x33;
				_delay_ms(period);	
			}
			_delay_ms(10);
		}
	}else if(Stepper_1_Distance<0&&Stepper_2_Distance<0){
		int defference=abs(Stepper_1_Distance-Stepper_2_Distance);
		if (abs(Stepper_1_Distance)>abs(Stepper_2_Distance)){
				for (int i = 0; i <abs(Stepper_2_Distance); i++)
				{
					PORTA = 0x33;
					_delay_ms(period);
					PORTA = 0x99;
					_delay_ms(period);
					PORTA = 0xcc;
					_delay_ms(period);
					PORTA = 0x66;
					_delay_ms(period);
					PORTA = 0x33;
					_delay_ms(period);
				}
				_delay_ms(10);
			
				for (int i = 0; i <defference; i++)
				{
					PORTA = 0x03;
					_delay_ms(period);
					PORTA = 0x09;
					_delay_ms(period);
					PORTA = 0x0c;
					_delay_ms(period);
					PORTA = 0x06;
					_delay_ms(period);
					PORTA = 0x03;
					_delay_ms(period);
				}
				_delay_ms(10);
			
			}else  if(abs(Stepper_2_Distance)>abs(Stepper_1_Distance)){
				for (int i = 0; i <abs(Stepper_1_Distance); i++)
				{
					PORTA = 0x33;
					_delay_ms(period);
					PORTA = 0x99;
					_delay_ms(period);
					PORTA = 0xcc;
					_delay_ms(period);
					PORTA = 0x66;
					_delay_ms(period);
					PORTA = 0x33;
					_delay_ms(period);
				}
				_delay_ms(10);
			
				for (int i = 0; i <defference; i++)
				{
					PORTA = 0x30;
					_delay_ms(period);
					PORTA = 0x90;
					_delay_ms(period);
					PORTA = 0xc0;
					_delay_ms(period);
					PORTA = 0x60;
					_delay_ms(period);
					PORTA = 0x30;
					_delay_ms(period);
				}
				_delay_ms(10);
			
			}else{
			for (int i = 0; i <Stepper_1_Distance; i++){
				PORTA = 0x33;
				_delay_ms(period);
				PORTA = 0x99;
				_delay_ms(period);
				PORTA = 0xcc;
				_delay_ms(period);
				PORTA = 0x66;
				_delay_ms(period);
				PORTA = 0x33;
				_delay_ms(period);
			}
			_delay_ms(10);
		}
	}else if(Stepper_1_Distance>0&&Stepper_2_Distance<0){
		int defference=abs(Stepper_1_Distance)-abs(Stepper_2_Distance);
		if (abs(Stepper_1_Distance)>abs(Stepper_2_Distance)){
			for (int i = 0; i <abs(Stepper_2_Distance); i++)
			{
				PORTA = 0x33;
				_delay_ms(period);
				PORTA = 0x96;
				_delay_ms(period);
				PORTA = 0xcc;
				_delay_ms(period);
				PORTA = 0x69;
				_delay_ms(period);
				PORTA = 0x33;
				_delay_ms(period);
			}
			_delay_ms(10);
			
			for (int i = 0; i <defference; i++)
			{
				PORTA = 0x03;
				_delay_ms(period);
				PORTA = 0x06;
				_delay_ms(period);
				PORTA = 0x0c;
				_delay_ms(period);
				PORTA = 0x09;
				_delay_ms(period);
				PORTA = 0x03;
				_delay_ms(period);
			}
			_delay_ms(10);
			
		}else  if(abs(Stepper_2_Distance)>abs(Stepper_1_Distance)){
			for (int i = 0; i <abs(Stepper_1_Distance); i++)
			{
				PORTA = 0x33;
				_delay_ms(period);
				PORTA = 0x96;
				_delay_ms(period);
				PORTA = 0xcc;
				_delay_ms(period);
				PORTA = 0x69;
				_delay_ms(period);
				PORTA = 0x33;
				_delay_ms(period);
			}
			_delay_ms(10);
			
			for (int i = 0; i <defference; i++)
			{
				PORTA = 0x30;
				_delay_ms(period);
				PORTA = 0x90;
				_delay_ms(period);
				PORTA = 0xc0;
				_delay_ms(period);
				PORTA = 0x60;
				_delay_ms(period);
				PORTA = 0x30;
				_delay_ms(period);
			}
			_delay_ms(10);
			
		}else{
			for (int i = 0; i <Stepper_1_Distance; i++){
				PORTA = 0x33;
				_delay_ms(period);
				PORTA = 0x96;
				_delay_ms(period);
				PORTA = 0xcc;
				_delay_ms(period);
				PORTA = 0x69;
				_delay_ms(period);
				PORTA = 0x33;
				_delay_ms(period);
			}
			_delay_ms(10);
		}
		
	}else{
		int defference=abs(Stepper_1_Distance)-abs(Stepper_2_Distance);
		if (abs(Stepper_1_Distance)>abs(Stepper_2_Distance)){
			for (int i = 0; i <Stepper_2_Distance; i++)
			{
				PORTA = 0x33;
				_delay_ms(period);
				PORTA = 0x69;
				_delay_ms(period);
				PORTA = 0xcc;
				_delay_ms(period);
				PORTA = 0x96;
				_delay_ms(period);
				PORTA = 0x33;
				_delay_ms(period);
			}
			_delay_ms(10);
			
			for (int i = 0; i <defference; i++)
			{
				PORTA = 0x03;
				_delay_ms(period);
				PORTA = 0x09;
				_delay_ms(period);
				PORTA = 0x0c;
				_delay_ms(period);
				PORTA = 0x06;
				_delay_ms(period);
				PORTA = 0x03;
				_delay_ms(period);
			}
			_delay_ms(10);
			
			}else  if(abs(Stepper_2_Distance)>abs(Stepper_1_Distance)){
			for (int i = 0; i <abs(Stepper_1_Distance); i++)
			{
				PORTA = 0x33;
				_delay_ms(period);
				PORTA = 0x69;
				_delay_ms(period);
				PORTA = 0xcc;
				_delay_ms(period);
				PORTA = 0x96;
				_delay_ms(period);
				PORTA = 0x33;
				_delay_ms(period);
			}
			_delay_ms(10);
			
			for (int i = 0; i <defference; i++)
			{
				PORTA = 0x30;
				_delay_ms(period);
				PORTA = 0x60;
				_delay_ms(period);
				PORTA = 0xc0;
				_delay_ms(period);
				PORTA = 0x90;
				_delay_ms(period);
				PORTA = 0x30;
				_delay_ms(period);
			}
			_delay_ms(10);
			
			}else{
			for (int i = 0; i <Stepper_1_Distance; i++){
				PORTA = 0x33;
				_delay_ms(period);
				PORTA = 0x69;
				_delay_ms(period);
				PORTA = 0xcc;
				_delay_ms(period);
				PORTA = 0x96;
				_delay_ms(period);
				PORTA = 0x33;
				_delay_ms(period);
			}
			_delay_ms(10);
		}
	}
}