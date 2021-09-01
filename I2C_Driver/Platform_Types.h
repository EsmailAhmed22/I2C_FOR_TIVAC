/******************************************************************************
*
* Module name: Platform Types
*
* File Name: Platform_Types.h
*
* Description: Platform types for ARM Cortex-M4F
*
* Author: Esmail Ahmed 
*
*******************************************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/*
 * CPU register type width
 */
#define CPU_TYPE_8                                  (8U)
#define CPU_TYPE_16                                 (16U)
#define CPU_TYPE_32                                 (32U)
#define CPU_TYPE_64                                 (64U)

/*
 * Bit order definition
 */
#define MSB_FIRST                                   (0U)        /* Big endian bit ordering        */
#define LSB_FIRST                                   (1U)        /* Little endian bit ordering     */

/*
 * Byte order definition
 */
#define HIGH_BYTE_FIRST                             (0U)        /* Big endian byte ordering       */
#define LOW_BYTE_FIRST                              (1U)        /* Little endian byte ordering    */

/*
 * Boolean Values
 */
#ifndef FALSE
#define FALSE                                       (0U)
#endif
#ifndef TRUE
#define TRUE                                        (1U)
#endif

/*
 * Platform type and endianess definitions, specific for ARM Cortex-M4F
 */
#define CPU_TYPE            CPU_TYPE_32
#define CPU_BIT_ORDER       LSB_FIRST
#define CPU_BYTE_ORDER      LOW_BYTE_FIRST

typedef unsigned char           boolean;

typedef signed char             sint8;
typedef unsigned char           uint8;
typedef signed short            sint16;
typedef unsigned short          uint16;
typedef signed long             sint32;
typedef signed long long        sint64;
typedef unsigned long           uint32;
typedef unsigned long long      uint64;

typedef signed long             sint8_least;
typedef unsigned long           uint8_least;
typedef signed long             sint16_least;
typedef unsigned long           uint16_least;
typedef signed long             sint32_least;
typedef unsigned long           uint32_least;
typedef float                   float32;
typedef double                  float64; 

#endif /* PLATFORM_TYPES_H */

