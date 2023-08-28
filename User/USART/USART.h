#ifndef _USART_H
#define _USART_H

#include "stm32f10x.h"

#define USART_x     USART1

void USART_Config(void);
void USART_Send(USART_TypeDef* p,uint8_t date);//发送一个字节
void USART_SendHalfword(USART_TypeDef* p,uint16_t date);//发送两个字节
void USART_SendArray(USART_TypeDef* p,uint8_t *array,uint8_t num);//发送一个8位的数组
void USART_SendStr(USART_TypeDef* p,uint8_t *str);//发送一个字符串
#endif

