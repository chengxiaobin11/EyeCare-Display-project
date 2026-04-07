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
// ID Code      : RL6851_Series_ScalerCommonDpAdaptiveSync.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_COMMON_DP_ADAPTIVESYNC__

#include "ScalerCommonFunctionInclude.h"

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
#if(_DP_SUPPORT == _ON)
#if(_DP_ADAPTIVESYNC_SUPPORT == _ON)
#if(_TRANSLATOR_SUPPORT == _OFF)
void ScalerDpAdaptiveSyncSupportSwitch(EnumSourceSearchPort enumSourcePort, EnumDpAdaptiveSyncSupport enumSupport);
#endif
#endif // End of #if(_DP_FREESYNC_SUPPORT == _ON)
#endif // End of #if(_DP_SUPPORT == _ON)

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_DP_SUPPORT == _ON)
#if(_DP_ADAPTIVESYNC_SUPPORT == _ON)
#if(_TRANSLATOR_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Switch DP ADAPTIVESYNCSYNC Support
// Input Value  : Hotplug Type and ADAPTIVESYNCSYNC Enable or Not
// Output Value : None
//--------------------------------------------------
void ScalerDpAdaptiveSyncSupportSwitch(EnumSourceSearchPort enumSourcePort, EnumDpAdaptiveSyncSupport enumSupport)
{
    switch(enumSourcePort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

            if(GET_DP_RX0_ADAPTIVESYNC_SUPPORT() != enumSupport)
            {
                SET_DP_RX_CAPABILITY_SWITCHED();
                SET_DP_RX0_ADAPTIVESYNC_CAPABILITY_SWITCH();
                SET_DP_RX0_ADAPTIVESYNC_SUPPORT(enumSupport);
            }

            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:

            if(GET_DP_RX1_ADAPTIVESYNC_SUPPORT() != enumSupport)
            {
                SET_DP_RX_CAPABILITY_SWITCHED();
                SET_DP_RX1_ADAPTIVESYNC_CAPABILITY_SWITCH();
                SET_DP_RX1_ADAPTIVESYNC_SUPPORT(enumSupport);
            }

            break;
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
        case _D2_INPUT_PORT:

            if(GET_DP_RX2_ADAPTIVESYNC_SUPPORT() != enumSupport)
            {
                SET_DP_RX_CAPABILITY_SWITCHED();
                SET_DP_RX2_ADAPTIVESYNC_CAPABILITY_SWITCH();
                SET_DP_RX2_ADAPTIVESYNC_SUPPORT(enumSupport);
            }

            break;
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:

            if(GET_DP_RX6_ADAPTIVESYNC_SUPPORT() != enumSupport)
            {
                SET_DP_RX_CAPABILITY_SWITCHED();
                SET_DP_RX6_ADAPTIVESYNC_CAPABILITY_SWITCH();
                SET_DP_RX6_ADAPTIVESYNC_SUPPORT(enumSupport);
            }

            break;
#endif

        default:
            break;
    }
}
#endif

#endif // End of #if(_DP_ADAPTIVESYNC_SUPPORT == _ON)
#endif // End of #if(_DP_SUPPORT == _ON)

