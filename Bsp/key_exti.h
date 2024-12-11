//...................................................................................
//key_exti.h
//...................................................................................

#ifndef __KEY_EXTI_H__
	#define __KEY_EXTI_H__
	
	//�ļ�����
	#include "stm32f10x.h"
	#include "key_exti.h"
/*==================================================================================
	KEY������ض���
*/


/*===================================================================================
	KEYӲ����ض���
*/
	//ʱ��
#define 	KEY0_GPIO_CLK_ENABLE()				RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE)
#define		KEY1_GPIO_CLK_ENABLE()				RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE)
#define		WK_UP_GPIO_CLK_ENABLE()				RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE)
#define		AFIO_CLK_ENABLE()					RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE)
		
/***************************************************************************************
		KEY�����ض���
*/
	//PORT
#define		KEY0_PORT			(GPIOE)
#define 	KEY1_PORT			(GPIOE)
#define 	WK_UP_PORT			(GPIOA)
	//Pin	
#define 	KEY0_GPIO_PIN		(GPIO_Pin_4)
#define 	KEY1_GPIO_PIN		(GPIO_Pin_3)
#define		WK_UP_GPIO_PIN		(GPIO_Pin_0)
	//GPIO��Ϊ����˿�����
#define 	KEY0_EXTI_PORT		GPIO_PortSourceGPIOE
#define		KEY1_EXTI_PORT		GPIO_PortSourceGPIOE	
#define		KEY0_EXTI_PIN		GPIO_PinSource4
#define		KEY1_EXTI_PIN		GPIO_PinSource3

#define	ReadKey0()		(GPIO_ReadInputDataBit(KEY0_PORT, KEY0_GPIO_PIN))
#define	ReadKey1()		(GPIO_ReadInputDataBit(KEY1_PORT, KEY0_GPIO_PIN))


/*****************�����������ԭ������****************************************************/
	void KEY_Init(void);
	void KEY_GPIO_Config(void);
	void KEY_Pcssoer(void);
	void EXTI_Config(void);
	void NVIC_Config(void);
	void GPIO_EXTI_LineConfig(void);
	void KEY_Process(void);
#endif

