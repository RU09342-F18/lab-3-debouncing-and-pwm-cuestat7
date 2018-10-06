//Tiernan Cuesta
//Version: 1
//Revised 9/28
//Lab 2: Button Debounce with G2

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1DIR |= 0x01;                            // Set P1.0 to output direction
  P1REN |= BIT3;                            // Enables the pull up resistor
  P1OUT = BIT3;                             // Sets P1.3, button, to an input
  P1IE |= BIT3;                             // Enables the button port interrupt
  P1IES &= BIT3;                            // Sets interrupt to trigger on rising edge. (change | to & to have interrupt trigger on falling edge)
  P1IFG &= ~BIT3;                           // clears button interrupt flag


  __enable_interrupt();
}
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{
    BCSCTL3 = LFXT1S_2;                      // Forces ACLK to use internal oscillator
    TACTL = TASSEL_1 + MC_1;                 // Sets timer to ACLK source, and mode control to up
    CCTL0 = CCIE;                            // Enables CCR0 as the TimerA interrupt register
    CCR0 = 5000;                             // Sets interrupt, where 5000 ticks is lowest time interval to mitigate button bouncing
    P1IFG &= ~BIT3;                          // clears interrupt flag
}
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A(void)

{
    P1OUT ^= 0x01;                             // Toggles LED p1.0
    P1IE |= BIT3;                              // Enables the button port interrupt
    CCTL0 = ~CCIE;                             // Disables CRR0 as the timerA interrupt
    P1IFG &= ~BIT3;                            // Clears interrupt flag
}
