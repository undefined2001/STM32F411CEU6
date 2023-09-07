/**
 ******************************************************************************
 * @file           : button_interrupt.c
 * @author         : Asraful Islam Taj
 * @brief          : This Program is For setting Interrupt on Builtin User Button
 ******************************************************************************
 **/
#include "stm32f411xx.h"

uint8_t Button_Pin = 0;
uint8_t Led_One_Pin = 13;


int main()
{

    GPIO_Handle_t Button;
    Button.GPIO = GPIOA;
    Button.GPIO_PinConfig.GPIO_Pin = Button_Pin;
    Button.GPIO_PinConfig.GPIO_Mode = GPIO_IT_FTSR;
    Button.GPIO_PinConfig.GPIO_PuPd = GPIO_PULL_UP;


    GPIO_Handle_t Led_One;
    Led_One.GPIO = GPIOC;
    Led_One.GPIO_PinConfig.GPIO_Pin = Led_One_Pin;
    Led_One.GPIO_PinConfig.GPIO_Mode = GPIO_OUTPUT;
    Led_One.GPIO_PinConfig.GPIO_Speed = GPIO_SPEED_HIGH;
    Led_One.GPIO_PinConfig.GPIO_OType = GPIO_OUT_PP;



    GPIO_Clock_Config(GPIOA, ENABLE);
    GPIO_Clock_Config(GPIOC, ENABLE);

    GPIO_Init(&Button);
    GPIO_Init(&Led_One);
//    Button.GPIO->ODR |=(1 << 0);


    GPIO_IRQ_Priority(IRQ_NO_EXTI0, 0);
    GPIO_IRQ_Config(IRQ_NO_EXTI0, ENABLE);

    while (1){
    	GPIO_Write_Pin(GPIOC, GPIO_Pin_13, GPIO_HIGH);
    }

    return 0;
}

void EXTI0_IRQHandler(void)
{
	GPIO_IRQ_Handling(Button_Pin);
    GPIO_Toggle_Pin(GPIOC, Led_One_Pin, 1000000);
}
