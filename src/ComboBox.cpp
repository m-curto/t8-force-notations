#include "ComboBox.hpp"

ComboBox::ComboBox()
// : ID(0),x(0),y(0),w(0),h(0)
{
    
}

ComboBox::ComboBox(HWND &hwnd,const UINT_PTR &ID,const int &xPos,const int &yPos,const int &width,const int &height)
: ID(ID),x(xPos),y(yPos),w(width),h(height)
{
    cb = CreateWindowExA(
            0, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_VSCROLL,
            x, y,
            // w, h, hwnd,(HMENU)ID,GetModuleHandle(NULL),NULL
            w, h, hwnd,reinterpret_cast<HMENU>(ID),GetModuleHandle(NULL),NULL
    );
    SendMessageA(cb, CB_SETCURSEL, 0, 0);
}

ComboBox::ComboBox(HWND &hwnd,const UINT_PTR &ID,const int &xPos,const int &yPos,const int &width,const int &height,const int &flag)
: ID(ID),x(xPos),y(yPos),w(width),h(height)
{
    cb = CreateWindowExA(
            0, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_VSCROLL | flag,
            x, y,
            // w, h, hwnd,(HMENU)ID,GetModuleHandle(NULL),NULL
            w, h, hwnd,reinterpret_cast<HMENU>(ID),GetModuleHandle(NULL),NULL
    );
    SendMessageA(cb, CB_SETCURSEL, 0, 0);
}

ComboBox::ComboBox(const ComboBox &other) { *this = other; }

ComboBox& ComboBox::operator=(const ComboBox &other) {
    if (this != &other) {
        this->ID = other.ID;
        this->cb = other.cb;
        this->x = other.x;
        this->y = other.y;
        this->w = other.w;
        this->h = other.h;
        SendMessageA(cb, CB_GETCURSEL, 0, SendMessageA(cb,CB_GETCURSEL,0,0));
    }
    return *this;
}

ComboBox::~ComboBox() {}

std::ostream& operator<<(std::ostream& os, const ComboBox&)
{
    os << "TODO";
    return os;
}

void ComboBox::setPos(const int &newX, const int &newY) {
    x = newX;
    y = newY;
    SetWindowPos(cb, NULL, x, y, w, h, SWP_NOZORDER);
}

void ComboBox::setFont(const int &size) {
    HFONT font = CreateFontA(
        size, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH,
        "");
    SendMessageA(cb, WM_SETFONT, (WPARAM)font, TRUE);

}


void ComboBox::addContent(const std::string &s) {
    SendMessageA(cb, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(s.c_str()));
    resetCursor();
}

void ComboBox::resetCursor() {
    SendMessageA(cb, CB_SETCURSEL, 0, 0);
}

int ComboBox::getCursor() {
    return SendMessageA(cb,CB_GETCURSEL,0,0);
}

std::string ComboBox::getContent() {
    int index = SendMessageA(cb, CB_GETCURSEL, 0, 0);
    if (index != CB_ERR)
        return "";
    char buffer[256];
    SendMessageA(cb, CB_GETLBTEXT, index, (LPARAM)buffer);
    return std::string(buffer);
}
