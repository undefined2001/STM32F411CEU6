/*
/*
 * @file stm32f411xx_nvic.c
 * @author: Asraful Islam Taj
 * @param: This Source file is to Use all the NVIC Related Task
 * Created on: 27 Oct 2023
 */


#include "stm32f411xx_nvic.h"

//This Function is Used to Enable an Interrupt Inside The NVIC
void NVIC_EnableIRQ(IRQn_Type IRQn)
{
    if (((uint32_t)IRQn) >= 0)
    {
        NVIC->ISER[(__RIGHT_SHIFT(((uint32_t)IRQn), 5U))] |= (uint32_t)__BIT_LEFT_SHIFT((((uint32_t)IRQn) & 0x1F));
    }
}

//This Function is Used to Disable an Interrupt Inside the NVIC
void NVIC_DisableIRQ(IRQn_Type IRQn)
{
	if(((uint32_t)IRQn) >= 0)
	{
		NVIC->ICER[(__RIGHT_SHIFT(((uint32_t)IRQn), 5U))] |= (uint32_t)__BIT_LEFT_SHIFT((((uint32_t)IRQn) & 0x1F));
	}
}

//This Function is Used to Set a priority to Pending State
void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
	if(((uint32_t)IRQn) >= 0)
	{
		NVIC->ISPR[(__RIGHT_SHIFT(((uint32_t)IRQn), 5U))] |= (uint32_t)__BIT_LEFT_SHIFT((((uint32_t)IRQn)&0x1F));
	}
}
//This Function is To Check The pending State of an Interrupt
uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
	uint8_t INDEX = (__RIGHT_SHIFT(((uint32_t)IRQn), 5U));
	uint8_t BIT_POSITION = (((uint32_t)IRQn)&0x1F);
	return (__RIGHT_SHIFT((NVIC->ISPR[INDEX]), BIT_POSITION) & 0x1);
}

//This Function is Used to Clear the Pending State of an Interrupt
void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
    if (((uint32_t)IRQn) >= 0)
    {
        NVIC->ISPR[(__RIGHT_SHIFT(((uint32_t)IRQn), 5U))] |= (uint32_t)__BIT_LEFT_SHIFT((((uint32_t)IRQn) & 0x1F));
    }
}



//This Function is Used to Set Priority of an Interrupt Inside The NVIC
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
    if ((((uint32_t)IRQn) >= 0) && (priority < 16))
    {
        NVIC->IPR[((uint32_t)IRQn)] = (uint32_t)__LEFT_SHIFT(priority, 4U);
    }
}

//This Function is Used to Get the Priority of an Interrupt Inside The NVIC
uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{
	return (uint32_t) (__RIGHT_SHIFT(((uint8_t)NVIC->IPR[IRQn]), 4U) & 0x0F);
}
