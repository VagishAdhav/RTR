// win32 headers
#include <Windows.h>
#include "Window.h"
#include <stdio.h>
#include <stdlib.h>

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
// variables related to fullscreen
BOOL gbFullScreen = FALSE;
HWND ghwnd = NULL;
DWORD dwStyle; // could have been local static
WINDOWPLACEMENT wpPrev;

//variables related to fileIO
char gszLogFileName[] = "Log.txt";
FILE *gpFile = NULL;

// entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // variable declaration
    WNDCLASSEX wndclass;
    HWND hwnd;
    MSG msg;
    TCHAR szAppName[] = TEXT("RTR6");

    //code
    // create log file
    gpFile = fopen(gszLogFileName, "w");
    if (gpFile == NULL)
    {
        MessageBox(NULL, "Log File Creation Failed", "File IO Error", MB_OK);
        exit(0);
    }
    else
    {
        fprintf(gpFile, "Program Started Successfully\n");
    }
    
    // window class initialisation
    wndclass.cbSize = sizeof(WNDCLASSEX);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.hInstance = hInstance;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = szAppName;
    wndclass.lpszMenuName = NULL;
    wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

    // registration of window class
    RegisterClassEx(&wndclass);

    // create window
    hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, TEXT("Vagish Vishvanath Adhav"), 
                        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, 
                        CW_USEDEFAULT, 
                        CW_USEDEFAULT, 
                        CW_USEDEFAULT, 
                        CW_USEDEFAULT, 
                        NULL, 
                        NULL, 
                        hInstance, 
                        NULL);

    ghwnd = hwnd;

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

    // close the file
    if (gpFile)
    {
        fprintf(gpFile,"Program terminated Successfully\n");
        fclose(gpFile);
        gpFile = NULL;
    }
    return (int)msg.wParam;
}

// callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // function declarations
    void ToggleFullScreen(void);
    // variable declaration
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rc;
    TCHAR str[] = TEXT("Hello FULLSCREEN world !!");
    static int iPaintFlag = 0;
    COLORREF arrColor[8] = {RGB(0, 0, 0), RGB(255, 0, 0), RGB(0, 255, 0), RGB(0, 0, 255), RGB(255, 255, 0), RGB(0, 255, 255), RGB(255, 0, 255), RGB(255, 255, 255) };
    //code 
    switch (iMsg)
    {
    
    case WM_CREATE:
        ZeroMemory((void *)&wpPrev, sizeof(WINDOWPLACEMENT));
        wpPrev.length = sizeof(WINDOWPLACEMENT);
        break;

    case WM_PAINT:
        // WM_PAINT is posted messsage 
        // InvalidateRect(hwnd, NULL, TRUE) // third arguments here speifies repaint which results in WMPAINT message
        GetClientRect(hwnd, &rc);
        hdc = BeginPaint(hwnd, &ps);
        SetBkColor(hdc, RGB(0, 0, 0));
        SetTextColor(hdc, arrColor[iPaintFlag]);
        DrawText(hdc, str, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        EndPaint(hwnd, &ps);
        break;

    case WM_CHAR:
        switch(wParam)
        {
            case 'F':
            case 'f':
                if (gbFullScreen == FALSE)
                {
                    ToggleFullScreen();
                    gbFullScreen = TRUE;
                }
                else
                {
                    ToggleFullScreen();
                    gbFullScreen = FALSE;
                }
                break;

            case 'R':
            case 'r':
                iPaintFlag = 1;
                InvalidateRect(hwnd, NULL, TRUE);
                break;

            case 'G':
            case 'g':
                iPaintFlag = 2;
                InvalidateRect(hwnd, NULL, TRUE);
                break;

            case 'B':
            case 'b':
                iPaintFlag = 3;
                InvalidateRect(hwnd, NULL, TRUE);
                break;

            
            case 'Y':
            case 'y':
                iPaintFlag = 4;
                InvalidateRect(hwnd, NULL, TRUE);
                break;

            
            case 'C':
            case 'c':
                iPaintFlag = 5;
                InvalidateRect(hwnd, NULL, TRUE);
                break;

                        
            case 'M':
            case 'm':
                iPaintFlag = 6;
                InvalidateRect(hwnd, NULL, TRUE);
                break;


            case 'W':
            case 'w':
                iPaintFlag = 7;
                InvalidateRect(hwnd, NULL, TRUE);
                break;

            default:
                break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        break;
    }

    return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void ToggleFullScreen(void)
{
    // variable declaration
    MONITORINFO mi;
    //code 
    if (gbFullScreen == FALSE)
    {
        dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
        if (dwStyle & WS_OVERLAPPEDWINDOW)
        {
           ZeroMemory((void *)&mi, sizeof(MONITORINFO));
           mi.cbSize = sizeof(MONITORINFO);
           if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
           {
                SetWindowLong(ghwnd, GWL_STYLE, dwStyle & (~WS_OVERLAPPEDWINDOW));
                SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top,
                SWP_NOZORDER | SWP_FRAMECHANGED );
           }
        }
        //optional, hide cursor
        ShowCursor(FALSE);
    }
    else
    {
        SetWindowPlacement(ghwnd, &wpPrev);
        SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
        SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
        ShowCursor(TRUE);
    }    
}