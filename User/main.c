
#include "stm32f10x.h"
//#include "ADC_Config.h"
#include "motor.h"
#include "steering_engine_Control.h"
//#include "USART.h"
#include "Encorder.h"
extern uint8_t flag;
//已用定时器 一（电机）  二（编码器）  四（舵机）  三（编码器） 五（定时读取）

int main(void)
{
//	USART_Config();
	GInit();
//	PID_Init();			 //舵机PID参数初始化
	Motor_Pid_Init();	 //电机PID参数初始化
//	ADC_config();		 //ADC配置
	Pwm_Config();		 //舵机PWM波配置
	motor_config();      //电机PWM波配置
	Timer_Encorder1();   //编码器1
	Timer_Encorder2();	 //编码器2
	timer_Init();		 //定时器定时读取编码器脉冲
	while(1)
	{
		SEC_Control();
		Turn(flag);
//		Stop();
	}
}

