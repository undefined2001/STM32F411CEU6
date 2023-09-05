/*
 *  Created on: Sep 6, 2023
 *  @file: stm32f411xx_gpio.c
 *  @brief: This source file contain all the Code for (GPIO) General Purpose Input Output
 *  @mcu: STM32F411CEU6
 *  @author: Asraful Islam Taj
 */

#include "Stm32f411xx_gpio.h"

void GPIO_Delay(volatile uint32_t count)
{
    while (count)
    {
        count--;
    }
}

void GPIO_Clock_Config(GPIO_RegDef_t *GPIOx, uint8_t ENorDI)
{
    if (ENorDI == ENABLE)
    {
        if (GPIOx == GPIOA)
        {
            GPIOA_PCLK_EN();
        }
        else if (GPIOx == GPIOB)
        {
            GPIOB_PCLK_EN();
        }
        else if (GPIOx == GPIOC)
        {
            GPIOC_PCLK_EN();
        }
        else if (GPIOx == GPIOD)
        {
            GPIOD_PCLK_EN();
        }
        else if (GPIOx == GPIOE)
        {
            GPIOE_PCLK_EN();
        }
        else if (GPIOx == GPIOH)
        {
            GPIOH_PCLK_EN();
        }
    }
    else
    {
        if (GPIOx == GPIOA)
        {
            GPIOA_PCLK_DI();
        }
        else if (GPIOx == GPIOB)
        {
            GPIOB_PCLK_DI();
        }
        else if (GPIOx == GPIOC)
        {
            GPIOC_PCLK_DI();
        }
        else if (GPIOx == GPIOD)
        {
            GPIOD_PCLK_DI();
        }
        else if (GPIOx == GPIOE)
        {
            GPIOE_PCLK_DI();
        }
        else if (GPIOx == GPIOH)
        {
            GPIOH_PCLK_DI();
        }
    }
}

void GPIO_Init(GPIO_Handle_t *GPIO_Config)
{
    if (GPIO_Config->GPIO_PinConfig.GPIO_Mode < GPIO_ANALOG)
    {
        // This Section is For GPIO MOde

        // Clearing the two bit responsible for GPIO Mode
        GPIO_Config->GPIO->MODER &= ~(3 << (2 * GPIO_Config->GPIO_PinConfig.GPIO_Pin));

        // Setting the two bit responsible for GPIO Mode
        GPIO_Config->GPIO->MODER |= (GPIO_Config->GPIO_PinConfig.GPIO_Mode << (GPIO_Config->GPIO_PinConfig.GPIO_Pin * 2));

        // Setting the Type of the Output
        GPIO_Config->GPIO->OTYPER |= (GPIO_Config->GPIO_PinConfig.GPIO_OType << GPIO_Config->GPIO_PinConfig.GPIO_Pin);

        // Clearing the two bit responsible for GPIO Output Speed
        GPIO_Config->GPIO->OSPEEDR &= ~(3 << (2 * GPIO_Config->GPIO_PinConfig.GPIO_Pin));

        // Setting the two bit responsible for GPIO Output Speed
        GPIO_Config->GPIO->OSPEEDR |= (GPIO_Config->GPIO_PinConfig.GPIO_Speed << (2 * GPIO_Config->GPIO_PinConfig.GPIO_Pin));

        // Clearing the two bit responsible for GPIO Pull Up/ Pull Down
        GPIO_Config->GPIO->PUPDR &= ~(3 << (2 * GPIO_Config->GPIO_PinConfig.GPIO_Pin));

        // Setting the two bit responsible for GPIO Pull Up/ Pull Down
        GPIO_Config->GPIO->PUPDR |= (2 << (GPIO_Config->GPIO_PinConfig.GPIO_PuPd * GPIO_Config->GPIO_PinConfig.GPIO_Pin));
    }
}

uint32_t GPIO_Read_Pin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_Pin)
{
    uint32_t value = ((GPIOx->IDR >> GPIO_Pin) & (0x1));
    return value;
}

void GPIO_Write_Pin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_Pin, uint8_t GPIO_Status)
{
    if (GPIO_Status == GPIO_HIGH)
    {
        // Writing 1 into the Bit Set Register of BSRR
        GPIOx->BSRR |= (1 << GPIO_Pin);
    }
    else
    {
        // Writing 1 into the Bit Reset Register of BSRR
        GPIOx->BSRR |= (1 << (GPIO_Pin + 16));
    }
}

void GPIO_Toggle_Pin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_Pin, uint32_t Delay)
{
    GPIO_Write_Pin(GPIOx, GPIO_Pin, GPIO_HIGH);
    GPIO_Delay(Delay);
    GPIO_Write_Pin(GPIOx, GPIO_Pin, GPIO_LOW);
    GPIO_Delay(Delay);
}
