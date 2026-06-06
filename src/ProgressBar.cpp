#include "ProgressBar.hpp"

ProgressBar::ProgressBar() {}

ProgressBar::ProgressBar(HWND &hwnd,const UINT_PTR &ID,const int &xPos,const int &yPos,const int &width,const int &height)
: Actor(ID,"",xPos,yPos,width,height)
{
    this->hwnd = CreateWindowEx(
        0, PROGRESS_CLASS, (LPTSTR)NULL,WS_CHILD | WS_VISIBLE,
        x, y, w, h, hwnd, reinterpret_cast<HMENU>(ID), GetModuleHandle(NULL), NULL);
    SendMessage(this->hwnd, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
}

ProgressBar::ProgressBar(const ProgressBar &other)
: Actor(other)
{ *this = other; }

ProgressBar& ProgressBar::operator=(const ProgressBar &other) {
    if (this != &other) {
        this->hwnd = other.hwnd;
        this->total = other.total;
        this->p = other.p;
    }
    return *this;
}

ProgressBar::~ProgressBar() {
    DestroyWindow(hwnd);
}

void ProgressBar::init(HWND &hwnd,const UINT_PTR &ID,const int &xPos,const int &yPos,const int &width,const int &height) {
    Actor::init(this->hwnd,ID,name,xPos,yPos,width,height);
    this->hwnd = CreateWindowEx(
        0, PROGRESS_CLASS, (LPTSTR)NULL,WS_CHILD | WS_VISIBLE,
        x, y, w, h, hwnd, reinterpret_cast<HMENU>(ID), GetModuleHandle(NULL), NULL);
    SendMessage(this->hwnd, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
}

void ProgressBar::step() {
    if (p < total)
        SendMessage(hwnd, PBM_SETPOS, ++p, 0);
}

void ProgressBar::reset() {
    p = 0;
    SendMessage(hwnd, PBM_SETPOS, 0, 0);
}

void ProgressBar::setTotal(const int &t) {
    total = t;
    SendMessage(hwnd, PBM_SETRANGE, 0, MAKELPARAM(0, total));
}
void ProgressBar::addTotal(const int &t) { 
    total += t;
    SendMessage(hwnd, PBM_SETRANGE, 0, MAKELPARAM(0, total));
}

// PBM_SETRANGE (WM_USER+1)
// PBM_SETPOS (WM_USER+2)
// PBM_DELTAPOS (WM_USER+3)
// PBM_SETSTEP (WM_USER+4)
// PBM_STEPIT (WM_USER+5)
// PBM_SETRANGE32 (WM_USER+6)
// PBM_GETRANGE (WM_USER+7)
// PBM_GETPOS (WM_USER+8)
// PBM_SETBARCOLOR (WM_USER+9)
// PBM_SETBKCOLOR CCM_SETBKCOLOR