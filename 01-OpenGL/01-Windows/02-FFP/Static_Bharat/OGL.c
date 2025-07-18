// win32 headers
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES (1)
#include <math.h>
// custome header files
#include "OGL.h"

// OpenGL related header files
#include <gl/GL.h>
#include <gl/GLU.h>

// OpenGL related libraries
#pragma comment(lib, "opengl32.lib") // Import library
#pragma comment(lib, "glu32.lib") // Import library

// OpenGL related global variables
HDC ghdc = NULL;   // handle to device context
HGLRC ghrc = NULL; // handle to graphics library rendering context

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global macro
#define WIN_WIDTH  (800)
#define WIN_HEIGHT (600)


// global variable declarations
// variables related to fullscreen
BOOL gbFullScreen = FALSE;
HWND ghwnd = NULL;
DWORD dwStyle; // could have been local static
WINDOWPLACEMENT wpPrev;

//variables related to fileIO
char gszLogFileName[] = "Log.txt";
FILE *gpFile = NULL;

// active window related variable
BOOL gbActiveWindow = FALSE;

// esc key related variable
BOOL gbEscKeyIsPressed = FALSE;

// entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpszCmdLine, int iCmdShow)
{

    // function declarations
    int initialise(void);
    void display(void);
    void uninitialise(void);
    void update(void);
    void ToggleFullScreen(void);

    // variable declaration
    WNDCLASSEX wndclass;
    HWND hwnd;
    MSG msg;
    TCHAR szAppName[] = TEXT("RTR6");
    BOOL bDone = FALSE;
    //MONITORINFO mi;

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
    wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
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
                        GetSystemMetrics(SM_CXSCREEN)/2 - WIN_WIDTH/2,
                        GetSystemMetrics(SM_CYSCREEN)/2 - WIN_HEIGHT/2, 
                        WIN_WIDTH, 
                        WIN_HEIGHT, 
                        NULL, 
                        NULL, 
                        hInstance, 
                        NULL);

    ghwnd = hwnd;

    // show window
    ShowWindow(hwnd, iCmdShow);

    // paint background
    UpdateWindow(hwnd);

    // initialise
    int result = initialise();

    if (result != 0)
    {
        fprintf(gpFile, "Initialise function failed");
        DestroyWindow(hwnd);
        hwnd = NULL;
    }
    else
    {
        fprintf(gpFile, "Initialise function completed successfully");
    }

    
    // set this window as foreground and active window
    SetForegroundWindow(hwnd);
    SetFocus(hwnd);
    ToggleFullScreen();

    //game loop
    while(bDone == FALSE)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                bDone = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            if(gbActiveWindow == TRUE)
            {
                if(gbEscKeyIsPressed == TRUE)
                {
                    bDone = TRUE;
                }
                // render 
                display();

                // update
                update();
            }
        }
    }

    // uninitialise
    uninitialise();

    return (int)msg.wParam;
}

// callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // function declarations
    void ToggleFullScreen(void);
    void resize(int width, int height);
    void uninitialise(void);

    //code 
    switch (iMsg)
    {
    
    case WM_CREATE:
        ZeroMemory((void *)&wpPrev, sizeof(WINDOWPLACEMENT));
        wpPrev.length = sizeof(WINDOWPLACEMENT);
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
            default:
                break;
        }
        break;
    
    case WM_SETFOCUS:
        gbActiveWindow = TRUE;
        break;

    case WM_KILLFOCUS:
        gbActiveWindow = FALSE;
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_ERASEBKGND: // not mandatory, for smooth backgound 
        return (0);
    
    case WM_SIZE:
        resize(LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
            case VK_ESCAPE:
                gbEscKeyIsPressed = TRUE;
                break;

            default:
                break;   
        }
        break;

    case WM_CLOSE:
        uninitialise();
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
        //ShowCursor(FALSE);
    }
    else
    {
        SetWindowPlacement(ghwnd, &wpPrev);
        SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
        SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
        ShowCursor(TRUE);
    }    
}

int initialise(void)
{
    // function declarations
    void printGLInfo(void);
    void resize(int width, int height);

    // variable declaration
    PIXELFORMATDESCRIPTOR pfd;
    int iPixelFormatIndex = 0;

    //code
    // pixel format descriptor initialization
    ZeroMemory((void *)&pfd, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cRedBits = 8;
    pfd.cGreenBits = 8;
    pfd.cBlueBits = 8;
    pfd.cAlphaBits = 8;
    pfd.cDepthBits = 32;

    //get devixe context
    ghdc = GetDC(ghwnd);
    if (ghdc == NULL)
    {
        fprintf(gpFile, "GetDC() Function failed\n");
        return -1;
    }

    // get matching pixel format index using hdc and pfd
    iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);

    if(iPixelFormatIndex == 0)
    {
        fprintf(gpFile, "ChoosePixelFormat() Failed\n");
        return -2;
    }

    // select the pixel format of found index
    if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
    {
        fprintf(gpFile, "SetPixelFormat() function failed\n");
        return -3;
    }

    // create rendering context using hdc, pfd and chosen iPixelFormatIndex
    ghrc = wglCreateContext(ghdc); // wgl* are bridging API
    if (ghrc == NULL)
    {
        fprintf(gpFile, "wglCreateContext() failed");
        return -4;
    }

    // make this rendering conext as current context
    if (wglMakeCurrent(ghdc, ghrc) == FALSE)
    {
        fprintf(gpFile, "wglMakeCurrent() failed");
        return -5; 
    }

    // printf GL info
    printGLInfo();

    //from here onwards opengl code starts


    // depth related code
    glShadeModel(GL_SMOOTH); // tell opengl to use smoothness whilde shading
    glClearDepth(1.0f); // depth buffer to 1.0
    glEnable(GL_DEPTH_TEST); // enable depth test
    glDepthFunc(GL_LEQUAL); // pass the fragments whose values are less than are equal to glClear depth
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // whenever some shapes are deterioted due to prespective projection and depth, give them nicest appearance

    // tell openGl to choose the color to clear the screen
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // warm up resize
    resize(WIN_WIDTH, WIN_HEIGHT);

    return 0;
}

void printGLInfo(void)
{
    // code
    // printf opengl information
    fprintf(gpFile, "OPEN GL INFORMATION\n");
    fprintf(gpFile, "********************\n");
    fprintf(gpFile, "OpenGL Vendor : %s\n", glGetString(GL_VENDOR));
    fprintf(gpFile, "OpenGL Renderer : %s\n", glGetString(GL_RENDERER));
    fprintf(gpFile, "OpenGL Version : %s\n", glGetString(GL_VERSION));
    fprintf(gpFile, "********************\n");
}


void resize(int width, int height)
{
    //code
    // if height by accident becomes 0 or less then make height 1
    if (height <= 0)
    {
        height = 1;
    }
    // set the viewport
    glViewport(0, 0, (GLsizei)width, height);

    // set matrix projection mode
    glMatrixMode(GL_PROJECTION);

    //set to identity matrix
    glLoadIdentity();

    // do prespective projection
    // parameters 
    // 1. FOV-Y field of view Y
    // 2. Aspect Ration
    // 3. Near
    // 4. Far
    gluPerspective(45.0f, (GLdouble)width/(GLdouble)height, 0.1f, 100.0f);

    // // frustrun
    // GLdouble angle = 45.0f * (3.14f/180.0f);
    // GLdouble H = tan(angle/2.0)*(0.1f);
    // GLdouble W = H * ((GLdouble)width/(GLdouble)height);
    // glFrustum(-W, W, -H, H, 0.1, 100.0f);

}

void display(void)
{
    // function declaratiion
    void drawBharat(void);
    //code
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set matrix model view mode
    glMatrixMode(GL_MODELVIEW);

    // set  to identity matrix
    glLoadIdentity();

    // trasform drawing , push it forward
    glTranslatef(0.0f, 0.0f, -3.0f);
    
    // draw the bharat
    drawBharat();
    

    SwapBuffers(ghdc);
}

void update(void)
{
    //code
}
void uninitialise(void)
{
    // function declaration 
    void ToggleFullScreen(void);

    //code
    // if exiting fullscreen restore to normal
    if (gbFullScreen == TRUE)
    {
        ToggleFullScreen();
        gbFullScreen = FALSE;
    }

    //make hdc as current conext by releasing releasing renderring context as current context
    if (wglGetCurrentContext() == ghrc)
    {
        wglMakeCurrent(NULL, NULL);
    }

    // delete the renderring context
    if (ghrc)
    {
        wglDeleteContext(ghrc);
        ghrc = NULL;
    }

    //release the dc
    if (ghdc)
    {
        ReleaseDC(ghwnd, ghdc);
    }

    if(ghwnd)
    {
        DestroyWindow(ghwnd);
        ghwnd = NULL;
    }

    // close the log file
    if (gpFile)
    {
        fprintf(gpFile,"Program terminated Successfully\n");
        fclose(gpFile);
        gpFile = NULL;
    }
}

#define FONT_WIDTH (0.4f)
#define FONT_HEIGHT (0.6f)
#define THICKNESS (0.3f * FONT_HEIGHT)
#define THICKNESS (0.3f * FONT_HEIGHT)
void drawB(void)
{
    // upper part fix color
    glColor3f(1.0f, 0.549f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS, FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT - (THICKNESS * 0.8f), 0);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
    glEnd();

    // upper part color gradiant

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.549f, 0.0f);
        glVertex3f(FONT_WIDTH - THICKNESS, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(FONT_WIDTH, (THICKNESS * 0.7), 0);
        glVertex3f(FONT_WIDTH - THICKNESS, 0.0f, 0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.549f, 0.0f);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, FONT_HEIGHT - THICKNESS, 0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, THICKNESS/2.0f, 0);
    glEnd();

    // lower part, color gradiant
    // right
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(FONT_WIDTH - THICKNESS, 0.0f, 0);
        glVertex3f(FONT_WIDTH, -(THICKNESS * 0.7), 0);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(FONT_WIDTH, -(FONT_HEIGHT - THICKNESS), 0);
        glVertex3f(FONT_WIDTH - THICKNESS, -(FONT_HEIGHT - THICKNESS), 0);
    glEnd();
    // left
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, -THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, -THICKNESS/2.0f, 0);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, -(FONT_HEIGHT - THICKNESS), 0);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, -(FONT_HEIGHT - THICKNESS), 0);
    glEnd();

    // lower part fix color
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS, -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH, -(FONT_HEIGHT - (THICKNESS * 0.8f)), 0);
        glVertex3f(FONT_WIDTH, -(FONT_HEIGHT - THICKNESS), 0);
        glVertex3f(-FONT_WIDTH, -(FONT_HEIGHT - THICKNESS), 0);
    glEnd();

    // middle line fix color
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1), THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - THICKNESS, THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - THICKNESS, -THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1), -THICKNESS/2.0f, 0);
    glEnd();


}

void drawH(void)
{
    // upper part fix color
    // left
    glColor3f(1.0f, 0.549f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH), FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH), FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
    glEnd();
    // right
    glColor3f(1.0f, 0.549f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
    glEnd();

    // uppere part color gradiant
    // left
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.549f, 0.0f);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, FONT_HEIGHT - THICKNESS, 0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, THICKNESS/2.0f, 0);
    glEnd();
    // right
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.549f, 0.0f);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS, FONT_HEIGHT - THICKNESS, 0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS, THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, THICKNESS/2.0f, 0);
    glEnd();

    
    // lower part color gradiant
    // left
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, -THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, -THICKNESS/2.0f, 0);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();
    // right
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, -THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS, -THICKNESS/2.0f, 0);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS, -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    // lower part fix color
    //left
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH), -FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH),-FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();
    // right
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(FONT_WIDTH, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    // middle line fix color
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1), THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1), THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1), -THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1), -THICKNESS/2.0f, 0);
    glEnd();

}

void drawA(void)
{
    // upper part fix color
    // left
    glColor3f(1.0f, 0.549f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-THICKNESS/2.0f - (FONT_WIDTH*0.1), FONT_HEIGHT, 0);
        glVertex3f(THICKNESS/2.0f + (FONT_WIDTH*0.1), FONT_HEIGHT, 0);
        glVertex3f(THICKNESS/2.0f + (FONT_WIDTH*0.1), FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-THICKNESS/2.0f - (FONT_WIDTH*0.1), FONT_HEIGHT - THICKNESS, 0);
    glEnd();

    // upper part color gradiant
    // left
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.549f, 0.0f);
        glVertex3f(THICKNESS/2.0f, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-THICKNESS/2.0f, FONT_HEIGHT - THICKNESS, 0);

        // center
       glColor3f(1.0f, 1.0f, 1.0f);
       glVertex3f(-FONT_WIDTH + THICKNESS, 0.0f, 0);
       glVertex3f(-FONT_WIDTH + (1.9f *THICKNESS), 0.0f, 0);
    glEnd();

    // Right
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.549f, 0.0f);
        glVertex3f(-THICKNESS/2.0f, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(+THICKNESS/2.0f, FONT_HEIGHT - THICKNESS, 0);

        // center
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(FONT_WIDTH - THICKNESS, 0.0f, 0);
        glVertex3f(FONT_WIDTH - (1.9f *THICKNESS), 0.0f, 0);
    glEnd();

    // lower part fix color
    //left
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH), -FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH),-FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();
    // right
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(FONT_WIDTH, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    // middle part white color
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH - THICKNESS, 0.0f, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS, 0.0f, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS*0.7f, -THICKNESS*0.9, 0);
        glVertex3f(FONT_WIDTH - THICKNESS*0.7f, -THICKNESS*0.9, 0);
    glEnd();

    // lower part color gradiant
    // left
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH + THICKNESS*0.7f + THICKNESS, -THICKNESS*0.9, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS*0.7f, -THICKNESS*0.9, 0);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH*0.09), - FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS*1.2, - FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    // right
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH - THICKNESS*0.7f - THICKNESS, -THICKNESS*0.9, 0);
        glVertex3f(FONT_WIDTH - THICKNESS*0.7f, -THICKNESS*0.9, 0);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH*0.09), - FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(FONT_WIDTH - THICKNESS*1.2, - FONT_HEIGHT + THICKNESS, 0);
    glEnd();
}

void drawR(void)
{

    // middle line fix color
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1), THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - (1.2f * THICKNESS), THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - (1.2f * THICKNESS), -THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1), -THICKNESS/2.0f, 0);
    glEnd();

    // upper part fix color
    glColor3f(1.0f, 0.549f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.3, FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
    glEnd();
    //rpper right vertical line    
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.549f, 0.0f);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS*1.2f, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS, FONT_HEIGHT*0.5f, 0);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, FONT_HEIGHT*0.5f, 0);
    glEnd();

    // upper part color gradiant
    // left
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.549f, 0.0f);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, FONT_HEIGHT - THICKNESS, 0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, THICKNESS/2.0f, 0);
    glEnd();

    // right
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.549f, 0.0f);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, FONT_HEIGHT*0.5f, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS, FONT_HEIGHT*0.5f, 0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(FONT_WIDTH - THICKNESS*1.2f - THICKNESS, THICKNESS*0.5, 0);
        glVertex3f(FONT_WIDTH - THICKNESS*1.2f, 0, 0);
    glEnd();

    // lower part color gradiant
    //left
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, -THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, -THICKNESS/2.0f, 0);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();
    //right
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH - THICKNESS*1.2f - THICKNESS, -THICKNESS*0.5, 0);
        glVertex3f(FONT_WIDTH - THICKNESS*1.2f, -THICKNESS*0.5, 0);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH*0.09), - FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(FONT_WIDTH - THICKNESS*1.2, - FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    //lower part fix colors
    //left
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH), -FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH),-FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();
    // right
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(FONT_WIDTH, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();


}

void drawT(void)
{
    // upper part fix color
    //right
    glColor3f(1.0f, 0.549f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS, FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS, FONT_HEIGHT - 1.3f*THICKNESS, 0);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT - 1.3f*THICKNESS, 0);
    glEnd();
    // left
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS, FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS, FONT_HEIGHT - 1.3f*THICKNESS, 0);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT - 1.3f*THICKNESS, 0);
    glEnd();
    // middle horizontal line
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
    glEnd();

    // upper part color gradiant
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.549f, 0.0f);
        glVertex3f(THICKNESS*0.5f, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-THICKNESS*0.5f, FONT_HEIGHT - THICKNESS, 0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-THICKNESS*0.5f, 0, 0);
        glVertex3f(THICKNESS*0.5f, 0, 0);
    glEnd();

    //lower part color gradiant
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-THICKNESS*0.5f, 0, 0);
        glVertex3f(THICKNESS*0.5f, 0, 0);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(THICKNESS*0.5f, -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-THICKNESS*0.5f, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    //lower part fix color
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-THICKNESS*0.7f, -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(THICKNESS*0.7f, -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(THICKNESS*0.7f, -FONT_HEIGHT, 0);
        glVertex3f(-THICKNESS*0.7f, -FONT_HEIGHT, 0);
    glEnd();


}

void drawBharat(void)
{
    // variable declaration
    float translateStart = -2.0f;
    glScalef(0.5f, 0.5f, 1.0f);

    glPushMatrix();
    glTranslatef(translateStart, 0.0f, 0.0f);
    drawB();
    glPopMatrix();

    glPushMatrix();
    translateStart += FONT_WIDTH * 2.1f;
    glTranslatef(translateStart, 0.0f, 0.0f);
    drawH();
    glPopMatrix();

    glPushMatrix();
    translateStart += FONT_WIDTH * 2.1f;
    glTranslatef(translateStart, 0.0f, 0.0f);
    drawA();
    glPopMatrix();

    glPushMatrix();
    translateStart += FONT_WIDTH * 2.1f;
    glTranslatef(translateStart, 0.0f, 0.0f);
    drawR();
    glPopMatrix();

    glPushMatrix();
    translateStart += FONT_WIDTH * 2.1f;
    glTranslatef(translateStart, 0.0f, 0.0f);
    drawA();
    glPopMatrix();

    glPushMatrix();
    translateStart += FONT_WIDTH * 2.1f;
    glTranslatef(translateStart, 0.0f, 0.0f);
    drawT();
    glPopMatrix();
}