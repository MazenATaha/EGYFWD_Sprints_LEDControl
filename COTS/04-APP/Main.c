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
#include "../COTS/01-MCAL/03-GPIO/INC/GPIO_interface.h"
#include "../COTS/01-MCAL/07-GPT/INC/GPT_Interface.h"
#include "../COTS/01-MCAL/01-IntCtrl/INC/IntCtrl_Interface.h"




/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define TimerByUser   1                        //Insert Timer in seconds format

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/





void LED_Toggling(void);
void LED_Timer_Fire(u32 Timer_value );




/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
int main(void){
	IntCrtl_Init();
  	SysCtrl_MicrocontrollerInit();
	PORT_Init();
	GPT_Init();

while(1)
	{   
		LED_Timer_Fire ((TimerByUser*16000000));//16Mhz - > 1sec
	}
	return 0;


}


void LED_Toggling(void){
    GPIO_TogglePinValue(PF2);

}
void LED_Timer_Fire(u32 Timer_value ){
 	GPT_EnableNotification(T0);
	GPT_Notification_T0(LED_Toggling);
	GPT_StartTimer(T0 , Timer_value);
}
/**********************************************************************************************************************
 *  END OF FILE: GPIO_program.c
 *********************************************************************************************************************/
