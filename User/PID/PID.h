
#ifndef _PID_H
#define _PID_H

#include "stm32f10x.h"


typedef struct 
{
	float Pp;
	float Pi;
	float Pd;
	float error;
	float error_last;
	float error_Cumula;
}PID;



#define Pid_P  250                 //90
#define Pid_I  0
#define Pid_D  180				   //125
#define Mul    0.001


void PID_Init(void);

float PID_ATM(int temp1,int temp2);


#endif /* PID_H */
