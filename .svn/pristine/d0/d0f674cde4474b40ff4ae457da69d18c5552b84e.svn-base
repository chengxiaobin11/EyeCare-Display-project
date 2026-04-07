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
// ID Code      : RL6851_Series_ScalerMemory.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_MEMORY__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if(_SHARPNESS_SUPPORT == _ON)
#define _SHARPNESS_TABLE_SIZE                       (128)
#endif


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
#if(_SHARPNESS_SUPPORT == _ON)
void ScalerMemorySetScalingCoef(BYTE code *pucAddress1, BYTE code *pucAddress2, BYTE ucBankNum);
#endif

void ScalerMemoryInitial(void);

#if(_LAST_LINE_FINETUNE_ENABLE == _ENABLE)
void ScalerMemoryCompensateDtForLastLine(DWORD ulTargetLastLine, DWORD ulCurrentLastLine);
#endif

void ScalerMemoryUpdateIVS2DVSLineDelay(DWORD ulCompsIVS2DVSpixel);
void ScalerMemorySetIVS2DVSLineDelay(WORD usIVS2DVSDelay);
void ScalerMemoryFineTuneIVS2DVSDelay(WORD usOldIVS2DVSDelay, WORD usNewIVS2DVSDelay, WORD usIVS2DVSChgLimit);
DWORD ScalerMemoryGetDtMaxMin(void);
WORD ScalerMemoryGetScaleUpDt(void);

#if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)
void ScalerMemoryReset(void);
void ScalerMemoryPowerControl(bit bOnOff);
#endif


#if(_FRC_SUPPORT == _ON)
void ScalerMemorySetFrameTrackingEnable(bit bEn);
bit ScalerMemoryGetFrameTrackingEnable(void);
void ScalerMemoryFrameTracking(void);
WORD ScalerMemoryGetMNRatio(void);
#endif

#if(_OD_SUPPORT == _ON)
#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
void ScalerMemorySetODThreeBlockAddress(void);
#endif
#endif

#if(_DT_RANGE_TEST_SUPPORT == _ON)
void ScalerMemoryDtRangeInitial(void);
void ScalerMemoryDtRangeTest(void);
void ScalerMemoryDtRangeScan(void);
void ScalerMemoryDtRangePrintFWDt(void);
DWORD ScalerMemoryDtRangeRealDt(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_SHARPNESS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Scale Up coef
// Input Value  : H/V coef table, length
// Output Value : none
//--------------------------------------------------
void ScalerMemorySetScalingCoef(BYTE code *pucAddress1, BYTE code *pucAddress2, BYTE ucBankNum)
{
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    // Set Coefficient table 1
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(pucAddress1, _SHARPNESS_TABLE_SIZE, ucBankNum, P0_36_USER_DEF_FILTER_ACCESS_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Set Coefficient table 2
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(pucAddress2, _SHARPNESS_TABLE_SIZE, ucBankNum, P0_36_USER_DEF_FILTER_ACCESS_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);


    // Disable Coefficient Access, Set HSU to use coefficient table 1 & set VSU to use coefficient table 2
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);
}
#endif

//--------------------------------------------------
// Description  : M Domain Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMemoryInitial(void)
{
#if(_MEMORY_TYPE_CONFIG == _MEMORY_SDRAM)
    //------------------------------
    // SDRAM Initial
    //------------------------------
#endif

#if(_MEMORY_TYPE_CONFIG == _MEMORY_DDR1)
    //------------------------------
    // DDR1 Initial
    //------------------------------
#endif

#if(_MEMORY_TYPE_CONFIG == _MEMORY_DDR3)
    //------------------------------
    // DDR3 Initial
    //------------------------------
#endif

#if(_HW_FRC_TYPE != _FRC_GEN_NONE)
    //------------------------------
    // FRC Initial
    //------------------------------
    ScalerFRCInitial();
#endif

#if(_OD_SUPPORT == _ON)
    //------------------------------
    // OD Initial
    //------------------------------
    ScalerODSetMemoryStartAddress();
#endif

#if(_FREESYNC_SUPPORT == _ON)
    //------------------------------
    // Free Sync Initial
    //------------------------------
    ScalerMemorySetShiftOneLine(GET_FREESYNC_ENABLED());
#endif
}

#if(_LAST_LINE_FINETUNE_ENABLE == _ENABLE)
//--------------------------------------------------
// Description  : Compensate Last Line Fine Tune
// Input Value  : Target Last Line, Current Last Line
// Output Value : None
//--------------------------------------------------
void ScalerMemoryCompensateDtForLastLine(DWORD ulTargetLastLine, DWORD ulCurrentLastLine)
{
    DWORD ulCompsIVS2DVSpixel = 0;

    // Get Initial Dt Fine Tune Value
    PDATA_DWORD(0) = ScalerMemoryGetIVS2DVSDelayPixel();

    DebugMessageFS("Original Dt", PDATA_DWORD(0));

    // Compensate Dt = Original Dt + ((Target Last Line - Current Last Line) * DVHeight / DVTotal * IVHeight / DVHeight * IHTotal / DHTotal) / 2
    {
        SDWORD lCompsIVS2DVSpixel = (SDWORD)PDATA_DWORD(0) + ((((SDWORD)ulTargetLastLine - (SDWORD)ulCurrentLastLine) * GET_MDOMAIN_INPUT_VHEIGHT() / GET_MDOMAIN_OUTPUT_VTOTAL() * GET_MDOMAIN_INPUT_HTOTAL() / GET_MDOMAIN_OUTPUT_HTOTAL()) >> 1);

        if(lCompsIVS2DVSpixel >= 0)
        {
            ulCompsIVS2DVSpixel = (DWORD)lCompsIVS2DVSpixel;
        }
        else
        {
            DebugMessageFS("Compensated Dt can't be negative !!!!!", lCompsIVS2DVSpixel);
        }
    }
    DebugMessageFS("Last Line Difference", ((SDWORD)ulTargetLastLine - (SDWORD)ulCurrentLastLine));
    DebugMessageFS("Dt Compensate Value", (((SDWORD)ulTargetLastLine - (SDWORD)ulCurrentLastLine) * g_stMDomainInputData.usVHeight / g_stMDomainOutputData.usVTotal * g_stMDomainInputData.usHTotal / g_stMDomainOutputData.usHTotal) >> 1);

    DebugMessageFS("Compensated Dt", ulCompsIVS2DVSpixel);
    ScalerMemoryUpdateIVS2DVSLineDelay(ulCompsIVS2DVSpixel);
}
#endif

//--------------------------------------------------
// Description  : Set IVS2DVS Delay (line)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMemoryUpdateIVS2DVSLineDelay(DWORD ulCompsIVS2DVSpixel)
{
    BYTE ucEOshift = 0;
#if(_FORMAT_CONVERSION_SUPPORT == _ON)
    if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
    {
        ucEOshift = 1;
    }
#endif

    ulCompsIVS2DVSpixel = ulCompsIVS2DVSpixel >> ucEOshift;

    if((ScalerGetBit(P0_43_FS_DELAY_FINE_TUNE, _BIT1) == _BIT1) &&
       (ulCompsIVS2DVSpixel >= (((g_stMDomainInputData.usHTotal >> 1) + 64) >> ucEOshift)))
    {
        // Preserve 0.5 lines + 64 pixel in Fine Tune Byte
        PDATA_WORD(2) = (ulCompsIVS2DVSpixel - (((g_stMDomainInputData.usHTotal >> 1) + 64) >> ucEOshift)) / g_stMDomainInputData.usHTotal;
        PDATA_WORD(3) = (ulCompsIVS2DVSpixel - ((DWORD)g_stMDomainInputData.usHTotal * PDATA_WORD(2))) >> 4;

        if(_VSU_INI_PHASE_LINES == _VSU_3_LINE)
        {
            PDATA_WORD(4) = (ulCompsIVS2DVSpixel + (g_stMDomainInputData.usHTotal >> (1 + ucEOshift)) - ((DWORD)g_stMDomainInputData.usHTotal * PDATA_WORD(2))) >> 4;
        }
        else
        {
            PDATA_WORD(4) = (ulCompsIVS2DVSpixel - (g_stMDomainInputData.usHTotal >> (1 + ucEOshift)) - ((DWORD)g_stMDomainInputData.usHTotal * PDATA_WORD(2))) >> 4;
        }
        pData[10] = (ulCompsIVS2DVSpixel - ((DWORD)g_stMDomainInputData.usHTotal * PDATA_WORD(2)) - (PDATA_WORD(3) << 4));
        pData[11] = (ulCompsIVS2DVSpixel - ((DWORD)g_stMDomainInputData.usHTotal * PDATA_WORD(2)) - (PDATA_WORD(4) << 4));
    }
    else
    {
        PDATA_WORD(2) = ulCompsIVS2DVSpixel / g_stMDomainInputData.usHTotal;
        PDATA_WORD(3) = ulCompsIVS2DVSpixel - ((DWORD)g_stMDomainInputData.usHTotal * PDATA_WORD(2)) >> 4;
        PDATA_WORD(4) = 0x0000;
        pData[10] = (ulCompsIVS2DVSpixel - ((DWORD)g_stMDomainInputData.usHTotal * PDATA_WORD(2)) - (PDATA_WORD(3) << 4));
        pData[11] = 0x00;
    }

    //-------------------------------------------------
    // Apply updated Delay
    //-------------------------------------------------
    // IVS2DVS line delay, unit: line
    ScalerSetByte(P0_3E_IVS2DVS_DLY_LINE_H, (pData[4] & 0x1F));
    ScalerSetByte(P0_40_IVS2DVS_DLY_LINE_L, pData[5]);

    // IVS2DVS 16iclk1 delay, unit: 16 pixel
    PDATA_WORD(3) -= (PDATA_WORD(3) >= 1) ? 1 : 0;
    SET_IVS2DVS_DELAY_16ICLK1(PDATA_WORD(3));

    // IVS2DVS 16iclk2 delay, unit: 16 pixel
    PDATA_WORD(4) -= (PDATA_WORD(4) >= 1) ? 1 : 0;
    SET_IVS2DVS_DELAY_16ICLK2(PDATA_WORD(4));

    // IVS2DVS iclk1 delay, unit: 1 pixel
    ScalerSetBit(P0_3D_IV_DV_DELAY_CLK_FINE, ~0xF0, ((pData[10] & 0x0F) << 4));

    // IVS2DVS iclk2 delay, unit: 1 pixel
    ScalerSetBit(P0_3D_IV_DV_DELAY_CLK_FINE, ~0x0F, (pData[11] & 0x0F));
}

//--------------------------------------------------
// Description  : Set IVS2DVS Delay (line)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMemorySetIVS2DVSLineDelay(WORD usIVS2DVSDelay)
{
#if(_FORMAT_CONVERSION_SUPPORT == _ON)
    if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
    {
        usIVS2DVSDelay = (usIVS2DVSDelay >> 1);
    }
#endif

    // IVS2DVS delay setting min=0x01
    if(usIVS2DVSDelay == 0)
    {
        usIVS2DVSDelay = 0x01;
    }

    ScalerSetByte(P0_3E_IVS2DVS_DLY_LINE_H, (HIBYTE(usIVS2DVSDelay) & 0x1F));
    ScalerSetByte(P0_40_IVS2DVS_DLY_LINE_L, LOBYTE(usIVS2DVSDelay));
}

//--------------------------------------------------
// Description  : IVS2DVS Delay Finetune
// Input Value  : Old IVS2DVS Delay/ New IVS2DVS Delay/ IVS2DVS Change limit
// Output Value : None
//--------------------------------------------------
void ScalerMemoryFineTuneIVS2DVSDelay(WORD usOldIVS2DVSDelay, WORD usNewIVS2DVSDelay, WORD usIVS2DVSChgLimit)
{
    WORD usDVTotalFrameSync = 0;
    WORD usDVTotalFreeRun = 0;
    WORD usRemainIVS2DVSDelay = 0;
    BYTE ucTimeoutCounter = 255;

    // Set Frame Sync Mode Delay Fine Tune = 0
    SET_IVS2DVS_DELAY_16ICLK1(0x0000);
    SET_IVS2DVS_DELAY_16ICLK2(0x0000);

    if(ScalerGetBit(P0_10_M1_VGIP_CTRL, _BIT1) == _BIT1)
    {
        // Avoid (Current_IVStart + IVHeight) > IVToal + New_IVSDelay in digital capture
        PDATA_WORD(0) = (g_stInputTimingData.usVStart + ScalerVgipGetCaptureVStartPosition() + g_stMDomainInputData.usVHeight);
    }
    else
    {
        // Avoid (Current_IVSDelay + IVStart + IVHeight) > IVToal + New_IVSDelay in analog capture
        PDATA_WORD(0) = (ScalerVgipGetCaptureVDelay() + ScalerVgipGetCaptureVStartPosition() + g_stMDomainInputData.usVHeight);
    }

    if(PDATA_WORD(0) > g_stMDomainInputData.usVTotal)
    {
        ScalerMemorySetIVS2DVSLineDelay(usNewIVS2DVSDelay);
        return;
    }

    // IVS2DVS delay from small to large
    if((usOldIVS2DVSDelay + ScalerVgipGetCaptureVDelay()) < (usNewIVS2DVSDelay + GET_VGIP_INITIAL_VDELAY()))
    {
        usRemainIVS2DVSDelay = (usNewIVS2DVSDelay + GET_VGIP_INITIAL_VDELAY()) - (usOldIVS2DVSDelay + ScalerVgipGetCaptureVDelay());

        while(usRemainIVS2DVSDelay > usIVS2DVSChgLimit)
        {
            usRemainIVS2DVSDelay -= usIVS2DVSChgLimit;
            usOldIVS2DVSDelay += usIVS2DVSChgLimit;

            ScalerMemorySetIVS2DVSLineDelay(usOldIVS2DVSDelay);
            ScalerGlobalIDomainDBApply(_DB_APPLY_POLLING);

            if(ucTimeoutCounter == 0)
            {
                break;
            }

            ucTimeoutCounter--;
        }

        ScalerMemorySetIVS2DVSLineDelay(usNewIVS2DVSDelay);
    }
    else if((usOldIVS2DVSDelay + ScalerVgipGetCaptureVDelay()) > (usNewIVS2DVSDelay + GET_VGIP_INITIAL_VDELAY()))
    {
        // Get Frame Sync DVtotal
        ScalerSetBit(P0_43_FS_DELAY_FINE_TUNE, ~_BIT5, 0x00);
        ScalerSetBit(P0_44_LAST_LINE_H, ~_BIT7, _BIT7);
        GET_DVTOTAL_LASTLINE(usDVTotalFrameSync);

        // IVS2DVS  diff (D_line)
        usRemainIVS2DVSDelay = (usOldIVS2DVSDelay + ScalerVgipGetCaptureVDelay()) - (usNewIVS2DVSDelay + GET_VGIP_INITIAL_VDELAY());
        usRemainIVS2DVSDelay = (DWORD)usRemainIVS2DVSDelay * g_stMDomainOutputData.usVBackHeight / g_stMDomainInputData.usVHeight;

        // Select smaller between measure DVtotal & Calculate DVtotal
        PDATA_WORD(0) = (usDVTotalFrameSync < g_stMDomainOutputData.usVTotal) ? usDVTotalFrameSync : g_stMDomainOutputData.usVTotal;

        // Display front porch
        PDATA_WORD(1) = (PDATA_WORD(0) > (g_stMDomainOutputData.usVBackHeight + g_stMDomainOutputData.usVStart)) ? (PDATA_WORD(0) - (g_stMDomainOutputData.usVBackHeight + g_stMDomainOutputData.usVStart)) : 0;

        // (IVS2DVS diff >= Display front porch) or (transient DVtotal < DVtotal min)
        if((usRemainIVS2DVSDelay >= PDATA_WORD(1)) || ((PDATA_WORD(0) - usRemainIVS2DVSDelay) <= _PANEL_DV_TOTAL_MIN))
        {
            // IVS2DVS delay from large to small --> small_IVS2DVS + IVtotal - large_IVS2DVS
            usRemainIVS2DVSDelay = (usNewIVS2DVSDelay + GET_VGIP_INITIAL_VDELAY()) + g_stMDomainInputData.usVTotal - (usOldIVS2DVSDelay + ScalerVgipGetCaptureVDelay());

            while((usRemainIVS2DVSDelay > usIVS2DVSChgLimit) && ((usOldIVS2DVSDelay + usIVS2DVSChgLimit) < g_stMDomainInputData.usVTotal))
            {
                usRemainIVS2DVSDelay -= usIVS2DVSChgLimit;
                usOldIVS2DVSDelay += usIVS2DVSChgLimit;

                ScalerMemorySetIVS2DVSLineDelay(usOldIVS2DVSDelay);
                ScalerGlobalIDomainDBApply(_DB_APPLY_POLLING);

                if(ucTimeoutCounter == 0)
                {
                    break;
                }

                ucTimeoutCounter--;
            }

            // Back up Free run DVtotal
            usDVTotalFreeRun = GET_FREE_RUN_DVTOTAL();

            if((usRemainIVS2DVSDelay > usIVS2DVSChgLimit) && ((usOldIVS2DVSDelay + usIVS2DVSChgLimit) >= g_stMDomainInputData.usVTotal))
            {
                usRemainIVS2DVSDelay -= usIVS2DVSChgLimit;
                usOldIVS2DVSDelay = usOldIVS2DVSDelay + usIVS2DVSChgLimit - g_stMDomainInputData.usVTotal;

                PDATA_WORD(7) = ((DWORD)g_stMDomainInputData.usVTotal + usIVS2DVSChgLimit) * usDVTotalFrameSync / g_stMDomainInputData.usVTotal + 1;

                SET_FREE_RUN_DVTOTAL(PDATA_WORD(7));

                ScalerGlobalDDomainDBApply(_DB_APPLY_POLLING);

                ScalerTimerWaitForEvent(_EVENT_DVS);

                // Set to free-run mode
                ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~_BIT3, 0x00);

                if(usRemainIVS2DVSDelay > usIVS2DVSChgLimit)
                {
                    usRemainIVS2DVSDelay -= usIVS2DVSChgLimit;
                    usOldIVS2DVSDelay += usIVS2DVSChgLimit;

                    ScalerTimerWaitForEvent(_EVENT_IEN_START);
                    ScalerMemorySetIVS2DVSLineDelay(usOldIVS2DVSDelay);
                    ScalerGlobalIDomainDBApply(_DB_APPLY_NO_POLLING);

                    ScalerTimerWaitForEvent(_EVENT_IEN_START);
                    ScalerTimerWaitForEvent(_EVENT_IVS);

                    // Set to frame-sync mode
                    ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~_BIT3, _BIT3);

                    while(usRemainIVS2DVSDelay > usIVS2DVSChgLimit)
                    {
                        usRemainIVS2DVSDelay -= usIVS2DVSChgLimit;
                        usOldIVS2DVSDelay += usIVS2DVSChgLimit;

                        ScalerMemorySetIVS2DVSLineDelay(usOldIVS2DVSDelay);
                        ScalerGlobalIDomainDBApply(_DB_APPLY_POLLING);

                        if(ucTimeoutCounter == 0)
                        {
                            break;
                        }

                        ucTimeoutCounter--;
                    }

                    ScalerMemorySetIVS2DVSLineDelay(usNewIVS2DVSDelay);
                }
                else
                {
                    ScalerTimerWaitForEvent(_EVENT_IEN_START);
                    ScalerMemorySetIVS2DVSLineDelay(usNewIVS2DVSDelay);
                    ScalerGlobalIDomainDBApply(_DB_APPLY_NO_POLLING);

                    ScalerTimerWaitForEvent(_EVENT_IEN_START);
                    ScalerTimerWaitForEvent(_EVENT_IVS);

                    // Set to frame-sync mode
                    ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~_BIT3, _BIT3);
                }
            }
            else if((usRemainIVS2DVSDelay <= usIVS2DVSChgLimit) && ((usOldIVS2DVSDelay + usIVS2DVSChgLimit) >= g_stMDomainInputData.usVTotal))
            {
                PDATA_WORD(7) = ((DWORD)g_stMDomainInputData.usVTotal * 2 - usOldIVS2DVSDelay + usNewIVS2DVSDelay) * usDVTotalFrameSync / g_stMDomainInputData.usVTotal + 1;

                SET_FREE_RUN_DVTOTAL(PDATA_WORD(7));

                ScalerGlobalDDomainDBApply(_DB_APPLY_POLLING);

                ScalerTimerWaitForEvent(_EVENT_DVS);

                // Set to free-run mode
                ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~_BIT3, 0x00);

                ScalerTimerWaitForEvent(_EVENT_IEN_START);

                ScalerMemorySetIVS2DVSLineDelay(usNewIVS2DVSDelay);
                ScalerGlobalIDomainDBApply(_DB_APPLY_NO_POLLING);

                ScalerTimerWaitForEvent(_EVENT_IEN_START);
                ScalerTimerWaitForEvent(_EVENT_IVS);

                // Set to frame-sync mode
                ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~_BIT3, _BIT3);
            }
            else
            {
                ScalerMemorySetIVS2DVSLineDelay(usNewIVS2DVSDelay);
                DebugMessageFS("Error condition", 0);
            }

            SET_FREE_RUN_DVTOTAL(usDVTotalFreeRun);
        }
        else
        {
            ScalerMemorySetIVS2DVSLineDelay(usNewIVS2DVSDelay);
        }
    }

    DebugMessageFS("Timeout counter", ucTimeoutCounter);
}

//--------------------------------------------------
// Description  : Calculate Dt Max/Min Value for Scale Up
// Input Value  : None
// Output Value : Calculated Max/Min Dt in 0.01 Lines
//--------------------------------------------------
DWORD ScalerMemoryGetDtMaxMin(void)
{
    BYTE ucMax = 0;
    BYTE ucMin = 100;
    BYTE ucCount = 0;
    BYTE ucPhase = 0;
    WORD usDtMin = 0;
    WORD usDtMax = 0;
    WORD usSUF = 0;
    WORD usFIFOHWidth = 0;
    WORD usDt = 0;
    DWORD ulVFCI = 0;

    // Get Ver filter coef initial value: VFCI * 128
    GET_VER_FILTER_COEF_INI(ulVFCI);

    DebugMessageFS("7.ulVFCI", ulVFCI);

    // Since MSB would be Eliminated by Mod, Only WORD is Required
    usSUF = (WORD)(((DWORD)g_stMDomainInputData.usVHeight << 13) / g_stMDomainOutputData.usVHeight);

    // Get Min and Max Value
    do
    {
        // (VFCI + n * VSF) mod 1
        ucPhase = (BYTE)(((WORD)ulVFCI + (((WORD)ucCount * usSUF) >> 6)) & 0x7F);

        if(ucPhase > ucMax)
        {
            ucMax = ucPhase;
        }

        if(ucPhase < ucMin)
        {
            ucMin = ucPhase;
        }

        ucCount++;
    }
    while(ucCount < 255);

    DebugMessageFS("7.Calculated Max", ucMax);
    DebugMessageFS("7.Calculated Min", ucMin);

    //-------------------------------------------------
    // Get FIFO Input Width: 13 bit
    //-------------------------------------------------
    usFIFOHWidth = ScalerMemoryGetFifoWidth();

    // VFCI * 100
    ulVFCI = (ulVFCI * 100) >> 7;

#if(_FORMAT_CONVERSION_SUPPORT == _ON)
    if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
    {
        // DtMin = 1  +(VFCI-min)/2+ VSF/2 - VSF*DHActiveEnd/DHTotal/2
        usDtMin = 100 + (ulVFCI >> 1) - (((WORD)ucMin * 100) >> 8) + (DWORD)g_stMDomainInputData.usVHeight  * 50 / g_stMDomainOutputData.usVHeight - (DWORD)g_stMDomainInputData.usVHeight * (g_stMDomainOutputData.usHStart + g_stMDomainOutputData.usHWidth) / g_stMDomainOutputData.usVHeight * 50 / g_stMDomainOutputData.usHWidth;
        usDtMin = usDtMin << 1;

        // DtMax = 1 + FIFODepth/FIFOHWidth each(max-VFCI)/2 each VSF*(DHActiveStart/DHTotal)
        usDtMax = 100 + (DWORD)_M_DOMAMAIN_FIFO_BIT / GET_MEMORY_DATA_BIT() * 100 / usFIFOHWidth + (ulVFCI >> 1) - (((WORD)ucMax * 100) >> 8) - (DWORD)g_stMDomainInputData.usVHeight * g_stMDomainOutputData.usHStart / g_stMDomainOutputData.usVHeight * 50 / g_stMDomainOutputData.usHTotal;
        usDtMax = usDtMax << 1;
    }
    else
#endif
    {
        // Dt min = 2 + (VFCI - min - VSF * DHActiveEnd / DHTotal)
        usDtMin = 200 + ulVFCI - (((WORD)ucMin * 100) >> 7) - (DWORD)g_stMDomainInputData.usVHeight * (g_stMDomainOutputData.usHStart + g_stMDomainOutputData.usHWidth) / g_stMDomainOutputData.usVHeight * 100 / g_stMDomainOutputData.usHTotal;

        // Dt max = 2 + FIFODepth / FIFOWIDTH - max + VFCI - VSF * DHActiveSt / DHTotal
        usDtMax = 200 + (DWORD)_M_DOMAMAIN_FIFO_BIT / GET_MEMORY_DATA_BIT() * 100 / usFIFOHWidth - (((WORD)ucMax * 100) >> 7) + ulVFCI - (DWORD)g_stMDomainInputData.usVHeight * g_stMDomainOutputData.usHStart / g_stMDomainOutputData.usVHeight * 100 / g_stMDomainOutputData.usHTotal;
    }
    DebugMessageFS("7. DtMax", usDtMax);
    DebugMessageFS("7. DtMin", usDtMin);

    if(GET_D_DOMAIN_REQUEST() == _7_LINES_BEFORE_DEN)
    {
        usDt = ((DWORD)_M_DOMAMAIN_FIFO_BIT / GET_MEMORY_DATA_BIT() * 90 / usFIFOHWidth + (DWORD)g_stMDomainInputData.usVHeight * 700 / g_stMDomainOutputData.usVHeight);

        if(usDtMax > usDt)
        {
            usDtMax = usDt;
            DebugMessageFS("7. dt max modifyed", usDtMax);
        }
    }

    return (((DWORD)usDtMax << 16) | usDtMin);
}

//--------------------------------------------------
// Description  : Calculate Dt Value for Scale Up
// Input Value  : None
// Output Value : Calculated Dt in 0.01 Lines
//--------------------------------------------------
WORD ScalerMemoryGetScaleUpDt(void)
{
    WORD usDtMin = 0;
    WORD usDtMax = 0;
    WORD usDt = 0;
    DWORD ulDtMaxMin = ScalerMemoryGetDtMaxMin();

    usDtMin = LOWORD(ulDtMaxMin);
    usDtMax = HIWORD(ulDtMaxMin);

    usDt = (usDtMax + usDtMin) / 2;
    DebugMessageFS("7. Target Dt Value", usDt);

// VSD Dt compensation
#if(_ULTRA_VIVID_SUPPORT == _ON)
    if(GET_V_SCALE_DOWN() == _TRUE)
    {
        if(g_stMDomainInputData.usVHeight > g_stMDomainOutputData.usVHeight)
        {
            usDt = GET_DWORD_MUL_DIV(usDt, g_stMDomainInputData.usVHeight, g_stMDomainOutputData.usVHeight);
            DebugMessageFS("2. VSD Target Dt Value new", usDt);
        }
    }

    // IVh=1080, DVh=1200, Dt target is lower than Dt lower bound
    if((GET_INPUT_TIMING_VHEIGHT() == 1080) && (_PANEL_DV_HEIGHT == 1200))
    {
        usDt += 50;
    }
#endif

    // Calculat (I porch - 2)
    PDATA_WORD(0) = (g_stMDomainInputData.usVTotal > (g_stMDomainInputData.usVHeight + 2)) ? (g_stMDomainInputData.usVTotal - (g_stMDomainInputData.usVHeight + 2)) : 0;

    // Dt must small than (I portch - 2)
    if(usDt >= (PDATA_WORD(0) * 100))
    {
        usDt = ((PDATA_WORD(0) * 100) + usDtMin) / 2;
        DebugMessageFS("7. Target Dt Value new", usDt);
    }

    return usDt;
}

#if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)
//--------------------------------------------------
// Description  : Memory Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMemoryReset(void)
{
#if(_MEMORY_TYPE_CONFIG == _MEMORY_SDRAM)
    ScalerTimerWaitForEvent(_EVENT_IEN_STOP);
    ScalerSdramControlReset();
#elif(_MEMORY_TYPE_CONFIG == _MEMORY_DDR1)
    ScalerTimerWaitForEvent(_EVENT_IEN_STOP);
    ScalerDDR1ControlReset();
#elif(_MEMORY_TYPE_CONFIG == _MEMORY_DDR2)
    // DDR Reset
#elif(_MEMORY_TYPE_CONFIG == _MEMORY_DDR3)
    // DDR Reset
#endif
}

//--------------------------------------------------
// Description  : Memory Power Control
// Input Value  :
// Output Value :
//--------------------------------------------------
void ScalerMemoryPowerControl(bit bOnOff)
{
    if(bOnOff == _ON)
    {
        ScalerFRCPowerOnInitial();
    }
}
#endif // End of #if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)

#if(_FRC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : M:N frame tracking
// Input Value  : En: enable / disable
// Output Value : None
//--------------------------------------------------
void ScalerMemorySetFrameTrackingEnable(bit bEn)
{
    // Enable/Disable M:N frame tracking function
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_25_MN_FRAME_RATE_EN, ~_BIT7, (BYTE)bEn << 7);
}

//--------------------------------------------------
// Description  : Get M:N frame tracking status
// Input Value  : None
// Output Value : _TRUE if enabled
//--------------------------------------------------
bit ScalerMemoryGetFrameTrackingEnable(void)
{
    if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_25_MN_FRAME_RATE_EN, _BIT7) != 0)
    {
        return _ENABLE;
    }

    return _DISABLE;
}

//--------------------------------------------------
// Description  : Set M:N frame tracking
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMemoryFrameTracking(void)
{
    BYTE ucM = 1;
    BYTE ucN = 1;

    if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_25_MN_FRAME_RATE_EN, _BIT7) == _BIT7)
    {
        return;
    }

    // Measure DVtotal in frame sync mode
    ScalerSetBit(P0_43_FS_DELAY_FINE_TUNE, ~_BIT5, 0x00);
    ScalerSetBit(P0_44_LAST_LINE_H, ~_BIT7, _BIT7);

    // Wait IVS for get correct data
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);

    PDATA_WORD(0) = ScalerMemoryGetMNRatio();

    ucM = (PDATA_WORD(0) >> 8) & 0xFF;
    ucN = PDATA_WORD(0) & 0xFF;

    // Read DVTotal result
    GET_DVTOTAL_LASTLINE(PDATA_WORD(1));

    // Set to read last line result
    ScalerSetBit(P0_44_LAST_LINE_H, ~_BIT7, 0x00);

    // Read Last line result
    GET_DVTOTAL_LASTLINE(PDATA_WORD(0));
    PDATA_WORD(0) = (PDATA_WORD(0) << _D_DOMAIN_PATH);

    // Calulate Display total pixel: DHtotal * DVtotal + last line
    PDATA_DWORD(1) = (DWORD)GET_MDOMAIN_OUTPUT_HTOTAL() * PDATA_WORD(1) + (PDATA_WORD(0));

    // Fine tune MN frame sync last line
#if(_MN_FINE_TUNE_LASTLINE_SUPPORT == _OFF)
    if(((PDATA_DWORD(1) * ucM) % GET_MDOMAIN_OUTPUT_HTOTAL()) > ((DWORD)GET_MDOMAIN_OUTPUT_HTOTAL() * 90 / 100))
    {
        // Free run DVtotal
        PDATA_WORD(1) = (PDATA_DWORD(1) * ucM) / GET_MDOMAIN_OUTPUT_HTOTAL() / ucN + 1;

        // Free run Last line
        PDATA_WORD(0) = ((PDATA_DWORD(1) * ucM) % GET_MDOMAIN_OUTPUT_HTOTAL()) / ucN;
    }
    else if(((PDATA_DWORD(1) * ucM) % GET_MDOMAIN_OUTPUT_HTOTAL()) < ((DWORD)GET_MDOMAIN_OUTPUT_HTOTAL() * 10 / 100))
    {
        // Free run DVtotal
        PDATA_WORD(1) = ((PDATA_DWORD(1) * ucM) - GET_MDOMAIN_OUTPUT_HTOTAL()) / GET_MDOMAIN_OUTPUT_HTOTAL() / ucN + 1;

        // Free run Last line
        PDATA_WORD(0) = (((PDATA_DWORD(1) * ucM) % GET_MDOMAIN_OUTPUT_HTOTAL()) + GET_MDOMAIN_OUTPUT_HTOTAL()) / ucN;
    }
    else
#endif // End of #if(_MN_FINE_TUNE_LASTLINE_SUPPORT == _OFF)
    {
        // Free run DVtotal
        PDATA_WORD(1) = PDATA_DWORD(1) * ucM / GET_MDOMAIN_OUTPUT_HTOTAL() / ucN;

        // Free run Last line
        PDATA_WORD(0) = GET_MDOMAIN_OUTPUT_HTOTAL();
    }

    if(PDATA_WORD(1) < (g_stMDomainOutputData.usVStart + g_stMDomainOutputData.usVHeight))
    {
        DebugMessageFRC("FrameTrack-DVT-Error", PDATA_WORD(1));
        PDATA_WORD(1) = _PANEL_DV_TOTAL;
    }

    // Set DVTotal
    SET_FREE_RUN_DVTOTAL(PDATA_WORD(1));

    // Set Frame Sync Watch Dog
    SET_DIS_TIMING_GEN_WD_VTOTAL(PDATA_WORD(1) + 64);

    // Lase line to be multiple of output port
    PDATA_WORD(2) = PDATA_WORD(0) - (PDATA_WORD(0) % _DHTOTAL_MULTIPLE);

    // Set Last line
    SET_FREE_RUN_LAST_LINE(PDATA_WORD(2));

    // Set M:N frame tracking function
    // Set ivs skipped, M = register value +1
    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_26_M_FOR_MN_FRAME_RATE);
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (ucM - 1));
    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_27_N_FOR_MN_FRAME_RATE);
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (ucN - 1));
}

//--------------------------------------------------
// Description  : Get M:N ratio
// Input Value  : None
// Output Value : M << 8 | N
//--------------------------------------------------
WORD ScalerMemoryGetMNRatio(void)
{
    BYTE ucM = 1;
    BYTE ucN = 1;

    switch(GET_MEMORY_DVF_SELECT())
    {
        case _2_IVF:

            ucM = 1;
            ucN = 2;

            break;

        case _3_IVF:

            ucM = 1;
            ucN = 3;

            break;

        case _2_5_IVF:

            ucM = 2;
            ucN = 5;

            break;
#if(_DISPLAY_ROTATION_SUPPORT == _ON)
#if((_DISPLAY_ROTATION_TYPE == _DISPLAY_ROTATION_GEN_II) && (_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON))
        case _5_4_IVF:

            ucM = 5;
            ucN = 4;

            break;

        case _6_5_IVF:

            ucM = 6;
            ucN = 5;

            break;
#endif
#endif
        default:

            break;
    }

    return ((ucM << 8) | (ucN));
}
#endif // End of #if(_FRC_SUPPORT == _ON)

#if(_OD_SUPPORT == _ON)
#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set OD address in 3-block-toggle case
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMemorySetODThreeBlockAddress(void)
{
    // 24->60Hz / 24->72Hz uses HW auto 3 block toggle
    if(GET_FRC_3BLOCK_TOGGLE_STATUS() == _ENABLE)
    {
        DWORD ulBlockAddr = 0;
        DWORD ulTotalMemSpace = 0;
        DWORD ulODUseSpace = 0;

        ulTotalMemSpace = (DWORD)_MEMORY_ROW << _FW_MEM_ROW_ADDR_SHIFT_BIT_NUM;
        ulODUseSpace = (ScalerODGetMemoryUsagePerPath(GET_OD_USE_BIT()) / _MEMORY_BIT_NUM / (_MEMORY_COL_PER_BANK * _MEMORY_BANK) + 1) << _FW_MEM_ROW_ADDR_SHIFT_BIT_NUM;

        //=========================================
        // Set OD 1st Address
        //=========================================
        // Get 1st Write Address
        ulBlockAddr = _FRC_R_2ND_BLOCK_STA_ADDR;
        g_ulMemoryThreeBlockAddr1 = (ulBlockAddr + ulTotalMemSpace - ulODUseSpace) % ulTotalMemSpace;

        //=========================================
        // Set OD 2nd Address
        //=========================================
        // Get 2nd Write Address
        ulBlockAddr = _FRC_R_3RD_BLOCK_STA_ADDR;
        g_ulMemoryThreeBlockAddr2 = (ulBlockAddr + ulTotalMemSpace - ulODUseSpace) % ulTotalMemSpace;

        //=========================================
        // Set OD 3rd Address
        //=========================================
        // Get 3rd Write Address
        ulBlockAddr = _FRC_R_1ST_BLOCK_STA_ADDR;
        g_ulMemoryThreeBlockAddr3 = (ulBlockAddr + ulTotalMemSpace - ulODUseSpace) % ulTotalMemSpace;

        DebugMessageFRC("OD 3Blk-1st Addr", g_ulMemoryThreeBlockAddr1);
        DebugMessageFRC("OD 3Blk-2nd Addr", g_ulMemoryThreeBlockAddr2);
        DebugMessageFRC("OD 3Blk-3rd Addr", g_ulMemoryThreeBlockAddr3);
    }
    else
    {
        g_ulMemoryThreeBlockAddr1 = (DWORD)_OD_PATH_INIT_ROW_ADDR << _FW_MEM_ROW_ADDR_SHIFT_BIT_NUM;
        g_ulMemoryThreeBlockAddr2 = g_ulMemoryThreeBlockAddr1;
        g_ulMemoryThreeBlockAddr3 = g_ulMemoryThreeBlockAddr1;
    }
}
#endif // End of #if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
#endif // End of #if(_OD_SUPPORT == _ON)

#if(_DT_RANGE_TEST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Initialize for Dt Scan
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMemoryDtRangeInitial(void)
{
    WORD usDHwidth = 0;
    WORD usDVheight = 0;

    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerSetByte(P0_02_STATUS0, 0xFF);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    if(ScalerGetBit(P0_02_STATUS0, (_BIT1 | _BIT0)) != 0x00)
    {
        DebugMessageAutoTest(" Frame sync ERROR ", 0);
        DebugMessageAutoTest("---- Dt Scan Fail -----", 0);
        return;
    }

    ScalerGlobalWatchDog(_DISABLE);
    ScalerGlobalDoubleBufferEnable(_DISABLE);

    // Disable video compensation
    ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~(_BIT7 | _BIT5), _BIT5);
    ScalerSetBit(P0_43_FS_DELAY_FINE_TUNE, ~_BIT1, 0x00);

    // disable double buffer
    ScalerGlobalDoubleBufferEnable(_DISABLE);

    ScalerTimerWaitForEvent(_EVENT_IVS);

    usDHwidth = (ScalerGetDataPortWord(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_07_DISPLAY_HOR_ACT_END_H, _AUTOINC) & _13_BIT);
    usDHwidth -= (ScalerGetDataPortWord(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_05_DISPLAY_HOR_ACT_STA_H, _AUTOINC) & _13_BIT);

    usDVheight = (ScalerGetDataPortWord(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_12_DISPLAY_VER_ACT_END_H, _AUTOINC) & _13_BIT);
    usDVheight -= (ScalerGetDataPortWord(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_10_DISPLAY_VER_ACT_STA_H, _AUTOINC) & _13_BIT);

    DebugMessageAutoTest("3. IHFreq", GET_MDOMAIN_INPUT_HFREQ());
    DebugMessageAutoTest("3. IHTotal", GET_MDOMAIN_INPUT_HTOTAL());
    DebugMessageAutoTest("3. IHStart", GET_MDOMAIN_INPUT_HSTART());
    DebugMessageAutoTest("3. IHWidth", GET_MDOMAIN_INPUT_HWIDTH());

    DebugMessageAutoTest("3. IVFreq", GET_MDOMAIN_INPUT_VFREQ());
    DebugMessageAutoTest("3. IVTotal", GET_MDOMAIN_INPUT_VTOTAL());
    DebugMessageAutoTest("3. IVStart", GET_MDOMAIN_INPUT_VSTART());
    DebugMessageAutoTest("3. IVHeight", GET_MDOMAIN_INPUT_VHEIGHT());

    DebugMessageAutoTest("3. DHtotal", GET_DIS_TIMING_GEN_H_TOTAL());
    DebugMessageAutoTest("3. DHWidth", usDHwidth);
    DebugMessageAutoTest("3. DVheight", usDVheight);
}

//--------------------------------------------------
// Description  : Test the Upper/Lower Bound for Dt
// Input Value  : usVheight: fifo Vheight
// Output Value : None
//--------------------------------------------------
void ScalerMemoryDtRangeTest(void)
{
#if(_ULTRA_VIVID_SUPPORT == _ON)
    DebugMessageAutoTest("3. ========================START========================", GET_MEMORY_DATA_BIT());

    // Enable LSR
    ScalerSetByte(P14_C0_LSR_CTRL, 0x80);
    ScalerMDomainControlDBApply();

    DebugMessageAutoTest("3. LSR_ENABLE", ScalerGetByte(P14_C0_LSR_CTRL));

    ScalerMemoryDtRangeScan();
    DebugMessageAutoTest("3. ========================END========================", 0);
#endif

    DebugMessageAutoTest("3. ========================START========================", GET_MEMORY_DATA_BIT());
    ScalerSetByte(P14_C0_LSR_CTRL, 0x00);
    ScalerMDomainControlDBApply();


    DebugMessageAutoTest("3. LSR_ENABLE", ScalerGetByte(P14_C0_LSR_CTRL));

    ScalerMemoryDtRangeScan();
    DebugMessageAutoTest("3. ========================END========================", 0);
}

//--------------------------------------------------
// Description  : Test the Upper/Lower Bound for Dt
// Input Value  : usVheight: fifo Vheight
// Output Value : None
//--------------------------------------------------
void ScalerMemoryDtRangeScan(void)
{
    BYTE ucNum = 50;
    WORD usBackupIVst = GET_MDOMAIN_INPUT_VSTART();
    WORD usBackupIvsDelay = ScalerVgipGetCaptureVDelay();
    WORD usBackupDVst = GET_MDOMAIN_OUTPUT_VSTART();

    if(GET_MEMORY_CONFIG() == _MEMORY_WORK_MODE)
    {
        DebugMessageAutoTest("Frame Buffer", ScalerMemoryDtRangeRealDt());
        return;
    }

    ScalerMemoryDtRangeInitial();
    ScalerMemoryDtRangePrintFWDt();

    DebugMessageAutoTest("3. RealDt", ScalerMemoryDtRangeRealDt());
    DebugMessageAutoTest("3. -------------------------", 0);

    if(ScalerGetBit(P0_02_STATUS0, (_BIT1 | _BIT0)) != 0x00)
    {
        DebugMessageAutoTest("Fail", 0);
        return;
    }

    ucNum = 50;
    while((ScalerGetBit(P0_02_STATUS0, (_BIT1 | _BIT0)) == 0x00) && (ucNum > 0))
    {
        ucNum -= 1;
        ScalerMemoryFrameSyncSetDt(ucNum);
        ScalerMDomainSetDisplayTimingGen();

        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);

        // clear overflow/unferflow flags
        ScalerSetByte(P0_02_STATUS0, 0xFF);

        // clear display line buffer busy flag
        ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~_BIT5, _BIT5);

        // Wait for 2 DVS for flag update status
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }

    ucNum += 1;
    ScalerMemoryFrameSyncSetDt(ucNum);
    ScalerMDomainSetDisplayTimingGen();

    ScalerSetByte(P0_02_STATUS0, 0xFF);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    DebugMessageAutoTest("3. Dt_lower", ScalerMemoryDtRangeRealDt());
    DebugMessageAutoTest("3. -------------------------", 0);

    // restore original ivst, dvst
    SET_MDOMAIN_INPUT_VSTART(usBackupIVst);
    SET_MDOMAIN_OUTPUT_VSTART(usBackupDVst);
    SET_MDOMAIN_OUTPUT_VBSTART(usBackupDVst);

    if(ScalerVgipGetDigitalCaptureStatus() == _FALSE)
    {
        // Set new IVSt under analog capture
        ScalerVgipSetCaptureVStartPosition(GET_MDOMAIN_INPUT_VSTART());
        ScalerVgipSetCaptureVDelay(usBackupIvsDelay);
    }

    ucNum = 50;
    ScalerMemoryFrameSyncSetDt(ucNum);
    ScalerMDomainSetDisplayTimingGen();

    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);

    // clear overflow/unferflow flags
    ScalerSetByte(P0_02_STATUS0, 0xFF);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    while((ScalerGetBit(P0_02_STATUS0, (_BIT1 | _BIT0)) == 0x00) && (ucNum < 100))
    {
        ucNum += 1;
        ScalerMemoryFrameSyncSetDt(ucNum);
        ScalerMDomainSetDisplayTimingGen();

        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);

        // clear overflow/unferflow flags
        ScalerSetByte(P0_02_STATUS0, 0xFF);

        // clear display line buffer busy flag
        ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~_BIT5, _BIT5);

        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }

    ucNum -= 1;
    ScalerMemoryFrameSyncSetDt(ucNum);
    ScalerMDomainSetDisplayTimingGen();

    ScalerSetByte(P0_02_STATUS0, 0xFF);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);

    DebugMessageAutoTest("3. Dt_upper", ScalerMemoryDtRangeRealDt());
    DebugMessageAutoTest("3. -------------------------", 0);

    // restore original ivst, dvst
    SET_MDOMAIN_INPUT_VSTART(usBackupIVst);
    SET_MDOMAIN_OUTPUT_VSTART(usBackupDVst);
    SET_MDOMAIN_OUTPUT_VBSTART(usBackupDVst);

    if(ScalerVgipGetDigitalCaptureStatus() == _FALSE)
    {
        // Set new IVSt under analog capture
        ScalerVgipSetCaptureVStartPosition(GET_MDOMAIN_INPUT_VSTART());
        ScalerVgipSetCaptureVDelay(usBackupIvsDelay);
    }

    ScalerMemoryFrameSyncSetDt(50);
    ScalerMDomainSetDisplayTimingGen();

    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);

    // clear overflow/unferflow flags
    ScalerSetByte(P0_02_STATUS0, 0xFF);

    // Clear Display Vsync timeout flag
    ScalerSetBit(P0_0C_WATCH_DOG_CTRL0, ~_BIT0, _BIT0);

    // clear display line buffer busy flag
    ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~_BIT5, _BIT5);

    // Wait for 2 DVS for flag status update
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerTimerWaitForEvent(_EVENT_DVS);
}

//--------------------------------------------------
// Description  : Get Real Dt From Register
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMemoryDtRangePrintFWDt(void)
{
    WORD usDtMin = 0;
    WORD usDtMax = 0;
    DWORD ulDtMaxMin = ScalerMemoryGetDtMaxMin();

    usDtMin = (WORD)(ulDtMaxMin & 0xFFFF);
    usDtMax = (WORD)((ulDtMaxMin >> 16) & 0xFFFF);

    if((usDtMax == 0) || (usDtMin == 0))
    {
        usDtMax = 0;
        usDtMin = 0;
    }

    DebugMessageAutoTest("3. Dtmax", usDtMax);
    DebugMessageAutoTest("3. Dtmin", usDtMin);
    DebugMessageAutoTest("5. DtTarget", (usDtMin + usDtMax) / 2);
}
//--------------------------------------------------
// Description  : Get Real Dt From Register
// Input Value  : None
// Output Value : None
//--------------------------------------------------
DWORD ScalerMemoryDtRangeRealDt(void)
{
    DWORD ulIVStoDVSPixels = 0;
    WORD usIVS2DVSdelayP0_40 = 0;
    WORD usIVS2DVSdelayP0_41 = 0;
    DWORD ulIVstartPixel = 0;
    DWORD ulDVstartPixel = 0;
    WORD usDHst = 0;
    WORD usDVst = 0;
    WORD usDVheight = 0;
    WORD usDHtotal = 0;

    usDHtotal = GET_DIS_TIMING_GEN_H_TOTAL();

    usDHst = ScalerGetDataPortWord(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_05_DISPLAY_HOR_ACT_STA_H, _AUTOINC);
    usDVst = ScalerGetDataPortWord(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_10_DISPLAY_VER_ACT_STA_H, _AUTOINC);
    usDVheight = ScalerMDomainGetDisplayVheight();

    usIVS2DVSdelayP0_40 = (((WORD)ScalerGetByte(P0_3E_IVS2DVS_DLY_LINE_H) << 8) & 0x1F00) | ScalerGetByte(P0_40_IVS2DVS_DLY_LINE_L);
    usIVS2DVSdelayP0_41 = (((WORD)ScalerGetByte(P0_3F_DISPLAY_ALIGN_CONTROL) << 4) & 0x300) | ScalerGetByte(P0_41_IVS2DVS_DLY_TUNE_ODD);
    ulIVStoDVSPixels = ScalerMemoryGetIVS2DVSDelayPixel();

    DebugMessageAutoTest("3. -------------------------", 0);
    DebugMessageAutoTest("3. P0_40", usIVS2DVSdelayP0_40);
    DebugMessageAutoTest("3. P0_41", usIVS2DVSdelayP0_41);

    DebugMessageAutoTest("3. Dvst_line", usDVst);
    DebugMessageAutoTest("3. IVst_line", g_stMDomainInputData.usVStart);

    DebugMessageAutoTest("3. IVS_delay", ScalerGetByte(P0_1C_M1_IVS_DELAY));

    DebugMessageAutoTest("3. ulIVStoDVSPixels", ulIVStoDVSPixels);

    ulDVstartPixel = ((DWORD)usDHtotal * usDVst) + usDHst;
    ulDVstartPixel = ulDVstartPixel * g_stMDomainInputData.usVHeight / usDVheight * g_stMDomainInputData.usHTotal / usDHtotal;
    DebugMessageAutoTest("3. ulDVstartPixel", ulDVstartPixel);

    // Calculate IVS to IH Active in ICLK
    ulIVstartPixel = ((DWORD)g_stMDomainInputData.usHTotal * g_stMDomainInputData.usVStart) + g_stMDomainInputData.usHStart;
    DebugMessageAutoTest("3. ulIVstartPixel", ulIVstartPixel);

    return ((DWORD)(ulDVstartPixel + ulIVStoDVSPixels - ulIVstartPixel) * 100 / g_stMDomainInputData.usHTotal);
}
#endif // End of #if(_DT_RANGE_TEST_SUPPORT == _ON)

