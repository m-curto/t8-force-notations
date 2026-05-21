#include "T8_ForceNotations.hpp"

int VerifyIntegrity(std::string &err, AppState &app)
{
    fs::path current;// = fs::current_path();
    int total = (149*3*4) + (4*4*2) + (2);
    int p = 0;

    std::vector<const char*> notation_folder = {"T8"};
    std::vector<const char*> notation_style = {"default"/*,"default_dark","xbox","xbox_dark","playstation","playstation_dark"*/};
    std::vector<const char*> notation_cmd = {"X","Y","A","B"};

    std::vector<const char*> bitmap_folder = {"resources"};

    std::vector<const char*> specific = {BMP_BACKGROUND, "resources/none.bmp"};

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
                    int percent = (p++ * 100) / total;
                    SendMessage(app.hProgress, PBM_SETPOS, percent, 0);
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
                int percent = (p++ * 100) / total;
                SendMessage(app.hProgress, PBM_SETPOS, percent, 0);
            }
        }
    }

    for (auto path : specific) {
        fs::path spec = path;
        if (!fs::exists(spec)) { err += spec.string(); return false; }
        
        int percent = (p++ * 100) / total;
        SendMessage(app.hProgress, PBM_SETPOS, percent, 0);
    }

    SendMessage(app.hProgress, PBM_SETPOS, 100, 0);
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
    SendMessage(app.hProgress, PBM_SETPOS, 0, 0);
}

void ResetCursor(HWND &target) {
    SendMessageA(target, CB_SETCURSEL, 0, 0);
}

std::string GetComboText(HWND &cmb)
{
    int index = SendMessageA(cmb, CB_GETCURSEL, 0, 0);
    if (index == CB_ERR)
        return "";
    int len = SendMessageA(cmb, CB_GETLBTEXTLEN, index, 0);
    std::string text(len, '\0');
    SendMessageA(cmb, CB_GETLBTEXT, index, (LPARAM)text.data());
    return text;
}

int GetComboCursor(HWND cmb)
{
    return SendMessageA(cmb,CB_GETCURSEL,0,0);
}

int KBL_build(HWND &, AppState&app)
{
    std::vector<std::string> name =
    {"UP","DOWN","LEFT","RIGHT","A","B",
     "X","Y","START","SELECT","LB","RB",
     "LT","RT","LS_UP","LS_DOWN","LS_LEFT","LS_RIGHT",
     "RS_UP","RS_DOWN","RS_LEFT","RS_RIGHT", "L3", "R3"};

    std::vector<std::string> folders =
    { "default", "default_dark","xbox","xbox_dark","playstation","playstation_dark","1234","1234_dark"};

    fs::path dst_f = "KBL";
    fs::path dst_pf = ((int)GetComboCursor((HWND)app.buildplayer) == 0) ? "P1" : "P2";

    for (int s = 0; s < BIND_MAX; ++s) {
        int btn = GetComboCursor((HWND)app.P1[s]);
        int cmd = GetComboCursor((HWND)app.notations[s]); (void)cmd;

        if (btn > 0 && cmd > 0) {

            fs::path dst_nf = GetFolder(cmd);
            fs::path dstfile = dst_f / dst_pf / name[s];
            fs::path src_f  = "T8";
            fs::path src_nf = dst_nf;
            fs::path src_tf = name[s];

            fs::path srcfile = src_f / src_nf / src_tf;
            std::cout << "{" << btn << "," << cmd << "}" << "src:\t" << srcfile << std::endl;
            std::cout << "{" << btn << "," << cmd << "}" << "dst:\t" << dstfile << std::endl;

            // fs::create_directories(dstfile);
            // fs::copy_file(sample, sample2 / sample, fs::copy_options::overwrite_existing); // can throw lmao fml trycatch etc. TODO
        }
    }

    return 1;
}

const char* GetFolder(int &c)
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
