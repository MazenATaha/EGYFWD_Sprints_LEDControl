/**
 * @file IntCtrl_private.h
 * @author Mazen Ahmed Taha (MazenATaha@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-24
 * * @note Please note this driver code was taken from online source because mine wasn't working fine so I took this driver because I couldn't implement a NVIC driver in time

 * @copyright Copyright (c) 2022
 *
 */

#ifndef IntCtrl_Private_H_
#define IntCtrl_Private_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../COTS/02-LIB/Common/STD_TYPES.h"
#include "../COTS/01-MCAL/03-GPIO/INC/GPIO_private.h"
#include "../COTS/02-LIB/Common/TM4C123.h"

typedef struct
{

    u32 VECACT : 8;
    u32 : 3;
    u32 RETBASE : 1;
    u32 VECPEND : 8;
    u32 : 2;
    u32 ISRPEND : 1;
    u32 ISRPRE : 1;
    u32 : 1;
    u32 PENDSTCLR : 1;
    u32 PENDSTSET : 1;
    u32 UNPENDSV : 1;
    u32 PENDSV : 1;
    u32 reserved : 2;
    u32 NMISET : 1;

} INTCTRL_BF;

typedef union
{
    u32 R;
    INTCTRL_BF B;
} INTCTRL_Tag;

typedef struct
{
    u32 : 5;
    u32 MEM : 3;
    u32 : 5;
    u32 BUS : 3;
    u32 : 5;
    u32 USAGE : 3;
    u32 : 8;

} SYSPRI1_BF;

typedef union
{
    u32 R;
    SYSPRI1_BF B;
} SYSPRI1_Tag;

typedef struct
{
    u32 : 29;
    u32 SVC : 3;

} SYSPRI2_BF;

typedef union
{
    u32 R;
    SYSPRI2_BF B;
} SYSPRI2_Tag;

typedef struct
{
    u32 : 5;
    u32 DEBUG : 3;
    u32 : 13;
    u32 PENDSV : 3;
    u32 : 5;
    u32 TICK : 3;

} SYSPRI3_BF;
typedef union
{
    u32 R;
    SYSPRI3_BF B;
} SYSPRI3_Tag;

typedef struct
{
    u32 MEMA : 1;
    u32 BUSA : 1;
    u32 : 1;
    u32 USGA : 1;
    u32 : 3;
    u32 SVCA : 1;
    u32 MON : 1;
    u32 : 1;
    u32 PNDSV : 1;
    u32 TICK : 1;
    u32 USAGEP : 1;
    u32 MEMP : 1;
    u32 BUSP : 1;
    u32 SVC : 1;
    u32 MEM : 1;
    u32 BUS : 1;
    u32 USAGE : 1;
    u32 : 13;
} SYSHNDCTRL_BF;

typedef union
{
    u32 R;
    SYSHNDCTRL_BF B;
} SYSHNDCTRL_Tag;

typedef struct
{
    u32 VECTRESET : 1;
    u32 VECTCLRACT : 1;
    u32 SYSRESREQ : 1;
    u32 : 5;
    u32 PRIGROUP : 3;
    u32 : 4;
    u32 ENDIANESS : 1;
    u32 VECTKEY : 16;
} APINT_BF;

typedef union
{
    u32 R;
    APINT_BF B;
} APINT_Tag;

typedef struct
{
    u32 : 5;
    u32 INTA : 3;
    u32 : 5;
    u32 INTB : 3;
    u32 : 5;
    u32 INTC : 3;
    u32 : 5;
    u32 INTD : 3;
} PRIx_BF;

typedef union
{
    u32 R;
    PRIx_BF B;
} PRIx_Tag;

typedef struct
{
    u8 B0 : 1;
    u8 B1 : 1;
    u8 B2 : 1;
    u8 B3 : 1;
    u8 B4 : 1;
    u8 B5 : 1;
    u8 B6 : 1;
    u8 B7 : 1;
} u8_BF;

typedef union
{
    u8 R;
    u8_BF B;
} u8_Tag;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define M4_PERI_BASE_ADDRESS 0xE000E000
#define INTCTRL (*(volatile INTCTRL_Tag *)(M4_PERI_BASE_ADDRESS + 0xD04))
#define SYSPRI1 (*(volatile SYSPRI1_Tag *)(M4_PERI_BASE_ADDRESS + 0xD18))
#define SYSPRI2 (*(volatile SYSPRI2_Tag *)(M4_PERI_BASE_ADDRESS + 0xD1C))
#define SYSPRI3 (*(volatile SYSPRI3_Tag *)(M4_PERI_BASE_ADDRESS + 0xD20))
#define SYSHNDCTRL (*(volatile SYSHNDCTRL_Tag *)(M4_PERI_BASE_ADDRESS + 0xD24))
#define FAULTSTAT (*(volatile u32 *)(M4_PERI_BASE_ADDRESS + 0xD28))
#define HFAULTSTAT (*(volatile u32 *)(M4_PERI_BASE_ADDRESS + 0xD2C))
#define APINT (*(volatile APINT_Tag *)(M4_PERI_BASE_ADDRESS + 0xD0C))
#define VTABLE (*(volatile u32 *)(M4_PERI_BASE_ADDRESS + 0xD08))
#define SWTRIG (*(volatile u32 *)(M4_PERI_BASE_ADDRESS + 0xF00))

#define PRI(x) (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x400 + (x + x + x + x)))

#define PRI0 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x400))
#define PRI1 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x404))
#define PRI2 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x408))
#define PRI3 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x40C))
#define PRI4 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x410))
#define PRI5 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x414))
#define PRI6 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x418))
#define PRI7 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x41C))
#define PRI8 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x420))
#define PRI9 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x424))
#define PRI10 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x428))
#define PRI11 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x42C))
#define PRI12 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x430))
#define PRI13 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x434))
#define PRI14 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x438))
#define PRI15 (*(volatile PRIx_Tag *)(M4_PERI_BASE_ADDRESS + 0x43C))

#define EN0 (*(volatile u32_Tag *)(M4_PERI_BASE_ADDRESS + 0x100))
#define EN1 (*(volatile u32_Tag *)(M4_PERI_BASE_ADDRESS + 0x104))
#define EN2 (*(volatile u32_Tag *)(M4_PERI_BASE_ADDRESS + 0x108))
#define EN3 (*(volatile u32_Tag *)(M4_PERI_BASE_ADDRESS + 0x10C))
#define EN4 (*(volatile u8_Tag *)(M4_PERI_BASE_ADDRESS + 0x110))

#define DIS0 (*(volatile u32_Tag *)(M4_PERI_BASE_ADDRESS + 0x180))
#define DIS1 (*(volatile u32_Tag *)(M4_PERI_BASE_ADDRESS + 0x184))
#define DIS2 (*(volatile u32_Tag *)(M4_PERI_BASE_ADDRESS + 0x188))
#define DIS3 (*(volatile u32_Tag *)(M4_PERI_BASE_ADDRESS + 0x18C))
#define DIS4 (*(volatile u8_Tag *)(M4_PERI_BASE_ADDRESS + 0x190))

#endif /* IntCtrl_Private_H_ */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Private_H_
 *********************************************************************************************************************/
