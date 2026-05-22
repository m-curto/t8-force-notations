// g++ t8fn.cpp -o t8fn.exe -mwindows -static

#include "T8ForceNotations.hpp"

AppState app;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CREATE:
        wm_create(hwnd, app);
        PostMessage(hwnd, WM_APP+1,0,0);
        break;
    case WM_APP + 1:
        wm_app1(hwnd, app);
        break;
    case WM_PAINT:
        wm_paint(hwnd, app);
        break;
    case WM_COMMAND:
        wm_command(hwnd,wParam, app);
        break;
    case WM_DESTROY:
        wm_destroy(0);
        break;
    case WM_MEASUREITEM:
        return wm_measureitem(hwnd,wParam,lParam,app);
    case WM_DRAWITEM:
        return wm_drawitem(hwnd,wParam,lParam,app);
    default:
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    WNDCLASSW wc = {
        0,WindowProc,0,0,hInstance,0,LoadCursor(NULL, IDC_ARROW),
        (HBRUSH)(COLOR_BTNFACE + 1),0,L"window_class"
    };
 
    RegisterClassW(&wc);
 
    HWND hwnd = CreateWindowW(
        L"window_class",
        L"window_title",
        // WS_OVERLAPPEDWINDOW,
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        NULL, NULL, hInstance, NULL
    );

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    RECT rect;
    int width = 13;
    int height = 13;
    if(GetWindowRect(hwnd, &rect))
    {
        width = rect.right - rect.left;
        height = rect.bottom - rect.top;
    }
    std::cout << "window: " << width << "x" << height << std::endl;

    // SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)&app);

    MSG msg;
    while (GetMessageW(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return (int)msg.wParam;
}

/*
            // {
            //     MessageBoxW(hwnd,
            //     L"created",
            //     L"Succes", MB_OK | MB_ICONINFORMATION | MB_ICONINFORMATION);
            // }
            // else
                // MessageBoxW(hwnd,
                //     L"already exist/perm",
                //     L"Info", MB_OK | MB_ICONINFORMATION | MB_ICONWARNING);
*/
