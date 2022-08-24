/**
 * @file TM4C123.h
 * @author Mazen Ahmed Taha (MazenATaha@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*Preprocessor File Guard*/
#ifndef TM4C123_H_
#define TM4C123_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "../COTS/02-LIB/Common/STD_TYPES.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**
 * @brief Base Addresses
 * */
#define 	SYSTEM_CONTROL_BASE				0x400FE000
#define 	M4_PERI_BASE_ADDRESS			0xE000E000

#define RCC							(*(volatile RCC_Tag*)		(SYSTEM_CONTROL_BASE + 0x060) )
#define RCC2						(*(volatile RCC2_Tag*)		(SYSTEM_CONTROL_BASE + 0x070) )
#define	RCGC2						(*(volatile RCGC2_Tag*)		(SYSTEM_CONTROL_BASE + 0x108) )
#define PLLSTAT						(*(volatile PLLSTAT_Tag*) 	(SYSTEM_CONTROL_BASE + 0x168) )
#define RCGCGPIO					(*(volatile RCGCGPIO_Tag*)	(SYSTEM_CONTROL_BASE + 0x608) )
#define RCGCWTIMER					(*(volatile RCGCWTIMER_Tag*)(SYSTEM_CONTROL_BASE + 0x65C) )
#define RCGCTIMER					(*(volatile RCGCWTIMER_Tag*)(SYSTEM_CONTROL_BASE + 0x604) )







#define 	INTCTRL						(*(volatile INTCTRL_Tag*)( M4_PERI_BASE_ADDRESS + 0xD04) )

/********************		Memories base addresses		******************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef struct
{
	u32 MOSCDIS			:1;
	u32 				:3;
	u32 OSCSRC			:2;
	u32 XTAL			:5;
	u32 BYPASS			:1;
	u32 				:1;
	u32 PWRDN			:1;
	u32					:3;
	u32 PWMDIV			:3;
	u32 USEPWMDIV		:1;
	u32 				:1;
	u32 USESYSDIV		:1;
	u32 SYSDIV			:4;
	u32 ACG				:1;
	u32 				:4;
}RCC_BF;

typedef union
{
	u32 	R;
	RCC_BF  B;
}RCC_Tag;

typedef struct
{
	u32 				:4;
	u32 OSCSRC2			:3;
	u32 				:4;
	u32 BYPASS2			:1;
	u32 				:1;
	u32 PWRDN2			:1;
	u32 USBPWRDN		:1;
	u32					:7;
	u32 SYSDIV2LSB		:1;
	u32 SYSDIV2			:6;
	u32 				:1;
	u32 DIV400			:1;
	u32 USERCC2			:1;
}RCC2_BF;

typedef union
{
	u32 	R;
	RCC2_BF  B;
}RCC2_Tag;

typedef struct
{
	u32		R0			:1;
	u32		R1			:1;
	u32		R2			:1;
	u32		R3			:1;
	u32		R4			:1;
	u32		R5			:1;
	u32 				:26;
}RCGCGPIO_BF;

typedef union 
{
	u32 R;
	RCGCGPIO_BF B;
}RCGCGPIO_Tag;


typedef struct 
{
	u32 GPIOA		:1;
	u32 GPIOB		:1;
	u32 GPIOC		:1;
	u32 GPIOD		:1;
	u32 GPIOE		:1;
	u32 GPIOF		:1;
	u32 			:7;
	u32 UDMA		:1;
	u32				:2;
	u32	USB0		:1;
	u32				:15;
}RCGC2_BF;
typedef union 
{
	u32 R;
	RCGC2_BF B;
}RCGC2_Tag;

typedef struct
{
	u32				:31;
	u32 LOCK		:1;
}PLLSTAT_BF;

typedef union
{
	PLLSTAT_BF  B;
}PLLSTAT_Tag;

typedef struct
{
	u32		R0			:1;
	u32		R1			:1;
	u32		R2			:1;
	u32		R3			:1;
	u32		R4			:1;
	u32		R5			:1;
	u32 				:26;
}RCGCWTIMER_BF;
typedef union 
{
	u32 R;
	RCGCWTIMER_BF B;
}RCGCWTIMER_Tag;

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/********************	GPIO register definition structure	***************************/


/********************	GPIO Peripherial definitions	***************************/

#endif

