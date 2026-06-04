#include "Button.hpp"

Button::Button() {}

Button::Button(HWND &hwnd,const UINT_PTR &ID,const std::string &name,const int &xPos,const int &yPos,const int &width,const int &height)
: Actor(ID,name,xPos,yPos,width,height)
{
    this->hwnd = CreateWindowW(
        L"BUTTON",reinterpret_cast<const wchar_t*>(std::wstring(name.begin(),name.end()).c_str()),WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        x,y,w,h,hwnd,reinterpret_cast<HMENU>(ID),NULL,NULL
    );
}

Button::Button(const Button &other)
: Actor(other)
{ *this = other; }

Button& Button::operator=(const Button &other) {
    if (this != &other) {
        this->hwnd = other.hwnd;
    }
    return *this;
}

Button::~Button() {}
