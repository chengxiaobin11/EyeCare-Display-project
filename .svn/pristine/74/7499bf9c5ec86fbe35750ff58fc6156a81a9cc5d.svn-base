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
// ID Code      : UserCommonGlobalDimmingInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_GLOBAL_DIMMING_SUPPORT == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _GLOBAL_DIMMING_MAX_GAIN                   0xA00
#define _GLOBAL_DIMMING_MIN_GAIN                   0x200
#define _GLOBAL_DIMMING_SRGB_MAX                   0x7CC
#define _GLOBAL_DIMMING_WHITE_THD                  668
#define _GLOBAL_DIMMING_ACTIVE_THD                 400
#define _GLOBAL_DIMMING_ONE_STEP_THD               950

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum
{
    _GD_DISABLE = 0,
    _GD_ENABLE,

} EnumGDStatus;

typedef enum
{
    _GD_GAMMA_18 = 0,
    _GD_GAMMA_20,
    _GD_GAMMA_22,
    _GD_GAMMA_24,
    _GD_GAMMA_26,
    _GD_GAMMA_28,

    _GD_PCM_SRGB,
    _GD_PCM_ADOBE,

} EnumGDSDRColorMode;

typedef enum
{
    _GD_PATTERN_MIDDLE_BLACK = 0,
    _GD_PATTERN_NONE,
} EnumGDPatternType;



//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern EnumGDStatus UserCommonGlobalDimmingGetEnableStatus(void);
extern void UserCommonGlobalDimmingInitialSetting(bit bEn);
extern void UserCommonGlobalDimmingEnable(bit bEn);
extern void UserCommonGlobalDimmingSetPWMValue(WORD usPWM);
#if(_GLOBAL_DIMMING_PATTERN_ESTIMATE == _ON)
extern bit UserCommonGlobalDimmingPatternEstimate(EnumGDPatternType enumPatternType);
#endif
#endif // End of #if(_GLOBAL_DIMMING_SUPPORT == _ON)
