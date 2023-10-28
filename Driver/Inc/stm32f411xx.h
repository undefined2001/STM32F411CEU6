/**
 *  Created on: Aug 21, 2023
 *  @file: stm3203xx.h
 *  @brief: This is the MCU specific header file contain all the register info of the MCU
 *  @mcu: STM32F103C8T6
 *  @author: Asraful Islam Taj
 **/

#ifndef STM32F411XX_H_
#define STM32F411XX_H_
#include<stdint.h>
#define _IO volatile

#define __BIT_LEFT_SHIFT(POSITION)        (1U << (POSITION))
#define __BIT_RIGHT_SHIFT(POSITION)       ((POSITION) >> 1U)
#define __LEFT_SHIFT(VALUE, POSITION)     (((VALUE) << (POSITION)))
#define __RIGHT_SHIFT(VALUE, POSITION)    (((VALUE) >> (POSITION)))

/*********************** Here Goes Cortex-M4 Provided address ******************************/
#define SYSCLK_FREQ  16000000U

/*---------------------------Systick-------------------*/
#define SYSTICK_BASEADDR              0xE000E010U

typedef struct{
	_IO uint32_t CSR;
	_IO uint32_t RVR;
	_IO uint32_t CVR;
	_IO uint32_t CALIB;
}Systick_RegDef_t;

#define SYSTICK                    ((Systick_RegDef_t*)SYSTICK_BASEADDR)

//Here goes NVIC Related Register

#define NO_PR_BITS_IMPLEMENTED        4

#define NVIC_BASEADDR                 0xE000E100U



//Address of Memories
#define FLASH_BASEADDR                0x08000000U
#define SRAM1_BASEADDR                0x20000000U
#define SRAM                          SRAM1_BASEADDR
#define ROM                           0x1FFFF000U

//Address of Peripherals

#define PERIPH_BASEADDR               0x40000000U
#define AHB1PERIPH_BASEADDR           0x40020000U
#define AHB2PERIPH_BASEADDR           0x50000000U

#define APB1PERIPH_BASEADDR           0x40000000U
#define APB2PERIPH_BASEADDR           0x40010000U
#define RCC_BASEADDR                  0x40023800U

//Base Address of peripheral of APB2 BUS

#define GPIOA_BASEADDR               (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR				 (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR               (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR               (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR               (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOH_BASEADDR               (AHB1PERIPH_BASEADDR + 0x1C00)


#define SYSCFG_BASEADDR              (APB2PERIPH_BASEADDR + 0x3800)
#define EXTI_BASEADDR                (APB2PERIPH_BASEADDR + 0x3C00)

//Base Address of Peripherals of APB1 BUS

#define I2C1_BASEADDR                (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR                (APB1PERIPH_BASEADDR + 0x5800)

#define SPI1_BASEADDR                (APB2PERIPH_BASEADDR + 0x3000)
#define SPI2_BASEADDR                (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR                (APB1PERIPH_BASEADDR + 0x3C00)
#define SPI4_BASEADDR                (APB2PERIPH_BASEADDR + 0x3400)


#define USART1_BASEADDR              (APB2PERIPH_BASEADDR + 0x1000)
#define USART2_BASEADDR              (APB1PERIPH_BASEADDR + 0x4400)
#define USART6_BASEADDR              (APB2PERIPH_BASEADDR + 0x1400)

/***************************** This Section is For ARM Core Peripheral Structures *******************************/

typedef struct
{
	_IO uint32_t ISER[8];
	     uint32_t PADDING_0[24];
	_IO uint32_t ICER[8];
		 uint32_t PADDING_1[24];
	_IO uint32_t ISPR[8];
		 uint32_t PADDING_2[24];
	_IO uint32_t ICPR[8];
		 uint32_t PADDING_3[24];
	_IO uint32_t IABR[8];
	     uint32_t PADDING_4[56];
	_IO uint8_t IPR[240];
		 uint32_t RESERVED5[644];
	_IO uint32_t STIR;
} NVIC_RegDef_t;


/***************************** This Section is For Peripheral Structures *******************************/


/*--------------------------------This Struct is For GPIO-----------------------------*/
typedef struct{
	_IO uint32_t MODER;
	_IO uint32_t OTYPER;
	_IO uint32_t OSPEEDR;
	_IO uint32_t PUPDR;
	_IO uint32_t IDR;
	_IO uint32_t ODR;
	_IO uint32_t BSRR;
	_IO uint32_t LCKR;
	_IO uint32_t AFR[2];
}GPIO_RegDef_t;


/*--------------------------------This Struct is For RCC-----------------------------*/
typedef struct{
	_IO uint32_t CR;
	_IO uint32_t PLLCFGR;
	_IO uint32_t CFGR;
	_IO uint32_t CIR;
	_IO uint32_t AHB1RSTR;
	_IO uint32_t AHB2RSTR;
	_IO uint32_t RESERVED_ONE[2];
	_IO uint32_t APB1RSTR;
	_IO uint32_t APB2RSTR;
	_IO uint32_t RESERVED_TWO[2];
	_IO uint32_t AHB1ENR;
	_IO uint32_t AHB2ENR;
	_IO uint32_t RESERVED_THREE[2];
	_IO uint32_t APB1ENR;
	_IO uint32_t APB2ENR;
	_IO uint32_t RESERVED_FOUR[2];
	_IO uint32_t AHB1LPENR;
	_IO uint32_t AHB2LPENR;
	_IO uint32_t RESERVED_FIVE[2];
	_IO uint32_t APB1LPENR;
	_IO uint32_t APB2LPENR;
	_IO uint32_t RESERVED_SIX[2];
	_IO uint32_t BDCR;
	_IO uint32_t CSR;
	_IO uint32_t RESERVED_SEVEN[2];
	_IO uint32_t SSCGR;
	_IO uint32_t PLLI2SCFGR;
	_IO uint32_t RESERVED_EIGHT;
	_IO uint32_t DCKCFGR;
}RCC_RegDef_t;



/*--------------------------------This Struct is For EXTI-----------------------------*/
typedef struct{
	_IO uint32_t IMR;
	_IO uint32_t EMR;
	_IO uint32_t RTSR;
	_IO uint32_t FTSR;
	_IO uint32_t SWIER;
	_IO uint32_t PR;
}EXTI_RegDef_t;

/*--------------------------------This Struct is For SYSCFG-----------------------------*/
typedef struct{
	_IO uint32_t MEMRMP;
	_IO uint32_t PMC;
	_IO uint32_t EXTICR[4];
	_IO uint32_t CMPCR;
}SYSCFG_RegDef_t;


/*--------------------------------This Struct is For SPI-----------------------------*/
typedef struct{
	_IO uint32_t CR1;
	_IO uint32_t SR;
	_IO uint32_t DR;
	_IO uint32_t CRCPR;
	_IO uint32_t RXCRCR;
	_IO uint32_t TXCRCR;
	_IO uint32_t I2SCFGR;
	_IO uint32_t I2SPR;

}SPI_RegDef_t;

/*--------------------------------This Struct is For USART-----------------------------*/
typedef struct{
	_IO uint32_t SR;
	_IO uint32_t DR;
	_IO uint32_t BRR;
	_IO uint32_t CR1;
	_IO uint32_t CR2;
	_IO uint32_t CR3;
	_IO uint32_t GTPR;
}USART_RegDef_t;


/***************************** End of Peripheral Structures *******************************/

//NVIC Definition
#define NVIC                         ((NVIC_RegDef_t *)NVIC_BASEADDR)


//GPIO Peripherals Definition
#define GPIOA                        ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB                        ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC                        ((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD                        ((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE                        ((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOH                        ((GPIO_RegDef_t *)GPIOH_BASEADDR)

//SPI Definition Macros
#define SPI1                         ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2                         ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3                         ((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4                         ((SPI_RegDef_t*)SPI4_BASEADDR)

//USART Definition Macros

#define USART1                       ((USART_RegDef_t*)USART1_BASEADDR)
#define USART2                       ((USART_RegDef_t*)USART2_BASEADDR)
#define USART6                       ((USART_RegDef_t*)USART6_BASEADDR)


//RCC Peripherals Definition
#define RCC                          ((RCC_RegDef_t *)RCC_BASEADDR)

//EXTI(External Interrupt Controller)  Definition
#define SYSCFG                    	 ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

//EXTI(External Interrupt Controller)  Definition
#define EXTI                    	 ((EXTI_RegDef_t*)EXTI_BASEADDR)



/*---------------------------------------This Section is for Clock Enable Macros-----------------------------------*/

// GPIO Clock Enable Macros
#define GPIOA_PCLK_EN()              (RCC->AHB1ENR |= __BIT_LEFT_SHIFT(0))
#define GPIOB_PCLK_EN()              (RCC->AHB1ENR |= __BIT_LEFT_SHIFT(1))
#define GPIOC_PCLK_EN()              (RCC->AHB1ENR |= __BIT_LEFT_SHIFT(2))
#define GPIOD_PCLK_EN()              (RCC->AHB1ENR |= __BIT_LEFT_SHIFT(3))
#define GPIOE_PCLK_EN()              (RCC->AHB1ENR |= __BIT_LEFT_SHIFT(4))
#define GPIOH_PCLK_EN()              (RCC->AHB1ENR |= __BIT_LEFT_SHIFT(7))

//SYSCFG Enable Macro
#define SYSCFG_PCLK_EN()             (RCC->APB2ENR |= (__BIT_LEFT_SHIFT(14)))


//SPI Clock Enable Macros
#define SPI1_PCLK_EN()               (RCC->APB2ENR |= (__BIT_LEFT_SHIFT(12)))
#define SPI2_PCLK_EN()               (RCC->APB1ENR |= (__BIT_LEFT_SHIFT(14)))
#define SPI3_PCLK_EN()               (RCC->APB1ENR |= (__BIT_LEFT_SHIFT(15)))
#define SPI4_PCLK_EN()               (RCC->APB2ENR |= (__BIT_LEFT_SHIFT(16)))


//I2C Clock Enable Macros
#define I2C1_PCLK_EN()               (RCC->APB1ENR |= (__BIT_LEFT_SHIFT(21)))
#define I2C2_PCLK_EN()               (RCC->APB1ENR |= (__BIT_LEFT_SHIFT(22)))


//UART and USART Clock Enable Macros
#define USART1_PCLK_EN()             (RCC->APB2ENR |= (__BIT_LEFT_SHIFT(4)))
#define USART2_PCLK_EN()             (RCC->APB1ENR |= (__BIT_LEFT_SHIFT(17)))
#define USART6_PCLK_EN()             (RCC->APB2ENR |= (__BIT_LEFT_SHIFT(5)))




/*---------------------------------------This Section is for Clock Disable Macros-----------------------------------*/

//GPIO Clock Disable Macros
#define GPIOA_PCLK_DI()              (RCC->AHB1ENR &= ~__BIT_LEFT_SHIFT(0))
#define GPIOB_PCLK_DI()              (RCC->AHB1ENR &= ~__BIT_LEFT_SHIFT(1))
#define GPIOC_PCLK_DI()              (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()              (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()              (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOH_PCLK_DI()              (RCC->AHB1ENR &= ~(1 << 7))



//SPI Clock Disable Macros
#define SPI1_PCLK_DI()               (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()               (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()               (RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI()               (RCC->APB2ENR &= ~(1 << 13))

//SYSCFG Enable Macro
#define SYSCFG_PCLK_DI()             (RCC->APB2ENR &= ~(1 << 14))


//I2C Clock Disable Macros
#define I2C1_PCLK_DI()          (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()          (RCC->APB1ENR &= ~(1 << 22))


//UART and USART Clock Disable Macros
#define USART1_PCLK_DI()             (RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI()             (RCC->APB1ENR &= ~(1 << 17))
#define USART6_PCLK_DI()             (RCC->APB2ENR &= ~(1 << 5))



//IRQ(Interrupt Request) Number
#define IRQ_NO_EXTI0            6
#define IRQ_NO_EXTI1            7
#define IRQ_NO_EXTI2            8
#define IRQ_NO_EXTI3            9
#define IRQ_NO_EXTI4            10
#define IRQ_NO_EXTI9_5          23
#define IRQ_NO_EXTI15_10        40

//AFIO(Alternate Function Input Output) Definition
#define AFIO                    ((AFIO_RegDef_t*)AFIO_BASE_ADDR)

#define GPIO_BASE_ADDR_TO_CODE(x) ((x == GPIOA)? 0 :\
		                          (x == GPIOB) ? 1 :\
				                  (x == GPIOC) ? 2 :\
						          (x == GPIOD) ? 3 :\
						          (x == GPIOE) ? 4 :\
								  (x == GPIOE) ? 7 :0)

#include "stm32f411xx_gpio.h"

#endif /* STM32F411XX_H_ */
