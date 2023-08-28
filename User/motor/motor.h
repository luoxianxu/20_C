#ifndef _MOTOR_H
#define _MOTOR_H

#include "stm32f10x.h"

typedef struct motor
{
	float p;
	float i;
	float d;
	float motor_error;
	float motor_last_error;
	float motor_sum_error;
}Motor_PID;


void motor_config(void);
void Motor_Pid_Init(void);
float Motor_Pid_ATM(float speed,float target);
void Speed_Contorl(float speed,float target);
void Stop(void);

#endif/*_MOTOR_H*/
