/*
 * usart.h
 *
 * Created: 5/22/2022 4:43:57 AM
 *  Author: Dasith
 */ 


#ifndef USART_H_
#define USART_H_

#define F_CPU 16000000UL
#define BAUD_PRESCALE(USART_BAUDRATE) (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

void initUSART(long USART_BAUDRATE);
void sendData(uint8_t byte);
uint8_t getReceivedData();

#endif /* USART_H_ */