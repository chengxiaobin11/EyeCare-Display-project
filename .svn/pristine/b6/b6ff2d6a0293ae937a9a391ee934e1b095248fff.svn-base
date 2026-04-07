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
// ID Code      : ScalerDDomainInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************

#if(_PANEL_EXIST_MULTIPANEL == _ON)
extern BYTE g_ucDDomainPanelIndex;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerDDomainPatternGenEnable(bit bEnable);
extern void ScalerDDomainPatternGenAdjustColor(BYTE ucRed, BYTE ucGreen, BYTE ucBlue);

#if(_OGC_GEN_TYPE == _OGC_GEN_1)
#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
extern void ScalerDDomainPatternGenAdjustColor10bit(WORD usRed, WORD usGreen, WORD usBlue);
#endif
#endif

#if(_FREESYNC_OD_MEASURE == _ON)
extern void ScalerDDomainFREESYNCODSetBackgroundGrayLevel(void);
#endif

