/**
 * @file GPIO_program.c
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
#include "../COTS/02-LIB/Common/BIT_MATH.h"
#include "../COTS/02-LIB/Common/TM4C123.h"

#include "../COTS/01-MCAL/03-GPIO/INC/GPIO_interface.h"
#include "../COTS/01-MCAL/03-GPIO/INC/GPIO_private.h"
#include "../COTS/01-MCAL/03-GPIO/INC/GPIO_Config.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/



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

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
/* IO Pins */
void GPIO_SetPinValue(GPIO_ChannelType ChannelId, GPIO_LevelType Level)
{
	GPIO_PortType PORTi = (u8) (ChannelId / 10);
	GPIO_PinNo	  PINi	= ChannelId % 10;
	
	SET_BIT(GPIODIR(PORTi), ChannelId);
	if (Level==HIGH)
	{
		GPIODATA(PORTi).R |= Level << PINi;
	}else if (Level==LOW)
	{
		GPIODATA(PORTi).R &= ~ (1 << (PINi));
	}
	
	
	

}


// Toggle
void GPIO_TogglePinValue(GPIO_ChannelType ChannelId)
{
	GPIO_PortType PORTi = (u8) (ChannelId / 10);
	GPIO_PinNo	  PINi	= ChannelId % 10;
		
	TOGGLE_BIT(GPIODATA(PORTi).R ,PINi) ;
}



void PORT_Init (void)
{
	GPIO_PortType PORTi = 0;
	for( PORTi=PORTA ; PORTi<=PORTF ; PORTi++)
	{
		if( PortConfig[PORTi] == ENABLE)
		{	
			u8 i=0;
			GPIO_PinNo PINi = 0;
			u32 CTL_Mask	= 0x0000000f;
			/*Gate Enable*/
			SET_BIT(RCGC2.R ,   PORTi);
			SET_BIT(RCGCGPIO.R, PORTi);
			while(i<5)
			{
				i++;
			}
			/*Commit Control*/
			GPIOLOCK(PORTi) = 0x4C4F434B ;	
			GPIOCR(PORTi) 	= 0x000000ff;
			GPIODEN(PORTi)	= 0x000000ff;
			/*Mux selects port as DIO*/
			GPIOAFSEL(PORTi) = 0;
			/*Data Control*/
			
			for(PINi=PIN0 ; PINi<=PIN7 ; PINi++)
			{	
				if(PinConfig[PORTi][PINi] == OUTPUT )
				{
					SET_BIT(GPIODIR(PORTi), PINi);
					CLR_BIT(GPIODATA(PORTi).R, PINi);
				}
				else if (PinConfig[PORTi][PINi] == INPUT_OPEN_DRAIN )
				{
					CLR_BIT(GPIODIR(PORTi), PINi);
					SET_BIT(GPIOODR(PORTi), PINi);

				}
				else if (PinConfig[PORTi][PINi] == INPUT_PULL_UP )
				{
					CLR_BIT(GPIODIR(PORTi), PINi);
					SET_BIT(GPIOPUR(PORTi), PINi);
				}
				else if (PinConfig[PORTi][PINi] == INPUT_PULL_DN )
				{
					CLR_BIT(GPIODIR(PORTi), PINi);
					SET_BIT(GPIOPDR(PORTi), PINi);
				}
				else
				{
					
					SET_BIT(GPIOAFSEL(PORTi), PINi);
					GPIOPCTL(PORTi) |= (CTL_Mask << (4*PINi) ) & PinConfig[PORTi][PINi];
				}			
			}
		}
	}
}


/**********************************************************************************************************************
 *  END OF FILE: GPIO_program.c
 *********************************************************************************************************************/
