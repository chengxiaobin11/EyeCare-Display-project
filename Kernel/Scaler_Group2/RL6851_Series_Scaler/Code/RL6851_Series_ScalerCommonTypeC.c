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
// ID Code      : RL6851_Series_ScalerCommonTypeC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_COMMON_TYPEC__

#include "ScalerFunctionInclude.h"

#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
#if((_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON) && (_TYPE_C_DPAM_VERSION >= _DPAM_VERSION_2_1))
#warning "NOTE: _TYPE_C_DPAM_VERSION >= 2.1 but DP Dose Not Support 128/132B Coding, Cable ID Identification Only for PD."
#endif
#endif

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
#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
StructTypeCInfo g_pstTypeCInfo[_TYPE_C_PORT_VALID];
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
BYTE ScalerTypeCGetTypeCIndex(BYTE ucInputPort);
void ScalerTypeCSetAltModeReady(BYTE ucInputPort, EnumTypeCAltModeStatus enumAltModeStatus);
EnumTypeCAltModeStatus ScalerTypeCRxGetAltModeReady(BYTE ucInputPort);
void ScalerTypeCSetExplicitContract(BYTE ucInputPort, bit bGetExplicitContract);
bit ScalerTypeCRxGetExplicitContract(BYTE ucInputPort);
EnumTypeCPortCtrlType ScalerTypeCGetPortCtrlType(BYTE ucInputPort);
#endif // End of #if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Translate ucInputPort into Type-C Port Index For Macro Usage
// Input Value  : ucInputPort
// Output Value : Type-C Port Index
//--------------------------------------------------
BYTE ScalerTypeCGetTypeCIndex(BYTE ucInputPort)
{
    BYTE ucIndex = 0x00;

#if(_D0_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

    if(ucInputPort == _D0_INPUT_PORT)
    {
        return ucIndex;
    }
    else
    {
        ucIndex = ucIndex + 1;
    }

#endif

#if(_D1_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

    if(ucInputPort == _D1_INPUT_PORT)
    {
        return ucIndex;
    }
    else
    {
        ucIndex = ucIndex + 1;
    }

#endif

#if(_D6_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

    if(ucInputPort == _D6_INPUT_PORT)
    {
        return ucIndex;
    }

#endif

    // enumInputPort Invalid : Show Warning Message
    DebugMessageTypeC("8. [TYPE C] ==========X Invalid TypeC PCB Port For TypeC Index", ucInputPort);

    return ucIndex;
}

//--------------------------------------------------
// Description  : Set System Level Alt Mode Ready to Scaler Level
// Input Value  : ucInputPort (_D0_INPUT_PORT / _D1_INPUT_PORT...), Alt Mode Ready
// Output Value : void
//--------------------------------------------------
void ScalerTypeCSetAltModeReady(BYTE ucInputPort, EnumTypeCAltModeStatus enumAltModeStatus)
{
    SET_TYPE_C_ALT_MODE_READY(ucInputPort, enumAltModeStatus);
}

//--------------------------------------------------
// Description  : For Other Interface to Get Rx Port Alt Mode Ready
// Input Value  : ucInputPort --> Inputput
// Output Value : EnumTypeCAltModeStatus : _TYPE_C_ALT_MODE_NOT_READY / _TYPE_C_ALT_MODE_READY
//--------------------------------------------------
EnumTypeCAltModeStatus ScalerTypeCRxGetAltModeReady(BYTE ucInputPort)
{
    if(ucInputPort != _NO_INPUT_PORT)
    {
        return GET_TYPE_C_ALT_MODE_READY(ucInputPort);
    }
    else
    {
        return _TYPE_C_ALT_MODE_NOT_READY;
    }
}

//--------------------------------------------------
// Description  : Set System Level Explicit Contract to Scaler Level
// Input Value  : ucInputPort (_D0_INPUT_PORT / _D1_INPUT_PORT...), Explicit Contract
// Output Value : void
//--------------------------------------------------
void ScalerTypeCSetExplicitContract(BYTE ucInputPort, bit bGetExplicitContract)
{
    SET_TYPE_C_EXPLICIT_CONTRACT(ucInputPort, bGetExplicitContract);
}

//--------------------------------------------------
// Description  : For Other Interface to Get Rx Port Explicit Contract
// Input Value  : ucInputPort --> Inputput
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit ScalerTypeCRxGetExplicitContract(BYTE ucInputPort)
{
    if(ucInputPort != _NO_INPUT_PORT)
    {
        return GET_TYPE_C_EXPLICIT_CONTRACT(ucInputPort);
    }
    else
    {
        return _FALSE;
    }
}

//--------------------------------------------------
// Description  : For Other Interface to Get Type-C Port Controller Type
// Input Value  : ucInputPort
// Output Value : Type-C Port Controller Type
//--------------------------------------------------
EnumTypeCPortCtrlType ScalerTypeCGetPortCtrlType(BYTE ucInputPort)
{
    EnumTypeCPortCtrlType enumPortCtrlType = _TYPE_C_PORT_CTRL_NONE;

    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
        case _D0_INPUT_PORT:

#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)
            enumPortCtrlType = _TYPE_C_PORT_CTRL_EMBEDDED;
#elif(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_RTS5400_SERIES)
            enumPortCtrlType = _TYPE_C_PORT_CTRL_RTS;
#elif(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_USER)
            enumPortCtrlType = _TYPE_C_PORT_CTRL_USER;
#endif
            break;
#endif  // End of #if(_D0_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

#if(_D1_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
        case _D1_INPUT_PORT:

#if(_D1_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)
            enumPortCtrlType = _TYPE_C_PORT_CTRL_EMBEDDED;
#elif(_D1_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_RTS5400_SERIES)
            enumPortCtrlType = _TYPE_C_PORT_CTRL_RTS;
#elif(_D1_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_USER)
            enumPortCtrlType = _TYPE_C_PORT_CTRL_USER;
#endif
            break;
#endif  // End of #if(_D1_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

#if(_D6_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
        case _D6_INPUT_PORT:

#if(_D6_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)
            enumPortCtrlType = _TYPE_C_PORT_CTRL_EMBEDDED;
#elif(_D6_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_RTS5400_SERIES)
            enumPortCtrlType = _TYPE_C_PORT_CTRL_RTS;
#elif(_D6_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_USER)
            enumPortCtrlType = _TYPE_C_PORT_CTRL_USER;
#endif
            break;
#endif  // End of #if(_D6_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

        default:

            break;
    }

    return enumPortCtrlType;
}
#endif // End of #if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)