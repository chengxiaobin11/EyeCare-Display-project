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
// ID Code      : ScalerOD.c No.0000
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
#if(_OD_SUPPORT == _ON)
#if(_FRC_SUPPORT == _ON)
BYTE g_ucODCurrDynamicStatus;
#endif
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_OD_SUPPORT == _ON)
BYTE ScalerODGetCompressionBitNum(DWORD ulMemoryRemainSpace, WORD usMemoryRemainBW);
bit ScalerODGetSupportStatus(void);
EnumFunctionOnOFF ScalerODGetStatus(void);
EnumOdCmpParamMode ScalerODGetCmpParamMode(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_OD_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get OD compression bit number
//                according to available memory space & BW.
// Input Value  : Remaining space & BW
// Output Value : OD compression bit number(10x)
//--------------------------------------------------
BYTE ScalerODGetCompressionBitNum(DWORD ulMemoryRemainSpace, WORD usMemoryRemainBW)
{
    WORD usODUseSpace = 0;
    WORD usODUseBW = 0;

    DebugMessageMemory("4. Remaining BW for OD", usMemoryRemainBW);
    DebugMessageMemory("4. Remaining Space for OD", ulMemoryRemainSpace);

    // Disable OD for emissive panel
    if((_PANEL_PIXEL_TYPE == _PANEL_PIXEL_OLED) || (_PANEL_PIXEL_TYPE == _PANEL_PIXEL_MICRO_LED))
    {
        return _OFF;
    }

    //=============================================
    // OD compression bit num: 7.5bits / pixel
    //=============================================
    if(CHECK_OD_MODE_AVAILABLE(_OD_SUPERPIXEL1X2_75BIT_BIT_NUM) == _TRUE)
    {
        usODUseSpace = ScalerMDomainODCalculateMemoryUseSpace(_OD_SUPERPIXEL1X2_75BIT_BIT_NUM);
        usODUseBW = ScalerMDomainODCalculateMemoryUseBW(_OD_SUPERPIXEL1X2_75BIT_BIT_NUM);

        DebugMessageMemory("4. 7_5_bit OD BW", usODUseBW);
        DebugMessageMemory("4. 7_5_bit OD Size", usODUseSpace);
        if((usODUseSpace < ulMemoryRemainSpace) && (usODUseBW < usMemoryRemainBW))
        {
            return _OD_SUPERPIXEL1X2_75BIT_BIT_NUM;
        }
    }
    //=============================================
    // OD compression bit num: 6 bits / pixel
    //=============================================
    if(CHECK_OD_MODE_AVAILABLE(_OD_SUPERPIXEL1X4_60BIT_BIT_NUM) == _TRUE)
    {
        usODUseSpace = ScalerMDomainODCalculateMemoryUseSpace(_OD_SUPERPIXEL1X4_60BIT_BIT_NUM);
        usODUseBW = ScalerMDomainODCalculateMemoryUseBW(_OD_SUPERPIXEL1X4_60BIT_BIT_NUM);

        DebugMessageMemory("4. 6_0_bit OD BW", usODUseBW);
        DebugMessageMemory("4. 6_0_bit OD Size", usODUseSpace);
        if((usODUseSpace < ulMemoryRemainSpace) && (usODUseBW < usMemoryRemainBW))
        {
            return _OD_SUPERPIXEL1X4_60BIT_BIT_NUM;
        }
    }
    //=============================================
    // Otherwise, OD off
    //=============================================
    return _OFF;
}

//--------------------------------------------------
// Description  : Get OD kernel Useability
// Input Value  : None
// Output Value : _OFF/_ON
//--------------------------------------------------
bit ScalerODGetSupportStatus(void)
{
    return ((GET_OD_USE_BIT() == _OFF) ? (_OFF) : (_ON));
}

//--------------------------------------------------
// Description  : Get OD real-time enable status
// Input Value  : None
// Output Value : _FUNCTION_OFF/_FUNCTION_ON
//--------------------------------------------------
EnumFunctionOnOFF ScalerODGetStatus(void)
{
#if(_FRC_SUPPORT == _ON)
    if(GET_OD_CURR_DYNAMIC_STATUS() == _ENABLE)
    {
        return _FUNCTION_ON;
    }

#endif
    return (ScalerGetBit(P3_A1_LS_CTRL0, (_BIT7 | _BIT6)) == (_BIT7 | _BIT6)) ? _FUNCTION_ON : _FUNCTION_OFF;
}

//--------------------------------------------------
// Description  : Get OD compression parameter mode
// Input Value  : None
// Output Value : OD compression parameter mode
//--------------------------------------------------
EnumOdCmpParamMode ScalerODGetCmpParamMode(void)
{
#if(_OD_6_0_BIT_MODE_IMPROVE_OPTION == _ON)
    return _OD_CMP_PARAM_MODE_6_0_BIT_IMPROVE;
#else
    return _OD_CMP_PARAM_MODE_DEFAULT;
#endif
}
#endif
