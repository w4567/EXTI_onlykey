//...................................................................................
//systick.c
//
//ʹ��ϵͳʱ�Ӷ�ʱ����ʱ1ms����Ϊʱ��
//...................................................................................

#include "systick.h"

//�������nTime�������ƺ���DelayXms����ʱʱ��
//nTime��SysTick���жϷ������б���һ
//nTime�붨���volatile��
vu32 nTime;

//ϵͳʱ�Ӷ�ʱ��SysTick��ʼ��
//����ϵͳʱ�Ӷ�ʱ��SysTick��ʱ1ms�����ж�
void SysTick_Init(void)
{
	SysTick_Config(SystemCoreClock / 1000);
	//SystemCoreClock: �ں˵�ʱ��Ƶ�ʣ�Hz��
	//SysTick�ļ���ʱ��Դ����Ϊ�ں�ʱ�ӣ�Ϊ72MHz
}

//�����ʱ����
//��ʱʱ�� = n�����룩
void DelayXms(u32 n)
{
	nTime = n;
	
	while(nTime != 0)
	{
		;
	}
}

