#include "T8ForceNotations.hpp"

std::vector<fs::path> notation_cmd = {fs::path("1"),fs::path("2"),fs::path("3"),fs::path("4")};

int VerifyIntegrity(std::string &err, AppState &app)
{
    fs::path current;// = fs::current_path();
    app.verifyBar.setTotal((149*3*4) + (4*4*2) + (2));

    std::vector<const char*> notation_folder = {PAKS_FOLDER};
    std::vector<const char*> notation_style = {"default","default_dark","xbox","xbox_dark","playstation","playstation_dark"};

    std::vector<const char*> bitmap_folder = {"resources"};

    std::vector<const char*> specific = {BMP_BACKGROUND, "resources/none.bmp"}; //TODO

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
        MessageBoxA(hwnd, (LPCSTR)err.c_str(), "Integrity Check", MB_ICONERROR);
    else
        MessageBoxA(hwnd, (LPCSTR)MSG_VERIFY2, "Integrity Check", MB_OK | MB_ICONINFORMATION);
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

int KBL_build(HWND &, AppState&app)
{
    int total = 0;
    for (int s = 0; s < BIND_MAX; ++s) {
        if (app.P1[s].getCursor() > 0 && app.notations[s].getCursor() > 0) total += 5;
    }
    app.buildBar.setTotal(total);

    fs::path current;// = fs::current_path();

    std::vector<fs::path> notation_folder = {PAKS_FOLDER};
    std::vector<fs::path> notation_style = {"default"/*,"default_dark","xbox","xbox_dark","playstation","playstation_dark"*/};
    // std::vector<fs::path> notation_cmd = {"UP","DOWN","LEFT","RIGHT","X","Y",
    //  "A","B","START","SELECT","LB","RB",
    //  "LT","RT","LS_UP","LS_DOWN","LS_LEFT","LS_RIGHT",
    //  "RS_UP","RS_DOWN","RS_LEFT","RS_RIGHT", "L3", "R3"};

    std::vector<fs::path> bitmap_folder = {"resources"};
    std::vector<fs::path> specific = {BMP_BACKGROUND, "resources/none.bmp"};

    for (int s = 0; s < BIND_MAX; ++s)
    {
        int btn = app.P1[s].getCursor();
        int cmd = app.notations[s].getCursor();

        if (btn > 0 && cmd > 0) {

            std::cout << "ONE" << std::endl;
            fs::path src = current / notation_folder[0] / fs::path(GetFolder(cmd)) / fs::path(GetSubFolder(cmd));
            fs::path dst = current / fs::path(KBL_FOLDER) / (app.buildCb.getCursor() == 0 ? fs::path(P1_FOLDER) : fs::path(P2_FOLDER)) / fs::path(GetSubFolder(cmd));
            std::cout << "TWO" << std::endl;

            char pak[64], ucas[64], utoc[64];
            sprintf(pak,  "pakchunk8%03d-Windows_P.pak", btn);
            sprintf(ucas, "pakchunk8%03d-Windows_P.ucas", btn);
            sprintf(utoc, "pakchunk8%03d-Windows_P.utoc", btn);

            fs::path src_pak  = src / fs::path(pak);
            fs::path src_ucas = src / fs::path(ucas);
            fs::path src_utoc = src / fs::path(utoc);
            fs::path dst_pak  = dst / fs::path(pak);
            fs::path dst_ucas = dst / fs::path(ucas);
            fs::path dst_utoc = dst / fs::path(utoc);




            fs::create_directories(src);
            app.buildBar.step();
            fs::create_directories(dst);
            app.buildBar.step();

            std::cout << "{" << btn << "," << cmd << "}" << src_pak  << " --> " << dst_pak << std::endl;
            fs::copy_file(src_pak, dst_pak, fs::copy_options::overwrite_existing); // TODO throw/exp trycatch
            app.buildBar.step();

            std::cout << "{" << btn << "," << cmd << "}" << src_ucas << " --> " << dst_ucas << std::endl;
            fs::copy_file(src_ucas, dst_ucas, fs::copy_options::overwrite_existing);
            app.buildBar.step();

            std::cout << "{" << btn << "," << cmd << "}" << src_utoc << " --> " << dst_utoc << std::endl;
            fs::copy_file(src_utoc, dst_utoc, fs::copy_options::overwrite_existing);
            app.buildBar.step();

        }
    }
    return 1;
}

const char* GetFolder(const int &c)
{
    if (c >= DEFAULT_1 && c <= DEFAULT_4) return "default";
    if (c >= DEFAULT_DARK_1 && c <= DEFAULT_DARK_4) return "default_dark";
    if (c >= XBOX_1 && c <= XBOX_4) return "xbox";
    if (c >= XBOX_DARK_1 && c <= XBOX_DARK_4) return "xbox_dark";
    if (c >= PLAYSTATION_1 && c <= PLAYSTATION_4) return "playstation";
    if (c >= PLAYSTATION_DARK_1 && c <= PLAYSTATION_DARK_4) return "playstation_dark";
    if (c >= NUM_1 && c <= NUM_4) return "1234";
    if (c >= NUM_DARK_1 && c <= NUM_DARK_4) return "1234_dark";
    return "ERR";
}

const char* GetSubFolder(const int &c)
{
    if (c == DEFAULT_1 || c == DEFAULT_DARK_1 || c == XBOX_1 || c == XBOX_DARK_1 || c == PLAYSTATION_1 || c == PLAYSTATION_DARK_1 || c == NUM_1 || c == NUM_DARK_1) return "1";
    if (c == DEFAULT_2 || c == DEFAULT_DARK_2 || c == XBOX_2 || c == XBOX_DARK_2 || c == PLAYSTATION_2 || c == PLAYSTATION_DARK_2 || c == NUM_2 || c == NUM_DARK_2) return "2";
    if (c == DEFAULT_3 || c == DEFAULT_DARK_3 || c == XBOX_3 || c == XBOX_DARK_3 || c == PLAYSTATION_3 || c == PLAYSTATION_DARK_3 || c == NUM_3 || c == NUM_DARK_3) return "3";
    if (c == DEFAULT_4 || c == DEFAULT_DARK_4 || c == XBOX_4 || c == XBOX_DARK_4 || c == PLAYSTATION_4 || c == PLAYSTATION_DARK_4 || c == NUM_4 || c == NUM_DARK_4) return "4";

    return "UNDEFINED"; // you hope it doesn't ig
}

int preset(AppState &app, const int &c) {
    if (c == 0) { // "Keyboard Settings 1"
        app.P1[0].setCursor(KC_W);  app.notations[0].setCursor(NONE);       app.P1[12].setCursor(KC_L);             app.notations[12].setCursor(NONE);
        app.P1[1].setCursor(KC_S);  app.notations[1].setCursor(NONE);       app.P1[13].setCursor(KC_SEMI_COLON);    app.notations[13].setCursor(NONE);
        app.P1[2].setCursor(KC_A);  app.notations[2].setCursor(NONE);       app.P1[14].setCursor(NONE);             app.notations[14].setCursor(NONE);
        app.P1[3].setCursor(KC_D);  app.notations[3].setCursor(NONE);       app.P1[15].setCursor(NONE);             app.notations[15].setCursor(NONE);
        app.P1[4].setCursor(KC_J);  app.notations[4].setCursor(DEFAULT_3);  app.P1[16].setCursor(NONE);             app.notations[16].setCursor(NONE);
        app.P1[5].setCursor(KC_K);  app.notations[5].setCursor(DEFAULT_4);  app.P1[17].setCursor(NONE);             app.notations[17].setCursor(NONE);
        app.P1[6].setCursor(KC_U);  app.notations[6].setCursor(DEFAULT_1);  app.P1[18].setCursor(NONE);             app.notations[18].setCursor(NONE);
        app.P1[7].setCursor(KC_I);  app.notations[7].setCursor(DEFAULT_2);  app.P1[19].setCursor(NONE);             app.notations[19].setCursor(NONE);
        app.P1[8].setCursor(KC_B);  app.notations[8].setCursor(NONE);       app.P1[20].setCursor(NONE);             app.notations[20].setCursor(NONE);
        app.P1[9].setCursor(KC_V);  app.notations[9].setCursor(NONE);       app.P1[21].setCursor(NONE);             app.notations[21].setCursor(NONE);
        app.P1[10].setCursor(KC_O); app.notations[10].setCursor(NONE);      app.P1[22].setCursor(KC_C);             app.notations[22].setCursor(NONE);
        app.P1[11].setCursor(KC_P); app.notations[11].setCursor(NONE);      app.P1[23].setCursor(KC_N);             app.notations[23].setCursor(NONE);
    }
    else if (c == 1) { // "Keyboard Settings 2"
        app.P1[0].setCursor(KC_ARROWUP);    app.notations[0].setCursor(NONE);       app.P1[12].setCursor(KC_NUMPAD_PLUS);   app.notations[12].setCursor(NONE);
        app.P1[1].setCursor(KC_ARROWDOWN);  app.notations[1].setCursor(NONE);       app.P1[13].setCursor(KC_NUMPAD_6);      app.notations[13].setCursor(NONE);
        app.P1[2].setCursor(KC_ARROWLEFT);  app.notations[2].setCursor(NONE);       app.P1[14].setCursor(KC_NUMPAD_PLUS);   app.notations[14].setCursor(NONE);
        app.P1[3].setCursor(KC_ARROWRIGHT); app.notations[3].setCursor(NONE);       app.P1[15].setCursor(NONE);             app.notations[15].setCursor(NONE);
        app.P1[4].setCursor(KC_NUMPAD_4);   app.notations[4].setCursor(DEFAULT_3);  app.P1[16].setCursor(NONE);             app.notations[16].setCursor(NONE);
        app.P1[5].setCursor(KC_NUMPAD_5);   app.notations[5].setCursor(DEFAULT_4);  app.P1[17].setCursor(NONE);             app.notations[17].setCursor(NONE);
        app.P1[6].setCursor(KC_NUMPAD_7);   app.notations[6].setCursor(DEFAULT_1);  app.P1[18].setCursor(NONE);             app.notations[18].setCursor(NONE);
        app.P1[7].setCursor(KC_NUMPAD_8);   app.notations[7].setCursor(DEFAULT_2);  app.P1[19].setCursor(NONE);             app.notations[19].setCursor(NONE);
        app.P1[8].setCursor(KC_HOME);       app.notations[8].setCursor(NONE);       app.P1[20].setCursor(NONE);             app.notations[20].setCursor(NONE);
        app.P1[9].setCursor(KC_INSERT);     app.notations[9].setCursor(NONE);       app.P1[21].setCursor(NONE);             app.notations[21].setCursor(NONE);
        app.P1[10].setCursor(KC_MINUS);     app.notations[10].setCursor(NONE);      app.P1[22].setCursor(KC_DELETE);        app.notations[22].setCursor(NONE);
        app.P1[11].setCursor(KC_NUMPAD_9);  app.notations[11].setCursor(NONE);      app.P1[23].setCursor(KC_END);           app.notations[23].setCursor(NONE);
    }
    else if (c == 2) { // "Navigation Cluster"
        app.P1[0].setCursor(KC_SPACE);      app.notations[0].setCursor(NONE);   app.P1[12].setCursor(KC_1);   app.notations[12].setCursor(NONE);
        app.P1[1].setCursor(KC_S);          app.notations[1].setCursor(NONE);   app.P1[13].setCursor(KC_2);   app.notations[13].setCursor(NONE);
        app.P1[2].setCursor(KC_A);          app.notations[2].setCursor(NONE);   app.P1[14].setCursor(KC_3);   app.notations[14].setCursor(NONE);
        app.P1[3].setCursor(KC_D);          app.notations[3].setCursor(NONE);   app.P1[15].setCursor(KC_4);   app.notations[15].setCursor(NONE);
        app.P1[4].setCursor(KC_DELETE);     app.notations[4].setCursor(XBOX_3); app.P1[16].setCursor(KC_5);   app.notations[16].setCursor(NONE);
        app.P1[5].setCursor(KC_END);        app.notations[5].setCursor(XBOX_4); app.P1[17].setCursor(KC_6);   app.notations[17].setCursor(NONE);
        app.P1[6].setCursor(KC_INSERT);     app.notations[6].setCursor(XBOX_1); app.P1[18].setCursor(KC_7);   app.notations[18].setCursor(NONE);
        app.P1[7].setCursor(KC_HOME);       app.notations[7].setCursor(XBOX_2); app.P1[19].setCursor(KC_8);   app.notations[19].setCursor(NONE);
        app.P1[8].setCursor(KC_CSBRACKET);  app.notations[8].setCursor(NONE);   app.P1[20].setCursor(KC_9);   app.notations[20].setCursor(NONE);
        app.P1[9].setCursor(KC_BACKSLASH);  app.notations[9].setCursor(NONE);   app.P1[21].setCursor(KC_0);   app.notations[21].setCursor(NONE);
        app.P1[10].setCursor(KC_PAGEUP);    app.notations[10].setCursor(NONE);  app.P1[22].setCursor(KC_F11); app.notations[22].setCursor(NONE);
        app.P1[11].setCursor(KC_PAGEDOWN);  app.notations[11].setCursor(NONE);  app.P1[23].setCursor(KC_F12); app.notations[23].setCursor(NONE);
    }
    else if (c == 3) { // "Invisible"
        /*app.P1[0].setCursor(KC_SPACE);     */ app.notations[0].setCursor(BLANK);   /*app.P1[12].setCursor(KC_1);*/   app.notations[12].setCursor(BLANK);
        /*app.P1[1].setCursor(KC_S);         */ app.notations[1].setCursor(BLANK);   /*app.P1[13].setCursor(KC_2);*/   app.notations[13].setCursor(BLANK);
        /*app.P1[2].setCursor(KC_A);         */ app.notations[2].setCursor(BLANK);   /*app.P1[14].setCursor(KC_3);*/   app.notations[14].setCursor(BLANK);
        /*app.P1[3].setCursor(KC_D);         */ app.notations[3].setCursor(BLANK);   /*app.P1[15].setCursor(KC_4);*/   app.notations[15].setCursor(BLANK);
        /*app.P1[4].setCursor(KC_DELETE);    */ app.notations[4].setCursor(BLANK);   /*app.P1[16].setCursor(KC_5);*/   app.notations[16].setCursor(BLANK);
        /*app.P1[5].setCursor(KC_END);       */ app.notations[5].setCursor(BLANK);   /*app.P1[17].setCursor(KC_6);*/   app.notations[17].setCursor(BLANK);
        /*app.P1[6].setCursor(KC_INSERT);    */ app.notations[6].setCursor(BLANK);   /*app.P1[18].setCursor(KC_7);*/   app.notations[18].setCursor(BLANK);
        /*app.P1[7].setCursor(KC_HOME);      */ app.notations[7].setCursor(BLANK);   /*app.P1[19].setCursor(KC_8);*/   app.notations[19].setCursor(BLANK);
        /*app.P1[8].setCursor(KC_CSBRACKET); */ app.notations[8].setCursor(BLANK);   /*app.P1[20].setCursor(KC_9);*/   app.notations[20].setCursor(BLANK);
        /*app.P1[9].setCursor(KC_BACKSLASH); */ app.notations[9].setCursor(BLANK);   /*app.P1[21].setCursor(KC_0);*/   app.notations[21].setCursor(BLANK);
        /*app.P1[10].setCursor(KC_PAGEUP);   */ app.notations[10].setCursor(BLANK);  /*app.P1[22].setCursor(KC_F11);*/ app.notations[22].setCursor(BLANK);
        /*app.P1[11].setCursor(KC_PAGEDOWN); */ app.notations[11].setCursor(BLANK);  /*app.P1[23].setCursor(KC_F12);*/ app.notations[23].setCursor(BLANK);
    }
    else
        return 0;

    return 1;
}