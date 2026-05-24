#ifndef T8FORCENOTATIONS_HPP
# define T8FORCENOTATIONS_HPP

#include <windows.h>
#include <sys/stat.h>
#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <commctrl.h>
// #pragma comment(lib, "Comctl32.lib")
// #include <thread>
// #include <FreeImage.h>

# include "ProgressBar.hpp"
# include "Button.hpp"
# include "ComboBox.hpp"
# include "Bitmap.hpp"

#define BMP_BACKGROUND "resources/background3.bmp"

#define PAKS_FOLDER     "T8Paks"
#define KBL_FOLDER   "KBL"
#define P1_FOLDER   "P1"
#define P2_FOLDER   "P2"

#define WINDOW_WIDTH    846
#define WINDOW_HEIGHT   779
#define WINDOW_X        CW_USEDEFAULT
#define WINDOW_Y        CW_USEDEFAULT

#define MSG_VERIFY1 "MISSING FILE "
#define MSG_VERIFY2 "WE GOOD"

#define NOTATION_MAX 100
#define BIND_MAX 24

// #define BTN_W 180
// #define BTN_H 40

// #define BTN2_W CB2_W
// #define BTN2_H BTN_H

// #define BTN3_W CB2_W
// #define BTN3_H BTN_H*.5

#define NOTATION_W 25
#define NOTATION_H 25

// #define PMB1_W BTN_W // 300
// #define PMB1_H 25    // 25

// #define PMB2_W BTN2_W
// #define PMB2_H 25

namespace fs = std::filesystem;

enum SLOT {
    SLOT_UP,
    SLOT_DOWN,
    SLOT_LEFT,
    SLOT_RIGHT
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
    ID_PRESET_CB,
};

#define ID_CB1_24            200
#define ID_CB2_24            223

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


enum BMP_NOTATION {
    NONE,
    DEFAULT_1,
    DEFAULT_2,
    DEFAULT_3,
    DEFAULT_4,
    DEFAULT_DARK_1,
    DEFAULT_DARK_2,
    DEFAULT_DARK_3,
    DEFAULT_DARK_4,
    XBOX_1,
    XBOX_2,
    XBOX_3,
    XBOX_4,
    XBOX_DARK_1,
    XBOX_DARK_2,
    XBOX_DARK_3,
    XBOX_DARK_4,
    PLAYSTATION_1,
    PLAYSTATION_2,
    PLAYSTATION_3,
    PLAYSTATION_4,
    PLAYSTATION_DARK_1,
    PLAYSTATION_DARK_2,
    PLAYSTATION_DARK_3,
    PLAYSTATION_DARK_4,
    NUM_1,
    NUM_2,
    NUM_3,
    NUM_4,
    NUM_DARK_1,
    NUM_DARK_2,
    NUM_DARK_3,
    NUM_DARK_4,
    
};

struct AppState
{
    Bitmap bmpNotations[NOTATION_MAX];

    HWND verifyprogressbar;
    ComboBox P1[BIND_MAX];
    ComboBox notations[BIND_MAX];

    Bitmap background;


    Button      buildBtn;
    ComboBox    buildCb;
    ProgressBar buildBar;

    Button      presetBtn;
    ComboBox    presetCb;

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
int KBL_build(HWND &hwnd, AppState &);
int preset(AppState &app, const int &cursor);

std::string GetComboText(HWND &);
int GetComboCursor(HWND);
const char* GetFolder(const int&);
const char* GetSubFolder(const int&);

#endif