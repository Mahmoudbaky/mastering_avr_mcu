/*
 * mcal_interrupt_manager.h
 *
 * Created: 3/4/2024 10:19:13 PM
 *  Author: houda
 */ 


#ifndef MCAL_INTERRUPT_MANAGER_H_
#define MCAL_INTERRUPT_MANAGER_H_


#include "mcal_interrupt_config.h"


/* INCLUDS */

/* MACRO DECLARATIONS */

/* MACRO FUNTIONS DECLARATIONS */

/* DATA TYPE DECLARATIONS (ENUMS,UNIONS,STRUCTS,TYPEDEF) */

/* FUNTIONS DECLARATIONS */
void INT0_ISR (void);
void INT1_ISR (void);
void INT2_ISR (void);

#endif /* MCAL_INTERRUPT_MANAGER_H_ */