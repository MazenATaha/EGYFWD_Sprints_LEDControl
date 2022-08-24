/**
 * @file SysCtrl_program.c
 * @author Mazen Ahmed Taha (MazenATaha@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */




/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../COTS/02-LIB/Common/STD_TYPES.h"
#include "../COTS/02-LIB/Common/BIT_MATH.h"
#include "../COTS/02-LIB/Common/TM4C123.h"
#include "../COTS/01-MCAL/07-GPT/INC/GPT_Configure.h"
#include "../COTS/01-MCAL/07-GPT/INC/GPT_private.h"
#include "../COTS/01-MCAL/07-GPT/INC/GPT_Interface.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
void (*TimerCallBack[12]) (void) = {	NULL , NULL , NULL ,NULL ,
										NULL , NULL , NULL , NULL, 
										NULL , NULL , NULL , NULL };


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/



void GPT_Init(void)
{

	u8 i =0;
	RCGCTIMER.R	 = 0xff;
	RCGCWTIMER.R = 0xff;
	for( i=0 ; i<11 ; i++)
	{	
		GPTMCTL(GPT_ConfigArray[i].ChannelId).B.TAEN 	= DISABLE;
		GPTMCFG(GPT_ConfigArray[i].ChannelId).B.GPTMCFG = 0x00000000;
		GPTMTAMR(GPT_ConfigArray[i].ChannelId).B.TAMR 	= GPT_ConfigArray[i].ChannelMode;
		GPTMTAMR(GPT_ConfigArray[i].ChannelId).B.TACDIR	= COUNT_DOWN;
		GPTMTAPR(GPT_ConfigArray[i].ChannelId).R 		= GPT_ConfigArray[i].ChannelTickFreq;
		GPTMTAILR(GPT_ConfigArray[i].ChannelId).R 		= GPT_ConfigArray[i].ChannelTickValueMax;
		GPTMIMR(GPT_ConfigArray[i].ChannelId).R			= 0x00000000;
	}
	
	/*Predefined Timer Init*/
	GPTMCTL(WT5).B.TAEN 	= DISABLE;
	GPTMCFG(WT5).B.GPTMCFG 	= 0x00000000;
	GPTMTAMR(WT5).B.TAMR 	= PERIODIC_MODE;
	GPTMTAMR(WT5).B.TACDIR	= COUNT_DOWN;
	GPTMTAPR(WT5).R 		= GPT_16MHz;
	GPTMTAILR(WT5).R 		= 0xffffffff;
	GPTMCTL(WT5).B.TAEN 	= ENABLE;
}

void	GPT_DisableNotification(Gpt_ChannelType Channel)
{
	GPTMIMR(Channel).R	= 0x00000000;
}
void	GPT_EnableNotification(Gpt_ChannelType Channel)
{
	GPTMIMR(Channel).B.TATOIM = ENABLE;
}

void GPT_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Counts)
{
	
	GPTMTAILR(Channel).R = Counts;
	GPTMCTL(Channel).B.TAEN 	= ENABLE;
	while( (GPTMRIS(Channel).B.TATORIS) != 1);
}



void GPT_Notification_T0 (void (*Timer0CallBack) (void) )
{
	TimerCallBack[0] = Timer0CallBack ;
}




void TIMER0A_Handler(void)
{
	if( TimerCallBack[0] != NULL )
	{
		/*execute passed function*/
		TimerCallBack[0]();
		GPTMICR(T0).B.TATOCINT = 1;
	}
}