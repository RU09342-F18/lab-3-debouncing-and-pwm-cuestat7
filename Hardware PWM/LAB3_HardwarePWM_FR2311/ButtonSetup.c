/*
 * ButtonSetup.c
 *
 *  Created on: Oct 4, 2018
 *      Author: Tiernan Cuesta
 */
#include <msp430.h>


void ButtonSetup(void)
{

     P1DIR &= ~BIT1;             // Sets button P1.1 to an input
     P1OUT |= BIT1;              // Sets P1.3 high
     P1REN |= BIT1;              // Enables pull up resistor on 1.3
     P1IE |= BIT1;               // P1.1 interrupt enabled
     P1IES |= BIT1;              // P1.1 Hi/lo edge
     P1IFG &= ~BIT1;             // P1.1 IFG cleared

}



