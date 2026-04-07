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
// ID Code      : RL6851_Series_ScalerOD.c No.0000
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
#if(_OD_SUPPORT == _ON)
EnumODParamIndex code tODParamChkList[] =
{
    _OD_PARAM_7_5_BPP,
    _OD_PARAM_6_0_BPP,
    _OD_PARAM_4_5_BPP,
};
#endif

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
EnumODParamIndex ScalerODGetParamSet(DWORD ulMemoryRemainSpace, WORD usMemoryRemainBW);
bit ScalerODGetSupportStatus(void);
EnumFunctionOnOFF ScalerODGetStatus(void);
EnumOdCmpParamMode ScalerODGetCmpParamMode(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_OD_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get OD parameter set
//                according to available memory space & BW.
// Input Value  : Remaining space & BW
// Output Value : Serial num of OD parameter set
//--------------------------------------------------
EnumODParamIndex ScalerODGetParamSet(DWORD ulMemoryRemainSpace, WORD usMemoryRemainBW)
{
    BYTE ucParamI = 0;
    WORD usODUseSpace = 0;
    WORD usODUseBW = 0;
    StructMemoryBWUsageParam stMemBWParam;

    DebugMessageMemory("4. Remaining BW for OD", usMemoryRemainBW);
    DebugMessageMemory("4. Remaining Space for OD", ulMemoryRemainSpace);

    if((_PANEL_PIXEL_TYPE == _PANEL_PIXEL_OLED) || (_PANEL_PIXEL_TYPE == _PANEL_PIXEL_MICRO_LED))
    {
        // Disable OD for emissive panel
        return _OD_PARAM_OFF;
    }

    //=============================================
    // Get memory BW parameters
    //=============================================
    ScalerMDomainGetMemBWParam(&stMemBWParam);

    //=============================================
    // Check if OD 7.5/6.0/4.5 bit mode is avaliable
    //=============================================
    for(ucParamI = 0; ucParamI < (sizeof(tODParamChkList) / sizeof(tODParamChkList[0])); ucParamI++)
    {
        BYTE ucODBit10x = GET_OD_BIT_RATE(tODParamChkList[ucParamI]);

        if(CHECK_OD_PARAM_AVAILABLE(tODParamChkList[ucParamI]) == _FALSE)
        {
            continue;
        }
        usODUseSpace = ScalerMDomainODCalculateMemoryUseSpace(ucODBit10x);
        usODUseBW = ScalerMDomainODCalculateMemoryUseBW(ucODBit10x, &stMemBWParam);

#if(_DEBUG_MESSAGE_MEMORY == _ON)
        if(_TRUE)
        {
            SBYTE pchODBWStr[] = "4. 7_5_bit OD BW";
            SBYTE pchODSizeStr[] = "4. 7_5_bit OD Size";
            pchODBWStr[3] = '0' + (ucODBit10x / 10);
            pchODBWStr[5] = '0' + (ucODBit10x % 10);
            pchODSizeStr[3] = '0' + (ucODBit10x / 10);
            pchODSizeStr[5] = '0' + (ucODBit10x % 10);

            DebugMessageMemory(pchODBWStr, usODUseBW);
            DebugMessageMemory(pchODSizeStr, usODUseSpace);
        }
#endif
        if((usODUseSpace < ulMemoryRemainSpace) && (usODUseBW < usMemoryRemainBW))
        {
            return tODParamChkList[ucParamI];
        }
    }

    //=============================================
    // Otherwise, OD off
    //=============================================
    return _OD_PARAM_OFF;
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
