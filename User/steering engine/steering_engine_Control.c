
#include "steering_engine_Control.h"

//uint16_t left,rigth;

//extern uint16_t value_left,value_rigth;


uint8_t flag=0;
uint8_t i;
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

//void GInit(void)
//{
//	GPIO_InitTypeDef GPIO_InitStruct;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
//	
//	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
//	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_5;
//	GPIO_Init(GPIOB,&GPIO_InitStruct);
//}

//void PID_Init(void)
//{
//	Pid.P=220;
//	Pid.I=0;
//	Pid.D=1900;
//	Pid.error=0;
//	Pid.last_error=0;
//	Pid.sum_error=0;
//}

//int16_t PID_ATM(uint16_t rigth,uint16_t left)
//{
//	int16_t SUM;
//	if(rigth>=450)
//		rigth=450+(rigth-450)/35;
//	if(left>=450)
//		left=450+(left-450)/35;
//	Pid.error=rigth-left;
//	if(Pid.error>=163)
//		Pid.error=163;
//	if(Pid.error<=-163)
//		Pid.error=-163;
//	Pid.sum_error+=Pid.last_error;
//	SUM=Pid.P*Pid.error+Pid.I*Pid.sum_error+Pid.D*(Pid.error-Pid.last_error);
//	Pid.last_error=Pid.error;
//	SUM=0.0005*SUM;
//	return SUM;
//}

//void SEC_Control(void)
//{
//	int16_t deviation;
//	Get_ADC_Value();
//	deviation=PID_ATM(value_rigth,value_left);
//	deviation=15+deviation;
//	if(deviation>=25)
//		deviation=25;
//	if(deviation<=5)
//		deviation=5;
//	if((GPIOB->IDR & GPIO_Pin_5)!=0)
//		deviation=25;
//	if((GPIOB->IDR & GPIO_Pin_4)!=0)
//		deviation=5;
//	TIM_SetCompare4(TIM4,deviation);
//}

void GInit(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_Init(GPIOD,&GPIO_InitStruct);
	
//	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
//	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_10;
//	GPIO_Init(GPIOC,&GPIO_InitStruct);
}
void SEC_Control(void)
{
	if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_3)==Bit_SET)
	{
		flag=1;
	}

	if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_4)==Bit_SET)
	{
		flag=2;
	}

	if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_5)==Bit_SET)
	{
		flag=3;
	}
		
	if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_6)==Bit_SET)
	{
		flag=4;
	}

	if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_7)==Bit_SET)
	{
		flag=5;
	}

}
void Turn(uint8_t i)
{
	switch(i)
	{
		case 1:
			TIM_SetCompare4(TIM4,5);
		break;
		case 2:
			TIM_SetCompare4(TIM4,10);
		break;
		case 3:
			TIM_SetCompare4(TIM4,15);
		break;
		case 4:
			TIM_SetCompare4(TIM4,20);
		break;
		case 5:
			TIM_SetCompare4(TIM4,25);
		break;
		default:
			break;
	}
}

