#include "T8ForceNotations.hpp"

std::vector<fs::path> notation_cmd = {fs::path("1"),fs::path("2"),fs::path("3"),fs::path("4")};

int VerifyIntegrity(std::string &err, AppState &app)
{
    fs::path current;// = fs::current_path();
    app.verifyBar.setTotal((149*3*4) + (4*4*2) + (2));

    std::vector<const char*> notation_folder = {PAKS_FOLDER};
    std::vector<const char*> notation_style = {"default","default_dark","xbox","xbox_dark","playstation","playstation_dark"};

    std::vector<const char*> bitmap_folder = {"resources"};

    std::vector<const char*> specific = {BMP_BG_KB, "resources/none.bmp"}; //TODO

    for (auto ns : notation_style)
    {
        for (auto nc : notation_cmd)
        {
            for (auto nf : notation_folder)
            {
                for (int i = 1; i < 150; i++)
                {
                    char pak[64], ucas[64], utoc[64];
                    sprintf(pak, "pakchunk8%03d-Windows_P.pak", i);
                    sprintf(ucas, "pakchunk8%03d-Windows_P.ucas", i);
                    sprintf(utoc, "pakchunk8%03d-Windows_P.utoc", i);
                    fs::path p_pak  = current / nf / ns / nc / pak;
                    fs::path p_ucas = current / nf / ns / nc / ucas;
                    fs::path p_utoc = current / nf / ns / nc / utoc;
                    if (!fs::exists(p_pak))  { err += p_pak.string(); return false; }
                    if (!fs::exists(p_ucas)) { err += p_pak.string(); return false; }
                    if (!fs::exists(p_utoc)) { err += p_pak.string(); return false; }
                    app.verifyBar.step();
                }
            }
        }
    }

    for (auto sf : notation_style)
    {
        for (auto f : bitmap_folder)
        {
            for (int i = 1; i < 5; i++)
            {
                char bmp[64];
                sprintf(bmp, "%s_%d.bmp", sf, i);
                fs::path p_bmp = current / f / sf / bmp;

                if (!fs::exists(p_bmp))  { err += p_bmp.string(); return false; }
                app.verifyBar.step();
            }
        }
    }

    for (auto path : specific) {
        fs::path spec = path;
        if (!fs::exists(spec)) { err += spec.string(); return false; }
        app.verifyBar.step();
    }

    SendMessage(app.verifyprogressbar, PBM_SETPOS, 100, 0);

    return 1;
}

void StartVerify(HWND &hwnd, AppState &app)
{
    // std::thread(VerifyIntegrity).detach();
    std::string err = MSG_VERIFY1;
    if (!VerifyIntegrity(err,app))
        MessageBoxA(hwnd, (LPCSTR)err.c_str(), CAPTION_VERIFY, MB_ICONERROR);
    else
        MessageBoxA(hwnd, (LPCSTR)MSG_VERIFY2, CAPTION_VERIFY, MB_OK | MB_ICONINFORMATION);
    SendMessage(app.verifyprogressbar, PBM_SETPOS, 0, 0);
    app.verifyBar.reset();

}

void ResetCursor(HWND &target) {
    SendMessageA(target, CB_SETCURSEL, 0, 0);
}

std::string GetComboText(HWND &cb)
{
    int index = SendMessageA(cb, CB_GETCURSEL, 0, 0);
    if (index == CB_ERR)
        return "";
    int len = SendMessageA(cb, CB_GETLBTEXTLEN, index, 0);
    std::string text(len, '\0');
    SendMessageA(cb, CB_GETLBTEXT, index, (LPARAM)text.data());
    return text;
}

int GetComboCursor(HWND cb)
{
    return SendMessageA(cb,CB_GETCURSEL,0,0);
}

int preset(AppState &app, const int &c) {
    
    if (app.layout_current == LAYOUT_KB)
    {
        if (c == 0) { // "Keyboard Settings 1"
            app.KB[0].setCursor(KC_W);  app.notations[0].setCursor(NONE);       app.KB[12].setCursor(KC_L);             app.notations[12].setCursor(NONE);
            app.KB[1].setCursor(KC_S);  app.notations[1].setCursor(NONE);       app.KB[13].setCursor(KC_SEMI_COLON);    app.notations[13].setCursor(NONE);
            app.KB[2].setCursor(KC_A);  app.notations[2].setCursor(NONE);       app.KB[14].setCursor(NONE);             app.notations[14].setCursor(NONE);
            app.KB[3].setCursor(KC_D);  app.notations[3].setCursor(NONE);       app.KB[15].setCursor(NONE);             app.notations[15].setCursor(NONE);
            app.KB[4].setCursor(KC_J);  app.notations[4].setCursor(DEFAULT_1);  app.KB[16].setCursor(NONE);             app.notations[16].setCursor(NONE);
            app.KB[5].setCursor(KC_K);  app.notations[5].setCursor(DEFAULT_2);  app.KB[17].setCursor(NONE);             app.notations[17].setCursor(NONE);
            app.KB[6].setCursor(KC_U);  app.notations[6].setCursor(DEFAULT_3);  app.KB[18].setCursor(NONE);             app.notations[18].setCursor(NONE);
            app.KB[7].setCursor(KC_I);  app.notations[7].setCursor(DEFAULT_4);  app.KB[19].setCursor(NONE);             app.notations[19].setCursor(NONE);
            app.KB[8].setCursor(KC_B);  app.notations[8].setCursor(NONE);       app.KB[20].setCursor(NONE);             app.notations[20].setCursor(NONE);
            app.KB[9].setCursor(KC_V);  app.notations[9].setCursor(NONE);       app.KB[21].setCursor(NONE);             app.notations[21].setCursor(NONE);
            app.KB[10].setCursor(KC_O); app.notations[10].setCursor(NONE);      app.KB[22].setCursor(KC_C);             app.notations[22].setCursor(NONE);
            app.KB[11].setCursor(KC_P); app.notations[11].setCursor(NONE);      app.KB[23].setCursor(KC_N);             app.notations[23].setCursor(NONE);
        }
        else if (c == 1) { // "Keyboard Settings 2"
            app.KB[0].setCursor(KC_ARROWUP);    app.notations[0].setCursor(NONE);       app.KB[12].setCursor(KC_NUMPAD_PLUS);   app.notations[12].setCursor(NONE);
            app.KB[1].setCursor(KC_ARROWDOWN);  app.notations[1].setCursor(NONE);       app.KB[13].setCursor(KC_NUMPAD_6);      app.notations[13].setCursor(NONE);
            app.KB[2].setCursor(KC_ARROWLEFT);  app.notations[2].setCursor(NONE);       app.KB[14].setCursor(KC_NUMPAD_PLUS);   app.notations[14].setCursor(NONE);
            app.KB[3].setCursor(KC_ARROWRIGHT); app.notations[3].setCursor(NONE);       app.KB[15].setCursor(NONE);             app.notations[15].setCursor(NONE);
            app.KB[4].setCursor(KC_NUMPAD_4);   app.notations[4].setCursor(DEFAULT_1);  app.KB[16].setCursor(NONE);             app.notations[16].setCursor(NONE);
            app.KB[5].setCursor(KC_NUMPAD_5);   app.notations[5].setCursor(DEFAULT_2);  app.KB[17].setCursor(NONE);             app.notations[17].setCursor(NONE);
            app.KB[6].setCursor(KC_NUMPAD_7);   app.notations[6].setCursor(DEFAULT_3);  app.KB[18].setCursor(NONE);             app.notations[18].setCursor(NONE);
            app.KB[7].setCursor(KC_NUMPAD_8);   app.notations[7].setCursor(DEFAULT_4);  app.KB[19].setCursor(NONE);             app.notations[19].setCursor(NONE);
            app.KB[8].setCursor(KC_HOME);       app.notations[8].setCursor(NONE);       app.KB[20].setCursor(NONE);             app.notations[20].setCursor(NONE);
            app.KB[9].setCursor(KC_INSERT);     app.notations[9].setCursor(NONE);       app.KB[21].setCursor(NONE);             app.notations[21].setCursor(NONE);
            app.KB[10].setCursor(KC_MINUS);     app.notations[10].setCursor(NONE);      app.KB[22].setCursor(KC_DELETE);        app.notations[22].setCursor(NONE);
            app.KB[11].setCursor(KC_NUMPAD_9);  app.notations[11].setCursor(NONE);      app.KB[23].setCursor(KC_END);           app.notations[23].setCursor(NONE);
        }
        else if (c == 2) { // "Navigation Cluster"
            app.KB[0].setCursor(KC_SPACE);      app.notations[0].setCursor(NONE);   app.KB[12].setCursor(KC_1);   app.notations[12].setCursor(NONE);
            app.KB[1].setCursor(KC_S);          app.notations[1].setCursor(NONE);   app.KB[13].setCursor(KC_2);   app.notations[13].setCursor(NONE);
            app.KB[2].setCursor(KC_A);          app.notations[2].setCursor(NONE);   app.KB[14].setCursor(KC_3);   app.notations[14].setCursor(NONE);
            app.KB[3].setCursor(KC_D);          app.notations[3].setCursor(NONE);   app.KB[15].setCursor(KC_4);   app.notations[15].setCursor(NONE);
            app.KB[4].setCursor(KC_DELETE);     app.notations[4].setCursor(XBOX_1); app.KB[16].setCursor(KC_5);   app.notations[16].setCursor(NONE);
            app.KB[5].setCursor(KC_END);        app.notations[5].setCursor(XBOX_2); app.KB[17].setCursor(KC_6);   app.notations[17].setCursor(NONE);
            app.KB[6].setCursor(KC_INSERT);     app.notations[6].setCursor(XBOX_3); app.KB[18].setCursor(KC_7);   app.notations[18].setCursor(NONE);
            app.KB[7].setCursor(KC_HOME);       app.notations[7].setCursor(XBOX_4); app.KB[19].setCursor(KC_8);   app.notations[19].setCursor(NONE);
            app.KB[8].setCursor(KC_CSBRACKET);  app.notations[8].setCursor(NONE);   app.KB[20].setCursor(KC_9);   app.notations[20].setCursor(NONE);
            app.KB[9].setCursor(KC_BACKSLASH);  app.notations[9].setCursor(NONE);   app.KB[21].setCursor(KC_0);   app.notations[21].setCursor(NONE);
            app.KB[10].setCursor(KC_PAGEUP);    app.notations[10].setCursor(NONE);  app.KB[22].setCursor(KC_F11); app.notations[22].setCursor(NONE);
            app.KB[11].setCursor(KC_PAGEDOWN);  app.notations[11].setCursor(NONE);  app.KB[23].setCursor(KC_F12); app.notations[23].setCursor(NONE);
        }
        else if (c == 3) { // "Invisible"
            /*app.KB[0].setCursor(KC_SPACE);     */ app.notations[0].setCursor(BLANK);   /*app.KB[12].setCursor(KC_1);*/   app.notations[12].setCursor(BLANK);
            /*app.KB[1].setCursor(KC_S);         */ app.notations[1].setCursor(BLANK);   /*app.KB[13].setCursor(KC_2);*/   app.notations[13].setCursor(BLANK);
            /*app.KB[2].setCursor(KC_A);         */ app.notations[2].setCursor(BLANK);   /*app.KB[14].setCursor(KC_3);*/   app.notations[14].setCursor(BLANK);
            /*app.KB[3].setCursor(KC_D);         */ app.notations[3].setCursor(BLANK);   /*app.KB[15].setCursor(KC_4);*/   app.notations[15].setCursor(BLANK);
            /*app.KB[4].setCursor(KC_DELETE);    */ app.notations[4].setCursor(BLANK);   /*app.KB[16].setCursor(KC_5);*/   app.notations[16].setCursor(BLANK);
            /*app.KB[5].setCursor(KC_END);       */ app.notations[5].setCursor(BLANK);   /*app.KB[17].setCursor(KC_6);*/   app.notations[17].setCursor(BLANK);
            /*app.KB[6].setCursor(KC_INSERT);    */ app.notations[6].setCursor(BLANK);   /*app.KB[18].setCursor(KC_7);*/   app.notations[18].setCursor(BLANK);
            /*app.KB[7].setCursor(KC_HOME);      */ app.notations[7].setCursor(BLANK);   /*app.KB[19].setCursor(KC_8);*/   app.notations[19].setCursor(BLANK);
            /*app.KB[8].setCursor(KC_CSBRACKET); */ app.notations[8].setCursor(BLANK);   /*app.KB[20].setCursor(KC_9);*/   app.notations[20].setCursor(BLANK);
            /*app.KB[9].setCursor(KC_BACKSLASH); */ app.notations[9].setCursor(BLANK);   /*app.KB[21].setCursor(KC_0);*/   app.notations[21].setCursor(BLANK);
            /*app.KB[10].setCursor(KC_PAGEUP);   */ app.notations[10].setCursor(BLANK);  /*app.KB[22].setCursor(KC_F11);*/ app.notations[22].setCursor(BLANK);
            /*app.KB[11].setCursor(KC_PAGEDOWN); */ app.notations[11].setCursor(BLANK);  /*app.KB[23].setCursor(KC_F12);*/ app.notations[23].setCursor(BLANK);
        }
        else if (c == 4) { // "test"
            app.KB[0].setCursor(KC_SPACE);      app.notations[0].setCursor(DEFAULT_1);              app.KB[12].setCursor(KC_1);     app.notations[12].setCursor(NOSELECT);
            app.KB[1].setCursor(KC_S);          app.notations[1].setCursor(DEFAULT_DARK_1);         app.KB[13].setCursor(KC_2);     app.notations[13].setCursor(RAGE);
            app.KB[2].setCursor(KC_A);          app.notations[2].setCursor(XBOX_1);                 app.KB[14].setCursor(KC_3);     app.notations[14].setCursor(ZONE);
            app.KB[3].setCursor(KC_D);          app.notations[3].setCursor(XBOX_DARK_1);            app.KB[15].setCursor(KC_4);     app.notations[15].setCursor(DEFAULT_4);
            app.KB[4].setCursor(KC_DELETE);     app.notations[4].setCursor(PLAYSTATION_1);          app.KB[16].setCursor(KC_5);     app.notations[16].setCursor(NONE);
            app.KB[5].setCursor(KC_END);        app.notations[5].setCursor(PLAYSTATION_DARK_1);     app.KB[17].setCursor(KC_6);     app.notations[17].setCursor(NONE);
            app.KB[6].setCursor(KC_INSERT);     app.notations[6].setCursor(NUM_1);                  app.KB[18].setCursor(KC_7);     app.notations[18].setCursor(NONE);
            app.KB[7].setCursor(KC_HOME);       app.notations[7].setCursor(NUM_DARK_1);             app.KB[19].setCursor(KC_8);     app.notations[19].setCursor(NONE);
            app.KB[8].setCursor(KC_CSBRACKET);  app.notations[8].setCursor(NUM_VERTICAL_1);         app.KB[20].setCursor(KC_9);     app.notations[20].setCursor(NONE);
            app.KB[9].setCursor(KC_BACKSLASH);  app.notations[9].setCursor(PLAYSTATION_VERTICAL_1); app.KB[21].setCursor(KC_0);     app.notations[21].setCursor(NONE);
            app.KB[10].setCursor(KC_PAGEUP);    app.notations[10].setCursor(ASSIST);                app.KB[22].setCursor(KC_F11);   app.notations[22].setCursor(NONE);
            app.KB[11].setCursor(KC_PAGEDOWN);  app.notations[11].setCursor(BLANK);                 app.KB[23].setCursor(KC_F12);   app.notations[23].setCursor(NONE);
        }
    }
    else if (app.layout_current == LAYOUT_XSX) // WIP
    {
        if (app.layout_current == LAYOUT_XSX && c == 0) { // "Xbox Color"
            app.XSX[0].setCursor(NONE);     app.XSX[11].setCursor(NONE);    app.XSX[22].setCursor(NONE);
            app.XSX[1].setCursor(NONE);     app.XSX[12].setCursor(NONE);    app.XSX[23].setCursor(NONE);
            app.XSX[2].setCursor(NONE);     app.XSX[13].setCursor(NONE);    app.XSX[24].setCursor(NONE);
            app.XSX[3].setCursor(NONE);     app.XSX[14].setCursor(NONE);    app.XSX[25].setCursor(NONE);
            app.XSX[4].setCursor(XBOX_1);   app.XSX[15].setCursor(NONE);    app.XSX[26].setCursor(NONE);
            app.XSX[5].setCursor(XBOX_2);   app.XSX[16].setCursor(NONE);    app.XSX[27].setCursor(NONE);
            app.XSX[6].setCursor(XBOX_3);   app.XSX[17].setCursor(NONE);    app.XSX[28].setCursor(NONE);
            app.XSX[7].setCursor(XBOX_4);   app.XSX[18].setCursor(NONE);    app.XSX[29].setCursor(NONE);
            app.XSX[8].setCursor(NONE);     app.XSX[19].setCursor(NONE);    app.XSX[30].setCursor(NONE);
            app.XSX[9].setCursor(NONE);     app.XSX[20].setCursor(NONE);    app.XSX[31].setCursor(NONE);
            app.XSX[10].setCursor(NONE);    app.XSX[21].setCursor(NONE);    app.XSX[32].setCursor(NONE);

        }
    }
    else
        return 0;

    return 1;
}

int layout(AppState &app, const int &layout) {
    if (layout == LAYOUT_KB) {
        for (int s = 0; s < BIND_MAX; ++s) {
            app.notations[s].window(SW_SHOW);
            app.KB[s].window(SW_SHOW);
        }
        for (int s = 0; s < XSX_MAX; ++s) {
            app.XSX[s].window(SW_HIDE);
        }
        app.presetCb[LAYOUT_KB].window(SW_SHOW);
        app.presetCb[LAYOUT_XSX].window(SW_HIDE);
    }
    else if (layout == LAYOUT_XSX) {
        for (int s = 0; s < BIND_MAX; ++s) {
            app.notations[s].window(SW_HIDE);
            app.KB[s].window(SW_HIDE);
        }
        for (int s = 0; s < XSX_MAX; ++s) {
            app.XSX[s].window(SW_SHOW);
        }
        app.presetCb[LAYOUT_KB].window(SW_HIDE);
        app.presetCb[LAYOUT_XSX].window(SW_SHOW);
    }
    else
        return 0;
    app.layout_current = layout;
    return 1;
}

int clear(AppState &app) {
    std::cout << "LAYOUT_CURRENT ==" << app.layout_current << std::endl;
    if (app.layout_current == LAYOUT_KB) {
        for (int s = 0; s < BIND_MAX; ++s) {
            app.notations[s].resetCursor();
            app.KB[s].resetCursor();
        }
    }
    else if (app.layout_current == LAYOUT_XSX) {
        for (int s = 0; s < XSX_MAX; ++s) {
            app.XSX[s].resetCursor();
        }
    }
    app.buildCb.resetCursor();

    return 1;
}

/* VerifyIntegrity() with tree T8Paks/default/1

std::vector<fs::path> notation_cmd = {fs::path("1"),fs::path("2"),fs::path("3"),fs::path("4")};

int VerifyIntegrity(std::string &err, AppState &app)
{
    fs::path current;// = fs::current_path();
    app.verifyBar.setTotal((149*3*4) + (4*4*2) + (2));

    std::vector<const char*> notation_folder = {PAKS_FOLDER};
    std::vector<const char*> notation_style = {"default","default_dark","xbox","xbox_dark","playstation","playstation_dark"};

    std::vector<const char*> bitmap_folder = {"resources"};

    std::vector<const char*> specific = {BMP_BG_KB, "resources/none.bmp"}; //TODO

    for (auto ns : notation_style)
    {
        for (auto nc : notation_cmd)
        {
            for (auto nf : notation_folder)
            {
                for (int i = 1; i < 150; i++)
                {
                    char pak[64], ucas[64], utoc[64];
                    sprintf(pak, "pakchunk8%03d-Windows_P.pak", i);
                    sprintf(ucas, "pakchunk8%03d-Windows_P.ucas", i);
                    sprintf(utoc, "pakchunk8%03d-Windows_P.utoc", i);
                    fs::path p_pak  = current / nf / ns / nc / pak;
                    fs::path p_ucas = current / nf / ns / nc / ucas;
                    fs::path p_utoc = current / nf / ns / nc / utoc;
                    if (!fs::exists(p_pak))  { err += p_pak.string(); return false; }
                    if (!fs::exists(p_ucas)) { err += p_pak.string(); return false; }
                    if (!fs::exists(p_utoc)) { err += p_pak.string(); return false; }
                    app.verifyBar.step();
                }
            }
        }
    }

    for (auto sf : notation_style)
    {
        for (auto f : bitmap_folder)
        {
            for (int i = 1; i < 5; i++)
            {
                char bmp[64];
                sprintf(bmp, "%s_%d.bmp", sf, i);
                fs::path p_bmp = current / f / sf / bmp;

                if (!fs::exists(p_bmp))  { err += p_bmp.string(); return false; }
                app.verifyBar.step();
            }
        }
    }

    for (auto path : specific) {
        fs::path spec = path;
        if (!fs::exists(spec)) { err += spec.string(); return false; }
        app.verifyBar.step();
    }

    SendMessage(app.verifyprogressbar, PBM_SETPOS, 100, 0);

    return 1;
}
*/