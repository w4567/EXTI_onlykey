//...................................................................................
//led.c
//...................................................................................

#include "led.h"
#include "key_exti.h"
/**led_gpio_Init
  * @brief  led_gpio初始化
  *         
  * @param  none
  *   
  * @retval none
  *         
  */
void LED_Init(void)
{
	LED_GPIO_Config();
	LED0_OFF_Bit();
	LED1_OFF_Bit();
}

/**
  * @brief  LED_GPIO配置
  *         
  * @param  none
  *   
  * @retval none
  *         
  *noet	外设操作函数定义

  */
void LED_GPIO_Config(void)
{
	LED0_GPIO_CLK_ENABLE();
	LED1_GPIO_CLK_ENABLE();
	
	GPIO_InitTypeDef GPIO_InitStructB = {
		.GPIO_Pin = LED0_GPIO_PIN,
		.GPIO_Mode = GPIO_Mode_Out_PP,
		.GPIO_Speed = GPIO_Speed_2MHz,
	};
	GPIO_Init(GPIOB,&GPIO_InitStructB);
	
	GPIO_InitTypeDef GPIO_InitStructE = {
		.GPIO_Pin = LED1_GPIO_PIN,
		.GPIO_Mode = GPIO_Mode_Out_PP,
		.GPIO_Speed = GPIO_Speed_2MHz,
	};
	GPIO_Init(GPIOE,&GPIO_InitStructE);
}

/**
  * @brief  LED_GPIO处理函数
  *         
  * @param  none
  *   
  * @retval none
  *         
  *
  */
