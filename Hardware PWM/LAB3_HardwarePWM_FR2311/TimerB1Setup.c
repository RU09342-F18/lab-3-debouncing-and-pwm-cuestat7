/*
 * TimerB1Setup.c
 *
 *  Created on: Oct 5, 2018
 *      Author: cuest
 */
 #include <msp430.h>


void TimerB1Setup(void)
{
    TB0CCTL0 = CCIE;                              // TB0CCR0 interrupt enabled
    TB0CCR0 = 5500;                               // Sets TB0CCR0 interrupt with parameter in Hz
    TB0CTL = TBSSEL_1 + MC_1;                     // ACLK, UP
}





