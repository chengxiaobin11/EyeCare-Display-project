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
// ID Code      : RL6851_Series_ScalerImgCmp.c No.0000
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
StructImgCmpParam g_pstImgCmpParam[] =
{
    // ENABLE
    // |   DATA_BIT_DEPTH       LLB
    // |   |                     |
    {_OFF, _OFF,                 _OFF},   // _IMG_CMP_PARAM_OFF
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
    {_ON,  _COLOR_DEPTH_8_BITS,  12  },   // _IMG_CMP_PARAM_LLB_12
    {_ON,  _COLOR_DEPTH_8_BITS,  11  },   // _IMG_CMP_PARAM_LLB_11
    {_ON,  _COLOR_DEPTH_8_BITS,  10  },   // _IMG_CMP_PARAM_LLB_10
    {_ON,  _COLOR_DEPTH_8_BITS,   9  },   // _IMG_CMP_PARAM_LLB_9
    {_ON,  _COLOR_DEPTH_8_BITS,   8  },   // _IMG_CMP_PARAM_LLB_8
    {_ON,  _COLOR_DEPTH_8_BITS,   7  },   // _IMG_CMP_PARAM_LLB_7
    {_ON,  _COLOR_DEPTH_8_BITS,   6  },   // _IMG_CMP_PARAM_LLB_6
#endif
};

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
void ScalerImgCmpCtrl(WORD usHWidth, WORD usVHeight, EnumImgCmpParamIndex enumCmpParamIndex);
void ScalerImgCmpEn(EnumFRCOnOff enumCapDispOnOff, bit bEn);
void ScalerImgCmpDecmpPowerControl(bit bPowerOn);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value :
//--------------------------------------------------
void ScalerImgCmpCtrl(WORD usHWidth, WORD usVHeight, EnumImgCmpParamIndex enumCmpParamIndex)
{
    StructImgCmpGen1Param stImgCmpGen1Param;

    // Check if IMC function is not even enable
    if(GET_IMG_CMP_ENABLE(enumCmpParamIndex) != _TRUE)
    {
        return;
    }

    ScalerGlobalEnableUnderflowMonitor(_ENABLE);

    //=========================
    // IMC / Encoder + Decoder
    //=========================
    stImgCmpGen1Param.usWidth = usHWidth;
    stImgCmpGen1Param.usHeight = usVHeight;
    stImgCmpGen1Param.b4BitPerComponent = GET_IMG_CMP_PARAM_DATA_DEPTH(enumCmpParamIndex);
    stImgCmpGen1Param.b10BitPerPixel = ((WORD)(GET_IMG_CMP_PARAM_LLB(enumCmpParamIndex)) << _IMG_CMP_GEN1_BPP_SHIFT) & 0x03FF;
    stImgCmpGen1Param.b4LineBufDepth = 9;
    stImgCmpGen1Param.b1YCCModeEn = _ENABLE; // always input YCC

    // Stream period
    stImgCmpGen1Param.ucSteamPeriodEnc = (BYTE)CEILING_OF_INT_DIVISION(stImgCmpGen1Param.b10BitPerPixel * 2, (1 << _IMG_CMP_GEN1_BPP_SHIFT)) - 1;
    stImgCmpGen1Param.ucSteamPeriodDec = (BYTE)CEILING_OF_INT_DIVISION((ScalerFRCGetLineSumBit(stImgCmpGen1Param.usWidth, GET_MEMORY_DATA_BIT(), enumCmpParamIndex)) * 2, GET_MDOMAIN_OUTPUT_HTOTAL()) - 1;

    ScalerImgCmpGen1CommonCtrl(_REG_PAGE_M1_M_DOMAIN_IMG_CMP, _REG_PAGE_M1_M_DOMAIN_IMG_DECMP, &stImgCmpGen1Param);
}

//--------------------------------------------------
// Description  : Image Compression on/off
// Input Value  : enumOn --> _FUNCTION_ON/_FUNCTION_OFF
// Output Value : None
//--------------------------------------------------
void ScalerImgCmpEn(EnumFRCOnOff enumCapDispOnOff, bit bEn)
{
    //===================================
    // FRC Capture - Image Compression
    //===================================
    if(((enumCapDispOnOff & _FRC_CAPTURE_ONOFF) == _FRC_CAPTURE_ONOFF))
    {
        if((bEn == _ON) && (GET_IMG_CMP_ENABLE(GET_IMG_CMP_PARAM()) == _TRUE))
        {
            ScalerImgCmpEncEn(_REG_PAGE_M1_M_DOMAIN_IMG_CMP, _ENABLE);
        }
        else
        {
            ScalerImgCmpEncEn(_REG_PAGE_M1_M_DOMAIN_IMG_CMP, _DISABLE);
        }
    }

    // ===================================
    // FRC Display - Image Decompression
    // ===================================
    if(((enumCapDispOnOff & _FRC_DISPLAY_ONOFF) == _FRC_DISPLAY_ONOFF))
    {
        if((bEn == _ON) && (GET_IMG_CMP_ENABLE(GET_IMG_CMP_PARAM()) == _TRUE))
        {
            ScalerImgCmpDecEn(_REG_PAGE_M1_M_DOMAIN_IMG_DECMP, _ENABLE);
        }
        else
        {
            ScalerImgCmpDecEn(_REG_PAGE_M1_M_DOMAIN_IMG_DECMP, _DISABLE);
        }
    }
}

//--------------------------------------------------
// Description  : Image Compression Power Cut Control
// Input Value  : Input data path/ _ON or _OFF
// Output Value : None
//--------------------------------------------------
void ScalerImgCmpDecmpPowerControl(bit bPowerOn)
{
    if(bPowerOn == _ON)
    {
        ScalerPowerDomainEnableControl(_POWER_CUT_GROUP_005_IMC_ENC_M1, _POWER_CUT_OFF);
        ScalerPowerDomainEnableControl(_POWER_CUT_GROUP_006_IMC_DEC_M1, _POWER_CUT_OFF);
    }
    else
    {
        ScalerPowerDomainEnableControl(_POWER_CUT_GROUP_005_IMC_ENC_M1, _POWER_CUT_ON);
        ScalerPowerDomainEnableControl(_POWER_CUT_GROUP_006_IMC_DEC_M1, _POWER_CUT_ON);
    }
}
#endif

