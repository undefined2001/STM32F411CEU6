/*
 * @file util.c
 * Created on: Sep 11, 2023
 * Author: mdasr
 * @param: This File contains all the utility function's definition 
 */


#include "util.h"


void Delay_ms(uint16_t delay_ms)
{
	SYSTICK->RVR = SYSTICX_LOAD_VALUE;
	SYSTICK->CVR = 0;
	SYSTICK->CSR = (1 << 0) | (1 << 2);

	for( int i = 0; i < delay_ms; i++)
	{
		while((SYSTICK->CSR & (1 << 16)) == 0);
	}

	SYSTICK->CSR = 0;

}

int add(int a, int b)
{
	return a + b;
}
