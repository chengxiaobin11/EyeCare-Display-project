/********************************************************************************/
/*   Copyright (c) 2021 Realtek Semiconductor Corp. All rights reserved.        */
/*                                                                              */
/*   SPDX-License-Identifier: LicenseRef-Realtek-Proprietary                    */
/*                                                                              */
/*   This software component is confidential and proprietary to Realtek         */
/*   Semiconductor Corp. Disclosure, reproduction, redistribution, in whole     */
/*   or in part, of this work and its derivatives without express permission    */
/*   is prohibited.                                                             */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : RL6851_Series_ScalerGlobal.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_GLOBAL__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_WD_TIMER_INT_SUPPORT == _ON)
EnumGlobalXtalClkSelect g_enumGlobalXtalClkSelect = _GLOBAL_XTAL_CLK_SEL_UNCHANGE;
#endif

#if(_FORCE_D_DOMAIN_DB_APPLY == _ON)
#if((_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_II) || (_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_III))
StructGlobalForceDDomainDB g_stGlobalForceDDomainDB;
#endif
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerGlobalIRQControl(bit bEn);
void ScalerGlobalSetIRQControl(BYTE ucIRQControl);
BYTE ScalerGlobalGetIRQControl(void);
void ScalerGlobalWholeChipReset(void);
void ScalerGlobalOsdInitial(void);
void ScalerGlobalResetProc(BYTE ucResetTarget, BYTE ucGetInputPort);
void ScalerGlobalFirstActiveProc(BYTE ucSourceType, BYTE ucGetInputPort);
void ScalerGlobalSystemClkSel(EnumClkSel enumClockSel);

#if(((_OD_SUPPORT == _ON) && (_FRC_SUPPORT == _ON)) || (_XTALESS_SUPPORT == _ON))
void ScalerGlobalSetInterrupt(EnumIRQ enumIRQType, BYTE ucEn);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Set Global IRQ Control Register
// Input Value  : CM_14_IRQ_CTRL0 Register Value
// Output Value : None
//--------------------------------------------------
void ScalerGlobalIRQControl(bit bEn)
{
    if(bEn == _ENABLE)
    {
        ScalerSetBit(P0_04_IRQ_CTRL0, ~_BIT7, _BIT7);
    }
    else
    {
        ScalerSetBit(P0_04_IRQ_CTRL0, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : Set Global IRQ Control Register
// Input Value  : P0_04 and P40_04 register
// Output Value : None
//--------------------------------------------------
void ScalerGlobalSetIRQControl(BYTE ucIRQControl)
{
    ScalerSetByte(P0_04_IRQ_CTRL0, ucIRQControl);
}

//--------------------------------------------------
// Description  : Get Global IRQ Control Register
// Input Value  : None
// Output Value : P0_04 and P40_04 register
//--------------------------------------------------
BYTE ScalerGlobalGetIRQControl(void)
{
    return (ScalerGetByte(P0_04_IRQ_CTRL0));
}

//--------------------------------------------------
// Description  : Scaler Whole Chip Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGlobalWholeChipReset(void)
{
    // Whole chip reset
    ScalerSetBit(P0_01_HOST_CTRL, ~_BIT0, _BIT0);

    // For Delay 10 ms
    ScalerTimerDelayXms(10);

    // Clear to 0
    ScalerSetBit(P0_01_HOST_CTRL, ~_BIT0, 0x00);
}

//--------------------------------------------------
// Description  : Initialize OSD Position Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGlobalOsdInitial(void)
{
    OSD_SET_INITIAL();

    ScalerOsdWriteAllByte(_OSD_SRAM, 0x00, 0x00, 0x00, 0x00);

    ScalerOsdVerticalStartSelect(_OSD_VSYNC_SELECT_DVS);
    ScalerOsdGlobalDoubleBuffer(_DISABLE);

#if(_OSD_POSITION_OFFSET_CORRECTION == _ON)
    ScalerOsdPositionOffsetCorrection();

    // window & font alignment
    ScalerOsdFontWindowVericalAlignemnt(_ENABLE);
    ScalerOsdPositionOffset(_OSD_POSITION_OFFSET_WINDOW, X_POS(_OSD_OFFSET_DRAW_WINDOW_H), Y_POS(_OSD_OFFSET_DRAW_WINDOW_V));

#else

    // Set OSD position global offset
    ScalerOsdPositionOffset(_OSD_POSITION_OFFSET_GLOBAL,
                            (ScalerOsdGetDoubleFunctionH() == _ENABLE) ? X_POS(_OSD_DOUBLE_POSITION_OFFSET_H) : X_POS(_OSD_POSITION_OFFSET_H),
                            (ScalerOsdGetDoubleFunctionV() == _ENABLE) ? Y_POS(_OSD_DOUBLE_POSITION_OFFSET_V) : Y_POS(_OSD_POSITION_OFFSET_V));

#if(_OSD_POSITION_SELF_ALIGNMENT == _ON)
    ScalerOsdFontWindowVericalAlignemnt(_ENABLE);
    ScalerOsdPositionOffset(_OSD_POSITION_OFFSET_WINDOW, X_POS(_OSD_OFFSET_DRAW_WINDOW_H), Y_POS(_OSD_OFFSET_DRAW_WINDOW_V));
#else
    ScalerOsdFontWindowVericalAlignemnt(_DISABLE);
    ScalerOsdPositionOffset(_OSD_POSITION_OFFSET_WINDOW, X_POS(0), Y_POS(0));
#endif

#endif // End of #if(_OSD_POSITION_OFFSET_CORRECTION == _OFF)

#if(_D_DITHER_SUPPORT == _ON)
#if(_D_DITHER_FREERUNEN_SUPPORT == _ENABLE)
    // Reset DDither By Enable Rising Edge Signal
    ScalerColorDDitherEnable(_FUNCTION_OFF);
    ScalerColorDDitherEnable(_FUNCTION_ON);
#endif
#endif
}

//--------------------------------------------------
// Description  : Global Reset Event
// Input Value  : ucResetTarget --> Reset target action
//                ucGetInputPort --> Reset port
// Output Value : None
//--------------------------------------------------
void ScalerGlobalResetProc(BYTE ucResetTarget, BYTE ucGetInputPort)
{
    switch(ucResetTarget)
    {
        case _MODE_ACTION_RESET_TO_SEARCH:

            // Set Background Color to Black
            ScalerDDomainBackgroundSetColor(0, 0, 0);
            ScalerDDomainBackgroundEnable(_ENABLE);

            ScalerGlobalWatchDog(_DISABLE);

#if(_SOURCE_BACKGROUND_DETECT_SUPPORT == _ON)
            ScalerSyncClearActivedPort();
#endif

#if(_VGA_SUPPORT == _ON)
            // Disable Vga Top Double Buffer
            ScalerVgaTopDoubleBufferEnable(_DISABLE);
#endif

            ScalerGlobalDoubleBufferEnable(_DISABLE);

#if(_HW_FRC_TYPE != _FRC_GEN_NONE)
            // FRC Disable M1/M2 Capture/Display
            ScalerFRCEn(_FRC_CAP_DISP_ALL, _DISABLE);
#endif

#if(_FRC_SUPPORT == _ON)
            // Set Frame sync with line buffer mode
            ScalerFRCSetDDomainSourceSelect(_DDOMAIN_SRC_FRAM_FRAME_SYNC_MODE);
#endif

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
            // Reset Functions related to Rotation
            ScalerRotationResetProc();
#endif

#if(_OD_SUPPORT == _ON)
            ScalerODEnable(_FUNCTION_OFF);
#endif

#if(_XTALESS_SUPPORT == _ON)
#if(_LC_TANK_SUPPORT == _ON)
            ScalerGlobalSetInterrupt(_IRQ_DEN_STOP, _DISABLE);
#endif
#endif

            ScalerSyncResetProc(ucGetInputPort);

            // Scaling down initial
            ScalerIDomainScalingDownInitial();

#if(_SDRAM_PHASE_CALIBRATION == _ON)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_SDRAM_PHASE_CNT_CHECK);

#elif(_DDR1_PHASE_CALIBRATION == _ON)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DDR_PHASE_CNT_CHECK);
#endif
            break;

        case _MODE_ACTION_RESET_TO_DISPLAY_SETTING:
        case _MODE_ACTION_RESET_TO_DISPLAY_SETTING_WITHOUT_FORCETOBG:

            if(ucResetTarget == _MODE_ACTION_RESET_TO_DISPLAY_SETTING)
            {
                // Set Background Color to Black
                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                ScalerDDomainBackgroundSetColor(0, 0, 0);
                ScalerDDomainBackgroundEnable(_ENABLE);
            }

            ScalerGlobalWatchDog(_DISABLE);

#if(_SOURCE_BACKGROUND_DETECT_SUPPORT == _ON)
            ScalerSyncClearActivedPort();
#endif

            ScalerGlobalDoubleBufferConfigReset();

#if(_XTALESS_SUPPORT == _ON)
#if(_LC_TANK_SUPPORT == _ON)
            ScalerGlobalSetInterrupt(_IRQ_DEN_STOP, _DISABLE);
#endif
#endif

#if(_SDRAM_PHASE_CALIBRATION == _ON)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_SDRAM_PHASE_CNT_CHECK);

#elif(_DDR1_PHASE_CALIBRATION == _ON)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DDR_PHASE_CNT_CHECK);
#endif
            break;

        case _MODE_ACTION_RESET_TO_POWER_SAVING:
        case _MODE_ACTION_RESET_TO_POWER_OFF:

            // Reset OSD Setting
            ScalerOsdReset();

            // Disable WD
            ScalerGlobalWatchDog(_DISABLE);

#if(_SOURCE_BACKGROUND_DETECT_SUPPORT == _ON)
            ScalerSyncClearActivedPort();
#endif

            // Reset all interface block WD/Irq/Timer Event....
            ScalerSyncResetProc(ucGetInputPort);

#if(_XTALESS_SUPPORT == _ON)
#if(_LC_TANK_SUPPORT == _ON)
            ScalerGlobalSetInterrupt(_IRQ_DEN_STOP, _DISABLE);
#endif
#endif

#if(_SDRAM_PHASE_CALIBRATION == _ON)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_SDRAM_PHASE_CNT_CHECK);

#elif(_DDR1_PHASE_CALIBRATION == _ON)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DDR_PHASE_CNT_CHECK);
#endif
            break;

        default:

            break;
    }

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
    ScalerRotationSetEnable(_DISABLE);
#endif

#if(_OD_SUPPORT == _ON)
    ScalerODEnable(_FUNCTION_OFF);
#endif
}

//--------------------------------------------------
// Description  : Process Required when Switched to Active State
// Input Value  : Input Source
// Output Value : None
//--------------------------------------------------
void ScalerGlobalFirstActiveProc(BYTE ucSourceType, BYTE ucGetInputPort)
{
    ucGetInputPort = ucGetInputPort;

    // Enable Watch Dog
    ScalerGlobalWatchDog(_ENABLE);

#if(_SOURCE_BACKGROUND_DETECT_SUPPORT == _ON)
    ScalerSyncStoreActivedPort(ucGetInputPort);
#endif

    ScalerGlobalDoubleBufferEnable(_ENABLE);

    switch(ucSourceType)
    {
#if(_VGA_SUPPORT == _ON)
        case _SOURCE_VGA:

            // Enable Vga Top Double Buffer
            ScalerVgaTopDoubleBufferEnable(_ENABLE);

            break;
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
        case _SOURCE_DVI:
        case _SOURCE_HDMI:

            ScalerTMDSFirstActiveProc(ucGetInputPort, ucSourceType);

            break;
#endif

#if(_DP_SUPPORT == _ON)
        case _SOURCE_DP:

            ScalerDpFirstActiveProc(ucGetInputPort);

            break;
#endif

        default:
            break;
    }

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
    if(GET_IMG_CMP_ENABLE(GET_IMG_CMP_PARAM()) == _FALSE)
    {
        ScalerImgCmpDecmpPowerControl(_OFF);
    }
#endif
}

//--------------------------------------------------
// Description  : Internal Clock Selection.
// Input Value  : bSel    --> _TRUE: Xtal, _FALSE: M2PLL.
// Output Value : None
//--------------------------------------------------
void ScalerGlobalSystemClkSel(EnumClkSel enumClockSel)
{
    if(enumClockSel == _M2PLL_CLK)
    {
        // System clock select to M2PLL/div.
        ScalerM2PLLDiv(_M2PLL_SYS_DIV);

        // Bit2: Internal Xtal Freq. Select to M2PLL/div
        ScalerSetBit(P0_22_M1_FIFO_CLOCK_SELECT, ~_BIT2, _BIT2);

        // SyncProcessor Clock Select to M2PLL & Set Divider
        ScalerSetBit(P40_06_SYNCPROC_CLK_DIVIDER, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _M2PLL_SYS_DIV));

        // Measure Block Clock Select to M2PLL & Set Divider
        ScalerSetBit(P40_07_MEASURE_CLK_DIVIDER, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _M2PLL_MEASURE_DIV));

        // GDI Clock Select to M2PLL & Set Divider
        ScalerSetBit(P80_06_GDI_CLK_DIVIDER, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _M2PLL_SYS_DIV));
    }
    else
    {
        // Internal Xtal Freq. Select to cystal.
        ScalerSetBit(P0_22_M1_FIFO_CLOCK_SELECT, ~_BIT2, 0x00);

        // Sync Processor Clock select to Xtal
        ScalerSetBit(P40_06_SYNCPROC_CLK_DIVIDER, ~_BIT4, 0x00);

        // Measure Block Clock Select to Xtal
        ScalerSetBit(P40_07_MEASURE_CLK_DIVIDER, ~_BIT4, 0x00);

        // GDI Clock Select to Xtal
        ScalerSetBit(P80_06_GDI_CLK_DIVIDER, ~_BIT4, 0x00);
    }
}

#if(((_OD_SUPPORT == _ON) && (_FRC_SUPPORT == _ON)) || (_XTALESS_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Set IRQ
// Input Value  : En : Enable / Disable
// Output Value : None
//--------------------------------------------------
void ScalerGlobalSetInterrupt(EnumIRQ enumIRQType, BYTE ucEn)
{
    if(ucEn == _ENABLE)
    {
        // Internal IRQ Enable (Global)
        ScalerGlobalIRQControl(_ENABLE);

        // Enable INT0
        EX0 = 1;
    }

    switch(enumIRQType)
    {
        case _IRQ_DVS:
            // Clear DVS IRQ flag
            ScalerSetBit(P0_08_IRQ_CTRL2, ~(_BIT6 | _BIT4 | _BIT2), _BIT4);

            // Enable/Disable DVS IRQ
            ScalerSetBit(P0_08_IRQ_CTRL2, ~(_BIT6 | _BIT5 | _BIT4 | _BIT2), (ucEn << 5));
            break;

        case _IRQ_DEN_START:
            // Clear DEN start IRQ flag
            ScalerSetBit(P0_05_IRQ_CTRL1, ~(_BIT6 | _BIT4 | _BIT2), _BIT2);

            // Enable/Disable DEN start IRQ
            ScalerSetBit(P0_05_IRQ_CTRL1, ~(_BIT6 | _BIT4 | _BIT3 | _BIT2), (ucEn << 3));
            break;

        case _IRQ_DEN_STOP:
            // Clear DEN stop IRQ flag
            ScalerSetBit(P0_05_IRQ_CTRL1, ~(_BIT6 | _BIT4 | _BIT2), _BIT4);

            // Enable/Disable DEN stop IRQ
            ScalerSetBit(P0_05_IRQ_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT2), (ucEn << 5));
            break;

        default:
            // For compiler warning
            ucEn = ucEn;
            break;
    }
}
#endif // End of #if(_OD_SUPPORT == _ON)

