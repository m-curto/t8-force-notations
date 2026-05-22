#include "Button.hpp"

Button::Button()
// : ID(0),x(0),y(0),w(0),h(0)
{
    
}

Button::Button(HWND &hwnd,const UINT_PTR &ID,const std::string &name,const int &xPos,const int &yPos,const int &width,const int &height)
: ID(ID),name(name),x(xPos),y(yPos),w(width),h(height)
{
    btn = CreateWindowW(
        L"BUTTON",reinterpret_cast<const wchar_t*>(std::wstring(name.begin(),name.end()).c_str()),WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        x,y,w,h, hwnd,reinterpret_cast<HMENU>(ID),NULL,NULL
    );
}

Button::Button(const Button &other) { *this = other; }

Button& Button::operator=(const Button &other) {
    if (this != &other) {
        this->ID = other.ID;
        this->btn = other.btn;
        this->x = other.x;
        this->y = other.y;
        this->w = other.w;
        this->h = other.h;
    }
    return *this;
}

Button::~Button() {}

std::ostream& operator<<(std::ostream& os, const Button&)
{
    os << "TODO";
    return os;
}

void Button::setPos(const int &newX, const int &newY) {
    x = newX;
    y = newY;
    SetWindowPos(btn, NULL, x, y, w, h, SWP_NOZORDER);
}
