/********************************************************************************/
/*	The  Software  is  proprietary,  confidential,	and  valuable to Realtek   */
/*	Semiconductor  Corporation	("Realtek").  All  rights, including but not   */
/*	limited  to  copyrights,  patents,	trademarks, trade secrets, mask work   */
/*	rights, and other similar rights and interests, are reserved to Realtek.   */
/*	Without  prior	written  consent  from	Realtek,  copying, reproduction,   */
/*	modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*	Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*	disclosed to or otherwise accessed by any third party.					   */
/*	c<2003> - <2012>														   */
/*	The Software is provided "AS IS" without any warranty of any kind,		   */
/*	express, implied, statutory or otherwise.								   */
/********************************************************************************/

#if(_PANEL_TYPE == _CSOT_SG2381B084_LVDS_FHD240HZ)
//----------------------------------------------------------------------------------------------------
// ID Code	   : 44_AUO_T215HVN05_1_LVDS_60HZ.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define _PANNEL_NAME                        _P__,_a__,_n__,_e__,_l__,__,_COLON__,__,_S__,_G__,_2__,_3__,_8__,_1__,_B__,_0__,_4__,_SLINE__,_3__

//////////////////
// General Info //
//////////////////
#define _PANEL_PRESET_MODE_FRAME_RATE            2400//1650

//--------------------------------------------------
// Definitions for Panel Style
//--------------------------------------------------
#define _PANEL_STYLE                            _PANEL_LVDS

//--------------------------------------------------
// Definitions for LVDS Panel Configuration
//--------------------------------------------------
#define _LVDS_OUTPUT_PORT                       _LVDS_4_PORT
#define _LVDS_PANEL_SECTION                     _LVDS_PANEL_1_SECTION
#define _LVDS_TABLE_TYPE                        _LVDS_BIT_MAP_TABLE_1_3
#define _LVDS_CABLE_TYPE                        _LVDS_CABLE_TYPE_0

//--------------------------------------------------
// Definitions for MultiPanel Support
//--------------------------------------------------
#define _PANEL_EXIST_MULTIPANEL                 _OFF

//--------------------------------------------------
// Definitions for Panel Manufacturer
//--------------------------------------------------
#define _PANEL_MANUFACTURER                     _PANEL_SAMSUNG

//--------------------------------------------------
// Definitions for Panel Display Color Depth
//--------------------------------------------------
#define _PANEL_DISP_BIT_MODE                    _PANEL_DISP_24_BIT

#define _PANEL_PIXEL_TYPE                       _PANEL_PIXEL_LCD


#define _PANEL_TYP_FRAME_RATE                   600
#define _PANEL_MAX_FRAME_RATE           	    2400
#define _PANEL_MIN_FRAME_RATE                   480


#if(_FREESYNC_SUPPORT == _ON)
   //--------------------------------------------------
   // FREESYNC Maximum Panel Frame Rate (Unit: 0.1 Hz)
   //--------------------------------------------------
#define _PANEL_FREESYNC_MAX_FRAME_RATE          2400
#define _PANEL_FREESYNC_MIN_FRAME_RATE          480

#endif


///////////////
// Parameter //
///////////////
#define _PANEL_DH_START                         48                  // Display Horizontal Start Position
#define _PANEL_DH_WIDTH                         1920                // Display Horizontal Width
#define _PANEL_DH_END                           1968                // Display Horizontal End Position

#define _PANEL_DH_TOTAL                         2080//2120                // Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MAX          			4080//3000                // Maxinum Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MIN                     2040//1968//2000                // Mininum Display Horizontal Total Clock Number in One Display Line

#define _PANEL_DV_START                         6                   // Display Vertical Start Position
#define _PANEL_DV_HEIGHT                        1080                // Display Vertical Width
#define _PANEL_DV_END                           1086                // Display Vertical End Position

#define _PANEL_DV_TOTAL                        1100// 1110                // Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MAX           			6000//4584//4520               // Maxinum Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MIN                    1098// 1098                // Mininum Display Vertical Total Clock Number in One Display Line

#define _PANEL_DH_SYNC_WIDTH                    8                   // Display Horizontal Sync Width
#define _PANEL_DV_SYNC_HEIGHT                   2                   // Display Vertical Sync Height

#define _PANEL_PIXEL_CLOCK                      136//141                 // Typical Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MAX        		    600//480//450                // Maxinum Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MIN             		108//114               // Mininum Pixel Clock in MHz


#define _PANEL_POWER_ON_T1                      30                  // Panel Power On T1 (ms)
#define _PANEL_POWER_ON_T2                      10                  // Panel Power On T2 (ms)
#define _PANEL_POWER_ON_T3                      550                // Panel Power On T3 (ms)

#define _PANEL_POWER_OFF_T4                     120                // Panel Power Off T4 (ms)
#define _PANEL_POWER_OFF_T5                     20                  // Panel Power Off T5 (ms)
#define _PANEL_POWER_OFF_T6                     1050                // Panel Power Off T6 (ms)

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
// Definitions for Panel DCLK Unit
//--------------------------------------------------
#define _PANEL_PIXEL_CLOCK_UNIT                 _PANEL_CLOCK_MHZ

//--------------------------------------------------
// Definitions for video compensation
//-------------------------------------------------
#define BYPASS_VIDEO_COMPENSATION(Vin, Vout)    ((Vin) == ((Vout) >> 1))


////////////////////
// VGA Auto Color //
////////////////////

//--------------------------------------------------
// Definitions for ADC Gain/Offset Adjust
//--------------------------------------------------
#define _PANEL_ADC_OFFSET_BIAS                  (0)
#define _PANEL_ADC_GAIN_BIAS                    (0)


///////////////////////////
// Color Characteristics //
///////////////////////////

//--------------------------------------------------
// Definitions for Display HDR
//--------------------------------------------------
#define _PANEL_MAX_LUMINANCE                    0x62 // from OGC Tool
#define _PANEL_MAX_FRAME_AVERAGE_LUMINANCE      0x62 // from OGC Tool


/////////////////////////
// Color Default Table //
/////////////////////////

//--------------------------------------------------
// Color Default Value
//--------------------------------------------------
#include "./RTDColorDefaultTable/ColorTableInclude.h"

#endif // End of #if(_PANEL_TYPE == _AUO_T215HVN05_1_LVDS_60HZ)

