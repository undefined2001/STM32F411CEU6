/*
 * @file util.h
 * Created on: Sep 11, 2023
 * Author: mdasr
 * @param: This File contains all the utility function's declarations
 */

#ifndef UTIL_H_
#define UTIL_H_

#include "stm32f411xx.h"

#define SYSTICX_LOAD_VALUE     ((uint32_t)SYSCLK_FREQ / 1000)

void Delay_ms(uint16_t ms);


#endif /* UTIL_H_ */
