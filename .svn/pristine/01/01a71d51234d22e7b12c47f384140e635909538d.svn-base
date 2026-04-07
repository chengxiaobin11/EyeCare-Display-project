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
// ID Code      : RTD2014UserInterDimming.c
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_INTERFACE_DIMMING__

#include "UserCommonInclude.h"

#if((_OSD_TYPE == _REALTEK_2014_OSD) && (_BACKLIGHT_DIMMING_SUPPORT == _ON))

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
EnumSDRCalibrationType UserInterfaceSDROCCOGCMode(void);
EnumSDRPCMStatus UserInterfaceGetSDRPCMMode(void);
EnumSDROGCStatus UserInterfaceGetSDROGCMode(void);
#if(_GLOBAL_DIMMING_SUPPORT == _ON)
#if(_OCC_PCM_GAMMA_SUPPORT == _ON)
EnumOCCPCMGammaCTMatrix UserInterfaceGetSDRPCMOCCGammaMode(void);
#endif
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : whether SDR mode calibrated by OCC/OGC
// Input Value  : void
// Output Value : _SDR_CALIBRATION_BY_OGC_TOOL / _SDR_NONE_CALIBRATION_BY_OGC_TOOL,
//--------------------------------------------------
EnumSDRCalibrationType UserInterfaceSDROCCOGCMode(void)
{
    if((GET_OSD_PCM_STATUS() == _PCM_OSD_NATIVE) &&
       (GET_OSD_GAMMA() == _GAMMA_OFF))
    {
        return _SDR_NONE_CALIBRATION_BY_OGC_TOOL;
    }
    else
    {
        return _SDR_CALIBRATION_BY_OGC_TOOL;
    }
}

//--------------------------------------------------
// Description  : which SDR mode calibrated by OCC selected
// Input Value  : void
// Output Value : EnumSDRPCMStatus
//--------------------------------------------------
EnumSDRPCMStatus UserInterfaceGetSDRPCMMode(void)
{
#if(_PCM_FUNCTION == _ON)
    if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE)
    {
        switch(GET_OSD_PCM_STATUS())
        {
#if(_OCC_SUPPORT == _ON)
            case _PCM_OSD_SRGB:
                return _SDR_SRGB;
				
#if(_DEF_PCM_ADOBE_RGB == _ON)
            case _PCM_OSD_ADOBE_RGB:
                return _SDR_ADOBE_RGB;
#endif

#endif
			case _PCM_OSD_DCI_P3:

				return _SDR_DCI_P3;

            default:
                return _SDR_NONE_OCC;
        }
    }
#endif // End of #if(_PCM_FUNCTION == _ON)
    return _SDR_NONE_OCC;
}


//--------------------------------------------------
// Description  : which SDR mode calibrated by OGC be selected
// Input Value  : void
// Output Value : EnumSDROGCStatus
//--------------------------------------------------
EnumSDROGCStatus UserInterfaceGetSDROGCMode(void)
{
    switch(GET_OSD_GAMMA())
    {
#if(_OGC_SUPPORT == _ON)
        case _GAMMA_18:
            return _SDR_OGC_CASE_1;
#if(_OGC_TOTAL_GAMMA > 1)
        case _GAMMA_20:
            return _SDR_OGC_CASE_2;
#if(_OGC_TOTAL_GAMMA > 2)
        case _GAMMA_22:
            return _SDR_OGC_CASE_3;
#if(_OGC_TOTAL_GAMMA > 3)
        case _GAMMA_24:
            return _SDR_OGC_CASE_4;
#endif
#endif
#endif
#endif
        default:
            return _SDR_NONE_OGC;
    }
}

#if(_GLOBAL_DIMMING_SUPPORT == _ON)
#if(_OCC_PCM_GAMMA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : which SDR mode calibrated by OCC PCM Gamma be selected
// Input Value  : void
// Output Value : EnumOCCPCMGammaCTMatrix
//--------------------------------------------------
EnumOCCPCMGammaCTMatrix UserInterfaceGetSDRPCMOCCGammaMode(void)
{
    EnumOCCPCMGammaCTMatrix enumOCCPCMGammaCTMatrix = _OCC_PCM_GAMMA_CT_OFF;

    switch(GET_COLOR_TEMP_TYPE())
    {
        case _CT_9300:
            enumOCCPCMGammaCTMatrix = _OCC_PCM_GAMMA_CT_MODE1;
            break;

        case _CT_7500:
            enumOCCPCMGammaCTMatrix = _OCC_PCM_GAMMA_CT_MODE2;
            break;

        case _CT_6500:
            enumOCCPCMGammaCTMatrix = _OCC_PCM_GAMMA_CT_MODE3;
            break;

        case _CT_5000:
            enumOCCPCMGammaCTMatrix = _OCC_PCM_GAMMA_CT_MODE4;
            break;

        case _CT_SRGB:
            enumOCCPCMGammaCTMatrix = _OCC_PCM_GAMMA_CT_MODE5;
            break;

        case _CT_USER:
        default:
            enumOCCPCMGammaCTMatrix = _OCC_PCM_GAMMA_CT_MODE6;
            break;
    }

    return enumOCCPCMGammaCTMatrix;
}

#endif
#endif
#endif // End of #if((_OSD_TYPE == _REALTEK_2014_OSD) && (_BACKLIGHT_DIMMING_SUPPORT == _ON))

