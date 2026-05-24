#ifndef COMBOBOX_HPP
# define COMBOBOX_HPP

#include <windows.h>
#include <sys/stat.h>
#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <commctrl.h>

class ComboBox
{
    public:
        ComboBox();
        ComboBox(const ComboBox &);
        ComboBox(HWND &hwnd,const UINT_PTR &ID,const int &x,const int &y,const int &w,const int &h);
        ComboBox(HWND &hwnd,const UINT_PTR &ID,const int &x,const int &y,const int &w,const int &h, const int &flag);

        ~ComboBox();
        ComboBox& operator=(const ComboBox&);

        void setPos(const int &newX, const int &newY);
        void setFont(const int &size);
        void addContent(const std::string &);
        int getCursor();
        std::string getContent();
        int setCursor(const int &);
        void resetCursor();

        UINT_PTR ID;
        HWND    cb;
    private:
        int     x,y,w,h;
};

std::ostream& operator<<(std::ostream&, const ComboBox&);

#endif