#ifndef __APP_RTT_LOG_H__
	#define __APP_RTT_LOG_H__
	
#define APP_RTT_LOG_ENABLE		1
	
#if APP_RTT_LOG_ENABLE
	#include "SEGGER_RTT.h"
#endif

#if APP_RTT_LOG_ENABLE
#define APP_LOG_Printf(sFormat, ...)	SEGGER_RTT_printf(0,sFormat,##__VA_ARGS__);\
										SEGGER_RTT_printf(0,"\r\n");
#else 
#define APP_LOG_Printf(sFormat, ...)
#endif

#endif

