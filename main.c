/*
 * NEW_AVR.c
 *
 * Created: 2/16/2024 1:09:10 AM
 * Author : houda
 */

#include "main.h"


void ISR_0_INIT (void);

ir_sensor_t sensor_1 = {
	.receiving_pin.port      = PORTD_T,
	.receiving_pin.pin       = pin2,
	.receiving_pin.direction = AVR_INPUT,
	.obj_status              = OBJ_OUT_OF_RANGE
};


pin_config_t pin_1 = {
	.port      = PORTC_T,
	.pin       = pin0,
	.direction = AVR_OUTPUT,
	.logic     = LOW
};

interrupt_INTx_t int_0 ={
	.source = INTERRUPT_EXTERNAL_INT0,
	.sense  = RISING_EDGE,
	.EXT_InterruptHandler = ISR_0_INIT,
	.mcu_pin.direction    = AVR_INPUT,
	.mcu_pin.pin          = pin2,
	.mcu_pin.port         = PORTD_T
};


Std_ReturnType ret = E_NOT_OK;

int main(void)
{
	app_init();
	
    while (1) 
    {
		
    }
}


void app_init (void){
	Std_ReturnType ret = E_NOT_OK;
	ret = gpio_pin_initialization(&pin_1);
	ret = INTx_interrupt_Init (&int_0);
	//ret = ir_sensor_intitialize(&sensor_1);
}

void ISR_0_INIT (void){
	gpio_pin_toggle_logic(&pin_1);
}