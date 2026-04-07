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
// ID Code      : ScalerDisplayInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------


//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_PANEL_STYLE == _PANEL_VBO)
typedef struct
{
    BYTE b1VboLocknStatus     : 1;
    BYTE b1VboLocknRippedOff  : 1;
    BYTE b1PanelFastOffStatus : 1;
} StructVboInfo;
#endif // #if(_PANEL_STYLE == _PANEL_VBO)

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_PANEL_STYLE == _PANEL_VBO)
extern StructVboInfo g_stVboInfo;
#endif

extern StructDisplayCustomizedData g_stDisplayCustomizedData;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_PANEL_STYLE == _PANEL_LVDS)
extern void ScalerDisplayLvdsTxDataSel(void);
extern void ScalerDisplayLvdsTxPortSwap(void);
#endif

#if(_PANEL_STYLE == _PANEL_VBO)
extern void ScalerDisplayVboMac(bit bOn);
extern void ScalerDisplayVboPhy(bit bOn);
extern void ScalerDisplayVboCdr2AlnLatency(void);
extern void ScalerDisplayVboHtpdnSetFwControl(bit bEnable);
extern bit ScalerDisplayGetVboPowerStatus(void);
extern void ScalerDisplaySetVboPLLSSC(bit bDclkSpreadSpeed, BYTE ucSpreadRange);
extern void ScalerDisplayVboInitialTable(void);
extern void ScalerDisplayVboPLL(bit bOn);
extern void ScalerDisplayVboPower(bit bOn);
extern void ScalerDisplayVboSetZ0(void);
#endif

extern BYTE ScalerDisplaySelectDVFMode(void);
extern void ScalerDisplaySetDVFreq(void);

