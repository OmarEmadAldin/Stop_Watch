/*
 * 	Stop_Watch.c
 *  Created on: 14 Sept 2022
 *  Author: Omar Ben Emad
 */
//=================================================================================================
#include <avr/io.h>
#include <util/delay.h>
#include<avr/interrupt.h>
#include"Seven_Segments.h"
#include"Interrupts.h"
#include"Timer.h"
#include"ISR.h"

void Seven_Segment_display();
void display();

int main(void){
	SREG |=(1<<7);
	// Decoder
	DDRC |= 0x0F;
	PORTC &= 0xF0;
	// Seven-Segment Enable
	DDRA |= 0x3F;
	PORTA &= 0xC0; ;
	// Timer Function and Interrupts Functions
	Timer1_OP();
	INT0_Init();
	INT1_Init();
	INT2_Init();

	while(1){
		Seven_Segment_display();
		if(g_flag==1){
			display();
			g_flag = 0 ;
		}
	}
}

