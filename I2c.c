/*
 * I2c.c
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */



#include "I2c.h"

void I2C_Init()
{
	TWBR = 0x02;
	TWCR = (1<<TWEN);
	TWSR = 0x00;
	TWAR = 0b00000010;
}

void I2C_Start()
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(Bit_Is_Clear(TWCR,TWINT));
}

void I2C_Stop()
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void I2C_Write(u8 data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(Bit_Is_Clear(TWCR,TWINT));
}

u8 I2C_Read_ACK()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(Bit_Is_Clear(TWCR,TWINT));
	return TWDR;
}

u8 I2C_Read_NO_ACK()
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(Bit_Is_Clear(TWCR,TWINT));
	return TWDR;
}

u8 I2C_Status()
{
	u8 status;
	status = (TWSR & 0xF8);
	return status;
}

