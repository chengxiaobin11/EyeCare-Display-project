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
// ID Code      : NoneNVRamOsd.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_OSD_TYPE == _NONE_OSD)

#define _PANEL_INDEX_ADDRESS                        (_VGA_MODE_DATA_ADDRESS_END + 1)
#define _OSD_DATA_ADDRESS                           (_PANEL_INDEX_ADDRESS + 1)
#define _OSD_DATA_USER_ADDRESS_END                  (_OSD_DATA_ADDRESS)
//---------------------------------------------------------------------------------------------------------------------------------------

#define _FACTORY_SETTING_DATA_ADDRESS               (_OSD_DATA_USER_ADDRESS_END)

//--------------------------------------------------------------------------------------------

typedef struct
{
    BYTE ucSixColorHueR;
    BYTE ucSixColorSaturationR;
    BYTE ucSixColorHueY;
    BYTE ucSixColorSaturationY;
    BYTE ucSixColorHueG;
    BYTE ucSixColorSaturationG;
    BYTE ucSixColorHueC;
    BYTE ucSixColorSaturationC;
    BYTE ucSixColorHueB;
    BYTE ucSixColorSaturationB;
    BYTE ucSixColorHueM;
    BYTE ucSixColorSaturationM;
} StructSixColorDataType;

typedef struct
{
    WORD usColorTempR;
    WORD usColorTempG;
    WORD usColorTempB;
} StructColorProcDataType;

extern StructSixColorDataType g_stSixColorData;

//----------------------------------------------------------------------------------------
// Extern functions from UserNVRamOsd.c
//----------------------------------------------------------------------------------------
#ifndef __NONE_NVRAM_OSD__
extern void NoneEepromStartup(void);

#define NoneNVRamStartup()                             NoneEepromStartup()
#endif

#endif//#if(_OSD_TYPE == _NONE_OSD)
