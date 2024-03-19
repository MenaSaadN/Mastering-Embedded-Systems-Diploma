/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
typedef volatile uint32_t vuint32_t;
/*************************************************************/
/*                         MACROS                            */
/*************************************************************/
#define GPIOA_BASE     0X40010800
#define RCC_BASE       0x40021000
#define GPIOA_ODR      *((volatile uint32_t *)(GPIOA_BASE + 0x0c))
#define GPIOA_CRH      *((volatile uint32_t *)(GPIOA_BASE + 0x04))
#define RCC_APB2ENR    *((volatile uint32_t *)(RCC_BASE + 0x18))
/*************************************************************/
/*                         INIT_PINS                         */
/*************************************************************/
typedef struct
{
   vuint32_t reserved:13;
   vuint32_t p_13:1;
}R_ODR_t;
volatile R_ODR_t* R_ODR =(volatile R_ODR_t*)(GPIOA_BASE + 0x0c);
/*************************************************************/
/*                         MAIN                              */
/*************************************************************/
int main(void)
{

	 int i;
	 RCC_APB2ENR  |= (1 << 2);
	 GPIOA_CRH    &= 0xff0fffff;
	 GPIOA_CRH    |= 0x00200000;
/*************************************************************/
/*                        toggling                           */
/*************************************************************/
     while(1)
     {

	 R_ODR->p_13 = 1;
	 for(i = 5000;i != 0;--i);
	 R_ODR->p_13 = 0;

	 for(i = 5000;i != 0;--i);



	 }
     return 0;
}
