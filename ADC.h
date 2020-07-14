/*
 * ADC.h
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#ifndef ADC_H_
#define ADC_H_

#include "DIO.h"
#include "Macros.h"
#include "AVR_con.h"
#include "Types.h"
void ADC_Init (void) ;
u16  ADC_Read(void) ;

#endif /* ADC_H_ */
