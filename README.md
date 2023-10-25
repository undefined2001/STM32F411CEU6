# STM32F411CEU6

## GPIO Functions

- [Introduction](#introduction)
- [GPIO_Init](#gpio_init)
- [GPIO_Clock_Config](#gpio_clock_config)
- [GPIO_Read_Pin](#gpio_read_pin)
- [GPIO_Write_Pin](#gpio_write_pin)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This is Custome Library To Controll The GPIO(General Purpose Input Output) of STM32F411CEU6. All Those Function to control 
Those GPIO pin is Provided here with all the details

## GPIO_Init

### `void GPIO_Init(GPIO_Handle_t *GPIOx)`

This Funciton is used to initialize or configure a GPIO pin there are several configuration for the pins

## GPIO_Clock_Config

### `void GPIO_Clock_Config(GPIO_Regdef_t *GPIOx, uint8_t state)`

This Function Enables or Disables a GPIO port 

## GPIO_Read_Pin

### `uint32_t GPIO_Read_Pin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_Pin)`

This function reads the state of a GPIO pin and returns the value.

## GPIO_Write_Pin

### `void GPIO_Write_Pin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_Pin, uint8_t GPIO_Status)`

This Function is usefull Write on a pin like High or Low