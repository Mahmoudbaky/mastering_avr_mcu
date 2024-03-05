/*
 * ecu_ir_sensor.h
 *
 * Created: 3/5/2024 7:12:11 PM
 *  Author: houda
 */ 


#ifndef ECU_IR_SENSOR_H_
#define ECU_IR_SENSOR_H_


/* INCLUDS */

#include "ecu_ir_sensor_cfg.h"
#include "MCAL/GPIO/mcal_gpio.h"

/* MACRO DECLARATIONS */

/* MACRO FUNTIONS DECLARATIONS */

/* DATA TYPE DECLARATIONS (ENUMS,UNIONS,STRUCTS,TYPEDEF) */


typedef enum{
	OBJ_OUT_OF_RANGE     = 0,
	OBJ_IN_RANGE
}obj_status_t;


typedef struct{
	pin_config_t receiving_pin;
	obj_status_t obj_status;
}ir_sensor_t;


/* FUNTIONS DECLARATIONS */

Std_ReturnType ir_sensor_intitialize(const ir_sensor_t *sensor);
Std_ReturnType ir_sensor_read_status(const ir_sensor_t *sensor,obj_status_t *obj_status);

#endif /* ECU_IR_SENSOR_H_ */