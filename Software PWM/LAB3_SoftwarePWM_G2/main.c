//Tiernan Cuesta
//Version: 1
//Revised 9/28
//Lab 3: Software PWM with G2

#include <msp430.h>

  void LEDSetup(void);
  void TimerA0Setup(void);
  void ButtonSetup(void);
  void TimerA1Setup(void);

int main(void)
{
   WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  P1DIR |= BIT0;          // Sets P1.0 to be an output pin
  //LEDSetup();
  TimerA0Setup();
  TimerA1Setup();
  ButtonSetup();


  __enable_interrupt();
}
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{
    BCSCTL3 = LFXT1S_2;                      // Forces ACLK to use internal oscillator
    TA1CTL = TASSEL_1 + MC_1;                // Sets timer to ACLK source, and mode control to up
    P1IFG &= ~BIT3;                          // clears interrupt flag

    if(TA0CCR1 <= 1000)
    {
        TA0CCR1 += 100;                      // Increases Duty Cycle by 10%
    }
    else if (TA0CCR1 > 1000)
    {
        TA0CCR1 = 0;
    }
}
#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer1_A0(void)

{
    P1IE |= BIT3;                              // Enables the button port interrupt
    TA1CTL = 0x0000;                           // Resets Timer A0
    P1IFG &= ~BIT3;                            // Clears interrupt flag

}

#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer0_A1(void)
{
    if(TA0CCR1 != 1000)                         // Checks if duty cycle is 100%, if not then turns on LED
    {
        P1OUT &= ~BIT0;
    }
    TA0CCTL1 &= ~BIT0;                          // Clears interrupt flag
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0_A0(void)
{
    P1OUT |= BIT0;                             // Turns P1.0 LED off
    TA0CCTL0 &= ~BIT0;
}
