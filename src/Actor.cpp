#include "Actor.hpp"

Actor::Actor() {}

Actor::Actor(const UINT_PTR &ID,const std::string &name,const int &xPos,const int &yPos,const int &width,const int &height)
: ID(ID),hwnd(0),name(name),x(xPos),y(yPos),w(width),h(height) {}

Actor::Actor(const Actor &other) { *this = other; }

Actor& Actor::operator=(const Actor &other) {
    if (this != &other) {
        this->ID = other.ID;
        this->hwnd = other.hwnd;
        this->x = other.x;
        this->y = other.y;
        this->w = other.w;
        this->h = other.h;
    }
    return *this;
}

Actor::~Actor() {}

std::ostream& operator<<(std::ostream& os, const Actor &) {
    os << "TODO";
    return os;
}

void Actor::init(HWND &hwnd, const UINT_PTR &ID,const std::string &name,const int &xPos,const int &yPos,const int &width,const int &height) {
    this->ID = ID;
    this->hwnd = hwnd;
    this->name = name;
    this->x = xPos;
    this->y = yPos;
    this->w = width;
    this->h = height;
}

void Actor::setPos(const int &newX, const int &newY) {
    x = newX;
    y = newY;
    // if (hwnd != 0) // ?
    SetWindowPos(hwnd, NULL, x, y, w, h, SWP_NOZORDER);
}

WINBOOL Actor::window(const int &nCmdShow) {
    return ShowWindow(hwnd, nCmdShow);
// SW_HIDE                          Hides the window and activates another window.
// SW_SHOWNORMAL SW_NORMAL          Activates and displays a window. If the window is minimized, maximized, or arranged, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time.
// SW_SHOWMINIMIZED                 Activates the window and displays it as a minimized window.
// SW_SHOWMAXIMIZED SW_MAXIMIZE     Activates the window and displays it as a maximized window.
// SW_SHOWNOACTIVATE                Displays a window in its most recent size and position. This value is similar to SW_SHOWNORMAL, except that the window is not activated.
// SW_SHOW                          Activates the window and displays it in its current size and position.
// SW_MINIMIZE                      Minimizes the specified window and activates the next top-level window in the Z order.
// SW_SHOWMINNOACTIVE               Displays the window as a minimized window. This value is similar to SW_SHOWMINIMIZED, except the window is not activated.
// SW_SHOWNA                        Displays the window in its current size and position. This value is similar to SW_SHOW, except that the window is not activated.
// SW_RESTORE                       Activates and displays the window. If the window is minimized, maximized, or arranged, the system restores it to its original size and position. An application should specify this flag when restoring a minimized window.
// SW_SHOWDEFAULT                   Sets the show state based on the SW_ value specified in the STARTUPINFO structure passed to the CreateProcess function by the program that started the application.
// SW_FORCEMINIMIZE                 Minimizes a window, even if the thread that owns the window is not responding. This flag should only be used when minimizing windows from a different thread.
}