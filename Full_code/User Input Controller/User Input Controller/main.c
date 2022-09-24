/*
 * User Input Controller.c
 *
 * Created: 5/22/2022 3:46:27 AM
 * Author : Dasith Rathnasinghe
 */ 

#define F_CPU 16000000UL
#define START 1
#define STOP 0
#define HIGH_SPEED 2
#define LOW_SPEED 3

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "lcd.h"
#include "keypad.h"
#include "dcmotor.h"
#include "usart.h"

unsigned char x;
unsigned char y;
int x1=0 ; // variable for length of the pipe
int x2=0; // variable for quantity
int8_t receivedData;

ISR(USART_RXC_vect){
	receivedData=UDR;
	if(receivedData==START){
		rotateMotor();
	}else if(receivedData==STOP){
		stopMotor();
	}else if(receivedData==HIGH_SPEED){
		setMotorSpeed(255);
	}else if(receivedData==LOW_SPEED){
		setMotorSpeed(100);
	}
}

int main(void)
{
	initUSART();
	DDRA=0x0F;
	lcd_init();
	sei();
	lcd_print("  HELLO USER ");
	_delay_ms(100);
	label1:
	lcdcmd(0x01);//clear display
	lcdcmd(0x0E);//blink the cursor
	_delay_ms(100);
	lcd_print("ENTER LENGTH");
	lcdcmd(0xC0);//bring cursor to second row
	
	do
	{
		PORTA=0xF0;
		if(PINA!=0xF0)
		{
			x=keypad();
			if(x=='/'||x=='*'||x=='-'||x=='C')
			{
				lcdcmd(0x01);
				lcdcmd(0x0E);
				_delay_ms(100);
				lcd_print("INVALID INPUT");
				_delay_ms(100);
				goto label1;
			}
			
			else if(x!='E')//read the input length x1
			{
				x1=(x1*10)+(x-'0');
				lcddata(x);
			}
		}
		
	}while(x!='E');
	
	label2:
	lcdcmd(0x01);
	lcdcmd(0x0E);
	_delay_ms(100);
	lcd_print("ENTER QUANTITY :");
	_delay_ms(100);
	lcdcmd(0xC0);
	
	do
	{
		PORTA=0xF0;
		if(PINA!=0xF0)
		{
			y=keypad();
			if(y=='/'||y=='*'||y=='-')
			{
				lcdcmd(0x01);
				lcdcmd(0x0E);
				_delay_ms(100);
				lcd_print("INVALID INPUT");
				_delay_ms(100);
				goto label2;
			}
			else if(y!='E')//read the input quantity x2
			{
				x2=y-'0';
				lcddata(y);
			}
		}
	}while(y!='E');
	
	if(y=='E')//completion of inserting relevant inputs
	{
		//send length
		sendData(x1);
		_delay_ms(100);
		sendData(x2);
	
		lcdcmd(0x01);
		lcdcmd(0x0E);
		_delay_ms(100);
		lcd_print("     Done");
		_delay_ms(100);
		lcdcmd(0x01);
		_delay_ms(500);
	}

	return 0;
}

