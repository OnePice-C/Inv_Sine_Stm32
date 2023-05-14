#include "stm32f10x.h"
#include "pid.h"

/*Khai bao bien*/
GPIO_InitTypeDef GPIO_InitStructure;
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef TIM_OCInitStructure;
TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
NVIC_InitTypeDef NVIC_InitStructure;
ADC_InitTypeDef ADC_InitStructure;

struct PID_DATA pidData;

void ADC_Configuration(void);
void TIM1_Configuraion(void);

extern uint16_t L4[396];
uint16_t L3[396];
uint16_t L5[396];

uint16_t Ext_ReadAdc_Max1 = 0;
uint16_t Arr1 = 396;
uint16_t Arr = 0;
int chonmang = 0;

float k = 0.3;

int Read_pid = 0;
float read_p1 = 0;

int main(void) {

	SystemInit();
	TIM1_Configuraion();
	ADC_Configuration();

	Init_PID(K_P * SCALING_FACTOR, K_I * SCALING_FACTOR, K_D * SCALING_FACTOR,
			&pidData);

	while (1) {

		if (Ext_ReadAdc_Max1 > 1900 && Ext_ReadAdc_Max1 < 2200) {
			k = k;

		} else {
			k += read_p1;
			if (k >= 0.950) {
				k = 0.950;
			} else if (k < 0.3) {
				k = 0.3;
			} else {
				if (chonmang == 1) {

					for (int g = 0; g < 396; g++) {
						L3[g] = (L4[g] * k);
					}
					chonmang = 0;
				} else {

					for (int g = 0; g < 396; g++) {
						L5[g] = (L4[g] * k);
					}
					chonmang = 1;
				}
//				Ext_K = k;

			}
		}

		Read_pid = PID(2048, Ext_ReadAdc_Max1, &pidData);

		if (Read_pid >= -2048 && Read_pid <= 2048) {
			read_p1 = ((float) Read_pid) / (float) 4096000;
		}
	}
}

void TIM1_Configuraion(void) {
	/*Cap clock*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

	/* Cau hinh channel */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* cau hinh timer base */
	TIM_TimeBaseStructure.TIM_Prescaler = 2;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 1200;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

	/* cho phep TIM1 hoat dong */
	TIM_Cmd(TIM1, ENABLE);

	/* config NVIC  */
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);

	/* cau hinh channel3 o mode PWM */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;     // nguoc
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;         // nguoc

	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;       // nguoc

	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);

	/* Tai truoc thanh ghi CCRx */
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
	/* tai truoc thanh ghi dem ARR(Preiod) */
	TIM_ARRPreloadConfig(TIM1, ENABLE);

	TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;
	TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;
	TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_OFF;
	TIM_BDTRInitStructure.TIM_DeadTime = 20;
	TIM_BDTRInitStructure.TIM_Break = TIM_Break_Disable;
	TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_Low;
	TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Disable;
	TIM_BDTRConfig(TIM1, &TIM_BDTRInitStructure);

	TIM_CtrlPWMOutputs(TIM1, ENABLE); // luu ý command này phai set, enabel bit 15-BDTR( enable OC va OCN)

	/* Config NVIC */

	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	TIM_SelectOCxM(TIM1, TIM_Channel_1, TIM_OCMode_PWM1);
	TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Enable);
	TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Enable);

}

void ADC_Configuration(void) {
	/*cap clock cho chan GPIO va bo ADC1*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	/*cau hinh chan Input cua bo ADC1 la chan PA0*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*cau hinh ADC1*/
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &ADC_InitStructure);

	/* Cau hinh chanel, rank, thoi gian lay mau */
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_55Cycles5);
	/* Cho phep bo ADC1 hoa dong */
	ADC_Cmd(ADC1, ENABLE);
	/* cho phep cam bien nhiet hoat dong */
	ADC_TempSensorVrefintCmd(ENABLE);
	/* Reset thanh ghi cablib  */
	ADC_ResetCalibration(ADC1);
	/* Cho thanh ghi cablib reset xong */
	while (ADC_GetResetCalibrationStatus(ADC1))
		;
	/* Khoi dong bo ADC */
	ADC_StartCalibration(ADC1);
	/* Cho trang thai cablib duoc bat */
	while (ADC_GetCalibrationStatus(ADC1))
		;
	/* Bat dau chuyen doi ADC */
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}
