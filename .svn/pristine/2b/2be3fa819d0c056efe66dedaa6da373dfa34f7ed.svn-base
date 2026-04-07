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
// ID Code      : ScalerCommonFreeSyncInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_HDMI_FREESYNC_SUPPORT == _ON)
extern StructDrrAmdAupiInfo g_stDrrHdmiAmdAupiInfo;
#endif

#if((_HDMI_FREESYNC_SUPPORT == _ON) || (_HDMI_FREESYNC_II_SUPPORT == _ON))
extern StructDrrFreeSyncHdmiEnableInfo g_stDrrFreeSyncHdmiInfo;
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_FREESYNC_SUPPORT == _ON)
typedef struct
{
    BYTE ucColorSapce;
    WORD usHtotal;
    WORD usHtotalMargin;
} StructFreeSyncSourceInfo;

typedef struct
{
    WORD usIHwidth;
    WORD usIVheight;
    WORD usIHtotal;
    WORD usPixelClk;
    WORD usIVfreq;
} StructDrrFreeSyncTimingInfo;

//--------------------------------------------------
// Enum for FreeSync IVF Max from Table Search
//--------------------------------------------------
typedef enum
{
    _TABLE_SEARCHING_WITH_IVF_MAX = 0x00,
    _TABLE_SEARCHING_WITHOUT_IVF_MAX,
} EnumGetIVFFromTableSearch;

#if(_DP_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Enum for DP FreeSync IVF Max
//--------------------------------------------------
typedef enum
{
    _DP_FREESYNC_WITH_IVF_MAX = 0x00,
    _DP_FREESYNC_WITHOUT_IVF_MAX,
} EnumDrrFreeSyncDpGetIVF;
#endif

#if(_HDMI_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Enum for HDMI FreeSync IVF Max
//--------------------------------------------------
typedef enum
{
    _HDMI_FREESYNC_WITH_IVF_MAX = 0x00,
    _HDMI_FREESYNC_WITHOUT_IVF_MAX,
} EnumDrrFreeSyncHdmiGetIVF;
#endif
#endif


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_FREESYNC_SUPPORT == _ON)
extern DWORD ScalerFreeSyncGetFreeSyncInfo(EnumSourceSearchPort enumSearchPort, EnumAmdSpdInfoContent enumContent);
extern void ScalerFreeSyncSPDInfoReceive(EnumSourceSearchPort enumSearchPort);
extern bit ScalerFreeSyncVfreqMaxInfoEnable(EnumSourceSearchPort enumInputPort, BYTE ucPortType);
extern void ScalerFreeSyncGetSourceInfo(EnumSourceSearchPort enumSearchPort, BYTE ucPortType, StructFreeSyncSourceInfo *pstSourceInfo);
extern EnumGetIVFFromTableSearch ScalerFreeSyncEdidAnalysisGetVfreqMax(BYTE *pucReadArray, WORD usPixelClk, const StructFreeSyncSourceInfo *pstSourceInfo, WORD *pusVfreqMax);
extern EnumGetIVFFromTableSearch ScalerFreeSyncCalculateIVFmaxFromCVT(WORD *pusVfreqMax, const StructFreeSyncSourceInfo *pstSourceInfo, BYTE ucPortType);

#if(_TRANSLATOR_SUPPORT == _OFF)
extern void ScalerFreeSyncSupportSwitch(EnumSourceSearchPort enumSourcePort, EnumFreeSyncSupport enumSupport, EnumSourceSearchPort enumFreesyncTargetPort);
#endif

#if(_HDMI_SUPPORT == _ON)
#if(_HDMI_FREESYNC_SUPPORT == _ON)
#if((_DEBUG_MESSAGE_SUPPORT == _OFF) &&\
    (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
extern EnumFreeSyncSupport ScalerFreeSyncHDMIGetFreeSyncSupport_EXINT1(EnumSourceSearchPort enumSourcePort);
#endif
#endif
#endif

#endif

