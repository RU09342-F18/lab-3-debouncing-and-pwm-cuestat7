/*
 * TimerB0Setup.c
 *
 *  Created on: Oct 5, 2018
 *      Author: cuest
 */
 #include <msp430.h>


void TimerB0Setup(void)
{
    TB1CCR0 = 1000;             // Sets the period of Timer B0 to 1000 ms
    TB1CCTL1 = OUTMOD_7;         // Enables CCR1 as interrupt in compare mode
    TB1CCR1 = 0;                // Sets the period of Timer B1 to 500 ms for a duty cycle of 50%
    TB1CTL = TBSSEL_2 + MC_1;   // Enables the Timer B to start counting (Small Clock, up mode, no clock division)
}




