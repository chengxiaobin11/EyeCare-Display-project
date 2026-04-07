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
// ID Code      : RL6851_Series_Global.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

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

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerGlobalDoubleBufferEnable(bit bEn);
void ScalerGlobalIDDomainDBSetTriggerEvent(void);
void ScalerGlobalIDDomainDBApply(EnumDBApply enumDBApply);
void ScalerGlobalDDomainDBApply(EnumDBApply enumDBApply);
void ScalerGlobalIDomainDBApply(EnumDBApply enumDBApply);
void ScalerGlobalDoubleBufferConfigReset(void);
bit ScalerGlobalGetDBStatus(void);
void ScalerGlobalCrystalClkSel(EnumClkSel enumClkSel);

void ScalerGlobalWatchDog(bit bEnable);

#if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)
void ScalerGlobalPreventGarbageByBacklight_EXINT0(void);
#endif
void ScalerGlobalDisplayInitial(void);

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
#if(_HW_M_DOMAIN_IMG_CMP_TYPE == _M_DOMAIN_IMG_CMP_GEN_1)
void ScalerGlobalEnableUnderflowMonitor(bit bEnable);
#endif
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable/Disable double buffer
// Input Value  : bEn --> _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerGlobalDoubleBufferEnable(bit bEn)
{
    ScalerVgipDoubleBufferEnable(bEn);
    ScalerMDomainDisplayTimingGenDBEnable(bEn);
}

//--------------------------------------------------
// Description  : Set I domain double buffer trigger event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGlobalIDDomainDBSetTriggerEvent(void)
{
}

//--------------------------------------------------
// Description  : Set I and D domain double buffer apply
// Input Value  : DB path select, DB apply polling/ no polling/ none
// Output Value : None
//--------------------------------------------------
void ScalerGlobalIDDomainDBApply(EnumDBApply enumDBApply)
{
    if(enumDBApply != _DB_APPLY_NONE)
    {
        // I-domain double buffer apply
        ScalerVgipVgipDoubleBufferApply(enumDBApply);

        // Display timing gen double buffer apply
        ScalerMDomainDisplayTimingGenDBApply(enumDBApply);
    }
}

//--------------------------------------------------
// Description  : Set D domain double buffer apply
// Input Value  : DB apply polling/ no polling/ none
// Output Value : None
//--------------------------------------------------
void ScalerGlobalDDomainDBApply(EnumDBApply enumDBApply)
{
    // Display timing gen double buffer apply
    ScalerMDomainDisplayTimingGenDBApply(enumDBApply);
}

//--------------------------------------------------
// Description  : Set I domain double buffer apply
// Input Value  : DB path select, DB apply polling/ no polling/ none
// Output Value : None
//--------------------------------------------------
void ScalerGlobalIDomainDBApply(EnumDBApply enumDBApply)
{
    // I-domain double buffer apply
    ScalerVgipVgipDoubleBufferApply(enumDBApply);
}

//--------------------------------------------------
// Description  : Global Double Buffer Config Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGlobalDoubleBufferConfigReset(void)
{
    // Enable I-domain double buffer
    ScalerVgipDoubleBufferEnable(_ENABLE);

    // Enable Display timing gen double buffer
    ScalerMDomainDisplayTimingGenDBEnable(_ENABLE);
}

//--------------------------------------------------
// Description  : Get double buffer status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerGlobalGetDBStatus(void)
{
    return _FALSE;
}

//--------------------------------------------------
// Description  : Select internal oscillator Clock.
// Input Value  : IOSC/ Xtal
// Output Value : None
//--------------------------------------------------
void ScalerGlobalCrystalClkSel(EnumClkSel enumClkSel)
{
#if(_WD_TIMER_INT_SUPPORT == _ON)
    BYTE ucWDPreRefClk = ScalerGetByte(P0_09_TOP_POWER_CTRL);
#endif

    if(enumClkSel == _IOSC_CLK)
    {
        // Select at internal Xtal.
        ScalerSetBit(P0_09_TOP_POWER_CTRL, ~_BIT3, _BIT3);

#if(_WD_TIMER_INT_SUPPORT == _ON)
        if((ucWDPreRefClk & _BIT3) == 0x00)
        {
            // Record Global Xtal Clk Has been Switched, WD_Timer INT Ref Clk Change
            SET_GLOBAL_XTAL_CLK_SWITCH(_GLOBAL_XTAL_CLK_SEL_TO_INTERNAL);

            // Manual Trigger WD_Timer INT to Proc WDTimerProc_WDINT
            EXIF = (EXIF & (~_BIT4)) | _BIT4;
        }
        else
        {
            SET_GLOBAL_XTAL_CLK_SWITCH(_GLOBAL_XTAL_CLK_SEL_UNCHANGE);
        }
#endif
    }
    else if(enumClkSel == _EXT_XTAL_CLK)
    {
#if((_LC_TANK_SUPPORT == _ON) && (_XTALESS_SUPPORT == _ON))
        // Select at internal Iosc.
        ScalerSetBit(P0_09_TOP_POWER_CTRL, ~_BIT3, _BIT3);

#if(_WD_TIMER_INT_SUPPORT == _ON)
        if((ucWDPreRefClk & _BIT3) == 0x00)
        {
            // Record Global Xtal Clk Has been Switched, WD_Timer INT Ref Clk Change
            SET_GLOBAL_XTAL_CLK_SWITCH(_GLOBAL_XTAL_CLK_SEL_TO_INTERNAL);

            // Manual Trigger WD_Timer INT to Proc WDTimerProc_WDINT
            EXIF = (EXIF & (~_BIT4)) | _BIT4;
        }
        else
        {
            SET_GLOBAL_XTAL_CLK_SWITCH(_GLOBAL_XTAL_CLK_SEL_UNCHANGE);
        }
#endif
#else
        // Select at external Xtal.
        ScalerSetBit(P0_09_TOP_POWER_CTRL, ~_BIT3, 0x00);

#if(_WD_TIMER_INT_SUPPORT == _ON)
        if((ucWDPreRefClk & _BIT3) == _BIT3)
        {
            // Record Global Xtal Clk Has been Switched, WD_Timer INT Ref Clk Change
            SET_GLOBAL_XTAL_CLK_SWITCH(_GLOBAL_XTAL_CLK_SEL_TO_EXTERNAL);

            // Manual Trigger WD_Timer INT to Proc WDTimerProc_WDINT
            EXIF = (EXIF & (~_BIT4)) | _BIT4;
        }
        else
        {
            SET_GLOBAL_XTAL_CLK_SWITCH(_GLOBAL_XTAL_CLK_SEL_UNCHANGE);
        }
#endif
#endif
    }
}

//--------------------------------------------------
// Description  : Enabel Global Watch Dog
// Input Value  : _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerGlobalWatchDog(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        if(GET_MEMORY_SELECT() == _FRAME_SYNC_LINE_BUFFER)
        {
#if(_PANEL_FREESYNC_FREE_RUN_DVTOTAL_CALCULATED_BY_VFREQ_MIN == _ON)
#if(_DRR_SUPPORT == _ON)
            if(ScalerDrrGetType() == _DRR_NONE_TYPE)
#endif
#endif
            {
                // Set Free Run DVTotal = WD-Triggering DVTotal + 1 to Prevent DVTotal Too Long
                ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_0B_DISPLAY_VER_TOTAL_H, 2, pData, _AUTOINC);
                PDATA_WORD(0) += 1;

                SET_FREE_RUN_DVTOTAL(PDATA_WORD(0));
            }
        }

        // Set Background Color to Black
        ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);

        // Clear Display Vsync Timeout Flag
        ScalerSetByte(P0_0C_WATCH_DOG_CTRL0, 0x01);

        // Enable WD overflow gated
        ScalerSetBit(P0_0D_WATCH_DOG_CTRL1, ~(_BIT7 | _BIT5), (_BIT7 | _BIT5));

#if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)

        // Clear Buffer Status and Input HVsync error flag
        ScalerSetByte(P0_02_STATUS0, 0xFF);

        // Internal IRQ Enable (Global)
        ScalerGlobalIRQControl(_ENABLE);

        // Enable Input HVsync error IRQ and fifo under/overflow IRQ
        ScalerSetBit(P0_04_IRQ_CTRL0, ~(_BIT5 | _BIT1), (_BIT5 | _BIT1));

        EX0 = 1;
#else
        // Disable WD First & Write 1 Clear Display Vertival Time-Out WD Flag
        ScalerSetBit(P30_17_MEAS_HS_VS_DELTA_WD, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P30_18_MEAS_HS_VS_ERROR_WD, ~(_BIT5 | _BIT4), 0x00);
        ScalerSetBit(P30_1C_MEASURE_DUMMY0, ~_BIT7, 0x00);

        // Clear flag
        ScalerSetByte(P0_02_STATUS0, 0xFF);
        ScalerSetBit(P30_16_MEAS_HS_VS_DELTA_IRQ, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        ScalerSetByte(P30_03_MEAS_ERROR_FLG0, 0xFF);

        // Enable Input H/V Error WD & Enable Frame Sync WD & WD Action
        ScalerSetBit(P0_0C_WATCH_DOG_CTRL0, ~(_BIT7 | _BIT5 | _BIT3 | _BIT2 | _BIT1), (_BIT7 | _BIT5 | _BIT3 | _BIT2 | _BIT1));

        // Enable measure overrange WD
#if(_VGA_SUPPORT == _ON)
        // Skip VGA case
        if(ScalerGetBit(P0_10_M1_VGIP_CTRL, (_BIT3 | _BIT2)) != 0x00)
#endif
        {
            ScalerSetBit(P30_17_MEAS_HS_VS_DELTA_WD, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
        }

        // Enable Input H/Vsync overflow WD (analog)
        ScalerSetBit(P30_18_MEAS_HS_VS_ERROR_WD, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

        // Enable Input Vsync timeout WD
        ScalerSetBit(P30_1C_MEASURE_DUMMY0, ~_BIT7, _BIT7);
#endif
    }
    else
    {
#if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)
        // Disable Input HVsync error IRQ and fifo under/overflow IRQ
        ScalerSetBit(P0_04_IRQ_CTRL0, ~(_BIT5 | _BIT1), 0x00);
#else
        // Disable Input H/V Error WD & Enable Frame Sync WD & Input H/Vsync overflow WD
        ScalerSetByte(P0_0C_WATCH_DOG_CTRL0, 0x00);
        ScalerSetBit(P30_17_MEAS_HS_VS_DELTA_WD, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P30_18_MEAS_HS_VS_ERROR_WD, ~(_BIT5 | _BIT4), 0x00);
        ScalerSetBit(P30_1C_MEASURE_DUMMY0, ~_BIT7, 0x00);
#endif
    }
}

#if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)
//--------------------------------------------------
// Description  : Check if fifo underflow or overflow or IHV error, turn off backlight
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGlobalPreventGarbageByBacklight_EXINT0(void) using 1
{
    if(((ScalerGetBit_EXINT(P0_02_STATUS0, (_BIT1 | _BIT0)) != 0x00) && (ScalerGetBit_EXINT(P0_04_IRQ_CTRL0, _BIT1) == _BIT1)) ||
       ((ScalerGetBit_EXINT(P0_02_STATUS0, (_BIT6 | _BIT5)) != 0x00) && (ScalerGetBit_EXINT(P0_04_IRQ_CTRL0, _BIT5) == _BIT5)))
    {
#if(_PANEL_OLED_BACKLIGHT_AC_DET_CONTROL_TYPE == _PANEL_OLED_AC_DET_CTRL_WITHOUT_SEQ)
        PCB_BACKLIGHT_POWER_PIN(_LIGHT_CONTROL_OFF);
#endif

        // Set force to background and free run mode
        ScalerSetBit_EXINT(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~(_BIT5 | _BIT3), _BIT5);

        // Disable Input HVsync error IRQ and fifo under/overflow IRQ
        ScalerSetBit_EXINT(P0_04_IRQ_CTRL0, ~(_BIT5 | _BIT1), 0x00);
    }
}
#endif // End of #if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)

//--------------------------------------------------
// Description  : Global display initial process
// Input Value  : enumDisplayMode --> display mode
// Output Value : None
//--------------------------------------------------
void ScalerGlobalDisplayInitial(void)
{
#if(_FRC_SUPPORT == _ON)
    CLR_MDOMAIN_FRC_CTRL_PARAM_INDEX();
#endif

#if(_FRC_SUPPORT == _ON)
    SET_FRC_MAIN_BW(GET_MEMORY_TOTAL_BW());
    ScalerFRCSpaceInitialAllocation();
#endif

#if(_OD_SUPPORT == _ON)

#if(_FRC_SUPPORT == _ON)
    // Release all FRC bandwidth
    SET_MEMORY_REMAIN_BW(GET_MEMORY_TOTAL_BW()); // unit:100k
#endif

#endif
}

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
#if(_HW_M_DOMAIN_IMG_CMP_TYPE == _M_DOMAIN_IMG_CMP_GEN_1)
//--------------------------------------------------
// Description  :
// Input Value  : bEnable
// Output Value :
//--------------------------------------------------
void ScalerGlobalEnableUnderflowMonitor(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        // Threshold frame cnt: 2 display frames
        ScalerSetByte(P0_CB_UNDERFLOW_MONITOR_1, 0x02);

        // Enable underflow monitor and monitor frame cnt: 2 frame
        ScalerSetByte(P0_CA_UNDERFLOW_MONITOR_0, 0x80);
    }
    else
    {
        // Disable underflow monitor
        ScalerSetByte(P0_CA_UNDERFLOW_MONITOR_0, 0x00);
    }
}
#endif
#endif // End of #if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)


