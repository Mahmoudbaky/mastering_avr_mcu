/*
 * mcal_external_interrupt.h
 *
 * Created: 3/4/2024 10:18:47 PM
 *  Author: houda
 */ 


#ifndef MCAL_EXTERNAL_INTERRUPT_H_
#define MCAL_EXTERNAL_INTERRUPT_H_

#include "mcal_interrupt_config.h"

/* INCLUDS */


/* MACRO DECLARATIONS */


/*  INTx ENABLE AND DISABLE  */
#define INT0_ENABLE    SET_BIT(GICR_T,6)
#define INT0_DISABLE   CLEAR_BIT(GICR_T,6)
#define INT1_ENABLE    SET_BIT(GICR_T,7)
#define INT1_DISABLE   CLEAR_BIT(GICR_T,7)
#define INT2_ENABLE    SET_BIT(GICR_T,5)
#define INT2_DISABLE   CLEAR_BIT(GICR_T,5)

/*  INTx CLEAR FLAG  */
#define INT0_FLAG_CLEAR CLEAR_BIT(GIFR_T,6)
#define INT1_FLAG_CLEAR CLEAR_BIT(GIFR_T,7)
#define INT2_FLAG_CLEAR CLEAR_BIT(GIFR_T,5)

/*  INT_0 AND INT_1 SENSE MODE  */

#define INT0_SENSE_LOW_LEVEL     CLEAR_BIT(MCUCR_T,1)|CLEAR_BIT(MCUCR_T,0)
#define INT0_SENSE_ON_CHANGE     CLEAR_BIT(MCUCR_T,1)|SET_BIT(MCUCR_T,0)
#define INT0_SENSE_FALLING_EDGE  SET_BIT(MCUCR_T,1)|CLEAR_BIT(MCUCR_T,0)
#define INT0_SENSE_RISING_EDGE   SET_BIT(MCUCR_T,1)|SET_BIT(MCUCR_T,0)

#define INT1_SENSE_LOW_LEVEL     CLEAR_BIT(MCUCR_T,3) | CLEAR_BIT(MCUCR_T,2)
#define INT1_SENSE_ON_CHANGE     CLEAR_BIT(MCUCR_T,3) | SET_BIT(MCUCR_T,2)
#define INT1_SENSE_FALLING_EDGE  SET_BIT(MCUCR_T,3)   | CLEAR_BIT(MCUCR_T,2)
#define INT1_SENSE_RISING_EDGE   SET_BIT(MCUCR_T,3)   | SET_BIT(MCUCR_T,2)

/*  INT_2 SENSE MODE  */
#define INT2_SENSE_FALLING_EDGE  CLEAR_BIT(MCUCSR_T,6)
#define INT2_SENSE_RISING_EDGE   SET_BIT(MCUCSR_T,6)


/* MACRO FUNTIONS DECLARATIONS */

/******************for INT_0********************/
/* This routine sets the interrupt enable for the external interrupt INT0 */
#define EXT_INT0_InterruptEnable()      INT0_ENABLE
/* This routine clears the interrupt enable for the external interrupt INT0 */
#define EXT_INT0_InterruptDisable()     INT0_DISABLE
/* This routine clears the interrupt flag for the external interrupt INT0 */
#define EXT_INT0_InterruptFlagClear()  INT0_FLAG_CLEAR

#define EXT_INT0_LowLevelSense()     INT0_SENSE_LOW_LEVEL

#define EXT_INT0_OnChangeSense()     INT0_SENSE_ON_CHANGE 

#define EXT_INT0_FallingEdgeSense()  INT0_SENSE_FALLING_EDGE

#define EXT_INT0_RisingEdgeSense()   INT0_SENSE_RISING_EDGE

/******************for INT_1********************/
/* This routine sets the interrupt enable for the external interrupt INT1 */
#define EXT_INT1_InterruptEnable()     INT1_ENABLE
/* This routine clears the interrupt enable for the external interrupt INT1 */
#define EXT_INT1_InterruptDisable()    INT1_DISABLE
/* This routine clears the interrupt flag for the external interrupt INT1*/
#define EXT_INT1_InterruptFlagClear() INT1_FLAG_CLEAR

#define EXT_INT1_LowLevelSense()     INT1_SENSE_LOW_LEVEL

#define EXT_INT1_OnChangeSense()     INT1_SENSE_ON_CHANGE

#define EXT_INT1_FallingEdgeSense()  INT1_SENSE_FALLING_EDGE

#define EXT_INT1_RisingEdgeSense()   INT1_SENSE_RISING_EDGE

/******************for INT_2********************/
/* This routine sets the interrupt enable for the external interrupt INT2 */
#define EXT_INT2_InterruptEnable()     INT2_ENABLE
/* This routine clears the interrupt enable for the external interrupt INT2 */
#define EXT_INT2_InterruptDisable()    INT2_DISABLE
/* This routine clears the interrupt flag for the external interrupt, INT2 */
#define EXT_INT2_InterruptFlagClear() INT2_FLAG_CLEAR 

#define EXT_INT2_FallingEdgeSense()  INT2_SENSE_FALLING_EDGE

#define EXT_INT2_RisingEdgeSense()   INT2_SENSE_RISING_EDGE

/* DATA TYPE DECLARATIONS (ENUMS,UNIONS,STRUCTS,TYPEDEF) */

typedef void (*InterruptHandler)(void);

typedef enum{
	LOW_LEVEL =  0,
	ON_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}sense_mode_t;


typedef enum{
	INTERRUPT_EXTERNAL_INT0 =  0,
	INTERRUPT_EXTERNAL_INT1,
	INTERRUPT_EXTERNAL_INT2
}interrupt_INTx_src;


typedef struct{
	void (* EXT_InterruptHandler)(void);
	void (* EXT_InterruptHandlerHigh)(void);
	void (* EXT_InterruptHandlerLow)(void);
	pin_config_t           mcu_pin;
	sense_mode_t           sense;
	interrupt_INTx_src     source;
}interrupt_INTx_t;


/* FUNTIONS DECLARATIONS */

Std_ReturnType INTx_interrupt_Init  (const interrupt_INTx_t *int_obj);
Std_ReturnType INTx_interrupt_DeInit(const interrupt_INTx_t *int_obj);


#endif /* MCAL_EXTERNAL_INTERRUPT_H_ */