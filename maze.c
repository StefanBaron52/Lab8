#include "maze.h"

/*
 * maze.c
 *
 *  Created on: Dec 11, 2013
 *      Author: C15Stefan.BaronvonVi
 */

//Motor Part of the Code//

//----------------------------------------------------------//

void InitPinsOut() {

        P1DIR |= BIT1;        //P1.1
        P1SEL |= BIT1;
        P1DIR |= BIT2;        //P1.2
        P1SEL |= BIT2;

        P2DIR |= BIT0;        //P2.0
        P2SEL |= BIT0;
        P2DIR |= BIT1;        //P2.1
        P2SEL |= BIT1;
}

void ConfigTimer(){

    TA0CTL &= ~MC1|MC0;
    TA1CTL &= ~MC1|MC0;
    TA0CTL |= TACLR;
    TA1CTL |= TACLR;
    TA0CTL |= TASSEL1;
    TA1CTL |= TASSEL1;

    TA1CCR0 = 100; //
    TA0CCR0 = 100; //
    TA0CCR1 = 20;  //
    TA1CCR1 = 20;  //

    TA0CCTL1 |= OUTMOD_7;
    TA0CCTL0 |= OUTMOD_5;
    TA1CCTL1 |= OUTMOD_7;
    TA1CCTL0 |= OUTMOD_5;
    TA0CTL |= MC0;
    TA1CTL |= MC0;

   }

void MoveRightMotorForward() {

//        P2DIR |= BIT1;        //P2.1
//        P2SEL |= BIT1;
//        MoveTimer();
//        TA1CCTL0 = OUTMOD_5;
        TA1CCTL0 = OUTMOD_5;
        _delay_cycles(10000);
        TA1CCR1 = 50;
//        TA1CCR0 = 0;
}

void MoveRightMotorBackward() {

//        P2DIR |= BIT0;        //P2.0
//        P2SEL |= BIT0;
//        MoveTimer();
//        TA1CCTL0 = OUTMOD_4;

        TA1CCR1 = 0;
        _delay_cycles(10000);
        TA1CCTL0 = OUTMOD_4;
//        TA1CCR0 = 30;
}

void MoveLeftMotorForwardLarge() {

//        P1DIR |= BIT2;        //P1.2
//        P1SEL |= BIT2;
//        MoveTimer();
//        TA0CCTL0 = OUTMOD_5;

        TA0CCTL0 = OUTMOD_5;
        _delay_cycles(10000);
        TA0CCR1 = 60;
//        TA0CCR0 = 0;
}


void MoveLeftMotorForwardSmall() {

		TA0CCTL0 = OUTMOD_5;
		_delay_cycles(10000);
		TA0CCR1 = 30;
}


void MoveLeftMotorBackward() {

//        P1DIR |= BIT1;        //P1.1
//        P1SEL |= BIT1;
//        MoveTimer();
//        TA0CCTL0 = OUTMOD_4;

        TA0CCR1 = 0;
        _delay_cycles(10000);
        TA0CCTL0 = OUTMOD_4;
//        TA0CCR0 = 30;
}

void MoveRight() {

        MoveLeftMotorForward();
        MoveRightMotorBackward();
}

void MoveLeft() {

        MoveLeftMotorBackward();
        MoveRightMotorForward();
}

void MoveForward() {

        MoveRightMotorForward();
        MoveLeftMotorForwardSmall();
}

void MoveBackward() {

        MoveRightMotorBackward();
        MoveLeftMotorBackward();
}

//----------------------------------------------------------//

//Sensor Part of the Code//

//----------------------------------------------------------//

void initADC10() {

	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;   //ADC10ON, interrupt enabled
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;         //Select SMCLK
	ADC10CTL1 |= ADC10DIV2|ADC10DIV1|ADC10DIV0;
	ADC10AE0 |= BIT3|BIT4;
}

unsigned int leftsensor() {

	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
	ADC10CTL1 |= INCH_3;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

unsigned int centersensor() {

	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
	ADC10CTL1 |= INCH_4;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}

