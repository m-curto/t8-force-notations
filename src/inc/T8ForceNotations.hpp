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

#define BMP_BACKGROUND "resources/background3.bmp"

#define ID_BUILD            101
#define ID_VERIFY           102
#define ID_VERIFY_PMB       103
#define ID_COMBO1           104
#define ID_BUILD_CB          105
#define ID_BUILD_PMB        106
#define ID_CLEAR            107

#define ID_CB1_24            200
#define ID_CB2_24            223

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

#define BTN_W 180
#define BTN_H 40

#define BTN2_W CB2_W
#define BTN2_H BTN_H

#define BTN3_W CB2_W
#define BTN3_H BTN_H*.5

#define NOTATION_MAX 33
#define BIND_MAX 24

#define NOTATION_W 25
#define NOTATION_H 25

#define PMB1_W BTN_W // 300
#define PMB1_H 25    // 25

#define PMB2_W BTN2_W
#define PMB2_H 25

#define CB_W 100
#define CB_H 200
#define CB2_W 80
#define CB2_H 80
#define CB3_W 48
#define CB3_H 300

namespace fs = std::filesystem;

enum SLOT {
    SLOT_UP,
    SLOT_DOWN,
    SLOT_LEFT,
    SLOT_RIGHT
};

enum ID_SLOT {
    ID_UP = 101,
    ID_DOWN,
    ID_LEFT,
    ID_RIGHT
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
    HBITMAP background;
    HBITMAP bmpNotations[NOTATION_MAX];

    HWND verifyprogressbar;
    ComboBox P1[BIND_MAX];
    ComboBox notations[BIND_MAX];

    Button      buildBtn;
    ComboBox    buildCb;
    ProgressBar buildBar;

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

std::string GetComboText(HWND &);
int GetComboCursor(HWND);
const char* GetFolder(const int&);
const char* GetSubFolder(const int&);

#endif