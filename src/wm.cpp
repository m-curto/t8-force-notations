#include "T8_ForceNotations.hpp"

void wm_create(HWND &hwnd, AppState &app) {
    std::cout << "WM_CREATE" << std::endl;
    short create_x     = WINDOW_WIDTH*.85;
    short create_y     = WINDOW_HEIGHT*.75;
    short verify_x     = WINDOW_WIDTH*.12;
    short verify_y     = WINDOW_HEIGHT*.8;
    short verify_pmb_x = verify_x - PMB_W*.5;
    short verify_pmb_y = verify_y + PMB_H*1.2;
    // short notation_x     = WINDOW_WIDTH*.35;
    // short notation_y     = WINDOW_HEIGHT*.8;

    CreateWindowW(
        L"BUTTON",L"Build",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        create_x,create_y,
        BTN2_W,BTN2_H, hwnd,(HMENU)ID_BUILD,NULL,NULL
    );


    app.buildplayer = CreateWindowExA(
            0, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_VSCROLL,
            create_x, create_y - 25,
            CMB2_W, CMB2_H, hwnd,(HMENU)ID_BUILDPLAYER,GetModuleHandle(NULL),NULL
    );
    CreateWindowW(
        L"BUTTON",L"Clear",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        create_x,create_y + 25 + BTN3_H,
        BTN3_W,BTN3_H, hwnd,(HMENU)ID_CLEAR,NULL,NULL
    );

    // create_x - BTN2_W*.5, create_y - BTN2_H*.5,

    CreateWindowW(
        L"BUTTON",
        L"Verify Integrity",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        verify_x - BTN_W*.5, verify_y - BTN_H*.5,
        BTN_W, BTN_H,
        hwnd,
        (HMENU)ID_VERIFY,
        NULL, NULL
    );
    int xOff = 200;
    int yOff = 18;
    for (int s = 0; s < BIND_MAX; ++s) {
        if (s < 12)
        {
            app.P1[s] = CreateWindowExA(
            0, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_VSCROLL,
            xOff, yOff, CMB_W, CMB_H, hwnd,(HMENU)ID_CMB1_24 + s,GetModuleHandle(NULL),NULL
            );
        }
        else
        {
            app.P1[s] = CreateWindowExA(0, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_VSCROLL,xOff+CMB_W+108, yOff, CMB_W, CMB_H, hwnd,(HMENU)ID_CMB1_24 + s,GetModuleHandle(NULL),NULL);
        }
        yOff += 26;
        if (s == 11) yOff = 18;
        SendMessageA(app.P1[s], CB_SETCURSEL, 0, 0);
    }
    yOff = 18;

    for (int s = 0; s < BIND_MAX; ++s) {
        if (s < 12)
        {
            app.notations[s] = CreateWindowExA(
                0, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_OWNERDRAWFIXED | CBS_HASSTRINGS | WS_VSCROLL,
                // notation_x - BTN_W*.5, notation_y - BTN_H*.5, NOTATION_W+NOTATION_W,NOTATION_H*NOTATION_MAX,
                // 250, 18, NOTATION_W+NOTATION_W,NOTATION_H*NOTATION_MAX,hwnd,(HMENU)ID_NOTATIONS_TMP,GetModuleHandle(NULL),NULL
                xOff+CMB_W+5,yOff,CMB3_W,CMB3_H,hwnd,(HMENU)ID_CMB2_24+s,GetModuleHandle(NULL),NULL
            );
        }
        else
        {
            app.notations[s] = CreateWindowExA(
                0, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_OWNERDRAWFIXED | CBS_HASSTRINGS | WS_VSCROLL,
                // notation_x - BTN_W*.5, notation_y - BTN_H*.5, NOTATION_W+NOTATION_W,NOTATION_H*NOTATION_MAX,
                // 250, 18, NOTATION_W+NOTATION_W,NOTATION_H*NOTATION_MAX,hwnd,(HMENU)ID_NOTATIONS_TMP,GetModuleHandle(NULL),NULL
                xOff+CMB_W+225,yOff,CMB3_W,CMB3_H,hwnd,(HMENU)ID_CMB2_24+s,GetModuleHandle(NULL),NULL
            );
        }
        yOff += 26;
        if (s == 11) yOff = 18;
    }

    app.hProgress = CreateWindowEx(0, PROGRESS_CLASS, (LPTSTR) NULL,
            WS_CHILD | WS_VISIBLE,
            verify_pmb_x, verify_pmb_y, PMB_W, PMB_H,
            hwnd, (HMENU)ID_VERIFY_PMB, GetModuleHandle(NULL), NULL);
    SendMessage(app.hProgress, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
    PostMessage(hwnd, WM_APP + 1, 0, 0);
    app.background = (HBITMAP)LoadImageA(
            NULL,
            BMP_BACKGROUND,
            IMAGE_BITMAP,
            0, 0,
            LR_LOADFROMFILE
        );
    if (!app.background)
    {
        MessageBoxA(NULL, std::to_string(GetLastError()).c_str(), "LoadImage error", MB_OK);
    }
}

void wm_paint(HWND &hwnd, AppState &app) {
    std::cout << "WM_PAINT" << std::endl;
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    if (app.background)
    {
        HDC memDC = CreateCompatibleDC(hdc);
        SelectObject(memDC, app.background);
        BITMAP bm;
        GetObject(app.background, sizeof(bm), &bm);
        BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCCOPY);
        DeleteDC(memDC);
    }
    EndPaint(hwnd, &ps);
}

void wm_app1(HWND &, AppState &app)
{
    // std::map<std::string, int>  combo1 ={{"0",1},"1","2","3","4","5","6","7","8","9","space"};
    std::vector<const char *> name = {
"- -","0","1","2","3","4","5","6","7","8","9","Ctrl.",".Shift","Shift.","Insert","Home","PageUp","Delete","End","PageDown","ArrowUp","ArrowLeft","ArrowRight","ArrowDown","ArrowUp","ArrowLeft","ArrowRight","ArrowDown","NumPad 0","NumPad 1","NumPad 2","NumPad 3","NumPad 4","NumPad 5","NumPad 6","NumPad 7","NumPad 8","NumPad 9","NumPad /","NumPad *","NumPad -","NumPad +","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","-","^","¥","@","[","]",";",":",",",".","/","\\","=","`",")","$","Ù","*","!","ß","'","Ü","Ä","Ì","È","Ò","À","i","Ñ","Ç","~","¿","<","ظ","ฟ","²","#","o̲","}","|","{","Ж","б","ю","ë","x","ъ","Э","ك","F1","F2","F3","F4","F5","F6","F7","F8","F9","F10","F11","F12","tab",".Alt","Alt.","CapsLock","ScrollLock"
};

    std::vector<const char *> bmp = {
"resources/none.bmp",

"resources/default/default_1.bmp",
"resources/default/default_2.bmp",
"resources/default/default_3.bmp",
"resources/default/default_4.bmp",
"resources/default_dark/default_dark_1.bmp",
"resources/default_dark/default_dark_2.bmp",
"resources/default_dark/default_dark_3.bmp",
"resources/default_dark/default_dark_4.bmp",
"resources/xbox/xbox_1.bmp",
"resources/xbox/xbox_2.bmp",
"resources/xbox/xbox_3.bmp",
"resources/xbox/xbox_4.bmp",
"resources/xbox_dark/xbox_dark_1.bmp",
"resources/xbox_dark/xbox_dark_2.bmp",
"resources/xbox_dark/xbox_dark_3.bmp",
"resources/xbox_dark/xbox_dark_4.bmp",
"resources/playstation/playstation_1.bmp",
"resources/playstation/playstation_2.bmp",
"resources/playstation/playstation_3.bmp",
"resources/playstation/playstation_4.bmp",
"resources/playstation_dark/playstation_dark_1.bmp",
"resources/playstation_dark/playstation_dark_2.bmp",
"resources/playstation_dark/playstation_dark_3.bmp",
"resources/playstation_dark/playstation_dark_4.bmp",
"resources/1234/1234_1.bmp",
"resources/1234/1234_2.bmp",
"resources/1234/1234_3.bmp",
"resources/1234/1234_4.bmp",
"resources/1234_dark/1234_dark_1.bmp",
"resources/1234_dark/1234_dark_2.bmp",
"resources/1234_dark/1234_dark_3.bmp",
"resources/1234_dark/1234_dark_4.bmp"
};

    for (size_t s = 0; s < bmp.size(); ++s) { // IF NOTATION_MAX != bmp.size() we segfualt ig

        app.bmpNotations[s] = (HBITMAP)LoadImageA(NULL,bmp[s],IMAGE_BITMAP,NOTATION_W,NOTATION_H,LR_LOADFROMFILE);
        if (!app.bmpNotations[s]) { MessageBoxA(NULL, bmp[s], "LoadImage error", MB_OK);}
    }

    HFONT hFont = CreateFontA(
        24, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH,
        ""
    );

    for (size_t s = 0; s < BIND_MAX; ++s) {
        for (auto n : name) {
            SendMessageA(app.P1[s], CB_ADDSTRING, 0, (LPARAM)n);
        }
    }

    for (int s = 0; s < BIND_MAX; ++s) {
        for (auto b : bmp) {
            SendMessageA(app.notations[s], CB_ADDSTRING, 0, (LPARAM)b);
        }
    }

    for (int s = 0; s < BIND_MAX; ++s) {
        SendMessageA(app.P1[s], CB_SETCURSEL, 0, 0);
        SendMessageA(app.notations[s], CB_SETCURSEL, 0, 0);

        SendMessageA(app.P1[s], WM_SETFONT, (WPARAM)hFont, TRUE);
        // SendMessageA(app.notations[s], WM_SETFONT, (WPARAM)hFont, TRUE);

        for (auto b : bmp) {
            SendMessageA(app.notations[s], CB_ADDSTRING, 0, (LPARAM)b);
        }
    }
    SendMessageA(app.buildplayer, CB_ADDSTRING, 0, (LPARAM)"Player1");
    SendMessageA(app.buildplayer, CB_ADDSTRING, 0, (LPARAM)"Player2");
    SendMessageA(app.buildplayer, CB_SETCURSEL, 0, 0);

}

void wm_command(HWND &hwnd, WPARAM wParam, AppState &app) {
    std::cout << "WM_COMMAND LOWORD==" << LOWORD(wParam) << std::endl;
       if (LOWORD(wParam) == ID_BUILD)
        {
            KBL_build(hwnd,app);
        }
        else if (LOWORD(wParam) == ID_CLEAR)
        {
            for (int s = 0; s < BIND_MAX; ++s) {
                // int btn = GetComboCursor((HWND)app.P1[s]);
                // int cmd = GetComboCursor((HWND)app.notations[s]);
                ResetCursor(app.P1[s]);
                ResetCursor(app.notations[s]);
            }
        }
        else if (LOWORD(wParam) == ID_VERIFY)
        {
            // VerifyIntegrity();
            StartVerify(hwnd,app);
        }
        else if (LOWORD(wParam) == ID_COMBO1)
        {
            int index = SendMessageA(app.P1[SLOT_UP], CB_GETCURSEL, 0, 0);
            if (index != CB_ERR)
            {
                char buffer[256];
                SendMessageA(app.P1[SLOT_UP], CB_GETLBTEXT, index, (LPARAM)buffer);
                std::cout << "COMBO1:\t" << buffer << std::endl;
            }
        }
}

int wm_drawitem(HWND &, WPARAM , LPARAM lParam, AppState &app) {
    // std::cout << "WM_DRAWITEM" << std::endl;
    LPDRAWITEMSTRUCT dis = (LPDRAWITEMSTRUCT)lParam;
    HDC memDC = CreateCompatibleDC(dis->hDC);
    HBITMAP bmp = nullptr;

    for (size_t s = 0; s < NOTATION_MAX; ++s) {
        if (dis->itemID == s) {
            bmp = app.bmpNotations[s];
            break;
        }
    }

    if (bmp)
    {
        SelectObject(memDC, bmp);

        BITMAP bm;
        GetObject(bmp, sizeof(bm), &bm);

        FillRect(
            dis->hDC,
            &dis->rcItem,
            (HBRUSH)(COLOR_WINDOW + 1)
        );

        BitBlt(
            dis->hDC,
            dis->rcItem.left,
            dis->rcItem.top,
            NOTATION_W,
            NOTATION_H,
            memDC,
            0,
            0,
            SRCCOPY
        );
    }

    DeleteDC(memDC);
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