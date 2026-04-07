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
// ID Code      : ScalerCommonFreeSyncInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_FREESYNC_SUPPORT == _ON)
#define _EDID_ANALYSIS_CLK_MARGIN                        (1)
#define _EDID_ANALYSIS_HTOTAL_MARGIN                     (2)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
//--------------------------------------------------
// Struct for FREESYNC Ver from Edid
//--------------------------------------------------
typedef struct
{
    BYTE b3D0FreeSyncVerbyEdid : 3;
    BYTE b3D1FreeSyncVerbyEdid : 3;
    BYTE b3D2FreeSyncVerbyEdid : 3;
    BYTE b3D3FreeSyncVerbyEdid : 3;
    BYTE b3D4FreeSyncVerbyEdid : 3;
    BYTE b3D5FreeSyncVerbyEdid : 3;
} StructDrrFreesyncVerByEdid;

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

typedef struct
{
    BYTE b1Interlace : 1;
    WORD usHwidth;
    WORD usVheight;
    WORD usHblank;
    WORD usPixelClk;
    WORD usHtotal;
    WORD usVtotal;
} StructFreeSyncEdidInfo;

typedef struct
{
    BYTE b1RefInterlace : 1;
    WORD usRefHwidth;
    WORD usRefVheight;
    WORD usRefHblankHBound;
    WORD usRefHblankLBound;
    WORD usPixelClkHBound;
    WORD usPixelClkLBound;
} StructFreeSyncEdidRefInfo;

//--------------------------------------------------
// Enum for FreeSync IVF Max from Table Search
//--------------------------------------------------
typedef enum
{
    _TABLE_SEARCHING_WITH_IVF_MAX = 0x00,
    _TABLE_SEARCHING_WITHOUT_IVF_MAX,
} EnumGetIVFFromTableSearch;
#endif

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
// FUNCTION EXTERN
//****************************************************************************
#if(_FREESYNC_SUPPORT == _ON)

#if(_DP_SUPPORT == _ON)
#if(_DP_FREESYNC_SUPPORT == _ON)
extern WORD ScalerFreeSyncDpGetHSPeriod(EnumSourceSearchPort enumSourceSearchPort);
extern WORD ScalerFreeSyncDpGetHSW(EnumSourceSearchPort enumSourceSearchPort);
extern WORD ScalerFreeSyncDpGetVFreq(EnumSourceSearchPort enumSourceSearchPort);
extern WORD ScalerFreeSyncDpGetVSPeriod(EnumSourceSearchPort enumSourceSearchPort);

#if(_D0_DP_EXIST == _ON)
extern DWORD ScalerFreeSyncDpRx0GetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
extern void ScalerFreeSyncDpRx0GetSPDVfreqMaxMin(void);
#endif

#if(_D1_DP_EXIST == _ON)
extern DWORD ScalerFreeSyncDpRx1GetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
extern void ScalerFreeSyncDpRx1GetSPDVfreqMaxMin(void);
#endif
#endif
#endif

#if(_HDMI_SUPPORT == _ON)
#if(_HDMI_FREESYNC_SUPPORT == _ON)
#if(_HDMI_MAC_PAGE2_USE == _ON)
extern DWORD ScalerFreeSyncHDMIRx0GetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
#endif

#if(_HDMI_MAC_PAGE71_USE == _ON)
extern DWORD ScalerFreeSyncHDMIRx2GetAmdSpdInfo(EnumAmdSpdInfoContent enumContent, bit bD1Combo);
#endif

#if(_HDMI_MAC_PAGE72_USE == _ON)
extern DWORD ScalerFreeSyncHDMIRx3GetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
#endif

#if(_HDMI_MAC_PAGE73_USE == _ON)
extern DWORD ScalerFreeSyncHDMIRx4GetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
#endif

#if(_HDMI_MAC_PAGE74_USE == _ON)
extern DWORD ScalerFreeSyncHDMIRx5GetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
#endif
#endif // End of #if(_HDMI_FREESYNC_SUPPORT == _ON)
#endif // End of #if(_HDMI_SUPPORT == _ON)

#endif
