#include "T8ForceNotations.hpp"

size_t nm = NOTATION_MAX;

void wm_create(HWND &hwnd, AppState &app) {
    int CB_W = 100, CB2_W = 80, CB3_W = 48;
    int CB_H = 200, CB2_H = 180, CB3_H = 300;

    int BTN_W = 180, BTN2_W = CB2_W, VRF_W = 120,BTN3_W = BTN_W+5; // BTN3_W = BTN_W*.5;
    int BTN_H = 40,  BTN2_H = BTN_H, VRF_H = 40; // BTN3_H = BTN_H*.5;

    int PMB1_W = VRF_W;
    int PMB1_H = 25;

    short build_x   = WINDOW_WIDTH*.85,  build_pmb_x = build_x           , buildCb_x = build_x;
    short build_y   = WINDOW_HEIGHT*.85, build_pmb_y = build_y + BTN2_H+5, buildCb_y = build_y-30;

    short layout_x  = WINDOW_WIDTH*.2;
    short layout_y  = WINDOW_HEIGHT*.80;

    short presetCb_x  = layout_x;
    short presetCb_y  = layout_y+30;

    short clear_x  = presetCb_x;
    short clear_y  = presetCb_y+30;

    short preset_x  = clear_x + 95;
    short preset_y  = clear_y;

    // short preview_x  = WINDOW_WIDTH*.88;
    // short preview_y  = WINDOW_HEIGHT*.005;

    short verify_x = WINDOW_WIDTH*.02, verify_pmb_x = verify_x;
    short verify_y = WINDOW_HEIGHT*.80, verify_pmb_y = verify_y + BTN_H+5;

    app.buildBtn.init(hwnd,ID_BUILD, "Build",build_x,build_y,BTN2_W,BTN2_H);
    app.buildBar.init(hwnd,ID_BUILD_PMB,build_pmb_x,build_pmb_y,CB2_W,PMB1_H);
    app.buildCb.init(hwnd,ID_BUILD_CB,buildCb_x,buildCb_y,CB2_W,CB2_H,WS_VISIBLE);

    app.presetCb[LAYOUT_KB].init(hwnd,ID_PRESET_KB_CB, presetCb_x, presetCb_y, BTN3_W, CB_H, WS_VISIBLE);
    app.presetCb[LAYOUT_XSX].init(hwnd,ID_PRESET_XSX_CB, presetCb_x, presetCb_y, BTN3_W, CB_H);
    app.presetCb[LAYOUT_PS5].init(hwnd,ID_PRESET_PS5_CB, presetCb_x, presetCb_y, BTN3_W, CB_H);
    app.clearBtn.init(hwnd,ID_CLEAR, "Clear", clear_x, clear_y, BTN_W*0.5, BTN_H);
    app.presetBtn.init(hwnd,ID_PRESET,"Apply Preset", preset_x, preset_y, BTN_W*0.5,  BTN_H);

    app.layoutCb.init(hwnd,ID_LAYOUT_CB, layout_x, layout_y, BTN3_W, CB_H, WS_VISIBLE);

    app.verifyBtn.init(hwnd,ID_VERIFY,CAPTION_VERIFY_BTN, verify_x, verify_y, VRF_W, VRF_H);
    app.verifyBar.init(hwnd,ID_VERIFY_PMB,verify_pmb_x,verify_pmb_y,PMB1_W,PMB1_H);

    app.background[BG_KB].init(hwnd,BMP_BG_KB,0,0,0,0);
    app.background[BG_XSX].init(hwnd,BMP_BG_XSX,0,0,0,0);
    app.background[BG_PS5].init(hwnd,BMP_BG_PS5,0,0,0,0);
    app.background[BG_NOT].init(hwnd,BMP_BG_NOT,498,0,0,0);

    // app.previewBtn = Button(hwnd,ID_PREVIEW,"Preview", preview_x, preview_y, BTN3_W, BTN3_H);
    // app.preview = CreateWindowExW(WS_EX_TOOLWINDOW,L"STATIC",L"",WS_POPUP | WS_BORDER,0, 0, 250, 600,hwnd,NULL,GetModuleHandle(NULL),NULL);

    int xColPad1 = 265;
    int xColPad2 = 120;
    int xColPad3 = 150;
    int xColPad4 = 150;
    int xCol1 = 54;
    int xCol2 = xCol1 + xColPad2;
    int xCol3 = xCol1 + xColPad1;
    int xCol4 = xCol3 + xColPad2;
    int xCol5 = xCol4 + xColPad3;
    int xCol6 = xCol5 + xColPad4;
    int xCol7 = xCol1 + 75;
    int yTop = 36;

    int y    = yTop;
    int yXSX = yTop;
    int yPad = 4;
    int yRow = 45;

    for (int s = 0; s < PS5_MAX; ++s) {
        if (s < 12)
        {
                 if (s == 4) { y = yTop + (yRow*6); yXSX = yTop + (yRow*6); } // UI shuffled AB<->XY order
            else if (s == 5) { y = yTop + (yRow*7); yXSX = yTop + (yRow*7); }
            else if (s == 6) { y = yTop + (yRow*4); yXSX = yTop + (yRow*4); }
            else if (s == 7) { y = yTop + (yRow*5); yXSX = yTop + (yRow*5); }
            else if (s == 8) { y = yTop + (yRow*8); yXSX = yTop + (yRow*8); }

            app.KBn[s].init(hwnd,ID_CB2+s,xCol2,y-yPad,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS);
            app.KB[s].init(hwnd,ID_CB1+s,xCol1,y,CB_W,CB_H);
            app.common[s].init(hwnd,ID_CB5+s,xCol5,y-yPad,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS|WS_VISIBLE);
        }
        else if (s < BIND_MAX)
        {
            app.KBn[s].init(hwnd,ID_CB2+s,xCol4,y-yPad,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS);
            app.KB[s].init(hwnd,ID_CB1+s,xCol3,y,CB_W,CB_H);
            app.common[s].init(hwnd,ID_CB5+s,xCol6,y-yPad,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS|WS_VISIBLE);
        }
        
        if (s < 12) {
            app.XSX[s].init(hwnd,ID_CB3+s,xCol7,yXSX-yPad,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS);
            app.PS5[s].init(hwnd,ID_CB4+s,xCol7,yXSX-yPad,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS);
        }
        else if (s < BIND_MAX) { //TODO
            app.XSX[s].init(hwnd,ID_CB3+s,xCol7,yXSX-yPad,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS);
            app.PS5[s].init(hwnd,ID_CB4+s,xCol7,yXSX-yPad,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS);
        }

        y += yRow;
        yXSX += yRow;
        if (s == 11) { y = yTop; yXSX = yTop; }
        // else if (s == 10 || s == 21) yXSX = yTop;
        // app.KB[s].resetCursor();
    }

}

void wm_paint(HWND &hwnd, AppState &app) {
    std::cout << "WM_PAINT" << std::endl;
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    if (hdc == 0)
        return;
    app.background[app.background_current].paint(hdc);
    app.background[BG_NOT].paint(hdc);
    EndPaint(hwnd, &ps);
}

void wm_app1(HWND &hwnd, AppState &app)
{
    std::cout << "WM_APP1" << std::endl;
    std::vector<const char *> name = get_cmd();
    std::array<std::pair<fs::path, const char*>, PAKS_MAX> paths = get_paths();

    if (nm > paths.size())
        nm = paths.size();
    for (size_t s = 0; s < nm; ++s) { // IF NOTATION_MAX < bmp.size() we segfualt ig
        app.bmpNotations[s].load(paths[s].second, NOTATION_W,NOTATION_H);
    }

    for (size_t s = 0; s < BIND_MAX; ++s) {
        // app.KB[s].setFont(24);
        for (auto n : name) {
            app.KB[s].addContent(n);
        }
        for (auto b : paths) {
            app.KBn[s].addContent(b.second);
        }
        for (auto b : paths) {
            app.common[s].addContent(b.second);
        }
    }
    for (size_t s = 0; s < XSX_MAX; ++s) {
        for (auto b : paths) {
            app.XSX[s].addContent(b.second);
        }
    }

    app.buildCb.addContent("Player1");
    app.buildCb.addContent("Player2");

    app.presetCb[LAYOUT_KB].addContent("Keyboard Settings 1");
    app.presetCb[LAYOUT_KB].addContent("Keyboard Settings 2");
    app.presetCb[LAYOUT_KB].addContent("Navigation Cluster");
    app.presetCb[LAYOUT_KB].addContent("Invisible");
    app.presetCb[LAYOUT_KB].addContent("test");

    app.presetCb[LAYOUT_XSX].addContent("Xbox Color");
    app.presetCb[LAYOUT_XSX].addContent("PS5 Color");
    app.presetCb[LAYOUT_XSX].addContent("1234 Color");
    app.presetCb[LAYOUT_XSX].addContent("Force Xbox");
    app.presetCb[LAYOUT_XSX].addContent("Force PS5");
    app.presetCb[LAYOUT_XSX].addContent("Invisible");

    app.presetCb[LAYOUT_PS5].addContent("PS5 PRESETS");

    app.layoutCb.addContent("Keyboard");
    app.layoutCb.addContent("Controller XBOX/XSX");
    app.layoutCb.addContent("Controller PS5");

    // std::cout << SendMessageA(app.presetCb.cb, CB_GETCURSEL,0,0) << std::endl;
    layout(hwnd, app, LAYOUT_KB, 1);
}

// PostMessage(hwnd, WM_COMMAND, MAKEWPARAM(ID_XXX, 0), 0);
void wm_command(HWND &hwnd, WPARAM wParam, AppState &app) {
    std::cout << "WM_COMMAND LOWORD=" << LOWORD(wParam) << std::endl;

    if (LOWORD(wParam) != ID_BUILD)
        app.buildBar.reset();

    if (LOWORD(wParam) == ID_BUILD)
    {
        if (app.layout_current == LAYOUT_KB)
            KB_build(hwnd,app);
        else if (app.layout_current == LAYOUT_XSX)
            XSX_build(hwnd,app);
    }
    else if (LOWORD(wParam) == ID_CLEAR)
    {
        clear(app);
    }
    else if (LOWORD(wParam) == ID_PREVIEW)
    {
        // ShowWindow(app.preview,IsWindowVisible(app.preview) ? SW_HIDE : SW_SHOW);
        // if (app.background_current == BG_XSX)
        //     app.background_current = BG_KB;
        // else
        //     app.background_current = BG_XSX;
        // InvalidateRect(hwnd,NULL,0);
    }
    else if (LOWORD(wParam) == ID_PRESET)
    {
        preset(app, app.presetCb[app.layout_current].getCursor());
        // app.background_current = BG_XSX;
        // InvalidateRect(hwnd,NULL,0);
    }
    else if (LOWORD(wParam) == ID_LAYOUT_CB)
    {
        if (HIWORD(wParam) == CBN_SELCHANGE) {
            layout(hwnd, app, app.layoutCb.getCursor(), 0);
        }
    }
    else if (LOWORD(wParam) == ID_VERIFY)
    {
        // VerifyIntegrity();
        StartVerify(hwnd,app);
    }
    else if (LOWORD(wParam) >= ID_CB1 && LOWORD(wParam) <= ID_CB2 + 24)
    {
        app.buildBar.reset();
    }
    else if (LOWORD(wParam) == ID_PREVIEW)
    {
    }
}

int wm_drawitem(HWND &, WPARAM, LPARAM lParam, AppState &app) {
    LPDRAWITEMSTRUCT dis = (LPDRAWITEMSTRUCT)lParam;
    for (size_t s = 0; s < nm; ++s) {
        if (dis->itemID == s) {
            app.bmpNotations[s].draw(dis);
            break;
        }
    }
    return 1;
}

int wm_measureitem(HWND &, WPARAM, LPARAM lParam, AppState&) {
    //std::cout << "WM_MEASUREITEM" << std::endl;
    LPMEASUREITEMSTRUCT mis = (LPMEASUREITEMSTRUCT)lParam;
    mis->itemWidth  = NOTATION_W;
    mis->itemHeight = NOTATION_H;
    return TRUE;
}

void wm_destroy(int nExitCode) {
    std::cout << "WM_DESTROY" << std::endl;
    PostQuitMessage(nExitCode);
}

void wm_move(HWND &hwnd, AppState &app) {
    // std::cout << "WM_MOVE" << std::endl;
    RECT rc;
    GetWindowRect(hwnd, &rc);
    SetWindowPos(app.preview,NULL,rc.right,rc.top,250,rc.bottom - rc.top,SWP_NOZORDER);
}
