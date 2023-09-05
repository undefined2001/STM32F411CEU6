/*
 *  Created on: Sep 6, 2023
 *  @file: stm32f411xx_spi.h
 *  @brief: This header file contain all the things for (SPI) Serial Peripheral Interface
 *  @mcu: STM32F411CEU6
 *  @author: Asraful Islam Taj
 */

#ifndef INC_STM32F411XX_SPI_H_
#define INC_STM32F411XX_SPI_H_
#include "stm32f411xx.h"


#define ENABLE          1
#define DISABLE         0

/*--------------------------SPI_Configurations------------------------------*/

//@SPI_Mode
#define SPI_MODE_MASTER   1
#define SPI_MODE_SLAVE    0

//@SPI_Config
#define SPI_BUS_FD        1
#define SPI_BUS_HD		  2
#define SPI_BUS_TXONLY    3
#define SPI_BUS_RXONLY    4

//@SPI_Clock_Speed
#define SPI_CLK_DIV_2        0
#define SPI_CLK_DIV_4        1
#define SPI_CLK_DIV_8        2
#define SPI_CLK_DIV_16       3
#define SPI_CLK_DIV_32       4
#define SPI_CLK_DIV_64       5
#define SPI_CLK_DIV_128      6
#define SPI_CLK_DIV_256      7

//@SPI_DataFrame
#define SPI_DFF_8BITS        0
#define SPI_DFF_16BITS       1


//@SPI_Clock_Polarity
#define SPI_CPOL_HIGH        1
#define SPI_CPOL_LOW         0


//@SPI_Clock_Phase
#define SPI_CPOH_HIGH        1
#define SPI_CPOH_LOW         0


//@SPI_Slave_Select_Mode
#define SPI_SSM_SW           0
#define SPI_SSM_HW           1


//This Struct is for Carry the SPI Peripheral's Configuration

typedef struct{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}SPI_PinConfig_t;


//This Struct Handle The SPI Config

typedef struct{
	SPI_RegDef_t *SPIx;
	SPI_PinConfig_t SPI_PinConfig;
}SPI_Handle_t;

void SPI_Clock_Config(SPI_RegDef_t *SPIx, uint8_t ENorDI);
void SPI_Init(void);


#endif /* INC_STM32F411XX_SPI_H_ */
