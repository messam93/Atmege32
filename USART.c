/*
 * USART.c
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#include "USART.h"

void USART_Init()
{
	UCSRA |= (1<<U2X);
	UCSRB |= (1<<RXEN) | (1<<TXEN);
	UCSRC |= (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
	UBRRH = 0;
	UBRRL = 12;
}

void USART_SendByte(u8 data)
{
	while(Bit_Is_Clear(UCSRA,UDRE));
	UDR = data;
}

u8 USART_ReceiveByte()
{
	while(Bit_Is_Clear(UCSRA,RXC));
	return UDR;
}

void USART_SendString(u8 *str)
{
	while(*str != '\0')
	{
		USART_SendByte(*str);
		str++;
	}
}

void USART_ReceiveString(u8 *str)
{
	u8 i = 0;
	str[i] = USART_ReceiveByte();
	while(str[i] != '#')
	{
		i++;
		str[i] = USART_ReceiveByte();
	}
	str[i] = '\0';
}
