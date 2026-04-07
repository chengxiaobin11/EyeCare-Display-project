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

#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// ID Code      : RL6851_Series_ScalerCommonTypeCInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define GET_TYPE_C_ALT_MODE_READY(x)                        (g_pstTypeCInfo[ScalerTypeCGetTypeCIndex(x)].enumAltModeStatus)
#define SET_TYPE_C_ALT_MODE_READY(x, y)                     (g_pstTypeCInfo[ScalerTypeCGetTypeCIndex(x)].enumAltModeStatus = (y))

#define GET_TYPE_C_EXPLICIT_CONTRACT(x)                     (g_pstTypeCInfo[ScalerTypeCGetTypeCIndex(x)].b1PowerContract)
#define SET_TYPE_C_EXPLICIT_CONTRACT(x, y)                  (g_pstTypeCInfo[ScalerTypeCGetTypeCIndex(x)].b1PowerContract = (y))

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
//--------------------------------------------------
// Structure of Type-C Related Structs
//--------------------------------------------------
typedef struct
{
    EnumTypeCAltModeStatus enumAltModeStatus;
    // -----------------------------
    BYTE b1PowerContract : 1;
} StructTypeCInfo;


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern StructTypeCInfo g_pstTypeCInfo[_TYPE_C_PORT_VALID];

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern EnumTypeCAltModeStatus ScalerTypeCRxGetAltModeReady(BYTE ucInputPort);
extern bit ScalerTypeCRxGetExplicitContract(BYTE ucInputPort);
#endif // End of #if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

