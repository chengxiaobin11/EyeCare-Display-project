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
// ID Code      : RL6410_Series_ODFunction.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6410_Series_ODLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _OD_8BIT_LUT_LENGTH                 289
#define _OD_10BIT_LUT_LENGTH                578

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
void ScalerODInitial(WORD usPanelHWidth, WORD usPanelVHeight);
void ScalerODAdjustDeltaGain(BYTE ucValue);
void ScalerODLoadLUT(BYTE code *pucODTable, BYTE ucBankNum, bit bLUTMode);
void ScalerODSetFIFO(WORD usWidth, WORD usHeight);
void ScalerODHLWinSetting(EnumHLWType enumHLWType, EnumDBApply enumDBApply);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : OD initialization setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerODInitial(WORD usPanelHWidth, WORD usPanelVHeight)
{
    ScalerODEnable(_FUNCTION_OFF);

    if(GET_OD_USE_BIT() != _OFF)
    {
        // Set OD compression settings
        ScalerODCompressionSetting();

        // Set OD FIFO settings
        ScalerODSetFIFO(usPanelHWidth, usPanelVHeight);
    }
}

//--------------------------------------------------
// Description  : Adjust OD delta gain
// Input Value  : Delta gain
// Output Value : None
//--------------------------------------------------
void ScalerODAdjustDeltaGain(BYTE ucValue)
{
    ScalerSetByte(P3_A3_DELTA_GAIN, ucValue);
}

//--------------------------------------------------
// Description  : Load OD LUT
// Input Value  :
//                pODTable -> OD TABLE Pointer
//                ucBankNum -> Bank number
//                bLUTMode -> OD LUT Type (8bit/10bit LUT)
// Output Value : None
//--------------------------------------------------
void ScalerODLoadLUT(BYTE code *pucODTable, BYTE ucBankNum, bit bLUTMode)
{
    // Set OD LUT Mode
    ScalerSetBit(P3_BF_LS_LUT_CTRL, ~_BIT0, ((bLUTMode == _OD_10BIT_LUT) ? _BIT0 : 0x00));

    // Enable LUT access
    ScalerSetBit(P3_BF_LS_LUT_CTRL, ~(_BIT7 | _BIT6), _BIT7);

    ScalerBurstWrite(pucODTable, ((bLUTMode == _OD_10BIT_LUT) ? _OD_10BIT_LUT_LENGTH : _OD_8BIT_LUT_LENGTH), ucBankNum, P3_C0_LS_LUT_DATA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Disable LUT access
    ScalerSetBit(P3_BF_LS_LUT_CTRL, ~_BIT7, 0x00);
}

//--------------------------------------------------
// Description  : OD memory & FIFO setting
// Input Value  : usWidth -> Display Width
//                usHeight -> Display Height
// Output Value : None
//--------------------------------------------------
void ScalerODSetFIFO(WORD usWidth, WORD usHeight)
{
    // OD Front/Back mode(_ENABLE: OD F/B mode, _DISABLE: OD Front only)
    bit bODFrontBackMode = ((ScalerGetBit(P0_2F_DISPLAY_FORMAT_DOUBLE_BUFFER, _BIT0) == _BIT0) ? _ENABLE : _DISABLE);
    // Effective H_Width & V_Height of each OD path
    WORD usODHWidthPerPath = 0;
    WORD usODVHeightPerPath = 0;

    if(bODFrontBackMode == _ENABLE)
    {
        usODHWidthPerPath = CEILING_OF_INT_DIVISION(usWidth, 2);
        usODVHeightPerPath = CEILING_OF_INT_DIVISION(usHeight, 2);
    }
    else // bODFrontBackMode == _DISABLE
    {
        usODHWidthPerPath = usWidth;
        usODVHeightPerPath = CEILING_OF_INT_DIVISION(usHeight, 2);
    }

    // Calculate Memory usage of each OD path
    PDATA_DWORD(0) = ((DWORD)CEILING(usODHWidthPerPath, _OD_PIXEL_PER_COMP)) * GET_OD_USE_BIT() / 10 * usODVHeightPerPath;
    PDATA_DWORD(0) = CEILING_OF_INT_DIVISION(PDATA_DWORD(0), _OD_FIFO_BUS_WIDTH);

    // Calculate Number and Remain --> (Number x Length + Remain) x OD_FIFO_BUS_WIDTH = Total size
    PDATA_DWORD(0) = ScalerMemoryCalculateNumberAndRemain(PDATA_DWORD(0), _OD_FIFO_WR_LENGTH, 1);

    // Set FIFO Write Water Level
    // M1 (& S1 if OD Front/Back is not separated)
    ScalerSetByte(P3_D0_LS_DDR_FIFO_WTLVL_W_H, (((_OD_FIFO_WR_LENGTH / 2) & _BIT8) >> 8));
    ScalerSetByte(P3_D1_LS_DDR_FIFO_WTLVL_W_L, ((_OD_FIFO_WR_LENGTH / 2) & 0xFF));
    // M2 (& S2 if OD Front/Back is not separated)
    ScalerSetByte(P43_D0_LS_DDR_FIFO_WTLVL_W_H, (((_OD_FIFO_WR_LENGTH / 2) & _BIT8) >> 8));
    ScalerSetByte(P43_D1_LS_DDR_FIFO_WTLVL_W_L, ((_OD_FIFO_WR_LENGTH / 2) & 0xFF));

    // Set FIFO Read Water Level
    // M1 (& S1 if OD Front/Back is not separated)
    ScalerSetByte(P3_D2_LS_DDR_FIFO_WTLVL_R_H, ((_OD_FIFO_WR_LENGTH & _BIT8) >> 8));
    ScalerSetByte(P3_D3_LS_DDR_FIFO_WTLVL_R_L, (_OD_FIFO_WR_LENGTH & 0xFF));
    // M2 (& S2 if OD Front/Back is not separated)
    ScalerSetByte(P43_D2_LS_DDR_FIFO_WTLVL_R_H, ((_OD_FIFO_WR_LENGTH & _BIT8) >> 8));
    ScalerSetByte(P43_D3_LS_DDR_FIFO_WTLVL_R_L, (_OD_FIFO_WR_LENGTH & 0xFF));

    // Set FIFO RW Number
    // M1 (& S1 if OD Front/Back is not separated)
    ScalerSetByte(P3_D4_LS_DDR_FIFO_RW_NUM_H, pData[2]);
    ScalerSetByte(P3_D5_LS_DDR_FIFO_RW_NUM_L, pData[3]);
    // M2 (& S2 if OD Front/Back is not separated)
    ScalerSetByte(P43_D4_LS_DDR_FIFO_RW_NUM_H, pData[2]);
    ScalerSetByte(P43_D5_LS_DDR_FIFO_RW_NUM_L, pData[3]);

    // Set FIFO RW Length
    // M1 (& S1 if OD Front/Back is not separated)
    ScalerSetByte(P3_D6_LS_DDR_FIFO_RW_LEN_H, ((_OD_FIFO_WR_LENGTH & _BIT8) >> 8));
    ScalerSetByte(P3_D7_LS_DDR_FIFO_RW_LEN_L, (_OD_FIFO_WR_LENGTH & 0xFF));
    // M2 (& S2 if OD Front/Back is not separated)
    ScalerSetByte(P43_D6_LS_DDR_FIFO_RW_LEN_H, ((_OD_FIFO_WR_LENGTH & _BIT8) >> 8));
    ScalerSetByte(P43_D7_LS_DDR_FIFO_RW_LEN_L, (_OD_FIFO_WR_LENGTH & 0xFF));

    // Set FIFO RW Remain
    // M1 (& S1 if OD Front/Back is not separated)
    ScalerSetByte(P3_D8_LS_DDR_FIFO_RW_REMAIN_H, pData[0]);
    ScalerSetByte(P3_D9_LS_DDR_FIFO_RW_REMAIN_L, pData[1]);
    // M2 (& S2 if OD Front/Back is not separated)
    ScalerSetByte(P43_D8_LS_DDR_FIFO_RW_REMAIN_H, pData[0]);
    ScalerSetByte(P43_D9_LS_DDR_FIFO_RW_REMAIN_L, pData[1]);
}

//--------------------------------------------------
// Description  : OD HLW type select
// Input Value  : enumHLWType --> _FULL_WINDOW, _INSIDE_WINDOW or _OUTSIDE_WINDOW
// Output Value : None
//--------------------------------------------------
void ScalerODHLWinSetting(EnumHLWType enumHLWType, EnumDBApply enumDBApply)
{
    // Select OD HLW type
    switch(enumHLWType)
    {
        case _HLW_FULL_WINDOW:

            ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_10_HLW_CONTROL3, ~(_BIT5 | _BIT4), 0x00);

            break;

        case _HLW_INSIDE_WINDOW:

            ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_10_HLW_CONTROL3, ~(_BIT5 | _BIT4), 0x01 << 4);

            break;

        case _HLW_OUTSIDE_WINDOW:

            ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_10_HLW_CONTROL3, ~(_BIT5 | _BIT4), 0x02 << 4);

            break;

        default:

            break;
    }

    ScalerGlobalDDomainDBApply(enumDBApply);
}

