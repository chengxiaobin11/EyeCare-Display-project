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
// ID Code      : NoneUserAdjustRGBGamma.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_ADJUST_RGB_GAMMA__

#include "UserCommonInclude.h"

#if((_OSD_TYPE == _NONE_OSD) && (_RGB_GAMMA_FUNCTION == _ON))

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
void UserAdjustRGBGamma(BYTE ucGamma);



//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust Gamma
// Input Value  : Gamma type
// Output Value : None
//--------------------------------------------------
void UserAdjustRGBGamma(BYTE ucGamma)
{
    ScalerColorRGBOutputGammaAdjust(tRGBGAMMA_TABLE[ucGamma - 1], GET_CURRENT_BANK_NUMBER());
}


#endif // End of #if((_OSD_TYPE == _REALTEK_2014_OSD) && (_RGB_GAMMA_FUNCTION == _ON))
