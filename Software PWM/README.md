# Software PWM
Boards Used - MSP430G2553, MSP430F5529
## Functionality
These programs controls the brightness of an LED. The LED's brightness is controlled by a button where the brightness starts at 50% and increases by 10% untill it reaches 100% and drops back to 0. The button is debounced in that it will strictly trigger the interrupt once.

## Description of code
To achieve desired functionality the port 1, TimerA0, and TimerA1 interrupt vectors were used. Here Timer1 takes care of the button debouncing seperately from the brightness control. TimerA0 uses two compare registers, CCR0 and CCR1 where they are set to 1000 and 500 respectively for initial duty cycle of 50%. The LED is on for the duration of CCR1 and is then turned off when the timer intterupt triggers at CCR0. When the button is pressed the duty cylce is increased to 60%. In other words, CCR1 was increased by 100 ticks.
