/*
 * EEPROM.h
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include "Macros.h"
#include "AVR_con.h"
#include "Types.h"

void 	EEPROMWrite(u16 Address, u8 Data);
u8	EEPROMRead(u16 Address);

#endif /* EEPROM_H_ */
