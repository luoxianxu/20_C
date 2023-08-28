
#include "ADC_Config.h"

uint16_t value_left,value_rigth;

void ADC_config(void)
{
	ADC_InitTypeDef ADC_InitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2|RCC_APB2Periph_ADC1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AIN;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_5;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	ADC_DeInit(ADC1);
	ADC_DeInit(ADC2);
	
	ADC_InitStruct.ADC_Mode=ADC_Mode_Independent;
	ADC_InitStruct.ADC_DataAlign=ADC_DataAlign_Right;
	ADC_InitStruct.ADC_NbrOfChannel=1;
	ADC_InitStruct.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;
	ADC_InitStruct.ADC_ScanConvMode=DISABLE;
	ADC_InitStruct.ADC_ContinuousConvMode=ENABLE;
	ADC_Init(ADC1,&ADC_InitStruct);
	ADC_Init(ADC2,&ADC_InitStruct);
	
	ADC_RegularChannelConfig(ADC1,ADC_Channel_4,1,ADC_SampleTime_239Cycles5);
	ADC_RegularChannelConfig(ADC2,ADC_Channel_5,1,ADC_SampleTime_239Cycles5);
	
	ADC_Cmd(ADC1,ENABLE);
	ADC_Cmd(ADC2,ENABLE);
	
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));
	
	ADC_ResetCalibration(ADC2);
	while(ADC_GetResetCalibrationStatus(ADC2));
	ADC_StartCalibration(ADC2);
	while(ADC_GetCalibrationStatus(ADC2));

}

void Get_ADC_Value(void)
{
	ADC_RegularChannelConfig(ADC1,ADC_Channel_4,1,ADC_SampleTime_239Cycles5);
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));
	value_rigth=ADC_GetConversionValue(ADC1);
	
	ADC_RegularChannelConfig(ADC2,ADC_Channel_5,1,ADC_SampleTime_239Cycles5);
	ADC_SoftwareStartConvCmd(ADC2,ENABLE);
	while(!ADC_GetFlagStatus(ADC2,ADC_FLAG_EOC));
	value_left=ADC_GetConversionValue(ADC2);
}

