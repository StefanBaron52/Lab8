#include <msp430g2553.h>
#include "maze.h"
/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	initADC10();
	InitPinsOut();
	ConfigTimer();

	P1DIR |= BIT0|BIT6;

	while(1) {

		unsigned int leftVal = leftsensor(), centerVal = centersensor();


		if (centerVal > 0x200){
			MoveForward();
			_delay_cycles(10000);
			P1OUT |= BIT0;
		}
		else if (leftVal > 0x250){
			MoveLeftMotorForwardSmall();
			MoveRightMotorBackward();
			_delay_cycles(10000);
		}
		else{
			MoveBackward();
			_delay_cycles(10000);


			P1OUT &= ~BIT0;
		}


		/*
		if (centerVal > 0x2ff)
			P1OUT |= BIT0;
		else
			P1OUT &= ~BIT0;

		if (leftVal > 0x150)
			P1OUT |= BIT6;
		else
			P1OUT &= ~BIT6;
			*/

}



	return 0;
}
