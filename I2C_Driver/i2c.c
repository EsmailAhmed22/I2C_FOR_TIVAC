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
static void(*g_I2C_interrupt_Func_Ptr)(void);


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
  
  volatile uint8 delay = 0;
  
	/* Enable I2C clock*/
  SET_BIT(SYSCTL_I2C_RCGCI2C_REG,I2C0_CLOCK_BIT);
  delay = (uint8) SYSCTL_I2C_RCGCI2C_REG;
  /* Enable Port clock*/
  SET_BIT(SYSCTL_GPIO_REGCGC2_REG,PORTB_CLOCK_BIT);
  delay = (uint8) SYSCTL_GPIO_REGCGC2_REG;
	/*Select I2C as alternative function for PB2(CLK) and PB3(Data) */
  GPIO_PORTB_AFSEL_REG |= I2C0_PINS_MASK;
	GPIO_PORTB_PCTL_REG  |= I2C0_PCTL_VALUE;
  /*Set PB2 and PB3 as Digital Pins*/
  GPIO_PORTB_DEN_REG |= I2C0_PINS_MASK;
	/* Make I2CSDA PIN (PB3) open drain */
	SET_BIT(GPIO_PORTB_ODS_REG,I2C0_SDA_PIN);
	
	/* Disable I2C to configure */
	CLEAR_BIT(I2C0_MASTER_CTL_STAT_REG,I2C0_ENABLE_BIT);
	
	/* Set required TPR value */
	I2C0_MASTER_TIMER_PER_REG = a_config_Ptr->TPR_value;
	
	/* Initialize as master or slave */
	if(a_config_Ptr->s_master_slave == MASTER_ENABLE)
	{
		SET_BIT(GPIO_PORTB_DIR_REG,I2C0_SDA_PIN); /* Set clk direction */
		SET_BIT(I2C0_MASTER_CONFIG_REG,I2C0_MASTER_ENABLE_BIT);
	}
	else if(a_config_Ptr->s_master_slave == SLAVE_ENABLE)
	{
		CLEAR_BIT(GPIO_PORTB_DIR_REG,I2C0_SDA_PIN); /* Set clk direction */
		SET_BIT(I2C0_MASTER_CONFIG_REG,I2C0_SLAVE_ENABLE_BIT);
		I2C0_SLAVE_OWN_ADD_REG = a_config_Ptr->Device_Address; /* Device Slave Address */
	}
	/* Enable ACK and NACK */
	SET_BIT(I2C0_SLAVE_ACK_CTL_REG,I2C0_ACK_NACK_ENABLE);
	/* Enable receive data interrupt */
	SET_BIT(I2C0_SLAVE_INT_MASK_REG,I2C0_DATA_RECEIVE_INT_BIT);
	
	/* Set priority 2 for  SPI_Receive_Handler*/
  NVIC_PRI2_REG &= 0xFFFFFF0F;
  NVIC_PRI2_REG |= I2C0_HANDLER_PRIORITY;
  
  /* Set interrupt number in vector table */
  SET_BIT(NVIC_EN0_REG,NVIC_I2C_INTERRUPT);

	/* Enable I2C */
	SET_BIT(I2C0_MASTER_CTL_STAT_REG,I2C0_ENABLE_BIT);
}
/********************************************************************************
*[Function Name]: I2C_sendByte.
*[Description]  : This function is responsible for Master sending one byte.
*[in]		: uint8 a_slave_add: contain the address I will send data to.
*					uint8 a_data:contain data that will be sent.
*[out]		: None.
*[in/out]	: None.
*[Returns]	: None.
*********************************************************************************/
uint8 I2C_Master_sendByte(const uint8 a_slave_add ,const uint8 a_data){
	 
	/* Specifiy the operation is send */
	I2C0_MASTER_SLAVE_ADD_REG = STD_OFF;
	
	/* Write Slave address */
	I2C0_MASTER_SLAVE_ADD_REG = ((uint32)a_slave_add << I2C0_SLAVE_ADD_OFFSET);
	
	/* Write the byte to be sent */
	I2C0_MASTER_DATA_REG = a_data;
	
	/* Monitor the bus until it is idle */
	while(BIT_IS_SET(I2C0_MASTER_CTL_STAT_REG,I2C0_BUS_BUSY_BIT));
	
	/* Write the Master one byte send sequence */
	I2C0_MASTER_CTL_STAT_REG = MASTER_TRANSMIT_ONE_BYTE;
	
	/* Polling until the data is sent */
	while(BIT_IS_SET(I2C0_MASTER_CTL_STAT_REG,I2C0_BUS_BUSY_BIT));
	
	/* Check error bit */
	if( BIT_IS_CLEAR(I2C0_MASTER_CTL_STAT_REG,I2C0_ERROR_BIT))
		return E_OK;
	else
		return E_NOT_OK;
}

/********************************************************************************
*[Function Name]: SPI_receiveByte.
*[Description]  : This function is responsible for Master receiving one byte.
*[in]		: uint8 a_data:contain data that will be sent.
*[out]		: None.
*[in/out]	: None.
*[Returns]	: The received data.
*********************************************************************************/
uint8 I2C_Master_receiveByte(const uint8 a_slave_add){ 
  /* Specifiy the operation is receive */
	I2C0_MASTER_SLAVE_ADD_REG = STD_ON;
	
	/* Write Slave address */
	I2C0_MASTER_SLAVE_ADD_REG = ((uint32)a_slave_add << I2C0_SLAVE_ADD_OFFSET);
	
	/* Monitor the bus until it is idle */
	while(BIT_IS_SET(I2C0_MASTER_CTL_STAT_REG,I2C0_BUS_BUSY_BIT));
	
	/* Write the Master one byte send sequence */
	I2C0_MASTER_CTL_STAT_REG = MASTER_RECEIVE_ONE_BYTE;
	
	/* Polling until the data is sent */
	while(BIT_IS_SET(I2C0_MASTER_CTL_STAT_REG,I2C0_BUS_BUSY_BIT));
	
	/* Check error bit */
	if( BIT_IS_CLEAR(I2C0_MASTER_CTL_STAT_REG,I2C0_ERROR_BIT))
		return (uint8)I2C0_MASTER_DATA_REG;
	else
		return E_NOT_OK;
	
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
	if(a_master_or_slave == MASTER_ENABLE)
	{
		SET_BIT(GPIO_PORTB_DIR_REG,I2C0_SDA_PIN); /* Set clk direction */
		SET_BIT(I2C0_MASTER_CONFIG_REG,I2C0_MASTER_ENABLE_BIT);
	}
	else if(a_master_or_slave == SLAVE_ENABLE)
	{
		CLEAR_BIT(GPIO_PORTB_DIR_REG,I2C0_SDA_PIN); /* Set clk direction */
		SET_BIT(I2C0_MASTER_CONFIG_REG,I2C0_SLAVE_ENABLE_BIT);
	}
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
		g_I2C_interrupt_Func_Ptr = a_Func_Ptr;
}

/*******************************************************************************
***************************INTERRUPT HANDLER************************************
*******************************************************************************/

/* ISR for Receiving a Byte*/     
void I2C_Receive_Handler(void)
{
	/* Call the function in the Scheduler using Call Back concept */
	(*g_I2C_interrupt_Func_Ptr)();
}
