#ifndef ACTOR_HPP
# define ACTOR_HPP

#include <windows.h>
#include <sys/stat.h>
#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <commctrl.h>

class Actor
{
    public:
        Actor();
        Actor(const Actor &);
        Actor(const UINT_PTR &ID,const std::string &name,const int &x,const int &y,const int &w,const int &h);

        ~Actor();
        Actor& operator=(const Actor &);

        void setPos(const int &x,const int &y);
        void init(HWND &hwnd, const UINT_PTR &ID,const std::string &name,const int &xPos,const int &yPos,const int &width,const int &height);

        WINBOOL window(const int &x);

        UINT_PTR ID;
        HWND hwnd = 0;
    protected:
        std::string name;
        int     x,y,w,h;
};

std::ostream& operator<<(std::ostream&, const Actor&);

#endif