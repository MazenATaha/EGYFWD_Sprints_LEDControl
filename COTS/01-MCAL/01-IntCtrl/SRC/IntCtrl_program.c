/**
 * @file IntCtrl_program.c
 * @author Mazen Ahmed Taha (MazenATaha@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-24
 * @note Please note this driver code was taken from online source because mine wasn't working fine so I took this driver because I couldn't implement a NVIC driver in time
 * @copyright Copyright (c) 2022
 *
 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../COTS/02-LIB/Common/STD_TYPES.h"
#include "../COTS/02-LIB/Common/BIT_MATH.h"
#include "../COTS/02-LIB/Common/TM4C123.h"

#include "../COTS/01-MCAL/01-IntCtrl/INC/IntCtrl_private.h"
#include "../COTS/01-MCAL/01-IntCtrl/INC/IntCtrl_Interface.h"
#include "../COTS/01-MCAL/01-IntCtrl/INC/IntCtrl_Configure.h"

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

void IntCrtl_Init(void)
{
    IntCtrl_InterruptType iteratingInt = 0;
    u32 IntEnMask = 1;
    // u32 PrioMask  = 0x000000E0;
    u8 RegNo = 0;
    u8 BitNo = 0;
    u8 PrioValue = 0;
    u8 Prio_i = 0;
    u8 PrioMask[] = {4, 12, 20, 28};
    u8 PRI_reg = 0;
    APINT.B.VECTKEY = 0x05FA;
    APINT.B.VECTRESET = 0x0;
    APINT.B.VECTCLRACT = 0x0;
    APINT.B.SYSRESREQ = 0x0;
#if PRIORITY_GROUPING == XXX
    APINT.B.PRIGROUP = 0x0;
#elif PRIORITY_GROUPING == XXY
    APINT.B.PRIGROUP = 0x5;
#elif PRIORITY_GROUPING == XYY
    APINT.B.PRIGROUP = 0x6;
#elif PRIORITY_GROUPING == YYY
    APINT.B.PRIGROUP = 0x7;
#endif

    SYSHNDCTRL.B.MEM = MEMORY_MANAGEMENT_EN;
    SYSHNDCTRL.B.BUS = BUS_FAULT_EN;
    SYSHNDCTRL.B.USAGE = USAGE_FAULT_EN;

    SYSPRI1.B.MEM = Memory_Management_Priority;
    SYSPRI1.B.BUS = Bus_Fault_Priority;
    SYSPRI1.B.USAGE = Usage_Fault_Priority;
    SYSPRI2.B.SVC = SVCall_Priority;
    SYSPRI3.B.DEBUG = Debug_Monitor_Priority;
    SYSPRI3.B.PENDSV = PendSV_Priority;
    SYSPRI3.B.TICK = SysTick_Priority;

    for (iteratingInt = GPIO_Port_A; iteratingInt <= PWM1_Fault; iteratingInt++)
    {
        if (IntCtrl_InterruptCfg[iteratingInt][IntName] < 0)
        {
            /**If it is reserved keep iterating without assigning any values**/
            u8 i = 0;
            for (i = 0; i <= -(IntCtrl_InterruptCfg[iteratingInt][IntName]); i++)
            {
                IntEnMask <<= 1;
                if (IntEnMask == 0)
                {
                    IntEnMask = 1;
                    RegNo++;
                }
                Prio_i == 3 ? Prio_i = 0, PRI_reg++ : Prio_i++;
                BitNo == 7 ? BitNo = 0 : BitNo++;
                // PrioMask == 0xE0000000 ? (PrioMask = 0x000000E0) : (PrioMask <<= 8);
                iteratingInt++;
            }
            iteratingInt--;
            continue;
        }

#if PRIORITY_GROUPING == XXX
        PrioValue = IntCtrl_InterruptCfg[iteratingInt][Grouping];
#elif PRIORITY_GROUPING == XXY
        PrioValue = (IntCtrl_InterruptCfg[iteratingInt][Grouping] << 1) + IntCtrl_InterruptCfg[iteratingInt].SubGrouping;
#elif PRIORITY_GROUPING == XYY
        PrioValue = (IntCtrl_InterruptCfg[iteratingInt][Grouping] << 2) + IntCtrl_InterruptCfg[iteratingInt].SubGrouping;
#elif PRIORITY_GROUPING == YYY
        PrioValue = IntCtrl_InterruptCfg[iteratingInt][SubGrouping];
#endif

        PRI(PRI_reg).R |= (u32)((PrioValue) << (PrioMask[Prio_i]));

        if (IntCtrl_InterruptCfg[iteratingInt][IntEnable] == ENABLE)
        {
            /*Set its bit in ENx*/
            if (RegNo == 0)
                SET_BIT(EN0.R, BitNo);
            else if (RegNo == 1)
                SET_BIT(EN1.R, BitNo);
            else if (RegNo == 2)
                SET_BIT(EN2.R, BitNo);
            else if (RegNo == 3)
                SET_BIT(EN3.R, BitNo);
            else if (RegNo == 4)
                SET_BIT(EN4.R, BitNo);
        }

        IntEnMask <<= 1;
        if (IntEnMask == 0)
        {
            IntEnMask = 1;
            RegNo++;
        }
        Prio_i == 3 ? Prio_i = 0, PRI_reg++ : Prio_i++;
        BitNo == 31 ? BitNo = 0 : BitNo++;
        // PrioMask == 0xE0000000 ? (PrioMask = 0x000000E0) : (PrioMask <<= 8);
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
