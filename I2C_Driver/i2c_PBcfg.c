/******************************************************************************
*
* Module:I2C
*
* File Name: i2c_pbcfg.c
*
* Description: Source file for Post build configurations of i2c module. 
*
* Author: Esmail Ahmed
*
*******************************************************************************/

#include "i2c.h"

/* PB structure used with SPI_Init API */
const I2C_ConfigType I2C_Configuration= {MASTER_ENABLE, /* Initialize device in master mode  */
																				 0x10,					/* Assign a Slave address for the device */
																				 9};						/* Assign PTR value */
