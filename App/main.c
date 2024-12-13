//...............................................................
//main.c
//...............................................................

#include "main.h"
#include "led.h"
#include "key_exti.h"
#include "stm32f10x_it.h"
#include "app_rtt_log.h"
#include "stm32f10x_conf.h"
/* Includes ------------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
uint8_t NVIC_Priority_cont_err = 0;
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	/*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f10x_xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f10x.c file
    */     
	
	//初始化SysTick定时器
	SysTick_Init();
	
	
	//中断优先级分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	if((NVIC_Priority_cont_err++) > 0) {
		
		assert_failed(__FILE__,__LINE__);
	}
	
	KEY_Init();
	
    LED_Init();
	
	
	
	
	APP_LOG_Printf("exti star");
	while (1)
	{
		;
	}
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
	assert_failed(__FILE__,__LINE__);
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	APP_LOG_Printf("Wrong parameters value: file %s on line %d\r\n", file, line);
  /* Infinite loop */
  while (1)
  {
  }
}

#endif

/************************END OF FILE***********************************/
