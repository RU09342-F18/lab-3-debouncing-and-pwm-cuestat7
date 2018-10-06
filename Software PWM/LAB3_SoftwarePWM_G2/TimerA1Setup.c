/*
 * TimerA1Setup.c
 *
 *  Created on: Oct 4, 2018
 *      Author: Tiernan Cuesta
 */
 #include <msp430.h>


void TimerA1Setup(void)
{

    TA1CCTL0 = CCIE;   // Enables CCR0 as an interrupt
    TA1CCR0 = 5000;    // Sets the period of Timer A0 to 1000 ms

}


