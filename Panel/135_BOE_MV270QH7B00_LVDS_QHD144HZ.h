/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2012>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : panel.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//////////////////
// General Info //
//////////////////
#define _PANNEL_NAME                          _P__,_a__,_n__,_e__,_l__,__,_COLON__,__,_M__,_V__,_2__,_3__,_8__,_F__,_H__,_B__,_N__,_F__,_1__

//--------------------------------------------------
// Definitions for Panel Style
//--------------------------------------------------
#define _PANEL_STYLE                            _PANEL_LVDS
#define _PANEL_PIXEL_TYPE                       _PANEL_PIXEL_LCD

//--------------------------------------------------
// Definitions for LVDS Panel Configuration
//--------------------------------------------------
#define _LVDS_OUTPUT_PORT                       _LVDS_4_PORT
#define _LVDS_PANEL_SECTION                     _LVDS_PANEL_1_SECTION
#define _LVDS_TABLE_TYPE                        _LVDS_BIT_MAP_TABLE_1_3
#define _LVDS_NO_VCM_LEVEL_BEFORE_DATA          _OFF
#define _LVDS_CABLE_TYPE                        _LVDS_CABLE_TYPE_0

//--------------------------------------------------
// Definitions for MultiPanel Support
//--------------------------------------------------
#define _PANEL_EXIST_MULTIPANEL                 _OFF

//--------------------------------------------------
// Definitions for Panel Manufacturer
//--------------------------------------------------
#define _PANEL_MANUFACTURER                     _PANEL_BOE

//--------------------------------------------------
// Definitions for Panel Display Color Depth
//--------------------------------------------------
#define _PANEL_DISP_BIT_MODE                    _PANEL_DISP_24_BIT

//--------------------------------------------------
// Definitions for Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------
#define _PANEL_TYP_FRAME_RATE                   1200
#define _PANEL_MAX_FRAME_RATE                   1450
#define _PANEL_MIN_FRAME_RATE                   600

//--------------------------------------------------
// Definitions for FREESYNC Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------
#define _PANEL_FREESYNC_MAX_FRAME_RATE          1440
#define _PANEL_FREESYNC_MIN_FRAME_RATE          480



///////////////
// Parameter //
///////////////

//--------------------------------------------------
// Definitions for Panel Parameter
//--------------------------------------------------
#define _PANEL_DH_START                         48
#define _PANEL_DH_WIDTH                         2560
#define _PANEL_DH_END                           2608

#define _PANEL_DH_TOTAL                         2780
#define _PANEL_DH_TOTAL_MAX                     2800
#define _PANEL_DH_TOTAL_MIN                     2720

#define _PANEL_DV_START                         6
#define _PANEL_DV_HEIGHT                        1440
#define _PANEL_DV_END                           1446

#define _PANEL_DV_TOTAL                         1500
#define _PANEL_DV_TOTAL_MAX                     4521
#define _PANEL_DV_TOTAL_MIN                     1479

#define _PANEL_DH_SYNC_WIDTH                    8
#define _PANEL_DV_SYNC_HEIGHT                   2

#define _PANEL_PIXEL_CLOCK                      250
#define _PANEL_PIXEL_CLOCK_MAX                  610
#define _PANEL_PIXEL_CLOCK_MIN                  241

#define _PANEL_POWER_ON_T1                      100
#define _PANEL_POWER_ON_T2                      40
#define _PANEL_POWER_ON_T3                      600

#define _PANEL_POWER_OFF_T4                     120
#define _PANEL_POWER_OFF_T5                     30
#define _PANEL_POWER_OFF_T6                     1200

/////////////
// Display //
/////////////

//--------------------------------------------------
// Definitions for Last Line Finetune Target
//--------------------------------------------------
#define _LAST_LINE_TARGET                       (_PANEL_DH_TOTAL - 150)

//--------------------------------------------------
// Definitions for Frame Sync Margin (Unit: 0.1Hz)
//--------------------------------------------------
#define _FRAME_SYNC_MARGIN                      20

//--------------------------------------------------
// Definitions for video compensation
//-------------------------------------------------
#define BYPASS_VIDEO_COMPENSATION(Vin, Vout)    ((Vin) == ((Vout) >> 1))


///////////////////////////
// Color Characteristics //
///////////////////////////

//--------------------------------------------------
// Definitions for Display HDR
//--------------------------------------------------
#define _PANEL_MAX_LUMINANCE                    0x62 // from OGC Tool
#define _PANEL_MAX_FRAME_AVERAGE_LUMINANCE      0x62 // from OGC Tool
#define _PANEL_MAX_USER_DEFINE_LUMINANCE        0x62 // from OGC Tool


/////////////////////////
// Color Default Table //
/////////////////////////

//--------------------------------------------------
// Color Default Value
//--------------------------------------------------
#include "./RTDColorDefaultTable/ColorTableInclude.h"

