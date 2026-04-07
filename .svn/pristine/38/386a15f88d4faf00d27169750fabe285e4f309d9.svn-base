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
// ID Code      : User_Panel_Option.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PANEL_EXIST_MULTIPANEL == _OFF)
#if(_PANEL_STYLE == _PANEL_LVDS)
#if(_LVDS_ULTRA_HIGH_SPEED_SUPPORT == _OFF)

#if(_PANEL_PIXEL_CLOCK_UNIT == _PANEL_CLOCK_KHZ)

#if(((_LVDS_OUTPUT_PORT == _LVDS_1_PORT) && (_PANEL_PIXEL_CLOCK_MAX > 97650)) ||\
    ((_LVDS_OUTPUT_PORT == _LVDS_2_PORT) && ((_PANEL_PIXEL_CLOCK_MAX / 2) > 97650)) ||\
    ((_LVDS_OUTPUT_PORT == _LVDS_4_PORT) && ((_PANEL_PIXEL_CLOCK_MAX / 4) > 97650)))
#undef _LVDS_ULTRA_HIGH_SPEED_SUPPORT
#define _LVDS_ULTRA_HIGH_SPEED_SUPPORT                  _ON
#endif

#elif(_PANEL_PIXEL_CLOCK_UNIT == _PANEL_CLOCK_MHZ)

#if(((_LVDS_OUTPUT_PORT == _LVDS_1_PORT) && ((_PANEL_PIXEL_CLOCK_MAX * 1000UL) > 97650)) ||\
    ((_LVDS_OUTPUT_PORT == _LVDS_2_PORT) && (((_PANEL_PIXEL_CLOCK_MAX * 1000UL) / 2) > 97650)) ||\
    ((_LVDS_OUTPUT_PORT == _LVDS_4_PORT) && (((_PANEL_PIXEL_CLOCK_MAX * 1000UL) / 4) > 97650)))
#undef _LVDS_ULTRA_HIGH_SPEED_SUPPORT
#define _LVDS_ULTRA_HIGH_SPEED_SUPPORT                  _ON
#endif

#endif

#endif
#endif
#endif
