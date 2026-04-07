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
// ID Code      : RTD2014UserAdjust3DGamma.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_ADJUST_3D_GAMMA__

#include "UserCommonInclude.h"

#if((_OSD_TYPE == _REALTEK_2014_OSD) && (_RGB_3D_GAMMA == _ON))

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
void UserAdjust3DGamma(BYTE uc3DGammaMode);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust 3D Gamma
// Input Value  : 3D Gamma type
// Output Value : None
//--------------------------------------------------
void UserAdjust3DGamma(BYTE uc3DGammaMode)
{
//    if(uc3DGammaMode != _3D_GAMMA_OFF)
    {
        ScalerColorRGB3DGammaAdjust(tRGB3DGAMMA_TABLE[uc3DGammaMode], GET_CURRENT_BANK_NUMBER());
    }
}
#endif // End of #if((_OSD_TYPE == _REALTEK_2014_OSD) && (_RGB_3D_GAMMA == _ON))


