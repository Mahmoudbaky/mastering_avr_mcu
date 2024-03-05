/*
 * ecu_ir_sensor.c
 *
 * Created: 3/5/2024 7:11:35 PM
 *  Author: houda
 */ 

#include "ecu_ir_sensor.h"

Std_ReturnType ir_sensor_intitialize(const ir_sensor_t *sensor){
		Std_ReturnType ret = E_OK;
		if(NULL == sensor){
			ret = E_NOT_OK;
		}
		else{
			ret = gpio_pin_direction_inti (&(sensor->receiving_pin));
		}
		return ret;
}

Std_ReturnType ir_sensor_read_status(const ir_sensor_t *sensor,obj_status_t *obj_status){
	Std_ReturnType  ret        = E_OK;
	logic_t        logicstate = LOW ;
	if((NULL == sensor) || (NULL == obj_status)){
		ret = E_NOT_OK;
	}
	else{
		ret = gpio_pin_read_logic(&(sensor->receiving_pin),&logicstate);
		if (HIGH == logicstate){
			*obj_status = OBJ_IN_RANGE;
		}
		else if(LOW == logicstate){
			*obj_status = OBJ_OUT_OF_RANGE;
		}
		else{
			// nothing
		}
	}
	return ret;	
}
