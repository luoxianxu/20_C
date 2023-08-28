

#include "Timer_Pwm.h"

void Pwm_Config(void)
{
	TIM_TimeBaseInitTypeDef Time_InitStruct;
	TIM_OCInitTypeDef TIM_OCInitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	//初始化GPIO口
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
	//定时器配置
	Time_InitStruct.TIM_Prescaler=7199;
	Time_InitStruct.TIM_Period=199;
	Time_InitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	Time_InitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4,&Time_InitStruct);
	
	//PWM波配置
	TIM_OCInitStruct.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;
	
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC4Init(TIM4,&TIM_OCInitStruct);
	
	TIM_Cmd(TIM4,ENABLE);
}

