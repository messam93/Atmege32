/*
 * ADC.c
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

// following data sheet for atmega32
#include "ADC.h"
void ADC_Init (void)
{
	//setting pA0 (ADC0) as input
	Dio_SetPinDirection(PHYSICAL_PORTA_BASE_ADDRESS , PIN_0 ,INPUT_DIRECTION) ;

		//select Aref to be adc reference voltage
	CLEAR_BIT(ADMUX ,REFS0) ;
	CLEAR_BIT(ADMUX ,REFS1) ;

	//RIGHT ADJUSTMENT
	CLEAR_BIT(ADMUX ,ADLAR) ;

	//SELECT ADC0
	CLEAR_BIT(ADMUX ,MUX0) ;
	CLEAR_BIT(ADMUX ,MUX1) ;
	CLEAR_BIT(ADMUX ,MUX2) ;
	CLEAR_BIT(ADMUX ,MUX3) ;
	CLEAR_BIT(ADMUX ,MUX4) ;

	//set ADC prescaler to divide by 4
	CLEAR_BIT(ADCSRA ,ADPS0) ;
	SET_BIT(ADCSRA ,ADPS1) ;
	CLEAR_BIT(ADCSRA ,ADPS2) ;

	//enable ADC MODULE
	SET_BIT(ADCSRA ,ADEN) ;

	//select polling mode
	CLEAR_BIT(ADCSRA ,ADIE) ;
}
u16  ADC_Read(void)
{
	u8 AdcLowByte = 0 ;
		u16 AdcHighByte =0 ;
		u16 AdcValue =0 ;

		//start ADC conversion
	  SET_BIT(ADCSRA ,ADSC) ;
	    //check flag for finishing conversion
	while(GET_BIT(ADCSRA ,ADIF)==0)
	{
	}
	//clear conversion completion flag
	SET_BIT(ADCSRA ,ADIF) ;

	//getting converted value
	AdcLowByte =GET_REGISTER(ADCL) ;
	AdcHighByte =GET_REGISTER(ADCH) ;
	AdcValue =AdcLowByte ;
	AdcValue=AdcValue | (AdcHighByte <<8) ;

	return AdcValue ;
}

