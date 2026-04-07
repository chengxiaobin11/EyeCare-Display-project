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
// ID Code      : RL6851_Series_ScalerDrr.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_DRR__

#include "ScalerFunctionInclude.h"

#if(_DRR_SUPPORT == _ON)
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
bit g_bDrrGetIVFInfo;

WORD g_usDrrPanelVFreqMax;
WORD g_usDrrPanelVFreqMin;

DWORD g_ulDrrVFreqMax;
DWORD g_ulDrrVFreqMin;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
EnumDrrType ScalerDrrGetType(void);

#if(_HDMI21_VRR_SUPPORT == _ON)
void ScalerDrrSetPanelVfeqInfo(EnumSourceSearchPort enumInputPort);
bit ScalerDrrVfreqMaxInfoEnable(EnumSourceSearchPort enumInputPort, BYTE ucPortType);
#endif
//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Get Drr Enable Type
// Input Value  : none
// Output Value : Drr enable type
//--------------------------------------------------
EnumDrrType ScalerDrrGetType(void)
{
#if(_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _TRUE)
    {
        return _DRR_FREESYNC_TYPE;
    }
#endif

#if(_HDMI21_VRR_SUPPORT == _ON)
    if(ScalerTMDSMacRxGetHdmi21VrrStatus() == _TRUE)
    {
        return _DRR_HDMI21_VRR_TYPE;
    }
#endif

    return _DRR_NONE_TYPE;
}

#if(_HDMI21_VRR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Drr Panel Vfeq Info
// Input Value  : enumInputPort, enumDrrType
// Output Value : None
//--------------------------------------------------
void ScalerDrrSetPanelVfeqInfo(EnumSourceSearchPort enumInputPort)
{
    WORD usDrrPanelVfreqMax = _PANEL_MAX_FRAME_RATE;
    WORD usDrrPanelVfreqMin = _PANEL_MIN_FRAME_RATE;
    EnumDrrType enumDrrType = ScalerDrrGetType();

    switch(enumInputPort)
    {
        case _D0_INPUT_PORT:
            if(enumDrrType == _DRR_FREESYNC_TYPE)
            {
#if((_DP_FREESYNC_SUPPORT == _ON) || (_HDMI_FREESYNC_SUPPORT == _ON))
                usDrrPanelVfreqMax = _PANEL_FREESYNC_MAX_FRAME_RATE;
                usDrrPanelVfreqMin = _PANEL_FREESYNC_MIN_FRAME_RATE;
#endif
            }
            else if(enumDrrType == _DRR_HDMI21_VRR_TYPE)
            {
#if((_D0_HDMI_SUPPORT == _ON) && (_HDMI21_VRR_SUPPORT == _ON))
                usDrrPanelVfreqMax = _PANEL_HDMI21_VRR_MAX_FRAME_RATE;
                usDrrPanelVfreqMin = _PANEL_HDMI21_VRR_MIN_FRAME_RATE;
#endif
            }
            break;

        case _D1_INPUT_PORT:
            if(enumDrrType == _DRR_FREESYNC_TYPE)
            {
#if((_DP_FREESYNC_SUPPORT == _ON) || (_HDMI_FREESYNC_SUPPORT == _ON))
                usDrrPanelVfreqMax = _PANEL_FREESYNC_MAX_FRAME_RATE;
                usDrrPanelVfreqMin = _PANEL_FREESYNC_MIN_FRAME_RATE;
#endif
            }
            else if(enumDrrType == _DRR_HDMI21_VRR_TYPE)
            {
#if((_D1_HDMI_SUPPORT == _ON) && (_HDMI21_VRR_SUPPORT == _ON))
                usDrrPanelVfreqMax = _PANEL_HDMI21_VRR_MAX_FRAME_RATE;
                usDrrPanelVfreqMin = _PANEL_HDMI21_VRR_MIN_FRAME_RATE;
#endif
            }
            break;

        case _D2_INPUT_PORT:
            if(enumDrrType == _DRR_FREESYNC_TYPE)
            {
#if((_DP_FREESYNC_SUPPORT == _ON) || (_HDMI_FREESYNC_SUPPORT == _ON))
                usDrrPanelVfreqMax = _PANEL_FREESYNC_MAX_FRAME_RATE;
                usDrrPanelVfreqMin = _PANEL_FREESYNC_MIN_FRAME_RATE;
#endif
            }
            else if(enumDrrType == _DRR_HDMI21_VRR_TYPE)
            {
#if((_D2_HDMI_SUPPORT == _ON) && (_HDMI21_VRR_SUPPORT == _ON))
                usDrrPanelVfreqMax = _PANEL_HDMI21_VRR_MAX_FRAME_RATE;
                usDrrPanelVfreqMin = _PANEL_HDMI21_VRR_MIN_FRAME_RATE;
#endif
            }
            break;

        case _D3_INPUT_PORT:
            if(enumDrrType == _DRR_FREESYNC_TYPE)
            {
#if((_D3_HDMI_SUPPORT == _ON) && (_HDMI_FREESYNC_SUPPORT == _ON))
                usDrrPanelVfreqMax = _PANEL_FREESYNC_MAX_FRAME_RATE;
                usDrrPanelVfreqMin = _PANEL_FREESYNC_MIN_FRAME_RATE;
#endif
            }
            else if(enumDrrType == _DRR_HDMI21_VRR_TYPE)
            {
#if((_D3_HDMI_SUPPORT == _ON) && (_HDMI21_VRR_SUPPORT == _ON))
                usDrrPanelVfreqMax = _PANEL_HDMI21_VRR_MAX_FRAME_RATE;
                usDrrPanelVfreqMin = _PANEL_HDMI21_VRR_MIN_FRAME_RATE;
#endif
            }
            break;

        case _D4_INPUT_PORT:
            if(enumDrrType == _DRR_FREESYNC_TYPE)
            {
#if((_D4_HDMI_SUPPORT == _ON) && (_HDMI_FREESYNC_SUPPORT == _ON))
                usDrrPanelVfreqMax = _PANEL_FREESYNC_MAX_FRAME_RATE;
                usDrrPanelVfreqMin = _PANEL_FREESYNC_MIN_FRAME_RATE;
#endif
            }
            else if(enumDrrType == _DRR_HDMI21_VRR_TYPE)
            {
#if((_D4_HDMI_SUPPORT == _ON) && (_HDMI21_VRR_SUPPORT == _ON))
                usDrrPanelVfreqMax = _PANEL_HDMI21_VRR_MAX_FRAME_RATE;
                usDrrPanelVfreqMin = _PANEL_HDMI21_VRR_MIN_FRAME_RATE;
#endif
            }
            break;

        case _D5_INPUT_PORT:
            if(enumDrrType == _DRR_FREESYNC_TYPE)
            {
#if((_D5_HDMI_SUPPORT == _ON) && (_HDMI_FREESYNC_SUPPORT == _ON))
                usDrrPanelVfreqMax = _PANEL_FREESYNC_MAX_FRAME_RATE;
                usDrrPanelVfreqMin = _PANEL_FREESYNC_MIN_FRAME_RATE;
#endif
            }
            else if(enumDrrType == _DRR_HDMI21_VRR_TYPE)
            {
#if((_D5_HDMI_SUPPORT == _ON) && (_HDMI21_VRR_SUPPORT == _ON))
                usDrrPanelVfreqMax = _PANEL_HDMI21_VRR_MAX_FRAME_RATE;
                usDrrPanelVfreqMin = _PANEL_HDMI21_VRR_MIN_FRAME_RATE;
#endif
            }
            break;

        default:
            break;
    }
    SET_DRR_PANEL_MAX_FRAME_RATE(usDrrPanelVfreqMax);
    SET_DRR_PANEL_MIN_FRAME_RATE(usDrrPanelVfreqMin);
}

//--------------------------------------------------
// Description  : Drr Vfreq Max Info Enable
// Input Value  : enumInputPort, ucPortType
// Output Value : _TRUE, _FAIL
//--------------------------------------------------
bit ScalerDrrVfreqMaxInfoEnable(EnumSourceSearchPort enumInputPort, BYTE ucPortType)
{
    enumInputPort = enumInputPort;

#if(_FREESYNC_SUPPORT == _ON)
    if(ScalerDrrGetType() == _DRR_FREESYNC_TYPE)
    {
        // AMD ver 1 & 2
        if((ScalerSyncGetAmdVsdbVer(enumInputPort) == _AMD_VER1) ||
           (ScalerSyncGetAmdVsdbVer(enumInputPort) == _AMD_VER2))
        {
            if(GET_FREESYNC_SPD_INFO_FRAME_RECEIVED() == _TRUE)
            {
#if(_HDMI_FREESYNC_SUPPORT == _ON)
                if((ucPortType == _PORT_HDMI) || (ucPortType == _PORT_DVI))
                {
                    return GET_HDMI_FREESYNC_ENABLED();
                }
                else
#endif
                {
#if(_DP_FREESYNC_SUPPORT == _ON)
#if(_DP_DRR_GET_IVF_TYPE == _DP_DRR_SPD_INFO)
                    if(ucPortType == _PORT_DP)
                    {
                        return GET_DP_FREESYNC_ENABLED();
                    }
#endif
#endif
                }
            }
            else
            {
                // Gsync
            }
        }
        else
        {
            // Version 3 or _AMD_VER_NONE
        }
    }
#endif

#if(_HDMI21_VRR_SUPPORT == _ON)
    if((ucPortType == _PORT_HDMI) && (ScalerDrrGetType() == _DRR_HDMI21_VRR_TYPE))
    {
        return _TRUE;
    }
#endif

    return _FALSE;
}
#endif
#endif
