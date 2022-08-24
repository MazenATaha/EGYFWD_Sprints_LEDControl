/**
 * @file GPIO_private.h
 * @author Mazen Ahmed Taha (MazenATaha@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/********************		Memories base addresses		******************************/

/**
 * 
 * @a SYSTIC_RCGC_GPIO_registers
 * @brief The following are defines for the bit fields in the SYSCTL_RCGCGPIO register
 * 
 */
#define SYSCTL_RCGCGPIO_R5      0x00000020  // GPIO Port F Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R4      0x00000010  // GPIO Port E Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R3      0x00000008  // GPIO Port D Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R2      0x00000004  // GPIO Port C Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R1      0x00000002  // GPIO Port B Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R0      0x00000001  // GPIO Port A Run Mode Clock
                                            // Gating Control
// 
#define SYSCTL_RCGCGPIO_R (*(( volatile unsigned long *)0x400FE608))





//*****************************************************************************
//
// GPIO registers (PORTF)
//
//*****************************************************************************
#define GPIO_PORTF_DATA_BITS_R  ((volatile unsigned long *)0x40025000)
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_IS_R         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_R        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_R        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_R         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_RIS_R        (*((volatile unsigned long *)0x40025414))
#define GPIO_PORTF_MIS_R        (*((volatile unsigned long *)0x40025418))
#define GPIO_PORTF_ICR_R        (*((volatile unsigned long *)0x4002541C))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_DR2R_R       (*((volatile unsigned long *)0x40025500))
#define GPIO_PORTF_DR4R_R       (*((volatile unsigned long *)0x40025504))
#define GPIO_PORTF_DR8R_R       (*((volatile unsigned long *)0x40025508))
#define GPIO_PORTF_ODR_R        (*((volatile unsigned long *)0x4002550C))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_PDR_R        (*((volatile unsigned long *)0x40025514))
#define GPIO_PORTF_SLR_R        (*((volatile unsigned long *)0x40025518))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define GPIO_PORTF_ADCCTL_R     (*((volatile unsigned long *)0x40025530))
#define GPIO_PORTF_DMACTL_R     (*((volatile unsigned long *)0x40025534))


/********************************************************************************************************************/

/**
 * @brief Found new way of naming looking for it
 * 
 */
#define 	GPIOF_APB_BASE_ADDRESS			0x40025000
#define 	GPIODATA_PF					(*( volatile u8*)(  GPIOF_APB_BASE_ADDRESS+ 0x000 +0x3FC ) )
#define 	GPIOLOCK_PF					(*( volatile u32*)(  GPIOF_APB_BASE_ADDRESS+ 0x520 ) )
#define 	GPIOPCTL_PF					(*( volatile GPIOPCTL_Tag*)(  GPIOF_APB_BASE_ADDRESS+ 0x52C ) )
#define 	GPIOCR_PF					(*( volatile u8*)(  GPIOF_APB_BASE_ADDRESS+ 0x524 ) )
#define 	GPIOICR_PF					(*( volatile u8*)(  GPIOF_APB_BASE_ADDRESS+ 0x41C ) )
#define 	GPIOAFSEL_PF				(*( volatile u8*)(  GPIOF_APB_BASE_ADDRESS+ 0x420 ) )
#define 	GPIODIR_PF					(*( volatile u8*)(  GPIOF_APB_BASE_ADDRESS+ 0x400 ) )
#define 	GPIODEN_PF					(*( volatile u8*)(  GPIOF_APB_BASE_ADDRESS+ 0x51C ) )


/**
 * @brief Base Addresses
 * 
 */

#define 	SYSTEM_CONTROL_BASE				0x400FE000
#define 	M4_PERI_BASE_ADDRESS			0xE000E000
#define 	BASE_ADDRESS(PORTx)				(PORTx<4 ? (0x40004000 + (PORTx*0x1000)) : (0x40024000 + (PORTx-4)*0x1000))

/**
 * @brief GPIO registers (All ports For Intialisation purpose)
 * 
 */
#define 	GPIOLOCK(PORTx)					(*( volatile u32*)( (BASE_ADDRESS(PORTx))+ 0x520 ) )
#define 	GPIOCR(PORTx)					(*( volatile u32*) ( (BASE_ADDRESS(PORTx))+ 0x524 ) )
#define 	GPIODEN(PORTx)					(*( volatile u32*) ( (BASE_ADDRESS(PORTx))+ 0x51C ) )
#define 	GPIOAFSEL(PORTx)				(*( volatile u32*) (  BASE_ADDRESS(PORTx) + 0x420 ) )
#define 	GPIODIR(PORTx)					(*( volatile u32*)(  BASE_ADDRESS(PORTx) + 0x400 ) )
#define 	GPIOPUR(PORTx)					(*( volatile u32*)(  BASE_ADDRESS(PORTx) + 0x510 ) )
#define 	GPIOODR(PORTx)					(*( volatile u32*)(  BASE_ADDRESS(PORTx) + 0x50C ) )
#define 	GPIOPDR(PORTx)					(*( volatile u32*)(  BASE_ADDRESS(PORTx) + 0x514 ) )
#define 	GPIOPCTL(PORTx)					(*( volatile u32*)(  BASE_ADDRESS(PORTx) + 0x52C ) )
#define 	GPIODATA(PORTx)					(*( volatile u32_Tag*)(  BASE_ADDRESS(PORTx) + 0x3FC ) )

/**
 * @brief 
 * 
 */
#define RCGCGPIO					(*(volatile RCGCGPIO_Tag*)	(SYSTEM_CONTROL_BASE + 0x608) )
#define	RCGC2						(*(volatile RCGC2_Tag*)		(SYSTEM_CONTROL_BASE + 0x108) )



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef struct
{
	u32	PMC0	:4;
	u32	PMC1	:4;
	u32	PMC2	:4;
	u32	PMC3	:4;
	u32	PMC4	:4;
	u32	PMC5	:4;
	u32	PMC6	:4;
	u32	PMC7	:4;
}GPIOPCTL_BF;

typedef union
{
	u32 R;
	GPIOPCTL_BF B;
} GPIOPCTL_Tag;














/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES MACROS
 *********************************************************************************************************************/
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

typedef union 
{
	u32 R;
}u32_Tag;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
