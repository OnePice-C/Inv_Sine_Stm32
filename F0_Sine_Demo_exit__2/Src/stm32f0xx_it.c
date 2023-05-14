/**
 ******************************************************************************
 * @file    Project/STM32F0xx_StdPeriph_Templates/stm32f0xx_it.c
 * @author  MCD Application Team
 * @version V1.6.0
 * @date    13-October-2021
 * @brief   Main Interrupt Service Routines.
 *          This file provides template for all exceptions handler and
 *          peripherals interrupt service routine.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2014 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_it.h"

/** @addtogroup STM32F0xx_StdPeriph_Templates
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M0 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
 * @brief  This function handles NMI exception.
 * @param  None
 * @retval None
 */
uint16_t lookUp1[434] = { 0, 16, 32, 48, 64, 80, 96, 111, 127, 143, 159, 175,
		190, 206, 222, 237, 253, 268, 284, 299, 314, 330, 345, 360, 375, 390,
		405, 419, 434, 449, 463, 478, 492, 506, 520, 534, 548, 562, 576, 589,
		603, 616, 629, 642, 655, 668, 680, 693, 705, 717, 729, 741, 753, 764,
		776, 787, 798, 809, 820, 830, 841, 851, 861, 871, 880, 890, 899, 908,
		917, 926, 934, 943, 951, 959, 966, 974, 981, 988, 995, 1002, 1009, 1015,
		1021, 1027, 1032, 1038, 1043, 1048, 1053, 1057, 1062, 1066, 1070, 1073,
		1077, 1080, 1083, 1086, 1088, 1091, 1093, 1095, 1096, 1098, 1099, 1100,
		1100, 1101, 1101, 1101, 1101, 1100, 1100, 1099, 1098, 1096, 1095, 1093,
		1091, 1088, 1086, 1083, 1080, 1077, 1073, 1070, 1066, 1062, 1057, 1053,
		1048, 1043, 1038, 1032, 1027, 1021, 1015, 1009, 1002, 995, 988, 981,
		974, 966, 959, 951, 943, 934, 926, 917, 908, 899, 890, 880, 871, 861,
		851, 841, 830, 820, 809, 798, 787, 776, 764, 753, 741, 729, 717, 705,
		693, 680, 668, 655, 642, 629, 616, 603, 589, 576, 562, 548, 534, 520,
		506, 492, 478, 463, 449, 434, 419, 405, 390, 375, 360, 345, 330, 314,
		299, 284, 268, 253, 237, 222, 206, 190, 175, 159, 143, 127, 111, 96, 80,
		64, 48, 32, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0 };

uint16_t lookUp2[434] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 16, 32, 48, 64, 80, 96, 111, 127, 143, 159, 175,
		190, 206, 222, 237, 253, 268, 284, 299, 314, 330, 345, 360, 375, 390,
		405, 419, 434, 449, 463, 478, 492, 506, 520, 534, 548, 562, 576, 589,
		603, 616, 629, 642, 655, 668, 680, 693, 705, 717, 729, 741, 753, 764,
		776, 787, 798, 809, 820, 830, 841, 851, 861, 871, 880, 890, 899, 908,
		917, 926, 934, 943, 951, 959, 966, 974, 981, 988, 995, 1002, 1009, 1015,
		1021, 1027, 1032, 1038, 1043, 1048, 1053, 1057, 1062, 1066, 1070, 1073,
		1077, 1080, 1083, 1086, 1088, 1091, 1093, 1095, 1096, 1098, 1099, 1100,
		1100, 1101, 1101, 1101, 1101, 1100, 1100, 1099, 1098, 1096, 1095, 1093,
		1091, 1088, 1086, 1083, 1080, 1077, 1073, 1070, 1066, 1062, 1057, 1053,
		1048, 1043, 1038, 1032, 1027, 1021, 1015, 1009, 1002, 995, 988, 981,
		974, 966, 959, 951, 943, 934, 926, 917, 908, 899, 890, 880, 871, 861,
		851, 841, 830, 820, 809, 798, 787, 776, 764, 753, 741, 729, 717, 705,
		693, 680, 668, 655, 642, 629, 616, 603, 589, 576, 562, 548, 534, 520,
		506, 492, 478, 463, 449, 434, 419, 405, 390, 375, 360, 345, 330, 314,
		299, 284, 268, 253, 237, 222, 206, 190, 175, 159, 143, 127, 111, 96, 80,
		64, 48, 32, 16 };

volatile uint16_t i = 0;
volatile int16_t Read_ADC_Pic = 0;
volatile float Ext_K = 0;

extern __IO int16_t RegularConvData_Tab[2];

void TIM1_BRK_UP_TRG_COM_IRQHandler(void) {
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET) //if update flag turns on
	{

		i++;
		if (i == 110) {
			Read_ADC_Pic = RegularConvData_Tab[1];
		}

		if (i > 434) {
			i = 0;
		}
		TIM_SetCompare2(TIM1, (lookUp1[i]) * Ext_K);
		TIM_SetCompare1(TIM1, (lookUp2[i]) * Ext_K);


		TIM_ClearFlag(TIM1, TIM_FLAG_Update);
	}
}

void EXTI0_1_IRQHandler(void) {

	if (EXTI_GetITStatus(EXTI_Line0) != RESET) {

		EXTI_ClearITPendingBit(EXTI_Line0);

		if ((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)) == 0) {

			GPIOA->BSRR |= (1 << 15);

			NVIC_DisableIRQ(TIM1_BRK_UP_TRG_COM_IRQn);
//			TIM_SetCompare1(TIM1, 0);
//			TIM_SetCompare2(TIM1, 0);
			TIM_CtrlPWMOutputs(TIM1, DISABLE);

		}

	}

}

void NMI_Handler(void) {
}

/**
 * @brief  This function handles Hard Fault exception.
 * @param  None
 * @retval None
 */
void HardFault_Handler(void) {
	/* Go to infinite loop when Hard Fault exception occurs */
	while (1) {
	}
}

/**
 * @brief  This function handles SVCall exception.
 * @param  None
 * @retval None
 */
void SVC_Handler(void) {
}

/**
 * @brief  This function handles PendSVC exception.
 * @param  None
 * @retval None
 */
void PendSV_Handler(void) {
}

/**
 * @brief  This function handles SysTick Handler.
 * @param  None
 * @retval None
 */
void SysTick_Handler(void) {
}

/******************************************************************************/
/*                 STM32F0xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f0xx.s).                                            */
/******************************************************************************/

/**
 * @brief  This function handles PPP interrupt request.
 * @param  None
 * @retval None
 */
/*void PPP_IRQHandler(void)
 {
 }*/

/**
 * @}
 */

