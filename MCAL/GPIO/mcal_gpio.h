/*
 * mcal_gpio.h
 *
 * Created: 2/16/2024 1:13:30 AM
 *  Author: houda
 */ 


#ifndef MCAL_GPIO_H_
#define MCAL_GPIO_H_

/* INCLUDS */

#include "mcal_gpio_cfg.h"
#include "MCAL/mcal_std_types.h"
#include "MCAL/device_config.h"
#include <avr/io.h>

/* MACRO DECLARATIONS */
#define BIT_MASK            (uint8)1

#define MAX_NUMBER_OF_BINS  8
#define MAX_NUMBER_OF_PORTS 5

/* MACRO FUNTIONS DECLARATIONS */

#define HWREG8(_X)    (*((volatile uint8 *)(_X)))      // to convert the address to a pointer (using casting)

#define SET_BIT(REG_ADD,BIT_POSS)     (REG_ADD |=  (BIT_MASK << BIT_POSS))
#define CLEAR_BIT(REG_ADD,BIT_POSS)   (REG_ADD &= ~(BIT_MASK << BIT_POSS))
#define TOGGLE_BIT(REG_ADD,BIT_POSS)  (REG_ADD ^=  (BIT_MASK << BIT_POSS))
#define BIT_READ(REG_ADD,BIT_POSS)    ((REG_ADD >> BIT_POSS) & BIT_MASK)

/* DATA TYPE DECLARATIONS (ENUMS,UNIONS,STRUCTS,TYPEDEF) */
typedef enum {
	LOW = 0,
	HIGH
}logic_t;

typedef enum {
	AVR_INPUT = 0,
	AVR_OUTPUT
}direction_t;

typedef enum {
	pin0 = 0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7
}pin_index_t;

typedef enum {
	PORTA_T = 0,
	PORTB_T,
	PORTC_T,
	PORTD_T,
}port_index_t;

typedef struct {
	uint8 port      : 3;
	uint8 pin       : 3;
	uint8 direction : 1;
	uint8 logic     : 1;
}pin_config_t;




/* FUNTIONS DECLARATIONS */

Std_ReturnType gpio_pin_direction_inti       (const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_get_direction_status (const pin_config_t *_pin_config , direction_t *_direction_status);
Std_ReturnType gpio_pin_write_logic          (const pin_config_t *_pin_config , logic_t logic);
Std_ReturnType gpio_pin_read_logic           (const pin_config_t *_pin_config , logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic         (const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_initialization       (const pin_config_t *_pin_config);


Std_ReturnType gpio_port_direction_initialization      (port_index_t port , uint8 direction);
Std_ReturnType gpio_port_get_direction_status          (port_index_t port , uint8 *direction);
Std_ReturnType gpio_port_write_logic                   (port_index_t port , uint8 logic);
Std_ReturnType gpio_port_read_logic                    (port_index_t port , uint8 *logic);
Std_ReturnType gpio_port_toggle_logic                  (port_index_t port);


#endif /* MCAL_GPIO_H_ */