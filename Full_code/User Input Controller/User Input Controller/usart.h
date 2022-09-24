/*
 * usart.h
 *
 * Created: 5/22/2022 5:28:51 AM
 *  Author: Dasith
 */ 


#ifndef USART_H_
#define USART_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void initUSART();
void sendData(uint8_t byte);

#endif /* USART_H_ */