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



#ifndef		SYSCTRL_INTERFACE_H_
#define 	SYSCTRL_INTERFACE_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../COTS/02-LIB/Common/STD_TYPES.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*Common Configurations*/	
#define  ENABLE				1
#define	 DISABLE			0

/*Oscillator Source Configurations*/
#define   MOSC				0  /*Main oscillator*/
#define   PIOSC				1  /*Precision internal oscillator*/
#define   PIOSC_DIV_4		2  /*Precision internal oscillator / 4   */


/*Crystal Value Configurations*/
#define _4_MHZ     			0x06         
#define _5_MHZ				0x09
#define _6_MHZ				0x0B
#define _16_MHZ				0x015
#define _18_MHZ 			0x017
#define _20_MHZ 			0x018
#define _24_MHZ				0x019

/*PWM Unit Clock Divisor Configurations*/
#define  DIV_2 			0x0
#define  DIV_4 			0x1
#define  DIV_8 			0x2
#define  DIV_16			0x3
#define  DIV_32			0x4


/*Divide PLL */
#define _400_MHZ		1
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
void SysCtrl_MicrocontrollerInit (void);



#endif		/* SYSCTRL_Interface_H_ */