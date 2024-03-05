/*
 * mcal_std_types.h
 *
 * Created: 2/16/2024 1:24:17 AM
 *  Author: houda
 */ 


#ifndef MCAL_STD_TYPES_H_
#define MCAL_STD_TYPES_H_

/* INCLUDS */

#include "MCAL/std_librariesh.h"
#include "MCAL/compiler.h"

/* DATA TYPE DECLARATIONS (ENUMS,UNIONS,STRUCTS,TYPEDEF) */

typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;
typedef signed char    sint8;
typedef signed short   sint16;
typedef signed int     sint32;

typedef uint8 Std_ReturnType;


/* MACRO DECLARATIONS */

#define STD_HIGH         0X01
#define STD_LOW          0X00

#define STD_ON           0X01
#define STD_OFF          0X00

#define STD_ACTIVE       0X01
#define STD_IDLE         0X00

#define E_OK             (Std_ReturnType)0X01
#define E_NOT_OK         (Std_ReturnType)0X00


/* MACRO FUNTIONS DECLARATIONS */



/* FUNTIONS DECLARATIONS */





#endif /* MCAL_STD_TYPES_H_ */