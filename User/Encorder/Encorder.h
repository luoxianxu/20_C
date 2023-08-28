#ifndef _ENCORDER_H
#define _ENCORDER_H

#include "stm32f10x.h"
#include "core_cm3.h"

#define  RCC_PeriphClockCmd_1		RCC_APB2PeriphClockCmd
#define  RCC_PeriphClockCmd_2		RCC_APB1PeriphClockCmd
#define  RCC_APB2Periph_A			RCC_APB2Periph_GPIOA
#define  RCC_APB2Periph_B			RCC_APB2Periph_GPIOB
#define  RCC_APB1Periph_T2			RCC_APB1Periph_TIM2
#define  RCC_APB1Periph_T3			RCC_APB1Periph_TIM3

#define  GPIO_A						GPIOA
#define  GPIO_B						GPIOB

#define  Prescaler					0
#define  Period						4999

#define  TIM_2						TIM2
#define	 TIM_3						TIM3

void Timer_Encorder1(void);
void Timer_Encorder2(void);
void timer_Init(void);
void Get_value(void);

#endif/*_ENCORDER_H*/
