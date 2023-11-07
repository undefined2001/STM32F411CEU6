/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Asraful Islam Taj
 * @brief          : Program to blink the built in LED at GPIO PORTC pin 13
 ******************************************************************************
 **/

#include <stdint.h>
#define AHB1_BASE_ADDR 0x40020000U
#define RCC_BASE_ADDR (AHB1_BASE_ADDR + 0x3800U)
#define GPIOC_BASE_ADDR (AHB1_BASE_ADDR + 0x0800U)
#define RCC_AHB1_ENR (RCC_BASE_ADDR + 0x30U)
#define __vo volatile

void delay(volatile uint32_t count)
{
    while (count)
    {
        count--;
    }
}

int main(void)
{
    __vo uint32_t *AHB1_ENR = (__vo uint32_t *)RCC_AHB1_ENR;
    __vo uint32_t *GPIOC = (__vo uint32_t *)GPIOC_BASE_ADDR;
    __vo uint32_t *GPIOC_BSRR = (__vo uint32_t *)(GPIOC_BASE_ADDR + 0x18);
    __vo uint32_t *GPIOC_OTYPER = (__vo uint32_t *)(GPIOC_BASE_ADDR + 0x04);

    (*AHB1_ENR) |= (1 << 2);
    (*GPIOC) |= (0x1 << 26);
    (*GPIOC_OTYPER) &= ~(1 << 13);

    while (1)
    {
        (*GPIOC_BSRR) |= (1 << (13 + 16));
        delay(1000000);
        (*GPIOC_BSRR) |= (1 << 13);
        delay(1000000);
    }
}
