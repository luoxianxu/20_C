
#include "Encorder.h"

void Timer_Encorder1(void)   //编码器模式只有通道一和二有
{
	TIM_TimeBaseInitTypeDef TIM_InitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_ICInitTypeDef TIM_ICInitStruct;
//	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_PeriphClockCmd_1(RCC_APB2Periph_A,ENABLE);
	RCC_PeriphClockCmd_2(RCC_APB1Periph_T2,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
	GPIO_Init(GPIO_A,&GPIO_InitStruct);
	
	TIM_TimeBaseStructInit(&TIM_InitStruct);
	TIM_InitStruct.TIM_Prescaler=Prescaler;
	TIM_InitStruct.TIM_Period=Period;
	TIM_InitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_InitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM_2,&TIM_InitStruct);
	
	
	
	TIM_EncoderInterfaceConfig(TIM_2,TIM_EncoderMode_TI12,TIM_ICPolarity_Falling,TIM_ICPolarity_Falling);
	TIM_ICStructInit(&TIM_ICInitStruct);
	TIM_ICInitStruct.TIM_ICFilter=0;
	TIM_ICInit(TIM_2,&TIM_ICInitStruct);
	
//	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//	NVIC_InitStruct.NVIC_IRQChannel=TIM2_IRQn;
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
//	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_Init(&NVIC_InitStruct);

	TIM2->CNT=1000;
	TIM_Cmd(TIM_2,ENABLE);
}

void Timer_Encorder2(void)     //GPIOA_Pin_6 & GPIOA_Pin_7
{
	TIM_TimeBaseInitTypeDef TIM_InitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_ICInitTypeDef TIM_ICInitStruct;
//	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_PeriphClockCmd_1(RCC_APB2Periph_A,ENABLE);
	RCC_PeriphClockCmd_2(RCC_APB1Periph_T3,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7;
	GPIO_Init(GPIO_A,&GPIO_InitStruct);
	
	TIM_TimeBaseStructInit(&TIM_InitStruct);
	TIM_InitStruct.TIM_Prescaler=Prescaler;
	TIM_InitStruct.TIM_Period=Period;
	TIM_InitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_InitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM_3,&TIM_InitStruct);

	TIM_EncoderInterfaceConfig(TIM_3,TIM_EncoderMode_TI12,TIM_ICPolarity_Falling,TIM_ICPolarity_Falling);
	
	TIM_ICStructInit(&TIM_ICInitStruct);
	TIM_ICInitStruct.TIM_ICFilter=0;
	TIM_ICInit(TIM_3,&TIM_ICInitStruct);
	
//	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//	NVIC_InitStruct.NVIC_IRQChannel=TIM3_IRQn;
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority=2;
//	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_Init(&NVIC_InitStruct);
	

	TIM3->CNT=1000;
	TIM_Cmd(TIM_3,ENABLE);
}

void timer_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);
	
	TIM_InitStruct.TIM_Prescaler=719;
	TIM_InitStruct.TIM_Period=9999;
	TIM_InitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_InitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM5,&TIM_InitStruct);
	
	TIM_ITConfig(TIM5,TIM_IT_Update,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStruct.NVIC_IRQChannel=TIM5_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=0;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;
    NVIC_Init(&NVIC_InitStruct);
	
	TIM_Cmd(TIM5,ENABLE);
}

