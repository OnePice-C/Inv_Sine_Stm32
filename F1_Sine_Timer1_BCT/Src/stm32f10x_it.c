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

//uint16_t L4[450] = { 0, 22, 45, 67, 89, 112, 134, 156, 178, 200, 223, 245, 267,
//		289, 311, 332, 354, 376, 398, 419, 441, 462, 483, 505, 526, 547, 568,
//		589, 609, 630, 650, 671, 691, 711, 731, 751, 770, 790, 809, 828, 847,
//		866, 885, 903, 922, 940, 958, 976, 993, 1011, 1028, 1045, 1062, 1078,
//		1095, 1111, 1127, 1142, 1158, 1173, 1188, 1203, 1218, 1232, 1246, 1260,
//		1274, 1287, 1300, 1313, 1326, 1338, 1350, 1362, 1373, 1385, 1396, 1407,
//		1417, 1427, 1437, 1447, 1456, 1465, 1474, 1483, 1491, 1499, 1506, 1514,
//		1521, 1527, 1534, 1540, 1546, 1552, 1557, 1562, 1566, 1571, 1575, 1578,
//		1582, 1585, 1588, 1590, 1592, 1594, 1596, 1597, 1598, 1600, 1600, 1600,
//		1600, 1598, 1597, 1596, 1594, 1592, 1590, 1588, 1585, 1582, 1578, 1575,
//		1571, 1566, 1562, 1557, 1552, 1546, 1540, 1534, 1527, 1521, 1514, 1506,
//		1499, 1491, 1483, 1474, 1465, 1456, 1447, 1437, 1427, 1417, 1407, 1396,
//		1385, 1373, 1362, 1350, 1338, 1326, 1313, 1300, 1287, 1274, 1260, 1246,
//		1232, 1218, 1203, 1188, 1173, 1158, 1142, 1127, 1111, 1095, 1078, 1062,
//		1045, 1028, 1011, 993, 976, 958, 940, 922, 903, 885, 866, 847, 828, 809,
//		790, 770, 751, 731, 711, 691, 671, 650, 630, 609, 589, 568, 547, 526,
//		505, 483, 462, 441, 419, 398, 376, 354, 332, 311, 289, 267, 245, 223,
//		200, 178, 156, 134, 112, 89, 67, 45, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

uint16_t L4[396] = { 0, 19, 38, 57, 76, 95, 114, 133, 152, 171, 190, 208, 227,
		246, 264, 283, 301, 320, 338, 356, 374, 392, 410, 428, 446, 464, 481,
		498, 516, 533, 550, 567, 583, 600, 616, 633, 649, 665, 680, 696, 711,
		727, 742, 757, 771, 786, 800, 814, 828, 842, 855, 868, 882, 894, 907,
		919, 931, 943, 955, 966, 977, 988, 999, 1010, 1020, 1030, 1039, 1049,
		1058, 1067, 1075, 1084, 1092, 1099, 1107, 1114, 1121, 1128, 1134, 1140,
		1146, 1151, 1157, 1162, 1166, 1171, 1175, 1178, 1182, 1185, 1188, 1190,
		1193, 1195, 1196, 1198, 1199, 1199, 1200, 1200, 1200, 1199, 1199, 1198,
		1196, 1195, 1193, 1190, 1188, 1185, 1182, 1178, 1175, 1171, 1166, 1162,
		1157, 1151, 1146, 1140, 1134, 1128, 1121, 1114, 1107, 1099, 1092, 1084,
		1075, 1067, 1058, 1049, 1039, 1030, 1020, 1010, 999, 988, 977, 966, 955,
		943, 931, 919, 907, 894, 882, 868, 855, 842, 828, 814, 800, 786, 771,
		757, 742, 727, 711, 696, 680, 665, 649, 633, 616, 600, 583, 567, 550,
		533, 516, 498, 481, 464, 446, 428, 410, 392, 374, 356, 338, 320, 301,
		283, 264, 246, 227, 208, 190, 171, 152, 133, 114, 95, 76, 57, 38, 19, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0 };

extern uint16_t L3[396];
extern uint16_t L5[396];

extern int chonmang;
extern uint16_t Ext_ReadAdc_Max1;
extern uint16_t Arr1;
extern uint16_t Arr;

void TIM1_UP_IRQHandler(void) {

	if (TIM_GetITStatus( TIM1, TIM_IT_Update) != RESET) {

		++Arr;
		--Arr1;
		if (Arr == 300) {
			Ext_ReadAdc_Max1 = ADC_GetConversionValue(ADC1);

		}

		if (chonmang == 1) {
			TIM_SetCompare1(TIM1, L5[Arr]);
			TIM_SetCompare2(TIM1, L5[Arr1]);

		} else {
			TIM_SetCompare1(TIM1, L3[Arr]);
			TIM_SetCompare2(TIM1, L3[Arr1]);
		}
//		TIM_SetCompare2(TIM1,  L4[Arr] * Ext_K );
//		TIM_SetCompare1(TIM1,  L4[Arr1] * Ext_K );

		if (Arr == 396 && Arr1 == 0) { // sua bang sine, can phai -1 gia tri doi voi pp bam luong cuc
			Arr1 = 396;
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
