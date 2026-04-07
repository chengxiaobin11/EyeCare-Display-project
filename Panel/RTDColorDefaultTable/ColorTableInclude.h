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
// Color Default Value
//----------------------------------------------------------------------------------------------------
#include "ColorDitherDefault.h"
#include "ColorTempDefault.h"

#ifdef __USER_PANEL__

#if(_DCC_FUNCTION == _ON)
//----------------------------------------------------------------------------------------------------
// DCC Table
//----------------------------------------------------------------------------------------------------
/*
BYTE code tDCC_GAME[] =
{
#include "./DCC/DccModeGame.h"
};

BYTE code tDCC_MOVIE[] =
{
#include "./DCC/DccModeMovie.h"
};

BYTE code tDCC_PHOTO[] =
{
#include "./DCC/DccModePhoto.h"
};

BYTE code tDCC_VIVID[] =
{
#include "./DCC/DccModeVivid.h"
};
*/

BYTE code tDCC_Mode0[] =
{
#include ".\DCC\DccMode0.h"
};
BYTE code tDCC_Mode1[] =
{
#include ".\DCC\DccMode1.h"
};
BYTE code tDCC_Mode2[] =
{
#include ".\DCC\DccMode2.h"
};
BYTE code tDCC_Mode3[] =
{
#include ".\DCC\DccMode3.h"
};
BYTE code tDCC_Mode4[] =
{
#include ".\DCC\DccMode4.h"
};
BYTE code tDCC_Mode5[] =
{
#include ".\DCC\DccMode5.h"
};
BYTE code tDCC_Mode6[] =
{
#include ".\DCC\DccMode6.h"
};
BYTE code tDCC_Mode7[] =
{
#include ".\DCC\DccMode7.h"
};
BYTE code tDCC_Mode8[] =
{
#include ".\DCC\DccMode8.h"
};
BYTE code tDCC_Mode9[] =
{
#include ".\DCC\DccMode9.h"
};
BYTE code tDCC_Mode10[] =
{
#include ".\DCC\DccMode10.h"
};

BYTE code tDCC_Mode11[] =
{
#include ".\DCC\DccMode11.h"
};

BYTE code tDCC_Mode12[] =
{
#include ".\DCC\DccMode12.h"
};

BYTE code tDCC_Mode13[] =
{
#include ".\DCC\DccMode13.h"
};

BYTE code tDCC_Mode14[] =
{
#include ".\DCC\DccMode14.h"
};

BYTE code tDCC_Mode15[] =
{
#include ".\DCC\DccMode15.h"
};

BYTE code tDCC_Mode16[] =
{
#include ".\DCC\DccMode16.h"
};

BYTE code tDCC_Mode17[] =
{
#include ".\DCC\DccMode17.h"
};

BYTE code tDCC_Mode18[] =
{
#include ".\DCC\DccMode18.h"
};

BYTE code tDCC_Mode19[] =
{
#include ".\DCC\DccMode19.h"
};

BYTE code tDCC_Mode20[] =
{
#include ".\DCC\DccMode20.h"
};

BYTE code tDCC_Mode21[] =
{
#include ".\DCC\DccMode21.h"
};

BYTE code tDCC_Mode22[] =
{
#include ".\DCC\DccMode22.h"
};

#if 1
code BYTE *tDCC_TABLE[] =
{

    tDCC_Mode0,
    tDCC_Mode1,
    tDCC_Mode2,
    tDCC_Mode3,
    tDCC_Mode4,
    tDCC_Mode5,
    tDCC_Mode6,
    tDCC_Mode7,
    tDCC_Mode8,
    tDCC_Mode9,
    tDCC_Mode10,
    tDCC_Mode11,
    tDCC_Mode12,
    tDCC_Mode13,
    tDCC_Mode14,
    tDCC_Mode15,
    tDCC_Mode16,
    tDCC_Mode17,
    tDCC_Mode18,
    tDCC_Mode19,
    tDCC_Mode20,
    tDCC_Mode21,
    tDCC_Mode22,
};

#else

code BYTE *tDCC_TABLE[] =
{
    NULL,  // Standard
    tDCC_GAME,
    tDCC_MOVIE,
    tDCC_PHOTO,
    tDCC_VIVID,
};
#endif // End of #if(_DCC_FUNCTION == _ON)

#endif // End of #if(_DCC_FUNCTION == _ON)

#if(_ICM_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// ICM Table
//----------------------------------------------------------------------------------------------------
BYTE code tICM_GAME[] =
{
#include "./ICM/IcmModeGame.h"
};

BYTE code tICM_MOVIE[] =
{
#include "./ICM/IcmModeMovie.h"
};

BYTE code tICM_PHOTO[] =
{
#include "./ICM/IcmModePhoto.h"
};

BYTE code tICM_VIVID[] =
{
#include "./ICM/IcmModeVivid.h"
};

code BYTE *tICM_TABLE[] =
{
    NULL,  // Standard
    tICM_GAME,
	tICM_MOVIE,
    tICM_PHOTO,
    tICM_VIVID,


	

};

//----------------------------------------------------------------------------------------------------
// SCM Table
//----------------------------------------------------------------------------------------------------
BYTE code tSCM_VIVID[] =
{
#include "./ICM/ScmModeVivid.h"
};

code BYTE *tSCM_TABLE[] =
{
    NULL,  // Standard
    NULL,  // Game
    NULL,  // Movie
    NULL,  // Photo
    tSCM_VIVID,
};

#endif // End of #if(_ICM_SUPPORT == _ON)



#if(_OD_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// OD Table
//----------------------------------------------------------------------------------------------------
#include "ODTable.h"

code BYTE *tOD_TABLE[] =
{
    tOD_TABLE_COMMON,

	
#if(_PROJECT_ID ==_ID_ZQ_2557E02_SG2701B08_4_FHD200_MKF27F240L_20250515)
    tOD_TABLE_COMMON1,

#endif
};

#if(_FREESYNC_SUPPORT == _ON)
code BYTE *tOD_FREESYNC_TABLE[] =
{
    tOD_TABLE_FREESYNC,
};
#endif
#endif // End of #if(_OD_SUPPORT == _ON)

#if(_SDR_TO_HDR_SUPPORT == _ON)
BYTE code tSDRTOHDR_INPUTGAMMA[] =
{
#include "./SDRtoHDR/SDRtoHDRInputGammaTable.h"
};

BYTE code tSDRTOHDR_ICM[] =
{
#include "./SDRtoHDR/SDRtoHDRICMTable.h"
};

BYTE code tSDRTOHDR_DCC[] =
{
#include "./SDRtoHDR/SDRtoHDRDCCTable.h"
};
#endif
#endif // End of #ifdef __USER_PANEL__

#ifdef __USER_COMMON_ADJUST__

//----------------------------------------------------------------------------------------------------
// Dithering Table
//----------------------------------------------------------------------------------------------------
#if(_I_DITHER_SUPPORT == _ON)
BYTE code tIDITHER_TABLE_FIFO8[] =
{
#if((_IDITHER_TYPE == _IDITHER_GEN_0_1_SEQ_TRUNCATE_2_0_BIT) || (_IDITHER_TYPE == _IDITHER_GEN_2_1_SEQ_NO_TEMPO_TRUNCATE_2_0_BIT))
#include "./IDither/IDitherTableGen0Fifo8.h"
#elif((_IDITHER_TYPE == _IDITHER_GEN_1_4_SEQ_TRUNCATE_4_2_BIT) || (_IDITHER_TYPE == _IDITHER_GEN_3_4_SEQ_TRUNCATE_6_4_2_BIT))
#include "./IDither/IDitherTableGen1Fifo8.h"
#endif
};

BYTE code tIDITHER_TABLE_FIFO10[] =
{
#if((_IDITHER_TYPE == _IDITHER_GEN_0_1_SEQ_TRUNCATE_2_0_BIT) || (_IDITHER_TYPE == _IDITHER_GEN_2_1_SEQ_NO_TEMPO_TRUNCATE_2_0_BIT))
#include "./IDither/IDitherTableGen0Fifo10.h"
#elif((_IDITHER_TYPE == _IDITHER_GEN_1_4_SEQ_TRUNCATE_4_2_BIT) || (_IDITHER_TYPE == _IDITHER_GEN_3_4_SEQ_TRUNCATE_6_4_2_BIT))
#include "./IDither/IDitherTableGen1Fifo10.h"
#endif
};

BYTE code tIDITHER_SEQ_TABLE[] =
{
#if((_IDITHER_TYPE == _IDITHER_GEN_0_1_SEQ_TRUNCATE_2_0_BIT) || (_IDITHER_TYPE == _IDITHER_GEN_2_1_SEQ_NO_TEMPO_TRUNCATE_2_0_BIT))
#include "./IDither/IDitherTableSeq1.h"
#elif((_IDITHER_TYPE == _IDITHER_GEN_1_4_SEQ_TRUNCATE_4_2_BIT) || (_IDITHER_TYPE == _IDITHER_GEN_3_4_SEQ_TRUNCATE_6_4_2_BIT))
#if(((_I_DITHER_MULTI_SEQ_ENABLE == _DISABLE) && (_I_DITHER_SERIES_SEQ_ENABLE == _DISABLE)))
#include "./IDither/IDitherTableSeq1.h"
#else
#include "./IDither/IDitherTableSeq4.h"
#endif
#endif
};

#if((_IDITHER_TYPE == _IDITHER_GEN_0_1_SEQ_TRUNCATE_2_0_BIT) || (_IDITHER_TYPE == _IDITHER_GEN_1_4_SEQ_TRUNCATE_4_2_BIT) || (_IDITHER_TYPE == _IDITHER_GEN_3_4_SEQ_TRUNCATE_6_4_2_BIT))
BYTE code tIDITHER_TEMPOFFSET_TABLE[] =
{
#include "./IDither/IDitherTableTempo.h"
};
#endif
#endif // End of #if(_I_DITHER_SUPPORT == _ON)

#if(_D_DITHER_SUPPORT == _ON)

#if(_PANEL_EXIST_MULTIPANEL == _OFF)

BYTE code tDDITHER_TABLE[] =
{
#if(_PANEL_DISP_BIT_MODE == _PANEL_DISP_18_BIT)

#if((_DDITHER_TYPE == _DDITHER_GEN_0_4BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_2_4_SEQ_NO_TEMPO_4BIT_DITHERTBL))
#include "./DDither/DDitherGen0Dither18Bit.h"
#elif(_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL)
#include "./DDither/DDitherGen1Dither30Bit.h"
#elif(_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2)
#include "./DDither/DDitherGen1Dither24Bit.h"
#endif

#elif(_PANEL_DISP_BIT_MODE == _PANEL_DISP_24_BIT)

#if((_DDITHER_TYPE == _DDITHER_GEN_0_4BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_2_4_SEQ_NO_TEMPO_4BIT_DITHERTBL))
#include "./DDither/DDitherGen0Dither24Bit.h"
#elif((_DDITHER_TYPE == _DDITHER_GEN_1_6BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL) || (_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2))
#include "./DDither/DDitherGen1Dither24Bit.h"
#endif

#elif(_PANEL_DISP_BIT_MODE == _PANEL_DISP_30_BIT)

#if((_DDITHER_TYPE == _DDITHER_GEN_0_4BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_2_4_SEQ_NO_TEMPO_4BIT_DITHERTBL))
#include "./DDither/DDitherGen0Dither30Bit.h"
#elif((_DDITHER_TYPE == _DDITHER_GEN_1_6BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL) || (_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2))
#include "./DDither/DDitherGen1Dither30Bit.h"
#endif

#endif
};

#else // Else of #if(_PANEL_EXIST_MULTIPANEL == _OFF)

#if(_DDITHER_TYPE != _DDITHER_GEN_1_6BIT_DITHERTBL)
BYTE code tDDITHER_TABLE18Bit[] =
{
#if((_DDITHER_TYPE == _DDITHER_GEN_0_4BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_2_4_SEQ_NO_TEMPO_4BIT_DITHERTBL))
#include "./DDither/DDitherGen0Dither18Bit.h"
#elif(_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL)
#include "./DDither/DDitherGen1Dither30Bit.h"
#elif(_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2)
#include "./DDither/DDitherGen1Dither24Bit.h"
#endif
};
#endif

BYTE code tDDITHER_TABLE24Bit[] =
{
#if((_DDITHER_TYPE == _DDITHER_GEN_0_4BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_2_4_SEQ_NO_TEMPO_4BIT_DITHERTBL))
#include "./DDither/DDitherGen0Dither24Bit.h"
#elif((_DDITHER_TYPE == _DDITHER_GEN_1_6BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL) || (_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2))
#include "./DDither/DDitherGen1Dither24Bit.h"
#endif
};

BYTE code tDDITHER_TABLE30Bit[] =
{
#if((_DDITHER_TYPE == _DDITHER_GEN_0_4BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_2_4_SEQ_NO_TEMPO_4BIT_DITHERTBL))
#include "./DDither/DDitherGen0Dither30Bit.h"
#elif((_DDITHER_TYPE == _DDITHER_GEN_1_6BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL) || (_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2))
#include "./DDither/DDitherGen1Dither30Bit.h"
#endif
};

#endif

BYTE code tDDITHER_SEQ_TABLE[] =
{
#if((_DDITHER_TYPE == _DDITHER_GEN_0_4BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_2_4_SEQ_NO_TEMPO_4BIT_DITHERTBL))
#if(_D_DITHER_MULTI_SEQ_ENABLE == _DISABLE)
#include "./DDither/DDitherGen0Seq1.h"
#else
#include "./DDither/DDitherGen0Seq4.h"
#endif
#elif((_DDITHER_TYPE == _DDITHER_GEN_1_6BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL) || (_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2))
#if(((_D_DITHER_MULTI_SEQ_ENABLE == _DISABLE) && (_D_DITHER_SERIES_SEQ_ENABLE == _DISABLE)) && (_D_DITHER_ADVANCE_SETTING_ENABLE != _ENABLE))
#include "./DDither/DDitherGen1Seq1.h"
#else
#include "./DDither/DDitherGen1Seq4.h"
#endif
#endif
};

#if((_DDITHER_TYPE == _DDITHER_GEN_0_4BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_1_6BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL) || (_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2))
BYTE code tDDITHER_TEMPOFFSET_TABLE[] =
{
#if(_DDITHER_TYPE == _DDITHER_GEN_0_4BIT_DITHERTBL)
#include "./DDither/DDitherGen0Tempo.h"
#elif((_DDITHER_TYPE == _DDITHER_GEN_1_6BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL) || (_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2))
#include "./DDither/DDitherGen1Tempo.h"
#endif
};
#endif

#if((_DDITHER_TYPE == _DDITHER_GEN_1_6BIT_DITHERTBL) || (_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL) || (_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2))
#if(_D_DITHER_ADVANCE_SETTING_ENABLE == _ENABLE)
BYTE code tDDITHER_REALIGN_TABLE[] =
{
#include "./DDither/DDitherGen1Realign.h"
};

BYTE code tDDITHER_REALIGN_TEMPO_TABLE[] =
{
#include "./DDither/DDitherGen1RealignTempo.h"
};

#if(_PANEL_EXIST_MULTIPANEL == _OFF)

BYTE code tDDITHER_LSB_TABLE[] =
{
#if(_PANEL_DISP_BIT_MODE == _PANEL_DISP_18_BIT)
#if(_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL)
#include "./DDither/DDitherGen1LSB30Bit.h"
#elif(_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2)
#include "./DDither/DDitherGen1LSB24Bit.h"
#endif
#elif(_PANEL_DISP_BIT_MODE == _PANEL_DISP_24_BIT)
#include "./DDither/DDitherGen1LSB24Bit.h"
#elif(_PANEL_DISP_BIT_MODE == _PANEL_DISP_30_BIT)
#include "./DDither/DDitherGen1LSB30Bit.h"
#endif
};

BYTE code tDDITHER_ADVANCE_SETTING_TABLE[] =
{
#if(_PANEL_DISP_BIT_MODE == _PANEL_DISP_18_BIT)
#if(_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL)
#include "./DDither/DDitherGen1AdvanceS418Bit.h"
#elif(_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2)
#include "./DDither/DDitherGen1AdvanceS218Bit.h"
#endif
#elif(_PANEL_DISP_BIT_MODE == _PANEL_DISP_24_BIT)
#include "./DDither/DDitherGen1Advance24Bit.h"
#elif(_PANEL_DISP_BIT_MODE == _PANEL_DISP_30_BIT)
#include "./DDither/DDitherGen1Advance30Bit.h"
#endif
};

#else // Else of #if(_PANEL_EXIST_MULTIPANEL == _OFF)

#if((_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL) || (_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2))
BYTE code tDDITHER_LSB_TABLE18Bit[] =
{
#if(_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL)
#include "./DDither/DDitherGen1LSB30Bit.h"
#elif(_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2)
#include "./DDither/DDitherGen1LSB24Bit.h"
#endif
};
#endif

BYTE code tDDITHER_LSB_TABLE24Bit[] =
{
#include "./DDither/DDitherGen1LSB24Bit.h"
};

BYTE code tDDITHER_LSB_TABLE30Bit[] =
{
#include "./DDither/DDitherGen1LSB30Bit.h"
};

#if((_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL) || (_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2))
BYTE code tDDITHER_ADVANCE_SETTING_TABLE18Bit[] =
{
#if(_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL)
#include "./DDither/DDitherGen1AdvanceS418Bit.h"
#elif(_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2)
#include "./DDither/DDitherGen1AdvanceS218Bit.h"
#endif
};
#endif

BYTE code tDDITHER_ADVANCE_SETTING_TABLE24Bit[] =
{
#include "./DDither/DDitherGen1Advance24Bit.h"
};

BYTE code tDDITHER_ADVANCE_SETTING_TABLE30Bit[] =
{
#include "./DDither/DDitherGen1Advance30Bit.h"
};

#endif // End of #if(_PANEL_EXIST_MULTIPANEL == _OFF)

#endif
#endif
#endif

#endif // End of #ifdef __USER_COMMON_ADJUST__

#ifdef __USER_ADJUST_OUTPUT_GAMMA__

#if((_GAMMA_FUNCTION == _ON) )
//----------------------------------------------------------------------------------------------------
// Gamma Table
//----------------------------------------------------------------------------------------------------
BYTE code tLUTGAMMA_18_TABLE[] =
{
#include "./GAMMA/Gamma18.h"
};

BYTE code tLUTGAMMA_20_TABLE[] =
{
#include "./GAMMA/Gamma20.h"
};

BYTE code tLUTGAMMA_22_TABLE[] =
{
#include "./GAMMA/Gamma22.h"
};

BYTE code tLUTGAMMA_24_TABLE[] =
{
#include "./GAMMA/Gamma24.h"
};

BYTE code tLUTGAMMA_26_TABLE[] =
{
#include "./GAMMA/Gamma26.h"
};

BYTE code tLUTGAMMA_28_TABLE[] =
{
#include "./GAMMA/Gamma28.h"
};

code BYTE *tGAMMA_TABLE[] =
{
    tLUTGAMMA_18_TABLE,
    tLUTGAMMA_20_TABLE,
    tLUTGAMMA_22_TABLE,
    tLUTGAMMA_24_TABLE,
	tLUTGAMMA_26_TABLE,
	tLUTGAMMA_28_TABLE,

};
#endif // End of #if((_GAMMA_FUNCTION == _ON) && (_OGC_SUPPORT == _OFF))

#if(_PCM_FUNCTION == _ON)
//----------------------------------------------------------------------------------------------------
// PCM Table
//----------------------------------------------------------------------------------------------------
BYTE code tPCM_USER_INPUT_GAMMA_TABLE[] =
{
#include "./PCM/PCMUserInputGammaTable.h"
};

BYTE code tPCM_USER_MATRIX[] =
{
#include "./PCM/PCMUserColorMatrixTable.h"
};

BYTE code tPCM_USER_OUTPUT_GAMMA_TABLE[] =
{
#include "./PCM/PCMUserOutputGammaTable.h"
};

// Color Transfer Matrix TABLE For CCT adjust
#if(_OCC_COLORTEMP_TRANSFER_FUNCTION == _ON)
WORD code tPCM_COLORTRANSFER_MATRIX[] =
{
#include <RTDColorDefaultTable/PCM/PCMUserColorMatrixTransferMatrixTable.h>
};
#endif

code BYTE *tPCM_USER_TABLE[] =
{
    tPCM_USER_INPUT_GAMMA_TABLE,    tPCM_USER_OUTPUT_GAMMA_TABLE,   tPCM_USER_MATRIX,
};
#endif // End of #if(_PCM_FUNCTION == _ON)

#endif // End of #ifdef __USER_ADJUST_OUTPUT_GAMMA__

#ifdef __USER_ADJUST_RGB_GAMMA__

#if(_RGB_GAMMA_FUNCTION == _ON)

BYTE code tLUTRGBGAMMA_18_TABLE[] =
{
#include "./GAMMA/RGBGamma18.h"
};

BYTE code tLUTRGBGAMMA_20_TABLE[] =
{
#include "./GAMMA/RGBGamma20.h"
};

BYTE code tLUTRGBGAMMA_22_TABLE[] =
{
#include "./GAMMA/RGBGamma22.h"
};

BYTE code tLUTRGBGAMMA_24_TABLE[] =
{
#include "./GAMMA/RGBGamma24.h"
};

code BYTE *tRGBGAMMA_TABLE[] =
{
    tLUTRGBGAMMA_18_TABLE,
    tLUTRGBGAMMA_20_TABLE,
    tLUTRGBGAMMA_22_TABLE,
    tLUTRGBGAMMA_24_TABLE,
};
#endif// End of #if(_RGB_GAMMA_FUNCTION == _ON)

#endif // End of #ifdef __USER_ADJUST_RGB_GAMMA__


#ifdef __USER_ADJUST_3D_GAMMA__

#if(_RGB_3D_GAMMA == _ON)

BYTE code tRGB3DGAMMA_MODE0_TABLE[] =
{
#include "./GAMMA/3DGammaMode0.h"
};

code BYTE *tRGB3DGAMMA_TABLE[] =
{
    tRGB3DGAMMA_MODE0_TABLE,
    tRGB3DGAMMA_MODE0_TABLE,
};

#endif // End of #if(_RGB_3D_GAMMA == _ON)
#endif // End of #ifdef __USER_ADJUST_3D_GAMMA__

#ifdef __USER_INTERFACE_HDR__
#if(_HDR10_LIGHT_ENHANCE_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// LightEnhance TABLE
//----------------------------------------------------------------------------------------------------
BYTE code tDCC_LIGHTENHANCE_120_540_TABLE[] =
{
#include "./HDR/HDR10_LightEnhance_Type1_540nit_Table.h"
};

BYTE code tDCC_LIGHTENHANCE_120_1200_TABLE[] =
{
#include "./HDR/HDR10_LightEnhance_Type1_1200nit_Table.h"
};

BYTE code tDCC_LIGHTENHANCE_120_4000_TABLE[] =
{
#include "./HDR/HDR10_LightEnhance_Type1_4000nit_Table.h"
};

BYTE code tDCC_LIGHTENHANCE_120_10000_TABLE[] =
{
#include "./HDR/HDR10_LightEnhance_Type1_10000nit_Table.h"
};

BYTE code tDCC_LIGHTENHANCE_140_540_TABLE[] =
{
#include "./HDR/HDR10_LightEnhance_Type2_540nit_Table.h"
};

BYTE code tDCC_LIGHTENHANCE_140_1200_TABLE[] =
{
#include "./HDR/HDR10_LightEnhance_Type2_1200nit_Table.h"
};

BYTE code tDCC_LIGHTENHANCE_140_4000_TABLE[] =
{
#include "./HDR/HDR10_LightEnhance_Type2_4000nit_Table.h"
};

BYTE code tDCC_LIGHTENHANCE_140_10000_TABLE[] =
{
#include "./HDR/HDR10_LightEnhance_Type2_10000nit_Table.h"
};

BYTE code tDCC_LIGHTENHANCE_160_540_TABLE[] =
{
#include "./HDR/HDR10_LightEnhance_Type3_540nit_Table.h"
};

BYTE code tDCC_LIGHTENHANCE_160_1200_TABLE[] =
{
#include "./HDR/HDR10_LightEnhance_Type3_1200nit_Table.h"
};

BYTE code tDCC_LIGHTENHANCE_160_4000_TABLE[] =
{
#include "./HDR/HDR10_LightEnhance_Type3_4000nit_Table.h"
};

BYTE code tDCC_LIGHTENHANCE_160_10000_TABLE[] =
{
#include "./HDR/HDR10_LightEnhance_Type3_10000nit_Table.h"
};

code BYTE *tDCC_LIGHTENHANCE_120_TABLE[] =
{
    tDCC_LIGHTENHANCE_120_540_TABLE,
    tDCC_LIGHTENHANCE_120_1200_TABLE,
    tDCC_LIGHTENHANCE_120_4000_TABLE,
    tDCC_LIGHTENHANCE_120_10000_TABLE,
};

code BYTE *tDCC_LIGHTENHANCE_140_TABLE[] =
{
    tDCC_LIGHTENHANCE_140_540_TABLE,
    tDCC_LIGHTENHANCE_140_1200_TABLE,
    tDCC_LIGHTENHANCE_140_4000_TABLE,
    tDCC_LIGHTENHANCE_140_10000_TABLE,
};

code BYTE *tDCC_LIGHTENHANCE_160_TABLE[] =
{
    tDCC_LIGHTENHANCE_160_540_TABLE,
    tDCC_LIGHTENHANCE_160_1200_TABLE,
    tDCC_LIGHTENHANCE_160_4000_TABLE,
    tDCC_LIGHTENHANCE_160_10000_TABLE,
};
#endif

#if(_HDR10_COLOR_ENHANCE_SUPPORT == _ON)
BYTE code tICM_COLORENHANCE_LEVEL1_TABLE[] =
{
#include "./HDR/HDR10_ColorEnhance_Level1_Table.h"
};

BYTE code tICM_COLORENHANCE_LEVEL2_TABLE[] =
{
#include "./HDR/HDR10_ColorEnhance_Level2_Table.h"
};

BYTE code tICM_COLORENHANCE_LEVEL3_TABLE[] =
{
#include "./HDR/HDR10_ColorEnhance_Level3_Table.h"
};

code BYTE *tICM_COLORENHANCE_TABLE[] =
{
    tICM_COLORENHANCE_LEVEL1_TABLE,
    tICM_COLORENHANCE_LEVEL2_TABLE,
    tICM_COLORENHANCE_LEVEL3_TABLE,
};
#endif

#if(_HDR10_SUPPORT == _ON)
#if(_DCC_FUNCTION == _ON)
//----------------------------------------------------------------------------------------------------
// HDR10 DCC Table
//----------------------------------------------------------------------------------------------------
BYTE code tDCC_HDR10_GAME[] =
{
#include "./DCC/DccModeGame.h"
};

BYTE code tDCC_HDR10_MOVIE[] =
{
#include "./DCC/DccModeMovie.h"
};

BYTE code tDCC_HDR10_PHOTO[] =
{
#include "./DCC/DccModePhoto.h"
};

BYTE code tDCC_HDR10_VIVID[] =
{
#include "./DCC/DccModeVivid.h"
};

code BYTE *tDCC_HDR10_TABLE[] =
{
    NULL,  // Standard
    tDCC_HDR10_GAME,
    tDCC_HDR10_MOVIE,
    tDCC_HDR10_PHOTO,
    tDCC_HDR10_VIVID,
};
#endif

#if(_ICM_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// HDR10 ICM Table
//----------------------------------------------------------------------------------------------------
BYTE code tICM_HDR10_GAME[] =
{
#include "./ICM/IcmModeGame.h"
};

BYTE code tICM_HDR10_MOVIE[] =
{
#include "./ICM/IcmModeMovie.h"
};

BYTE code tICM_HDR10_PHOTO[] =
{
#include "./ICM/IcmModePhoto.h"
};

BYTE code tICM_HDR10_VIVID[] =
{
#include "./ICM/IcmModeVivid.h"
};

code BYTE *tICM_HDR10_TABLE[] =
{
    NULL,  // Standard
    tICM_HDR10_GAME,
    tICM_HDR10_MOVIE,
    tICM_HDR10_PHOTO,
    tICM_HDR10_VIVID,
};
#endif
#endif

#endif
