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
#define C_CLK 16000000
#define PWMIntensity 5
#define LEDMINACTIVETIME 0.01
#define Fading_LOWTimer (1 / 1000) * C_CLK
#define TimerAfterFading (TimerByUser - 1)

u8 u8G_LEDSTATE = HIGH;
u8 PWM_State = HIGH;
u32 u8G_TimerValue2 = C_CLK * LEDMINACTIVETIME;
u32 u8G_Timer_value2 = 0;

u16 u8G_DimmingOnTime = 0;
u16 U8G_TotalDimmingTime = 100;
u16 u8G_DimmingOffTime = 1;

// Leds fading without flickering need 10 Milliseconds to act accordingly
// 10 milliseconds means 0.01 * 16000000
// To find segmented time we divide (Total time-1) / 0.01*C_CLK

void LED_TogglingON(void);
void LED_Dimming(void);
void LED_TogglingOFF(void);

void LED_Timer_Fire(u32 Timer_value);

int main(void)
{
	IntCrtl_Init();
	SysCtrl_MicrocontrollerInit();
	PORT_Init();
	GPT_Init();


	LED_Timer_Fire((TimerByUser * C_CLK)); // 16Mhz - > 1sec

	while (1)
	{
	}
	return 0;
}

void LED_TogglingON(void)
{
	GPIO_SetPinValue(PF2, LOW);
	u8G_LEDSTATE = LOW;
	GPT_Notification_T0(LED_TogglingOFF);

	//u8G_DimmingOffTime=1;
	//GPT_Notification_T0(LED_Dimming);

}

void LED_TogglingOFF(void)
{
	GPIO_SetPinValue(PF2, HIGH);
	u8G_LEDSTATE = HIGH;
	GPT_Notification_T0(LED_TogglingON);


}
void LED_Dimming(void)
{
	if (u8G_DimmingOffTime >= 90)
	{
		GPIO_SetPinValue(PF2, LOW);
		u8G_LEDSTATE = LOW;
		GPT_Notification_T0(LED_TogglingOFF);
		GPT_StartTimer(T0, TimerAfterFading * C_CLK);


	}
	else
	{
		u8G_DimmingOnTime = U8G_TotalDimmingTime - u8G_DimmingOffTime;
		u8G_Timer_value2 = (u8G_DimmingOnTime / 1000) * C_CLK;
		if (PWM_State == HIGH)
		{
			u8G_DimmingOffTime++;
			GPIO_SetPinValue(PF2, LOW);
			PWM_State = LOW;
		}
		else if (PWM_State == LOW)
		{
			GPIO_SetPinValue(PF2, HIGH);
			PWM_State = HIGH;
		}
	}
	GPT_Notification_T0(LED_Dimming);
	GPT_StartTimer(T0, u8G_Timer_value2);


}

void LED_Timer_Fire(u32 Timer_value)
{

	GPT_EnableNotification(T0);
	if (u8G_LEDSTATE == HIGH)
	{
		GPT_Notification_T0(LED_TogglingON);
		GPT_StartTimer(T0, Timer_value);
	}
	/* else if (u8G_LEDSTATE == LOW)
	{
		if (u8G_DimmingOffTime <= 90)
		{

			if (PWM_State == HIGH)
			{
				u8G_DimmingOnTime = U8G_TotalDimmingTime - u8G_DimmingOffTime;
				u8G_Timer_value2 = (u8G_DimmingOnTime / 1000) * C_CLK;
				GPT_Notification_T0(LED_Dimming);
				GPT_StartTimer(T0, u8G_Timer_value2);
			}
			else if (PWM_State == LOW)
			{
				u8G_Timer_value2 = Fading_LOWTimer;
				GPT_Notification_T0(LED_Dimming);
				GPT_StartTimer(T0, u8G_Timer_value2);
			}
		}
		else
		{
			GPT_Notification_T0(LED_TogglingOFF);
			GPT_StartTimer(T0, TimerAfterFading * C_CLK);
		}
	}*/
}

/**********************************************************************************************************************
 *  END OF FILE: Main.c
 *********************************************************************************************************************/