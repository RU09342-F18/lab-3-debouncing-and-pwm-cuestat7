//Tiernan Cuesta
//Version: 1
//Revised 9/28
//Lab 3: Software PWM with G2

#include <msp430.h>


  void TimerB0Setup(void);
  void ButtonSetup(void);
  void TimerB1Setup(void);

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                // Stop WDT
  PM5CTL0 &= ~LOCKLPM5;                    // Disables the GPIO power-on default high-impedance mode

  TimerB0Setup();
  TimerB1Setup();
  ButtonSetup();

  //LED setup
   P2DIR |= BIT0;                           // Sets P2.0 to an output pin
   P2SEL0 |= BIT0;                           // Sets P1.0 to TA0 output
   P2SEL1 &= ~BIT0;                         // Selects default function for P1.0

      __enable_interrupt();
}
// Button interrupt vector service protocol
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{

    TB0CTL = TBSSEL_1 | MC_1;                // Sets timer to ACLK source, and mode control to up
    P1IFG &= ~BIT1;                          // clears interrupt flag
    P1IE &= ~BIT1;                           // Disables interrupt flag
    TB1CCR1 = TB1CCR1 + 100;                // Increase duty cycle by 10%
    if (TB1CCR1 > 1000) TB1CCR1 = 0;        // Set duty cycle back to 0% if its greater than 100%
}
//Debounce interrupt vector service protocol
#pragma vector=TIMER0_B1_VECTOR
__interrupt void Timer_B(void)

{
    P1IFG &= ~BIT1;                            // Disables interrupt flag P1.1
    P1IE |= BIT1;                              // Enables the button port interrupt
    TB0CTL = 0x0000;                           // Resets Timer B0
}
