/*
 *  Created on: Sep 6, 2023
 *  @file: stm32f411xx_gpio.h
 *  @brief: This header file contain all the things for (GPIO) General Purpose Input Output
 *  @mcu: STM32F411CEU6
 *  @author: Asraful Islam Taj
 */

#ifndef INC_STM32F411XX_GPIO_H_
#define INC_STM32F411XX_GPIO_H_
#include "stm32f411xx.h"


//GPIO Modes
#define GPIO_INPUT            0
#define GPIO_OUTPUT           1
#define GPIO_AF               2
#define GPIO_ANALOG           3
#define GPIO_IT_FTSR          4
#define GPIO_IT_RTSR          5
#define GPIO_IT_FRTSR         6

//GPIO OUTPUT TYPE
#define GPIO_OUT_PP           0
#define GPIO_OUT_OD           1

//GPIO_OUTPUT_Speed
#define GPIO_SPEED_LOW        0
#define GPIO_SPEED_MEDIUM     1
#define GPIO_SPEED_FAST       2
#define GPIO_SPEED_HIGH       3

//GPIO Pull-UP/Pull-DOWN
#define GPIO_NO_PUPD          0
#define GPIO_PULL_UP          1
#define GPIO_PULL_DOWN        2

//Extras
#define GPIO_HIGH             1
#define GPIO_LOW              0
#define ENABLE                1
#define DISABLE               0

//GPIO Pin Numbers
#define GPIO_Pin_0            0
#define GPIO_Pin_1            1
#define GPIO_Pin_2            2
#define GPIO_Pin_3            3
#define GPIO_Pin_4            4
#define GPIO_Pin_5            5
#define GPIO_Pin_6            6
#define GPIO_Pin_7            7
#define GPIO_Pin_8            8
#define GPIO_Pin_9            9
#define GPIO_Pin_10           10
#define GPIO_Pin_11           11
#define GPIO_Pin_12           12
#define GPIO_Pin_13           13
#define GPIO_Pin_14           14
#define GPIO_Pin_15           15



//GPIO COnfig Struct

typedef struct{
	uint8_t GPIO_Pin;
	uint8_t GPIO_Mode;
	uint8_t GPIO_OType;
	uint8_t GPIO_Speed;
	uint8_t GPIO_PuPd;
}GPIO_PinConfig_t;

//GPIO_Handle_Struct

typedef struct{
	GPIO_RegDef_t *GPIO;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;


void GPIO_Init(GPIO_Handle_t* GPIO_Config);
void GPIO_Delay(volatile uint32_t count);
void GPIO_Clock_Config(GPIO_RegDef_t *GPIOx, uint8_t ENorDI);
uint32_t GPIO_Read_Pin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_Pin);
void GPIO_Write_Pin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_Pin, uint8_t GPIO_Status);
void GPIO_Toggle_Pin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_Pin, uint32_t Delay);
void IRQ_Config();
void IRQ_Priority();


#endif /* INC_STM32F411XX_GPIO_H_ */
