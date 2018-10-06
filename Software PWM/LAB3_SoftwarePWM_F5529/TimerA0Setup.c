/*
 * TimerA0Setup.c
 *
 *  Created on: Oct 4, 2018
 *      Author: Tiernan Cuesta
 */
 #include <msp430.h>


void TimerA0Setup(void)
{
    TA0CCTL0 = CCIE;   // Enables CRR0 as interrupt in compare mode
    TA0CCTL1 = CCIE;   // Enables CCR1 as interrupt in compare mode
    TA0CCR0 = 1000;    // Sets the period of Timer A0 to 1000 ms
    TA0CCR1 = 0;     // Sets the period of Timer A1 to 500 ms for a duty cycle of 50%
    TA0CTL = TASSEL_2 + MC_1;

}




