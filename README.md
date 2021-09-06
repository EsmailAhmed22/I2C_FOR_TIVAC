# I2C_FOR_TIVAC
## SUMMARY
* This module use receiver with interrupt and transmitting with polling.
* CALLBACK Address technique is used.
* Dynamic Driver for Inter-Integrated Circuit (I2C)
## OPTIONS GIVEN
* Changeable Baud rate.
* Make device Master or Slave.
* Enable Master and Slave.
## FUNCTIONS IMPLEMENTED
* __void I2C_init(const I2C_ConfigType *a_config_Ptr);__
  * This function is responsible for initializing the I2C.
* __uint8 I2C_Master_sendByte(const uint8 a_slave_add ,const uint8 a_data);__
  * This function is responsible for Master sending one byte.
* __uint8 I2C_Master_receiveByte(const uint8 a_slave_add);__
  * This function is responsible for Master receiving one byte.

* __void I2C_Slave_Check(void);__
  * This function responsible for checking whether the master want data or will give data.

* __void I2C_Slave_sendByte(const uint8 a_data);__
  * This function is responsible for Slave sending one byte.

* __uint8 I2C_Slave_receiveByte(void);__
  * This function is responsible for Slave receiving one byte.

* __void I2C_Master_Slave_Enable(uint8 a_master_or_slave);__
  * This function is responsible for Making Master or Slave.

* __void I2C_callBackAdress(void(*a_Func_Read_Ptr)(void),void(*a_Func_Write_Ptr)(void));__
  * This function is responsible for saving the address that will be called after Slave Check.
