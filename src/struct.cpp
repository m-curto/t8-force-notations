#include "T8ForceNotations.hpp"

std::vector<const char *> get_cmd() {
    return {"- -","0","1","2","3","4","5","6","7","8","9","Space","Ctrl.",".Ctrl",".Shift","Shift.","Insert","Home","PageUp","Delete","End","PageDown","ArrowUp","ArrowLeft","ArrowRight","ArrowDown","NumPad 0","NumPad 1","NumPad 2","NumPad 3","NumPad 4","NumPad 5","NumPad 6","NumPad 7","NumPad 8","NumPad 9","NumPad /","NumPad *","NumPad -","NumPad +","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","-","^","¥","@","[","]",";",":",",",".","/","\\","=","`",")","$","Ù","*","!","ß","'","Ü","+","Ö","Ä","Ì","È","Ò","À","i","Ñ","Ç","~","¿","<","ظ","ฟ","²","#","o̲","}","|","{","Ж","б","ю","ë","x","ъ","Э","ك","TODO","TODO","TODO","TODO","TODO","TODO","TODO","TODO","TODO","TODO","TODO","_","TODO","TODO","TODO","TODO","\'","F1","F2","F3","F4","F5","F6","F7","F8","F9","F10","F11","F12","tab",".Alt","Alt.","CapsLock","ScrollLock"};
}

const std::array<std::pair<fs::path,const char *>, PAKS_MAX> get_paths() {

    std::array<std::pair<fs::path,const char *>, PAKS_MAX> arr{};

    arr[NONE] =                 { "", "resources/none.bmp" };
    arr[NUM_1] =                { fs::path(PAKS_FOLDER) / NUM_FOLDER / ONE_FOLDER,   "resources/1234/1234_1.bmp" };
    arr[NUM_2] =                { fs::path(PAKS_FOLDER) / NUM_FOLDER / TWO_FOLDER,   "resources/1234/1234_2.bmp" };
    arr[NUM_3] =                { fs::path(PAKS_FOLDER) / NUM_FOLDER / THREE_FOLDER, "resources/1234/1234_3.bmp" };
    arr[NUM_4] =                { fs::path(PAKS_FOLDER) / NUM_FOLDER / FOUR_FOLDER,  "resources/1234/1234_4.bmp" };
    arr[NUM_DARK_1] =           { fs::path(PAKS_FOLDER) / NUMD_FOLDER / ONE_FOLDER,   "resources/1234_dark/1234_dark_1.bmp" };
    arr[NUM_DARK_2] =           { fs::path(PAKS_FOLDER) / NUMD_FOLDER / TWO_FOLDER,   "resources/1234_dark/1234_dark_2.bmp" };
    arr[NUM_DARK_3] =           { fs::path(PAKS_FOLDER) / NUMD_FOLDER / THREE_FOLDER, "resources/1234_dark/1234_dark_3.bmp" };
    arr[NUM_DARK_4] =           { fs::path(PAKS_FOLDER) / NUMD_FOLDER / FOUR_FOLDER,  "resources/1234_dark/1234_dark_4.bmp" };
    arr[NUM_VERTICAL_1] =       { fs::path(PAKS_FOLDER) / NUMV_FOLDER / ONE_FOLDER,     "resources/1234_vertical/1234_vertical_1.bmp" };
    arr[NUM_VERTICAL_2] =       { fs::path(PAKS_FOLDER) / NUMV_FOLDER / TWO_FOLDER,     "resources/1234_vertical/1234_vertical_2.bmp" };
    arr[NUM_VERTICAL_3] =       { fs::path(PAKS_FOLDER) / NUMV_FOLDER / THREE_FOLDER,   "resources/1234_vertical/1234_vertical_3.bmp" };
    arr[NUM_VERTICAL_4] =       { fs::path(PAKS_FOLDER) / NUMV_FOLDER / FOUR_FOLDER,    "resources/1234_vertical/1234_vertical_4.bmp" };
    arr[NUM_VERTICAL_DARK_1] =  { fs::path(PAKS_FOLDER) / NUMVD_FOLDER / ONE_FOLDER,      "resources/1234_vertical_dark/1234_vertical_dark_1.bmp" };
    arr[NUM_VERTICAL_DARK_2] =  { fs::path(PAKS_FOLDER) / NUMVD_FOLDER / TWO_FOLDER,      "resources/1234_vertical_dark/1234_vertical_dark_2.bmp" };
    arr[NUM_VERTICAL_DARK_3] =  { fs::path(PAKS_FOLDER) / NUMVD_FOLDER / THREE_FOLDER,    "resources/1234_vertical_dark/1234_vertical_dark_3.bmp" };
    arr[NUM_VERTICAL_DARK_4] =  { fs::path(PAKS_FOLDER) / NUMVD_FOLDER / FOUR_FOLDER,     "resources/1234_vertical_dark/1234_vertical_dark_4.bmp" };
    arr[ARTS_CROUCHING] =       { fs::path(PAKS_FOLDER) / ARTS_FOLDER / ARTS_CROUCHING_FOLDER,  "resources/CMN_Arts/CMN_Arts_Crouching.bmp" };
    arr[ARTS_FLOORBREAK] =      { fs::path(PAKS_FOLDER) / ARTS_FOLDER / ARTS_FLOORBREAK_FOLDER, "resources/CMN_Arts/CMN_Arts_FloorBreak.bmp" };
    arr[ARTS_GAUGE] =           { fs::path(PAKS_FOLDER) / ARTS_FOLDER / ARTS_GAUGE_FOLDER,      "resources/CMN_Arts/CMN_Arts_Gauge.bmp" };
    arr[ARTS_HOMING] =          { fs::path(PAKS_FOLDER) / ARTS_FOLDER / ARTS_HOMING_FOLDER,     "resources/CMN_Arts/CMN_Arts_Homing.bmp" };
    arr[ARTS_POWERCRASH] =      { fs::path(PAKS_FOLDER) / ARTS_FOLDER / ARTS_POWERCRASH_FOLDER, "resources/CMN_Arts/CMN_Arts_PowerCrash.bmp" };
    arr[ARTS_TORNADE] =         { fs::path(PAKS_FOLDER) / ARTS_FOLDER / ARTS_TORNADE_FOLDER,    "resources/CMN_Arts/CMN_Arts_Tornade.bmp" };
    arr[ARTS_WALLBREAK] =       { fs::path(PAKS_FOLDER) / ARTS_FOLDER / ARTS_WALLBREAK_FOLDER,  "resources/CMN_Arts/CMN_Arts_WallBreak.bmp" };
    arr[ARTS_ZONE] =            { fs::path(PAKS_FOLDER) / ARTS_FOLDER / ARTS_ZONE_FOLDER,       "resources/CMN_Arts/CMN_Arts_Zone.bmp" };
    arr[ASSIST] =               { fs::path(PAKS_FOLDER) / CMN_FOLDER / CMN_ASSIST_FOLDER,   "resources/cmn/ASSIST.bmp" };
    arr[BLANK] =                { fs::path(PAKS_FOLDER) / CMN_FOLDER / CMN_BLANK_FOLDER,    "resources/cmn/BLANK.bmp" };
    arr[NOSELECT] =             { fs::path(PAKS_FOLDER) / CMN_FOLDER / CMN_NOSELECT_FOLDER, "resources/cmn/NOSELECT.bmp" };
    arr[RAGE] =                 { fs::path(PAKS_FOLDER) / CMN_FOLDER / CMN_RAGE_FOLDER,     "resources/cmn/RAGE.bmp" };
    arr[ZONE] =                 { fs::path(PAKS_FOLDER) / CMN_FOLDER / CMN_ZONE_FOLDER,     "resources/cmn/ZONE.bmp" };
    arr[DEFAULT_1] =            { fs::path(PAKS_FOLDER) / DEF_FOLDER / ONE_FOLDER,      "resources/default/default_1.bmp" };
    arr[DEFAULT_2] =            { fs::path(PAKS_FOLDER) / DEF_FOLDER / TWO_FOLDER,      "resources/default/default_2.bmp" };
    arr[DEFAULT_3] =            { fs::path(PAKS_FOLDER) / DEF_FOLDER / THREE_FOLDER,    "resources/default/default_3.bmp" };
    arr[DEFAULT_4] =            { fs::path(PAKS_FOLDER) / DEF_FOLDER / FOUR_FOLDER,     "resources/default/default_4.bmp" };
    arr[DEFAULT_DARK_1] =       { fs::path(PAKS_FOLDER) / DEFD_FOLDER / ONE_FOLDER,      "resources/default_dark/default_dark_1.bmp" };
    arr[DEFAULT_DARK_2] =       { fs::path(PAKS_FOLDER) / DEFD_FOLDER / TWO_FOLDER,      "resources/default_dark/default_dark_2.bmp" };
    arr[DEFAULT_DARK_3] =       { fs::path(PAKS_FOLDER) / DEFD_FOLDER / THREE_FOLDER,    "resources/default_dark/default_dark_3.bmp" };
    arr[DEFAULT_DARK_4] =       { fs::path(PAKS_FOLDER) / DEFD_FOLDER / FOUR_FOLDER,     "resources/default_dark/default_dark_4.bmp" };

    arr[PLAYSTATION_1] = { fs::path(PAKS_FOLDER) / PS_FOLDER / ONE_FOLDER,      "resources/playstation/playstation_1.bmp" };
    arr[PLAYSTATION_2] = { fs::path(PAKS_FOLDER) / PS_FOLDER / TWO_FOLDER,      "resources/playstation/playstation_2.bmp" };
    arr[PLAYSTATION_3] = { fs::path(PAKS_FOLDER) / PS_FOLDER / THREE_FOLDER,    "resources/playstation/playstation_3.bmp" };
    arr[PLAYSTATION_4] = { fs::path(PAKS_FOLDER) / PS_FOLDER / FOUR_FOLDER,     "resources/playstation/playstation_4.bmp" };
    arr[PLAYSTATION_DARK_1] = { fs::path(PAKS_FOLDER) / PSD_FOLDER / ONE_FOLDER,    "resources/playstation_dark/playstation_dark_1.bmp" };
    arr[PLAYSTATION_DARK_2] = { fs::path(PAKS_FOLDER) / PSD_FOLDER / TWO_FOLDER,    "resources/playstation_dark/playstation_dark_2.bmp" };
    arr[PLAYSTATION_DARK_3] = { fs::path(PAKS_FOLDER) / PSD_FOLDER / THREE_FOLDER,  "resources/playstation_dark/playstation_dark_3.bmp" };
    arr[PLAYSTATION_DARK_4] = { fs::path(PAKS_FOLDER) / PSD_FOLDER / FOUR_FOLDER,   "resources/playstation_dark/playstation_dark_4.bmp" };
    arr[PLAYSTATION_VERTICAL_1] = { fs::path(PAKS_FOLDER) / PSV_FOLDER / ONE_FOLDER,    "resources/playstation_vertical/playstation_vertical_1.bmp" };
    arr[PLAYSTATION_VERTICAL_2] = { fs::path(PAKS_FOLDER) / PSV_FOLDER / TWO_FOLDER,    "resources/playstation_vertical/playstation_vertical_2.bmp" };
    arr[PLAYSTATION_VERTICAL_3] = { fs::path(PAKS_FOLDER) / PSV_FOLDER / THREE_FOLDER,  "resources/playstation_vertical/playstation_vertical_3.bmp" };
    arr[PLAYSTATION_VERTICAL_4] = { fs::path(PAKS_FOLDER) / PSV_FOLDER / FOUR_FOLDER,   "resources/playstation_vertical/playstation_vertical_4.bmp" };
    arr[PLAYSTATION_VERTICAL_DARK_1] = { fs::path(PAKS_FOLDER) / PSVD_FOLDER / ONE_FOLDER,      "resources/playstation_vertical_dark/playstation_vertical_dark_1.bmp" };
    arr[PLAYSTATION_VERTICAL_DARK_2] = { fs::path(PAKS_FOLDER) / PSVD_FOLDER / TWO_FOLDER,      "resources/playstation_vertical_dark/playstation_vertical_dark_2.bmp" };
    arr[PLAYSTATION_VERTICAL_DARK_3] = { fs::path(PAKS_FOLDER) / PSVD_FOLDER / THREE_FOLDER,    "resources/playstation_vertical_dark/playstation_vertical_dark_3.bmp" };
    arr[PLAYSTATION_VERTICAL_DARK_4] = { fs::path(PAKS_FOLDER) / PSVD_FOLDER / FOUR_FOLDER,     "resources/playstation_vertical_dark/playstation_vertical_dark_4.bmp" };

// arr[PS5_CIRCLE] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_CIRCLE_FOLDER,               "resources/ps5/PS5_CIRCLE.bmp"},
// arr[PS5_CREATE] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_CREATE_FOLDER,               "resources/ps5/PS5_CREATE.bmp"},
// arr[PS5_CROSS] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_CROSS_FOLDER,                 "resources/ps5/PS5_CROSS.bmp"},
// arr[PS5_DIRECTIONAL] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_DIRECTIONAL_FOLDER,     "resources/ps5/PS5_DIRECTIONAL.bmp"},
// arr[PS5_DOWN] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_DOWN_FOLDER,                   "resources/ps5/PS5_DOWN.bmp"},
// arr[PS5_L1_LINE] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_L1_LINE_FOLDER,             "resources/ps5/PS5_L1_Line.bmp"},
// arr[PS5_L1_OFF] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_L1_OFF_FOLDER,               "resources/ps5/PS5_L1_Off.bmp"},
// arr[PS5_L1_ON] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_L1_ON_FOLDER,                 "resources/ps5/PS5_L1_On.bmp"},
// arr[PS5_L2_LINE] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_L2_LINE_FOLDER,             "resources/ps5/PS5_L2_Line.bmp"},
// arr[PS5_L2_OFF] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_L2_OFF_FOLDER,               "resources/ps5/PS5_L2_Off.bmp"},
// arr[PS5_L2_ON] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_L2_ON_FOLDER,                 "resources/ps5/PS5_L2_On.bmp"},
// arr[PS5_L3] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_L3_FOLDER,                       "resources/ps5/PS5_L3.bmp"},
// arr[PS5_LEFT] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_LEFT_FOLDER,                   "resources/ps5/PS5_LEFT.bmp"},
// arr[PS5_LEFT_RIGHT] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_LEFT_RIGHT_FOLDER,       "resources/ps5/PS5_LEFT_RIGHT.bmp"},
// arr[PS5_LS] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_LS_FOLDER,                       "resources/ps5/PS5_LS.bmp"},
// arr[PS5_OPTIONS] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_OPTIONS_FOLDER,             "resources/ps5/PS5_OPTIONS.bmp"},
// arr[PS5_PS5] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_PS5_FOLDER,                     "resources/ps5/PS5_PS5.bmp"},
// arr[PS5_R1_LINE] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_R1_LINE_FOLDER,             "resources/ps5/PS5_R1_Line.bmp"},
// arr[PS5_R1_OFF] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_R1_OFF_FOLDER,               "resources/ps5/PS5_R1_Off.bmp"},
// arr[PS5_R1_ON] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_R1_ON_FOLDER,                 "resources/ps5/PS5_R1_On.bmp"},
// arr[PS5_R2_LINE] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_R2_LINE_FOLDER,             "resources/ps5/PS5_R2_Line.bmp"},
// arr[PS5_R2_OFF] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_R2_OFF_FOLDER,               "resources/ps5/PS5_R2_Off.bmp"},
// arr[PS5_R2_ON] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_R2_ON_FOLDER,                 "resources/ps5/PS5_R2_On.bmp"},
// arr[PS5_R3] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_R3_FOLDER,                       "resources/ps5/PS5_R3.bmp"},
// arr[PS5_RIGHT] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_RIGHT_FOLDER,                 "resources/ps5/PS5_RIGHT.bmp"},
// arr[PS5_RS] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_RS_FOLDER,                       "resources/ps5/PS5_RS.bmp"},
// arr[PS5_RS_X] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_RS_X_FOLDER,                   "resources/ps5/PS5_RS_X.bmp"},
// arr[PS5_RS_Y] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_RS_Y_FOLDER,                   "resources/ps5/PS5_RS_Y.bmp"},
// arr[PS5_SQUARE] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_SQUARE_FOLDER,               "resources/ps5/PS5_SQUARE.bmp"},
// arr[PS5_TOUCH] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_TOUCH_FOLDER,                 "resources/ps5/PS5_TOUCH.bmp"},
// arr[PS5_TRIANGLE] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_TRIANGLE_FOLDER,           "resources/ps5/PS5_TRIANGLE.bmp"},
// arr[PS5_UP] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_UP_FOLDER,                       "resources/ps5/PS5_UP.bmp"},
// arr[PS5_UP_DOWN] = { fs::path(PAKS_FOLDER) / PS5_FOLDER / PS5_UP_DOWN_FOLDER,             "resources/ps5/PS5_UP_DOWN.bmp"},

    arr[XBOX_1] = { fs::path(PAKS_FOLDER) / XBX_FOLDER / ONE_FOLDER,                     "resources/xbox/xbox_1.bmp" };
    arr[XBOX_2] = { fs::path(PAKS_FOLDER) / XBX_FOLDER / TWO_FOLDER,                     "resources/xbox/xbox_2.bmp" };
    arr[XBOX_3] = { fs::path(PAKS_FOLDER) / XBX_FOLDER / THREE_FOLDER,                   "resources/xbox/xbox_3.bmp" };
    arr[XBOX_4] = { fs::path(PAKS_FOLDER) / XBX_FOLDER / FOUR_FOLDER,                    "resources/xbox/xbox_4.bmp" };
    arr[XBOX_DARK_1] = { fs::path(PAKS_FOLDER) / XBXD_FOLDER / ONE_FOLDER,               "resources/xbox_dark/xbox_dark_1.bmp" };
    arr[XBOX_DARK_2] = { fs::path(PAKS_FOLDER) / XBXD_FOLDER / TWO_FOLDER,               "resources/xbox_dark/xbox_dark_2.bmp" };
    arr[XBOX_DARK_3] = { fs::path(PAKS_FOLDER) / XBXD_FOLDER / THREE_FOLDER,             "resources/xbox_dark/xbox_dark_3.bmp" };
    arr[XBOX_DARK_4] = { fs::path(PAKS_FOLDER) / XBXD_FOLDER / FOUR_FOLDER,              "resources/xbox_dark/xbox_dark_4.bmp" };
// arr[XBOX_VERTICAL_1] = { fs::path(PAKS_FOLDER) / XBXV_FOLDER / ONE_FOLDER,           "resources/xbox_vertical/xbox_vertical1.bmp" },
// arr[XBOX_VERTICAL_2] = { fs::path(PAKS_FOLDER) / XBXV_FOLDER / TWO_FOLDER,           "resources/xbox_vertical/xbox_vertical2.bmp" },
// arr[XBOX_VERTICAL_3] = { fs::path(PAKS_FOLDER) / XBXV_FOLDER / THREE_FOLDER,         "resources/xbox_vertical/xbox_vertical3.bmp" },
// arr[XBOX_VERTICAL_4] = { fs::path(PAKS_FOLDER) / XBXV_FOLDER / FOUR_FOLDER,          "resources/xbox_vertical/xbox_vertical4.bmp" },
// arr[XBOX_VERTICAL_DARK_1] = { fs::path(PAKS_FOLDER) / XBXVD_FOLDER / ONE_FOLDER,     "resources/xbox_vertical_dark/xbox_vertical_dark1.bmp" },
// arr[XBOX_VERTICAL_DARK_2] = { fs::path(PAKS_FOLDER) / XBXVD_FOLDER / TWO_FOLDER,     "resources/xbox_vertical_dark/xbox_vertical_dark2.bmp" },
// arr[XBOX_VERTICAL_DARK_3] = { fs::path(PAKS_FOLDER) / XBXVD_FOLDER / THREE_FOLDER,   "resources/xbox_vertical_dark/xbox_vertical_dark3.bmp" },
// arr[XBOX_VERTICAL_DARK_4] = { fs::path(PAKS_FOLDER) / XBXVD_FOLDER / FOUR_FOLDER,    "resources/xbox_vertical_dark/xbox_vertical_dark4.bmp" },

// arr[XSX_A] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_A",             "resources/xsx/XSX_A.bmp" },
// arr[XSX_B] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_B",             "resources/xsx/XSX_B.bmp" },
// arr[XSX_COMMON] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_COMMON",   "resources/xsx/XSX_COMMON.bmp" },
// arr[XSX_DARK_A] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_DARK_A",   "resources/xsx/XSX_DARK_A.bmp" },
// arr[XSX_DARK_B] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_DARK_B",   "resources/xsx/XSX_DARK_B.bmp" },
// arr[XSX_DARK_X] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_DARK_X",   "resources/xsx/XSX_DARK_X.bmp" },
// arr[XSX_DARK_Y] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_DARK_Y",   "resources/xsx/XSX_DARK_Y.bmp" },
// arr[XSX_DOWN] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_DOWN",       "resources/xsx/XSX_DOWN.bmp" },
// arr[XSX_L] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_L",             "resources/xsx/XSX_L.bmp" },
// arr[XSX_LB] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_LB",           "resources/xsx/XSX_LB.bmp" },
// arr[XSX_LB_Line] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_LB_Line", "resources/xsx/XSX_LB_Line.bmp" },
// arr[XSX_LB_Off] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_LB_Off",   "resources/xsx/XSX_LB_Off.bmp" },
// arr[XSX_LEFT] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_LEFT",       "resources/xsx/XSX_LEFT.bmp" },
// arr[XSX_LS] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_LS",           "resources/xsx/XSX_LS.bmp" },
// arr[XSX_LT_Line] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_LT_Line", "resources/xsx/XSX_LT_Line.bmp" },
// arr[XSX_LT_Off] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_LT_Off",   "resources/xsx/XSX_LT_Off.bmp" },
// arr[XSX_LT_On] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_LT_On",     "resources/xsx/XSX_LT_On.bmp" },
// arr[XSX_MENU] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_MENU",       "resources/xsx/XSX_MENU.bmp" },
// arr[XSX_R] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_R",             "resources/xsx/XSX_R.bmp" },
// arr[XSX_RB] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_RB",           "resources/xsx/XSX_RB.bmp" },
// arr[XSX_RB_Line] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_RB_Line", "resources/xsx/XSX_RB_Line.bmp" },
// arr[XSX_RB_Off] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_RB_Off",   "resources/xsx/XSX_RB_Off.bmp" },
// arr[XSX_RIGHT] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_RIGHT",     "resources/xsx/XSX_RIGHT.bmp" },
// arr[XSX_RS] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_RS",           "resources/xsx/XSX_RS.bmp" },
// arr[XSX_RT_Line] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_RT_Line", "resources/xsx/XSX_RT_Line.bmp" },
// arr[XSX_RT_Off] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_RT_Off",   "resources/xsx/XSX_RT_Off.bmp" },
// arr[XSX_RT_On] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_RT_On",     "resources/xsx/XSX_RT_On.bmp" },
// arr[XSX_UP] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_UP",           "resources/xsx/XSX_UP.bmp" },
// arr[XSX_VIEW] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_VIEW",       "resources/xsx/XSX_VIEW.bmp" },
// arr[XSX_X] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_X",             "resources/xsx/XSX_X.bmp" },
// arr[XSX_Y] = { fs::path(PAKS_FOLDER) / XSX_FOLDER / "XSX_Y",             "resources/xsx/XSX_Y.bmp" },
    return arr;
}
