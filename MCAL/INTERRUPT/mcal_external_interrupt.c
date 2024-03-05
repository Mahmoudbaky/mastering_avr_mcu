/*
 * mcal_external_interrupt.c
 *
 * Created: 3/4/2024 10:17:11 PM
 *  Author: houda
 */ 

#include "mcal_external_interrupt.h"

/* FUNTIONS DECLARATIONS */

/*  helper functions for INTx  */

static Std_ReturnType Interrupt_INTx_Enable       (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Disable      (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Clear_Flag   (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Set_Sense    (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Pin_Init     (const interrupt_INTx_t *int_obj);

static InterruptHandler INT0_InterruptHandler = NULL;
static InterruptHandler INT1_InterruptHandler = NULL;
static InterruptHandler INT2_InterruptHandler = NULL;

static Std_ReturnType Interrupt_Choose_Handler_INTx        (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INT0_MoveAddressFromStruct (void (*InterruptHandler)(void));
static Std_ReturnType Interrupt_INT1_MoveAddressFromStruct (void (*InterruptHandler)(void));
static Std_ReturnType Interrupt_INT2_MoveAddressFromStruct (void (*InterruptHandler)(void));

/*  helper functions for INTx  */


/********************* main INTx functions **********************/

Std_ReturnType INTx_interrupt_Init  (const interrupt_INTx_t *int_obj){
	Std_ReturnType ret = E_OK;
	if(NULL == int_obj){
		ret = E_NOT_OK;
	}
	else{
		/* Disable the External interrupt */
		ret = Interrupt_INTx_Disable(int_obj);
		/* Clear Interrupt Flag : External interrupt did not occur */
		ret = Interrupt_INTx_Clear_Flag(int_obj);
		/* Configure External interrupt sense */
		ret = Interrupt_INTx_Set_Sense (int_obj); 
		/* Configure External interrupt I/O pin */
		ret = Interrupt_INTx_Pin_Init(int_obj);
		/* Configure Default Interrupt CallBack */
		ret = Interrupt_Choose_Handler_INTx(int_obj);
		/* Enable the External interrupt */
		ret = Interrupt_INTx_Enable(int_obj);	
	}
	return ret;
}


Std_ReturnType INTx_interrupt_DeInit(const interrupt_INTx_t *int_obj){
	
	
}


void INT0_ISR (void){
	/* The INT0 external interrupt occurred (must be cleared in software) */
	EXT_INT0_InterruptFlagClear();
	/*   code    */
	
	/* Application Callback function gets called every time this ISR executes */
	if(INT0_InterruptHandler){ INT0_InterruptHandler(); }
	else{ /* Nothing */ }
}

void INT1_ISR (void){
	/* The INT1 external interrupt occurred (must be cleared in software) */
	EXT_INT0_InterruptFlagClear();
	/*   code    */
	
	/* Application Callback function gets called every time this ISR executes */
	if(INT1_InterruptHandler){ INT1_InterruptHandler(); }
	else{ /* Nothing */ }
}

void INT2_ISR (void){
	/* The INT2 external interrupt occurred (must be cleared in software) */
	EXT_INT0_InterruptFlagClear();
	/*   code    */
	
	/* Application Callback function gets called every time this ISR executes */
	if(INT2_InterruptHandler){ INT2_InterruptHandler(); }
	else{ /* Nothing */ }
}

/********************* main INTx functions **********************/


/*  helper functions for INTx  */

static Std_ReturnType Interrupt_INTx_Enable       (const interrupt_INTx_t *int_obj){
	Std_ReturnType ret = E_OK;
	if(NULL == int_obj){
		ret = E_NOT_OK;
	}
	else{
		switch(int_obj->source){
			case INTERRUPT_EXTERNAL_INT0 : 
				INTERRUPT_globalInterruptEnable();
				EXT_INT0_InterruptEnable();
				break;
			case INTERRUPT_EXTERNAL_INT1 :
				INTERRUPT_globalInterruptEnable();
				EXT_INT1_InterruptEnable();
				break;
			case INTERRUPT_EXTERNAL_INT2 :
				INTERRUPT_globalInterruptEnable();
				EXT_INT2_InterruptEnable();
				break;
		    default: ret = E_NOT_OK;	
		}
	}
	return ret;	
}

static Std_ReturnType Interrupt_INTx_Disable      (const interrupt_INTx_t *int_obj){
	Std_ReturnType ret = E_OK;
	if(NULL == int_obj){
		ret = E_NOT_OK;
	}
	else{
		switch(int_obj->source){
			case INTERRUPT_EXTERNAL_INT0 :
			EXT_INT0_InterruptDisable();
			break;
			case INTERRUPT_EXTERNAL_INT1 :
			EXT_INT1_InterruptDisable();
			break;
			case INTERRUPT_EXTERNAL_INT2 :
			EXT_INT2_InterruptDisable();
			break;
			default: ret = E_NOT_OK;
		}
	}
	return ret;
}

static Std_ReturnType Interrupt_INTx_Clear_Flag   (const interrupt_INTx_t *int_obj){
	Std_ReturnType ret = E_OK;
	if(NULL == int_obj){
		ret = E_NOT_OK;
	}
	else{
		switch(int_obj->source){
			case INTERRUPT_EXTERNAL_INT0 :
			EXT_INT0_InterruptFlagClear();
			break;
			case INTERRUPT_EXTERNAL_INT1 :
			EXT_INT1_InterruptFlagClear();
			break;
			case INTERRUPT_EXTERNAL_INT2 :
			EXT_INT2_InterruptFlagClear();
			break;
			default: ret = E_NOT_OK;
		}
	}
	return ret;
}

static Std_ReturnType Interrupt_INTx_Set_Sense    (const interrupt_INTx_t *int_obj){
	Std_ReturnType ret = E_OK;
	if(NULL == int_obj){
		ret = E_NOT_OK;
	}
	else{
		switch(int_obj->source){
			case INTERRUPT_EXTERNAL_INT0 :
				if(LOW_LEVEL == int_obj->sense)        { EXT_INT0_LowLevelSense(); }
				else if(ON_CHANGE == int_obj->sense)   { EXT_INT0_OnChangeSense(); }
				else if(FALLING_EDGE == int_obj->sense){ EXT_INT0_FallingEdgeSense(); }
				else if(RISING_EDGE == int_obj->sense) { EXT_INT0_RisingEdgeSense(); }
				else {/*nothing*/}	
				break;
			case INTERRUPT_EXTERNAL_INT1 :
				if(LOW_LEVEL == int_obj->sense)        { EXT_INT1_LowLevelSense(); }
				else if(ON_CHANGE == int_obj->sense)   { EXT_INT1_OnChangeSense(); }
				else if(FALLING_EDGE == int_obj->sense){ EXT_INT1_FallingEdgeSense(); }
				else if(RISING_EDGE == int_obj->sense) { EXT_INT1_RisingEdgeSense(); }
				else {/*nothing*/}
				break;
			case INTERRUPT_EXTERNAL_INT2 :
				if(FALLING_EDGE == int_obj->sense)    { EXT_INT2_FallingEdgeSense(); }
				else if(RISING_EDGE == int_obj->sense){ EXT_INT2_RisingEdgeSense(); }
				else {/*nothing*/}
				break;
			default: ret = E_NOT_OK;
		}
	}
	return ret;
}

static Std_ReturnType Interrupt_INTx_Pin_Init     (const interrupt_INTx_t *int_obj){
	Std_ReturnType ret = E_OK;
	if(NULL == int_obj){
		ret = E_NOT_OK;
	}
	else{
		ret = gpio_pin_direction_inti(&(int_obj->mcu_pin));
	}
	return ret;	
}

static Std_ReturnType Interrupt_Choose_Handler_INTx (const interrupt_INTx_t *int_obj){
	Std_ReturnType ret = E_OK;
	if(NULL == int_obj){
		ret = E_NOT_OK;
	}
	else{
		switch(int_obj->source){
			case INTERRUPT_EXTERNAL_INT0 :
				ret = Interrupt_INT0_MoveAddressFromStruct(int_obj->EXT_InterruptHandler);
				break;
			case INTERRUPT_EXTERNAL_INT1 :
				ret = Interrupt_INT1_MoveAddressFromStruct(int_obj->EXT_InterruptHandler);
				break;
			case INTERRUPT_EXTERNAL_INT2 :
				ret = Interrupt_INT2_MoveAddressFromStruct(int_obj->EXT_InterruptHandler);
				break;
			default : ret = E_NOT_OK;
		}
	}
	return ret;
}


static Std_ReturnType Interrupt_INT0_MoveAddressFromStruct (void (*InterruptHandler)(void)){
	Std_ReturnType ret = E_OK;
	if(NULL == InterruptHandler){
		ret = E_NOT_OK;
	}
	else{
		INT0_InterruptHandler = InterruptHandler;
	}
	return ret;
}

static Std_ReturnType Interrupt_INT1_MoveAddressFromStruct (void (*InterruptHandler)(void)){
	Std_ReturnType ret = E_OK;
	if(NULL == InterruptHandler){
		ret = E_NOT_OK;
	}
	else{
		INT1_InterruptHandler = InterruptHandler;
	}
	return ret;
}

static Std_ReturnType Interrupt_INT2_MoveAddressFromStruct (void (*InterruptHandler)(void)){
	Std_ReturnType ret = E_OK;
	if(NULL == InterruptHandler){
		ret = E_NOT_OK;
	}
	else{
		INT2_InterruptHandler = InterruptHandler;
	}
	return ret;
	
}

/*  helper functions for INTx  */