/*
 * proximity sensor.c
 *
 * Created: 12/12/2021 4:07:06 PM
 * Author : user
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
int main()
{
	PORTC = 0x00;
	DDRA=(1<<PA0);
	int isMetal;

	while (1)
	{
		if (PINB & 1 << PB5){ // Change DC motor speed
			// metal
			isMetal = 1;
			//sendData(HIGH_SPEED);
			
			}else{
			// PVC
			isMetal = 0;
			//sendData(LOW_SPEED);
		}
		//for demonstration only
		if(isMetal){
			PORTA |=(1<<PA0);
		}else{
			PORTA &=~(1<<PA0);
		}
	}
}




