#ifndef T8FORCENOTATIONS_HPP
# define T8FORCENOTATIONS_HPP

# include <windows.h>
# include <sys/stat.h>
# include <iostream>
# include <filesystem>
# include <vector>
# include <array>
# include <commctrl.h>
// #pragma comment(lib, "Comctl32.lib")
// #include <thread>
// #include <FreeImage.h>

# include "define.hpp"
# include "ProgressBar.hpp"
# include "Button.hpp"
# include "ComboBox.hpp"
# include "Bitmap.hpp"

namespace fs = std::filesystem;

enum ID_LAYOUT {
    LAYOUT_KB = 0,
    LAYOUT_XSX,
};

enum ID_BACKGROUND {
    BG_KB = 0,
    BG_XSX,
    BG_PS,
};

enum ID_SLOT {
    ID_BUILD = 101,
    ID_VERIFY,
    ID_VERIFY_PMB,
    ID_COMBO1,
    ID_BUILD_CB,
    ID_BUILD_PMB,
    ID_CLEAR,
    ID_PRESET,
    ID_PRESET_KB_CB,
    ID_PRESET_XSX_CB,
    ID_LAYOUT_CB,
    ID_CONTROLLER,
};

enum KEYCODE {
    KC_NONE = 0,
    KC_0,
    KC_1,
    KC_2,
    KC_3,
    KC_4,
    KC_5,
    KC_6,
    KC_7,
    KC_8,
    KC_9,
    KC_SPACE,
    KC_RCTRL,
    KC_LCTRL,
    KC_RSHIFT,
    KC_LSHIFT,
    KC_INSERT,
    KC_HOME,
    KC_PAGEUP,
    KC_DELETE,
    KC_END,
    KC_PAGEDOWN,
    KC_ARROWUP,
    KC_ARROWLEFT,
    KC_ARROWRIGHT,
    KC_ARROWDOWN,
    KC_NUMPAD_0,
    KC_NUMPAD_1,
    KC_NUMPAD_2,
    KC_NUMPAD_3,
    KC_NUMPAD_4,
    KC_NUMPAD_5,
    KC_NUMPAD_6,
    KC_NUMPAD_7,
    KC_NUMPAD_8,
    KC_NUMPAD_9,
    KC_NUMPAD_DIVIDE,
    KC_NUMPAD_MULT,
    KC_NUMPAD_MINUS,
    KC_NUMPAD_PLUS,
    KC_A,
    KC_B,
    KC_C,
    KC_D,
    KC_E,
    KC_F,
    KC_G,
    KC_H,
    KC_I,
    KC_J,
    KC_K,
    KC_L,
    KC_M,
    KC_N,
    KC_O,
    KC_P,
    KC_Q,
    KC_R,
    KC_S,
    KC_T,
    KC_U,
    KC_V,
    KC_W,
    KC_X,
    KC_Y,
    KC_Z,
    KC_MINUS,
    KC_CIRCUMFLEX,
    KC_YEN,
    KC_AT,
    KC_OSBRACKET,
    KC_CSBRACKET,
    KC_SEMI_COLON,
    KC_COLON,
    KC_COMMA,
    KC_DOT,
    KC_SLASH,
    KC_BACKSLASH,
    KC_EQUAL,
    KC_BACKTICK,
    KC_CPARENTHESIS,
    KC_DOLLAR,
    KC_TODO1,
    KC_MULT,
    KC_EXCLAMATIONMARK,
    KC_TODO2,
    KC_TODO3,
    KC_TODO4,
    KC_TODO5,
    KC_TODO6,
    KC_TODO7,
    KC_TODO8,
    KC_TODO9,
    KC_TODO10,
    KC_TODO11,
    KC_TODO12,
    KC_TILDE,
    KC_RQUESTIONMARK,
    KC_LESS_THAN,
    KC_TODO13,
    KC_TODO14,
    KC_SQUARED,
    KC_HASHTAG,
    KC_TODO15,
    KC_CCBRACKET,
    KC_PIPE,
    KC_OCBRACKET,
    KC_TODO16,
    KC_TODO17,
    KC_TODO18,
    KC_TODO19,
    KC_LOWERX,
    KC_TODO20,
    KC_TODO21,
    KC_TODO22,
    KC_TODO23,
    KC_TODO24,
    KC_TODO25,
    KC_TODO26,
    KC_TODO27,
    KC_TODO28,
    KC_TODO29,
    KC_TODO30,
    KC_TODO31,
    KC_TODO32,
    KC_TODO33,
    KC_TODO34,
    KC_TODO35,
    KC_UNDERSCORE,
    KC_TODO36,
    KC_TODO37,
    KC_TODO38,
    KC_TODO39,
    KC_TODO40,
    KC_F1,
    KC_F2,
    KC_F3,
    KC_F4,
    KC_F5,
    KC_F6,
    KC_F7,
    KC_F8,
    KC_F9,
    KC_F10,
    KC_F11,
    KC_F12,
    KC_TAB,
    KC_RALT,
    KC_LALT,
    KC_CAPSLOCK,
    KC_SCROLLLOCK
};

enum PAKS_NOTATION {
    NONE,               // "resources/none.bmp",
    DEFAULT_1,          // "resources/default/default_1.bmp",
    DEFAULT_2,          // "resources/default/default_2.bmp",
    DEFAULT_3,          // "resources/default/default_3.bmp",
    DEFAULT_4,          // "resources/default/default_4.bmp",
    DEFAULT_DARK_1,     // "resources/default_dark/default_dark_1.bmp",
    DEFAULT_DARK_2,     // "resources/default_dark/default_dark_2.bmp",
    DEFAULT_DARK_3,     // "resources/default_dark/default_dark_3.bmp",
    DEFAULT_DARK_4,     // "resources/default_dark/default_dark_4.bmp",
    XBOX_1,             // "resources/xbox/xbox_1.bmp",
    XBOX_2,             // "resources/xbox/xbox_2.bmp",
    XBOX_3,             // "resources/xbox/xbox_3.bmp",
    XBOX_4,             // "resources/xbox/xbox_4.bmp",
    XBOX_DARK_1,        // "resources/xbox_dark/xbox_dark_1.bmp",
    XBOX_DARK_2,        // "resources/xbox_dark/xbox_dark_2.bmp",
    XBOX_DARK_3,        // "resources/xbox_dark/xbox_dark_3.bmp",
    XBOX_DARK_4,        // "resources/xbox_dark/xbox_dark_4.bmp",
    PLAYSTATION_1,      // "resources/playstation/playstation_1.bmp",
    PLAYSTATION_2,      // "resources/playstation/playstation_2.bmp",
    PLAYSTATION_3,      // "resources/playstation/playstation_3.bmp",
    PLAYSTATION_4,      // "resources/playstation/playstation_4.bmp",
    PLAYSTATION_DARK_1, // "resources/playstation_dark/playstation_dark_1.bmp",
    PLAYSTATION_DARK_2, // "resources/playstation_dark/playstation_dark_2.bmp",
    PLAYSTATION_DARK_3, // "resources/playstation_dark/playstation_dark_3.bmp",
    PLAYSTATION_DARK_4, // "resources/playstation_dark/playstation_dark_4.bmp",
    NUM_1,              // "resources/1234/1234_1.bmp",
    NUM_2,              // "resources/1234/1234_2.bmp",
    NUM_3,              // "resources/1234/1234_3.bmp",
    NUM_4,              // "resources/1234/1234_4.bmp",
    NUM_DARK_1,         // "resources/1234_dark/1234_dark_1.bmp",
    NUM_DARK_2,         // "resources/1234_dark/1234_dark_2.bmp",
    NUM_DARK_3,         // "resources/1234_dark/1234_dark_3.bmp",
    NUM_DARK_4,         // "resources/1234_dark/1234_dark_4.bmp",

    PLAYSTATION_VERTICAL_1,    // "resources/playstation_vertical/playstation_vertical_1.bmp",
    PLAYSTATION_VERTICAL_2,    // "resources/playstation_vertical/playstation_vertical_2.bmp",
    PLAYSTATION_VERTICAL_3,    // "resources/playstation_vertical/playstation_vertical_3.bmp",
    PLAYSTATION_VERTICAL_4,    // "resources/playstation_vertical/playstation_vertical_4.bmp",
    PLAYSTATION_VERTICAL_DARK_1,    // "resources/playstation_vertical_dark/playstation_vertical_dark_1.bmp",
    PLAYSTATION_VERTICAL_DARK_2,    // "resources/playstation_vertical_dark/playstation_vertical_dark_2.bmp",
    PLAYSTATION_VERTICAL_DARK_3,    // "resources/playstation_vertical_dark/playstation_vertical_dark_3.bmp",
    PLAYSTATION_VERTICAL_DARK_4,    // "resources/playstation_vertical_dark/playstation_vertical_dark_4.bmp",
    NUM_VERTICAL_1,            // "resources/1234_vertical/1234_vertical_1.bmp",
    NUM_VERTICAL_2,            // "resources/1234_vertical/1234_vertical_2.bmp",
    NUM_VERTICAL_3,            // "resources/1234_vertical/1234_vertical_3.bmp",
    NUM_VERTICAL_4,            // "resources/1234_vertical/1234_vertical_4.bmp",
    NUM_VERTICAL_DARK_1,            // "resources/1234_vertical_dark/1234_vertical_dark_1.bmp",
    NUM_VERTICAL_DARK_2,            // "resources/1234_vertical_dark/1234_vertical_dark_2.bmp",
    NUM_VERTICAL_DARK_3,            // "resources/1234_vertical_dark/1234_vertical_dark_3.bmp",
    NUM_VERTICAL_DARK_4,            // "resources/1234_vertical_dark/1234_vertical_dark_4.bmp",

    ARTS_CROUCHING,     // "resources/CMN_Arts/CMN_Arts_Crouching.bmp"
    ARTS_FLOORBREAK,    // "resources/CMN_Arts/CMN_Arts_FloorBreak.bmp"
    ARTS_GAUGE,         // "resources/CMN_Arts/CMN_Arts_Gauge.bmp"
    ARTS_HOMING,        // "resources/CMN_Arts/CMN_Arts_Homing.bmp"
    ARTS_POWERCRASH,    // "resources/CMN_Arts/CMN_Arts_PowerCrash.bmp"
    ARTS_TORNADE,       // "resources/CMN_Arts/CMN_Arts_Tornade.bmp"
    ARTS_WALLBREAK,     // "resources/CMN_Arts/CMN_Arts_WallBreak.bmp"
    ARTS_ZONE,          // "resources/CMN_Arts/CMN_Arts_Zone.bmp"

    ASSIST,             // "resources/cmn/ASSIST.bmp",
    BLANK,              // "resources/cmn/BLANK.bmp",
    NOSELECT,           // "resources/cmn/NOSELECT.bmp",
    RAGE,               // "resources/cmn/RAGE.bmp",
    ZONE,               // "resources/cmn/ZONE.bmp",

    // XSX_A,                  // "resources/xsx/XSX_A.bmp",
    // XSX_B,                  // "resources/xsx/XSX_B.bmp",
    // XSX_COMMON,             // "resources/xsx/XSX_COMMON.bmp",
    // XSX_DIRECTIONAL,        // "resources/xsx/XSX_DIRECTIONAL.bmp",
    // XSX_DOWN,               // "resources/xsx/XSX_DOWN.bmp",
    // XSX_L,                  // "resources/xsx/XSX_L.bmp",
    // XSX_LB,                 // "resources/xsx/XSX_LB.bmp",
    // XSX_LB_LINE,            // "resources/xsx/XSX_LB_Line.bmp",
    // XSX_LB_OFF,             // "resources/xsx/XSX_LB_Off.bmp",
    // XSX_LEFT,               // "resources/xsx/XSX_LEFT.bmp",
    // XSX_LEFT_RIGHT,         // "resources/xsx/XSX_LEFT_RIGHT.bmp",
    // XSX_LS,                 // "resources/xsx/XSX_LS.bmp",
    // XSX_LT_LINE,            // "resources/xsx/XSX_LT_Line.bmp",
    // XSX_LT_OFF,             // "resources/xsx/XSX_LT_Off.bmp",
    // XSX_LT_ON,              // "resources/xsx/XSX_LT_On.bmp",
    // XSX_MENU,               // "resources/xsx/XSX_MENU.bmp",
    // XSX_R,                  // "resources/xsx/XSX_R.bmp",
    // XSX_RB,                 // "resources/xsx/XSX_RB.bmp",
    // XSX_RB_LINE,            // "resources/xsx/XSX_RB_Line.bmp",
    // XSX_RB_OFF,             // "resources/xsx/XSX_RB_Off.bmp",
    // XSX_RIGHT,              // "resources/xsx/XSX_RIGHT.bmp",
    // XSX_RS,                 // "resources/xsx/XSX_RS.bmp",
    // XSX_RS_X,               // "resources/xsx/XSX_RS_X.bmp",
    // XSX_RS_Y,               // "resources/xsx/XSX_RS_Y.bmp",
    // XSX_RT_LINE,            // "resources/xsx/XSX_RT_Line.bmp",
    // XSX_RT_OFF,             // "resources/xsx/XSX_RT_Off.bmp",
    // XSX_RT_ON,              // "resources/xsx/XSX_RT_On.bmp",
    // XSX_UP,                 // "resources/xsx/XSX_UP.bmp",
    // XSX_UP_DOWN,            // "resources/xsx/XSX_UP_DOWN.bmp",
    // XSX_VIEW,               // "resources/xsx/XSX_VIEW.bmp",
    // XSX_X,                  // "resources/xsx/XSX_X.bmp",
    // XSX_Y,                  // "resources/xsx/XSX_Y.bmp",

    // PS5_CIRCLE,         // "resources/ps5/PS5_CIRCLE.bmp",
    // PS5_CREATE,         // "resources/ps5/PS5_CREATE.bmp",
    // PS5_CROSS,          // "resources/ps5/PS5_CROSS.bmp",
    // PS5_DIRECTIONAL,    // "resources/ps5/PS5_DIRECTIONAL.bmp",
    // PS5_DOWN,           // "resources/ps5/PS5_DOWN.bmp",
    // PS5_L1_LINE,        // "resources/ps5/PS5_L1_Line.bmp",
    // PS5_L1_OFF,         // "resources/ps5/PS5_L1_Off.bmp",
    // PS5_L1_ON,          // "resources/ps5/PS5_L1_On.bmp",
    // PS5_L2_LINE,        // "resources/ps5/PS5_L2_Line.bmp",
    // PS5_L2_OFF,         // "resources/ps5/PS5_L2_Off.bmp",
    // PS5_L2_ON,          // "resources/ps5/PS5_L2_On.bmp",
    // PS5_L3,             // "resources/ps5/PS5_L3.bmp",
    // PS5_LEFT,           // "resources/ps5/PS5_LEFT.bmp",
    // PS5_LEFT_RIGHT,     // "resources/ps5/PS5_LEFT_RIGHT.bmp",
    // PS5_LS,             // "resources/ps5/PS5_LS.bmp",
    // PS5_OPTIONS,        // "resources/ps5/PS5_OPTIONS.bmp",
    // PS5_PS5,            // "resources/ps5/PS5_PS5.bmp",
    // PS5_R1_LINE,        // "resources/ps5/PS5_R1_Line.bmp",
    // PS5_R1_OFF,         // "resources/ps5/PS5_R1_Off.bmp",
    // PS5_R1_ON,          // "resources/ps5/PS5_R1_On.bmp",
    // PS5_R2_LINE,        // "resources/ps5/PS5_R2_Line.bmp",
    // PS5_R2_OFF,         // "resources/ps5/PS5_R2_Off.bmp",
    // PS5_R2_ON,          // "resources/ps5/PS5_R2_On.bmp",
    // PS5_R3,             // "resources/ps5/PS5_R3.bmp",
    // PS5_RIGHT,          // "resources/ps5/PS5_RIGHT.bmp",
    // PS5_RS,             // "resources/ps5/PS5_RS.bmp",
    // PS5_RS_X,           // "resources/ps5/PS5_RS_X.bmp",
    // PS5_RS_Y,           // "resources/ps5/PS5_RS_Y.bmp",
    // PS5_SQUARE,         // "resources/ps5/PS5_SQUARE.bmp",
    // PS5_TOUCH,          // "resources/ps5/PS5_TOUCH.bmp",
    // PS5_TRIANGLE,       // "resources/ps5/PS5_TRIANGLE.bmp",
    // PS5_UP,             // "resources/ps5/PS5_UP.bmp",
    // PS5_UP_DOWN,        // "resources/ps5/PS5_UP_DOWN.bmp",

    // CMD_01,             // "resources/cmd/CMD_01.bmp",
    // CMD_01_Dark,        // "resources/cmd/CMD_01_Dark.bmp",
    // CMD_02,             // "resources/cmd/CMD_02.bmp",
    // CMD_02_Dark,        // "resources/cmd/CMD_02_Dark.bmp",
    // CMD_03,             // "resources/cmd/CMD_03.bmp",
    // CMD_03_Dark,        // "resources/cmd/CMD_03_Dark.bmp",
    // CMD_04,             // "resources/cmd/CMD_04.bmp",
    // CMD_04_Dark,        // "resources/cmd/CMD_04_Dark.bmp",
    // CMD_05,             // "resources/cmd/CMD_05.bmp",
    // CMD_05_Dark,        // "resources/cmd/CMD_05_Dark.bmp",
    // CMD_06,             // "resources/cmd/CMD_06.bmp",
    // CMD_06_Dark,        // "resources/cmd/CMD_06_Dark.bmp",
    // CMD_07,             // "resources/cmd/CMD_07.bmp",
    // CMD_07_Dark,        // "resources/cmd/CMD_07_Dark.bmp",
    // CMD_08,             // "resources/cmd/CMD_08.bmp",
    // CMD_08_Dark,        // "resources/cmd/CMD_08_Dark.bmp",
    // CMD_09,             // "resources/cmd/CMD_09.bmp",
    // CMD_09_Dark,        // "resources/cmd/CMD_09_Dark.bmp",
    // CMD_10,             // "resources/cmd/CMD_10.bmp",
    // CMD_10_Dark,        // "resources/cmd/CMD_10_Dark.bmp",
    // CMD_11,             // "resources/cmd/CMD_11.bmp",
    // CMD_11_Dark,        // "resources/cmd/CMD_11_Dark.bmp",
    // CMD_12,             // "resources/cmd/CMD_12.bmp",
    // CMD_12_Dark,        // "resources/cmd/CMD_12_Dark.bmp",
    // CMD_13,             // "resources/cmd/CMD_13.bmp",
    // CMD_13_Dark,        // "resources/cmd/CMD_13_Dark.bmp",
    // CMD_14,             // "resources/cmd/CMD_14.bmp",
    // CMD_14_Dark,        // "resources/cmd/CMD_14_Dark.bmp",
    // CMD_15,             // "resources/cmd/CMD_15.bmp",
    // CMD_15_Dark,        // "resources/cmd/CMD_15_Dark.bmp",
    // CMD_16,             // "resources/cmd/CMD_16.bmp",
    // CMD_16_Dark,        // "resources/cmd/CMD_16_Dark.bmp",
    // CMD_17,             // "resources/cmd/CMD_17.bmp",
    // CMD_17_Dark,        // "resources/cmd/CMD_17_Dark.bmp",
    // CMD_18,             // "resources/cmd/CMD_18.bmp",
    // CMD_18_Dark,        // "resources/cmd/CMD_18_Dark.bmp",
    // CMD_35,             // "resources/cmd/CMD_35.bmp",
    // CMD_35_Dark,        // "resources/cmd/CMD_35_Dark.bmp",
    // CMD_38,             // "resources/cmd/CMD_38.bmp",
    // CMD_39,             // "resources/cmd/CMD_39.bmp",
    PAKS_MAX, //
};

struct AppState
{
    Bitmap bmpNotations[NOTATION_MAX];

    HWND verifyprogressbar;
    ComboBox KB[BIND_MAX];
    ComboBox notations[BIND_MAX];

    ComboBox XSX[XSX_MAX];

    int background_current = BG_KB;
    int layout_current = LAYOUT_KB;
    Bitmap background[BG_MAX];


    Button      buildBtn;
    ComboBox    buildCb;
    ProgressBar buildBar;

    Button      presetBtn;
    ComboBox    presetCb[PRESET_MAX];

    ComboBox    layoutCb;

    Button      verifyBtn;
    ProgressBar verifyBar;

    Button      clearBtn;

};

void wm_create(HWND&, AppState&);
void wm_paint(HWND&, AppState&);
void wm_app1(HWND&, AppState&);
void wm_command(HWND&, WPARAM, AppState&);
int wm_drawitem(HWND &, WPARAM, LPARAM, AppState&);
int wm_measureitem(HWND &, WPARAM, LPARAM lParam, AppState&);
void wm_destroy(int);

void StartVerify(HWND&, AppState&);
int  VerifyIntegrity(std::string &err, AppState&);
void ResetCursor(HWND &target);
int KB_build(HWND &hwnd, AppState &);
int XSX_build(HWND &hwnd, AppState &);

int preset(AppState &app, const int &cursor);
int layout(AppState &app, const int &layout);
int clear(AppState &app);

std::string GetComboText(HWND &);
int GetComboCursor(HWND);
const std::array<std::pair<fs::path, const char*>, PAKS_MAX> get_paths();
std::vector<const char *> get_cmd();


#endif