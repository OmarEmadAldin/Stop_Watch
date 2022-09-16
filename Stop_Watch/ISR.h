/*
 * ISR.h
 *
 *  Created on: 15 Sept 2022
 *      Author: Hamed
 */

#ifndef ISR_H_
#define ISR_H_
#include <avr/io.h>
unsigned char g_flag ;


ISR(TIMER1_COMPA_vect){
	SREG |= (1<<7);
	g_flag = 1 ;
}
// This interrupt is used to reset the stop watch
ISR(INT0_vect){
	SREG |= (1<<7);
	SecondsOne = 0;
	SecondsTwo = 0;
	MinutesOne = 0;
	MinutesTwo = 0;
	HoursOne = 0;
	HoursTwo = 0;
}
// & This is to stop the clock otherwise stop the counting process
ISR(INT1_vect){
	SREG |= (1<<7);
	TCCR1B &=~(1<<CS10) &~(1<<CS11) &~(1<<CS12);
}
// to resume the stopped process
ISR(INT2_vect){
	SREG |= (1<<7);
	TCCR1B |= (1<<CS10) |(1<<CS12);
}

#endif /* ISR_H_ */
