
#include "motor.h"

Motor_PID motor_Pid;

float speed,target;

//extern float Speed;
//extern float Speed_T2,Speed_T3;

float Target=66;

void motor_config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_BaseStruct;
	TIM_OCInitTypeDef OC_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_TIM1,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin=(GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11);
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	TIM_BaseStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_BaseStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_BaseStruct.TIM_Period=99;
	TIM_BaseStruct.TIM_Prescaler=71;
	TIM_TimeBaseInit(TIM1,&TIM_BaseStruct);
	
	OC_InitStruct.TIM_OCMode=TIM_OCMode_PWM1;
	OC_InitStruct.TIM_Pulse=0;
	OC_InitStruct.TIM_OutputState=TIM_OutputState_Enable;
	OC_InitStruct.TIM_OCPolarity=TIM_OCPolarity_High;
	
	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM1,TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Enable);
	
	TIM_OC1Init(TIM1,&OC_InitStruct);
	TIM_OC2Init(TIM1,&OC_InitStruct);
	TIM_OC3Init(TIM1,&OC_InitStruct);
	TIM_OC4Init(TIM1,&OC_InitStruct);
	
	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);
	TIM_Cmd(TIM1,ENABLE);
	
}

void Motor_Pid_Init(void)
{
	motor_Pid.p=10;  			 //10
	motor_Pid.i=2.4;  			//2.4
	motor_Pid.d=0.5;  			//0.5
	motor_Pid.motor_error=0;
	motor_Pid.motor_last_error=0;
	motor_Pid.motor_sum_error=0;
}

float Motor_Pid_ATM(float speed,float target)
{
	float MUL;
	motor_Pid.motor_error=target-speed;
	motor_Pid.motor_sum_error+=motor_Pid.motor_error;
	if(motor_Pid.motor_sum_error>=30000)
		motor_Pid.motor_sum_error=30000;
	MUL=motor_Pid.p*motor_Pid.motor_error+motor_Pid.i*motor_Pid.motor_sum_error+motor_Pid.d*(motor_Pid.motor_error-motor_Pid.motor_last_error);
	motor_Pid.motor_last_error=motor_Pid.motor_error;
	MUL=0.05*MUL;
	return MUL;
}

void Speed_Contorl(float speed,float target)
{	
	//此为前进
	TIM_SetCompare1(TIM1,15+Motor_Pid_ATM(speed,target));
	TIM_SetCompare2(TIM1,0);
	TIM_SetCompare3(TIM1,0);
	TIM_SetCompare4(TIM1,15+Motor_Pid_ATM(speed,target));
}

void Stop(void)
{
	if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_3)==Bit_SET && GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_4)==Bit_SET)
	{
		while(1)
		{
			TIM_SetCompare1(TIM1,0);
			TIM_SetCompare2(TIM1,0);
			TIM_SetCompare3(TIM1,0);
			TIM_SetCompare4(TIM1,0);
		}
	}
	if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_4)==Bit_SET && GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_5)==Bit_SET)
	{
		while(1)
		{
			TIM_SetCompare1(TIM1,0);
			TIM_SetCompare2(TIM1,0);
			TIM_SetCompare3(TIM1,0);
			TIM_SetCompare4(TIM1,0);
		}
	}
	if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_5)==Bit_SET && GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_6)==Bit_SET)
	{
		while(1)
			{
				TIM_SetCompare1(TIM1,0);
				TIM_SetCompare2(TIM1,0);
				TIM_SetCompare3(TIM1,0);
				TIM_SetCompare4(TIM1,0);
			}
	}
	if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_6)==Bit_SET && GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_7)==Bit_SET)
	{
		while(1)
		{
			TIM_SetCompare1(TIM1,0);
			TIM_SetCompare2(TIM1,0);
			TIM_SetCompare3(TIM1,0);
			TIM_SetCompare4(TIM1,0);
		}
	}
}

