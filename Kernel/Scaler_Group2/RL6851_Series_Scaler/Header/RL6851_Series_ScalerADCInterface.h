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
// ID Code      : RL6851_Series_ScalerADCInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_VGA_SUPPORT == _ON)
extern void ScalerADCGainAdjust(BYTE *pucGainMSB, BYTE *pucGainLSB);
extern void ScalerADCOffsetAdjust(BYTE *pucOffsetMSB, BYTE *pucOffsetLSB);
extern void ScalerADCClampMode(EnumColorSpace enumColorFormat);

#if(_VGA_CHROMA_PATTERN12_SUPPORT == _ON)
extern bit ScalerADCGetClampToTopStatus(void);
#endif

extern void ScalerADCDCRestoreEn(bit bEn);
extern void ScalerADCSOGClampEn(bit bEn);

#if(_ADCNR_SUPPORT == _ON)
extern void ScalerADCNREn(bit bEnable);
#endif
#endif // End of #if(_VGA_SUPPORT == _ON)
