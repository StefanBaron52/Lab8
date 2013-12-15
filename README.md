Lab8
====

Laboratory 8 Exercise, Robot Maze

##Function

The purpose of this laboratory is to now incorporate all that we have learned about the robot. Here we use the movement and the sensor together as one. In lab 6 we just asked the robot to perform some basic functions. In lab 7 we asked the robot to respond to certain sensor detections and light up a corresponding LED on the MSP430 Launchpad. The idea behind this lab is to bring it all together to show that we can program a robot to navigate a maze without hitting any walls. The idea is that the robot will respond when a sensor comes within range of detecting an obstacle. Instead of lighting up an LED, the sensor will send a signal to the motors and will tell the robot to turn in a certain direction, into the wall or away from the wall. I implemented my code with my robot being a wall hugger, therefore, the robot will only be using two sensors to make coding easier and to not let the robot get confused with too many sensory inputs. The purpose of the wall hugger is that the robot will continuously turn into the wall and then turn away from it shortly to avoid hitting it just to return afterwards to turning into the wall again. This is known as the wall hugging robot. The robot should be able to navigate the maze to the required door, the B door, or the A door. Bonus points are rewarded for navigating the maze the opposite direction this time without changing code. 

##Required Hardward

 - MSP430 Microcontroller Chip
 - Motor Driver Chip
 - Voltage Regulator
 - MSP430 Launchpad
 - Issued Robot from United States Air Force Academy
 - Wiring Kit
 - Maze

##Lab Experiences

The lab did not go as easy as I thought it would go. I simply thought it would be just as easy as using my code from previous labs and just putting them together in the main.c file to tell the robot what I wanted it to do. It did not work like that. I actually had some trouble with the robot following the wall and sending signals to the motors to tell it what to do. I messed around with the duty cycles as well as trying to make it a right wall follower when it did not want to follow the left wall. In the end I was able to make it a left wall follower. Overall, the robot was able to achieve required functionality. I really did want to get A and B functionality, but I believe that through copying over the files from LAB 6 and LAB 7 I might have accidently deleted some code from my robot movement library, therefore, my motors were not working as I expected. I was able to code around this issue. In the end required functionality was achieved.

##Thoughts on ECE 382 Fall Semester 2013

Overall, this semester was challenging. ECE 382 required me to go beyond the hand holding and actually go out and debug, and trial and error your own problems. I spent an immense amount of time working on these labs. It was sort of frustrating because I just started to understand Lab 4 and getting Assembly down by myself, but then we jumped right in C-Programming which was a new challenge. To me it was sort of like just learning Spanish and then having to learn French right afterwards. Programming is like learning a foreign language! I was challenged with every lab to really get into the users manual and understand microcontroller operation. In the end I really enjoyed ECE 382 because I was able to physically see my labs actually do something whether it be navigate a maze or create a game or a calculator. I believe this brings the greatest satisfaction to any electrical engineering student is seeing their labs come to life and actually do something! Thank you Capt Branchflower for all of your help during this semester!
