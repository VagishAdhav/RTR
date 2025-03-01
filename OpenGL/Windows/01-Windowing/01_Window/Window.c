// win32 headers
#include <Windows.h>

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // variable declaration
    WNDCLASSEX wndclass;
    HWND hwnd;
    MSG msg;
    TCHAR szAppName[] = TEXT("RTR6");

    //code
    
    // window class initialisation
    wndclass.cbSize = sizeof(WNDCLASSEX);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.hInstance = hInstance;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = szAppName;
    wndclass.lpszMenuName = NULL;
    wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    // registration of window class
    RegisterClassEx(&wndclass);

    // create window
    hwnd = CreateWindow(szAppName, TEXT("Vagish Vishvanath Adhav"), 
                        WS_OVERLAPPEDWINDOW, 
                        CW_USEDEFAULT, 
                        CW_USEDEFAULT, 
                        CW_USEDEFAULT, 
                        CW_USEDEFAULT, 
                        NULL, 
                        NULL, 
                        hInstance, 
                        NULL);

    // show window
    ShowWindow(hwnd, iCmdShow);

    // paint background
    UpdateWindow(hwnd);

    // message loop
    /// generally for HW message
    //GetMessage return false for WM_QUIT
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        // dispatch message never returned till processed by WndProc
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

// callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    //code 
    switch (iMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        break;
    }

    return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}
