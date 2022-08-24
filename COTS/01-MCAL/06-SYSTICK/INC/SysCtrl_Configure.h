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


#ifndef		SYSCTRL_CONFIGURE_H_
#define 	SYSCTRL_CONFIGURE_H_



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../COTS/01-MCAL/06-SYSTICK/INC/SysCtrl_Interface.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define USE_RCC2					DISABLE   /*RCC2 Fields Override RCC*/

/*RCC*/
#define MAIN_OSCILLATOR				DISABLE
#define OSCILLATOR_SOURCE			PIOSC
#define CRYSTAL_VALUE				_16_MHZ
#define PLL_BYPASS					ENABLE
#define	PLL_POWER_DOWN				ENABLE
#define PWM_DIVISOR					DIV_16
#define PWM_DIVISOR_EN				DISABLE
#define SYSCLOCK_DIVIDER_EN			ENABLE
#define SYSTEM_CLOCK_DIVIDER		1			
#define AUTO_CLOCK_GATING			DISABLE

/*RCC2*/
#define OSCILLATOR_SOURCE_2			PIOSC
#define PLL_BYPASS_2				ENABLE
#define	PLL_POWER_DOWN_2			ENABLE
#define	PWRDN_USB_PLL				ENABLE
#define SYSTEM_CLOCK_DIVIDER_2		1			
#define DIVIDE_PLL_AS				_400_MHZ


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif		/* SYSCTRL_CONFIGURE_H */