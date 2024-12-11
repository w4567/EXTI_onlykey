//...................................................................................
//led.h
//...................................................................................

#ifndef __LED_H__
	#define __LED_H__
	
	//�ļ�����
	#include "stm32f10x.h"
	#include "led.h"
	
/*==================================================================================
	LED_GPIO������ض���
*/


/*===================================================================================
	LED_GPIOӲ����ض���
*/
	//ʱ��
#define		LED0_GPIO_CLK_ENABLE()			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE)
#define		LED1_GPIO_CLK_ENABLE()			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE)		
	
/***************************************************************************************
		LED_GPIO�����ض���
*/
	//Pin
#define		LED0_GPIO_PIN			(GPIO_Pin_5)
#define		LED1_GPIO_PIN			(GPIO_Pin_5)
	//PORT	
#define		LED0_PORT				(GPIOB)
#define 	LED1_PORT				(GPIOE)

/*****************�����������ԭ������****************************************************/

#define		LED0_ON_Bit()		GPIO_ResetBits(LED0_PORT,LED0_GPIO_PIN)
#define		LED0_OFF_Bit()		GPIO_SetBits(LED0_PORT,LED0_GPIO_PIN)

#define		LED1_ON_Bit()		GPIO_ResetBits(LED1_PORT,LED1_GPIO_PIN)
#define		LED1_OFF_Bit()		GPIO_SetBits(LED1_PORT,LED1_GPIO_PIN)
#define	LED0_TOGGLE()	(GPIO_WriteBit(LED0_PORT, LED0_GPIO_PIN, (BitAction)(1 - GPIO_ReadOutputDataBit(LED0_PORT, LED0_GPIO_PIN))))
#define	LED1_TOGGLE()	(GPIO_WriteBit(LED1_PORT, LED0_GPIO_PIN, (BitAction)(1 - GPIO_ReadOutputDataBit(LED1_PORT, LED0_GPIO_PIN))))


void LED_Init(void);
void LED_GPIO_Config(void);
void LED_GPIO (void);

#endif

