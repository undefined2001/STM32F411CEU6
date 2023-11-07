#include "stm32f411xe.h"

extern uint32_t __END_OF_TEXT;
extern uint32_t __START_FLASH_DATA;
extern uint32_t __START_SRAM_DATA;
extern uint32_t __END_SRAM_DATA;
extern uint32_t __START_BSS;
extern uint32_t __END_BSS;

#define SRAM_END (SRAM_BASE + (128U * 1024U))
/*
 *Because Usually Stack Section is Located at The End of the SRAM
 *Also the MSP(MAIN STACK POINTER) located at the start of the STACK
 */
#define STACK_START SRAM_END

//* Defining Main

void main(void);

//* Vector Table for STM32F411x

//* Defining all the Handlers
void Reset_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMonitor_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Systick_Handler(void) __attribute__((weak, alias("Default_Handler")));
void WWDG_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PVD_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_Handler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_Handler(void) __attribute__((weak, alias("Default_Handler")));
void FLASH_Handler(void) __attribute__((weak, alias("Default_Handler")));
void RCC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream3_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream4_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream5_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream6_Handler(void) __attribute__((weak, alias("Default_Handler")));
void ADC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM3_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM4_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SPI1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SPI2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void USART1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void USART2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_Handler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_Handler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_FS_WKUP_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream7_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SDIO_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM5_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SPI3_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream3_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream4_Handler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_FS_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream5_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream6_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream7_Handler(void) __attribute__((weak, alias("Default_Handler")));
void USART6_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_Handler(void) __attribute__((weak, alias("Default_Handler")));
void FPU_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SPI4_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SPI5_Handler(void) __attribute__((weak, alias("Default_Handler")));

uint32_t vector[] __attribute__((section(".vector"))) =
{
	STACK_START,
	(uint32_t)Reset_Handler,
	(uint32_t)NMI_Handler,
	(uint32_t)HardFault_Handler,
	(uint32_t)MemManage_Handler,
	(uint32_t)BusFault_Handler,
	(uint32_t)UsageFault_Handler,
	(uint32_t)0U,
	(uint32_t)0U,
	(uint32_t)0U,
	(uint32_t)0U,
	(uint32_t)SVCall_Handler,
	(uint32_t)DebugMonitor_Handler,
	(uint32_t)0U,
	(uint32_t)PendSV_Handler,
	(uint32_t)Systick_Handler,
	(uint32_t)WWDG_Handler,
	(uint32_t)PVD_Handler,
	(uint32_t)TAMP_STAMP_Handler,
	(uint32_t)RTC_WKUP_Handler,
	(uint32_t)FLASH_Handler,
	(uint32_t)EXTI0_Handler,
	(uint32_t)EXTI1_Handler,
	(uint32_t)EXTI2_Handler,
	(uint32_t)EXTI3_Handler,
	(uint32_t)EXTI4_Handler,
	(uint32_t)DMA1_Stream0_Handler,
	(uint32_t)DMA1_Stream1_Handler,
	(uint32_t)DMA1_Stream2_Handler,
	(uint32_t)DMA1_Stream3_Handler,
	(uint32_t)DMA1_Stream4_Handler,
	(uint32_t)DMA1_Stream5_Handler,
	(uint32_t)ADC_Handler,
	(uint32_t)EXTI9_5_Handler,
	(uint32_t)TIM1_BRK_TIM9_Handler,
	(uint32_t)TIM1_UP_TIM10_Handler,
	(uint32_t)TIM1_TRG_COM_TIM11_Handler,
	(uint32_t)TIM1_CC_Handler,
	(uint32_t)TIM2_Handler,
	(uint32_t)TIM3_Handler,
	(uint32_t)TIM4_Handler,
	(uint32_t)I2C1_EV_Handler,
	(uint32_t)I2C1_ER_Handler,
	(uint32_t)I2C2_EV_Handler,
	(uint32_t)I2C2_ER_Handler,
	(uint32_t)SPI1_Handler,
	(uint32_t)SPI2_Handler,
	(uint32_t)USART1_Handler,
	(uint32_t)USART2_Handler,
	(uint32_t)EXTI15_10_Handler,
	(uint32_t)RTC_Alarm_Handler,
	(uint32_t)OTG_FS_WKUP_Handler,
	(uint32_t)DMA1_Stream7_Handler,
	(uint32_t)SDIO_Handler,
	(uint32_t)TIM5_Handler,
	(uint32_t)SPI3_Handler,
	(uint32_t)DMA2_Stream0_Handler,
	(uint32_t)DMA2_Stream1_Handler,
	(uint32_t)DMA2_Stream2_Handler,
	(uint32_t)DMA2_Stream3_Handler,
	(uint32_t)DMA2_Stream4_Handler,
	(uint32_t)OTG_FS_Handler,
	(uint32_t)DMA2_Stream5_Handler,
	(uint32_t)DMA2_Stream6_Handler,
	(uint32_t)DMA2_Stream7_Handler,
	(uint32_t)USART6_Handler,
	(uint32_t)I2C3_EV_Handler,
	(uint32_t)I2C3_ER_Handler,
	(uint32_t)FPU_Handler,
	(uint32_t)SPI4_Handler,
	(uint32_t)SPI5_Handler,
};

void Reset_Handler(void)
{
	uint32_t size = (uint32_t)(&__END_SRAM_DATA) - (uint32_t)(&__START_SRAM_DATA);
	uint8_t *pSrc = (uint8_t*)&__START_FLASH_DATA;
	uint8_t *pDes = (uint8_t*)&__START_SRAM_DATA;

	for(int i = 0; i < size; i++)
	{
		*pDes++ = *pSrc++;
	}

	size = (uint32_t)&__START_BSS - (uint32_t)__END_BSS;\
	pDes = (uint8_t*)&__START_BSS;
	
	for(int i = 0; i < size; i++)
	{
		*pDes++ = 0;
	}

	main();
	
}

void Default_Handler(void)
{
	while (1)
		;
}