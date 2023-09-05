/*
 *  Created on: Sep 6, 2023
 *  @file: stm32f411xx_spi.c
 *  @brief: This Source file contain all the Code for (SPI) Serial Peripheral Interface
 *  @mcu: STM32F411CEU6
 *  @author: Asraful Islam Taj
 */


#include "stm32f411xx_spi.h"




void SPI_Clock_Config(SPI_RegDef_t *SPIx, uint8_t ENorDI)
{
    if (ENorDI == ENABLE)
    {
        if (SPIx == SPI1)
        {
            SPI1_PCLK_EN();
        }
        else if (SPIx == SPI2)
        {
            SPI2_PCLK_EN();
        }
        else if (SPIx == SPI3)
        {
            SPI3_PCLK_EN();
        }
        else if (SPIx == SPI4)
        {
            SPI4_PCLK_EN();
        }
    }
    else if (ENorDI == DISABLE)
    {
        if (SPIx == SPI1)
        {
            SPI1_PCLK_DI();
        }
        else if (SPIx == SPI2)
        {
            SPI2_PCLK_DI();
        }
        else if (SPIx == SPI3)
        {
            SPI3_PCLK_DI();
        }
        else if (SPIx == SPI4)
        {
            SPI4_PCLK_DI();
        }
    }
}


void SPI_Init(void){};
