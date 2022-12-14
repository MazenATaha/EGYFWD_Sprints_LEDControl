/**
 * @file SysCtrl_Configure.h
 * @author Mazen Ahmed Taha (MazenATaha@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef		GPT_CONFIGURE_H_
#define 	GPT_CONFIGURE_H_



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../COTS/01-MCAL/07-GPT/INC/GPT_Interface.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define		GPT_PREDEF_TIEMR_1uS_16BIT_EN			ENABLE
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES MACROS
 *********************************************************************************************************************/
const Gpt_ConfigType	GPT_ConfigArray [] =
{
	/*ChannelId;ChannelTickFreq ;ChannelTickValueMax ;ChannelMode;*/
	{T0,	GPT_16MHz	, 16000000 	, PERIODIC_MODE },
	{T1,	GPT_16MHz	, 16		, PERIODIC_MODE },
	{T2,	GPT_16MHz	, 16 		, PERIODIC_MODE },
	{T3,	GPT_16MHz	, 16		, PERIODIC_MODE },
	{T4,	GPT_16MHz	, 16 		, PERIODIC_MODE },
	{T5,	GPT_16MHz	, 16 		, PERIODIC_MODE },
	
	{WT0,	GPT_8MHz	, 8000 		, PERIODIC_MODE },
	{WT1,	GPT_16MHz	, 16000000 	, PERIODIC_MODE },
	{WT2,	GPT_16MHz	, 16 		, PERIODIC_MODE },
	{WT3,	GPT_16MHz	, 16 		, PERIODIC_MODE },
	{WT4,	GPT_16MHz	, 16000000 	, PERIODIC_MODE },

};


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif		/* GPT_CONFIGURE_H */