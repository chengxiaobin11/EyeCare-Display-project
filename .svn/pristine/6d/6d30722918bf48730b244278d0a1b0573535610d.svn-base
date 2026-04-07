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
// ID Code      : RL6851_Series_Scaling.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if(_SHARPNESS_SUPPORT == _OFF)
#define _HSU_TABLE_SIZE                                   128
#define _VSU_TABLE_SIZE                                   128
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************
#if(_SHARPNESS_SUPPORT == _OFF)
//----------------------------------------------------------------------------------------------------
// 128 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSD_SU_COEF_128_TAPS[] =
{
    0xFB, 0x0F, 0xFE, 0x0F, 0xFD, 0x0F, 0xFC, 0x0F, 0xFB, 0x0F, 0xFA, 0x0F, 0xF7, 0x0F, 0xF5, 0x0F,
    0xF1, 0x0F, 0xED, 0x0F, 0xE9, 0x0F, 0xE4, 0x0F, 0xDE, 0x0F, 0xD9, 0x0F, 0xD3, 0x0F, 0xCD, 0x0F,
    0xC7, 0x0F, 0xDB, 0x0F, 0xF0, 0x0F, 0x0C, 0x00, 0x27, 0x00, 0x49, 0x00, 0x6B, 0x00, 0x93, 0x00,
    0xBC, 0x00, 0xEA, 0x00, 0x16, 0x01, 0x49, 0x01, 0x7A, 0x01, 0xB0, 0x01, 0xE3, 0x01, 0x1C, 0x02,
    0x84, 0x04, 0x78, 0x04, 0x6C, 0x04, 0x57, 0x04, 0x42, 0x04, 0x23, 0x04, 0x04, 0x04, 0xDC, 0x03,
    0xB4, 0x03, 0x86, 0x03, 0x59, 0x03, 0x26, 0x03, 0xF4, 0x02, 0xBD, 0x02, 0x89, 0x02, 0x50, 0x02,
    0xBA, 0x0F, 0xAF, 0x0F, 0xA7, 0x0F, 0xA1, 0x0F, 0x9C, 0x0F, 0x9A, 0x0F, 0x9A, 0x0F, 0x9C, 0x0F,
    0x9F, 0x0F, 0xA3, 0x0F, 0xA8, 0x0F, 0xAD, 0x0F, 0xB4, 0x0F, 0xBA, 0x0F, 0xC1, 0x0F, 0xC7, 0x0F,
};

#if(_VSU_3L_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// 96 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSD_SU_COEF_96_TAPS[] =
{
    0xF2, 0x0F, 0xF0, 0x0F, 0xED, 0x0F, 0xEB, 0x0F, 0xE8, 0x0F, 0xE9, 0x0F, 0xE8, 0x0F, 0xEC, 0x0F,
    0xEF, 0x0F, 0xF6, 0x0F, 0xFC, 0x0F, 0x06, 0x00, 0x0F, 0x00, 0x1D, 0x00, 0x2A, 0x00, 0x3B, 0x00,
    0x1A, 0x02, 0x41, 0x02, 0x66, 0x02, 0x8A, 0x02, 0xAC, 0x02, 0xCC, 0x02, 0xEB, 0x02, 0x06, 0x03,
    0x1F, 0x03, 0x35, 0x03, 0x48, 0x03, 0x59, 0x03, 0x66, 0x03, 0x70, 0x03, 0x76, 0x03, 0x7A, 0x03,
    0xF4, 0x01, 0xCF, 0x01, 0xAD, 0x01, 0x8B, 0x01, 0x6C, 0x01, 0x4B, 0x01, 0x2D, 0x01, 0x0E, 0x01,
    0xF2, 0x00, 0xD5, 0x00, 0xBC, 0x00, 0xA1, 0x00, 0x8B, 0x00, 0x73, 0x00, 0x60, 0x00, 0x4B, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
#endif
#endif

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerScalingSetScalingUp(const StructSDRAMDataInfo *pstFIFOScaling);
void ScalerScalingSetScalingDown(const StructSDRAMDataInfo *pstFIFOScaling);

#if(_SHARPNESS_SUPPORT == _ON)
EnumVSUCoefType ScalerScalingGetScalingUpType(void);
#else
void ScalerScalingSetScalingUpCoef(void);
#endif

void ScalerScalingUpdateFIFOScalingSize(StructSDRAMDataInfo *pstData);
void ScalerScalingGetFIFOScalingSize(StructSDRAMDataInfo *pstData);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Decide which scaling up function should be performed
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerScalingSetScalingUp(const StructSDRAMDataInfo *pstFIFOScaling)
{
    CLR_V_SCALE_UP();
    CLR_H_SCALE_UP();

    // Disable Scale Up
    ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~(_BIT5 | _BIT1 | _BIT0), _BIT5);

#if(_SHARPNESS_SUPPORT == _OFF)
    // Disable Scale Up FixCoef
    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE, ~(_BIT5 | _BIT4), 0x00);
#endif

    //===============================
    // Decide V direction scaling up
    //===============================
    // Set V Scaling Up Factor
    if(pstFIFOScaling->usOutputVHeight < GET_MDOMAIN_OUTPUT_VHEIGHT())
    {
        SET_V_SCALE_UP();

        // Calculate Scaling Factor
        PDATA_DWORD(0) = GET_DWORD_MUL_DIV((1UL << (_VSU_FACTOR_BIT + 1)), pstFIFOScaling->usOutputVHeight, GET_MDOMAIN_OUTPUT_VHEIGHT());
        PDATA_DWORD(0) = (PDATA_DWORD(0) + 1) >> 1;

        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_03_VER_SCALE_FACTOR_H, ((PDATA_DWORD(0) >> 16) & 0x0F));
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_04_VER_SCALE_FACTOR_M, ((PDATA_DWORD(0) >> 8) & 0xFF));
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_05_VER_SCALE_FACTOR_L, (PDATA_DWORD(0) & 0xFF));

        // Set V Initial Phase
        // R = Input Height /Output Height
        // ideal initial phase: for 4line SU = (1+R)*16*8
        PDATA_DWORD(0) = (DWORD)(pstFIFOScaling->usOutputVHeight + GET_MDOMAIN_OUTPUT_VHEIGHT()) * 16 * 8 / GET_MDOMAIN_OUTPUT_VHEIGHT();

        // Check for enabling video compensation
        if((GET_MDOMAIN_INPUT_INTERLACE_FLG() == _FALSE) ||
           (ScalerGetBit(P0_10_M1_VGIP_CTRL, (_BIT3 | _BIT2)) == 0x00) ||
           (BYPASS_VIDEO_COMPENSATION(pstFIFOScaling->usOutputVHeight, GET_MDOMAIN_OUTPUT_VHEIGHT()) == _TRUE))
        {
            ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_11_VER_FILTER_COEF_INI, pData[3]);
        }
        else
        {
            if(pData[3] > 0xBF)
            {
                pData[3] = 0xFF;
            }
            else
            {
                pData[3] = pData[3] + 0x40;
            }

            ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_11_VER_FILTER_COEF_INI, pData[3]);
        }
    }
    else
    {
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_03_VER_SCALE_FACTOR_H, 0x0F);
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_04_VER_SCALE_FACTOR_M, 0xFF);
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_05_VER_SCALE_FACTOR_L, 0xFF);

        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_11_VER_FILTER_COEF_INI, 0xFF);

#if(_SHARPNESS_SUPPORT == _OFF)
        // Enable V Scale Up FixCoef
        ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE, ~_BIT4, _BIT4);
#endif
    }

    if(GET_V_SCALE_UP() == _TRUE)
    {
        // Enable V Scale Up
        ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~(_BIT5 | _BIT1), (_BIT5 | _BIT1));

        if(GET_MDOMAIN_INPUT_INTERLACE_FLG() == _TRUE)
        {
            // VGA Input or Prefered Timing
            if((ScalerGetBit(P0_10_M1_VGIP_CTRL, (_BIT3 | _BIT2)) == 0x00) ||
               (BYPASS_VIDEO_COMPENSATION(pstFIFOScaling->usOutputVHeight, GET_MDOMAIN_OUTPUT_VHEIGHT()) == _TRUE))
            {
                // Disable Video Compensation
                ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~(_BIT7 | _BIT5), _BIT5);
            }
            else
            {
                // Enable Video Compensation According to Odd Field Delay One Line
                ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~(_BIT7 | _BIT5), (_BIT7 | _BIT5));
            }
        }
        else
        {
            // Disable Video Compensation
            ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~(_BIT7 | _BIT5), _BIT5);
        }
    }
    else
    {
        // Disable Video Compensation
        ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~(_BIT7 | _BIT5), _BIT5);
    }

    //===============================
    // Decide H direction scaling up
    //===============================
    // Set H Scaling Up Factor
    SET_H_SCALE_UP();

    if(pstFIFOScaling->usOutputHWidth < GET_MDOMAIN_OUTPUT_HWIDTH())
    {
        // Calculate Scaling Factor
        PDATA_DWORD(0) = GET_DWORD_MUL_DIV((1UL << (_HSU_FACTOR_BIT + 1)), pstFIFOScaling->usOutputHWidth, GET_MDOMAIN_OUTPUT_HWIDTH());
        PDATA_DWORD(0) = (PDATA_DWORD(0) + 1) >> 1;

        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_00_HOR_SCALE_FACTOR_H, ((PDATA_DWORD(0) >> 16) & 0x0F));
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_01_HOR_SCALE_FACTOR_M, ((PDATA_DWORD(0) >> 8) & 0xFF));
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_02_HOR_SCALE_FACTOR_L, (PDATA_DWORD(0) & 0xFF));

        // Set H Initial Phase
        // R = Input width /Output width
        // ideal initial phase = (1+R)*16*8
        PDATA_DWORD(0) = (DWORD)(pstFIFOScaling->usOutputHWidth + GET_MDOMAIN_OUTPUT_HWIDTH()) * 16 * 8 / GET_MDOMAIN_OUTPUT_HWIDTH();

        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_10_HOR_FILTER_COEF_INI, (BYTE)PDATA_DWORD(0));
    }
    else
    {
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_00_HOR_SCALE_FACTOR_H, 0x0F);
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_01_HOR_SCALE_FACTOR_M, 0xFF);
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_02_HOR_SCALE_FACTOR_L, 0xFF);

        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_10_HOR_FILTER_COEF_INI, 0xFF);

#if(_SHARPNESS_SUPPORT == _OFF)
        // Enable H Scale Up FixCoef
        ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE, ~_BIT5, _BIT5);
#endif
    }

    //===============================
    // Set H direction scaling up
    //===============================
    if(GET_H_SCALE_UP() == _TRUE)
    {
        // Enable H Scale Up
        ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~(_BIT5 | _BIT0), (_BIT5 | _BIT0));
    }
}

//--------------------------------------------------
// Description  : Decide which scaling down function should be performed
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerScalingSetScalingDown(const StructSDRAMDataInfo *pstFIFOScaling)
{
    CLR_V_SCALE_DOWN();
    CLR_H_SCALE_DOWN();

    // Disable Scale Down
    // M1
    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    //===============================
    // Decide H direction scaling down
    //===============================
    // Set H Scaling Down Factor
    if(GET_MDOMAIN_INPUT_HWIDTH() > pstFIFOScaling->usInputHWidth)
    {
        SET_H_SCALE_DOWN();

        // Calculate Scaling Factor
        PDATA_DWORD(0) = GET_DWORD_MUL_DIV((1UL << (_HSD_FACTOR_BIT)), GET_MDOMAIN_INPUT_HWIDTH(), pstFIFOScaling->usInputHWidth);

        // The rounding of hsd factor may cause frame sync line buffer error under specific resolution
        if(((((1UL << _HSD_FACTOR_BIT) % pstFIFOScaling->usInputHWidth) *
             (GET_MDOMAIN_INPUT_HWIDTH() % pstFIFOScaling->usInputHWidth)) % pstFIFOScaling->usInputHWidth) != 0)
        {
            PDATA_DWORD(0) += 1;
        }

        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_05_H_SD_FACTOR_H_M1, ((PDATA_DWORD(0) >> 16) & 0xFF));
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_06_H_SD_FACTOR_M_M1, ((PDATA_DWORD(0) >> 8) & 0xFF));
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_07_H_SD_FACTOR_L_M1, (PDATA_DWORD(0) & 0xFF));

        // Calculate Initial Phase
        // (factor - 1) / 2  // 1.6
        PDATA_DWORD(0) = (PDATA_DWORD(0) >> 15) - 32;

        if(PDATA_DWORD(0) > 0x3F)
        {
            PDATA_DWORD(0) = 0x3F;
        }

        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_04_H_SD_INIT_M1, PDATA_DWORD(0));
    }
    else
    {
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_04_H_SD_INIT_M1, 0x00);
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_05_H_SD_FACTOR_H_M1, 0x10);
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_06_H_SD_FACTOR_M_M1, 0x00);
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_07_H_SD_FACTOR_L_M1, 0x00);
    }

    //===============================
    // Decide V direction scaling down
    //===============================
    // Set V Scaling Down Factor
    if(GET_MDOMAIN_INPUT_VHEIGHT() > pstFIFOScaling->usInputVHeight)
    {
        SET_V_SCALE_DOWN();

        // Calculate Scaling Factor
        PDATA_DWORD(0) = GET_DWORD_MUL_DIV((1UL << (_VSD_FACTOR_BIT + 1)), GET_MDOMAIN_INPUT_VHEIGHT(), pstFIFOScaling->usInputVHeight);
        PDATA_DWORD(0) = (PDATA_DWORD(0) + 1) >> 1;

        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_01_V_SD_FACTOR_H_M1, ((PDATA_DWORD(0) >> 16) & 0x0F));
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_02_V_SD_FACTOR_M_M1, ((PDATA_DWORD(0) >> 8) & 0xFF));
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_03_V_SD_FACTOR_L_M1, (PDATA_DWORD(0) & 0xFF));

        // Calculate Initial Phase
        PDATA_DWORD(0) = (PDATA_DWORD(0) >> 12) - 32;

        if(PDATA_DWORD(0) > 0x3F)
        {
            PDATA_DWORD(0) = 0x3F;
        }
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_00_V_SD_INIT_M1, PDATA_DWORD(0));
    }
    else
    {
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_00_V_SD_INIT_M1, 0x00);
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_01_V_SD_FACTOR_H_M1, 0x02);
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_02_V_SD_FACTOR_M_M1, 0x00);
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_03_V_SD_FACTOR_L_M1, 0x00);
    }

    if((GET_H_SCALE_DOWN() == _TRUE) || (GET_V_SCALE_DOWN() == _TRUE))
    {
        // Toggle HSD/VSD enable in IV porch to prevent OSD mute
        ScalerTimerWaitForEvent(_EVENT_IVS);
    }

    if(GET_H_SCALE_DOWN() == _TRUE)
    {
        // Enable H Scale Down
        ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~(_BIT3 | _BIT1), _BIT1);
    }

    if(GET_V_SCALE_DOWN() == _TRUE)
    {
        // Enable V Scale Down
        ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~_BIT0, _BIT0);
    }
}

#if(_SHARPNESS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get 3D ScalingUp Type
// Input Value  : none
// Output Value : 0: no 3D ScaleUp,  1: 3D 3Line V ScaleUp,  2:3D 2Line V ScaleUp,
//--------------------------------------------------
EnumVSUCoefType ScalerScalingGetScalingUpType(void)
{
    return _VSU_2D_4LINE_COEF;
}
#else
//--------------------------------------------------
// Description  : Set ScaleUp Coef
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void ScalerScalingSetScalingUpCoef(void)
{
    // Set Coefficient table 1
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tSD_SU_COEF_128_TAPS, _HSU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Set Coefficient table 2
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tSD_SU_COEF_128_TAPS, _VSU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Disable Coefficient Access, Set HSU to use coefficient table 1 & set VSU to use coefficient table 2
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);
}
#endif

//--------------------------------------------------
// Description  : Decide which scaling size
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerScalingUpdateFIFOScalingSize(StructSDRAMDataInfo *pstData)
{
#if(_FRC_SUPPORT == _ON)
    if(GET_MEMORY_DVF_SELECT() == _1_IVF)
    {
        SET_MEMORY_FRAME_BUFFER(_MEMORY_1_FRAME_BUFFER);
    }
#if(_HW_ONE_FRAME_FRC_MAX_DROP_FRAME_SUPPORT == _ON)
    else if((GET_MEMORY_DVF_SELECT() == _PANEL_TYP_FRAME_RATE_FREE_RUN) && (ScalerFRCCheckDoubleFrameBuffer() == _FALSE))
    {
        SET_MEMORY_FRAME_BUFFER(_MEMORY_1_FRAME_BUFFER);
    }
#endif
    else
    {
#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
        if(GET_FRC_3BLOCK_TOGGLE_STATUS() == _ENABLE)
        {
            SET_MEMORY_FRAME_BUFFER(_MEMORY_1_5_FRAME_BUFFER);
        }
        else
#endif
        {
            SET_MEMORY_FRAME_BUFFER(_MEMORY_2_FRAME_BUFFER);
        }
    }

    if(GET_MEMORY_FRAME_BUFFER() == _MEMORY_2_FRAME_BUFFER)
    {
        SET_ROW_PER_PATH(_MEMORY_BOTTOM_ADDRESS >> 1);
    }
#endif

    //-----------------------------------------------
    // Consider FIFO Input / Output H width
    //-----------------------------------------------
    if(GET_MDOMAIN_INPUT_HWIDTH() > GET_MDOMAIN_OUTPUT_HWIDTH())
    {
        pstData->usInputHWidth = GET_MDOMAIN_OUTPUT_HWIDTH();
    }
    else
    {
        pstData->usInputHWidth = GET_MDOMAIN_INPUT_HWIDTH();
    }

    //-----------------------------------------------
    // Consider FIFO Input / Output V Height
    //-----------------------------------------------
    if(GET_MDOMAIN_INPUT_VHEIGHT() > GET_MDOMAIN_OUTPUT_VHEIGHT())
    {
        pstData->usInputVHeight = GET_MDOMAIN_OUTPUT_VHEIGHT();
    }
    else
    {
        pstData->usInputVHeight = GET_MDOMAIN_INPUT_VHEIGHT();
    }

#if(_FRC_SUPPORT == _ON)
    //-----------------------------------------------
    // Consider FIFO Input / Output H width in FRC
    //-----------------------------------------------
    if(GET_MEMORY_CONFIG() == _MEMORY_WORK_MODE)
    {
        BYTE ucRateCtrlParamIndex = 0;

        StructFRCRateCtrlInfo stFRCRateCtrlInfo;

        // Prepare necessary info for rate ctrl decision
        stFRCRateCtrlInfo.ucImgCmpUsable = ScalerFRCGetImgCmpHWUsability();
        stFRCRateCtrlInfo.ucImgCmpUsable &= ScalerFRCGetImgCmpRunTimeUsability(pstData->usInputHWidth);
        stFRCRateCtrlInfo.usInputHWidth = GET_MDOMAIN_INPUT_HWIDTH();
        stFRCRateCtrlInfo.usFifoHWidth = pstData->usInputHWidth;
        stFRCRateCtrlInfo.usFifoVHeight = pstData->usInputVHeight;
        stFRCRateCtrlInfo.ucMDomainExt = 0;
        stFRCRateCtrlInfo.ulGrantBW = ScalerMDomainGetCurBW();
        ScalerMDomainGetMemBWParam(&stFRCRateCtrlInfo.stMemBWParam);

        ucRateCtrlParamIndex = ScalerFRCGetMemRateCtrlParamIndex(&stFRCRateCtrlInfo);

        // Apply rate ctrl parameter
        ScalerFRCApplyMemRateCtrlParam(ucRateCtrlParamIndex);

        // Update HSD result
        pstData->usInputHWidth = stFRCRateCtrlInfo.usFifoHWidth;
    } // End of if(GET_MEMORY_CONFIG() == _MEMORY_WORK_MODE)
#endif // End of #if(_FRC_SUPPORT == _ON)


    pstData->usOutputHWidth = pstData->usInputHWidth;
    pstData->usOutputVHeight = pstData->usInputVHeight;
}

//--------------------------------------------------
// Description  : Decide which scaling size
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerScalingGetFIFOScalingSize(StructSDRAMDataInfo *pstData)
{
    ScalerScalingUpdateFIFOScalingSize(pstData);
#if(_FRC_SUPPORT == _ON)
    SET_FIFO_HWIDTH(pstData->usInputHWidth);

    // Clear Mdomain Bandwidth
    CLR_MEMORY_BW();

    if(GET_MEMORY_CONFIG() == _MEMORY_WORK_MODE)
    {
        // get mdomain input pixel clk
        PDATA_DWORD(0) = (DWORD)GET_MDOMAIN_INPUT_HFREQ() * GET_MDOMAIN_INPUT_HTOTAL() / 10; // kHz

        // get frc real-used bw
        PDATA_DWORD(0) = ScalerFRCBWCalUsage(pstData->usInputHWidth, pstData->usInputHWidth, GET_MEMORY_DATA_BIT(), GET_IMG_CMP_PARAM(), PDATA_DWORD(0), _FALSE);

        // Set using bandwidth
        SET_MEMORY_BW(PDATA_DWORD(0));

#if(_OD_SUPPORT == _ON)
        // Update FRC remaining bandwidth
        SET_MEMORY_REMAIN_BW(GET_MEMORY_TOTAL_BW() - GET_MEMORY_BW());
#endif
    }

#endif
}


