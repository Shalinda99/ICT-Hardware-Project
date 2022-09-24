/*
 * lcd.c
 *
 * Created: 5/22/2022 5:00:02 AM
 *  Author: Dasith
 */

#include "lcd.h"

void lcdcmd(unsigned char cmd)
{
	PORTC&=~(1<<RS);
	PORTC&=~(1<<RW);
	LCD=cmd & 0xF0;
	PORTD|=(1<<EN);
	_delay_ms(20);
	PORTD&=~(1<<EN);
	
	LCD=cmd<<4;
	PORTD|=(1<<EN);
	_delay_ms(20);
	PORTD&=~(1<<EN);
}

void lcddata(unsigned char data){
	//function to display input data
	PORTC|=(1<<RS);
	PORTC&=~(1<<RW);
	LCD=data & 0xF0;
	PORTD|=(1<<EN);
	_delay_ms(20);
	PORTD&=~(1<<EN);
	
	LCD=data << 4;
	PORTD|=(1<<EN);
	_delay_ms(20);
	PORTD&=~(1<<EN);
}

void lcd_init()//function to LCD initialization
{
	DDRC=0xFF;
	DDRD|=(1<<EN);
	PORTD&=~(1<<EN);
	lcdcmd(0x33);
	lcdcmd(0x32);
	lcdcmd(0x28);
	lcdcmd(0x0E);
	lcdcmd(0x01);
	_delay_ms(20);
}
void lcd_print(char *str)//function to print a given string
{
	unsigned char i=0;
	while(str[i]!=0)
	{
		lcddata(str[i]);
		i++;
	}
}