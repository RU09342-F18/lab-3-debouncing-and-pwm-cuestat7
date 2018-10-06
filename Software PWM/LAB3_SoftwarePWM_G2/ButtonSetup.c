/*
 * ButtonSetup.c
 *
 *  Created on: Oct 4, 2018
 *      Author: Tiernan Cuesta
 */
#include <msp430.h>


void ButtonSetup(void)
{

    //P1OUT |= BIT3;                            // Sets P1.3 button resistor to pull up
    P1IE |= BIT3;                             // Enables the button port interrupt
    P1IES |= BIT3;                            // Sets interrupt to trigger on rising edge. (change | to & to have interrupt trigger on falling edge)
    P1IFG &= ~BIT3;                           // clears button interrupt flag
    //P1REN |= BIT3;                            // Enable the internal resistor for P1.3
    //P1DIR &= ~BIT3;                           // Sets output direction
}



