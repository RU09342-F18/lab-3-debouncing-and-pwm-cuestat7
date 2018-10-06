/*
 * LEDSetup.c
 *
 *  Created on: Oct 3, 2018
 *      Author: Tiernan Cuesta
 */

#include <msp430.h>


void LEDsetup(void)
{
    P1DIR |= LED0;          // Sets P1.0 to be an output pin
    P1SEL |= LED0;          // Sets P1.0 to TA0 output
    P1SEL2 |= ~LED0;        // Selects default function for P1.0
}


