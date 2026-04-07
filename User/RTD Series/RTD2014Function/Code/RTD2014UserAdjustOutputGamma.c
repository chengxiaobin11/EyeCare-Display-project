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
// ID Code      : RTD2014UserAdjustOutputGamma.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_ADJUST_OUTPUT_GAMMA__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)

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
#if(_GAMMA_FUNCTION == _ON)
void UserAdjustGamma(BYTE ucGamma);
#endif


//-------------------------------------------------------
// PCM
//-------------------------------------------------------
#if(_PCM_FUNCTION == _ON)
void UserAdjustPCM(BYTE ucPCM);
#if(_OCC_PCM_GAMMA_SUPPORT == _ON)
EnumOCCPCMGammaType UserAdjustOCCPCMGammaOSDMapping(EnumGammaType enumGammaType);
EnumOCCPCMGammaCTMatrix UserAdjustOCCPCMGammaCTOSDMapping(EnumColortemptureDef enumColortemptureDef);
#endif
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_GAMMA_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Adjust Gamma
// Input Value  : Gamma type
// Output Value : None
//--------------------------------------------------
void UserAdjustGamma(BYTE ucGamma)
{
#if(_OGC_SUPPORT == _ON)
    BYTE ucGammaBankNum = 0;
    BYTE *pucGammaBankAddr = _NULL_POINTER;
#endif

	if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
	{
		ucGamma = _GAMMA_22;
	}
	
	//DebugMessageOsd("2.ucGammalxh",ucGamma);

    if(ucGamma != _GAMMA_OFF)
    {
#if(_OGC_SUPPORT == _ON)
        ucGammaBankNum = UserCommonAdjustOGCBank(ucGamma - 1, _OGC_NORMAL_TYPE);
        pucGammaBankAddr = UserCommonAdjustOGCAddr(ucGamma - 1, _OGC_NORMAL_TYPE);

        UserCommonAdjustGamma(pucGammaBankAddr, ucGammaBankNum);
		
       // UserCommonAdjustGamma(tGAMMA_TABLE[ucGamma - 1], GET_CURRENT_BANK_NUMBER());

        RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
		
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
		
#if(_CONTRAST_SUPPORT == _ON)
        UserAdjustContrast(GET_OSD_CONTRAST());
#endif



#else // 

#if(_RGB_GAMMA_FUNCTION == _ON)
        ScalerColorRGBOutputGammaEnable(_FUNCTION_OFF);
#endif

        UserCommonAdjustGamma(tGAMMA_TABLE[ucGamma - 1], GET_CURRENT_BANK_NUMBER());

#if(_CONTRAST_6BIT_PANEL_COMPENSATE == _ON)
        RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

#if(_CONTRAST_SUPPORT == _ON)
        UserAdjustContrast(GET_OSD_CONTRAST());
#endif
#endif

#if(_RGB_GAMMA_FUNCTION == _ON)
        UserAdjustRGBGamma(ucGamma);
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        ScalerColorRGBOutputGammaEnable(_FUNCTION_ON);
#endif


#endif // End of #if(_OGC_SUPPORT == _ON)
    }
}
#endif

#if(_PCM_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Adjust PCM
// Input Value  : ucPCM
// Output Value : None
//--------------------------------------------------
void UserAdjustPCM(BYTE ucPCM)
{
    if(ucPCM != _PCM_OSD_NATIVE)
    {
#if(_OCC_SUPPORT == _ON)
        if(ucPCM == _PCM_OSD_SRGB)
        {
            UserCommonAdjustPCM(_PCM_SRGB, _NULL_POINTER, g_pucDISP_CALIBRATION_FLASH + _OCC_GAMMA10_ADDRESS, g_pucDISP_CALIBRATION_FLASH + _OCC_SRGBMATRIX_ADDRESS, _OGC_FLASH_BANK, _OCC_COLORMATRIX_TABLE_SIZE);
        }
#if(_DEF_PCM_ADOBE_RGB == _ON)
        else if(ucPCM == _PCM_OSD_ADOBE_RGB)
        {
            UserCommonAdjustPCM(_PCM_ADOBE_RGB, _NULL_POINTER, g_pucDISP_CALIBRATION_FLASH + _OCC_GAMMA10_ADDRESS, g_pucDISP_CALIBRATION_FLASH + _OCC_ADOBEMATRIX_ADDRESS, _OGC_FLASH_BANK, _OCC_COLORMATRIX_TABLE_SIZE);
        }
#endif
		else if(ucPCM == _PCM_OSD_DCI_P3)
		{
#if(_DEFAULT_OSD_STYLE==_TRG_OSD_STYLE)
			UserCommonAdjustPCM(_PCM_DISPLAY_P3, _NULL_POINTER, g_pucDISP_CALIBRATION_FLASH + _OCC_GAMMA10_ADDRESS, g_pucDISP_CALIBRATION_FLASH + _OCC_DISPLAYP3_ADDRESS, _OGC_FLASH_BANK, _OCC_COLORMATRIX_TABLE_SIZE);
#else
			UserCommonAdjustPCM(_PCM_DCI_P3, _NULL_POINTER, g_pucDISP_CALIBRATION_FLASH + _OCC_GAMMA10_ADDRESS, g_pucDISP_CALIBRATION_FLASH + _OCC_DCIP3_ADDRESS, _OGC_FLASH_BANK, _OCC_COLORMATRIX_TABLE_SIZE);
#endif
		}

#if(_RGB_3D_GAMMA == _ON)
        else if(ucPCM == _PCM_OSD_SOFT_PROFT)
        {
            UserCommonAdjustPCM(_PCM_SOFT_PROFT, _NULL_POINTER, g_pucDISP_CALIBRATION_FLASH + _OCC_GAMMA10_ADDRESS, g_pucDISP_CALIBRATION_FLASH + _OCC_SOFTPROOF_ADDRESS, _OGC_FLASH_BANK, _OCC_COLORMATRIX_TABLE_SIZE);
        }
#endif // End of #if(_RGB_3D_GAMMA == _ON)

        else
#endif // End of #if(_OCC_SUPPORT == _ON)
        {
            UserCommonAdjustPCM(_PCM_USER_MODE, tPCM_USER_TABLE[(ucPCM - _PCM_OSD_DCI_P3) * 3], tPCM_USER_TABLE[((ucPCM - _PCM_OSD_DCI_P3) * 3) + 1], tPCM_USER_TABLE[((ucPCM - _PCM_OSD_DCI_P3) * 3) + 2], GET_CURRENT_BANK_NUMBER(), _OCC_COLORMATRIX_TABLE_SIZE);
        }
    }
#if(_OCC_PCM_GAMMA_SUPPORT == _ON)
    else
    {
        if(GET_OSD_GAMMA() != _GAMMA_OFF)
        {
            UserCommonAdjustPCM(_PCM_OCC_GAMMA,
                                (BYTE *)UserCommonAdjustOCCPCMGammaGetTableAddress(UserAdjustOCCPCMGammaOSDMapping(GET_OSD_GAMMA())),
                                g_pucDISP_CALIBRATION_FLASH + _OCC_GAMMA10_ADDRESS,
                                g_pucDISP_CALIBRATION_FLASH + UserCommonAdjustOCCPCMGammaGetsRGBCTTableAddress(UserAdjustOCCPCMGammaCTOSDMapping(GET_COLOR_TEMP_TYPE()), _OGC_NORMAL_TYPE),
                                GET_CURRENT_BANK_NUMBER(), _OCC_COLORMATRIX_TABLE_SIZE);
        }
    }
#endif

}
#if(_OCC_PCM_GAMMA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Mapping User OGC struct to Scaler PCM Gamma struct
// Input Value  : EnumGammaType
// Output Value : EnumPCMGammaType
//--------------------------------------------------
EnumOCCPCMGammaType UserAdjustOCCPCMGammaOSDMapping(EnumGammaType enumGammaType)
{
    EnumOCCPCMGammaType enumOCCPCMGammaType = _OCC_PCM_GAMMA_OFF;

    switch(enumGammaType)
    {
        case _GAMMA_OFF:
            enumOCCPCMGammaType = _OCC_PCM_GAMMA_OFF;
            break;

        case _GAMMA_18:
            enumOCCPCMGammaType = _OCC_PCM_GAMMA_18;
            break;

        case _GAMMA_20:
            enumOCCPCMGammaType = _OCC_PCM_GAMMA_20;
            break;

        case _GAMMA_22:
            enumOCCPCMGammaType = _OCC_PCM_GAMMA_22;
            break;

        case _GAMMA_24:
        default:
            enumOCCPCMGammaType = _OCC_PCM_GAMMA_24;
            break;
    }

    return enumOCCPCMGammaType;
}

//--------------------------------------------------
// Description  : Mapping User Temperature struct to Scaler PCM Gamma Temperature struct
// Input Value  : EnumGammaType
// Output Value : EnumPCMGammaType
//--------------------------------------------------
EnumOCCPCMGammaCTMatrix UserAdjustOCCPCMGammaCTOSDMapping(EnumColortemptureDef enumColortemptureDef)
{
    EnumOCCPCMGammaCTMatrix enumOCCPCMGammaCTMatrix = _OCC_PCM_GAMMA_CT_OFF;

    switch(enumColortemptureDef)
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


#if(_OCC_COLORTEMP_TRANSFER_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Color Transfer Matrix TABLE For CCT adjust
// Input Value  : User Mode Table Index
// Output Value : PCM User Modee table address
//--------------------------------------------------
void UserAdjustGetColorTransferUserModeTableAddress(EnumPCMType enumPCMType, EnumColortemptureDef enumOSDColorTempIndex, WORD *pusTable)
{
    BYTE ucI = 0;
    EnumColorimetryTransfer enumColorimetryTransfer = _COLORIMETRY_TRANSFER_DEFUALT_CCT;
    if(enumPCMType == _PCM_SRGB)
    {
        switch(enumOSDColorTempIndex)
        {
            case _CT_9300:
                enumColorimetryTransfer = _COLORIMETRY_TRANSFER_USER_DEFINE_5;
                break;
            case _CT_7500:
                enumColorimetryTransfer = _COLORIMETRY_TRANSFER_USER_DEFINE_3;
                break;
            case _CT_6500:
            default:
                enumColorimetryTransfer = _COLORIMETRY_TRANSFER_DEFUALT_CCT;
                break;
        }
    }
    else if(enumPCMType == _PCM_DCI_P3)
    {
        switch(enumOSDColorTempIndex)
        {
            case _CT_9300:
                enumColorimetryTransfer = _COLORIMETRY_TRANSFER_USER_DEFINE_12;
                break;
            case _CT_7500:
                enumColorimetryTransfer = _COLORIMETRY_TRANSFER_USER_DEFINE_10;
                break;
            case _CT_6500:
            default:
                enumColorimetryTransfer = _COLORIMETRY_TRANSFER_DEFUALT_CCT;
                break;
        }
    }
    for(ucI = 0; ucI < _COLORIMETRY_TRANSFER_MATRIX_SIZE; ucI++)
    {
        pusTable[ucI] = *(tPCM_COLORTRANSFER_MATRIX + (enumColorimetryTransfer * _COLORIMETRY_TRANSFER_MATRIX_SIZE) + ucI);
    }
}
#endif


#endif  // End of #if(_PCM_FUNCTION == _ON)
#endif // End of #if(_OSD_TYPE == _REALTEK_2014_OSD)
