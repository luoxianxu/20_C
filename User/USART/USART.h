#ifndef _USART_H
#define _USART_H

#include "stm32f10x.h"

#define USART_x     USART1

void USART_Config(void);
void USART_Send(USART_TypeDef* p,uint8_t date);//����һ���ֽ�
void USART_SendHalfword(USART_TypeDef* p,uint16_t date);//���������ֽ�
void USART_SendArray(USART_TypeDef* p,uint8_t *array,uint8_t num);//����һ��8λ������
void USART_SendStr(USART_TypeDef* p,uint8_t *str);//����һ���ַ���
#endif

