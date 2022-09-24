/*
 * stepper motor_01.c
 *
 * Created: 12/4/2021 7:50:28 AM
 * Author : Amal Shalinda
 */ 

#define F_CPU 16000000UL		
#include <avr/io.h>		
#include <util/delay.h>		

void initSteppers(){
	
	DDRC = 0xFF;
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

int main(void)
{
	initSteppers();
	rotateStepper_4(1);
	_delay_ms(2000);
	rotateStepper_4(0);
}



