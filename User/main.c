
#include "stm32f10x.h"
//#include "ADC_Config.h"
#include "motor.h"
#include "steering_engine_Control.h"
//#include "USART.h"
#include "Encorder.h"
extern uint8_t flag;
//���ö�ʱ�� һ�������  ������������  �ģ������  ������������ �壨��ʱ��ȡ��

int main(void)
{
//	USART_Config();
	GInit();
//	PID_Init();			 //���PID������ʼ��
	Motor_Pid_Init();	 //���PID������ʼ��
//	ADC_config();		 //ADC����
	Pwm_Config();		 //���PWM������
	motor_config();      //���PWM������
	Timer_Encorder1();   //������1
	Timer_Encorder2();	 //������2
	timer_Init();		 //��ʱ����ʱ��ȡ����������
	while(1)
	{
		SEC_Control();
		Turn(flag);
//		Stop();
	}
}

