/*
 * maze.h
 *
 *  Created on: Dec 11, 2013
 *      Author: C15Stefan.BaronvonVi
 */

#include <msp430g2553.h>

#ifndef MAZE_H_
#define MAZE_H_

//Motor Part of the Code//

//-------------------------------------------------//

void MoveRightMotorForward();

void MoveLeftMotorForward();

void MoveLeftMotorForwardLarge();

void MoveLeftMotorForwardSmall();

void MoveRightMotorBackward();

void MoveLeftMotorBackward();

void MoveLeft();

void MoveRight();

void InitPinsOut();

void MoveForward();

void MoveBackward();

void ConfigTimer();

//-------------------------------------------------//

//Sensor Part of the Code//

//-------------------------------------------------//


unsigned int rightsensor();

unsigned int centersensor();

unsigned int leftsensor();

void initADC10();

//-------------------------------------------------//


#endif /* MAZE_H_ */
