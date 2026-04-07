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
// ID Code      : RTD2014UserAdjustUniformity.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#define __USER_ADJUST_UNIFORMITY__

#include "UserCommonInclude.h"

#if((_OSD_TYPE == _REALTEK_2014_OSD) && (_UNIFORMITY_SUPPORT == _ON))

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
void UserAdjustPanelUniformityMode(BYTE ucUniformity);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Auto Recognize Panel Uniformity Mode, and Load Corresponding Panel Uniformity LUT
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustPanelUniformityMode(BYTE ucUniformity)
{
    EnumUniformityTypeSelect enumPanelUniformityType = 0;
    EnumUniformityModeSelect enumPanelUniformityMode = 0;

    if(GET_OSD_PCM_STATUS() == _PCM_OSD_NATIVE)
    {
        enumPanelUniformityMode = _UNIFORMITY_OGC_MODE;
    }
#if(_OCC_SUPPORT == _ON)
    else
    {
        enumPanelUniformityMode = _UNIFORMITY_PCM_MODE;
    }
#endif

    switch(ucUniformity)
    {
        case _UNIFORMITY_OSD_TYPE1:
            enumPanelUniformityType = _UNIFORMITY_TYPE1;
            break;


        case _UNIFORMITY_OSD_TYPE2:
            enumPanelUniformityType = _UNIFORMITY_TYPE2;
            break;


        case _UNIFORMITY_OSD_TYPE3:
            enumPanelUniformityType = _UNIFORMITY_TYPE3;
            break;


        case _UNIFORMITY_OSD_TYPE4:
            enumPanelUniformityType = _UNIFORMITY_TYPE4;
            break;


        case _UNIFORMITY_OSD_TYPE5:
            enumPanelUniformityType = _UNIFORMITY_TYPE5;
            break;


        case _UNIFORMITY_OSD_TYPE6:
            enumPanelUniformityType = _UNIFORMITY_TYPE6;
            break;


        default:
            break;
    }

    UserCommonAdjustPanelUniformity(enumPanelUniformityType, enumPanelUniformityMode);
}
#endif // End of #if((_OSD_TYPE == _REALTEK_2014_OSD) && (_UNIFORMITY_SUPPORT == _ON))

