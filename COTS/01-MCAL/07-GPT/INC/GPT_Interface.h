/**
 * @file SysCtrl_Interface.h
 * @author Mazen Ahmed Taha (MazenATaha@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef GPT_INTERFACE_H_
#define GPT_INTERFACE_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../COTS/02-LIB/Common/STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ENABLE 1
#define DISABLE 0

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef u32 Gpt_ValueType;

typedef enum
{
	T0 = 0,
	T1,
	T2,
	T3,
	T4,
	T5,
	WT0,
	WT1,
	WT2 = 0xC,
	WT3,
	WT4,
	WT5
} Gpt_ChannelType;

typedef enum
{
	ONESHOT_MODE = 1,
	PERIODIC_MODE
} Gpt_ModeType;

typedef enum
{
	GPT_16MHz = 0,
	GPT_8MHz = 1,
	GPT_4MHz = 3
} Gpt_TickFreq;

typedef struct
{
	Gpt_ChannelType ChannelId;
	Gpt_ValueType ChannelTickFreq;
	Gpt_ValueType ChannelTickValueMax;
	Gpt_ModeType ChannelMode;
	// Notification
} Gpt_ConfigType;
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void GPT_Init(void);

void GPT_DisableNotification(Gpt_ChannelType Channel);

void GPT_EnableNotification(Gpt_ChannelType Channel);

void GPT_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Counts);

void GPT_Notification_T0(void (*Timer0CallBack)(void));

#endif /* GPT_Interface_H_ */