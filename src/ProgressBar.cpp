#include "ProgressBar.hpp"

ProgressBar::ProgressBar()
// : ID(0),x(0),y(0),w(0),h(0)
{
    
}

ProgressBar::ProgressBar(HWND &hwnd,const UINT_PTR &ID,const int &xPos,const int &yPos,const int &width,const int &height)
: ID(ID),x(xPos),y(yPos),w(width),h(height)
{
    std::cout << "ID:" << ID << std::endl;
    bar = CreateWindowEx(0, PROGRESS_CLASS, (LPTSTR)NULL,
        WS_CHILD | WS_VISIBLE,
        x, y, w, h,
        hwnd, reinterpret_cast<HMENU>(ID), GetModuleHandle(NULL), NULL);
    SendMessage(bar, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
}

ProgressBar::ProgressBar(const ProgressBar &other) { *this = other; }

ProgressBar& ProgressBar::operator=(const ProgressBar &other) {
    if (this != &other) {
        this->ID = other.ID;
        this->bar = other.bar;
        this->x = other.x;
        this->y = other.y;
        this->w = other.w;
        this->h = other.h;
        this->total = other.total;
        this->p = other.p;
    }
    return *this;
}

ProgressBar::~ProgressBar() {}

std::ostream& operator<<(std::ostream& os, const ProgressBar&)
{
    os << "TODO";
    return os;
}


void ProgressBar::step() {
    if (p < total)
        SendMessage(bar, PBM_SETPOS, ++p, 0);
}

void ProgressBar::reset() {
    p = 0;
    SendMessage(bar, PBM_SETPOS, 0, 0);
}

void ProgressBar::setTotal(const int &t) {
    total = t;
    SendMessage(bar, PBM_SETRANGE, 0, MAKELPARAM(0, total));
}
void ProgressBar::addTotal(const int &t) { 
    total += t;
    SendMessage(bar, PBM_SETRANGE, 0, MAKELPARAM(0, total));
}

void ProgressBar::setPos(const int &newX, const int &newY) {
    x = newX;
    y = newY;
    SetWindowPos(bar, NULL, x, y, w, h, SWP_NOZORDER);
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