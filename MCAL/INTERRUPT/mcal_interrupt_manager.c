/*
 * mcal_interrupt_manager.c
 *
 * Created: 3/4/2024 10:18:31 PM
 *  Author: houda
 */ 

#include "mcal_interrupt_manager.h"

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	uint8 int0_en_bit_read   = BIT_READ(GICR_T,6);
	uint8 int0_flag_bit_read = BIT_READ(GIFR_T,6);
	
	uint8 int0_sense_mode_0   = BIT_READ(MCUCR_T,0);
	uint8 int0_sense_mode_1   = BIT_READ(MCUCR_T,1);
	
	uint8 int0_read_bit       = BIT_READ(PIND,2);
	
	if((INTERRUPT_ENABLE == int0_en_bit_read) && (INTERRUPT_OCCUR == int0_flag_bit_read)){
		if((int0_sense_mode_1 == 0) && (int0_sense_mode_0 == 0)) { INT0_ISR ();}
		else if ((int0_sense_mode_1 == 0) && (int0_sense_mode_0 == 1)) {
			if(int0_read_bit == LOW) { INT0_ISR_LOW();}
			else if (int0_read_bit == HIGH) {INT0_ISR_HIGH();}
			else{/* nothing */}
		}
		else if ((int0_sense_mode_1 == 1) && (int0_sense_mode_0 == 0)){ INT0_ISR ();}
		else if ((int0_sense_mode_1 == 1) && (int0_sense_mode_0 == 1)){ INT0_ISR ();}
		else{/* nothing */}
	}
	else{/* nothing */}
}


void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	uint8 int1_en_bit_read    = BIT_READ(GICR_T,7);
	uint8 int1_flag_bit_read  = BIT_READ(GIFR_T,7);
	
	uint8 int1_sense_mode_0   = BIT_READ(MCUCR_T,2);
	uint8 int1_sense_mode_1   = BIT_READ(MCUCR_T,3);
	
	uint8 int1_read_bit       = BIT_READ(PIND,3);
	
	if((INTERRUPT_ENABLE == int1_en_bit_read) && (INTERRUPT_OCCUR == int1_flag_bit_read)){
		if((int1_sense_mode_1 == 0) && (int1_sense_mode_0 == 0)) {INT1_ISR ();}
		else if ((int1_sense_mode_1 == 0) && (int1_sense_mode_0 == 1)) {
			if(int1_read_bit == LOW)        {INT1_ISR_LOW();}
			else if (int1_read_bit == HIGH) {INT1_ISR_HIGH();}
			else{/* nothing */}
		}
		else if ((int1_sense_mode_1 == 1) && (int1_sense_mode_0 == 0)){ INT1_ISR ();}
		else if ((int1_sense_mode_1 == 1) && (int1_sense_mode_0 == 1)){ INT1_ISR ();}
		else{/* nothing */}
	}
	else{/* nothing */}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	uint8 int2_en_bit_read    = BIT_READ(GICR_T,5);
	uint8 int2_flag_bit_read  = BIT_READ(GIFR_T,5);
	
	if((INTERRUPT_ENABLE == int2_en_bit_read) && (INTERRUPT_OCCUR == int2_flag_bit_read)){
		INT2_ISR ();
	}
}