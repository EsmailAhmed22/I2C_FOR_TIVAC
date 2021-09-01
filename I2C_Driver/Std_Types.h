/******************************************************************************
*
* Module:Standard Types
*
* File Name: Std_Types.h
*
* Description: Contains all types that are used across several modules of the 
*              basic software and that are platform and compiler independent.
*
* Author: Esmail Ahmed
*
*******************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "Platform_Types.h"

#define STD_HIGH        0x01U          /* Physical state 5V or 3.3V */ 
#define STD_LOW         0x00U          /* Physical state 0V */

#define STD_ACTIVE      0x01U         /* Logical state active */ 
#define STD_IDLE        0x00U         /* Logical state idle */

#define STD_ON          0x01U 
#define STD_OFF         0x00U

#endif /* STD_TYPES_H */
