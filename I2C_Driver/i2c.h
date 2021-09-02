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

#include "Std_Types.h"
#include "Common_Macros.h"
#include "i2c_registers.h"

/*******************************************************************************
*****************************PREPRPCESSOR MACROS********************************
*******************************************************************************/
#define PORTB_CLOCK_BIT         	(1U)					/* Bit that enables PORTB clk*/
#define I2C0_CLOCK_BIT          	(0U)					/* Bit that enables I2C0 clk */
#define I2C0_PINS_MASK						(0x0000000C)	/* Mask used to make PB2 and PB3 digital and alternative func */
#define I2C0_PCTL_VALUE						(0x00003300)  /* GPIO control value required to make PB2 and PB3 as I2C */
#define I2C0_SDA_PIN							(3U)					/* Data PIN (PB3) */
#define NVIC_I2C_INTERRUPT				(8U)					/* I2C Vectro Number */
#define I2C0_HANDLER_PRIORITY			(0x00000040)	/* SET PRIORITY to 2*/
#define I2C0_ENABLE_BIT						(0U)					/* I2C Enable and Disable Bit*/
#define I2C0_MASTER_ENABLE_BIT		(4U)					/* To Enable Master Functionality bit */
#define I2C0_SLAVE_ENABLE_BIT		  (5U)					/* To Enable Slave Functionality bit */
#define I2C0_DATA_RECEIVE_INT_BIT (0U)					/* Using the Data interrupt bit */
#define I2C0_ACK_NACK_ENABLE			(0U)					/* Slave ACK and NACK Enable */
#define I2C0_SLAVE_ADD_OFFSET			(1U)					/* Slave offset to shift address */
#define I2C0_BUS_BUSY_BIT					(6U)					/* Busy bit used to make sure bus is idle */
#define I2C0_ERROR_BIT					  (1U)					/* Error Bit used to make sure data is sent */
#define I2C0_REQUEST_READ_FLAG		(0U)					/* Flag that tells me Master send data */
#define I2C0_REQUEST_WRITE_FLAG		(1U)					/* Flag that tells me Master want data */
#define MASTER_TRANSMIT_ONE_BYTE	(7U)					/* Sequence of sending one byte by the master */
#define MASTER_RECEIVE_ONE_BYTE	  (7U)					/* Sequence of receiving one byte by the master */
/*******************************************************************************
****************************TYPES DECLARATION***********************************
*******************************************************************************/
/* Enum to Select device state at initialization */
typedef enum
{
	MASTER_ENABLE,SLAVE_ENABLE
}I2C_Master_Slave_Selection;

/* Configureation structure passed to the init function */
typedef struct
{
	I2C_Master_Slave_Selection s_master_slave; /* Make device at initialization Master or Slave */
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

/* This function responsible for checking whether the master want data or will give data */
void I2C_Slave_Check(void);

/* This function is responsible for Slave sending one byte */
void I2C_Slave_sendByte(const uint8 a_data);

/* This function is responsible for Slave receiving one byte */
uint8 I2C_Slave_receiveByte(void);

/* This function is responsible for Making Master or Slave */
void I2C_Master_Slave_Enable(uint8 a_master_or_slave);

/*This function is responsible for saving the address that will be called after Slave Check*/
void I2C_callBackAdress(void(*a_Func_Read_Ptr)(void),void(*a_Func_Write_Ptr)(void));

extern const I2C_ConfigType I2C_Configuration;
#endif /* I2C_H */
