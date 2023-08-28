
#ifndef _STEERING_ENGINE_CONTROL_H
#define _STEERING_ENGINE_CONTROL_H

#include "stm32f10x.h"

typedef struct engine
{
	int P;
	int I;
	int D;
	int16_t error;
	int16_t last_error;
	int16_t sum_error;
}PID;

void Pwm_Config(void);
void GInit(void);
void SEC_Control(void);
void Turn(uint8_t i);

//void PID_Init(void);
//int16_t PID_ATM(uint16_t left,uint16_t rigth);






#endif/*_STEERING_ENGINE_CONTROL_H*/
