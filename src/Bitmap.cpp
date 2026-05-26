#include "Bitmap.hpp"

Bitmap::Bitmap()
// : ID(0),x(0),y(0),w(0),h(0)
{

}

Bitmap::Bitmap(const std::string &path,const int &width,const int &height)
: path(path),w(width),h(height)
{
        bmp = (HBITMAP)LoadImageA(
            NULL,
            path.c_str(),
            IMAGE_BITMAP,
            w,h,
            LR_LOADFROMFILE
        );
}

Bitmap::Bitmap(const Bitmap &other) { *this = other; }

Bitmap& Bitmap::operator=(const Bitmap &other) {
    if (this != &other) {
        this->path = other.path;
        this->bmp = other.bmp;
        this->w = other.w;
        this->h = other.h;
    }
    return *this;
}

Bitmap::~Bitmap() {}

std::ostream& operator<<(std::ostream& os, const Bitmap&)
{
    os << "TODO";
    return os;
}

int Bitmap::paint(HDC &hdc) {
    HDC memDC = CreateCompatibleDC(hdc);
    if (memDC == 0)
        return 0;
    if (SelectObject(memDC, bmp) == 0) {
        DeleteDC(memDC);
        return 0;
    }
    BITMAP bm;
    if (GetObject(bmp, sizeof(bm), &bm) == 0) {
        DeleteDC(memDC);
        return 0;
    }
    BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCCOPY);
    DeleteDC(memDC);
    return 1;
}

int Bitmap::draw(LPDRAWITEMSTRUCT &dis)
{
    HDC memDC = CreateCompatibleDC(dis->hDC);
    if (SelectObject(memDC, bmp) == 0) {
        DeleteDC(memDC);
        return 0;
    }
    BITMAP bm;
    if (GetObject(bmp, sizeof(bm), &bm) == 0) {
        FillRect(
            dis->hDC,
            &dis->rcItem,
            (HBRUSH)(COLOR_WINDOW + 1)
        );
        DeleteDC(memDC);
        return 0;
    }

    BitBlt(
        dis->hDC,
        dis->rcItem.left,
        dis->rcItem.top,
        25,// TODO define w.h ? #define NOTATION_W 25
        25,// TODO #define NOTATION_H 25
        memDC,
        0,
        0,
        SRCCOPY
        );

    DeleteDC(memDC);
    return 1;
}

int Bitmap::load(const char *path, const int &width, const int &height) {
    w = width;
    h = height;
    bmp = (HBITMAP)LoadImageA(NULL,path,IMAGE_BITMAP,w,h,LR_LOADFROMFILE);
    if (!bmp) {
        // MessageBoxA(NULL, path, "LoadImage error", MB_OK);
        return 0;
    }
    return 1;
}
