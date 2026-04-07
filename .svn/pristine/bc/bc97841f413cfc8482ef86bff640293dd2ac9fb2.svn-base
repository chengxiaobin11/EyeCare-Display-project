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
// ID Code      : RL6851_Series_FRC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#define __RL6851_SERIES_FRC__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _FRC_IVS2DVSDELAY_MARGIN                    (30)  // (IVStart + IDEN) period > (DVStart + DDEN) period

#if(_DRR_SUPPORT == _ON)
#define _FRC_IVS2DVSDELAY_MARGIN_FREESYNC           (4)
#define _FRC_IVS2DVSDELAY_LINE_BUFFER_MARGIN        (4)
#endif


#if(_FRC_SUPPORT == _ON)
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
#define GET_MOD_FRC_LEN_WTLVL_STATUS()              (g_bFRCModLenWtlvlStatus)
#define SET_MOD_FRC_LEN_WTLVL_STATUS(x)             (g_bFRCModLenWtlvlStatus = (x))
#endif
#endif

#define _FRC_UNIT                                   (64)
#define _FRC_MIN_LINE_SUM_BIT                       (128 * 30)

//--------------------------------------------------
// Define FRC Access Length
//--------------------------------------------------
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
#define _FRC_ACCESS_WRITE_LENGTH                    ((GET_MOD_FRC_LEN_WTLVL_STATUS() == _TRUE) ? 0x60 : 0x7C)
#define _FRC_ACCESS_READ_LENGTH                     ((GET_MOD_FRC_LEN_WTLVL_STATUS() == _TRUE) ? 0x60 : 0x7C)
#define _FRC_DISP_WTLVL                             ((GET_MOD_FRC_LEN_WTLVL_STATUS() == _TRUE) ? 0x40 : (256 - _FRC_ACCESS_READ_LENGTH / 2))
#else
#define _FRC_ACCESS_WRITE_LENGTH                    (0x7C)
#define _FRC_ACCESS_READ_LENGTH                     (0x7C)
#define _FRC_DISP_WTLVL                             (256 - _FRC_ACCESS_READ_LENGTH / 2)
#endif

#define _OD_PARAM_LENGTH                            (sizeof(tODParam) / sizeof(tODParam[0]))

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
#if(_FRC_SUPPORT == _ON)

StructFRCRateCtrlParam code tFRCRateCtrlParam[] =
{
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
    // FIFO_BIT_DEPTH      HSD   ImgCmp                      OD Reserve
    {_COLOR_DEPTH_8_BITS,  _OFF, _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
    {_COLOR_DEPTH_8_BITS,  _OFF, _IMG_CMP_PARAM_LLB_8B_TYP,  _OD_PARAM_OFF},
#if(_M_DOMAIN_IMG_CMP_6_BPP_SUPPORT == _ON)
    {_COLOR_DEPTH_8_BITS,  _OFF, _IMG_CMP_PARAM_LLB_8B_MIN,  _OD_PARAM_OFF},
    {_COLOR_DEPTH_8_BITS,  _ON,  _IMG_CMP_PARAM_LLB_8B_MIN,  _OD_PARAM_OFF},
#else
    {_COLOR_DEPTH_8_BITS,  _ON,  _IMG_CMP_PARAM_LLB_8B_TYP,  _OD_PARAM_OFF},
#endif
    {_COLOR_DEPTH_8_BITS,  _ON,  _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
#else
    // FIFO_BIT_DEPTH      HSD   ImgCmp                      OD Reserve
    {_COLOR_DEPTH_8_BITS,  _OFF, _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
    {_COLOR_DEPTH_8_BITS,  _ON,  _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
#endif
};

#if 0 // (_BW_CUSTOME_MODE == _ENABLE) !!!! 6851 max _COLOR_DEPTH_8_BITS, need to remove _COLOR_DEPTH_10_BITS
StructFRCRateCtrlParam code tFRCRateCtrlParamCustomeFixColorDepth[] =
{
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
    // FIFO_BIT_DEPTH      HSD   ImgCmp                      OD Reserve
    {_COLOR_DEPTH_10_BITS, _ON,  _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
    {_COLOR_DEPTH_8_BITS,  _OFF, _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
    {_COLOR_DEPTH_8_BITS,  _OFF, _IMG_CMP_PARAM_LLB_8B_TYP,  _OD_PARAM_OFF},
#if(_M_DOMAIN_IMG_CMP_6_BPP_SUPPORT == _ON)
    {_COLOR_DEPTH_8_BITS,  _OFF, _IMG_CMP_PARAM_LLB_8B_MIN,  _OD_PARAM_OFF},
    {_COLOR_DEPTH_8_BITS,  _ON,  _IMG_CMP_PARAM_LLB_8B_MIN,  _OD_PARAM_OFF},
#else
    {_COLOR_DEPTH_8_BITS,  _ON,  _IMG_CMP_PARAM_LLB_8B_TYP,  _OD_PARAM_OFF},
#endif
    {_COLOR_DEPTH_8_BITS,  _ON,  _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
#else
    // FIFO_BIT_DEPTH      HSD   ImgCmp                      OD Reserve
    {_COLOR_DEPTH_10_BITS, _ON,  _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
    {_COLOR_DEPTH_8_BITS,  _ON,  _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
#endif
};

StructFRCRateCtrlParam code tFRCRateCtrlParamCustomeODoffFirst[] =
{
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
    // FIFO_BIT_DEPTH      HSD   ImgCmp                      OD Reserve
    {_COLOR_DEPTH_10_BITS, _OFF, _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
    {_COLOR_DEPTH_8_BITS,  _OFF, _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
    {_COLOR_DEPTH_8_BITS,  _OFF, _IMG_CMP_PARAM_LLB_8B_TYP,  _OD_PARAM_OFF},
#if(_M_DOMAIN_IMG_CMP_6_BPP_SUPPORT == _ON)
    {_COLOR_DEPTH_8_BITS,  _OFF, _IMG_CMP_PARAM_LLB_8B_MIN,  _OD_PARAM_OFF},
    {_COLOR_DEPTH_8_BITS,  _ON,  _IMG_CMP_PARAM_LLB_8B_MIN,  _OD_PARAM_OFF},
#else
    {_COLOR_DEPTH_8_BITS,  _ON,  _IMG_CMP_PARAM_LLB_8B_TYP,  _OD_PARAM_OFF},
#endif
    {_COLOR_DEPTH_8_BITS,  _ON,  _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
#else
    // FIFO_BIT_DEPTH      HSD   ImgCmp                      OD Reserve
    {_COLOR_DEPTH_10_BITS, _OFF, _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
    {_COLOR_DEPTH_8_BITS,  _OFF, _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
    {_COLOR_DEPTH_8_BITS,  _ON,  _IMG_CMP_PARAM_OFF,         _OD_PARAM_OFF},
#endif
};
#endif

EnumODParamIndex code tODParam[] =
{
    _OD_PARAM_OFF,
#if(_OD_SUPPORT == _ON)
    _OD_PARAM_4_5_BPP,
    _OD_PARAM_6_0_BPP,
    _OD_PARAM_7_5_BPP,
#endif
};

#endif

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_FRC_SUPPORT == _ON)
DWORD g_ulFRCRowPerPath;
DWORD g_ulFRCBottom;
DWORD g_ulFRCUseRow;
DWORD g_ulFRCMainBW;
#if((_M_DOMAIN_IMG_CMP_SUPPORT == _ON) && (_HW_M_DOMAIN_IMG_CMP_TYPE == _M_DOMAIN_IMG_CMP_GEN_1))
bit g_bFRCModLenWtlvlStatus;
#endif
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)
void ScalerFRCPowerOnInitial(void);
#endif

#if(_HW_FRC_TYPE != _FRC_GEN_NONE)
void ScalerFRCInitial(void);
void ScalerFRCEn(BYTE ucSettingPath, bit bEn);
#endif

#if(_FRC_SUPPORT == _ON)
WORD ScalerFRCSetOneFrameDVTotal(void);
void ScalerFRCControl(const StructSDRAMDataInfo *pstFIFOSize);
void ScalerFRCInputCtrl(WORD usHorSize, WORD usVerSize);
void ScalerFRCDisplayCtrl(WORD usHorSize, WORD usVerSize);
void ScalerFRCSetFRCEnble(void);
DWORD ScalerFRCGetCapAddress(EnumFRCBlock enumBlock);
void ScalerFRCSetCapAddress(EnumFRCBlock enumBlock, DWORD ulCapAddress);
void ScalerFRCSetDispAddress(EnumFRCBlock enumBlock, DWORD ulDispAddress);
void ScalerFRCOneFrameCtrl(WORD usHorSize, WORD usVerSize);
void ScalerFRCCompareIHFandDHF(WORD usHorSize, WORD usVerSize);
void ScalerFRCWaitWriteFrameBufFinish(void);

bit ScalerFRCGetImgCmpHWUsability(void);
bit ScalerFRCGetImgCmpRunTimeUsability(WORD usWidth);
DWORD ScalerFRCGetPathMaxLineSumBitByBW(DWORD ulGrantBW, StructMemoryBWUsageParam *pstMemBWParam);
BYTE ScalerFRCGetMemRateCtrlParamIndex(StructFRCRateCtrlInfo *pstRateCtrlInfo);
void ScalerFRCApplyMemRateCtrlParam(BYTE ucRateCtrlParamIndex);
DWORD ScalerFRCGetLineSumBit(WORD usHorSize, BYTE ucFIFOMemBits, EnumImgCmpParamIndex enumImgCmpIndex);
void ScalerFRCSetMemoryBoundary(EnumFRCBoundary enumFRCBoundary);
BYTE ScalerFRCGettFRCRateCtrlParamCnt(void);
EnumImgCmpParamIndex ScalerFRCGetRcpImcCmpParamFromIndex(BYTE ucIndex);
BYTE ScalerFRCGetRcpFifoColorDepthFromIndex(BYTE ucIndex);
BYTE ScalerFRCGetRcpHsdEnFromIndex(BYTE ucIndex);
#if(_OD_SUPPORT == _ON)
EnumODParamIndex ScalerFRCGetRcpODParamFromIndex(BYTE ucIndex);
#endif

#if(_FREEZE_SUPPORT == _ON)
void ScalerFRCDisplayFreeze(bit bEn);
#endif
#if(_HW_ONE_FRAME_FRC_MAX_DROP_FRAME_SUPPORT == _ON)
bit ScalerFRCCheckDoubleFrameBuffer(void);
#endif

void ScalerFRCCalculateAddress(void);
void ScalerFRCSpaceInitialAllocation(void);
DWORD ScalerFRCBWCalUsage(WORD usCaphwidth, WORD usDisphwidth, WORD usColorDepth, EnumImgCmpParamIndex enumLLB, DWORD ulPixelclk, bit bDefaultMode);
void ScalerFRCSetDDomainSourceSelect(EnumDDomainSourceSelect enumSourceSelect);
EnumImgCmpParamIndex ScalerFRCImgCmpGetPara(void);
#if((_M_DOMAIN_IMG_CMP_SUPPORT == _ON) && (_HW_M_DOMAIN_IMG_CMP_TYPE == _M_DOMAIN_IMG_CMP_GEN_1))
bit ScalerFRCModLenWtlvl(void);
#endif
#endif
//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)
//--------------------------------------------------
// Description  : FRC Power on initial
// Input Value  :
// Output Value : None
//--------------------------------------------------
void ScalerFRCPowerOnInitial(void)
{
    ScalerSetByte(P5_A8_DISP_M1_READ_NUM_H, 0x00);
    ScalerSetByte(P5_A9_DISP_M1_READ_NUM_L, 0x01);

    // Set Length, Remain
    ScalerSetByte(P5_AA_DISP_M1_READ_LEN, _FRC_ACCESS_READ_LENGTH);
    ScalerSetByte(P5_AB_DISP_M1_READ_REMAIN, _FRC_ACCESS_READ_LENGTH);

    // Enable Display double buffer
    ScalerSetBit(P5_AD_DISP_M1_STATUS, ~_BIT4, _BIT4);

    ScalerFRCEn(_FRC_CAP_DISP_ALL, _DISABLE);
}
#endif // #if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)

#if(_HW_FRC_TYPE != _FRC_GEN_NONE)
//--------------------------------------------------
// Description  : FRC Initial
// Input Value  :
// Output Value : None
//--------------------------------------------------
void ScalerFRCInitial(void)
{
#if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)
#if(_FRC_SUPPORT == _ON)
    ScalerFRCCalculateAddress();
#endif // End of #if(_FRC_SUPPORT == _ON)

    // Set Capture Line Step
    ScalerSetBit(P5_19_CAP_M1_LINE_STEP_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetByte(P5_1A_CAP_M1_LINE_STEP_H, 0x00);
    ScalerSetByte(P5_1B_CAP_M1_LINE_STEP_M, 0x00);
    ScalerSetByte(P5_1C_CAP_M1_LINE_STEP_L, 0x00);

    // Set Display Line Step
    ScalerSetBit(P5_99_DISP_M1_LINE_STEP_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetByte(P5_9A_DISP_M1_LINE_STEP_H, 0x00);
    ScalerSetByte(P5_9B_DISP_M1_LINE_STEP_M, 0x00);
    ScalerSetByte(P5_9C_DISP_M1_LINE_STEP_L, 0x00);

    // Set Single Buffer Mode
    ScalerSetBit(P5_27_CAP_M1_DDR_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT1);

    // Set Line Mode / CAP Start Point to Change Block_sel = 1: Reference to vertical active region
    ScalerSetBit(P5_28_CAP_M1_DDR_CTRL2, ~(_BIT6 | _BIT4 | _BIT1 | _BIT0), _BIT6);

#if(_HW_FRC_TYPE == _FRC_GEN_2)
    // [0]:Set 3 Buffer Disable, [2]:Capture fifo from I domain
    ScalerSetBit(P5_29_CAP_M1_DDR_CTRL3, ~(_BIT2 | _BIT0), 0x00);
#else
    ScalerSetBit(P5_29_CAP_M1_DDR_CTRL3, ~(_BIT7 | _BIT2 | _BIT0), 0x00);
#endif
    // Disable One Frame FRC
    ScalerSetByte(P5_B1_DISP_M1_ONEF_DHF_H, 0x00);

    // Set Display :(1) FIFO Output to D-Domain, (2) Disable 3 Buffer
    ScalerSetBit(P5_AF_DISP_M1_DISP_CTRL3, ~(_BIT2 | _BIT0), 0x00);

#if(_HW_M_DOMAIN_IMG_CMP_TYPE == _M_DOMAIN_IMG_CMP_GEN_1) // RL6851 IMC follow RLE1039
    ScalerSetBit(P5_AE_DISP_M1_DISP_CTRL2, ~(_BIT7), 0x00);
#endif
    // Set double frame buffer disable
    ScalerSetBit(P5_AC_DISP_M1_DISP_CTRL1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), 0x00);

#if(_FRC_SUPPORT == _ON)
    // Disable M:N frame tracking
    if(GET_MEMORY_SELECT() != _MN_FRAME_SYNC_MEMORY)
    {
        ScalerMemorySetFrameTrackingEnable(_DISABLE);
    }
#endif
#endif // end of #if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)

    if(GET_MEMORY_SELECT() == _FRAME_SYNC_LINE_BUFFER)
    {
        ScalerFRCEn(_FRC_CAP_DISP_ALL, _ENABLE);

#if(_FRC_SUPPORT == _ON)
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
        ScalerImgCmpEn(_FRC_ALL_ONOFF, _DISABLE);
#endif
        ScalerFRCSetDDomainSourceSelect(_DDOMAIN_SRC_FRAM_FRAME_SYNC_MODE);
#endif

#if(_FRC_SUPPORT == _ON)
#if(_FW_FRC_DYNAMIC_SPACE_ALLOCATION == _ON)
        SET_FRC_TOTAL_USE_ROW(0);
        SET_FRC_BOTTOM_ADDR(0);
#endif
#endif
    }

#if(_FRC_SUPPORT == _ON)
#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
    // Disable HW auto block toggle
    ScalerFRCSetDisplayAutoBlkToggleEnable(_DISABLE);
#endif
#endif

    // Enable Display double buffer
    ScalerSetBit(P5_AD_DISP_M1_STATUS, ~_BIT4, _BIT4);

    // Wait double buffer
    if(ScalerGlobalGetDBStatus() == _DISABLE)
    {
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }
}

//--------------------------------------------------
// Description  : FRC function enable/disable
// Input Value  : ucSettingPath: path
// Input Value  : bEn: enable/disable
// Output Value : None
//--------------------------------------------------
void ScalerFRCEn(BYTE ucSettingPath, bit bEn)
{
    EnumFRCOnOff enumCapDispOnOff = _FRC_ALL_ONOFF;

    switch(ucSettingPath)
    {
        case _FRC_CAP_DISP_ALL:
        default:
            break;

        case _FRC_CAP_MAIN_1:
            enumCapDispOnOff = _FRC_CAPTURE_ONOFF;
            break;

        case _FRC_DISP_MAIN_1:
            enumCapDispOnOff = _FRC_DISPLAY_ONOFF;
            break;
    }

#if((_FRC_SUPPORT == _ON) && (_M_DOMAIN_IMG_CMP_SUPPORT == _ON))
    ScalerImgCmpEn(enumCapDispOnOff, bEn);
#endif

    if(bEn == _DISABLE)
    {
        if((enumCapDispOnOff & _FRC_CAPTURE_ONOFF) == _FRC_CAPTURE_ONOFF)
        {
            if((ScalerGlobalGetDBStatus() == _DISABLE) && (ScalerGetBit(P0_10_M1_VGIP_CTRL, _BIT0) == _BIT0))
            {
                // Wait _EVENT_IEN_STOP before FRC Capture Disable
                ScalerTimerWaitForEvent(_EVENT_IEN_STOP);
            }

            // Disable Capture Block
            ScalerSetBit(P5_27_CAP_M1_DDR_CTRL1, ~(_BIT7), 0x00);
        }
    }
    else
    {
        if((enumCapDispOnOff & _FRC_CAPTURE_ONOFF) == _FRC_CAPTURE_ONOFF)
        {
            if(ScalerGetBit(P5_27_CAP_M1_DDR_CTRL1, _BIT7) == 0x00)
            {
                // Enable Capture Block
                ScalerSetBit(P5_27_CAP_M1_DDR_CTRL1, ~(_BIT7), _BIT7);
            }
        }
    } // End of if(bEn == _DISABLE)

    // Enable FRC display stop burst en
    ScalerSetBit(P5_AE_DISP_M1_DISP_CTRL2, ~(_BIT0), _BIT0);

    if(bEn == _DISABLE)
    {
        if((enumCapDispOnOff & _FRC_DISPLAY_ONOFF) == _FRC_DISPLAY_ONOFF)
        {
            // Disable Display Block
            ScalerSetBit(P5_AC_DISP_M1_DISP_CTRL1, ~(_BIT0), 0x00);
        }
    }
    else
    {
        if((enumCapDispOnOff & _FRC_DISPLAY_ONOFF) == _FRC_DISPLAY_ONOFF)
        {
            if(ScalerGetBit(P5_AC_DISP_M1_DISP_CTRL1, _BIT0) == 0x00)
            {
                // Enable Display block
                ScalerSetBit(P5_AC_DISP_M1_DISP_CTRL1, ~(_BIT0), _BIT0);
            }
        }
    } // End of if(bEn == _DISABLE)

    // Enable Double buffer
    ScalerSetBit(P5_AD_DISP_M1_STATUS, ~(_BIT4), _BIT4);

    if(((enumCapDispOnOff & _FRC_DISPLAY_ONOFF) != 0) && (ScalerGlobalGetDBStatus() == _DISABLE))
    {
        // Wait double buffer
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }
}
#endif // End of #if(_HW_FRC_TYPE != _FRC_GEN_NONE)

#if(_FRC_SUPPORT == _ON)
//-------------------------------------------------
// Description  : Calculate DVTotal for OneFrame FRC
// Input Value  : None
// Output Value : usDVTotal
//-------------------------------------------------
WORD ScalerFRCSetOneFrameDVTotal(void)
{
    DWORD ulFrameDiff = 0;
    DWORD ulActiveRegionDiff = 0;
    WORD usIHF = 0;
    WORD usDHF = 0;
    WORD usDVTotal = 0;

    if((DWORD)GET_MDOMAIN_OUTPUT_VHEIGHT() * 1066 / 1000 < _PANEL_DV_TOTAL)
    {
        usDHF = (DWORD)g_usMDomainDVFreq * _PANEL_DV_TOTAL / 1000;
    }
    else
    {
        usDHF = (DWORD)g_usMDomainDVFreq * (DWORD)GET_MDOMAIN_OUTPUT_VHEIGHT() * 1066 / 1000 / 1000;
    }

    usIHF = (DWORD)GET_MDOMAIN_INPUT_VFREQ() * GET_MDOMAIN_INPUT_VTOTAL() / 1000;
    ulFrameDiff = (DWORD)1000 * ((DWORD)1000 * GET_MDOMAIN_INPUT_VFREQ() - (DWORD)1000 * g_usMDomainDVFreq) / ((DWORD)GET_MDOMAIN_INPUT_VFREQ() * g_usMDomainDVFreq);
    ulActiveRegionDiff = (DWORD) 1000 * ((DWORD)GET_MDOMAIN_OUTPUT_VHEIGHT() * usIHF - (DWORD)GET_MDOMAIN_INPUT_VHEIGHT() * usDHF) / ((DWORD)usIHF * usDHF);

    // If((Input frame ahead) < 0.8*(Conflict region)), Then DVT = DVH / ((Input Frame ahead)*0.8 + IVH/IHF) * (1/DVF).
    // Else if(DVH*1.66 < DVT), Then DVT = Panel_DVT.
    // Else DVT = DVH*1.66
    if((ulFrameDiff * 100 / ulActiveRegionDiff) < 125)
    {
        usDVTotal = (DWORD)1000 * GET_MDOMAIN_OUTPUT_VHEIGHT() / ((ulFrameDiff * 100 / 125) + ((DWORD)1000 * GET_MDOMAIN_INPUT_VHEIGHT() / usIHF)) * 1000 / g_usMDomainDVFreq;
    }
    else if((DWORD)GET_MDOMAIN_OUTPUT_VHEIGHT() * 1066 / 1000 < _PANEL_DV_TOTAL)
    {
        usDVTotal = _PANEL_DV_TOTAL;
    }
    else
    {
        usDVTotal = (DWORD)GET_MDOMAIN_OUTPUT_VHEIGHT() * 1066 / 1000;
    }

    if(usDVTotal > _PANEL_DV_TOTAL_MAX)
    {
        usDVTotal = _PANEL_DV_TOTAL_MAX;
    }
    else if(usDVTotal < _PANEL_DV_TOTAL_MIN)
    {
        usDVTotal = _PANEL_DV_TOTAL_MIN;
    }

    return usDVTotal;
}

//--------------------------------------------------
// Description  : FRC control
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerFRCControl(const StructSDRAMDataInfo *pstFIFOSize)
{
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
    // Set ImgCmp param
    ScalerImgCmpCtrl(pstFIFOSize->usInputHWidth, pstFIFOSize->usInputVHeight, GET_IMG_CMP_PARAM());
#endif

    ScalerFRCSetMemoryBoundary(_FRC_BOUNDARY_DEFAULT);

    // -----------------------
    // Set FRC IVS2DVSDelay
    // -----------------------
    ScalerFRCAdjustIVS2DVSDelay();

    // -----------------------
    // Consider Input Faster Or Slower
    // -----------------------
    ScalerFRCCompareIHFandDHF(pstFIFOSize->usInputHWidth, pstFIFOSize->usInputVHeight);

    // -----------------------
    // Set Frame tracking function for VFreq < 30Hz
    // -----------------------
    if(GET_MEMORY_SELECT() == _MN_FRAME_SYNC_MEMORY)
    {
        ScalerMemoryFrameTracking();
        ScalerMemorySetFrameTrackingEnable(_ENABLE);

#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
        if(GET_FRC_3BLOCK_TOGGLE_STATUS() == _ENABLE)
        {
            ScalerFRCSetDisplayAutoBlkToggleEnable(_ENABLE);
        }
#endif
    }
    // -----------------------
    // Set Up FRC Capture
    // -----------------------
    ScalerFRCInputCtrl(pstFIFOSize->usInputHWidth, pstFIFOSize->usInputVHeight);

    // -----------------------
    // Set Up FRC Display
    // -----------------------
    ScalerFRCDisplayCtrl(pstFIFOSize->usInputHWidth, pstFIFOSize->usInputVHeight);

    // -----------------------
    // Enable FRC
    // -----------------------

    // Wait I-domain Stable Before FRC enable
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);

    ScalerFRCSetFRCEnble();

    // Enable FRC Display Double buffer
    ScalerSetBit(P5_AD_DISP_M1_STATUS, ~(_BIT4), _BIT4);

    // Wait _EVENT_IVS For FRC Run In Single Frame Buffer
    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);

    // -----------------------
    // Set Double / Single Frame Buffer
    // -----------------------
    // Wait _EVENT_IEN_START Before Double Frame Buffer Setting
    ScalerTimerWaitForEvent(_EVENT_IEN_START);

    switch(GET_MEMORY_FRAME_BUFFER())
    {
        case _MEMORY_1_FRAME_BUFFER:
        default:

            // Set Single Buffer, auto block toggle using 1.5 buffer, also set single buffer
            ScalerSetBit(P5_27_CAP_M1_DDR_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), 0x00);
            ScalerSetBit(P5_AC_DISP_M1_DISP_CTRL1, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
            break;

        case _MEMORY_2_FRAME_BUFFER:

            // Set Double Buffer
            ScalerSetBit(P5_27_CAP_M1_DDR_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT5);
            ScalerSetBit(P5_AC_DISP_M1_DISP_CTRL1, ~(_BIT6 | _BIT5 | _BIT4), _BIT6);
            break;

        case _MEMORY_3_FRAME_BUFFER:

            // Set Double Buffer
            ScalerSetBit(P5_27_CAP_M1_DDR_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT5);
            ScalerSetBit(P5_AC_DISP_M1_DISP_CTRL1, ~(_BIT6 | _BIT5 | _BIT4), _BIT6);

            // Set 3 Buffer
            ScalerSetBit(P5_29_CAP_M1_DDR_CTRL3, ~(_BIT0), _BIT0);
            ScalerSetBit(P5_AF_DISP_M1_DISP_CTRL3, ~(_BIT0), _BIT0);
            break;
    }

    // Enable FRC Display Double buffer
    ScalerSetBit(P5_AD_DISP_M1_STATUS, ~(_BIT4), _BIT4);

#if(_HW_FRC_FRAME_TEAR_PREVENTION_SUPPORT == _ON)
    // Prevent frame tear, only support under memory work mode, doesn't support under one frame frc and 1.5 frame buffer
    if(((GET_MEMORY_FRAME_BUFFER() == _MEMORY_1_FRAME_BUFFER) && (GET_MEMORY_SELECT() == _FREE_RUN_MEMORY)) || (GET_MEMORY_FRAME_BUFFER() == _MEMORY_1_5_FRAME_BUFFER))
    {
        ScalerSetByte(P5_E9_DISP_M1_FRAME_TEAR_PREVENTION, 0x00);
    }
    else
    {
        if(GET_IMG_CMP_ENABLE(GET_IMG_CMP_PARAM()) == _TRUE)
        {
            ScalerSetBit(P5_E9_DISP_M1_FRAME_TEAR_PREVENTION, ~(_BIT6), _BIT6);
            ScalerSetBit(P5_E9_DISP_M1_FRAME_TEAR_PREVENTION, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x02);
        }
        else
        {
            ScalerSetByte(P5_E9_DISP_M1_FRAME_TEAR_PREVENTION, 0x00);
        }
    }
#endif

    // Wait double buffer
    ScalerTimerWaitForEvent(_EVENT_DVS);

    DebugMessageFRC("FRC-H", pstFIFOSize->usInputHWidth);
    DebugMessageFRC("FRC-V", pstFIFOSize->usInputVHeight);
}

//--------------------------------------------------
// Description  : IN1 FIFO Setting for FRC Mode
// Input Value  : ucHorSize --> Horizontal size
//                ucVerSize --> Vertical Size
// Output Value : None
//--------------------------------------------------
void ScalerFRCInputCtrl(WORD usHorSize, WORD usVerSize)
{
    StructMemoryLineBlockStep stStep;
    DWORD ulTemp = 0;
    DWORD ulLinetotalpixel = 0;
    BYTE ucLen = 0;

    memset(&stStep, 0, sizeof(StructMemoryLineBlockStep));

    ulLinetotalpixel = ScalerFRCGetLineSumBit(usHorSize, GET_MEMORY_DATA_BIT(), GET_IMG_CMP_PARAM());

    // Calculate Line Mode Size
    ulLinetotalpixel = CEILING_OF_INT_DIVISION(ulLinetotalpixel, _FRC_UNIT);

    // Calculate Line Step and Block Step
    ScalerMemoryCalculateLineStepAndBlockStep(ulLinetotalpixel, usVerSize, &stStep);

#if(_FW_FRC_DYNAMIC_SPACE_ALLOCATION == _ON)
    // Do not change address if HSD is caused by space/BW insufficient!!!
    if(GET_FRC_RCP_HSD_EN(GET_MDOMAIN_FRC_CTRL_PARAM_INDEX()) == _FALSE)
    {
        ScalerFRCSetCapAddress(_FRC_1ST_BLOCK, ScalerFRCGetCapAddress(_FRC_2ND_BLOCK) + stStep.ulBlockStep);
    }

#if(_HW_ONE_FRAME_FRC_MAX_DROP_FRAME_SUPPORT == _ON)
    if(GET_MEMORY_FRAME_BUFFER() == _MEMORY_1_FRAME_BUFFER)
    {
        ScalerFRCSetCapAddress(_FRC_1ST_BLOCK, ScalerFRCGetCapAddress(_FRC_2ND_BLOCK));
    }
#endif
    PDATA_DWORD(0) = ScalerFRCGetCapAddress(_FRC_1ST_BLOCK) >> _FW_MEM_ROW_ADDR_SHIFT_BIT_NUM;
    PDATA_DWORD(0) += GET_DEFAULT_FRAME_USE_MEMORY_ROW(stStep.ulBlockStep * _FRC_UNIT);

    SET_FRC_TOTAL_USE_ROW(PDATA_DWORD(0)); // unit: memory row
    SET_FRC_BOTTOM_ADDR(ScalerFRCGetCapAddress(_FRC_1ST_BLOCK) + stStep.ulBlockStep); // unit: memory row << _HW_DDR_ROW_ADDR_SHIFT_BIT_NUM
#endif

#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
    // Set M:N auto block toggle
    if(GET_FRC_3BLOCK_TOGGLE_STATUS() == _ENABLE)
    {
        ScalerFRCSetInputAutoBlkToggle();
        SET_FRC_TOTAL_USE_ROW(GET_DEFAULT_FRAME_USE_MEMORY_ROW(stStep.ulBlockStep * _FRC_UNIT)); // unit: memory row
        SET_FRC_BOTTOM_ADDR((DWORD)(GET_DEFAULT_FRAME_USE_MEMORY_ROW(stStep.ulBlockStep * _FRC_UNIT)) << _FW_MEM_ROW_ADDR_SHIFT_BIT_NUM); // unit: memory row << _HW_DDR_ROW_ADDR_SHIFT_BIT_NUM
    }
#endif

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
#if(_HW_M_DOMAIN_IMG_CMP_TYPE == _M_DOMAIN_IMG_CMP_GEN_1)
    // ScalerFRCModLenWtlvl use GET_FRC_TOTAL_USE_ROW() for calculation! Make sure to call ScalerFRCModLenWtlvl after all SET_FRC_TOTAL_USE_ROW()
    SET_MOD_FRC_LEN_WTLVL_STATUS(ScalerFRCModLenWtlvl());
#endif
    // Set Cap FIFO source: I-Domain/PQC
    if(GET_IMG_CMP_ENABLE(GET_IMG_CMP_PARAM()) == _TRUE)
    {
        ScalerSetBit(P5_29_CAP_M1_DDR_CTRL3, ~(_BIT2), _BIT2);
    }
    else
#endif
    {
        ScalerSetBit(P5_29_CAP_M1_DDR_CTRL3, ~(_BIT2), 0x00);
    }

    ucLen = _FRC_ACCESS_WRITE_LENGTH;

    PDATA_DWORD(0) = ulLinetotalpixel;

    // Calculate Number of One Line and Remain of One Line
    ulTemp = ScalerMemoryCalculateNumberAndRemain(PDATA_DWORD(0), ucLen, 1);

    // Set Line Mode
    ScalerSetBit(P5_28_CAP_M1_DDR_CTRL2, ~(_BIT4), 0x00);

    // Set Block Step
    ScalerSetBit(P5_15_CAP_M1_BLOCK_STEP_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((stStep.ulBlockStep >> 24) & 0x0F));
    ScalerSetByte(P5_16_CAP_M1_BLOCK_STEP_H, ((stStep.ulBlockStep >> 16) & 0xFF));
    ScalerSetByte(P5_17_CAP_M1_BLOCK_STEP_M, ((stStep.ulBlockStep >> 8) & 0xFF));
    ScalerSetByte(P5_18_CAP_M1_BLOCK_STEP_L, (stStep.ulBlockStep & 0xFF));

    // Set Water level
    ScalerSetByte(P5_1E_CAP_M1_WATER_LEVEL_L, (((WORD)ucLen / 2) & 0xFF));

    // Set Pixel Nmber
    ScalerSetByte(P5_1F_CAP_M1_PIXEL_NUM_H, HIBYTE(usHorSize));
    ScalerSetByte(P5_20_CAP_M1_PIXEL_NUM_L, LOBYTE(usHorSize));

    // Set Line Number
    ScalerSetByte(P5_21_CAP_M1_LINE_NUM_H, HIBYTE(usVerSize));
    ScalerSetByte(P5_22_CAP_M1_LINE_NUM_L, LOBYTE(usVerSize));

    // Set Number
    ScalerSetByte(P5_23_CAP_M1_WR_NUM_H, ((ulTemp >> 8) & 0xFF));
    ScalerSetByte(P5_24_CAP_M1_WR_NUM_L, (ulTemp & 0xFF));

    // Set Length, Remain
    ScalerSetByte(P5_25_CAP_M1_WR_LEN, ucLen);
    ScalerSetByte(P5_26_CAP_M1_WR_REMAIN, ((ulTemp >> 16) & 0xFF));

    // Set Line step
    ScalerSetBit(P5_19_CAP_M1_LINE_STEP_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((BYTE)(stStep.ulLineStep >> 24) & 0x0F));
    ScalerSetByte(P5_1A_CAP_M1_LINE_STEP_H, (BYTE)(stStep.ulLineStep >> 16));
    ScalerSetByte(P5_1B_CAP_M1_LINE_STEP_M, (BYTE)(stStep.ulLineStep >> 8));
    ScalerSetByte(P5_1C_CAP_M1_LINE_STEP_L, (BYTE)(stStep.ulLineStep >> 0));

    // Use IVS as synchronous reset
    ScalerSetBit(P5_27_CAP_M1_DDR_CTRL1, ~(_BIT1), _BIT1);
}

//--------------------------------------------------
// Description  : MAIN FIFO Setting for FRC Mode
// Input Value  : usHorSize --> Horizontal size
//                usVerSize --> Vertical Size
// Output Value : None
//--------------------------------------------------
void ScalerFRCDisplayCtrl(WORD usHorSize, WORD usVerSize)
{
    StructMemoryLineBlockStep stStep;
    DWORD ulTemp = 0;
    DWORD ulLinetotalpixel = 0;
    WORD usPreReadLine = 0;
    BYTE ucLen = _FRC_ACCESS_READ_LENGTH;

    memset(&stStep, 0, sizeof(StructMemoryLineBlockStep));

    usPreReadLine = ScalerFRCCalculatePreReadLine();

    ulLinetotalpixel = ScalerFRCGetLineSumBit(usHorSize, GET_MEMORY_DATA_BIT(), GET_IMG_CMP_PARAM());

    // Calculate Line Mode Size
    ulLinetotalpixel = CEILING_OF_INT_DIVISION(ulLinetotalpixel, _FRC_UNIT);

    // Calculate Line Step And Block Step
    ScalerMemoryCalculateLineStepAndBlockStep(ulLinetotalpixel, usVerSize, &stStep);

    // Calculate Number of One Line and Remain of One Line
    ulTemp = ScalerMemoryCalculateNumberAndRemain(ulLinetotalpixel, ucLen, 1);

#if(_FW_FRC_DYNAMIC_SPACE_ALLOCATION == _ON)
    ScalerFRCSetDispAddress(_FRC_1ST_BLOCK, ScalerFRCGetCapAddress(_FRC_1ST_BLOCK));
#endif

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
    // Set Disp FIFO output: D-Domain/PQC
    if(GET_IMG_CMP_ENABLE(GET_IMG_CMP_PARAM()) == _TRUE)
    {
        ScalerSetBit(P5_AF_DISP_M1_DISP_CTRL3, ~(_BIT2), _BIT2);
#if(_HW_M_DOMAIN_IMG_CMP_TYPE == _M_DOMAIN_IMG_CMP_GEN_1)
        ScalerSetBit(P5_AE_DISP_M1_DISP_CTRL2, ~(_BIT7), _BIT7);
#endif
    }
    else
#endif
    {
        ScalerSetBit(P5_AF_DISP_M1_DISP_CTRL3, ~(_BIT2), 0x00);
    }

    // Set Block Step
    ScalerSetBit(P5_95_DISP_M1_BLOCK_STEP_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((stStep.ulBlockStep >> 24) & 0x0F));
    ScalerSetByte(P5_96_DISP_M1_BLOCK_STEP_H, ((stStep.ulBlockStep >> 16) & 0xFF));
    ScalerSetByte(P5_97_DISP_M1_BLOCK_STEP_M, ((stStep.ulBlockStep >> 8) & 0xFF));
    ScalerSetByte(P5_98_DISP_M1_BLOCK_STEP_L, (stStep.ulBlockStep & 0xFF));

    // Set Line Step
    ScalerSetBit(P5_99_DISP_M1_LINE_STEP_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((stStep.ulLineStep >> 24) & 0x0F));
    ScalerSetByte(P5_9A_DISP_M1_LINE_STEP_H, ((stStep.ulLineStep >> 16) & 0xFF));
    ScalerSetByte(P5_9B_DISP_M1_LINE_STEP_M, ((stStep.ulLineStep >> 8) & 0xFF));
    ScalerSetByte(P5_9C_DISP_M1_LINE_STEP_L, (stStep.ulLineStep & 0xFF));

    // Set Water Level
    // Display Water Level < FIFO Depth (512) - Length / 2
    ScalerSetByte(P5_A1_DISP_M1_WTLVL_L, (BYTE)(_FRC_DISP_WTLVL & 0xFF));

    // Set Pixel Number
    ScalerSetByte(P5_A2_DISP_M1_PXL_NUM_H, HIBYTE(usHorSize));
    ScalerSetByte(P5_A3_DISP_M1_PXL_NUM_L, LOBYTE(usHorSize));

    // Set Line number
    ScalerSetByte(P5_A4_DISP_M1_LINE_NUM_H, HIBYTE(usVerSize));
    ScalerSetByte(P5_A5_DISP_M1_LINE_NUM_L, LOBYTE(usVerSize));

    ScalerSetByte(P5_A6_DISP_M1_PRRD_VST_H, HIBYTE(usPreReadLine));
    ScalerSetByte(P5_A7_DISP_M1_PRRD_VST_L, LOBYTE(usPreReadLine));

    // Set Number
    ScalerSetByte(P5_A8_DISP_M1_READ_NUM_H, ((ulTemp >> 8) & 0xFF));
    ScalerSetByte(P5_A9_DISP_M1_READ_NUM_L, (ulTemp & 0xFF));

    // Set Length, Remain
    ScalerSetByte(P5_AA_DISP_M1_READ_LEN, ucLen);
    ScalerSetByte(P5_AB_DISP_M1_READ_REMAIN, ((ulTemp >> 16) & 0xFF));

    // Set Line mode
    ScalerSetBit(P5_AC_DISP_M1_DISP_CTRL1, ~_BIT7, 0x00);

#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
    if(GET_FRC_3BLOCK_TOGGLE_STATUS() == _ENABLE)
    {
        ScalerFRCSetDisplayAutoBlkToggle();
        ScalerFRCSetHWAutoBlockToggle();
    }
#endif

    // Set Using Information From FRC Capture
    ScalerFRCSetDDomainSourceSelect(_DDOMAIN_SRC_FRAM_FRC);

    ScalerSetBit(P5_AD_DISP_M1_STATUS, ~_BIT4, _BIT4);
    ScalerTimerWaitForEvent(_EVENT_DVS);
}

//--------------------------------------------------
// Description  : FRC Capture and Display Enable Setting
// Input Value  : ON --> Freeze
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetFRCEnble(void)
{
    // -- 1 -- Enable FRC Capture
    ScalerFRCEn(_FRC_CAP_MAIN_1, _ENABLE);

    // -- 2 -- Enable FRC Display
    ScalerFRCEn(_FRC_DISP_MAIN_1, _ENABLE);
}

//--------------------------------------------------
// Description  : Get FRC Capture address
// Input Value  : usSelectedPage: FRC page, ucBlock: Capture Block
// Output Value : address
//--------------------------------------------------
DWORD ScalerFRCGetCapAddress(EnumFRCBlock enumBlock)
{
    // affect scaler.GLOBAL
    // to do
    switch(enumBlock)
    {
        case _FRC_1ST_BLOCK:
        default:

            PDATA_DWORD(0) = (((DWORD)ScalerGetBit(P5_00_CAP_M1_MEM_ADDR_MSB, 0x0F) << 24) |
                              ((DWORD)ScalerGetByte(P5_01_CAP_M1_MEM_ADDR_H) << 16) |
                              ((DWORD)ScalerGetByte(P5_02_CAP_M1_MEM_ADDR_M) << 8) |
                              ((DWORD)ScalerGetByte(P5_03_CAP_M1_MEM_ADDR_L)));
            break;

        case _FRC_2ND_BLOCK:

            PDATA_DWORD(0) = (((DWORD)ScalerGetBit(P5_04_CAP_M1_BL2_ADDR_MSB, 0x0F) << 24) |
                              ((DWORD)ScalerGetByte(P5_05_CAP_M1_BL2_ADDR_H) << 16) |
                              ((DWORD)ScalerGetByte(P5_06_CAP_M1_BL2_ADDR_M) << 8) |
                              ((DWORD)ScalerGetByte(P5_07_CAP_M1_BL2_ADDR_L)));
            break;

        case _FRC_3RD_BLOCK:

            PDATA_DWORD(0) = (((DWORD)ScalerGetBit(P5_08_CAP_M1_BL3_ADDR_MSB, 0x0F) << 24) |
                              ((DWORD)ScalerGetByte(P5_09_CAP_M1_BL3_ADDR_H) << 16) |
                              ((DWORD)ScalerGetByte(P5_0A_CAP_M1_BL3_ADDR_M) << 8) |
                              ((DWORD)ScalerGetByte(P5_0B_CAP_M1_BL3_ADDR_L)));
            break;

#if(_HW_FRC_TYPE == _FRC_GEN_2)
        case _FRC_4TH_BLOCK:

            PDATA_DWORD(0) = (((DWORD)ScalerGetBit(P5_46_CAP_M1_BL4_ADDR_MSB, 0x0F) << 24) |
                              ((DWORD)ScalerGetByte(P5_47_CAP_M1_BL4_ADDR_H) << 16) |
                              ((DWORD)ScalerGetByte(P5_48_CAP_M1_BL4_ADDR_M) << 8) |
                              ((DWORD)ScalerGetByte(P5_49_CAP_M1_BL4_ADDR_L)));
            break;
#endif
    }

    return PDATA_DWORD(0);
}

//--------------------------------------------------
// Description  : Set FRC Capture address
// Input Value  : usSelectedPage: FRC page, ucBlock: Capture Block, ulCapAddress
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetCapAddress(EnumFRCBlock enumBlock, DWORD ulCapAddress)
{
    // affect scaler.GLOBAL
    // to do
    switch(enumBlock)
    {
        case _FRC_1ST_BLOCK:
        default:
            ScalerSetBit(P5_00_CAP_M1_MEM_ADDR_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ulCapAddress >> 24) & 0x0F));
            ScalerSetByte(P5_01_CAP_M1_MEM_ADDR_H, ((ulCapAddress >> 16) & 0xFF));
            ScalerSetByte(P5_02_CAP_M1_MEM_ADDR_M, ((ulCapAddress >> 8) & 0xFF));
            ScalerSetByte(P5_03_CAP_M1_MEM_ADDR_L, (ulCapAddress & 0xFF));
            break;

        case _FRC_2ND_BLOCK:

            ScalerSetBit(P5_04_CAP_M1_BL2_ADDR_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ulCapAddress >> 24) & 0x0F));
            ScalerSetByte(P5_05_CAP_M1_BL2_ADDR_H, ((ulCapAddress >> 16) & 0xFF));
            ScalerSetByte(P5_06_CAP_M1_BL2_ADDR_M, ((ulCapAddress >> 8) & 0xFF));
            ScalerSetByte(P5_07_CAP_M1_BL2_ADDR_L, (ulCapAddress & 0xFF));
            break;

        case _FRC_3RD_BLOCK:

            ScalerSetBit(P5_08_CAP_M1_BL3_ADDR_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ulCapAddress >> 24) & 0x0F));
            ScalerSetByte(P5_09_CAP_M1_BL3_ADDR_H, ((ulCapAddress >> 16) & 0xFF));
            ScalerSetByte(P5_0A_CAP_M1_BL3_ADDR_M, ((ulCapAddress >> 8) & 0xFF));
            ScalerSetByte(P5_0B_CAP_M1_BL3_ADDR_L, (ulCapAddress & 0xFF));
            break;

#if(_HW_FRC_TYPE == _FRC_GEN_2)
        case _FRC_4TH_BLOCK:

            ScalerSetBit(P5_46_CAP_M1_BL4_ADDR_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ulCapAddress >> 24) & 0x0F));
            ScalerSetByte(P5_47_CAP_M1_BL4_ADDR_H, ((ulCapAddress >> 16) & 0xFF));
            ScalerSetByte(P5_48_CAP_M1_BL4_ADDR_M, ((ulCapAddress >> 8) & 0xFF));
            ScalerSetByte(P5_49_CAP_M1_BL4_ADDR_L, (ulCapAddress & 0xFF));
            break;
#endif
    }
}

//--------------------------------------------------
// Description  : Set FRC Display address
// Input Value  : usSelectedPage: FRC page, ucBlock: Capture Block, ulCapAddress
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetDispAddress(EnumFRCBlock enumBlock, DWORD ulDispAddress)
{
    switch(enumBlock)
    {
        case _FRC_1ST_BLOCK:
        default:

            ScalerSetBit(P5_80_DISP_M1_READ_ADDR_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ulDispAddress >> 24) & 0x0F));
            ScalerSetByte(P5_81_DISP_M1_READ_ADDR_H, ((ulDispAddress >> 16) & 0xFF));
            ScalerSetByte(P5_82_DISP_M1_READ_ADDR_M, ((ulDispAddress >> 8) & 0xFF));
            ScalerSetByte(P5_83_DISP_M1_READ_ADDR_L, (ulDispAddress & 0xFF));
            break;

        case _FRC_2ND_BLOCK:

            ScalerSetBit(P5_84_DISP_M1_BL2_ADDR_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ulDispAddress >> 24) & 0x0F));
            ScalerSetByte(P5_85_DISP_M1_BL2_ADDR_H, ((ulDispAddress >> 16) & 0xFF));
            ScalerSetByte(P5_86_DISP_M1_BL2_ADDR_M, ((ulDispAddress >> 8) & 0xFF));
            ScalerSetByte(P5_87_DISP_M1_BL2_ADDR_L, (ulDispAddress & 0xFF));
            break;

        case _FRC_3RD_BLOCK:

            ScalerSetBit(P5_88_DISP_M1_BL3_ADDR_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ulDispAddress >> 24) & 0x0F));
            ScalerSetByte(P5_89_DISP_M1_BL3_ADDR_H, ((ulDispAddress >> 16) & 0xFF));
            ScalerSetByte(P5_8A_DISP_M1_BL3_ADDR_M, ((ulDispAddress >> 8) & 0xFF));
            ScalerSetByte(P5_8B_DISP_M1_BL3_ADDR_L, (ulDispAddress & 0xFF));
            break;

#if(_HW_FRC_TYPE == _FRC_GEN_2)
        case _FRC_4TH_BLOCK:

            ScalerSetBit(P5_DE_DISP_M1_BL4_ADDR_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ulDispAddress >> 24) & 0x0F));
            ScalerSetByte(P5_DF_DISP_M1_BL4_ADDR_H, ((ulDispAddress >> 16) & 0xFF));
            ScalerSetByte(P5_E0_DISP_M1_BL4_ADDR_M, ((ulDispAddress >> 8) & 0xFF));
            ScalerSetByte(P5_E1_DISP_M1_BL4_ADDR_L, (ulDispAddress & 0xFF));
            break;
#endif
    }
}

//--------------------------------------------------
// Description  : Set OneFrame FRC
// Input Value  : IHF, DHF
// Output Value : None
//--------------------------------------------------
void ScalerFRCOneFrameCtrl(WORD usHorSize, WORD usVerSize)
{
    bit bAutoMode = _ENABLE; // 1:auto mode; 0:manual mode
    WORD usPreRead = 0;
    WORD usLength = usVerSize;
    SWORD shMargin = 0;
    DWORD ulIHF = 0x00;
    DWORD ulDHF = 0x00;

    /// 1. Only if meet the following check condition, Write data to Memory:
    /// (1) Input Faster :
    ///      1. When R-FIFO is working check:  (IHP' * Length) > (DHP' * (Remain + Line_Margin)) --> (DHF' * Length) > (IHF' * (Remain + LIne_Margin))
    ///      2. When R-FIFO is idle check:     [W-FIFO starts] before [R-FIFO starts + Margin]
    /// (2) Input Slower :
    ///      1. When R-FIFO is working:  ((IHP' - DHP') * Length) < (DHP'* (Remain + Line_Margin)) --> ((DHF' - IHF')* Length) < ((DHF' * (Remain + Line_Margin)))
    ///      2. When R-FIFO is idle: Porch > [(IHP' - DHP') * Length ] / DHP'
    /// 2. Remain Value:
    /// (1) Input Faster :
    ///    if ( pre_read_trig | (pre_cnt > pre_read_margin) )
    ///       Remain = line_counter
    ///    else
    ///       Remain = 0
    /// (2) Input Slower :
    ///    if ( line_counter < (length-1) )
    ///       Remain = line_counter
    ///    else
    ///       Remain = 0

    // IHF' = IHF * (Length after SD / Length before SD) -> IHF to Mdomain
    ulIHF = (DWORD)GET_MDOMAIN_INPUT_HFREQ() * usVerSize / GET_MDOMAIN_INPUT_VHEIGHT();
    // DHF' = DHF * (Length before SU / Length after SU) -> DHF to Mdomain
    ulDHF = ((DWORD)GET_DWORD_MUL_DIV((GET_D_CLK_FREQ() * 10), usVerSize, ((DWORD)GET_MDOMAIN_OUTPUT_HTOTAL() * GET_MDOMAIN_OUTPUT_VHEIGHT())));

    // 256*128(frc fifo)/(length * imc 6bit) + 2 (d line buffer) + 9467(imc dec fifo)/length
    // imc dec fifo: str buffer is 320 * 128 / 6 bit = 6827 pixel; line buffer is 880 * 114 bit = 880 * 3 pixel
    // dvst need to enlarge when imc is on
    PDATA_WORD(0) = ((CEILING_OF_INT_DIVISION(14929, usHorSize) * ulDHF / ulIHF) + 1) & 0xFFFE;
    DebugMessageFRC("One Frame FRC Dvst minimum", PDATA_WORD(0));

    // Input Faster Case
    if(ScalerGetBit(P5_AC_DISP_M1_DISP_CTRL1, _BIT3) == _BIT3)
    {
        // preread margin set 0 by experiment, aviod write data to Memory from ivs rising
        usPreRead = 0;

        // Assume IHF_M = 37.48KHz, if input faster, IHF_M set 38, else set 37.
        ulIHF = (ulIHF % 10) ? (ulIHF / 10 + 1) : (ulIHF / 10);

        /// Set Line Margin
        ///      Auto mode : margin to avoid frame tear, range from -2048 to 2047
        ///      Manual mode : decide whether write data to Memory or not

        // line margin set 0x10 by experiment
        shMargin = 0x10;

        // Input faster case : DHF * Length
        ulDHF = ulDHF * usLength / 10;
    }
    else
    {
        shMargin = 0xFFE; // set -2.

        usPreRead = usLength - 2; // preread margin = line num - n, n is usPreRead.

        // Input Slower Case : (DHF - IHF) * Length
        ulDHF = (ulDHF - ulIHF) * usLength / 10;
        ulIHF = (DWORD)ulIHF / 10;
    }

    // Set FRC M1
    ScalerSetByte(P5_B1_DISP_M1_ONEF_DHF_H, ((ulDHF >> 16) | ((BYTE)bAutoMode << 6) | (_BIT7)));
    ScalerSetByte(P5_B2_DISP_M1_ONEF_DHF_M, (BYTE)(ulDHF >> 8));
    ScalerSetByte(P5_B3_DISP_M1_ONEF_DHF_L, (BYTE)ulDHF);
    ScalerSetByte(P5_B4_DISP_M1_ONEF_IHF, (BYTE)ulIHF);
    ScalerSetByte(P5_B5_DISP_M1_LINE_MAGN_L, LOBYTE(shMargin));
    ScalerSetByte(P5_B6_DISP_M1_ONEF_MAGN_H, (((HIBYTE(shMargin) << 4) & 0xF0) | (HIBYTE(usPreRead) & 0x0F)));
    ScalerSetByte(P5_B7_DISP_M1_ONEF_MAGN_L, LOBYTE(usPreRead));

    // Write in double buffer
    ScalerSetBit(P5_AD_DISP_M1_STATUS, ~(_BIT4), _BIT4);

    // Disable Osd Overlay In Case of Garbage
    pData[0] = ScalerGetByte(P0_6C_OVERLAY_CTRL);
    ScalerSetBit(P0_6C_OVERLAY_CTRL, ~_BIT0, 0x00);

    // Set Frame sync
    ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    // Set Free Run
    ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));
    ScalerSetBit(P0_6C_OVERLAY_CTRL, ~_BIT0, (pData[0] & _BIT0));

#if(_HW_ONE_FRAME_FRC_MAX_DROP_FRAME_SUPPORT == _ON)
    // Enable if needed, fine tune drop frame number by performance
    ScalerSetBit(P5_4D_CAP_M1_OFRC_MAX_FDROP, ~(_BIT7), 0x00);
    ScalerSetBit(P5_4D_CAP_M1_OFRC_MAX_FDROP, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x02);
#endif
}

//--------------------------------------------------
// Description  : Compare which one of IHF and DHF is bigger, and see if they are too similar
// Input Value  : ulFreq --> DCLK
// Output Value : output is true when they are too similar
//--------------------------------------------------
void ScalerFRCCompareIHFandDHF(WORD usHorSize, WORD usVerSize)
{
    EnumFRCStyle enumFRCStyle = _FRC_INPUT_SLOWER;
    WORD usPreRead = 0;
    WORD usIDenPeriod = 0;
    WORD usDDenPeriod = 0;

    // Set Previous FRC Style
    SET_MDOMAIN_FRC_STYLE((bit)((ScalerGetBit(P5_AC_DISP_M1_DISP_CTRL1, _BIT3) == _BIT3) ? (_FRC_INPUT_FASTER) : (_FRC_INPUT_SLOWER)));

    // Get Pre-read line
    usPreRead = ScalerFRCCalculatePreReadLine();
    usPreRead = (usPreRead == 0) ? (GET_MDOMAIN_OUTPUT_VSTART()) : (GET_MDOMAIN_OUTPUT_VSTART() - usPreRead);

    // IDEN Period = IVH / IHF
    usIDenPeriod = GET_DWORD_MUL_DIV(GET_MDOMAIN_INPUT_VHEIGHT(), 1000, GET_MDOMAIN_INPUT_HFREQ());

    // DDEN Period = (DVH + Pre-read line) / DHF
    usDDenPeriod = GET_DWORD_MUL_DIV((GET_MDOMAIN_OUTPUT_VHEIGHT() + usPreRead), 1000, ((DWORD)GET_D_CLK_FREQ() * 10 / GET_MDOMAIN_OUTPUT_HTOTAL()));

    if(GET_MEMORY_SELECT() == _FRAME_SYNC_MEMORY)
    {
        enumFRCStyle = _FRC_INPUT_SLOWER;
    }
    else
    {
        // Set FRC Style
        if(usDDenPeriod == usIDenPeriod) // If IDEN period = DDEN period, compare IVF/ DVF
        {
            if(GET_MDOMAIN_INPUT_VFREQ() < GET_OUTPUT_VFREQ())
            {
                enumFRCStyle = _FRC_INPUT_SLOWER;
            }
            else
            {
                enumFRCStyle = _FRC_INPUT_FASTER;
            }
        }
        else if(usDDenPeriod < usIDenPeriod)
        {
            enumFRCStyle = _FRC_INPUT_SLOWER;
        }
        else
        {
            enumFRCStyle = _FRC_INPUT_FASTER;
        }
    }

    if(ScalerMemoryCheckScreenCoverStatus() == _FALSE)
    {
        if(enumFRCStyle != GET_MDOMAIN_FRC_STYLE())
        {
            ScalerDDomainBackgroundEnable(_ENABLE);
        }
    }

    if(enumFRCStyle == _FRC_INPUT_SLOWER)
    {
#if(_HW_FRC_CAP_SRC_SEL_SUPPORT == _ON)
        ScalerSetBit(P5_32_CAP_M1_CTRL, ~_BIT3, 0x00);
#endif
        // Set Input slow Than Display
        ScalerSetBit(P5_AC_DISP_M1_DISP_CTRL1, ~_BIT3, 0x00);
    }
    else
    {
#if(_HW_FRC_CAP_SRC_SEL_SUPPORT == _ON)
        ScalerSetBit(P5_32_CAP_M1_CTRL, ~_BIT3, _BIT3);
#endif
        // Set Input Fast Than Display
        ScalerSetBit(P5_AC_DISP_M1_DISP_CTRL1, ~_BIT3, _BIT3);
    }

    // Write in double buffer
    ScalerSetBit(P5_AD_DISP_M1_STATUS, ~_BIT4, _BIT4);

    if((GET_MEMORY_SELECT() == _FRAME_SYNC_MEMORY) || (GET_MEMORY_SELECT() == _MN_FRAME_SYNC_MEMORY))
    {
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

        // Set Frame sync when FRC
        ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));
    }
    else if(GET_MEMORY_SELECT() == _FREE_RUN_MEMORY)
    {
        if(GET_MEMORY_FRAME_BUFFER() == _MEMORY_1_FRAME_BUFFER)
        {
            ScalerFRCOneFrameCtrl(usHorSize, usVerSize);
        }
        else
        {
            // Set Free Run when FRC
            ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));
        }
    }
}

//--------------------------------------------------
// Description  : Wait Capture Write Memory Block Finish
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerFRCWaitWriteFrameBufFinish(void)
{
    if(GET_MEMORY_CONFIG() == _MEMORY_WORK_MODE)
    {
        // Check Double Frame Buffer
        if((bit)(ScalerGetBit(P5_AC_DISP_M1_DISP_CTRL1, _BIT6)) == _TRUE)
        {
            // Get FRC Capture Block Index
            pData[0] = ScalerGetBit(P5_2A_CAP_M1_STATUS, (_BIT7 | _BIT6));

            // Wait Write Data
            ScalerTimerPollingFlagProc(50, P5_2A_CAP_M1_STATUS, _BIT6, ((~pData[0]) & _BIT6));
            ScalerTimerPollingFlagProc(50, P5_2A_CAP_M1_STATUS, _BIT6, ((pData[0]) & _BIT6));

            ScalerTimerWaitForEvent(_EVENT_IEN_STOP);
            ScalerTimerWaitForEvent(_EVENT_IVS);
        }
    }
}

//--------------------------------------------------
// Description  : Check if current FRC data path has image compression HW
// Input Value  : None
// Output Value : _TRUE/_FALSE
//--------------------------------------------------
bit ScalerFRCGetImgCmpHWUsability(void)
{
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _OFF)
    return _FALSE;
#endif

    return _TRUE;
}

//--------------------------------------------------
// Description  : Check if run-time config is supported by image compression
// Input Value  : None
// Output Value : _TRUE/_FALSE
//--------------------------------------------------
bit ScalerFRCGetImgCmpRunTimeUsability(WORD usWidth)
{
    WORD usHPorch = 0x0000;

    usWidth = usWidth;
    usHPorch = usHPorch;
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _OFF)
    return _FALSE;
#else
    usHPorch = (GET_MDOMAIN_INPUT_HTOTAL() - usWidth);

    // Check input timing HPorch does not exceed HW contraint
    if(usHPorch < _HW_M_DOMAIN_IMG_CMP_HPORCH_LIMIT)
    {
        return _FALSE;
    }
    return _TRUE;
#endif
}

//--------------------------------------------------
// Description  : Given granted BW -> get FRC path max line-sum-bit
// Input Value  : Granted BW (unit: 100K)
// Output Value : Max line-sum-bit (unit: bit)
//--------------------------------------------------
DWORD ScalerFRCGetPathMaxLineSumBitByBW(DWORD ulGrantBW, StructMemoryBWUsageParam *pstMemBWParam)
{
    // Max path line_sum_bit (unit: bit)
    PDATA_DWORD(0) = (ulGrantBW * 100000) /
                     ((((DWORD)pstMemBWParam->usIVTotal * pstMemBWParam->usIVFreq) +
                       ((DWORD)pstMemBWParam->usDVTotal * pstMemBWParam->usDVFreq) +
                       ((DWORD)pstMemBWParam->usDVTotal * pstMemBWParam->usDVFreq *
                        ((_DCLK_SPREAD_RANGE / _DPLL_SSCG_DIV_MODE) + _DCLK_SPREAD_RANGE_MARGIN) / 4 / 100)) / 10 + 1) *
                     _MEMORY_BUS_WIDTH;

    return PDATA_DWORD(0);
}

//--------------------------------------------------
// Description  : Decide PQC/OD/HSD Parameters
// Input Value  : pstRateCtrlInfo
// Output Value : Index of applicable FRC rate ctrl param
//--------------------------------------------------
BYTE ScalerFRCGetMemRateCtrlParamIndex(StructFRCRateCtrlInfo *pstRateCtrlInfo)
{
    BYTE ucIndex = 0;
    BYTE ucCnt = ScalerFRCGettFRCRateCtrlParamCnt();
    BYTE ucBasicMDomainExt = 0;
    DWORD pulMaxPathLineSumBit[_OD_PARAM_LENGTH] = {0};
    WORD usPathInputHWidth = pstRateCtrlInfo->usInputHWidth;
    WORD usPathFifoHWidth = pstRateCtrlInfo->usFifoHWidth;

    DebugMessageFRC("==FRC RC START==", 0xFF);

    //-------------------------------------------------
    // Get max path line sum bit in each case
    //-------------------------------------------------
    for(ucIndex = 0; ucIndex < _OD_PARAM_LENGTH; ucIndex++)
    {
        BYTE ucODBit10x = GET_OD_BIT_RATE(tODParam[ucIndex]);
        DWORD ulSpareBwForOD = ScalerMDomainGetCurODReservedBW(ucODBit10x, &(pstRateCtrlInfo->stMemBWParam));

        PDATA_DWORD(0) = (pstRateCtrlInfo->ulGrantBW > ulSpareBwForOD) ? (pstRateCtrlInfo->ulGrantBW - ulSpareBwForOD) : 0;
        DebugMessageFRC("@ OD Bit", ucODBit10x);
        DebugMessageFRC("FRC Granted BW", PDATA_DWORD(0));

        pulMaxPathLineSumBit[ucIndex] = ScalerFRCGetPathMaxLineSumBitByBW(PDATA_DWORD(0), &(pstRateCtrlInfo->stMemBWParam));
        DebugMessageFRC("Path MAX LSB", pulMaxPathLineSumBit[ucIndex]);
    }

    //-------------------------------------------------
    // Check which FRC rate ctrl param is applicable
    //-------------------------------------------------
    for(ucIndex = 0; ucIndex < ucCnt; ucIndex++)
    {
        DWORD ulMaxLineSumBit = pulMaxPathLineSumBit[GET_FRC_RCP_OD_PARAM(ucIndex)];
        WORD usFifoHWidth = usPathFifoHWidth;

        // Skip the rate ctrl param in following conditions:
        // 1. Insufficient line-sum-bit.
        if(ulMaxLineSumBit < _FRC_MIN_LINE_SUM_BIT)
        {
            continue;
        }
        // 2. Adopt ImgCmp, but it is not usable in such path
        if((GET_FRC_RCP_IMG_CMP_EN(ucIndex) == _TRUE) && (pstRateCtrlInfo->ucImgCmpUsable == _FALSE))
        {
            continue;
        }

#if(_HW_FRC_FRAME_TEAR_PREVENTION_SUPPORT == _ON)
        if(((GET_MEMORY_FRAME_BUFFER() == _MEMORY_1_FRAME_BUFFER) && (GET_MEMORY_SELECT() == _FREE_RUN_MEMORY)) || (GET_MEMORY_FRAME_BUFFER() == _MEMORY_1_5_FRAME_BUFFER))
#endif
        {
            // 3. Adopt ImgCmp, but path input width less than minimum requirement
            if((GET_FRC_RCP_IMG_CMP_EN(ucIndex) == _TRUE) && (pstRateCtrlInfo->usInputHWidth <= _IMG_CMP_MIN_INPUT_WIDTH))
            {
                continue;
            }
        }

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
        if(GET_FRC_RCP_IMG_CMP_EN(ucIndex) == _TRUE)
        {
            // Max line sum bit is trimmed to multiple of 128
            // Steam end dummy(256bit) is also deducted if necessary
            ulMaxLineSumBit = ulMaxLineSumBit - (ulMaxLineSumBit % _IMG_CMP_MEM_RW_UNIT) - _IMG_CMP_STREAM_END_DUMMY_LEN;
        }
#endif

        // HSD disabled cases
        if(GET_FRC_RCP_HSD_EN(ucIndex) == _FALSE)
        {
            DWORD ulFrameSize = 0;
            DWORD ulCompareBlock = GET_ROW_PER_PATH();
            BYTE ucFrameNum = (GET_MEMORY_FRAME_BUFFER() == _MEMORY_1_5_FRAME_BUFFER) ? 1 : GET_MEMORY_FRAME_BUFFER() + 1;

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
            if(GET_FRC_RCP_IMG_CMP_EN(ucIndex) == _TRUE)
            {
                // Path width is multiple of _IMG_CMP_BLK_WIDTH
                usFifoHWidth = CEILING((usFifoHWidth + ucBasicMDomainExt), _IMG_CMP_BLK_WIDTH);
            }
            else
#endif
            {
                // Take extension into BW calculation
                usFifoHWidth += ucBasicMDomainExt;
            }

#if(_FW_FRC_DYNAMIC_SPACE_ALLOCATION == _ON)
            ulFrameSize = ScalerFRCGetLineSumBit(usFifoHWidth, GET_FRC_RCP_BPP(ucIndex), GET_FRC_RCP_IMG_CMP_PARAM(ucIndex)) * pstRateCtrlInfo->usFifoVHeight;
            ulFrameSize = GET_DEFAULT_FRAME_USE_MEMORY_ROW(ulFrameSize);

#if(_HW_ONE_FRAME_FRC_MAX_DROP_FRAME_SUPPORT == _ON)
            if(GET_MEMORY_FRAME_BUFFER() == _MEMORY_1_FRAME_BUFFER)
            {
                if((ulFrameSize * ucFrameNum) > _MEMORY_ROW)
                {
                    continue;
                }
            }
            else
#endif
            {
                if(((ulCompareBlock >> _FW_MEM_ROW_ADDR_SHIFT_BIT_NUM) < ulFrameSize) || ((ulFrameSize * ucFrameNum) > _MEMORY_ROW))
                {
                    continue;
                }
            }
#endif

            if(((DWORD)usFifoHWidth * GET_FRC_RCP_BPP(ucIndex)) <= ulMaxLineSumBit)
            {
                pstRateCtrlInfo->ucMDomainExt = ucBasicMDomainExt;
                break;
            }
        }
        // HSD enabled cases
        else
        {
            BYTE ucMDomainExt = 0;

            // HSD considering to size
            PDATA_DWORD(0) = (DWORD)(GET_ROW_PER_PATH() >> _FW_MEM_ROW_ADDR_SHIFT_BIT_NUM) *
                             (DWORD)_FW_MEM_CLIENT_MEMORY_BIT_NUM * _MEMORY_COL_PER_BANK * _MEMORY_BANK / pstRateCtrlInfo->usFifoVHeight;

            DebugMessageFRC("Space MaxLineSumBit", PDATA_DWORD(0));
            DebugMessageFRC("BW MaxLineSumBit", ulMaxLineSumBit);
            ulMaxLineSumBit = MINOF(ulMaxLineSumBit, PDATA_DWORD(0));

            PDATA_DWORD(0) = ulMaxLineSumBit / GET_FRC_RCP_BPP(ucIndex);
            PDATA_DWORD(0) = PDATA_DWORD(0) * usPathInputHWidth / usPathInputHWidth;

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
            // Path HWidth is scale down to multiple of _IMG_CMP_BLK_WIDTH
            if(GET_FRC_RCP_IMG_CMP_EN(ucIndex) == _TRUE)
            {
                PDATA_DWORD(0) -= (PDATA_DWORD(0) % _IMG_CMP_BLK_WIDTH);
            }
#endif
            // HWidth need to be multiple of _FRC_UNIT * 4 (complement of linestep)
            PDATA_DWORD(0) *= GET_FRC_RCP_BPP(ucIndex);
            PDATA_DWORD(0) -= (PDATA_DWORD(0) % (_FRC_UNIT * 4));
            PDATA_DWORD(0) /= GET_FRC_RCP_BPP(ucIndex);

            // Let path HWidth be an even number
            PDATA_DWORD(0) -= (PDATA_DWORD(0) % 0x02);

            // Given granted memory usage & BPP, the max (full frame)HWidth available:
            DebugMessageFRC("4. FRC max SD width", PDATA_DWORD(0));

            DebugMessageFRC("4. FRC current SD width", pstRateCtrlInfo->usFifoHWidth);

            // Update (full frame)HWidth if scaling is necessary
            if(usFifoHWidth > PDATA_DWORD(0))
            {
                pstRateCtrlInfo->usFifoHWidth = PDATA_DWORD(0);
                pstRateCtrlInfo->ucMDomainExt = ucMDomainExt;
            }
            else
            {
                // pstRateCtrlInfo->usFifoHWidth left unchanged
                pstRateCtrlInfo->ucMDomainExt = ucBasicMDomainExt;
            }

            // Result of HSD assessment
            DebugMessageFRC("4.usHSDBW", pstRateCtrlInfo->usFifoHWidth);
            break;
        }
    }

    DebugMessageFRC("==FRC RC END==", ucIndex);

    if(ucIndex >= ucCnt)
    {
        return 0;
    }

    return ucIndex;
}

//--------------------------------------------------
// Description  : Apply FRC Rate Ctrl Parameter
// Input Value  : Parameter Index
// Output Value : None
//--------------------------------------------------
void ScalerFRCApplyMemRateCtrlParam(BYTE ucRateCtrlParamIndex)
{
    if(ScalerMemoryCheckScreenCoverStatus() == _FALSE)
    {
        if(GET_FRC_RCP_FIFO_COLOR_DEPTH(ucRateCtrlParamIndex) != GET_FRC_RCP_FIFO_COLOR_DEPTH(GET_MDOMAIN_FRC_CTRL_PARAM_INDEX()))
        {
            ScalerDDomainBackgroundEnable(_ENABLE);
        }
    }

    SET_MDOMAIN_FRC_CTRL_PARAM_INDEX(ucRateCtrlParamIndex);

    // Set FIFO bit num
    ScalerMDomainSetMemoryDataBit(GET_FRC_RCP_FIFO_COLOR_DEPTH(ucRateCtrlParamIndex));
    DebugMessageFRC("4. FIFO Color Depth", GET_FRC_RCP_FIFO_COLOR_DEPTH(ucRateCtrlParamIndex));
}

//--------------------------------------------------
// Description  : Calculate path line sum bit
// Input Value  : Path H width, FIFO color depth, ImgCmp index
// Output Value : Path line-sum-bit
//--------------------------------------------------
DWORD ScalerFRCGetLineSumBit(WORD usHorSize, BYTE ucFIFOMemBits, EnumImgCmpParamIndex enumImgCmpIndex)
{
    DWORD ulLineSumBit = 0;

    enumImgCmpIndex = enumImgCmpIndex;

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
    if(GET_IMG_CMP_ENABLE(enumImgCmpIndex) == _TRUE)
    {
        ulLineSumBit = (DWORD)CEILING(usHorSize, _IMG_CMP_BLK_WIDTH) * GET_IMG_CMP_PARAM_LLB(enumImgCmpIndex) + _IMG_CMP_STREAM_END_DUMMY_LEN;
        ulLineSumBit = CEILING(ulLineSumBit, _IMG_CMP_MEM_RW_UNIT);
    }
    else
#endif
    {
        ulLineSumBit = ((DWORD)usHorSize) * ucFIFOMemBits;
    }

    return ulLineSumBit;
}

//--------------------------------------------------
// Description  : Set Capture And Display Memory Boundary
// Input Value  : enumFRCBoundary
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetMemoryBoundary(EnumFRCBoundary enumFRCBoundary)
{
    DWORD ulUpLimit = 0;

    if(enumFRCBoundary == _FRC_BOUNDARY_DEFAULT)
    {
        // Set Memory Boundary initial value
        ulUpLimit = 0x0FFFFFFF;
    }
    else
    {
#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
        // Set M:N auto block toggle
        if(GET_FRC_3BLOCK_TOGGLE_STATUS() == _ENABLE)
        {
            ulUpLimit = 0x0FFFFFFF;
        }
        else
#endif
        {
            // Set Up limit , Rotation start from _MEMORY_BOTTOM_ADDRESS, so up limit = _MEMORY_BOTTOM_ADDRESS + 1
            ulUpLimit = _MEMORY_BOTTOM_ADDRESS + 1;
        }
    }

    ScalerSetBit(P5_10_CAP_M1_BOUNDARY_ADDR2_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ulUpLimit >> 24) & 0x0F));
    ScalerSetByte(P5_11_CAP_M1_BOUNDARY_ADDR2_H, ((ulUpLimit >> 16) & 0xFF));
    ScalerSetByte(P5_12_CAP_M1_BOUNDARY_ADDR2_M, ((ulUpLimit >> 8) & 0xFF));
    ScalerSetByte(P5_13_CAP_M1_BOUNDARY_ADDR2_L, (ulUpLimit & 0xFF));

    ScalerSetBit(P5_90_DISP_M1_BOUNDARY_ADDR2_MSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ulUpLimit >> 24) & 0x0F));
    ScalerSetByte(P5_91_DISP_M1_BOUNDARY_ADDR2_H, ((ulUpLimit >> 16) & 0xFF));
    ScalerSetByte(P5_92_DISP_M1_BOUNDARY_ADDR2_M, ((ulUpLimit >> 8) & 0xFF));
    ScalerSetByte(P5_93_DISP_M1_BOUNDARY_ADDR2_L, (ulUpLimit & 0xFF));

    // Enable FRC Display double buffer
    ScalerSetBit(P5_AD_DISP_M1_STATUS, ~_BIT4, _BIT4);

    ScalerTimerWaitForEvent(_EVENT_DVS);
}

//--------------------------------------------------
// Description  : Get tFRCRateCtrlParam Table Count
// Input Value  : None
// Output Value : BYTE
//--------------------------------------------------
BYTE ScalerFRCGettFRCRateCtrlParamCnt(void)
{
    return (sizeof(tFRCRateCtrlParam) / sizeof(tFRCRateCtrlParam[0]));
}

//--------------------------------------------------
// Description  : Get BW decide Parameter From Index
// Input Value  : Index
// Output Value : EnumImgCmpParamIndex
//--------------------------------------------------
EnumImgCmpParamIndex ScalerFRCGetRcpImcCmpParamFromIndex(BYTE ucIndex)
{
    return tFRCRateCtrlParam[ucIndex].enumImgCmpParamIndex;
}

//--------------------------------------------------
// Description  : Get Fifo Color Depth From Index
// Input Value  : Index
// Output Value : Color Depth
//--------------------------------------------------
BYTE ScalerFRCGetRcpFifoColorDepthFromIndex(BYTE ucIndex)
{
    return tFRCRateCtrlParam[ucIndex].b5FifoColorDepth;
}

//--------------------------------------------------
// Description  : Get H Scaling Down Enable From Index
// Input Value  : Index
// Output Value : HSD en
//--------------------------------------------------
BYTE ScalerFRCGetRcpHsdEnFromIndex(BYTE ucIndex)
{
    return (tFRCRateCtrlParam[ucIndex].b1AllowHSD == _ON);
}

#if(_OD_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get OD Parameter From Index
// Input Value  : Index
// Output Value : EnumODParamIndex
//--------------------------------------------------
EnumODParamIndex ScalerFRCGetRcpODParamFromIndex(BYTE ucIndex)
{
    return tFRCRateCtrlParam[ucIndex].enumExpectODParamIndex;
}
#endif

#if(_FREEZE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : FRC freeze mode
// Input Value  : ON --> Freeze
// Output Value : None
//--------------------------------------------------
void ScalerFRCDisplayFreeze(bit bEn)
{
    ScalerTimerWaitForEvent(_EVENT_IEN_STOP);

    if(bEn == _ON)
    {
        ScalerSetBit(P5_27_CAP_M1_DDR_CTRL1, ~_BIT2, _BIT2);
    }
    else
    {
        ScalerSetBit(P5_27_CAP_M1_DDR_CTRL1, ~_BIT2, 0x00);
    }
}
#endif // End of #if(_FREEZE_SUPPORT == _ON)

#if(_HW_ONE_FRAME_FRC_MAX_DROP_FRAME_SUPPORT == _ON)
//--------------------------------------------------
// Description  : FRC 2 Frame Buffer Case
// Input Value  : N.A.
// Output Value : _TRUE: 2 Frame Buffer
//--------------------------------------------------
bit ScalerFRCCheckDoubleFrameBuffer(void)
{
    BYTE ucIndex = 0;
    WORD usHwidth = MINOF(GET_MDOMAIN_INPUT_HWIDTH(), GET_MDOMAIN_OUTPUT_HWIDTH());
    WORD usVHeight = MINOF(GET_MDOMAIN_INPUT_VHEIGHT(), GET_MDOMAIN_OUTPUT_VHEIGHT());
    WORD usPreRead = 0;
    WORD usIDenPeriod = 0;
    WORD usDDenPeriod = 0;
    DWORD ulFrameSize = 0;
    DWORD ulODSize = 0x00;

    for(ucIndex = 0; ucIndex < (sizeof(tFRCRateCtrlParam) / sizeof(tFRCRateCtrlParam[0])); ucIndex++)
    {
#if(_OD_SUPPORT == _ON)
        ulODSize = CEILING_OF_INT_DIVISION(GET_DEFAULT_FRAME_USE_MEMORY_ROW(ulODSize), 10) + _FRAME_SIZE_MARGIN; // od bit unit was 0.1bit
#endif
        ulFrameSize = GET_DEFAULT_FRAME_USE_MEMORY_ROW(ScalerFRCGetLineSumBit(usHwidth, GET_FRC_RCP_BPP(ucIndex), GET_FRC_RCP_IMG_CMP_PARAM(ucIndex)) * usVHeight);

        if(((ulFrameSize * 2) + ulODSize) < _MEMORY_ROW)
        {
            return _TRUE;
        }
    }

    // Get Pre-read line
    usPreRead = ScalerFRCCalculatePreReadLine();
    usPreRead = (usPreRead == 0) ? (GET_MDOMAIN_OUTPUT_VSTART()) : (GET_MDOMAIN_OUTPUT_VSTART() - usPreRead);

    // IDEN Period = IVH / IHF
    usIDenPeriod = GET_DWORD_MUL_DIV(GET_MDOMAIN_INPUT_VHEIGHT(), 1000, GET_MDOMAIN_INPUT_HFREQ());

    // DDEN Period = (DVH + Pre-read line) / DHF
    usDDenPeriod = GET_DWORD_MUL_DIV((GET_MDOMAIN_OUTPUT_VHEIGHT() + usPreRead), 1000, ((DWORD)GET_D_CLK_FREQ() * 10 / GET_MDOMAIN_OUTPUT_HTOTAL()));

    if(usDDenPeriod > usIDenPeriod)
    {
        usDDenPeriod = usDDenPeriod * 10 / usIDenPeriod;
    }
    else
    {
        usDDenPeriod = usIDenPeriod * 10 / usDDenPeriod;
    }

    // 11 & 18 are from experiment
    // input slow, 1.1 < iden/dden < 1.8 is suitable for one frame frc
    // input fast, 0.5 < iden/dden < 9 is suitable for one frame frc
    if((usDDenPeriod > 11) && (usDDenPeriod < 18))
    {
        return _FALSE;
    }

    return _TRUE; // force 2 frame frc for performance
}
#endif

//--------------------------------------------------
// Description  : Calculate FRC Address
// Input Value  : FRC Page
// Output Value : None
//--------------------------------------------------
void ScalerFRCCalculateAddress(void)
{
    DWORD ulAddress1 = GET_ROW_PER_PATH();
    DWORD ulAddress2 = 0;

    ScalerFRCSetCapAddress(_FRC_1ST_BLOCK, ulAddress1);
    ScalerFRCSetDispAddress(_FRC_1ST_BLOCK, ulAddress1);
    ScalerFRCSetCapAddress(_FRC_2ND_BLOCK, ulAddress2);
    ScalerFRCSetDispAddress(_FRC_2ND_BLOCK, ulAddress2);

    DebugMessageFRC("ulBlkSpace", GET_ROW_PER_PATH());
    DebugMessageFRC("FRC_1ST_BLOCK", ScalerFRCGetCapAddress(_FRC_1ST_BLOCK));
    DebugMessageFRC("FRC_2ND_BLOCK", ScalerFRCGetCapAddress(_FRC_2ND_BLOCK));
}

//--------------------------------------------------
// Description  : Allocate FRC Space For Path
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerFRCSpaceInitialAllocation(void)
{
    SET_FRC_BOTTOM_ADDR(_MEMORY_BOTTOM_ADDRESS);
    SET_FRC_TOTAL_USE_ROW(_MEMORY_ROW);
    SET_ROW_PER_PATH(_MEMORY_BOTTOM_ADDRESS);
}

//--------------------------------------------------
// Description  : Get FRC BW Usage from parameter
// Input Value  : WORD ushwidth, WORD usColorDepth, WORD usLLB, DWORD ulPixelclk(unit: kHz), EnumInputDataPath enumInputPath, bit bDefaultMode
// Output Value : BW
//--------------------------------------------------
DWORD ScalerFRCBWCalUsage(WORD usCaphwidth, WORD usDisphwidth, WORD usColorDepth, EnumImgCmpParamIndex enumLLB, DWORD ulPixelclk, bit bDefaultMode)
{
    DWORD ulLineSumBit = 0;
    DWORD ulFRCWriteBw = 0;
    DWORD ulFRCReadBw = 0;
    // panel typ frame rate = ((GET_FORCE_DISPLAY_1P_MODE() == _TRUE) ? _PANEL_TYP_FRAME_RATE : _MTP_MAIN_PREFER_TIMING_FRAME_RATE)
    // only mtp allocation need to calculate bw usage
    DWORD ulDclk = (bDefaultMode == _TRUE) ? GET_D_CLK_FROM_VFREQ((DWORD)_PANEL_DH_TOTAL * _PANEL_DV_TOTAL, _PANEL_TYP_FRAME_RATE) : GET_D_CLK_FREQ();

    // Capture LLB
    ulLineSumBit = ScalerFRCGetLineSumBit(usCaphwidth, usColorDepth, enumLLB);

    // FRC write BW
    ulFRCWriteBw = GET_DWORD_MUL_DIV(ulPixelclk, ulLineSumBit, ((bDefaultMode == _TRUE) ? _PANEL_DH_TOTAL : GET_MDOMAIN_INPUT_HTOTAL())) / _MEMORY_BUS_WIDTH / 100;

    // Display LLB
    ulLineSumBit = ScalerFRCGetLineSumBit(usDisphwidth, usColorDepth, enumLLB);

    // FRC read BW
    ulFRCReadBw = GET_DWORD_MUL_DIV((DWORD)ulDclk, ulLineSumBit, GET_MDOMAIN_OUTPUT_HTOTAL()) / _MEMORY_BUS_WIDTH / 100;
    ulFRCReadBw += ulFRCReadBw * ((_DCLK_SPREAD_RANGE / _DPLL_SSCG_DIV_MODE) + _DCLK_SPREAD_RANGE_MARGIN) / 4 / 100;

    // FRC total BW
    PDATA_DWORD(0) = ulFRCWriteBw + ulFRCReadBw;

    DebugMessageFRC("FRC ALLOCATE BW", (PDATA_DWORD(0)));

    return PDATA_DWORD(0);
}

//--------------------------------------------------
// Description  : D Domain Source Select
// Input Value  :
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetDDomainSourceSelect(EnumDDomainSourceSelect enumSourceSelect)
{
    BYTE ucDisplaySource = 0x00;

    if(enumSourceSelect == _DDOMAIN_SRC_FRAM_FRAME_SYNC_MODE)
    {
        ucDisplaySource = _BIT2;
    }

#if(_HW_FRC_CAP_SRC_SEL_SUPPORT == _ON)
    // Set Frame sync with line buffer mode
    ScalerSetBit(P5_32_CAP_M1_CTRL, ~(_BIT2 | _BIT1), ucDisplaySource);
#endif

    // Set Frame sync with line buffer mode
    ScalerSetBit(P5_AC_DISP_M1_DISP_CTRL1, ~(_BIT2 | _BIT1), ucDisplaySource);

    // Enable Double buffer
    ScalerSetBit(P5_AD_DISP_M1_STATUS, ~(_BIT4), _BIT4);
}

//--------------------------------------------------
// Description  : Get Image Compression parameter
// Input Value  : void
// Output Value : Img cmp parameter
//--------------------------------------------------
EnumImgCmpParamIndex ScalerFRCImgCmpGetPara(void)
{
    return GET_FRC_RCP_IMG_CMP_PARAM(GET_MDOMAIN_FRC_CTRL_PARAM_INDEX());
}

#if((_M_DOMAIN_IMG_CMP_SUPPORT == _ON) && (_HW_M_DOMAIN_IMG_CMP_TYPE == _M_DOMAIN_IMG_CMP_GEN_1))
//--------------------------------------------------
// Description  : Modify frc cap/disp len, disp wtlvl under certain condition
// Input Value  : none
// Output Value : _TRUE, _FALSE
//--------------------------------------------------
bit ScalerFRCModLenWtlvl(void)
{
#if(_OD_SUPPORT == _ON)
    StructMemoryBWUsageParam stMemBWParam;
    DWORD ulODUseBW = 0;
    BYTE ucODBit10x = GET_OD_BIT_RATE(ScalerODGetParamSet(_MEMORY_ROW - GET_FRC_TOTAL_USE_ROW(), GET_MEMORY_REMAIN_BW()));

    ScalerMDomainGetMemBWParam(&stMemBWParam);
    ulODUseBW = ScalerMDomainODCalculateMemoryUseBW(ucODBit10x, &stMemBWParam);

    // when imc, 1:1/enlarge/reduce, od bw usage > frc bw usage, need to modify frc cap/disp len, disp wtlvl
    return ((GET_MDOMAIN_OUTPUT_VBHEIGHT() > GET_MDOMAIN_OUTPUT_VHEIGHT()) &&
            (GET_IMG_CMP_ENABLE(GET_IMG_CMP_PARAM()) == _TRUE) &&
            (ulODUseBW > GET_MEMORY_BW()));
#else
    return _FALSE;
#endif
}
#endif
#endif // End of #if(_FRC_SUPPORT == _ON)

