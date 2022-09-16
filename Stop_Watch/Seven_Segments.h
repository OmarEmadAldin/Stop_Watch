/*
 * Seven_Segments.h
 *
 *  Created on: 15 Sept 2022
 *      Author: Hamed
 */

#ifndef SEVEN_SEGMENTS_H_
#define SEVEN_SEGMENTS_H_
#include <avr/io.h>

// Variables for all digits
unsigned char SecondsOne = 0;
unsigned char SecondsTwo = 0;
unsigned char MinutesOne = 0;
unsigned char MinutesTwo = 0;
unsigned char HoursOne = 0;
unsigned char HoursTwo = 0;

// this style in displaying is usedd to display all the digits at once and allow the change in any of them
void Seven_Segment_display(){

	PORTA =(PORTA & 0xC0) | (1<<0) ;
	PORTC =(PORTC & 0x00) | (0x0F & SecondsOne) ;

	_delay_ms(2);
	PORTA =(PORTA & 0xC0) | (1<<1) ;
	PORTC =(PORTC & 0x00) | (0x0F & SecondsTwo) ;

	_delay_ms(2);
	PORTA =(PORTA & 0xC0) | (1<<2) ;
	PORTC =(PORTC & 0x00) | (0x0F & MinutesOne) ;

	_delay_ms(2);
	PORTA =(PORTA & 0xC0) | (1<<3) ;
	PORTC =(PORTC & 0x00) | (0x0F & MinutesTwo) ;

	_delay_ms(2);
	PORTA =(PORTA & 0xC0) | (1<<4) ;
	PORTC =(PORTC & 0x00) | (0x0F & HoursOne) ;

	_delay_ms(2);
	PORTA =(PORTA & 0xC0) | (1<<5) ;
	PORTC =(PORTC & 0x00) | (0x0F & HoursTwo) ;

	_delay_ms(2);

}
void display(){
	++SecondsOne ;
	if(SecondsOne == 10){
		SecondsOne = 0 ;
		SecondsTwo += 1;
	}
	if(SecondsTwo == 6 && SecondsOne == 0){
		SecondsTwo = 0;
		MinutesOne +=1;
	}
	if(MinutesOne == 10){
		MinutesOne = 0 ;
		MinutesTwo += 1;
	}
	if(MinutesTwo == 6 && MinutesOne == 0){
		MinutesTwo = 0;
		HoursOne +=1;
	}
	if(HoursOne==10){
		HoursOne= 0;
		HoursTwo=1;
	}
}


#endif /* SEVEN_SEGMENTS_H_ */
