# Hardware PWM
Boards Used - MSP430G2553, MSP430FR2311
## Functionality
These programs, indentical to software PWM, controls the brightness of an LED. The LED's brightness is controlled by a button where the brightness starts at 0% and increases by 10% untill it reaches 100% and drops back to 0. The button is debounced in that it will strictly trigger the interrupt once.

## Description of code
To achieve desired functionality the port 1, Timer0, and Timer 1 interrupt vectors were used. The Timer1 is responsibile for the button debouncing and handles that the same was as previously mentioned. TimerA0 uses CRR0 and CCR1 where TimerA is setup to be in OUT mode 7 which Resets/Sets on CCR1/CCR0 respectively. Using these two compare registers is how the PWM and duty cycle is controlled for the LED output. This also reduces the required interrupt vectors by 2 in contrast to the software PWM. The button interrupt increases the CCR1 value by 100 which increases the duty cycle by 10% and in turn increases the brightness of the LED. 
