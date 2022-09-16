/*
 * Interrupts.h
 *
 *  Created on: 15 Sept 2022
 *      Author: Hamed
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include<avr/io.h>
// in INTO & INT2 we used it in the internal Pull up mode

void INT0_Init(void){
	MCUCR |= (1<<ISC01) &~(1<<ISC00);
	GICR =(1<<INT0);
	DDRD &= ~(1<<PD2);
	PORTD |=(1<<PD2);
}
//MCUCR |= (1<<ISC01) &~(1<<ISC00) for The falling edge of INT0
//PORTD |=(1<<PD2) for internal pull up
//GICR External Interrupt Request 0 Enable

void INT1_Init(void){
	MCUCR |=(1<<ISC11) |(1<<ISC10);
	GICR |= (1<<INT1);
	DDRD &= ~(1<<PD3);
}
//MCUCR |=(1<<ISC11) |(1<<ISC10) for the rising edge

void INT2_Init(void){
	MCUCSR &=~(1<<ISC2);
	GICR|=(1<<INT2);
	DDRD &= ~(1<<PB2);
	PORTB |=(1<<PB2);
}
//similar to INTO


#endif /* INTERRUPTS_H_ */
