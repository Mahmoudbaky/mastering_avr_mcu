/*
 * mcal_interrupt_config.h
 *
 * Created: 3/4/2024 10:19:48 PM
 *  Author: houda
 */ 


#ifndef MCAL_INTERRUPT_CONFIG_H_
#define MCAL_INTERRUPT_CONFIG_H_

/* INCLUDS */

#include "MCAL/mcal_std_types.h"
#include <avr/io.h>
#include "MCAL/INTERRUPT/mcal_interrupt_gen_cfg.h"
#include "MCAL/GPIO/mcal_gpio.h"

/* MACRO DECLARATIONS */

#define SREG_T HWREG8(0x5F)         // I_bit bit_7

#define GICR_T   HWREG8(0x5B)
#define GIFR_T   HWREG8(0x5A)
#define MCUCR_T  HWREG8(0x55)
#define MCUCSR_T HWREG8(0x54)

#define INTERRUPT_ENABLE           1
#define INTERRUPT_DISABLE          0

#define INTERRUPT_OCCUR            1
#define INTERRUPT_NOT_OCCUR        0

#define INTERRUPT_PRIORITY_ENABLE  1
#define INTERRUPT_PRIORITY_DISABLE 0

/* MACRO FUNTIONS DECLARATIONS */

#define INTERRUPT_globalInterruptEnable()       SET_BIT(SREG_T,7)   // SREG I_BIT bit_7
#define INTERRUPT_globalInterruptDisable()      CLEAR_BIT(SREG_T,7)  // SREG I_BIT bit_7

/* DATA TYPE DECLARATIONS (ENUMS,UNIONS,STRUCTS,TYPEDEF) */

/* FUNTIONS DECLARATIONS */


#endif /* MCAL_INTERRUPT_CONFIG_H_ */