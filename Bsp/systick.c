//...................................................................................
//systick.c
//
//使用系统时钟定时器定时1ms，作为时基
//...................................................................................

#include "systick.h"

//定义变量nTime用来控制函数DelayXms的延时时间
//nTime在SysTick的中断服务函数中被减一
//nTime须定义成volatile的
vu32 nTime;

//系统时钟定时器SysTick初始化
//设置系统时钟定时器SysTick定时1ms，开中断
void SysTick_Init(void)
{
	SysTick_Config(SystemCoreClock / 1000);
	//SystemCoreClock: 内核的时钟频率（Hz）
	//SysTick的计数时钟源设置为内核时钟，为72MHz
}

//软件延时函数
//延时时间 = n（毫秒）
void DelayXms(u32 n)
{
	nTime = n;
	
	while(nTime != 0)
	{
		;
	}
}

