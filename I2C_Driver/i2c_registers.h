/******************************************************************************
*
* Module:I2C
*
* File Name: i2c.h
*
* Description: Header file for TM4C123GH6PM Microcontroller - I2C Driver Registers
*
* Author: Esmail Ahmed
*
*******************************************************************************/

#ifndef I2C_REGS_H
#define I2C_REGS_H

#include "Std_Types.h"

/* Needed to initialize the port containing SPI0 Clock and I2C0 Clock */
#define SYSCTL_GPIO_REGCGC2_REG   (*((volatile uint32 *)0x400FE108))
#define SYSCTL_I2C_RCGCI2C_REG    (*((volatile uint32 *)0x400FE620))

/* Needed GPIO Registers for I2C0 pins Initialization */
#define GPIO_PORTB_AFSEL_REG      (*((volatile uint32 *)0x40005420))
#define GPIO_PORTB_PCTL_REG       (*((volatile uint32 *)0x4000552C))
#define GPIO_PORTB_DIR_REG        (*((volatile uint32 *)0x40005400))
#define GPIO_PORTB_DEN_REG        (*((volatile uint32 *)0x4000551C))
#define GPIO_PORTB_ODS_REG        (*((volatile uint32 *)0x4000550C))

/* I2C Registers for I2C0 configuration */
/* Mater Mode Registers */
#define I2C0_MASTER_SLAVE_ADD_REG	(*((volatile uint32 *)0x40020000))
#define I2C0_MASTER_CTL_STAT_REG  (*((volatile uint32 *)0x40020004))
#define I2C0_MASTER_DATA_REG	    (*((volatile uint32 *)0x40020008))
#define I2C0_MASTER_TIMER_PER_REG	(*((volatile uint32 *)0x4002000C))
#define I2C0_MASTER_INT_MASK_REG	(*((volatile uint32 *)0x40020010))
#define I2C0_MASTER_INT_STAT_REG  (*((volatile uint32 *)0x40020014))
#define I2C0_MASTER_INT_CLEAR_REG	(*((volatile uint32 *)0x4002081C))
#define I2C0_MASTER_CONFIG_REG	  (*((volatile uint32 *)0x40020020))
#define I2C0_MASTER_BUS_MON_REG	  (*((volatile uint32 *)0x4002002C))
/* Slave Mode Registers */
#define I2C0_SLAVE_OWN_ADD_REG		(*((volatile uint32 *)0x40020800))
#define I2C0_SLAVE_CTL_STAT_REG		(*((volatile uint32 *)0x40020804))
#define I2C0_SLAVE_DATA_REG		    (*((volatile uint32 *)0x40020808))
#define I2C0_SLAVE_INT_MASK_REG		(*((volatile uint32 *)0x4002080C))
#define I2C0_SLAVE_INT_STAT_REG	  (*((volatile uint32 *)0x40020810))
#define I2C0_SLAVE_INT_CLEAR_REG	(*((volatile uint32 *)0x40020818))
#define I2C0_SLAVE_ACK_CTL_REG	  (*((volatile uint32 *)0x40020820))
/* NVIC Registers for SPI0 Interrupt handling */
#define NVIC_PRI2_REG             (*((volatile uint32 *)0xE000E408))
#define NVIC_EN0_REG              (*((volatile uint32 *)0xE000E100))

#endif
