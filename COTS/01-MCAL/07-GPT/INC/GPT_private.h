/**
 * @file SysCtrl_private.h
 * @author Mazen Ahmed Taha (MazenATaha@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef		GPT_PRIVATE_H_
#define 	GPT_PRIVATE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../COTS/02-LIB/Common/STD_TYPES.h"
#include "../COTS/02-LIB/Common/TM4C123.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define 	PC4_WT0CCP0							7
#define		TIMER0_BASE_ADDRESS					0x40030000
#define		TIMER1_BASE_ADDRESS					0x40031000
#define		TIMER2_BASE_ADDRESS					0x40032000
#define		TIMER3_BASE_ADDRESS					0x40033000
#define		TIMER4_BASE_ADDRESS					0x40034000
#define		TIMER5_BASE_ADDRESS					0x40035000

#define		WIDE_TIMER0_BASE_ADDRESS			0x40036000
#define		WIDE_TIMER1_BASE_ADDRESS			0x40037000
#define		WIDE_TIMER2_BASE_ADDRESS			0x4003C000
#define		WIDE_TIMER3_BASE_ADDRESS			0x4003D000
#define		WIDE_TIMER4_BASE_ADDRESS			0x4003E000
#define		WIDE_TIMER5_BASE_ADDRESS			0x4003F000

/**********************************************************************************************************************/
#define 	TIMER_BASE_ADDRESS(Timer)			( 0x40030000+(Timer*0x1000) )
/**********************************************************************************************************************/

#define		GPTMCTL(T)				( *(volatile GPTMCTL_Tag*)		( TIMER_BASE_ADDRESS(T) + 0x00C ) )
#define		GPTMCFG(T)				( *(volatile GPTMCFG_Tag*)		( TIMER_BASE_ADDRESS(T) + 0x000 ) )
#define		GPTMTAMR(T)				( *(volatile GPTMTAMR_Tag*)		( TIMER_BASE_ADDRESS(T) + 0x004 ) )
#define		GPTMTAPR(T)				( *(volatile u32_Register*)		( TIMER_BASE_ADDRESS(T) + 0x038 ) ) 
#define		GPTMTAILR(T)			( *(volatile u32_Register*)		( TIMER_BASE_ADDRESS(T) + 0x028 ) ) 
#define 	GPTMIMR(T)				( *(volatile GPTMIMR_Tag*)		( TIMER_BASE_ADDRESS(T) + 0x018 ) ) 
#define 	GPTMRIS(T)				( *(volatile GPTMRIS_Tag*)		( TIMER_BASE_ADDRESS(T) + 0x01C ) ) 
#define 	GPTMICR(T)				( *(volatile GPTMICR_Tag*)		( TIMER_BASE_ADDRESS(T) + 0x024 ) ) 




/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
	u16		TAEN			:1;
	u16		TASTALL			:1;
	u16		TAEVENT			:2;	
	u16		RTCEN			:1;
	u16		TAOTE			:1;
	u16		TAPWML			:1;
	u16						:1;
	u16		TBEN			:1;
	u16		TBSTALL			:1;
	u16		TBEVENT			:2;
	u16						:1;
	u16		TBOTE			:1;
	u16		TBPWML			:1;
	u16						:1;

}GPTMCTL_BF;

typedef union 
{
	u16 R;
	GPTMCTL_BF B;
}GPTMCTL_Tag;


typedef struct
{
	u16		TAMR			:2;
	u16		TACMR			:1;
	u16		TAAMS			:1;	
	u16		TACDIR			:1;
	u16		TAOTE			:1;
	u16		TAMIE			:1;
	u16		TAWOT			:1;
	u16		TASNAPS			:1;
	u16		TAILD			:1;
	u16		TAPWMIE			:1;
	u16		TAMRSU			:1;
	u16		TAPLO			:1;
	u16						:4;

}GPTMTAMR_BF;


typedef union 
{
	u16 R;
	GPTMTAMR_BF B;
}GPTMTAMR_Tag;

typedef struct
{
	u32		GPTMCFG			:3;
	u32 					:29;
}GPTMCFG_BF;
typedef union 
{
	u32 R;
	GPTMCFG_BF B;
}GPTMCFG_Tag;

typedef enum 
{
	COUNT_DOWN=0,
	COUNT_UP,
}Gpt_CountDir;


typedef union
{
	u32 R;
}u32_Register;
typedef struct
{
	u32 TATOIM	:1;
	u32 CAMIM	:1;
	u32 CAEIM	:1;
	u32 RTCIM	:1;
	u32 TAMIM	:1;
	u32 		:3;
	u32 TBTOIM	:1;
	u32 CBMIM	:1;
	u32 CBEIM	:1;
	u32 TBMIM	:1;
	u32 		:4;
	u32 WUEIM	:1;
	u32			:15;
}GPTMIMR_BF;
typedef union
{
	u32 R;
	GPTMIMR_BF B;
}GPTMIMR_Tag;




typedef struct
{
	u32 TATORIS	:1;
	u32 CAMRIS	:1;
	u32 CAERIS	:1;
	u32 RTCRIS	:1;
	u32 TAMRIS	:1;
	u32 		:3;
	u32 TBTORIS	:1;
	u32 CBMRIS	:1;
	u32 CBERIS	:1;
	u32 TBMRIS	:1;
	u32 		:4;
	u32 WUERIS	:1;
	u32			:15;
}GPTMRIS_BF;
typedef union
{
	u32 R;
	GPTMRIS_BF B;
}GPTMRIS_Tag;


typedef struct
{
	u32 TATOCINT	:1;
	u32 CAMCINT	:1;
	u32 CAECINT	:1;
	u32 RTCCINT	:1;
	u32 TAMCINT	:1;
	u32 		:3;
	u32 TBTOCINT	:1;
	u32 CBMCINT	:1;
	u32 CBECINT	:1;
	u32 TBMCINT	:1;
	u32 		:4;
	u32 WUECINT	:1;
	u32			:15;
}GPTMICR_BF;
typedef union
{
	u32 R;
	GPTMICR_BF B;
}GPTMICR_Tag;
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#endif		/* GPT_PRIVATE_H_ */