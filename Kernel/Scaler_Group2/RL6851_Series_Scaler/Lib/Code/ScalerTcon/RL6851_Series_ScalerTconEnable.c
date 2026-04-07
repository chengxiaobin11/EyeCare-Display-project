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
// ID Code      : RL6851_Series_ScalerTconEnable.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "RL6851_Series_ScalerTconLibInternalInclude.h"

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
void ScalerTconEnable(bit bEnable);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Enable TCON
// Input Value  : bEnable --> Enable TCON
// Output Value : None
//--------------------------------------------------
void ScalerTconEnable(bit bEnable)
{
    if(bEnable == _ON)
    {
        // Enable All TCON
        ScalerTconGlobalEnable(_ON);
#if(_HW_PWM_RST_BY_TCON_SELECT == _TCON7)
        // Enable TCON7
        ScalerTcon7Enable(_ON);
#elif(_HW_PWM_RST_BY_TCON_SELECT == _TCON8)
        // Enable TCON8
        ScalerTcon8Enable(_ON);
#endif
    }
    else
    {
        // Disable All TCON
        ScalerTconGlobalEnable(_OFF);
#if(_HW_PWM_RST_BY_TCON_SELECT == _TCON7)
        // Disable TCON7
        ScalerTcon7Enable(_OFF);
#elif(_HW_PWM_RST_BY_TCON_SELECT == _TCON8)
        // Disable TCON8
        ScalerTcon8Enable(_OFF);
#endif
    }
}
