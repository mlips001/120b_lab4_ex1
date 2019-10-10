/*	Author: mlips001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


enum States{init, wait, led1, led2} state;

unsigned char button;
unsigned char tempB;


void led_status(){
	switch(state){
		case init:
			if(button == 1){
				state = led2;
			}
			else{
				state = init;
			}
			break;
		case wait:
			if(button == 1){
				state = led1;
			}
			else{
				state = wait;
			}
			break;
		case led1:
			if(button == 1){
				state = led1;
			}
			else{
				state = init;
			}
			break;
		case led2:
			if(button == 1){
				state = led2;
			}
			else {
				state= wait;
			}
			break;	
	}
	switch(state){
		case init:
			tempB = 0x01;
			break;
		case wait:
			tempB = 0x02;
			break;
		case led1:
			tempB = 0x01;
			break;
		case led2:
			tempB = 0x02;
			break;
	}	
}


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; 
	DDRB = 0xFF; PORTB = 0x00; 
									
	state = init;
    /* Insert your solution below */
    while (1) {

	button = PINA & 0x01;
	led_status();
	PORTB = tempB;
    }
    return 1;
}
