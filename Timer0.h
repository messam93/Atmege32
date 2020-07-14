/*
 * Timer0.h
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#include "Macros.h"
#include "AVR_con.h"
#include "Types.h"
#define Normal_OverFlow 1
#define CTC 2
#define Fast_PWM 1
#define Phase_correct 2
void Timer0_mode(u8 mode);
void CTC_Value(u8 value );
void Timer0_PWM(u8 mode) ;




#endif /* TIMER0_H_ */
