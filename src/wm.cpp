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

    short layout_x  = WINDOW_WIDTH*.3;
    short layout_y  = WINDOW_HEIGHT*.75;

    short verify_x     = WINDOW_WIDTH*.05, verify_pmb_x = verify_x;
    short verify_y     = WINDOW_HEIGHT*.85, verify_pmb_y = verify_y + BTN_H+5;

    app.buildBtn = Button(hwnd,ID_BUILD, "Build",            build_x,  build_y,  BTN2_W,  BTN2_H);
    app.buildBar = ProgressBar(hwnd,ID_BUILD_PMB,build_pmb_x,build_pmb_y,PMB2_W,PMB2_H);
    app.buildCb  = ComboBox(hwnd,ID_BUILD_CB,build_x-150,build_y,CB2_W,CB2_H, WS_VISIBLE);

    app.presetCb[LAYOUT_KB]   = ComboBox(hwnd,ID_PRESET_KB_CB, preset_x, preset_y, BTN_W, CB_H, WS_VISIBLE);
    app.presetCb[LAYOUT_XSX]  = ComboBox(hwnd,ID_PRESET_XSX_CB, preset_x, preset_y, BTN_W, CB_H);
    app.clearBtn  = Button(hwnd,ID_CLEAR, "Clear",         preset_x,           preset_y+30, BTN_W*0.5, BTN_H);
    app.presetBtn = Button(hwnd,ID_PRESET,"Apply Preset",  preset_x+BTN_W*0.5, preset_y+30, BTN_W*0.5,  BTN_H);

    app.layoutCb  = ComboBox(hwnd,ID_LAYOUT_CB,            layout_x,           layout_y, BTN_W,   CB_H, WS_VISIBLE);

    app.verifyBtn = Button(hwnd,ID_VERIFY,"Verify Integrity", verify_x, verify_y, BTN_W,   BTN_H);
    app.verifyBar = ProgressBar(hwnd,ID_VERIFY_PMB,verify_pmb_x,verify_pmb_y,PMB1_W,PMB1_H);

    app.background[BG_KB] = Bitmap(BMP_BG_KB,0,0);
    app.background[BG_XSX] = Bitmap(BMP_BG_XSX,0,0);

    int xColPad1 = 425;
    int xColPad2 = 150;
    int xCol1 = 184;
    int xCol2 = xCol1 + xColPad2;
    int xCol3 = xCol1 + xColPad1;
    int xCol4 = xCol3 + xColPad2;
    int xCol5 = xCol1 + 75;
    int xCol6 = xCol2 + 25;
    int xCol7 = xCol3 + 75;
    int yTop = 36;

    int y    = yTop;
    int yXSX = yTop;
    int yPad = 4;
    int yRow = 45;

    for (int s = 0; s < XSX_MAX; ++s) {
        if (s < 12)
        {
                 if (s == 4) { y = yTop + (yRow*6); yXSX = yTop + (yRow*6); } // UI shuffled AB<->XY order
            else if (s == 5) { y = yTop + (yRow*7); yXSX = yTop + (yRow*7); }
            else if (s == 6) { y = yTop + (yRow*4); yXSX = yTop + (yRow*4); }
            else if (s == 7) { y = yTop + (yRow*5); yXSX = yTop + (yRow*5); }
            else if (s == 8) { y = yTop + (yRow*8); yXSX = yTop + (yRow*8); }

            app.notations[s] = ComboBox(hwnd,ID_CB2_24+s,xCol2,y-yPad,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS);
            app.KB[s] = ComboBox(hwnd,ID_CB1_24+s,xCol1,y,CB_W,CB_H);
        }
        else if (s < BIND_MAX)
        {
            app.notations[s] = ComboBox(hwnd,ID_CB2_24+s,xCol4,y,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS);
            app.KB[s] = ComboBox(hwnd,ID_CB1_24+s,xCol3,y,CB_W,CB_H);
        }
        
             if (s < 11) app.XSX[s] = ComboBox(hwnd,ID_CB3_24+s,xCol5,yXSX-yPad,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS);
        else if (s < 22) app.XSX[s] = ComboBox(hwnd,ID_CB3_24+s,xCol6,yXSX-yPad,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS);
        else             app.XSX[s] = ComboBox(hwnd,ID_CB3_24+s,xCol7,yXSX-yPad,CB3_W,CB3_H,CBS_OWNERDRAWFIXED|CBS_HASSTRINGS);

        y += yRow;
        yXSX += yRow;
        if (s == 11) y = yTop;
        else if (s == 10 || s == 21) yXSX = yTop;
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

    EndPaint(hwnd, &ps);
}

void wm_app1(HWND &, AppState &app)
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
            app.notations[s].addContent(b.second);
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

    app.layoutCb.addContent("Keyboard");
    app.layoutCb.addContent("Controller");


    // std::cout << SendMessageA(app.presetCb.cb, CB_GETCURSEL,0,0) << std::endl;
    layout(app, LAYOUT_KB);
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
    else if (LOWORD(wParam) == ID_PRESET)
    {
        preset(app, app.presetCb[app.layout_current].getCursor());
        // app.background_current = BG_XSX;
        // InvalidateRect(hwnd,NULL,0);
    }
    else if (LOWORD(wParam) == ID_LAYOUT_CB)
    {
        if (HIWORD(wParam) == CBN_SELCHANGE) {
            layout(app, app.layoutCb.getCursor());
        }
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
    else if (LOWORD(wParam) == ID_CONTROLLER)
    {
        app.background_current = BG_XSX;
        InvalidateRect(hwnd,NULL,0);
    }
}

int wm_drawitem(HWND &, WPARAM, LPARAM lParam, AppState &app) {
    LPDRAWITEMSTRUCT dis = (LPDRAWITEMSTRUCT)lParam;
    //static int delme = 0; std::cout << "WM_DRAWITEM " << delme++ << "\t" << dis->itemID << std::endl;

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