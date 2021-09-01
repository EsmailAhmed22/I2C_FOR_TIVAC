/******************************************************************************
*
* Module:I2C
*
* File Name: i2c.h
*
* Description: Source file for i2c module.
*
* Author: Esmail Ahmed
*
*******************************************************************************/

#include "i2c.h"

/*******************************************************************************
 *****************************GLOBAL VARIABLES**********************************
 *******************************************************************************/



/*******************************************************************************
*************************FUNCTIONS DEFINITIONS**********************************
*******************************************************************************/

/********************************************************************************
*[Function Name]: I2C_init.
*[Description]  : This function is responsible for initializing the I2C.
*[in]		: I2C_ConfigType *a_config_Ptr:pointer contains address of structure.
*[out]		: None.
*[in/out]	: None.
*[Returns]	: None.
*********************************************************************************/
void I2C_init(const I2C_ConfigType *a_config_Ptr){
  

}
/********************************************************************************
*[Function Name]: I2C_sendByte.
*[Description]  : This function is responsible for sending one byte.
*[in]		: uint8 a_data:contain data that will be sent.
*[out]		: None.
*[in/out]	: None.
*[Returns]	: None.
*********************************************************************************/
void I2C_sendByte(const uint8 a_data){
  /* Polling To check if  data is being sent */

  /* Write data I want to send */

  /* Clear Tx flag */
}

/********************************************************************************
*[Function Name]: SPI_receiveByte.
*[Description]  : This function is responsible for receiving one byte.
*[in]		: uint8 a_data:contain data that will be sent.
*[out]		: None.
*[in/out]	: None.
*[Returns]	: The received data.
*********************************************************************************/
uint8 I2C_receiveByte(void){

  /* return data */
	
}
/********************************************************************************
*[Function Name]: SPI_Master_Slave_Enable.
*[Description]  : This function is responsible for Making Master or Slave.
*[in]		: uint8 a_master_or_slave:contain data that will choose master or slave.
*[out]		: None.
*[in/out]	: None.
*[Returns]	: None.
*********************************************************************************/
void I2C_Master_Slave_Enable(uint8 a_master_or_slave){
	
	/* Select Master or Slave */
	
}
/**********************************************************************************************
 *[Function Name]:	I2C_callBackAdress
 *[Description] :This function is responsible for saving the address that will be called after interrupts happen
 *[in] :void(*a_Func_Ptr)(void): Pointer to function used to store function's address ISR will call
 *[out] :None.
 *[in/out] :None.
 *[Returns] :.
 ***********************************************************************************************/
void I2C_callBackAdress(void(*a_Func_Ptr)(void)){
}

/*******************************************************************************
***************************INTERRUPT HANDLER************************************
*******************************************************************************/

/* ISR for Receiving a Byte*/     
void I2C_Receive_Handler(void)
{
	/* Call the function in the Scheduler using Call Back concept */
	
}
