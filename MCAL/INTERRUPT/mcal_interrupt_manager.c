/*
 * mcal_interrupt_manager.c
 *
 * Created: 3/4/2024 10:18:31 PM
 *  Author: houda
 */ 

#include "mcal_interrupt_manager.h"

uint8 int0_en_bit = 0;


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	uint8 int0_en_bit_read   = BIT_READ(GICR_T,6);
	uint8 int0_flag_bit_read = BIT_READ(GIFR_T,6);
	
	if((INTERRUPT_ENABLE == int0_en_bit_read) && (INTERRUPT_OCCUR == int0_flag_bit_read)){
		INT0_ISR();
	}
	else{/* nothing */}

}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	
	
	
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	
	
	
}