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
// ID Code      : ScalerSyncInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_DP_SUPPORT == _ON)
typedef enum
{
    _DP_LONG_HPD_TIME = _USER_DP_LONG_HPD_TIME_VALUE,
    _DP_HDCP_LONG_HPD_TIME = _USER_DP_HDCP_LONG_HPD_TIME_VALUE,
    _DP_MST_LONG_HPD_TIME = 800,
    _DP_HBR2_MARGIN_LINK_HPD_TIME = 800,
    _DP_MST_FORCE_LONG_HPD_TIME = 5000,
    _DP_HPD_ASSERTED_TIME = 0,
    _DP_HPD_TIME_NONE = 0xFFFF,
} EnumDpHotPlugTime;

//--------------------------------------------------
// Structure of DP Port Hot Plug Time
//--------------------------------------------------
typedef struct
{
#if(_D0_DP_EXIST == _ON)
    EnumDpHotPlugTime enumD0HpdTime;
#endif
#if(_D1_DP_EXIST == _ON)
    EnumDpHotPlugTime enumD1HpdTime;
#endif
#if(_D2_DP_EXIST == _ON)
    EnumDpHotPlugTime enumD2HpdTime;
#endif
} StructDpPortHpdTime;

//--------------------------------------------------
// Struct of HPD Sequence for HotPlugHandler
//--------------------------------------------------
typedef struct
{
    EnumSourceSearchPort enumPort;
    EnumDpHotPlugTime enumHpdTime;
} StructHpdSequence;
#endif

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_FREESYNC_SUPPORT == _ON)
extern BYTE code tVIC_VFREQ_TABLE[256];
extern WORD code tVIC_HACTIVE_TABLE[256];
extern WORD code tVIC_HBLANK_TABLE[256];
extern WORD code tVIC_VACTIVE_TABLE[256];
extern WORD code tVIC_PIXEL_RATE_TABLE[256];
extern BYTE code tInterlaceVic[];
#endif

//------------------------------------------------------
// Definitions of DP Link Loss time interval check (ms)
//------------------------------------------------------
#define _DP_RX_LINK_LOSS_CHECK_INTERVAL                 30

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if((_FREESYNC_SUPPORT == _ON) || (_EMBEDDED_EDID_SUPPORT == _ON) || (_DP_TX_EDID_MODIFY_REMOVE_HDR_FS2_SUPPORT == _ON))
extern void ScalerSyncGetCtaExtDbAddress(WORD *pusCtaDataBlockAddr, BYTE *pucDdcRamAddr);
extern void ScalerSyncGetDidExtDbAddress(WORD *pusDidDataBlockAddr, BYTE *pucDdcRamAddr);
#endif

#if(_DP_SUPPORT == _ON)
#if(_HW_DIGITAL_PORT_COMBO_PHY_TYPE != _DIGITAL_PORT_COMBO_PHY_ALL)
extern void ScalerSyncDpMeasureCountInitial(void);
#endif
#endif

#if(_ADC_SUPPORT == _ON)
extern void ScalerSyncAdcApllPowerDown(void);
extern void ScalerSyncAdcPowerProc(EnumPowerAction enumPowerAction);
#endif

#if(_DDR_BURN_IN_TEST == _ON)
extern void ScalerSyncDDRBurnInCRCTest(void);
#endif
