/*
 * TimerA1Setup.c
 *
 *  Created on: Oct 4, 2018
 *      Author: Tiernan Cuesta
 */
 #include <msp430.h>


void TimerA1Setup(void)
{
    TA1CCTL0 = CCIE;                              // TA0CCR0 interrupt enabled
    TA1CCR0 = 2200;                               // Sets TA0CCR0 interrupt with parameter in Hz
 // TA1CTL = TASSEL_2 + MC_1;                     // ACLK, UP
}


