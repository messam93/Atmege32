/*
 * SPI.h
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#ifndef SPI_H_
#define SPI_H_

#include "Macros.h"
#include "AVR_con.h"
#include "Types.h"
void SPI_ReceiveString(u8 *str);
void SPI_SendString(u8 *str);
u8 SPI_ReceiveByte();
void SPI_SendByte(u8 data);
void SPI_InitSlave();
void SPI_InitMaster();




#endif /* SPI_H_ */
