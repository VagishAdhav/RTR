// win32 headers
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
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
BOOL gbActiveWindow = TRUE;

// solar system related variables
float year = 0;
float date = 0;
float moonRotation = 0.0f;
GLUquadric *quadric = NULL;

// esc key related variable
BOOL gbEscKeyIsPressed = FALSE;

// texture related global variables
GLuint textureEarth;
GLuint textureMoon;
GLuint textureSun;

// light related variables
GLfloat lightAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat lightDiffuse[] = {1.0f, 1.0f, 0.0f, 1.0f};
GLfloat lightPosition[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

GLfloat EarthDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };  
GLfloat EarthSpecular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat EarthShininess[] = { 32.0f };
GLfloat SunEmission[] = { 1.0f, 1.0f, 0.0f, 1.0f };  // Yellow 
GLfloat EarthEmission[] = { 0.0f, 0.0f, 0.0f, 1.0f };  // Yellow 

// camera rotation
BOOL topView = FALSE;


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
    //ToggleFullScreen();


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

            case 'T':
            case 't':
                topView = !topView;
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
    BOOL loadGLTexture(GLuint *texture, TCHAR imageResourceID[]);

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

    // load textures
    if (loadGLTexture(&textureEarth, MAKEINTRESOURCE(ID_BITMAP_EARTH)) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_EARTH\n");
        return -6;
    }

    if (loadGLTexture(&textureMoon, MAKEINTRESOURCE(ID_BITMAP_MOON)) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_MOON\n");
        return -7;
    }

    if (loadGLTexture(&textureSun, MAKEINTRESOURCE(ID_BITMAP_SUN)) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_SUN\n");
        return -8;
    }

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    // initialise quadric
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE); // Enable texture capability


    //Light configuration
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    glEnable(GL_LIGHT0);
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

BOOL loadGLTexture(GLuint *texture, TCHAR imageResourceID[])
{
    //variable declarations
    HBITMAP hBitmap = NULL;
    BITMAP bmp;
    BOOL bResult = FALSE;

    //code
    //load the bitmap as image
    hBitmap = LoadImage(GetModuleHandle(NULL), imageResourceID, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
    if (hBitmap)
    {
        bResult = TRUE;
        // get bitmap structure for the loaded bitmap image
        GetObject(hBitmap, sizeof(BITMAP), &bmp);
        // generate OpenGL texture object
        glGenTextures(1, texture);
        // bind to newly created texture object
        glBindTexture(GL_TEXTURE_2D, *texture);
        // unpack the image in memory for faster loading
        glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
        // set texture parameter
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

        // 1, binding point
        // 2, no of components (3 colors)
        // 3. width
        // 4. height
        // 5. format of image bata
        // 6. type of bitmap data
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, (void *)bmp.bmBits);

        // unbind
        glBindTexture(GL_TEXTURE_2D, 0);

        // delete object
        DeleteObject(hBitmap);

        hBitmap = NULL;
    }

    return bResult;
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
    //code
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set matrix model view mode
    glMatrixMode(GL_MODELVIEW);

    // set  to identity matrix
    glLoadIdentity();

    //do View Transformation
    if (topView)
    {
        gluLookAt(0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    }
    else
    {
        gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    }


    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    // save above transformation into model view matrix stack
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glMaterialfv(GL_FRONT, GL_EMISSION, SunEmission);
    glBindTexture(GL_TEXTURE_2D, textureSun);

    glPushMatrix();

        // code for Sun
        // adjust the poles of sphere of Sun
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

        // set Sun's polygon properties
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        // sett Sun's color

        gluSphere(quadric, 0.75f, 30, 30);

        // pop the matrix as we need to go back to origin to draw earth
    glPopMatrix();

    // save above transformation into model view matrix stackm matrix is now at look at position
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, EarthEmission);


    glBindTexture(GL_TEXTURE_2D, textureEarth);
    glPushMatrix();
        // code for earth   

        // allow earth revolve around sun
        glRotatef((GLfloat)year, 0.0f, 1.0f, 0.0f);
        // allow earth move away from sun
        glTranslatef(-1.5f, 0.0f, 0.0f);
        // adjust the poles of sphere of Earth
        glRotatef(90.0f, -1.0f, 0.0f, 0.0f);

        // allow earth spin around itself
        glRotatef((GLfloat)date, 0.0f, 0.0f, 1.0f);

        // set Earth's polygon properties
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        //glColor3f(0.0f, 1.0f, 0.0f);
        // draw Earth
        gluSphere(quadric, 0.2f, 20, 20);


    glPopMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glBindTexture(GL_TEXTURE_2D, textureMoon);
    glPushMatrix();
        //code for moon
        // allow moon move away from sun to match earths 
        glRotatef((GLfloat)year, 0.0f, 1.0f, 0.0f);
        glTranslatef(-1.5f, 0.0f, 0.0f);
        // allow moon revolve around earth
        glRotatef(moonRotation, 0.0f, 1.0f, 0.0f);
        // allow moon move away from EARTH
        glTranslatef(0.35f, 0.0f, 0.0f);

        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

         // set Moon's polygon properties
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


        // draw moon
        gluSphere(quadric, 0.05f, 10, 10);
    glPopMatrix();

    SwapBuffers(ghdc);
}

void update(void)
{
    //code#
    moonRotation += 5.0f;
    if (moonRotation >= 360.0f)
    {
        moonRotation = 0.0f;
    }

    year += 0.4f;
    if (year >= 360.0f)
    {
        year = 0.0f;
    }

    
    date += 3.0f;
    if (date >= 360.0f)
    {
        date = 0.0f;
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