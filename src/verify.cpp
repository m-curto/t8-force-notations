#include "T8ForceNotations.hpp"

int VerifyIntegrity(std::string &err, AppState &app)
{
    fs::path current;// = fs::current_path();
    std::vector<const char*> specific = get_paths_bmp();
    std::array<std::pair<fs::path,const char*>, PAKS_MAX> paths = get_paths();
    app.verifyBar.setTotal((PAKS_MAX-1)*(FILE_MAX-2) + PAKS_MAX + specific.size());

    for (auto p : paths) {
        
        for (int i = 1; i < FILE_MAX; i++)
        {
            if (p.first == "")
                break ;
            if (i == 198) // as intended CMD_36/CMD_37
                continue;
            char pak[64], ucas[64], utoc[64];
            sprintf(pak, "pakchunk8%03d-Windows_P.pak", i);
            sprintf(ucas, "pakchunk8%03d-Windows_P.ucas", i);
            sprintf(utoc, "pakchunk8%03d-Windows_P.utoc", i);
            fs::path p_pak  = p.first / pak;
            fs::path p_ucas = p.first / ucas;
            fs::path p_utoc = p.first / utoc;
            if (!fs::exists(p_pak))  { err += p_pak.string(); return false; }
            if (!fs::exists(p_ucas)) { err += p_pak.string(); return false; }
            if (!fs::exists(p_utoc)) { err += p_pak.string(); return false; }
            app.verifyBar.step();
        }
        if (!fs::exists(p.second))  { err += p.second; return false; }
        app.verifyBar.step();
    }

    for (auto path : specific) {
        fs::path spec = path;
        if (!fs::exists(spec)) { err += spec.string(); return false; }
        app.verifyBar.step();
    }

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
    app.verifyBar.reset();

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