/*
 * Keypad.c
 *
 *  Created on: Jul 14, 2020
 *      Author: Empire
 */

#include "Keypad.h"

u8 GetKeyPressed()
{
      u8 r,c;
      KEYPAD_PORT|= 0X0F;

      for(c=0;c<4;c++)
      {
         KEYPAD_DDR&=~(0XFF);

         KEYPAD_DDR|=(0X80>>c);
         for(r=0;r<4;r++)
         {
            if(!(KEYPAD_PIN & (0X08>>r)))
            {
               return (r*4+c);
            }
         }
      }
	  return 0XFF;//Indicate No key pressed
}




