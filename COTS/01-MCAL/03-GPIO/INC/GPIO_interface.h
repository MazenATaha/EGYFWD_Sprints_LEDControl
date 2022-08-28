/**
 * @file GPIO_interface.h
 * @author Mazen Ahmed Taha (MazenATaha@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../COTS/02-LIB/Common/STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**
 * Old way of Defination not accurate

/* Port Defines
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTC 4
#define PORTF 5

/* PIN Defines
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
 */
#define HIGH 1
#define LOW 0

/*************************************PINS Config ************************************************/

#define INPUT 0
#define OUTPUT 1
#define INPUT_PULL_UP 11
#define INPUT_PULL_DN 12
#define INPUT_OPEN_DRAIN 13
#define PC4_WT0CCP0 7 // Timer

#define DISABLE 0
#define ENABLE 1

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**
 * @brief GPIO Enums To easily access PIN Number without need for switch cases
 *
 */
typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
} GPIO_PinNo;

/**
 * @brief GPIO Enums To easily access PIN Number without need for switch cases
 *
 */
typedef enum
{
	PA0 = 00,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	PB0 = 10,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,
	PC0 = 20,
	PC1,
	PC2,
	PC3,
	PC4,
	PC5,
	PC6,
	PC7,
	PD0 = 30,
	PD1,
	PD2,
	PD3,
	PD4,
	PD5,
	PD6,
	PD7,
	PE0 = 40,
	PE1,
	PE2,
	PE3,
	PE4,
	PE5,
	PF0 = 50,
	PF1,
	PF2,
	PF3,
	PF4
} GPIO_ChannelType;

/**
 * @brief Port Enums To easily access PIN Number without need for switch cases
 *
 */
typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF
} GPIO_PortType;
/**
 * @brief GPIO Enums To easily access PIN Number without need for switch cases
 *
 */
typedef enum
{
	Low,
	High
} GPIO_LevelType;

typedef enum
{
	PORT_LOW,
	PORT_INPUT = 0,
	PORT_OUTPUT = 255,
	PORT_HIGH = 255
} GPIO_PortLevelType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**
 * @brief Call it When need to set a pin HIGH/LOW
 *
 *
 * @param ChannelId PIN Number Range (PA0 to PF4)
 * @param Level Set pin value either (HIGH/LOW) equivalent (1/0)
 * @sync
 * @
 */
void GPIO_SetPinValue(GPIO_ChannelType ChannelId, GPIO_LevelType Level);

/**
/**
 * @brief
 *
 * @param ChannelId PIN Number Range (PA0 to PF4)
 */
void GPIO_TogglePinValue(GPIO_ChannelType ChannelId);

/**
 * @brief Intialise ports according to our configures in GPIO Config File
 *
 */
void PORT_Init(void);

#endif /* GPIO_INTERFACE_H_ */