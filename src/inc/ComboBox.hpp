#ifndef COMBOBOX_HPP
# define COMBOBOX_HPP

#include "Actor.hpp"

class ComboBox : public Actor
{
    public:
        ComboBox();
        ComboBox(const ComboBox &);
        ComboBox(HWND &hwnd,const UINT_PTR &ID,const int &x,const int &y,const int &w,const int &h, const int &flag = 0);

        ~ComboBox();
        ComboBox& operator=(const ComboBox&);

        void init(HWND &hwnd,const UINT_PTR &ID,const int &x,const int &y,const int &w,const int &h, const int &flag = 0);
        void setFont(const int &size);
        void addContent(const std::string &);
        int getCursor();
        std::string getContent();
        int setCursor(const int &);
        void resetCursor();

};

#endif