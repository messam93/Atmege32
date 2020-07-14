/*
 * PWM.c
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */
#include <avr/io.h>
#include<PWM.h>
void pwm_init()
{
    // initialize TCCR0 as per requirement, say as follows
    TCCR0 |= (1<<WGM00)|(1<<COM01)|(1<<WGM01)|(1<<CS00);

    // make sure to make OC0 pin (pin PB3 for atmega32) as output pin
    DDRB |= (1<<PB3);
}

