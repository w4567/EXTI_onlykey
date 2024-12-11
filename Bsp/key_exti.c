//...................................................................................
//key_exti.c
//...................................................................................

#include "key_exti.h"
#include "led.h"
#include "misc.h"
#include "SysTick.h"
/**KEY_Init
  * @brief  KEY_EXTI��ʼ��
  *         
  * @param  none
  *   
  * @retval none
  *         
  */
void KEY_Init(void)
{
	KEY_GPIO_Config();
	NVIC_Config();
	EXTI_Config();
	GPIO_EXTI_LineConfig();
	
}
/**
  * @brief  KEY_EXTI����
  *         
  * @param  none
  *   
  * @retval none
  *         
  *noet	���������������
  */
void KEY_GPIO_Config(void)
{
	KEY0_GPIO_CLK_ENABLE();
	KEY1_GPIO_CLK_ENABLE();
	WK_UP_GPIO_CLK_ENABLE();
	AFIO_CLK_ENABLE();

	//KEY0
	GPIO_InitTypeDef GPIO_Initstructure = {
		.GPIO_Pin = KEY0_GPIO_PIN,
		.GPIO_Mode = GPIO_Mode_IPU,
	};
	GPIO_Init(KEY0_PORT,&GPIO_Initstructure);
	//KEY1
	GPIO_InitTypeDef GPIOE_Initstructure= {
		.GPIO_Pin = KEY1_GPIO_PIN,
		.GPIO_Mode = GPIO_Mode_IPU,
	};
	GPIO_Init(KEY1_PORT,&GPIOE_Initstructure);
	//WK_UP
	GPIO_InitTypeDef GPIOA_Initstructure = {
		.GPIO_Pin = WK_UP_GPIO_PIN,
		.GPIO_Mode = GPIO_Mode_IPD,
	};
	GPIO_Init(WK_UP_PORT,&GPIOA_Initstructure);
}

void GPIO_EXTI_LineConfig(void)
{
	//KEY0:EXTI4
	GPIO_EXTILineConfig(KEY0_EXTI_PORT, KEY0_EXTI_PIN);
	//KEY1:EXTI3
	GPIO_EXTILineConfig(KEY1_EXTI_PORT, KEY1_EXTI_PIN);

}

void NVIC_Config(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1 ;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority =0; 
	NVIC_InitStruct.NVIC_IRQChannelCmd =ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2 ;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority =0; 
	NVIC_InitStruct.NVIC_IRQChannelCmd =ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}

void EXTI_Config(void)
{
	//EXTI_ClearITPendingBit(EXTI_Line4);
	EXTI_InitTypeDef EXTI_InitStruct;
	EXTI_InitStruct.EXTI_Line = EXTI_Line4;
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
	
	//EXTI_ClearITPendingBit(EXTI_Line3);
	EXTI_InitStruct.EXTI_Line = EXTI_Line3;
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
}


/**
  * @brief  KEY��������
  *         
  * @param  none
  *   
  * @retval none
  *         
  */