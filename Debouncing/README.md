# Debouncing
Boards Used - MSP430G2553, MSP432P401R
## Functionality
This program simply blinks a LED. The LED's blinking is controlled by a button via a port 1 and TimerA interrupt vectors. The button is debounced in that it will strictly turn the LED on once then shut off after another button press. This debouncing is used in other programs to mitigate the issue of unintended data signal.

## Description of code
To achieve desired functionality the port 1 and TimerA interrupt vectors were implemented to control the toggling of the on-board LED. First, the various inputs and outputs, the Button and LED respectively, must be set up properly. The main difference between the two programs is here at the setups with regards to syntax. Also the interrupt service protocol syntax is slightly different, however, this does not alter the functionality. What's happening in this programs is that when the button is pressed 3 main things occur. The LED turns on, the button interrupt is disabled so that the system will not register another button press, and a timer with an interrupt vector is initiated. When the timer interrupt is triggered the button's interrupt is re-enabled and can be pressed again. This same behavior occurs on the release of the button as well since bouncing can occur at this moment as well.

