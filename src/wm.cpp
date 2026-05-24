#include "T8ForceNotations.hpp"

size_t nm = NOTATION_MAX;

void wm_create(HWND &hwnd, AppState &app) {
    int CB_W = 100, CB2_W = 80, CB3_W = 48;
    int CB_H = 200, CB2_H = 80, CB3_H = 300;

    int BTN_W = 180, BTN2_W = CB2_W; //BTN3_W = CB2_W;
    int BTN_H = 40,  BTN2_H = BTN_H; //BTN3_H = BTN_H*.5;

    int PMB1_W = BTN_W, PMB2_W = BTN2_W;
    int PMB1_H = 25,    PMB2_H = 25;

    short build_x   = WINDOW_WIDTH*.85,  build_pmb_x = build_x;
    short build_y   = WINDOW_HEIGHT*.85, build_pmb_y = build_y + BTN2_H+5;

    short preset_x  = WINDOW_WIDTH*.3;
    short preset_y  = WINDOW_HEIGHT*.85;

    short verify_x     = WINDOW_WIDTH*.05, verify_pmb_x = verify_x;
    short verify_y     = WINDOW_HEIGHT*.85, verify_pmb_y = verify_y + BTN_H+5;

    app.buildBtn = Button(hwnd,ID_BUILD, "Build",            build_x,  build_y,  BTN2_W,  BTN2_H);
    app.buildBar = ProgressBar(hwnd,ID_BUILD_PMB,build_pmb_x,build_pmb_y,PMB2_W,PMB2_H);
    app.buildCb  = ComboBox(hwnd,ID_BUILD_CB,build_x-150,build_y,CB2_W,CB2_H);

    app.presetCb  = ComboBox(hwnd,ID_PRESET_CB,            preset_x,           preset_y, BTN_W,   CB_H);
    app.clearBtn  = Button(hwnd,ID_CLEAR, "Clear",         preset_x,           preset_y+30,      BTN_W*0.5, BTN_H);
    app.presetBtn = Button(hwnd,ID_PRESET,"Apply Preset",  preset_x+BTN_W*0.5, preset_y+30,      BTN_W*0.5,  BTN_H);


    app.verifyBtn = Button(hwnd,ID_VERIFY,"Verify Integrity", verify_x, verify_y, BTN_W,   BTN_H);
    app.verifyBar = ProgressBar(hwnd,ID_VERIFY_PMB,verify_pmb_x,verify_pmb_y,PMB1_W,PMB1_H);

    app.background = Bitmap(BMP_BACKGROUND,0,0);

    int xColPad1 = 425;
    int xColPad2 = 150;
    int xCol1 = 184;
    int xCol2 = xCol1 + xColPad2;
    int xCol3 = xCol1 + xColPad1;
    int xCol4 = xCol3 + xColPad2;
    int yTop = 36;

    int y = yTop;
    int yRow = 45;

    for (int s = 0; s < BIND_MAX; ++s) {
        if (s < 12)
        {
                 if (s == 4) y = yTop + (yRow*6); // UI shuffled AB<->XY order
            else if (s == 5) y = yTop + (yRow*7);
            else if (s == 6) y = yTop + (yRow*4);
            else if (s == 7) y = yTop + (yRow*5);
            else if (s == 8) y = yTop + (yRow*8);

            app.P1[s] = ComboBox(hwnd,ID_CB1_24+s,xCol1,y,CB_W,CB_H);
        }
        else
        {
            app.P1[s] = ComboBox(hwnd,ID_CB1_24+s,xCol3,y,CB_W,CB_H);
        }
        y += yRow;
        if (s == 11) y = yTop;
        app.P1[s].resetCursor();
    }
    y = 32;
    for (int s = 0; s < BIND_MAX; ++s) {
        if (s < 12)
        {
                 if (s == 4) y = yTop + (yRow*6); // UI shuffled AB<->XY order
            else if (s == 5) y = yTop + (yRow*7);
            else if (s == 6) y = yTop + (yRow*4);
            else if (s == 7) y = yTop + (yRow*5);
            else if (s == 8) y = yTop + (yRow*8);

            app.notations[s] = ComboBox(hwnd,ID_CB2_24,xCol2,y,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS);
        }
        else
        {
            app.notations[s] = ComboBox(hwnd,ID_CB2_24,xCol4,y,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS);
        }
        app.notations[s].resetCursor();
        y += yRow;
        if (s == 11) y = yTop;
    }
}

void wm_paint(HWND &hwnd, AppState &app) {
    std::cout << "WM_PAINT" << std::endl;
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    if (hdc == 0)
        return;
    app.background.paint(hdc);

    EndPaint(hwnd, &ps);
}

void wm_app1(HWND &, AppState &app)
{
    std::vector<const char *> name = get_cmd();
    std::vector<const char *> bmp = get_paths();

    if (nm > bmp.size())
        nm = bmp.size();
    for (size_t s = 0; s < nm; ++s) { // IF NOTATION_MAX < bmp.size() we segfualt ig
        app.bmpNotations[s].load(bmp[s], NOTATION_W,NOTATION_H);
    }

    for (size_t s = 0; s < BIND_MAX; ++s) {
        // app.P1[s].setFont(24);
        for (auto n : name) {
            app.P1[s].addContent(n);
        }
        for (auto b : bmp) {
            app.notations[s].addContent(b);
        }
    }

    app.buildCb.addContent("Player1");
    app.buildCb.addContent("Player2");

    app.presetCb.addContent("Keyboard Settings 1");
    app.presetCb.addContent("Keyboard Settings 2");
    app.presetCb.addContent("Navigation Cluster");
    app.presetCb.addContent("Invisible");

    // std::cout << SendMessageA(app.presetCb.cb, CB_GETCURSEL,0,0) << std::endl;
}

void wm_command(HWND &hwnd, WPARAM wParam, AppState &app) {
    std::cout << "WM_COMMAND LOWORD==" << LOWORD(wParam) << std::endl;

    if (LOWORD(wParam) != ID_BUILD) app.buildBar.reset();

    if (LOWORD(wParam) == ID_BUILD)
        {
            KBL_build(hwnd,app);
        }
        else if (LOWORD(wParam) == ID_CLEAR)
        {
            for (int s = 0; s < BIND_MAX; ++s) {
                app.P1[s].resetCursor();
                app.notations[s].resetCursor();
            }
            app.buildCb.resetCursor();
        }
        else if (LOWORD(wParam) == ID_PRESET)
        {
            preset(app, app.presetCb.getCursor());
        }
        else if (LOWORD(wParam) == ID_VERIFY)
        {
            // VerifyIntegrity();
            StartVerify(hwnd,app);
        }
        else if (LOWORD(wParam) >= ID_CB1_24 && LOWORD(wParam) <= ID_CB2_24 + 24)
        {
            app.buildBar.reset();
        }
}

int wm_drawitem(HWND &, WPARAM, LPARAM lParam, AppState &app) {
    LPDRAWITEMSTRUCT dis = (LPDRAWITEMSTRUCT)lParam;
    static int delme = 0; std::cout << "WM_DRAWITEM " << delme++ << "\t" << dis->itemID << std::endl;


    for (size_t s = 0; s < nm; ++s) {
        if (dis->itemID == s) {
            app.bmpNotations[s].draw(dis);
            break;
        }
    }

    return 1;
}

int wm_measureitem(HWND &, WPARAM, LPARAM lParam, AppState&) {
    std::cout << "WM_MEASUREITEM" << std::endl;
    LPMEASUREITEMSTRUCT mis = (LPMEASUREITEMSTRUCT)lParam;
    mis->itemWidth  = NOTATION_W;
    mis->itemHeight = NOTATION_H;
    return TRUE;
}

void wm_destroy(int nExitCode) {
    std::cout << "WM_DESTROY" << std::endl;
    PostQuitMessage(nExitCode);
}