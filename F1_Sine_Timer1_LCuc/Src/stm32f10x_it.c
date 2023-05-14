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

uint16_t L6[450] = { 1600, 1600, 1600, 1599, 1598, 1598, 1597, 1596, 1594, 1593,
		1591, 1590, 1588, 1586, 1584, 1581, 1579, 1576, 1573, 1571, 1567, 1564,
		1561, 1557, 1554, 1550, 1546, 1542, 1537, 1533, 1529, 1524, 1519, 1514,
		1509, 1504, 1498, 1493, 1487, 1481, 1475, 1469, 1463, 1457, 1450, 1444,
		1437, 1430, 1423, 1416, 1409, 1402, 1395, 1387, 1379, 1372, 1364, 1356,
		1348, 1339, 1331, 1323, 1314, 1306, 1297, 1288, 1279, 1270, 1261, 1252,
		1243, 1233, 1224, 1214, 1205, 1195, 1185, 1176, 1166, 1156, 1146, 1136,
		1125, 1115, 1105, 1094, 1084, 1074, 1063, 1053, 1042, 1031, 1021, 1010,
		999, 988, 977, 966, 955, 944, 933, 922, 911, 900, 889, 878, 867, 856,
		845, 834, 822, 811, 800, 789, 778, 766, 755, 744, 733, 722, 711, 700,
		689, 678, 667, 656, 645, 634, 623, 612, 601, 590, 579, 569, 558, 547,
		537, 526, 516, 506, 495, 485, 475, 464, 454, 444, 434, 424, 415, 405,
		395, 386, 376, 367, 357, 348, 339, 330, 321, 312, 303, 294, 286, 277,
		269, 261, 252, 244, 236, 228, 221, 213, 205, 198, 191, 184, 177, 170,
		163, 156, 150, 143, 137, 131, 125, 119, 113, 107, 102, 96, 91, 86, 81,
		76, 71, 67, 63, 58, 54, 50, 46, 43, 39, 36, 33, 29, 27, 24, 21, 19, 16,
		14, 12, 10, 9, 7, 6, 4, 3, 2, 2, 1, 0, 0, 0, 0, 0, 0, 1, 2, 2, 3, 4, 6,
		7, 9, 10, 12, 14, 16, 19, 21, 24, 27, 29, 33, 36, 39, 43, 46, 50, 54,
		58, 63, 67, 71, 76, 81, 86, 91, 96, 102, 107, 113, 119, 125, 131, 137,
		143, 150, 156, 163, 170, 177, 184, 191, 198, 205, 213, 221, 228, 236,
		244, 252, 261, 269, 277, 286, 294, 303, 312, 321, 330, 339, 348, 357,
		367, 376, 386, 395, 405, 415, 424, 434, 444, 454, 464, 475, 485, 495,
		506, 516, 526, 537, 547, 558, 569, 579, 590, 601, 612, 623, 634, 645,
		656, 667, 678, 689, 700, 711, 722, 733, 744, 755, 766, 778, 789, 800,
		811, 822, 834, 845, 856, 867, 878, 889, 900, 911, 922, 933, 944, 955,
		966, 977, 988, 999, 1010, 1021, 1031, 1042, 1053, 1063, 1074, 1084,
		1094, 1105, 1115, 1125, 1136, 1146, 1156, 1166, 1176, 1185, 1195, 1205,
		1214, 1224, 1233, 1243, 1252, 1261, 1270, 1279, 1288, 1297, 1306, 1314,
		1323, 1331, 1339, 1348, 1356, 1364, 1372, 1379, 1387, 1395, 1402, 1409,
		1416, 1423, 1430, 1437, 1444, 1450, 1457, 1463, 1469, 1475, 1481, 1487,
		1493, 1498, 1504, 1509, 1514, 1519, 1524, 1529, 1533, 1537, 1542, 1546,
		1550, 1554, 1557, 1561, 1564, 1567, 1571, 1573, 1576, 1579, 1581, 1584,
		1586, 1588, 1590, 1591, 1593, 1594, 1596, 1597, 1598, 1598, 1599, 1600,
		1600, 1600 };

uint16_t L4[450] = { 800, 811, 822, 834, 845, 856, 867, 878, 889, 900, 911, 922,
		933, 944, 955, 966, 977, 988, 999, 1010, 1021, 1031, 1042, 1053, 1063,
		1074, 1084, 1094, 1105, 1115, 1125, 1136, 1146, 1156, 1166, 1176, 1185,
		1195, 1205, 1214, 1224, 1233, 1243, 1252, 1261, 1270, 1279, 1288, 1297,
		1306, 1314, 1323, 1331, 1339, 1348, 1356, 1364, 1372, 1379, 1387, 1395,
		1402, 1409, 1416, 1423, 1430, 1437, 1444, 1450, 1457, 1463, 1469, 1475,
		1481, 1487, 1493, 1498, 1504, 1509, 1514, 1519, 1524, 1529, 1533, 1537,
		1542, 1546, 1550, 1554, 1557, 1561, 1564, 1567, 1571, 1573, 1576, 1579,
		1581, 1584, 1586, 1588, 1590, 1591, 1593, 1594, 1596, 1597, 1598, 1598,
		1599, 1600, 1600, 1600, 1600, 1600, 1600, 1599, 1598, 1598, 1597, 1596,
		1594, 1593, 1591, 1590, 1588, 1586, 1584, 1581, 1579, 1576, 1573, 1571,
		1567, 1564, 1561, 1557, 1554, 1550, 1546, 1542, 1537, 1533, 1529, 1524,
		1519, 1514, 1509, 1504, 1498, 1493, 1487, 1481, 1475, 1469, 1463, 1457,
		1450, 1444, 1437, 1430, 1423, 1416, 1409, 1402, 1395, 1387, 1379, 1372,
		1364, 1356, 1348, 1339, 1331, 1323, 1314, 1306, 1297, 1288, 1279, 1270,
		1261, 1252, 1243, 1233, 1224, 1214, 1205, 1195, 1185, 1176, 1166, 1156,
		1146, 1136, 1125, 1115, 1105, 1094, 1084, 1074, 1063, 1053, 1042, 1031,
		1021, 1010, 999, 988, 977, 966, 955, 944, 933, 922, 911, 900, 889, 878,
		867, 856, 845, 834, 822, 811, 800, 789, 778, 766, 755, 744, 733, 722,
		711, 700, 689, 678, 667, 656, 645, 634, 623, 612, 601, 590, 579, 569,
		558, 547, 537, 526, 516, 506, 495, 485, 475, 464, 454, 444, 434, 424,
		415, 405, 395, 386, 376, 367, 357, 348, 339, 330, 321, 312, 303, 294,
		286, 277, 269, 261, 252, 244, 236, 228, 221, 213, 205, 198, 191, 184,
		177, 170, 163, 156, 150, 143, 137, 131, 125, 119, 113, 107, 102, 96, 91,
		86, 81, 76, 71, 67, 63, 58, 54, 50, 46, 43, 39, 36, 33, 29, 27, 24, 21,
		19, 16, 14, 12, 10, 9, 7, 6, 4, 3, 2, 2, 1, 0, 0, 0, 0, 0, 0, 1, 2, 2,
		3, 4, 6, 7, 9, 10, 12, 14, 16, 19, 21, 24, 27, 29, 33, 36, 39, 43, 46,
		50, 54, 58, 63, 67, 71, 76, 81, 86, 91, 96, 102, 107, 113, 119, 125,
		131, 137, 143, 150, 156, 163, 170, 177, 184, 191, 198, 205, 213, 221,
		228, 236, 244, 252, 261, 269, 277, 286, 294, 303, 312, 321, 330, 339,
		348, 357, 367, 376, 386, 395, 405, 415, 424, 434, 444, 454, 464, 475,
		485, 495, 506, 516, 526, 537, 547, 558, 569, 579, 590, 601, 612, 623,
		634, 645, 656, 667, 678, 689, 700, 711, 722, 733, 744, 755, 766, 778,
		789 };
uint16_t L3[450];
uint16_t L5[450];

extern float ReadAdc_Max(void);
extern float k;
extern int chonmang;

float Ext_ReadAdc_Max = 0;

uint16_t Arr = 0;

void TIM1_UP_IRQHandler(void) {

	if (TIM_GetITStatus( TIM1, TIM_IT_Update) != RESET) {

		++Arr;
		if (Arr == 10) {
			Ext_ReadAdc_Max = ReadAdc_Max();
		}
		if (chonmang == 1) {
			TIM_SetCompare1(TIM1, L3[Arr]);
			TIM_SetCompare2(TIM1, L3[Arr]);
		} else {
			TIM_SetCompare1(TIM1, L5[Arr]);
			TIM_SetCompare2(TIM1, L5[Arr]);
		}

		if (Arr == 449) { // sua bang sine, can phai -1 gia tri doi voi pp bam luong cuc

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
