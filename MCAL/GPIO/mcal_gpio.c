/*
 * mcal_gpio.c
 *
 * Created: 2/16/2024 1:12:37 AM
 *  Author: houda
 */ 

#include "MCAL/GPIO/mcal_gpio.h"

volatile uint8 *ddr_registers[]    = {&DDRA,&DDRB,&DDRC,&DDRD};
volatile uint8 *pin_registers[]    = {&PINA,&PINB,&PINC,&PIND};
volatile uint8 *port_registers[]   = {&PORTA,&PORTB,&PORTC,&PORTD};
	

#if GPIO_PIN_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_inti       (const pin_config_t *_pin_config){
	Std_ReturnType ret = E_OK ;
	if ((NULL == _pin_config) || (_pin_config->pin > (MAX_NUMBER_OF_BINS-1))){
		ret = E_NOT_OK;
	}
	else{
		switch(_pin_config->direction){
			case AVR_OUTPUT :
			SET_BIT((*ddr_registers[_pin_config->port]),_pin_config->pin);
			break;
			case AVR_INPUT :
			CLEAR_BIT((*ddr_registers[_pin_config->port]),_pin_config->pin);
			break;
			default: ret = E_NOT_OK;
		}
	}
	return ret;
}
#endif

#if GPIO_PIN_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status (const pin_config_t *_pin_config  , direction_t *_direction_status){
	Std_ReturnType ret = E_OK ;
	if ((NULL == _pin_config) || (NULL == _direction_status) || (_pin_config->pin > (MAX_NUMBER_OF_BINS-1))){
		ret = E_NOT_OK;
	}
	else{
		*_direction_status = BIT_READ((*ddr_registers[_pin_config->port]),_pin_config->pin);
	}
	
	return ret;
}
#endif

#if GPIO_PIN_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic          (const pin_config_t *_pin_config , logic_t logic){
	Std_ReturnType ret = E_OK ;
	if ((NULL == _pin_config) || (_pin_config->pin > (MAX_NUMBER_OF_BINS-1))){
		ret = E_NOT_OK;
	}
	else{
		switch(logic){
			case LOW :
			CLEAR_BIT((*port_registers[_pin_config->port]),_pin_config->pin);
			break;
			case HIGH :
			SET_BIT((*port_registers[_pin_config->port]),_pin_config->pin);
			break;
			default: ret = E_NOT_OK;
		}
	}
	return ret;
}
#endif

#if GPIO_PIN_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic           (const pin_config_t *_pin_config , logic_t *logic){
	Std_ReturnType ret = E_OK ;
	if ((NULL == _pin_config) || (NULL == logic) || (_pin_config->pin > (MAX_NUMBER_OF_BINS-1))){
		ret = E_NOT_OK;
	}
	else{
		*logic = BIT_READ((*pin_registers[_pin_config->port]),_pin_config->pin);
	}
	
	return ret;
}
#endif

#if GPIO_PIN_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic         (const pin_config_t *_pin_config){
	Std_ReturnType ret = E_OK ;
	if ((NULL == _pin_config) || (_pin_config->pin > (MAX_NUMBER_OF_BINS-1))){
		ret = E_NOT_OK;
	}
	else{
		TOGGLE_BIT((*port_registers[_pin_config->port]),_pin_config->pin);
	}
}
#endif

#if GPIO_PIN_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_initialization       (const pin_config_t *_pin_config){
	Std_ReturnType ret = E_OK ;
	if ((NULL == _pin_config) || (_pin_config->pin > (MAX_NUMBER_OF_BINS-1))){
		ret = E_NOT_OK;
	}
	else{
		ret = gpio_pin_direction_inti(_pin_config);
		ret = gpio_pin_write_logic(_pin_config , _pin_config->logic);
	}
	return ret;
}
#endif

////////////////////////////////////////////////////////////////////////////////

#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_port_direction_initialization      (port_index_t port , uint8 direction){
	Std_ReturnType ret = E_OK ;
	if ((port > (MAX_NUMBER_OF_PORTS-1))){
		ret = E_NOT_OK;
	}
	else{
		*ddr_registers[port] = direction;
	}
	return ret;
}
#endif

#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status          (port_index_t port , uint8 *direction){
	Std_ReturnType ret = E_OK ;
	if ((port > (MAX_NUMBER_OF_PORTS-1)) || (NULL == direction)){
		ret = E_NOT_OK;
	}
	else{
		*direction = *ddr_registers[port];
	}
	return ret;
}
#endif

#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic                   (port_index_t port , uint8 logic){
	Std_ReturnType ret = E_OK ;
	if ((port > (MAX_NUMBER_OF_PORTS-1))){
		ret = E_NOT_OK;
	}
	else{
		*port_registers[port] = logic;
	}
	return ret;
}
#endif

#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic                    (port_index_t port , uint8 *logic){
	Std_ReturnType ret = E_OK ;
	if ((port > (MAX_NUMBER_OF_PORTS-1)) || (NULL == logic)){
		ret = E_NOT_OK;
	}
	else{
		*logic = *port_registers[port];
	}
	return ret;
}
#endif

#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic        (port_index_t port){
	Std_ReturnType ret = E_OK ;
	if ((port > (MAX_NUMBER_OF_PORTS-1))){
		ret = E_NOT_OK;
	}
	else{
		*port_registers[port] ^= 0xFF;
	}
	return ret;
}
#endif