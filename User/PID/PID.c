
#include "PID.h"
PID Pid;
void PID_Init(void)
{
	Pid.Pp=Pid_P;
	Pid.Pi=Pid_I;
	Pid.Pd=Pid_D;
	Pid.error=0;
	Pid.error_Cumula=0;
	Pid.error_last=0;
}

int temp1,temp2;
float PID_ATM(int temp1,int temp2)
{
	float Cal;
	Pid.error=temp1-temp2;
	Pid.error_Cumula+=Pid.error;
	Cal=Pid.Pp*Pid.error+Pid.Pi*Pid.error_Cumula+Pid.Pd*(Pid.error-Pid.error_last);
	Cal=Cal*Mul;
	Pid.error_last=Pid.error;
	return Cal;
}

