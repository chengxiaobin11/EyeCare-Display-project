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
// ID Code      : RL6463_Series_OSD_Gen_Option.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#ifndef __RL6463_OSD_GEN_OPTION__
#define __RL6463_OSD_GEN_OPTION__

//--------------------------------------------------
// OSD SRAM size
//--------------------------------------------------
#define _OSD_SRAM_SIZE                                          6912

//--------------------------------------------------
// OSD Register Gen
//--------------------------------------------------
#define _OSD_REG_MAPPING_GEN                                    _USER_OSD_GEN_2

//--------------------------------------------------
// OSD CW180
//--------------------------------------------------
#define _OSD_ROTATE_CW180_SUPPORT                               _OFF

//--------------------------------------------------
// OSD Window 5-1 ~5-8 Support
//--------------------------------------------------
#define _OSD_WINDOW_5_1_5_8_SUPPORT                             _ON

//--------------------------------------------------
// OSD Window Rouned window pattern 32x32 Support
//--------------------------------------------------
#define _OSD_WINDOW_ROUNED_PATTERN_32X32_SUPPORT                _OFF

//--------------------------------------------------
// OSD Window Chessboard Win 8/9 Support
//--------------------------------------------------
#define _OSD_WINDOW_CHESSBORAD_WIN8_WIND9_SUPPORT               _OFF

//--------------------------------------------------
// OSD Window Color palette index bit number
//--------------------------------------------------
#define _OSD_WINDOW_COLOR_PALETTE_INDEX_BIT                     (4)

//--------------------------------------------------
// OSD Align function Support
//--------------------------------------------------
#define _OSD_ALIGN_SUPPORT                                      _OFF

//--------------------------------------------------
// OSD Initial
//--------------------------------------------------
#define OSD_SET_INITIAL()                                       {\
                                                                    /* Disable align function */\
                                                                    ScalerSetBit(P3A_33_FRAME_CTRL_33, ~(_BIT6), _BIT6);\
                                                                }

#endif // End of #ifndef __RL6463_OSD_GEN_OPTION__
