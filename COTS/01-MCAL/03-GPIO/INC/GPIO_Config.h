/**
 * @file GPIO_Config.h
 * @author Mazen Ahmed Taha (MazenATaha@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef GPIO_CONFIGURE_H
#define GPIO_CONFIGURE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MCU Ports and Pins Configurations
 *********************************************************************************************************************/

#define PORTA_INIT ENABLE
#define PORTB_INIT ENABLE
#define PORTC_INIT ENABLE
#define PORTD_INIT ENABLE
#define PORTE_INIT ENABLE
#define PORTF_INIT ENABLE

/**
 * @brief Pins Configurations
 * each pin has the following configurations : O0UTPUT,	INPUT_PULL_UP,	INPUT_PULL_DN,	INPUT_OPEN_DRAIN
 *
 */
/*******************************************************************************************************************

/******************************PORTA*********************************************************************************/
#define PORTA_PIN0 INPUT_OPEN_DRAIN
#define PORTA_PIN1 INPUT_OPEN_DRAIN
#define PORTA_PIN2 INPUT_OPEN_DRAIN
#define PORTA_PIN3 INPUT_OPEN_DRAIN
#define PORTA_PIN4 INPUT_OPEN_DRAIN
#define PORTA_PIN5 INPUT_OPEN_DRAIN
#define PORTA_PIN6 INPUT_OPEN_DRAIN
#define PORTA_PIN7 INPUT_OPEN_DRAIN

/******************************PORTB*********************************************************************************/
#define PORTB_PIN0 INPUT_OPEN_DRAIN
#define PORTB_PIN1 INPUT_OPEN_DRAIN
#define PORTB_PIN2 INPUT_OPEN_DRAIN
#define PORTB_PIN3 INPUT_OPEN_DRAIN
#define PORTB_PIN4 INPUT_OPEN_DRAIN
#define PORTB_PIN5 INPUT_OPEN_DRAIN
#define PORTB_PIN6 INPUT_OPEN_DRAIN
#define PORTB_PIN7 INPUT_OPEN_DRAIN

/******************************PORTC*********************************************************************************/
#define PORTC_PIN0 INPUT_OPEN_DRAIN
#define PORTC_PIN1 INPUT_OPEN_DRAIN
#define PORTC_PIN2 INPUT_OPEN_DRAIN
#define PORTC_PIN3 INPUT_OPEN_DRAIN
#define PORTC_PIN4 PC4_WT0CCP0 // Used Timer
#define PORTC_PIN5 INPUT_OPEN_DRAIN
#define PORTC_PIN6 INPUT_OPEN_DRAIN
#define PORTC_PIN7 INPUT_OPEN_DRAIN

/******************************PORTD*********************************************************************************/
#define PORTD_PIN0 INPUT_OPEN_DRAIN
#define PORTD_PIN1 INPUT_OPEN_DRAIN
#define PORTD_PIN2 INPUT_OPEN_DRAIN
#define PORTD_PIN3 INPUT_OPEN_DRAIN
#define PORTD_PIN4 INPUT_OPEN_DRAIN
#define PORTD_PIN5 INPUT_OPEN_DRAIN
#define PORTD_PIN6 INPUT_OPEN_DRAIN
#define PORTD_PIN7 INPUT_OPEN_DRAIN
/******************************PORTE*********************************************************************************/
#define PORTE_PIN0 INPUT_OPEN_DRAIN
#define PORTE_PIN1 INPUT_OPEN_DRAIN
#define PORTE_PIN2 INPUT_OPEN_DRAIN
#define PORTE_PIN3 INPUT_OPEN_DRAIN
#define PORTE_PIN4 INPUT_OPEN_DRAIN
#define PORTE_PIN5 INPUT_OPEN_DRAIN

/******************************PORTF*********************************************************************************/
#define PORTF_PIN0 INPUT_PULL_UP
#define PORTF_PIN1 OUTPUT
#define PORTF_PIN2 OUTPUT
#define PORTF_PIN3 OUTPUT
#define PORTF_PIN4 INPUT_PULL_UP

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
const u8 PortConfig[6] = {
	PORTA_INIT, PORTB_INIT, PORTC_INIT, PORTD_INIT, PORTE_INIT, PORTF_INIT};

const u8 PinConfig[6][8] = {
	{PORTA_PIN0, PORTA_PIN1, PORTA_PIN2, PORTA_PIN3, PORTA_PIN4, PORTA_PIN5, PORTA_PIN6, PORTA_PIN7},
	{PORTB_PIN0, PORTB_PIN1, PORTB_PIN2, PORTB_PIN3, PORTB_PIN4, PORTB_PIN5, PORTB_PIN6, PORTB_PIN7},
	{PORTC_PIN0, PORTC_PIN1, PORTC_PIN2, PORTC_PIN3, PORTC_PIN4, PORTC_PIN5, PORTC_PIN6, PORTC_PIN7},
	{PORTD_PIN0, PORTD_PIN1, PORTD_PIN2, PORTD_PIN3, PORTD_PIN4, PORTD_PIN5, PORTD_PIN6, PORTD_PIN7},
	{PORTE_PIN0, PORTE_PIN1, PORTE_PIN2, PORTE_PIN3, PORTE_PIN4, PORTE_PIN5, 99, 99},
	{PORTF_PIN0, PORTF_PIN1, PORTF_PIN2, PORTF_PIN3, PORTF_PIN4, 99, 99, 99}};

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* GPIO_CONFIGURE_H */
