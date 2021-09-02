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
#define PORTB_CLOCK_BIT         	(1U)
#define I2C0_CLOCK_BIT          	(0U)
#define I2C0_PINS_MASK						(0x0000000C)
#define I2C0_PCTL_VALUE						(0x00003300)
#define I2C0_SDA_PIN							(3U)
#define NVIC_I2C_INTERRUPT				(8U)
#define I2C0_HANDLER_PRIORITY			(0x00000040)	/* SET PRIORITY to 2*/
#define I2C0_HS_BIT_0							(4U)
#define I2C0_HS_BIT_1							(7U)
#define I2C0_ENABLE_BIT						(0U)
#define I2C0_MASTER_ENABLE_BIT		(4U)
#define I2C0_SLAVE_ENABLE_BIT		  (5U)
#define I2C0_DATA_RECEIVE_INT_BIT (0U)
#define I2C0_ACK_NACK_ENABLE			(0U)
#define I2C0_SLAVE_ADD_OFFSET			(1U)
#define I2C0_BUS_BUSY_BIT					(6U)
#define I2C0_ERROR_BIT					  (1U)
#define MASTER_TRANSMIT_ONE_BYTE	(7U)
#define MASTER_RECEIVE_ONE_BYTE	  (7U)
/*******************************************************************************
****************************TYPES DECLARATION***********************************
*******************************************************************************/
/* Enum to Select device state at initialization */
typedef enum
{
	MASTER_ENABLE,SLAVE_ENABLE
}I2C_Master_Slave_Selection;

/* Enum to Enable and Disable High Speed */
typedef enum{
	HS_DISABLE,HS_ENABLE
}HIGH_SPEED_ENABLE;


/* Configureation structure passed to the init function */
typedef struct
{
	I2C_Master_Slave_Selection s_master_slave; /* Make device at initialization Master or Slave */
	HIGH_SPEED_ENABLE s_Highspeed_Enable;	/* Enable High Speed for data transfer with 33.3MHz */
	uint8	Device_Address;								/* Store the Device address */
	/* For the equation SCL_PERIOD = 2×(1 + TPR)×(SCL_LP + SCL_HP)×CLK_PRD */  
	uint8 TPR_value; /* Range from 1 to 127 */
	
}I2C_ConfigType;

/*******************************************************************************
*****************************FUNCTIONS PROTOTYPE********************************
*******************************************************************************/

/* This function is responsible for initializing the I2C */
void I2C_init(const I2C_ConfigType *a_config_Ptr);

/* This function is responsible for Master sending one byte */
uint8 I2C_Master_sendByte(const uint8 a_slave_add ,const uint8 a_data);

/* This function is responsible for Master receiving one byte */
uint8 I2C_Master_receiveByte(const uint8 a_slave_add);

/* This function is responsible for sending one byte */
void I2C_sendByte(const uint8 a_data);

/* This function is responsible for receiving one byte */
uint8 I2C_receiveByte(void);

/* This function is responsible for Making Master or Slave */
void I2C_Master_Slave_Enable(uint8 a_master_or_slave);

/*This function is responsible for saving the address that will be called after interrupts happen*/
void I2C_callBackAdress(void(*a_Func_Ptr)(void));

extern const I2C_ConfigType I2C_Configuration;
#endif /* I2C_H */
