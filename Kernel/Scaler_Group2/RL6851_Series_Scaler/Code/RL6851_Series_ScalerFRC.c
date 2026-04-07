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
// ID Code      : RL6851_Series_ScalerFRC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#define __SCALER_FRC__

#include "ScalerFunctionInclude.h"

#if(_FRC_SUPPORT == _ON)
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
#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
BYTE g_ucDispLatecnyRatio;
#endif
#if(_ASPECT_RATIO_WITHOUT_MUTE == _ON)
WORD g_usAspectRatioMinDVHeight;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
WORD ScalerFRCGetIVS2DVSDelayMax(void);
#endif

WORD ScalerFRCCalculatePreReadLine(void);
void ScalerFRCAdjustIVS2DVSDelay(void);
BYTE ScalerFRCIVS2DVSDelayMargin(void);

#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
void ScalerFRCSetDisplayAutoBlkToggle(void);
void ScalerFRCSetDisplayAutoBlkToggleEnable(bit bEn);
void ScalerFRCSetHWAutoBlockToggle(void);
void ScalerFRCSetInputAutoBlkToggle(void);
#endif
#if(_ASPECT_RATIO_WITHOUT_MUTE == _ON)
void ScalerFRCSetAspectRatioDDomain(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get IVS2DVSDelay Max Value in Frame Sync Mode
// Input Value  : usFRCVerSize : Input VHeight
// Output Value : IVS2DVSDelay Max Value
//--------------------------------------------------
WORD ScalerFRCGetIVS2DVSDelayMax(void)
{
    WORD usDHF = 0x00;
    WORD usIPeriod = 0x00;
    WORD usDStartPeriod = 0x00;

    if(ScalerMDomainMemorySelectConfirm() == _FRAME_SYNC_MEMORY)
    {
        // DHFreq
        usDHF = ((DWORD)GET_D_CLK_FREQ() * 10 / GET_MDOMAIN_OUTPUT_HTOTAL());

        // (IVStart + IDEN) Period
        usIPeriod = (GET_MDOMAIN_INPUT_VSTART() + GET_MDOMAIN_INPUT_VHEIGHT());

        // Pre-read Period
        usDStartPeriod = ((DWORD)ScalerFRCCalculatePreReadLine() * GET_MDOMAIN_INPUT_HFREQ() / usDHF);

        return (usIPeriod - (usDStartPeriod + _FRC_IVS2DVSDELAY_MARGIN));
    }

    return 0;
}
#endif // End of #if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Calculate FRC Pre-read Line
// Input Value  : usFRCVerSize --> FRC Output Vertical Size
// Output Value : The line after DVS that FRC display start to access
//--------------------------------------------------
WORD ScalerFRCCalculatePreReadLine(void)
{
    // preread: 4 line
    // preread = 0: 1 line after DVS rising
    WORD usFRCVerSize = _PRE_READ_MEMORY + 1;

    return ((GET_MDOMAIN_OUTPUT_VSTART() > usFRCVerSize) ? ((GET_MDOMAIN_OUTPUT_VSTART() - usFRCVerSize)) : (0));
}

//--------------------------------------------------
// Description  : Adjust IVS2DVS Delay for Aspect Ratio Function
// Input Value  : usFRCVerSize : FRC Veritcal Size
// Output Value : None
//--------------------------------------------------
void ScalerFRCAdjustIVS2DVSDelay(void)
{
    DWORD ulIVStoDVSPixels = 0;
    WORD usIVS2DVSDelay = 0;
#if(_ASPECT_RATIO_WITHOUT_MUTE == _ON)
    WORD usVstbk = GET_MDOMAIN_OUTPUT_VSTART();
    WORD usVHeightbk = GET_MDOMAIN_OUTPUT_VHEIGHT();
    WORD usVBHeightbk = GET_MDOMAIN_OUTPUT_VBHEIGHT();
#endif

    BYTE ucMargin = ScalerFRCIVS2DVSDelayMargin();
    WORD usPreReadLine = ScalerFRCCalculatePreReadLine();
    WORD usIHFreq = 0;
    WORD usDHFreq = 0;

#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
    WORD usDelayMax = 0;
#endif
    usIHFreq = ScalerMeasureGetHFreq();
    DebugMessageFRC("FRC IHF 0.01k", usIHFreq);

    // DHFreq, unit: 0.01kHz
    usDHFreq = ((DWORD)GET_D_CLK_FREQ() * 100 / GET_MDOMAIN_OUTPUT_HTOTAL());

    switch(GET_MEMORY_SELECT())
    {
        case _FRAME_SYNC_MEMORY:

            // IVS2DVS line skip disable
            ScalerSetBit(P0_43_FS_DELAY_FINE_TUNE, ~_BIT3, _BIT3);
#if(_ASPECT_RATIO_WITHOUT_MUTE == _ON)
            ScalerFRCSetAspectRatioDDomain();
#endif
#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
            usDelayMax = ScalerFRCGetIVS2DVSDelayMax();
#endif
            // Consider IDEN period and (DDEN + pre-read) period
            if(GET_MDOMAIN_INPUT_VHEIGHT() >= ((DWORD)(GET_MDOMAIN_OUTPUT_VSTART() + GET_MDOMAIN_OUTPUT_VHEIGHT() - usPreReadLine) * usIHFreq / usDHFreq))
            {
                // (IVStart + IDEN) Period
                PDATA_WORD(0) = (GET_MDOMAIN_INPUT_VSTART() + GET_MDOMAIN_INPUT_VHEIGHT());

                // (DVStart + DDEN) Period
                PDATA_WORD(1) = ((DWORD)(GET_MDOMAIN_OUTPUT_VSTART() + GET_MDOMAIN_OUTPUT_VHEIGHT()) * usIHFreq / usDHFreq);
            }
            else
            {
                // IVStart Period
                PDATA_WORD(0) = GET_MDOMAIN_INPUT_VSTART();

                // FRC_Display pre-read Period
                PDATA_WORD(1) = (DWORD)usPreReadLine * usIHFreq / usDHFreq;
            }

            if(PDATA_WORD(0) > PDATA_WORD(1))
            {
                usIVS2DVSDelay = PDATA_WORD(0) - PDATA_WORD(1) + ucMargin;
            }
            else
            {
                usIVS2DVSDelay = ucMargin;
            }

            PDATA_WORD(1) = ((GET_MDOMAIN_INPUT_VSTART() + ucMargin) > ((DWORD)usPreReadLine * usIHFreq / usDHFreq)) ? ((GET_MDOMAIN_INPUT_VSTART() + ucMargin) - ((DWORD)usPreReadLine * usIHFreq / usDHFreq)) : 0;

            if(PDATA_WORD(1) > usIVS2DVSDelay)
            {
                usIVS2DVSDelay = PDATA_WORD(1);
            }

#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
            PDATA_WORD(1) = ((DWORD)usDelayMax - usIVS2DVSDelay) * GET_DISP_LATENCY_RATIO() / 100;
            usIVS2DVSDelay += PDATA_WORD(1);
#endif
            // ivs2dvsdelay must be smaller than IVTotal when frame sync
            if(usIVS2DVSDelay >= GET_MDOMAIN_INPUT_VTOTAL())
            {
                usIVS2DVSDelay = GET_MDOMAIN_INPUT_VTOTAL() - 1;
            }
            break;

        case _FREE_RUN_MEMORY:

            usIVS2DVSDelay = (GET_MDOMAIN_INPUT_VTOTAL() + GET_MDOMAIN_INPUT_VSTART() + GET_MDOMAIN_INPUT_VHEIGHT());
            usIVS2DVSDelay -= ((DWORD)(GET_MDOMAIN_OUTPUT_VSTART() + GET_MDOMAIN_OUTPUT_VHEIGHT()) * usIHFreq / usDHFreq);

            if(usIVS2DVSDelay > 255)
            {
                usIVS2DVSDelay = 0xFE - 32;
            }
            else
            {
                usIVS2DVSDelay -= 32;
            }

            break;

        default:
        case _MN_FRAME_SYNC_MEMORY:

#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
            switch(GET_MEMORY_DVF_SELECT())
            {
                case _6_5_IVF:
                case _5_4_IVF:

                    usIVS2DVSDelay = GET_MDOMAIN_INPUT_VSTART() + GET_MDOMAIN_INPUT_VHEIGHT() - ((DWORD)usPreReadLine * usIHFreq / usDHFreq) + 1;

                    break;

                case _2_5_IVF:

                    // lower bound : dvtotal+dvstart+dvheight+ivs2dvsdelay > ivstart + ivheight
                    usIVS2DVSDelay = GET_MDOMAIN_INPUT_VSTART() + GET_MDOMAIN_INPUT_VHEIGHT();
                    usIVS2DVSDelay -= ((DWORD)(GET_MDOMAIN_OUTPUT_VTOTAL() + GET_MDOMAIN_OUTPUT_VSTART() + GET_MDOMAIN_OUTPUT_VHEIGHT()) * usIHFreq / usDHFreq);

                    // upper bound : 3 * dvtotal+dvstart+ivs2dvsdelay < IVtotal + ivstart + ivheight/2
                    PDATA_WORD(1) = GET_MDOMAIN_INPUT_VTOTAL() + GET_MDOMAIN_INPUT_VSTART() + (GET_MDOMAIN_INPUT_VHEIGHT() / 2);
                    PDATA_WORD(1) -= ((DWORD)((GET_MDOMAIN_OUTPUT_VTOTAL() * 3) + GET_MDOMAIN_OUTPUT_VSTART()) * usIHFreq / usDHFreq);

                    usIVS2DVSDelay = (usIVS2DVSDelay + PDATA_WORD(1)) / 2;

                    break;

                default:

                    usIVS2DVSDelay = 0x01;
                    break;
            }
#else
            usIVS2DVSDelay = 0x01;
#endif
            break;
    }

    if((usIVS2DVSDelay > 0xF00) || (usIVS2DVSDelay == 0))
    {
        usIVS2DVSDelay = 0x01;
    }

    // Disable Frame Sync Fine Tune
    ScalerSetBit(P0_43_FS_DELAY_FINE_TUNE, ~_BIT1, 0x00);

    ulIVStoDVSPixels = (DWORD)usIVS2DVSDelay * GET_MDOMAIN_INPUT_HTOTAL();

    if(GET_MEMORY_SELECT() == _FRAME_SYNC_MEMORY)
    {
        if(ScalerMDomainGetFrameSyncMode() == _FRAME_SYNC_MODE)
        {
            // Convert DVline limit to IVline
            WORD usIVS2DVSChgLimit = ((DWORD)_PANEL_DV_LINE_CHG_LIMIT * GET_MDOMAIN_OUTPUT_HTOTAL() / GET_D_CLK_FREQ() * GET_MDOMAIN_INPUT_HFREQ() / 10) +
                                     ((DWORD)_PANEL_DV_LINE_CHG_LIMIT * GET_MDOMAIN_OUTPUT_HTOTAL() % GET_D_CLK_FREQ() * GET_MDOMAIN_INPUT_HFREQ() / 10 / GET_D_CLK_FREQ());

            // Get Old IVS2DVS + IVSdelay (I line)
            PDATA_WORD(0) = (ScalerMemoryGetIVS2DVSDelayPixel() / GET_MDOMAIN_INPUT_HTOTAL());

            ScalerMemoryFineTuneIVS2DVSDelay(PDATA_WORD(0), (ulIVStoDVSPixels / GET_MDOMAIN_INPUT_HTOTAL()), usIVS2DVSChgLimit);
        }

        PDATA_WORD(2) = ulIVStoDVSPixels / GET_MDOMAIN_INPUT_HTOTAL();
        PDATA_WORD(3) = (ulIVStoDVSPixels - ((DWORD)GET_MDOMAIN_INPUT_HTOTAL() * PDATA_WORD(2))) >> 4;
        PDATA_WORD(4) = 0x0000;

        pData[10] = (ulIVStoDVSPixels - ((DWORD)GET_MDOMAIN_INPUT_HTOTAL() * PDATA_WORD(2)) - (PDATA_WORD(3) << 4));
        pData[11] = 0x00;

        //-------------------------------------------------
        // Apply updated Delay
        //-------------------------------------------------
        // IVS2DVS line delay, unit: line
        ScalerSetByte(P0_3E_IVS2DVS_DLY_LINE_H, (HIBYTE(PDATA_WORD(2)) & 0x1F));
        ScalerSetByte(P0_40_IVS2DVS_DLY_LINE_L, LOBYTE(PDATA_WORD(2)));

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
    else
    {
        ScalerMemorySetIVS2DVSLineDelay((ulIVStoDVSPixels / GET_MDOMAIN_INPUT_HTOTAL()));

        // Set Frame Sync Mode Delay Fine Tune = 0
        SET_IVS2DVS_DELAY_16ICLK1(0x0000);
        SET_IVS2DVS_DELAY_16ICLK2(0x0000);
    }

#if(_ASPECT_RATIO_WITHOUT_MUTE == _ON)
    SET_MDOMAIN_OUTPUT_VSTART(usVstbk);
    SET_MDOMAIN_OUTPUT_VHEIGHT(usVHeightbk);
    SET_MDOMAIN_OUTPUT_VBHEIGHT(usVBHeightbk);
#endif
}

//--------------------------------------------------
// Description  : Calculate IVS2DVS delay margin
// Input Value  : N.A.
// Output Value : IVS2DVS delay margin
//--------------------------------------------------
BYTE ScalerFRCIVS2DVSDelayMargin(void)
{
#if(_DRR_SUPPORT == _ON)
    if(ScalerDrrGetType() != _DRR_NONE_TYPE)
    {
        WORD usIHwidth = GET_MDOMAIN_INPUT_HWIDTH();
        BYTE ucDataBit = GET_MEMORY_DATA_BIT();
        BYTE ucIMCLatency = 0;

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
        if(GET_IMG_CMP_ENABLE(GET_IMG_CMP_PARAM()) == _ENABLE)
        {
            ucDataBit = GET_IMG_CMP_PARAM_LLB(GET_IMG_CMP_PARAM());
            ucIMCLatency = _IMC_LATENCY;
        }
#endif
        // Margin need to consider Fifo margin, line buffer margin and setting margin
        // Fifo margin: FIFO size/ format/ IHwidth * 2
        pData[0] = ((DWORD)_M_DOMAMAIN_FIFO_BIT / ucDataBit / usIHwidth);
        pData[0] += ((((DWORD)_M_DOMAMAIN_FIFO_BIT / ucDataBit % usIHwidth) != 0x00) ? 1 : 0);

        pData[0] += (_FRC_IVS2DVSDELAY_LINE_BUFFER_MARGIN + _FRC_IVS2DVSDELAY_MARGIN_FREESYNC + ucIMCLatency);
    }
    else
#endif
    {
        pData[0] = _FRC_IVS2DVSDELAY_MARGIN;
    }

    return pData[0];
}

#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set display adderss for auto block toggle
// Input Value  : ulBlockStep --> block step(single frame input and display)
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetDisplayAutoBlkToggle(void)
{
    ScalerFRCSetDispAddress(_FRC_1ST_BLOCK, _FRC_R_1ST_BLOCK_STA_ADDR);
    ScalerFRCSetDispAddress(_FRC_2ND_BLOCK, _FRC_R_2ND_BLOCK_STA_ADDR);
    ScalerFRCSetDispAddress(_FRC_3RD_BLOCK, _FRC_R_3RD_BLOCK_STA_ADDR);
}

//--------------------------------------------------
// Description  : Set display adderss for auto block toggle
// Input Value  : En: enable / disable
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetDisplayAutoBlkToggleEnable(bit bEn)
{
    // Enable M:N HW auto toggle's double buffer
    ScalerSetBit(P5_4B_CAP_M1_MN, ~_BIT1, _BIT1);

    if(bEn == _ENABLE)
    {
        ScalerSetBit(P5_4B_CAP_M1_MN, ~_BIT5, _BIT5);

        // Input Hardware auto toggle address enable
        ScalerSetBit(P5_4B_CAP_M1_MN, ~_BIT0, _BIT0);

        // Display Hardware auto toggle among address enable
        ScalerSetBit(P5_E4_DISP_M1_MN_TOG_EN, ~_BIT3, _BIT3);
    }
    else
    {
        ScalerSetBit(P5_4B_CAP_M1_MN, ~_BIT5, 0x00);

        // Input Hardware auto toggle address disable
        ScalerSetBit(P5_4B_CAP_M1_MN, ~_BIT0, 0x00);

        // Display Hardware auto toggle among address disable
        ScalerSetBit(P5_E4_DISP_M1_MN_TOG_EN, ~_BIT3, 0x00);
    }

    // Hardware auto toggle M:N double buffer ready
    ScalerSetBit(P5_4B_CAP_M1_MN, ~_BIT2, _BIT2);

    // Wait dobule buffer
    ScalerTimerPollingFlagProc(_M_N_AUTO_BLK_TOGGLE_STABLE_TIME, P5_4B_CAP_M1_MN, _BIT2, 0);
}

//--------------------------------------------------
// Description  : Set auto block toggle
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetHWAutoBlockToggle(void)
{
    BYTE ucM = 1;
    BYTE ucN = 1;

    PDATA_WORD(0) = ScalerMemoryGetMNRatio();

    ucM = (PDATA_WORD(0) >> 8) & 0xFF;
    ucN = PDATA_WORD(0) & 0xFF;

    // IVS to DVS shift value for hardware auto toggle among three initial read address
    // Set Shift = 2 _3_IVF, _2_5_IVF
    ScalerSetBit(P5_E3_DISP_M1_MN_TOG_SHIFT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((GET_MEMORY_DVF_SELECT() == _3_IVF) ? 2 : 0)); // _2_5_IVF: 0

    // Multiple of hardware auto toggle among three initial read address, it is (N/M - 1)
    PDATA_WORD(0) = ucN / ucM - 1;

    ScalerSetBit(P5_E3_DISP_M1_MN_TOG_SHIFT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (PDATA_WORD(0) << 4));

    // Remain of hardware auto toggle among three initial read address, and it is (N%M)/N * 2^10.(11bit in total)
    PDATA_WORD(0) = ((ucN % ucM) << 10) / ucN;
    PDATA_WORD(0) += 1;

    ScalerSetBit(P5_E4_DISP_M1_MN_TOG_EN, ~(_BIT2 | _BIT1 | _BIT0), (HIBYTE(PDATA_WORD(0)) & 0xFF));
    ScalerSetByte(P5_E5_DISP_M1_MN_TOG_REM, (LOBYTE(PDATA_WORD(0)) & 0xFF));
}

//--------------------------------------------------
// Description  : Set Input adderss for auto block toggle
// Input Value  : ulBlockStep --> block step(single frame input and display)
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetInputAutoBlkToggle(void)
{
    ScalerFRCSetCapAddress(_FRC_1ST_BLOCK, _FRC_R_2ND_BLOCK_STA_ADDR);
    ScalerFRCSetCapAddress(_FRC_2ND_BLOCK, _FRC_R_3RD_BLOCK_STA_ADDR);
    ScalerFRCSetCapAddress(_FRC_3RD_BLOCK, _FRC_R_1ST_BLOCK_STA_ADDR);
}
#endif // End of #if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)

#if(_ASPECT_RATIO_WITHOUT_MUTE == _ON)
//--------------------------------------------------
// Description  : Set Dvst, Dvheight when aspect ratio wothout mute
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetAspectRatioDDomain(void)
{
    WORD usAspNewDVst = 0;
    if(GET_ASPECT_RATIO_MIN_DVH() != 0)
    {
        if(GET_MDOMAIN_OUTPUT_VHEIGHT() > GET_ASPECT_RATIO_MIN_DVH())
        {
            usAspNewDVst = GET_MDOMAIN_OUTPUT_VHEIGHT() - GET_ASPECT_RATIO_MIN_DVH();
            usAspNewDVst &= 0xFFFC;
            usAspNewDVst = GET_MDOMAIN_OUTPUT_VSTART() + (usAspNewDVst / 2);
        }
        else
        {
            usAspNewDVst = GET_ASPECT_RATIO_MIN_DVH() - GET_MDOMAIN_OUTPUT_VHEIGHT();
            usAspNewDVst &= 0xFFFC;
            usAspNewDVst = GET_MDOMAIN_OUTPUT_VSTART() - (usAspNewDVst / 2);
        }

        SET_MDOMAIN_OUTPUT_VSTART(usAspNewDVst);
        SET_MDOMAIN_OUTPUT_VHEIGHT(GET_ASPECT_RATIO_MIN_DVH());
        SET_MDOMAIN_OUTPUT_VBHEIGHT(GET_ASPECT_RATIO_MIN_DVH());
    }
}
#endif
#endif // End of #if(_FRC_SUPPORT == _ON)
