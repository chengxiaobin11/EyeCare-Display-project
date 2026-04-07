//--------------------------------------------------
// EDID Type Selection
//--------------------------------------------------
#define _A0_EDID_TYPE_SEL                               _EDID_VGA_1920_1200_60HZ


//--------------------------------------------------
// EDID Table
//--------------------------------------------------
// #if((_WRITE_EDID_TO_SYSTEM_EEPROM == _ON) || ((_A0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) && (_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)))
#if(((_WRITE_EDID_TO_SYSTEM_EEPROM == _ON)&&(_A0_INPUT_PORT_TYPE!=_A0_NO_PORT)) || ((_A0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) && (_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)) ||(_A0_INPUT_PORT_TYPE == _A0_VGA_PORT && _HDMI_24C02_SUPPORT))

BYTE code tEDID_TABLE_A0[] =
{
#if(_A0_EDID_TYPE_SEL == _EDID_VGA_1920_1200_60HZ)
#include "./EDID/EdidVga/EDID_VGA_1920x1200@60.h"
#endif
};

#endif
