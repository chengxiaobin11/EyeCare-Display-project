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
// ID Code      : RL6851_Series_ScalerDrrInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Enum for DRR Enable Type
//--------------------------------------------------
typedef enum
{
    _DRR_FREESYNC_TYPE = 0x00,
    _DRR_HDMI21_VRR_TYPE,        // Both VRR & VRR+FVA
    _DRR_NONE_TYPE,
} EnumDrrType;

#if(_DRR_SUPPORT == _ON)
//--------------------------------------------------
// Definitions of DRR Panel Vfreq MAX/MIN info
//--------------------------------------------------
#define GET_DRR_PANEL_MAX_FRAME_RATE()                      (g_usDrrPanelVFreqMax)
#define SET_DRR_PANEL_MAX_FRAME_RATE(x)                     (g_usDrrPanelVFreqMax = (x))
#define GET_DRR_PANEL_MIN_FRAME_RATE()                      (g_usDrrPanelVFreqMin)
#define SET_DRR_PANEL_MIN_FRAME_RATE(x)                     (g_usDrrPanelVFreqMin = (x))

//--------------------------------------------------
// Definitions of Drr info
//--------------------------------------------------
#define GET_DRR_IVF_INFO()                                  (g_bDrrGetIVFInfo)
#define SET_DRR_IVF_INFO(x)                                 (g_bDrrGetIVFInfo = (x))

#define GET_DRR_VFREQ_MAX()                                 (g_ulDrrVFreqMax)
#define SET_DRR_VFREQ_MAX(x)                                (g_ulDrrVFreqMax = (x))

#define GET_DRR_VFREQ_MIN()                                 (g_ulDrrVFreqMin)
#define SET_DRR_VFREQ_MIN(x)                                (g_ulDrrVFreqMin = (x))
#endif


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_DRR_SUPPORT == _ON)
extern bit g_bDrrGetIVFInfo;

extern WORD g_usDrrPanelVFreqMax;
extern WORD g_usDrrPanelVFreqMin;

extern DWORD g_ulDrrVFreqMax;
extern DWORD g_ulDrrVFreqMin;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_DRR_SUPPORT == _ON)
extern EnumDrrType ScalerDrrGetType(void);

#if(_HDMI21_VRR_SUPPORT == _ON)
extern void ScalerDrrSetPanelVfeqInfo(EnumSourceSearchPort enumInputPort);
extern bit ScalerDrrVfreqMaxInfoEnable(EnumSourceSearchPort enumInputPort, BYTE ucPortType);
#endif
#endif
