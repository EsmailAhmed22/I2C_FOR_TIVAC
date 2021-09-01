/******************************************************************************
*
* Module:I2C
*
* File Name: i2c.h
*
* Description: Header file for TM4C123GH6PM Microcontroller - I2C Driver
*
* Author: Esmail Ahmed
*
*******************************************************************************/

#ifndef I2C_H
#define I2C_H

#include "i2c_cfg.h"
#include "Std_Types.h"
#include "Common_Macros.h"
#include "i2c_registers.h"

/*******************************************************************************
*****************************PREPRPCESSOR MACROS********************************
*******************************************************************************/

#define MASTER_TRANSMIT_ONE_BYTE	(7U)
#define MASTER_RECEIVE_ONE_BYTE	  (7U)

/*******************************************************************************
****************************TYPES DECLARATION***********************************
*******************************************************************************/
typedef enum{
	M_S_DISABLE,M_S_ENABLE
}MASTER_SLAVE_ENABLE;

typedef enum{
	HS_DISABLE,HS_ENABLE
}HIGH_SPEED_ENABLE;

typedef struct
{
		HIGH_SPEED_ENABLE s_Highspeed_Enable;
		MASTER_SLAVE_ENABLE s_Master_Enable;
		MASTER_SLAVE_ENABLE s_Slave_Enable;
		uint8	Device_Address;
	
}I2C_ConfigType;
/*******************************************************************************
*****************************FUNCTIONS PROTOTYPE********************************
*******************************************************************************/

/* This function is responsible for initializing the I2C */
void I2C_init(const I2C_ConfigType *a_config_Ptr);

/* This function is responsible for sending one byte */
void I2C_sendByte(const uint8 a_data);

/* This function is responsible for receiving one byte */
uint8 I2C_receiveByte(void);

/* This function is responsible for Making Master or Slave */
void I2C_Master_Slave_Enable(uint8 a_master_or_slave);

/*This function is responsible for saving the address that will be called after interrupts happen*/
void I2C_callBackAdress(void(*a_Func_Ptr)(void));

#endif /* I2C_H */
