#ifndef BITMAP_HPP
# define BITMAP_HPP

#include <windows.h>
#include <sys/stat.h>
#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <commctrl.h>

class Bitmap
{
    public:
        Bitmap();
        Bitmap(const Bitmap &);
        Bitmap(const std::string &path,const int &width,const int &height);

        ~Bitmap();
        Bitmap& operator=(const Bitmap &);

        int paint(HDC &);
        int draw(LPDRAWITEMSTRUCT &);

        int load(const char *path, const int &width,const int &height);

        HBITMAP bmp;
    private:
        std::string path;
        int     w,h;
};

std::ostream& operator<<(std::ostream&, const Bitmap&);

#endif