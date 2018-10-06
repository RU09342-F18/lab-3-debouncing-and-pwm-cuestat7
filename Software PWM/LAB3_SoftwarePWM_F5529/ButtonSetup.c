/*
 * ButtonSetup.c
 *
 *  Created on: Oct 4, 2018
 *      Author: Tiernan Cuesta
 */
#include <msp430.h>


void ButtonSetup(void)
{

    P1OUT |= BIT1;              //Set pin 1.3 to a 1
    P1REN |= BIT1;              //Enable a pull up resistor on 1.3
    P1IE |= BIT1;           // P1.1 interrupt enabled
    P1IES |= BIT1;         // P1.1 Hi/lo edge
    P1IFG &= ~BIT1;              // P1.1 IFG cleared

}



