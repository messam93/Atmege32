/*
 * Timer0.c
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */


#include "Timer0.h"

void Timer0_mode(u8 mode)
{
	if(mode==Normal_OverFlow)
	{
/* noraml mode wave geanration */
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		/* make timer clk equal to system clk /1024 prescaler */
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		/* enable timer 0 interrupt */
		SET_BIT(TIMSK,TOIE0);
		/*enable the global interrupt */
		SET_BIT(SREG,SREG_I);
	}
	else if (mode==CTC)
	{
		/* CTC mode Wave geanration without pwm*/
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		/*toggle oco on compare match*/
		SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		/* make timer clk equal to system clk /1024 prescaler */
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		/* enable timer 0 interrupt */
		SET_BIT(TIMSK,OCIE0);
		/*enable the global interrupt */
		SET_BIT(SREG,SREG_I);
	}
}
void CTC_Value(u8 value )
{
	OCR0=value;
}

void Timer0_PWM(u8 mode)
{
	if (mode == Fast_PWM)
	{
	/* fast PWM wave geanration */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* clear oco on comapre match and set oco at top */
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	/* make timer clk equal to system clk /1024 prescaler */
	SET_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	}

	else if (mode == Phase_correct)
	{
	/* phase correct wave geanration */
	SET_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
	/* clear oco on comapre match upcounting and set oco at downcounting */
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	/* make timer clk equal to system clk /1024 prescaler */
	SET_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);

	}
}
