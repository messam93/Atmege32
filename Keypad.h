/*
 * Keypad.h
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Macros.h"
#include "AVR_con.h"
#include "Types.h"

#define KEYPAD_PORT PORTD
#define KEYPAD_DDR   DDRD
#define KEYPAD_PIN   PIND
 u8 GetKeyPressed();

#endif /* KEYPAD_H_ */
