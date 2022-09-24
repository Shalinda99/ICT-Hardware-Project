/*
 * CFile1.c
 *
 * Created: 5/22/2022 4:22:36 AM
 *  Author: Dasith
 */ 

#include "ultrasonic.h"

static volatile int i = 0;
static volatile int pulse2 = 0; // integer  to access all though the program
static volatile int j = 0;
static volatile int pulse3 = 0; // integer  to access all though the program
static volatile int ult1_count = NULL;
static volatile int16_t ult2_count = NULL;
static volatile int ult3_count = NULL;
int timer0OverFlow=0;
double timer2OverFlow=0;
int timer1OverFlow=0;

void initUltrasonic()
{
	//Initialize Ultrasonic-1
	DDRD |= 1 << PIND7;	 // set PD7 output
	GICR |= (1<<INT0); //enabling interupt 0
	//General Interrupt Control Register
	MCUCR|= (1<<ISC00); //setting interrupt triggering logic change
	// MCU control Register
	TIMSK|=(1<<TOIE0);
	TCCR0 = 0;
	
	//Initialize Ultrasonic-2
	DDRB |=(1<<PB6);
	GICR |= (1<<INT1); //enabling interupt 0
	//General Interrupt Control Register
	MCUCR|= (1<<ISC10); //setting interrupt triggering logic change
	// MCU control Register
	TIMSK|=(1<<TOIE1);
	TCCR1A = 0;
	
	//Initialize Ultrasonic-3
	DDRB |= (1<<PB7);
	GICR |= (1<<INT2); //enabling interupt 2
	//General Interrupt Control Register
	MCUCSR|= (1<<ISC2) ; //setting interrupt triggering logic LOW to HIGH
	// MCU control Register
	TIMSK|=(1<<TOIE2);
	TCCR2 = 0;
}

int getUltrasonic_1_Distance()
{
	int pulse;
	PORTD |= (1<<PIND7);
	_delay_us(30); //triggering the sensor for 30usec
	PORTD &= (~(1<<PIND7));
	
	while(ult1_count==NULL);
	
	pulse=ult1_count;
	ult1_count=NULL;
	return (pulse/58)+1;
}

int getUltrasonic_2_Distance()
{
	int pulse;
	PORTB |= (1<<PB6);
	_delay_us(30); //triggering the sensor for 30usec
	PORTB &= (~(1<<PB6));
	
	while(ult2_count==NULL);
	
	pulse=ult2_count;
	ult2_count=NULL;
	return (pulse/928)+1;
}

int getUltrasonic_3_Distance()
{
	int pulse;
	PORTB |= (1<<PB7);
	_delay_us(30); //triggering the sensor for 30usec
	PORTB &= (~(1<<PB7));
	while(ult3_count==NULL);
	
	pulse=ult3_count;
	ult3_count=NULL;
	return pulse/932.8+1;
}

ISR(INT0_vect) // interrupt service routine when there is a change in logic level
{

	if (i==1)//when logic from HIGH to LOW

	{

		TCCR0=0; //disabling counter

		ult1_count=TCNT0+timer0OverFlow;//count memory is updated to intege
		
		TCNT0=0;//resetting the counter memory

		i=0;

	}

	if (i==0)//when logic change from LOW to HIGH

	{

		TCCR0|=(1<<CS10);//enabling counter

		i=1;

	}
	timer0OverFlow=0;
}

ISR(INT1_vect) // interrupt service routine when there is a change in logic level
{

	if (j==1)//when logic from HIGH to LOW

	{

		TCCR1B=0; //disabling counter

		ult2_count=TCNT1+timer1OverFlow;//count memory is updated to intege

		TCNT1=0;//resetting the counter memory

		j=0;

	}

	if (j==0)//when logic change from LOW to HIGH

	{

		TCCR1B|=(1<<CS10);//enabling counter

		j=1;

	}
	timer1OverFlow=0;
}

ISR(INT2_vect) // interrupt service routine when there is a change in logic level
{

	if ((MCUCSR & (1<<ISC2))){//when logic change from LOW to HIGH

		TCCR2|=(1<<CS10);//enabling counter
		//i=1;
		MCUCSR &= ~(1<<ISC2) ; //HIGH to LOW
		}else{//when logic from HIGH to LOW

		TCCR2=0; //disabling counter

		ult3_count=TCNT2+timer2OverFlow;//count memory is updated to integer

		TCNT2=0;//resetting the counter memory
		//i=0;
		MCUCSR|= (1<<ISC2) ;
	}
	timer2OverFlow=0;
}

ISR(TIMER0_OVF_vect)
{
	timer0OverFlow+=256;
}

ISR(TIMER1_OVF_vect)
{
	timer1OverFlow+=65535;
}

ISR(TIMER2_OVF_vect)
{
	timer2OverFlow+=256;
}