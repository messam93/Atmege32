/*
 * USART.h
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#ifndef USART_H_
#define USART_H_

#include "Macros.h"
#include "AVR_con.h"
#include "Types.h"

void USART_Init();
void USART_SendByte(u8 data);
u8 USART_ReceiveByte();
void USART_SendString(u8 *str);
void USART_ReceiveString(u8 *str);



#endif /* USART_H_ */
