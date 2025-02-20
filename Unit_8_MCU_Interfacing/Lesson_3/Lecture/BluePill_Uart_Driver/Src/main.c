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

//<<<<<<<<Include>>>>>>>>
#include "Stm32f103c6_GPIO_Driver.h"
#include "Stm32f103c6_RCC_Driver.h"
#include "Stm32f103c6_Uart_Driver.h"
#include "LCD.h"

unsigned short int ch;

//========InterruptCallBack
void Uart_CallBack(void)
{
	MCAL_UART_ReceiveData(UART1, &ch, Disable);
	MCAL_UART_SendData(UART1, &ch, Enable);
}

//========GPIO_Init
void Clock_Init()
{
	//=====Enable GPIO Clocks
	E_GPIOA_CLK_EN();
	E_GPIOB_CLK_EN();

	//======Enable AFIO Clock
	E_AFIO_CLK_EN();

	//=====Enable UART Clocks
	RCC_UART1_CLK_EN();
	RCC_UART2_CLK_EN();
	RCC_UART3_CLK_EN();
}

int main(void)
{
	UART_Config Pin;

	//=====Init Function
	Clock_Init();

	//Config UART
	Pin.UART_BaudRate = UART_BaudRate_115200;
	Pin.HwFlowCTRL = UART_HwFlowCtl_None;
	Pin.IRQ_Enable = UART_IRQ_Enable_RXNEIE;
	Pin.P_IRQ_CallBack = Uart_CallBack;
	Pin.Parity = UART_Parity_NONE;
	Pin.Pay_Load_Length = UART_Pay_Load_Length_8bit;
	Pin.Stop_Bits = UART_Stop_Bit1;
	Pin.UART_Mode = UART_Mode_RX_TX;

	MCAL_UART_Init(UART1, &Pin);
	MCAL_UART_GPIO_Set_Pins(UART1);

	//Infinite Loop
    while (1);

	return 0;

}
