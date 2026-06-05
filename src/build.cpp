#include "T8ForceNotations.hpp"

int KB_build(HWND &hwnd, AppState &app)
{
    int total = 0;
    for (int s = 0; s < BIND_MAX; ++s) {
        if (app.KB[s].getCursor() > 0 && app.notations[s].getCursor() > 0) total += 4;
    }
    app.buildBar.setTotal(total);

    fs::path current; // = fs::current_path();

    std::vector<fs::path> notation_folder = {PAKS_FOLDER};

    std::array<std::pair<fs::path,const char*>, PAKS_MAX> src_paths = get_paths();

    for (int s = 0; s < BIND_MAX; ++s)
    {
        int btn = app.KB[s].getCursor();
        int cmd = app.notations[s].getCursor();

        if (btn > 0 && cmd > 0) {
            if (cmd < 0 || cmd >= PAKS_MAX) {
                std::cerr << COLOR_RED << "ERROR FOLDER NOT FOUND (" << cmd << ")" << COLOR_RESET << std::endl;
                continue ;
            }
            std::cout << COLOR_YELLOW << "cmd=" << cmd << COLOR_RESET << std::endl;
            fs::path src = current / src_paths[cmd].first;
            fs::path dst = current / fs::path(KBL_FOLDER) / (app.buildCb.getCursor() == 0 ? fs::path(P1_FOLDER) : fs::path(P2_FOLDER)) / fs::path(std::to_string(cmd).c_str());

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


            fs::create_directories(dst);
            app.buildBar.step();


            std::cout << "{" << btn << "," << cmd << "} " << src_pak  << " --> " << dst_pak << std::endl;
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

    if (total != 0)
        MessageBoxA(hwnd, (LPCSTR)MSG_BUILD, CAPTION_BUILD, MB_OK | MB_ICONINFORMATION);
    app.buildBar.reset();

    return 1;
}

int XSX_build(HWND &hwnd, AppState &)
{
    MessageBoxA(hwnd, (LPCSTR)"TODO", CAPTION_BUILD, MB_OK | MB_ICONINFORMATION);
    return 1;
}
