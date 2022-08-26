/**
 * @file Main.c
 * @author Mazen Ahmed Taha (MazenATaha@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "../COTS/02-LIB/Common/STD_TYPES.h"
#include "../COTS/01-MCAL/01-IntCtrl/INC/IntCtrl_Interface.h"
#include "../COTS/01-MCAL/06-SYSTICK/INC/SysCtrl_Interface.h"
#include "../COTS/01-MCAL/03-GPIO/INC/GPIO_interface.h"
#include "../COTS/01-MCAL/07-GPT/INC/GPT_Interface.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/
#define TimerByUser 3 // Insert Timer in seconds format
u8 u8G_LEDSTATE = 0;

void LED_Toggling(void);
void LED_Dimming(void);

void LED_Timer_Fire(u32 Timer_value);

int main(void)
{	
	IntCrtl_Init();
	SysCtrl_MicrocontrollerInit();
	PORT_Init();
	GPT_Init();

	while (1)
	{
		LED_Timer_Fire((TimerByUser*16000000)); // 16Mhz - > 1sec
	}
	return 0;
}

void LED_Toggling(void)
{
	u8G_LEDSTATE = 1;
	GPIO_SetPinValue(PF2,HIGH);
}

void LED_Dimming(void)
{
	
	GPIO_SetPinValue(PF2,HIGH);

	//Implementation of Dimmin Sequence To use timer as PWM  still in progress
	if(	u8G_LEDSTATE == 1){
		u8G_LEDSTATE = 0;
	}
}

void LED_Timer_Fire(u32 Timer_value)
{
	GPT_EnableNotification(T0);
	GPIO_TogglePinValue(PF3);
	if(u8G_LEDSTATE == 0)
	{
	GPT_Notification_T0(LED_Toggling);
	GPT_StartTimer(T0, Timer_value);
	}
	else if(u8G_LEDSTATE == 1) {
	GPT_Notification_T0(LED_Dimming);
	GPT_StartTimer(T0, Timer_value);
	}
	
}

/**********************************************************************************************************************
 *  END OF FILE: Main.c
 *********************************************************************************************************************/
