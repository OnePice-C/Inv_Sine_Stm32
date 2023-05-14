/**
 ******************************************************************************
 * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c
 * @author  MCD Application Team
 * @version V3.5.0
 * @date    08-April-2011
 * @brief   Main Interrupt Service Routines.
 *          This file provides template for all exceptions handler and
 *          peripherals interrupt service routine.
 ******************************************************************************
 * @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"

uint16_t L4[453] = {0,22, 45, 67, 89, 112, 134, 156, 178, 201, 223, 245, 267, 289, 311, 333, 354, 376, 398, 420, 441, 462, 484, 505, 526, 547, 568, 589, 610, 630, 651, 671, 691, 711, 731, 751, 771, 790, 810, 829, 848, 867, 885, 904, 922, 940, 958, 976, 994, 1011, 1028, 1045, 1062, 1079, 1095, 1111, 1127, 1143, 1159, 1174, 1189, 1204, 1218, 1233, 1247, 1261, 1274, 1288, 1301, 1314, 1326, 1339, 1351, 1363, 1374, 1386, 1397, 1407, 1418, 1428, 1438, 1448, 1457, 1466, 1475, 1483, 1492, 1500, 1507, 1515, 1522, 1528, 1535, 1541, 1547, 1552, 1558, 1563, 1567, 1572, 1576, 1579, 1583, 1586, 1589, 1591, 1593, 1595, 1597, 1598, 1599, 1600, 1600, 1600, 1600, 1599, 1598, 1597, 1595, 1593, 1591, 1589, 1586, 1583, 1579, 1576, 1572, 1567, 1563, 1558, 1552, 1547, 1541, 1535, 1528, 1522, 1515, 1507, 1500, 1492, 1483, 1475, 1466, 1457, 1448, 1438, 1428, 1418, 1407, 1397, 1386, 1374, 1363, 1351, 1339, 1326, 1314, 1301, 1288, 1274, 1261, 1247, 1233, 1218, 1204, 1189, 1174, 1159, 1143, 1127, 1111, 1095, 1079, 1062, 1045, 1028, 1011, 994, 976, 958, 940, 922, 904, 885, 867, 848, 829, 810, 790, 771, 751, 731, 711, 691, 671, 651, 630, 610, 589, 568, 547, 526, 505, 484, 462, 441, 420, 398, 376, 354, 333, 311, 289, 267, 245, 223, 201, 178,
		156, 134, 112, 89, 67, 45, 1200,800,22, 45, 67, 89, 112, 134, 156, 178, 201, 223, 245, 267, 289, 311, 333, 354, 376, 398, 420, 441, 462, 484, 505, 526, 547, 568, 589, 610, 630, 651, 671, 691, 711, 731, 751, 771, 790, 810, 829, 848, 867, 885, 904, 922, 940, 958, 976, 994, 1011, 1028, 1045, 1062, 1079, 1095, 1111, 1127, 1143, 1159, 1174, 1189, 1204, 1218, 1233, 1247, 1261, 1274, 1288, 1301, 1314, 1326, 1339, 1351, 1363, 1374, 1386, 1397, 1407, 1418, 1428, 1438, 1448, 1457, 1466, 1475, 1483, 1492, 1500, 1507, 1515, 1522, 1528, 1535, 1541, 1547, 1552, 1558, 1563, 1567, 1572, 1576, 1579, 1583, 1586, 1589, 1591, 1593, 1595, 1597, 1598, 1599, 1600, 1600, 1600, 1600, 1599, 1598, 1597, 1595, 1593, 1591, 1589, 1586, 1583, 1579, 1576, 1572, 1567, 1563, 1558, 1552, 1547, 1541, 1535, 1528, 1522, 1515, 1507, 1500, 1492, 1483, 1475, 1466, 1457, 1448, 1438, 1428, 1418, 1407, 1397, 1386, 1374, 1363, 1351, 1339, 1326, 1314, 1301, 1288, 1274, 1261, 1247, 1233, 1218, 1204, 1189, 1174, 1159, 1143, 1127, 1111, 1095, 1079, 1062, 1045, 1028, 1011, 994, 976, 958, 940, 922, 904, 885, 867, 848, 829, 810, 790, 771, 751, 731, 711, 691, 671, 651, 630, 610, 589, 568, 547, 526, 505, 484, 462, 441, 420, 398, 376, 354, 333, 311, 289, 267, 245, 223, 201,
		178, 156, 134, 112, 89, 67, 45, 22 ,1600};



uint16_t L3[453];
uint16_t L5[453];
extern int chonmang;
extern float ReadAdc_Max(void);
extern float k;

float Ext_ReadAdc_Max = 0;
uint16_t Arr = 0;

void TIM1_UP_IRQHandler(void) {

	if (TIM_GetITStatus( TIM1, TIM_IT_Update) != RESET) {

		++Arr;
		if(Arr == 150)
		{
			Ext_ReadAdc_Max = ReadAdc_Max();
		}
		if (Arr > 225) {
			if( chonmang == 1)
			{
				TIM_SetCompare1(TIM1, (1600 - L5[Arr]));
			}
			else
			{
				TIM_SetCompare1(TIM1, (1600 - L3[Arr]));
			}
			GPIOB->BRR |= (1 << 7);
			GPIOB->BRR |= (1 << 7);
			GPIOB->BRR |= (1 << 7);
			GPIOB->BRR |= (1 << 7);
			GPIOB->BSRR |= (1 << 6);

		}
		if (Arr < 226) {

			if( chonmang == 1)
			{
				TIM_SetCompare1(TIM1, (L5[Arr]));
			}
			else
			{
				TIM_SetCompare1(TIM1, (L3[Arr]));
			}
			GPIOB->BRR |= (1 << 6);
			GPIOB->BRR |= (1 << 6);
			GPIOB->BRR |= (1 << 6);
			GPIOB->BRR |= (1 << 6);
			GPIOB->BSRR |= (1 << 7);


		}

		if (Arr == 453) {
			Arr = 0;
		}
		TIM_ClearFlag(TIM1, TIM_FLAG_Update);
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
 * @brief  This function handles Memory Manage exception.
 * @param  None
 * @retval None
 */
void MemManage_Handler(void) {
	/* Go to infinite loop when Memory Manage exception occurs */
	while (1) {
	}
}

/**
 * @brief  This function handles Bus Fault exception.
 * @param  None
 * @retval None
 */
void BusFault_Handler(void) {
	/* Go to infinite loop when Bus Fault exception occurs */
	while (1) {
	}
}

/**
 * @brief  This function handles Usage Fault exception.
 * @param  None
 * @retval None
 */
void UsageFault_Handler(void) {
	/* Go to infinite loop when Usage Fault exception occurs */
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
 * @brief  This function handles Debug Monitor exception.
 * @param  None
 * @retval None
 */
void DebugMon_Handler(void) {
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
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
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

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
