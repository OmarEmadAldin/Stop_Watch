/*
 * Timer.h
 *
 *  Created on: 15 Sept 2022
 *      Author: Hamed
 */

#ifndef TIMER_H_
#define TIMER_H_
#include <avr/io.h>


void Timer1_OP(void){
	TCCR1A = (1<<FOC1A);
	TCCR1B=(1<<WGM12) |(1<<CS12)|(1<<CS10) ;
	TCNT1 = 0;
	OCR1A = 977;
	TIMSK|=(1<<OCIE1A);
}
// from 0 --> 977 to count a second
// TCCR1B=(1<<CS12)|(1<<CS10) to adjust the clk and prescaler to 1024
// TCCR1B=(1<<WGM12) to be used at CTC mode
// TIMSK|=(1<<OCIE1A) to enable interrupt

#endif /* TIMER_H_ */
