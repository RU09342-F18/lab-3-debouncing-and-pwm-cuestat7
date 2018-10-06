/*
 * LEDSetup.c
 *
 *  Created on: Oct 3, 2018
 *      Author: Tiernan Cuesta
 */

#include <msp430.h>

void LEDsetup(void)
{
    P1DIR |= BIT6 + BIT0;                    // Sets P1.0 and P1.6 to be an output pin
    P1OUT &= ~(BIT6+BIT0);                   // Initiates LED0 and LED1 off
    P1SEL |= BIT6;                           // Sets P1.0 to TA0 output
    P1SEL2 &= ~BIT6;                         // Selects default function for P1.0
}




