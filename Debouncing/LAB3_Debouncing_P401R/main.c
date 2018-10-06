//Tiernan Cuesta
    //Version: 1
    //Revised 9/28
    //Lab 3: Button Debounce with P401R
#include "msp.h"

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

	  // LED setup
	  P1DIR |= BIT0;                            // Set P1.0 to output direction
	  P1OUT &= ~BIT0;                           // Initializes P1.0 low
	  // Button setup
	  P1DIR &= ~BIT1;                           // Sets P1.1 to input direction
	  P1REN |= BIT1;                            // Enables the pull up resistor
	  P1OUT = BIT1;                             // Sets P1.3, button, to an input
	  P1IE |= BIT1;                             // Enables the button port interrupt
	  P1IES &= BIT1;                            // Sets interrupt to trigger on rising edge. (change | to & to have interrupt trigger on falling edge)
	  P1IFG &= ~BIT1;                           // clears button interrupt flag
	  // Timer setup
	  TA0CCTL0 = CCIE;                          // Enables CCR0 interrupt
	  NVIC->ISER[1] = 1 << ((PORT1_IRQn) & 31); // Interrupt enable P1
	  NVIC->ISER[0] = 1 << ((TA0_0_IRQn) & 31); // Interrupt enable TimerA0


	  __enable_irq();
	}

void PORT1_IRQHandler(void)

	{
	    TA0CTL = TASSEL_1 + MC_1;                // Sets timer to ACLK source, and mode control to up
	    P1IE &= ~BIT1;                           // Disables the button interrupt
	    P1OUT ^= BIT0;                           // Toggles the LED P1.0
	    P1IFG &= ~BIT1;                          // clears interrupt flag
	    TA0CCR0 = 5000;                          // Initializes TA0CCR0 interrupt value
	}
// Button debouncing interrupt service protocol
void TA0_0_IRQHandler(void)

	{
	    TA0CTL = MC_0 + TACLR;                     // Disables clock and resets for button debouncing
	    P1IE |= BIT1;                              // Enables the button port interrupt
	    P1IFG &= ~BIT1;                            // Clears interrupt flag
	}
