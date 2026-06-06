#ifndef BUTTON_HPP
# define BUTTON_HPP

#include <windows.h>
#include <sys/stat.h>
#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <commctrl.h>

#include "Actor.hpp"

class Button : public Actor
{
    public:
        Button();
        Button(const Button &);
        Button(HWND &hwnd,const UINT_PTR &ID,const std::string &name,const int &x,const int &y,const int &w,const int &h);

        void init(HWND &hwnd,const UINT_PTR &ID,const std::string &name,const int &x,const int &y,const int &w,const int &h);
        ~Button();
        Button& operator=(const Button &);

};

#endif