/*
 *  Created on: Sep 6, 2023
 *  @file: stm32f411xx.h
 *  @brief: This is the MCU specific header file contain all the register info of the MCU
 *  @mcu: STM32F411CEU6
 *  @author: Asraful Islam Taj
 */

#ifndef STM32F411XX_H_
#define STM32F411XX_H_
#include<stdint.h>
#define __vo volatile


//Architecture Related Things

//Here goes NVIC Related Register

#define NO_PR_BITS_IMPLEMENTED        4

#define NVIC_PR_BASE_ADDR             (uint32_t*)0xE000E400

//ISER(Interrupt Set-Enable Register)
#define NVIC_ISER0                    (uint32_t*)0xE000E100
#define NVIC_ISER1                    (uint32_t*)0xE000E104
#define NVIC_ISER2                    (uint32_t*)0xE000E108
#define NVIC_ISER3                    (uint32_t*)0xE000E10C


//ICER(Interrupt Clear-Enable Register
#define NVIC_ICER0                    (uint32_t*)0XE000E180
#define NVIC_ICER1                    (uint32_t*)0XE000E184
#define NVIC_ICER2                    (uint32_t*)0XE000E188
#define NVIC_ICER3                    (uint32_t*)0XE000E18C



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


#define USART2_BASEADDR              (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR              (APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR               (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR               (APB1PERIPH_BASEADDR + 0x5000)





/*--------------------------------This Struct is For GPIO-----------------------------*/
typedef struct{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
}GPIO_RegDef_t;



/*--------------------------------This Struct is For RCC-----------------------------*/
typedef struct{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t RESERVED_ONE[2];
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t RESERVED_TWO[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t RESERVED_THREE[2];
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t RESERVED_FOUR[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t RESERVED_FIVE[2];
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t RESERVED_SIX[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t RESERVED_SEVEN[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t RESERVED_EIGHT;
	__vo uint32_t DCKCFGR;
}RCC_RegDef_t;



/*--------------------------------This Struct is For EXTI-----------------------------*/
typedef struct{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
}EXTI_RegDef_t;

/*--------------------------------This Struct is For SYSCFG-----------------------------*/
typedef struct{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	__vo uint32_t CMPCR;
}SYSCFG_RegDef_t;


/*--------------------------------This Struct is For SPI-----------------------------*/
typedef struct{
	__vo uint32_t CR1;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
	__vo uint32_t I2SCFGR;
	__vo uint32_t I2SPR;

}SPI_RegDef_t;


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

//RCC Peripherals Definition
#define RCC                          ((RCC_RegDef_t *)RCC_BASEADDR)

//EXTI(External Interrupt Controller)  Definition
#define SYSCFG                    	 ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

//EXTI(External Interrupt Controller)  Definition
#define EXTI                    	 ((EXTI_RegDef_t*)EXTI_BASEADDR)



/*---------------------------------------This Section is for Clock Enable Macros-----------------------------------*/

// GPIO Clock Enable Macros
#define GPIOA_PCLK_EN()              (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()              (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()              (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()              (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()              (RCC->AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN()              (RCC->AHB1ENR |= (1 << 7))

//SYSCFG Enable Macro
#define SYSCFG_PCLK_EN()             (RCC->APB2ENR |= (1 << 14))


//SPI Clock Enable Macros
#define SPI1_PCLK_EN()               (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()               (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()               (RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()               (RCC->APB2ENR |= (1 << 13))




/*---------------------------------------This Section is for Clock Disable Macros-----------------------------------*/

//GPIO Clock Disable Macros
#define GPIOA_PCLK_DI()              (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()              (RCC->AHB1ENR &= ~(1 << 1))
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
								  (x == GPIOE) ? 4 :0)


#endif /* STM32F411XX_H_ */
