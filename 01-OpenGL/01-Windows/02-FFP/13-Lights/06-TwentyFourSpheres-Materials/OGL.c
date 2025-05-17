// win32 headers
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
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

// sphere system related variables
GLUquadric *quadric = NULL;

// esc key related variable
BOOL gbEscKeyIsPressed = FALSE;

// variables for 24 sphere application
BOOL bLight = FALSE;

GLfloat lightAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat lightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat lightPosition[] = {0.0f, 0.0f, 0.0f, 1.0f};

GLfloat lightModelAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat lightModelLocalViewer[] = {0.0f};

GLfloat angleForXRotation = 0.0f;
GLfloat angleForYRotation = 0.0f;
GLfloat angleForZRotation = 0.0f;

GLint keyPressed = -1;



// entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpszCmdLine, int iCmdShow)
{

    // function declarations
    int initialise(void);
    void display(void);
    void uninitialise(void);
    void update(void);

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

            case 'L':
            case 'l':
                if (bLight == FALSE)
                {
                    glEnable(GL_LIGHTING);
                    bLight = TRUE;
                }
                else
                {
                    glDisable(GL_LIGHTING);
                    bLight = FALSE;
                }
                break;

            case 'X':
            case 'x':
                keyPressed = 1;
                angleForXRotation = 0.0f; //resetting angle
                break;

            case 'Y':
            case 'y':
                keyPressed = 2;
                angleForYRotation = 0.0f; //resetting angle
                break;

            
            case 'Z':
            case 'z':
                keyPressed = 3;
                angleForZRotation = 0.0f; //resetting angle
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
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    // initialise quadric
    quadric = gluNewQuadric();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    // light configuration
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    
    glEnable(GL_LIGHT0);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightModelAmbient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, lightModelLocalViewer);
  
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

    // do orthographic projection
    if (width < height)
    {
        glOrtho( 
        0.0f,     // left
        15.5f,      // right
        (0.0f * ((GLfloat)height/(GLfloat)width)), // top
        (15.5f * ((GLfloat)height/(GLfloat)width)),  // bottom
        -10.0f,  // near
        10.0f);  // far
    }
    else
    {
        glOrtho( 
        (0.0f * ((GLfloat)width/(GLfloat)height)), //left
        (15.5f * ((GLfloat)width/(GLfloat)height)),  //right
        0.0f,   // top
        15.5f,    // bottom
        -10.0f,   // near
        10.0f);   // far
    }
}

void display(void)
{
    // function declaration
    void draw24Speheres(void);
    
    //code
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (keyPressed == 1)
    {
        glRotatef(angleForXRotation, 1.0f, 0.0f, 0.0f);
        lightPosition[2] = angleForXRotation;
    }
    else if (keyPressed == 2)
    {
        glRotatef(angleForYRotation, 0.0f, 1.0f, 0.0f);
        lightPosition[0] = angleForYRotation;
    }
    else if (keyPressed == 3)
    {
        glRotatef(angleForZRotation, 0.0f, 0.0f, 1.0f);
        lightPosition[1] = angleForZRotation;
    }

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);

    // draw 24 spheres
    draw24Speheres();  
    SwapBuffers(ghdc);
}

void draw24Speheres(void)
{
    // variable declarations
    GLfloat materialAmbient[4];
    GLfloat materialDiffuse[4];
    GLfloat materialSpecular[4];
    GLfloat materialShineness;

    //code

    // first sphere of first column - emerald
    materialAmbient[0] = 0.0215f; // r
    materialAmbient[1] = 0.1745f; // g
    materialAmbient[2] = 0.0215f; // b
    materialAmbient[3] = 1.0f;   // a
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.07568f; // r
    materialDiffuse[1] = 0.61424f; // g
    materialDiffuse[2] = 0.07568f; // b
    materialDiffuse[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);


    materialSpecular[0] = 0.633f;    // r
    materialSpecular[1] = 0.727811f; // g
    materialSpecular[2] = 0.633f;    // b
    materialSpecular[3] = 1.0f;     // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.6f * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(1.5f, 14.0f, 0.0f);

    gluSphere(quadric, 1.0f, 30, 30);

//----------------------------------------------------------------------
    // second sphere of first column jade
    materialAmbient[0] =  0.135f;  // r
    materialAmbient[1] =  0.2225f; // g
    materialAmbient[2] =  0.1575f; // b
    materialAmbient[3] =  1.0f;   // a
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.54f; // r
    materialDiffuse[1] = 0.89f; // g
    materialDiffuse[2] = 0.63f; // b
    materialDiffuse[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);


    materialSpecular[0] = 0.316228f; // r
    materialSpecular[1] = 0.316228f; // g
    materialSpecular[2] = 0.316228f; // b
    materialSpecular[3] = 1.0f;     // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.1f * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(1.5f, 11.5f, 0.0f);

    gluSphere(quadric, 1.0f, 30, 30);

//--------------------------------------------------------------

    // third sphere of first column - obsidian
    materialAmbient[0] = 0.05375f; // r
    materialAmbient[1] = 0.05f;    // g
    materialAmbient[2] = 0.06625f; // b
    materialAmbient[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.18275f; // r
    materialDiffuse[1] = 0.17f;    // g
    materialDiffuse[2] = 0.22525f; // b
    materialDiffuse[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);


    materialSpecular[0] = 0.332741f; // r
    materialSpecular[1] = 0.328634f; // g
    materialSpecular[2] = 0.346435f; // b
    materialSpecular[3] = 1.0f;     // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.3f * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(1.5f, 9.0f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);
//--------------------------------------------------------------
    // fourth sphere of first column - pearl
    materialAmbient[0] = 0.25f;    // r
    materialAmbient[1] = 0.20725f; // g
    materialAmbient[2] = 0.20725f; // b
    materialAmbient[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 1.0f;   // r
    materialDiffuse[1] = 0.829f; // g
    materialDiffuse[2] = 0.829f; // b
    materialDiffuse[3] = 1.0f;  // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);


    materialSpecular[0] = 0.296648f; // r
    materialSpecular[1] = 0.296648f; // g
    materialSpecular[2] = 0.296648f; // b
    materialSpecular[3] = 1.0f;     // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.088f * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(1.5f, 6.5f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

//--------------------------------------------------------------
    // fifth sphere of first column ruby
    materialAmbient[0] = 0.1745f;  // r
    materialAmbient[1] = 0.01175f; // g
    materialAmbient[2] = 0.01175f; // b
    materialAmbient[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.61424f; // r
    materialDiffuse[1] = 0.04136f; // g
    materialDiffuse[2] = 0.04136f; // b
    materialDiffuse[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);


    materialSpecular[0] = 0.727811f; // r
    materialSpecular[1] = 0.626959f; // g
    materialSpecular[2] = 0.626959f; // b
    materialSpecular[3] = 1.0f;     // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.6f * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(1.5f, 4.0f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);


//--------------------------------------------------------------
    // sixth sphere of first column turquoise
    materialAmbient[0] = 0.1f;     // r
    materialAmbient[1] = 0.18725f; // g
    materialAmbient[2] = 0.1745f;  // b
    materialAmbient[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.396f;   // r
    materialDiffuse[1] = 0.74151f; // g
    materialDiffuse[2] = 0.69102f; // b
    materialDiffuse[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);


    materialSpecular[0] = 0.297254f; // r
    materialSpecular[1] = 0.30829f;  // g
    materialSpecular[2] = 0.306678f; // b
    materialSpecular[3] = 1.0f;     // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.1f * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(1.5f, 1.5f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

// *******************************************************
//--------------------------------------------------------------
    // first sphere of second column brass
    materialAmbient[0] = 0.329412f; // r
    materialAmbient[1] = 0.223529f; // g
    materialAmbient[2] = 0.027451f; // b
    materialAmbient[3] = 1.0f;     // a
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.780392f; // r
    materialDiffuse[1] = 0.568627f; // g
    materialDiffuse[2] = 0.113725f; // b
    materialDiffuse[3] = 1.0f;     // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.992157f; // r
    materialSpecular[1] = 0.941176f; // g
    materialSpecular[2] = 0.807843f; // b
    materialSpecular[3] = 1.0f;     // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.21794872f * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(9.5f, 14.0f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);


//--------------------------------------------------------------
    // second sphere of second column bronze
    materialAmbient[0] = 0.2125f; // r
    materialAmbient[1] = 0.1275f; // g
    materialAmbient[2] = 0.054f;  // b
    materialAmbient[3] = 1.0f;   // a
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.714f;   // r
    materialDiffuse[1] = 0.4284f;  // g
    materialDiffuse[2] = 0.18144f; // b
    materialDiffuse[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.393548f; // r
    materialSpecular[1] = 0.271906f; // g
    materialSpecular[2] = 0.166721f; // b
    materialSpecular[3] = 1.0f;     // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.2f * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(9.5f, 11.5f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

//--------------------------------------------------------------
    // third sphere of second column
    materialAmbient[0] = 0.25f; // r
    materialAmbient[1] = 0.25f; // g
    materialAmbient[2] = 0.25f; // b
    materialAmbient[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.4f;  // r
    materialDiffuse[1] = 0.4f;  // g
    materialDiffuse[2] = 0.4f;  // b
    materialDiffuse[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);


    materialSpecular[0] = 0.774597f; // r
    materialSpecular[1] = 0.774597f; // g
    materialSpecular[2] = 0.774597f; // b
    materialSpecular[3] = 1.0f;     // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.6 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(9.5f, 9.0f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

//--------------------------------------------------------------
    // fourth sphere of second column
    materialAmbient[0] = 0.19125f; // r
    materialAmbient[1] = 0.0735f;  // g
    materialAmbient[2] = 0.0225f;  // b
    materialAmbient[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.7038f;  // r
    materialDiffuse[1] = 0.27048f; // g
    materialDiffuse[2] = 0.0828f;  // b
    materialDiffuse[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.256777f;  // r
    materialSpecular[1] = 0.137622f;  // g
    materialSpecular[2] = 0.086014f;  // b
    materialSpecular[3] = 1.0f;      // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.1 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(9.5f, 6.5f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

//--------------------------------------------------------------
    // fifth sphere of second column
    materialAmbient[0] = 0.24725f; // r
    materialAmbient[1] = 0.1995f;  // g
    materialAmbient[2] = 0.0745f;  // b
    materialAmbient[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.75164f; // r
    materialDiffuse[1] = 0.60648f; // g
    materialDiffuse[2] = 0.22648f; // b
    materialDiffuse[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.628281f;  // r
    materialSpecular[1] = 0.555802f;  // g
    materialSpecular[2] = 0.366065f;  // b
    materialSpecular[3] = 1.0f;      // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.4 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(9.5f, 4.0f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

//--------------------------------------------------------------
    // sixth sphere of second column
    materialAmbient[0] =0.19225f; // r
    materialAmbient[1] =0.19225f; // g
    materialAmbient[2] =0.19225f; // b
    materialAmbient[3] =1.0f;    // a
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.50754f; // r
    materialDiffuse[1] = 0.50754f; // g
    materialDiffuse[2] = 0.50754f; // b
    materialDiffuse[3] = 1.0f;    // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.508273f;  // r
    materialSpecular[1] = 0.508273f;  // g
    materialSpecular[2] = 0.508273f;  // b
    materialSpecular[3] = 1.0f;      // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.4 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(9.5f, 1.5f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

// *******************************************************
//--------------------------------------------------------------
    // first  sphere of third column
    materialAmbient[0] = 0.0f;  // r 
    materialAmbient[1] = 0.0f;  // g 
    materialAmbient[2] = 0.0f;  // b 
    materialAmbient[3] = 1.0f; // a 
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.01f; // r
    materialDiffuse[1] = 0.01f; // g
    materialDiffuse[2] = 0.01f; // b
    materialDiffuse[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.50f;  // r
    materialSpecular[1] = 0.50f;  // g
    materialSpecular[2] = 0.50f;  // b
    materialSpecular[3] = 1.0f;  // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.25f * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(17.5f, 14.0f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

//--------------------------------------------------------------
    // second  sphere of third column
    materialAmbient[0] = 0.0f;  // r 
    materialAmbient[1] = 0.1f;  // g 
    materialAmbient[2] = 0.06f; // b 
    materialAmbient[3] = 1.0f; // a 
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.0f;        // r
    materialDiffuse[1] = 0.50980392f; // g
    materialDiffuse[2] = 0.50980392f; // b
    materialDiffuse[3] = 1.0f;       // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.50196078f;  // r
    materialSpecular[1] = 0.50196078f;  // g
    materialSpecular[2] = 0.50196078f;  // b
    materialSpecular[3] = 1.0f;        // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.25f * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(17.5f, 11.5f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

    //--------------------------------------------------------------
    // third  sphere of third column
    materialAmbient[0] = 0.0f;  // r 
    materialAmbient[1] = 0.0f;  // g 
    materialAmbient[2] = 0.0f;  // b 
    materialAmbient[3] = 1.0f; // a 
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.1f;  // r
    materialDiffuse[1] = 0.35f; // g
    materialDiffuse[2] = 0.1f;  // b
    materialDiffuse[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.45f;  // r
    materialSpecular[1] = 0.55f;  // g
    materialSpecular[2] = 0.45f;  // b
    materialSpecular[3] = 1.0f;  // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.25 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(17.5f, 9.0f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

    //--------------------------------------------------------------
    // fourth  sphere of third column
    materialAmbient[0] = 0.0f; // r 
    materialAmbient[1] = 0.0f; // g 
    materialAmbient[2] = 0.0f; // b 
    materialAmbient[3] = 1.0f; // a 
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.5f;  // r
    materialDiffuse[1] = 0.0f; // g
    materialDiffuse[2] = 0.0f;  // b
    materialDiffuse[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.7f;   // r
    materialSpecular[1] = 0.6f;   // g
    materialSpecular[2] = 0.6f;   // b
    materialSpecular[3] = 1.0f;  // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.25 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(17.5f, 6.5f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

    //--------------------------------------------------------------
    // fifth sphere of third column
    materialAmbient[0] = 0.0f;  // r 
    materialAmbient[1] = 0.0f;  // g 
    materialAmbient[2] = 0.0f;  // b 
    materialAmbient[3] = 1.0f; // a 
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.55f; // r
    materialDiffuse[1] = 0.55f;// g
    materialDiffuse[2] = 0.55f; // b
    materialDiffuse[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.70f;  // r
    materialSpecular[1] = 0.70f;  // g
    materialSpecular[2] = 0.70f;  // b
    materialSpecular[3] = 1.0f;  // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.25 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(17.5f, 4.0f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

    //--------------------------------------------------------------
    // sixth sphere of third column
    materialAmbient[0] = 0.0f;  // r 
    materialAmbient[1] = 0.0f;  // g 
    materialAmbient[2] = 0.0f;  // b 
    materialAmbient[3] = 1.0f; // a 
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.5f;  // r
    materialDiffuse[1] = 0.5f; // g
    materialDiffuse[2] = 0.0f;  // b
    materialDiffuse[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.60f;  // r
    materialSpecular[1] = 0.60f;  // g
    materialSpecular[2] = 0.50f;  // b
    materialSpecular[3] = 1.0f;  // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.25 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(17.5f, 1.5f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);


// *******************************************************
//--------------------------------------------------------------
    // first sphere of fourth column
    materialAmbient[0] = 0.02;  // r 
    materialAmbient[1] = 0.02;  // g 
    materialAmbient[2] = 0.02;  // b 
    materialAmbient[3] = 1.0f; // a 
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.01;  // r
    materialDiffuse[1] = 0.01; // g
    materialDiffuse[2] = 0.01;  // b
    materialDiffuse[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.4;  // r
    materialSpecular[1] = 0.4;  // g
    materialSpecular[2] = 0.4;  // b
    materialSpecular[3] = 1.0f;  // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.078125 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(25.5f, 14.0f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

//--------------------------------------------------------------
    // second sphere of fourth column
    materialAmbient[0] = 0.0f;  // r 
    materialAmbient[1] = 0.05f;  // g 
    materialAmbient[2] = 0.05f;  // b 
    materialAmbient[3] = 1.0f; // a 
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.4f;  // r
    materialDiffuse[1] = 0.5f; // g
    materialDiffuse[2] = 0.5f;  // b
    materialDiffuse[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.04f;  // r
    materialSpecular[1] = 0.7;  // g
    materialSpecular[2] = 0.7;  // b
    materialSpecular[3] = 1.0f;  // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.078125 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(25.5f, 11.5f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

//--------------------------------------------------------------
    // third sphere of fourth column
    materialAmbient[0] = 0.0f;  // r 
    materialAmbient[1] = 0.05f;  // g 
    materialAmbient[2] = 0.0f;  // b 
    materialAmbient[3] = 1.0f; // a 
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.4f;  // r
    materialDiffuse[1] = 0.5f; // g
    materialDiffuse[2] = 0.4f;  // b
    materialDiffuse[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.04f;  // r
    materialSpecular[1] = 0.7;  // g
    materialSpecular[2] = 0.04;  // b
    materialSpecular[3] = 1.0f;  // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.078125 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(25.5f, 9.0f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

//--------------------------------------------------------------
    // fourth sphere of fourth column
    materialAmbient[0] = 0.05f;  // r 
    materialAmbient[1] = 0.0f;  // g 
    materialAmbient[2] = 0.0f;  // b 
    materialAmbient[3] = 1.0f; // a 
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.5f;  // r
    materialDiffuse[1] = 0.4f; // g
    materialDiffuse[2] = 0.4f;  // b
    materialDiffuse[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.7f;  // r
    materialSpecular[1] = 0.04;  // g
    materialSpecular[2] = 0.04;  // b
    materialSpecular[3] = 1.0f;  // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.078125 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(25.5f, 6.5f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

//--------------------------------------------------------------
    // fifth sphere of fourth column
    materialAmbient[0] = 0.05f;  // r 
    materialAmbient[1] = 0.05f;  // g 
    materialAmbient[2] = 0.05f;  // b 
    materialAmbient[3] = 1.0f; // a 
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.5f;  // r
    materialDiffuse[1] = 0.5f; // g
    materialDiffuse[2] = 0.5f;  // b
    materialDiffuse[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.7f;  // r
    materialSpecular[1] = 0.7f;  // g
    materialSpecular[2] = 0.7f;  // b
    materialSpecular[3] = 1.0f;  // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.078125 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(25.5f, 4.0f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);

//--------------------------------------------------------------
    // sixth sphere of fourth column
    materialAmbient[0] = 0.05f;  // r 
    materialAmbient[1] = 0.05f;  // g 
    materialAmbient[2] = 0.0f;  // b 
    materialAmbient[3] = 1.0f; // a 
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

    materialDiffuse[0] = 0.5f;  // r
    materialDiffuse[1] = 0.5f; // g
    materialDiffuse[2] = 0.4f;  // b
    materialDiffuse[3] = 1.0f; // a
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

    materialSpecular[0] = 0.7f;  // r
    materialSpecular[1] = 0.7f;  // g
    materialSpecular[2] = 0.04f;  // b
    materialSpecular[3] = 1.0f;  // a
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

    materialShineness = 0.078125 * 128;
    glMaterialf(GL_FRONT, GL_SHININESS, materialShineness);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(25.5f, 1.5f, 0.0f);
    gluSphere(quadric, 1.0f, 30, 30);
}

void update(void)
{
    //code
    
    // update X light angle
    angleForXRotation = angleForXRotation + 0.6f;
    if (angleForXRotation >= 360.0f)
    {
        angleForXRotation = angleForXRotation - 360.0f;
    }

    // update Y light angle
    angleForYRotation = angleForYRotation + 0.6f;
    if (angleForYRotation >= 360.0f)
    {
        angleForYRotation = angleForYRotation - 360.0f;
    }

    // update Z light angle
    angleForZRotation = angleForZRotation + 0.6f;
    if (angleForZRotation >= 360.0f)
    {
        angleForZRotation = angleForZRotation - 360.0f;
    }
}
void uninitialise(void)
{
    // function declaration 
    void ToggleFullScreen(void);

    //code

    if (quadric)
    {
        gluDeleteQuadric(quadric);
        quadric = NULL;
    }
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