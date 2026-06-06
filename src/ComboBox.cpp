#include "ComboBox.hpp"

ComboBox::ComboBox() {}

ComboBox::ComboBox(HWND &parent,const UINT_PTR &ID,const int &xPos,const int &yPos,const int &width,const int &height,const int &flag)
: Actor(ID,"",xPos,yPos,width,height)
{
    this->hwnd = CreateWindowExA(
        0, "COMBOBOX", NULL, WS_CHILD | CBS_DROPDOWNLIST | WS_VSCROLL | flag,
        x, y, w, h,parent,reinterpret_cast<HMENU>(ID),GetModuleHandle(NULL),NULL
    );
    SendMessageA(this->hwnd, CB_SETCURSEL, 0, 0);
}

ComboBox::ComboBox(const ComboBox &other)
: Actor(other)
{ *this = other; }

ComboBox& ComboBox::operator=(const ComboBox &other) {
    if (this != &other) {
        this->hwnd = other.hwnd;
        // SendMessageA(this->hwnd, CB_SETCURSEL, 0, 0);
        SendMessageA(hwnd, CB_GETCURSEL, 0, SendMessageA(hwnd,CB_GETCURSEL,0,0));
    }
    return *this;
}

ComboBox::~ComboBox() {
    DestroyWindow(hwnd);
}

void ComboBox::init(HWND &hwnd,const UINT_PTR &ID,const int &x,const int &y,const int &w,const int &h, const int &flag) {
    Actor::init(this->hwnd,ID,name,x,y,w,h);
    this->hwnd = CreateWindowExA(
        0, "COMBOBOX", NULL, WS_CHILD | CBS_DROPDOWNLIST | WS_VSCROLL | flag,
        x, y, w, h,hwnd,reinterpret_cast<HMENU>(ID),GetModuleHandle(NULL),NULL
    );
    SendMessageA(this->hwnd, CB_SETCURSEL, 0, 0);
}

void ComboBox::setFont(const int &size) {
    HFONT font = CreateFontA(
        size, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH,
        "");
    SendMessageA(hwnd, WM_SETFONT, (WPARAM)font, TRUE);
}

void ComboBox::addContent(const std::string &s) {
    // std::cout << "addContent(" << s << ") " << hwnd << std::endl;
    SendMessageA(hwnd, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(s.c_str()));
    GetLastError();
    resetCursor();
}

void ComboBox::resetCursor() {
    SendMessageA(hwnd, CB_SETCURSEL, 0, 0);
}

int ComboBox::getCursor() {
    return SendMessageA(hwnd, CB_GETCURSEL,0,0);
}

int ComboBox::setCursor(const int &c) {
    return SendMessageA(hwnd, CB_SETCURSEL,c,0);
}

std::string ComboBox::getContent() {
    int index = SendMessageA(hwnd, CB_GETCURSEL, 0, 0);
    if (index != CB_ERR)
        return "";
    char buffer[256];
    SendMessageA(hwnd, CB_GETLBTEXT, index, (LPARAM)buffer);
    return std::string(buffer);
}
