//Tiernan Cuesta
//Version: 1
//Revised 9/28
//Lab 3: Software PWM with G2

#include <msp430.h>

  //void LEDSetup(void);
  void TimerA0Setup(void);
  void ButtonSetup(void);
  void TimerA1Setup(void);

int main(void)
{
   WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  P1DIR |= BIT0;          // Sets P1.0 to be an output pin
  P1OUT &= ~BIT0;
  P4DIR |= BIT7;
  //LEDSetup();
  TimerA0Setup();
  TimerA1Setup();
  ButtonSetup();

  __enable_interrupt();
}
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{

    TA1CTL = TASSEL_1 + MC_1;                // Sets timer to ACLK source, and mode control to up
    P1IFG &= ~BIT1;                          // clears interrupt flag
    P1IE &= ~BIT1;
    P1OUT |= BIT0;
    // Increases the duty cycle by 10%
    TA0CCR1 = TA0CCR1 + 100;
    if (TA0CCR1 >= 1000) TA0CCR1 = 0;
}
#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer1_A0(void)

{
    P1IE |= BIT1;                              // Enables the button port interrupt
    TA1CTL = 0x0000;                           // Resets Timer A0
    P1OUT &= ~BIT0;                            //
    P1IFG &= ~BIT1;                            // Clears interrupt flag

}

#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer0_A1(void)
{
    P4OUT &= ~(BIT7);                       // Turns off red led
    TA0CCTL1 &= ~BIT0;                         // Clears interrupt flag
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0_A0(void)
{
    if(TA0CCR1 != 0) P4OUT |= (BIT7); //turns on red led
        TA0CCTL0 &= ~BIT0;  //clears flag
}
