#ifndef PROGRESSBAR_HPP
# define PROGRESSBAR_HPP

#include <windows.h>
#include <sys/stat.h>
#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <commctrl.h>

class ProgressBar
{
    public:
        ProgressBar();
        ProgressBar(const ProgressBar &);
        ProgressBar(HWND &hwnd,const UINT_PTR &ID,const int &x,const int &y,const int &w,const int &h);

        ~ProgressBar();
        ProgressBar& operator=(const ProgressBar &);

        void step();
        void reset();

        void setTotal(const int&);
        void addTotal(const int&);

        void setPos(const int&x,const int&y);

        UINT_PTR ID;
    private:
        HWND    bar;
        int     x,y,w,h;
        int     total;
        int     p;
};

std::ostream& operator<<(std::ostream&, const ProgressBar&);

#endif