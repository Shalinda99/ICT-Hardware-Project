/*
 * stepper.c
 *
 * Created: 6/15/2022 12:58:58 AM
 *  Author: Dasith
 */

#include "stepper.h"

void initSteppers(){
	DDRA = 0xFF;
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