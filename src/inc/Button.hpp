#ifndef BUTTON_HPP
# define BUTTON_HPP

#include <windows.h>
#include <sys/stat.h>
#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <commctrl.h>

class Button
{
    public:
        Button();
        Button(const Button &);
        Button(HWND &hwnd,const UINT_PTR &ID,const std::string &name,const int &x,const int &y,const int &w,const int &h);

        ~Button();
        Button& operator=(const Button &);

        void setPos(const int&x,const int&y);

        UINT_PTR ID;
    private:
        HWND    btn;
        std::string name;
        int     x,y,w,h;
};

std::ostream& operator<<(std::ostream&, const Button&);

#endif