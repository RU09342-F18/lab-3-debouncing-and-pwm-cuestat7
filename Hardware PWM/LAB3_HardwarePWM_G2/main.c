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
  WDTCTL = WDTPW + WDTHOLD;                // Stop WDT
  BCSCTL3 = LFXT1S_2;                      // Forces ACLK to use internal oscillator

  //LEDSetup();
  TimerA0Setup();
  TimerA1Setup();
  ButtonSetup();

   P1DIR |= BIT6 + BIT0;                    // Sets P1.0 and P1.6 to be an output pin
   P1OUT &= ~(BIT6+BIT0);                   // Initiates LED0 and LED1 off
   P1SEL |= BIT6;                           // Sets P1.0 to TA0 output
   P1SEL2 &= ~BIT6;                         // Selects default function for P1.0

      __enable_interrupt();
}
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{

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

    P1OUT |= BIT0;
    P1IE &= ~BIT3;
}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer1_A0(void)

{
    P1IE |= BIT3;                              // Enables the button port interrupt
    TA1CTL = 0x0000;                           // Resets Timer A0
    P1OUT &= ~BIT0;                            // Turns LED P1.0 off
}

