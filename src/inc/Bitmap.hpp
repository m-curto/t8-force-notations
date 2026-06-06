#ifndef BITMAP_HPP
# define BITMAP_HPP

# include "Actor.hpp"

class Bitmap : public Actor
{
    public:
        Bitmap();
        Bitmap(const Bitmap &);
        Bitmap(const std::string &path,const int &width,const int &height);

        ~Bitmap();
        Bitmap& operator=(const Bitmap &);

        void init(HWND &hwnd, const std::string &path,const int &x,const int &y,const int &width,const int &height);

        int paint(HDC &);
        int draw(LPDRAWITEMSTRUCT &);

        int load(const char *path, const int &width,const int &height);

    public:
        HBITMAP bmp = nullptr;
};


#endif