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

// media related includes and libraries
#include <Mmsystem.h>

#pragma comment(lib, "winmm.lib")  


// OpenGL related libraries
#pragma comment(lib, "opengl32.lib") // Import library
#pragma comment(lib, "glu32.lib") // Import library


// structure declarations

typedef struct
{
	float x;
	float y;
	float z;
}cord;

typedef struct
{
	float r;
	float g;
	float b;
}color;

typedef struct
{
	cord cords;
	color colors;
}point;

// OpenGL related global variables
HDC ghdc = NULL;   // handle to device context
HGLRC ghrc = NULL; // handle to graphics library rendering context

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global macro
#define WIN_WIDTH  (800)
#define WIN_HEIGHT (600)
#define FONT_WIDTH (0.4f)
#define FONT_HEIGHT (0.6f)
#define THICKNESS (0.3f * FONT_HEIGHT)
#define THICKNESS (0.3f * FONT_HEIGHT)

#define PLANE_PIVOT_X (9.0f)
#define PLANE_PIVOT_Y (7.0f)


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

// esc key related variable
BOOL gbEscKeyIsPressed = FALSE;

// transformation related variables
GLfloat gFontUpdateCnt = -5.0f;
GLfloat gPlaneRotationLeft = 0.0f;
GLfloat gPlaneRotationRight = -90.0f;
GLfloat gPlaneTranslationX = -PLANE_PIVOT_X;
GLfloat gCenterPlaneTranslationX = -PLANE_PIVOT_X - 5.5f;

// color
color cSaffron = {1.0f, 0.6f, 0.2f};
color cGreen = {0.0745f, 0.5333f, 0.0314f};
color cWhite = {1.0f, 1.0f, 1.0f};
color cGray= {0.5f, 0.5f, 0.5f};

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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // tell openGl to choose the color to clear the screen
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    	PlaySound(TEXT("MeraRangDe.wav"), NULL, SND_ASYNC);

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
    void drawPlane(color cSmoke);

    //code
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set matrix model view mode
    glMatrixMode(GL_MODELVIEW);

    // set  to identity matrix
    glLoadIdentity();

    // trasform drawing , push it forward
    glTranslatef(0.0f, 0.0f, -2.5f);
    
    // draw the Bharat
    drawBharat();

    // draw planes
    if (gFontUpdateCnt >= 4.0f)
    {
        glPushMatrix();
        glScalef(0.25f, 0.25f, 1.0f);
        glPushMatrix();
        // draw bottom plane
        if (gPlaneRotationLeft > -90.0f)
        {
             // rotate left part
            glTranslatef(-PLANE_PIVOT_X, -PLANE_PIVOT_Y, 0.0f);
            glRotatef(gPlaneRotationLeft, 0.0f, 0.0f, 1.0f);
            glTranslatef(-5.0f, 0.0f, 0.0f);
            drawPlane(cGreen);
        }
        else if (gPlaneTranslationX <= PLANE_PIVOT_X)
        {
            glTranslatef(gPlaneTranslationX, -2.0f, 0.0f);
            glRotatef(gPlaneRotationLeft, 0.0f, 0.0f, 1.0f);
            drawPlane(cGreen);
        }
        else
        {
            glTranslatef(PLANE_PIVOT_X, -PLANE_PIVOT_Y, 0.0f);
            glRotatef(gPlaneRotationRight, 0.0f, 0.0f, 1.0f);
            glTranslatef(-5.0f, 0.0f, 0.0f);
            drawPlane(cGreen);
        }
        glPopMatrix();
        glPushMatrix();
        // draw top plane
        GLfloat gTopPlaneRotationLeft = 180.0f - gPlaneRotationLeft;
        GLfloat gTopPlaneRotationRight = 180.0f - gPlaneRotationRight;
        if (gTopPlaneRotationLeft < 270.0f)
        {
             // rotate left part
            glTranslatef(-PLANE_PIVOT_X, PLANE_PIVOT_Y, 0.0f);
            glRotatef(gTopPlaneRotationLeft, 0.0f, 0.0f, 1.0f);
            glTranslatef(5.0f, 0.0f, 0.0f);
            drawPlane(cSaffron);
        }
        else if (gPlaneTranslationX <= PLANE_PIVOT_X)
        {
            glTranslatef(gPlaneTranslationX, 2.0f, 0.0f);
            glRotatef(gTopPlaneRotationLeft, 0.0f, 0.0f, 1.0f);
            drawPlane(cSaffron);
        }
        else
        {
            glTranslatef(PLANE_PIVOT_X, PLANE_PIVOT_Y, 0.0f);
            glRotatef(gTopPlaneRotationRight, 0.0f, 0.0f, 1.0f);
            glTranslatef(5.0f, 0.0f, 0.0f);
            drawPlane(cSaffron);
        }
        glPopMatrix();

        // draw middle plane
        glTranslatef(gCenterPlaneTranslationX, 0.0f, 0.0f);
        glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
        drawPlane(cWhite);
        glPopMatrix();
    }
    SwapBuffers(ghdc);
}

void update(void)
{
    //code
    if (gFontUpdateCnt < 4.0f)
    {
        gFontUpdateCnt = gFontUpdateCnt + 0.01f;
    }
    else if (gPlaneRotationLeft >= -90.0f)
    {
        gCenterPlaneTranslationX = gCenterPlaneTranslationX + 0.01f;
        gPlaneRotationLeft = gPlaneRotationLeft - 0.2f;
    }
    else if (gPlaneTranslationX < PLANE_PIVOT_X)
    {
        gCenterPlaneTranslationX = gCenterPlaneTranslationX + 0.02f;
        gPlaneTranslationX = gPlaneTranslationX + 0.02f;
    }
    else if (gPlaneRotationRight >= -220.0f)
    {
        gCenterPlaneTranslationX = gCenterPlaneTranslationX + 0.01f;
        gPlaneRotationRight = gPlaneRotationRight - 0.2f;
    }
    else
    {
        gCenterPlaneTranslationX = gCenterPlaneTranslationX + 0.01f;
    }


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

/**
 * @brief Plot quadratic bezier curve
 * 
 * @details This API calculates point on the curve using following linear interpolation formula for the given x and y coordinates 
 *          B(t) = (1 - t)Start Point + t(End Point)
 * 
 * @note OpenGL primtive must imitiated before calling this API
 * @param pStart Start point of curve 
 * @param pEnd  Start point of curve 
 * @param pControl Control point of the curve
 * @param fStep Step increment between t = 0 to 1
 * @return none
 */
void draw2DBezierQuadratic(point pStart, point pEnd, point pControl, float fStep)
{
	// variable declaration
	point pStartToControl, pControlToEnd, pFinal;

	//code 
	for (float t = 0; t <= 1; t+= fStep)
	{
		// calculate interpolation between pStart and PControl
		pStartToControl.cords.x = (1 - t)*pStart.cords.x + (t * pControl.cords.x);
		pStartToControl.cords.y = (1 - t)*pStart.cords.y + (t * pControl.cords.y);
		pStartToControl.colors.r = (1 - t)*pStart.colors.r + (t * pControl.colors.r);
		pStartToControl.colors.g = (1 - t)*pStart.colors.g + (t * pControl.colors.g);
		pStartToControl.colors.b = (1 - t)*pStart.colors.b + (t * pControl.colors.b);

		// calculate interpolation between Control and PEnd
		pControlToEnd.cords.x = (1 - t)*pControl.cords.x + (t * pEnd.cords.x);
		pControlToEnd.cords.y = (1 - t)*pControl.cords.y + (t * pEnd.cords.y);
		pControlToEnd.colors.r = (1 - t)*pControl.colors.r + (t * pEnd.colors.r);
		pControlToEnd.colors.g = (1 - t)*pControl.colors.g + (t * pEnd.colors.g);
		pControlToEnd.colors.b = (1 - t)*pControl.colors.b + (t * pEnd.colors.b);

		// calculate interpolation between above two interpolated points

		pFinal.cords.x = (1 - t)*pStartToControl.cords.x + (t * pControlToEnd.cords.x);
		pFinal.cords.y = (1 - t)*pStartToControl.cords.y + (t * pControlToEnd.cords.y);
		pFinal.colors.r = (1 - t)*pStartToControl.colors.r + (t * pControlToEnd.colors.r);
		pFinal.colors.g = (1 - t)*pStartToControl.colors.g + (t * pControlToEnd.colors.g);
		pFinal.colors.b = (1 - t)*pStartToControl.colors.b + (t * pControlToEnd.colors.b);

		// plot the final point

		glColor3f(pFinal.colors.r, pFinal.colors.g, pFinal.colors.b);
		glVertex3f(pFinal.cords.x, pFinal.cords.y, 0);
	}
}

/**
 * @brief Plots the ellipse over given range
 * @details This function implements following equation to plot ellipse on x,y plane
 * 			x = XOrigin + a cos(Angle)
 *  		y = YOrigin + b sin(Angle)
 * 			Where Angle varies from 0 to 2*PI
 * 			a = Radius along X 
 * 			b = Radius along Y
 * 			If a=b then this function plots the circle.
 * @note OpenGL primtive must imitiated before calling this API
 * @param faRadius Radius along X and Y Axis
 * @param pOrigin Coordinates of Origin
 * @param fStep Step increment to plot. Smaller the number smoother the plot
 * @param fStart Start radian of the ellipse
 * @param fEnd End radian of the ellipse
 */
void drawSemiEllipse(float faRadius[2], point pOrigin, float fStep, float fStart, float fEnd)
{
    for (float fAngle = fStart; fAngle <= fEnd; fAngle += fStep)
    {
        // triangle top
        glColor3f(pOrigin.colors.r, pOrigin.colors.g, pOrigin.colors.b);
        glVertex3f(pOrigin.cords.x, pOrigin.cords.y, 0.0f);

        float fX = pOrigin.cords.x + (faRadius[0] * cos(fAngle));
        float fY = pOrigin.cords.y + (faRadius[1] * sin(fAngle));

        glColor3f(pOrigin.colors.r, pOrigin.colors.g, pOrigin.colors.b);
        glVertex3f(fX, fY, 0.0f);
        fX = pOrigin.cords.x + (faRadius[0] * cos(fAngle + fStep));
        fY = pOrigin.cords.y + (faRadius[1] * sin(fAngle + fStep));

        glColor3f(pOrigin.colors.r, pOrigin.colors.g, pOrigin.colors.b);
        glVertex3f(fX, fY, 0.0f);
    }
}

void drawB(BOOL change_color)
{
    color cUpper = cGray;
    color cLower = cGray;;
    color cCenter = cGray;;
    if (change_color)
    {
        cUpper = cSaffron;
        cLower = cGreen;
        cCenter = cWhite;
    }

    // upper part fix color
    glColor3f(cUpper.r, cUpper.g, cUpper.b);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS, FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT - (THICKNESS * 0.8f), 0);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
    glEnd();

    // upper part color gradiant
    glBegin(GL_POLYGON);
        glColor3f(cUpper.r, cUpper.g, cUpper.b);
        glVertex3f(FONT_WIDTH - THICKNESS, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(FONT_WIDTH, (THICKNESS * 0.7), 0);
        glVertex3f(FONT_WIDTH - THICKNESS, 0.0f, 0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(cUpper.r, cUpper.g, cUpper.b);;
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, FONT_HEIGHT - THICKNESS, 0);
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, THICKNESS/2.0f, 0);
    glEnd();

    // lower part, color gradiant
    // right
    glBegin(GL_POLYGON);
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(FONT_WIDTH - THICKNESS, 0.0f, 0);
        glVertex3f(FONT_WIDTH, -(THICKNESS * 0.7), 0);
        glColor3f(cLower.r, cLower.g, cLower.b);
        glVertex3f(FONT_WIDTH, -(FONT_HEIGHT - THICKNESS), 0);
        glVertex3f(FONT_WIDTH - THICKNESS, -(FONT_HEIGHT - THICKNESS), 0);
    glEnd();

    // left
    glBegin(GL_POLYGON);
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, -THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, -THICKNESS/2.0f, 0);

        glColor3f(cLower.r, cLower.g, cLower.b);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, -(FONT_HEIGHT - THICKNESS), 0);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, -(FONT_HEIGHT - THICKNESS), 0);
    glEnd();

    // lower part fix color
    glColor3f(cLower.r, cLower.g, cLower.b);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS, -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH, -(FONT_HEIGHT - (THICKNESS * 0.8f)), 0);
        glVertex3f(FONT_WIDTH, -(FONT_HEIGHT - THICKNESS), 0);
        glVertex3f(-FONT_WIDTH, -(FONT_HEIGHT - THICKNESS), 0);
    glEnd();

    // middle line fix color
    glColor3f(cCenter.r, cCenter.g, cCenter.b);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1), THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - THICKNESS, THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - THICKNESS, -THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1), -THICKNESS/2.0f, 0);
    glEnd();
}

void drawH(BOOL change_color)
{
    color cUpper = cGray;
    color cLower = cGray;;
    color cCenter = cGray;;
    if (change_color)
    {
        cUpper = cSaffron;
        cLower = cGreen;
        cCenter = cWhite;
    }

    // upper part fix color
    // left
    glColor3f(cUpper.r, cUpper.g, cUpper.b);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH), FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH), FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
    glEnd();
    // right
    glColor3f(cUpper.r, cUpper.g, cUpper.b);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
    glEnd();

    // uppere part color gradiant
    // left
    glBegin(GL_POLYGON);
        glColor3f(cUpper.r, cUpper.g, cUpper.b);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, FONT_HEIGHT - THICKNESS, 0);
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, THICKNESS/2.0f, 0);
    glEnd();
    // right
    glBegin(GL_POLYGON);
        glColor3f(cUpper.r, cUpper.g, cUpper.b);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS, FONT_HEIGHT - THICKNESS, 0);
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS, THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, THICKNESS/2.0f, 0);
    glEnd();

    // lower part color gradiant
    // left
    glBegin(GL_POLYGON);
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, -THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, -THICKNESS/2.0f, 0);

        glColor3f(cLower.r, cLower.g, cLower.b);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();
    // right
    glBegin(GL_POLYGON);
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, -THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS, -THICKNESS/2.0f, 0);

        glColor3f(cLower.r, cLower.g, cLower.b);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS, -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    // lower part fix color
    //left
    glColor3f(cLower.r, cLower.g, cLower.b);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH), -FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH),-FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();
    // right
    glColor3f(cLower.r, cLower.g, cLower.b);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(FONT_WIDTH, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    // middle line fix color
    glColor3f(cCenter.r, cCenter.g, cCenter.b);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1), THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1), THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1), -THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1), -THICKNESS/2.0f, 0);
    glEnd();

}

void drawA(BOOL change_color)
{
    color cUpper = cGray;
    color cLower = cGray;;
    color cCenter = cGray;;
    if (change_color)
    {
        cUpper = cSaffron;
        cLower = cGreen;
        cCenter = cWhite;
    }

    // upper part fix color
    // left
    glColor3f(cUpper.r, cUpper.g, cUpper.b);
    glBegin(GL_POLYGON);
        glVertex3f(-THICKNESS/2.0f - (FONT_WIDTH*0.1), FONT_HEIGHT, 0);
        glVertex3f(THICKNESS/2.0f + (FONT_WIDTH*0.1), FONT_HEIGHT, 0);
        glVertex3f(THICKNESS/2.0f + (FONT_WIDTH*0.1), FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-THICKNESS/2.0f - (FONT_WIDTH*0.1), FONT_HEIGHT - THICKNESS, 0);
    glEnd();

    // upper part color gradiant
    // left
    glBegin(GL_POLYGON);
        glColor3f(cUpper.r, cUpper.g, cUpper.b);
        glVertex3f(THICKNESS/2.0f, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-THICKNESS/2.0f, FONT_HEIGHT - THICKNESS, 0);

        // center
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(-FONT_WIDTH + THICKNESS, 0.0f, 0);
        glVertex3f(-FONT_WIDTH + (1.9f *THICKNESS), 0.0f, 0);
    glEnd();

    // Right
    glBegin(GL_POLYGON);
        glColor3f(cUpper.r, cUpper.g, cUpper.b);
        glVertex3f(-THICKNESS/2.0f, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(+THICKNESS/2.0f, FONT_HEIGHT - THICKNESS, 0);

        // center
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(FONT_WIDTH - THICKNESS, 0.0f, 0);
        glVertex3f(FONT_WIDTH - (1.9f *THICKNESS), 0.0f, 0);
    glEnd();

    // lower part fix color
    //left
    glColor3f(cLower.r, cLower.g, cLower.b);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH), -FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH),-FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();
    // right
    glColor3f(cLower.r, cLower.g, cLower.b);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(FONT_WIDTH, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    // middle part white color
    glColor3f(cCenter.r, cCenter.g, cCenter.b);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH - THICKNESS, 0.0f, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS, 0.0f, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS*0.7f, -THICKNESS*0.9, 0);
        glVertex3f(FONT_WIDTH - THICKNESS*0.7f, -THICKNESS*0.9, 0);
    glEnd();

    // lower part color gradiant
    // left
    glColor3f(cCenter.r, cCenter.g, cCenter.b);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH + THICKNESS*0.7f + THICKNESS, -THICKNESS*0.9, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS*0.7f, -THICKNESS*0.9, 0);

        glColor3f(cLower.r, cLower.g, cLower.b);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH*0.09), - FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS*1.2, - FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    // right
    glColor3f(cCenter.r, cCenter.g, cCenter.b);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH - THICKNESS*0.7f - THICKNESS, -THICKNESS*0.9, 0);
        glVertex3f(FONT_WIDTH - THICKNESS*0.7f, -THICKNESS*0.9, 0);
        glColor3f(cLower.r, cLower.g, cLower.b);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH*0.09), - FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(FONT_WIDTH - THICKNESS*1.2, - FONT_HEIGHT + THICKNESS, 0);
    glEnd();
}

void drawR(BOOL change_color)
{
    color cUpper = cGray;
    color cLower = cGray;
    color cCenter = cGray;
    if (change_color)
    {
        cUpper = cSaffron;
        cLower = cGreen;
        cCenter = cWhite;
    }

    // middle line fix color
    glColor3f(cCenter.r, cCenter.g, cCenter.b);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1), THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - (1.2f * THICKNESS), THICKNESS/2.0f, 0);
        glVertex3f(FONT_WIDTH - (1.2f * THICKNESS), -THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1), -THICKNESS/2.0f, 0);
    glEnd();

    // upper part fix color
    glColor3f(cUpper.r, cUpper.g, cUpper.b);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.3, FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-FONT_WIDTH, FONT_HEIGHT - THICKNESS, 0);
    glEnd();

    //rpper right vertical line    
    glBegin(GL_POLYGON);
        glColor3f(cUpper.r, cUpper.g, cUpper.b);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS*1.2f, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS, FONT_HEIGHT*0.5f, 0);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, FONT_HEIGHT*0.5f, 0);
    glEnd();

    // upper part color gradiant
    // left
    glBegin(GL_POLYGON);
        glColor3f(cUpper.r, cUpper.g, cUpper.b);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, FONT_HEIGHT - THICKNESS, 0);
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, THICKNESS/2.0f, 0);
    glEnd();

    // right
    glBegin(GL_POLYGON);
        glColor3f(cUpper.r, cUpper.g, cUpper.b);
        glVertex3f(FONT_WIDTH - FONT_WIDTH * 0.1, FONT_HEIGHT*0.5f, 0);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH * 0.1) - THICKNESS, FONT_HEIGHT*0.5f, 0);
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(FONT_WIDTH - THICKNESS*1.2f - THICKNESS, THICKNESS*0.5, 0);
        glVertex3f(FONT_WIDTH - THICKNESS*1.2f, 0, 0);
    glEnd();

    // lower part color gradiant
    //left
    glBegin(GL_POLYGON);
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, -THICKNESS/2.0f, 0);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, -THICKNESS/2.0f, 0);

        glColor3f(cLower.r, cLower.g, cLower.b);
        glVertex3f(-FONT_WIDTH + (FONT_WIDTH * 0.1) + THICKNESS, -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-FONT_WIDTH + FONT_WIDTH * 0.1, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    //right
    glColor3f(cCenter.r, cCenter.g, cCenter.b);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH - THICKNESS*1.2f - THICKNESS, -THICKNESS*0.5, 0);
        glVertex3f(FONT_WIDTH - THICKNESS*1.2f, -THICKNESS*0.5, 0);
        glColor3f(cLower.r, cLower.g, cLower.b);
        glVertex3f(FONT_WIDTH - (FONT_WIDTH*0.09), - FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(FONT_WIDTH - THICKNESS*1.2, - FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    //lower part fix colors
    //left
    glColor3f(cLower.r, cLower.g, cLower.b);
    glBegin(GL_POLYGON);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH), -FONT_HEIGHT, 0);
        glVertex3f(-FONT_WIDTH + THICKNESS + (0.2 * FONT_WIDTH),-FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-FONT_WIDTH, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    // right
    glColor3f(cLower.r, cLower.g, cLower.b);
    glBegin(GL_POLYGON);
        glVertex3f(FONT_WIDTH, -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), -FONT_HEIGHT, 0);
        glVertex3f(FONT_WIDTH - THICKNESS - (0.2 * FONT_WIDTH), -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(FONT_WIDTH, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();
}

void drawT(BOOL change_color)
{
    color cUpper = cGray;
    color cLower = cGray;
    color cCenter = cGray;
    if (change_color)
    {
        cUpper = cSaffron;
        cLower = cGreen;
        cCenter = cWhite;
    }
    // upper part fix color
    //right
    glColor3f(cUpper.r, cUpper.g, cUpper.b);
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
        glColor3f(cUpper.r, cUpper.g, cUpper.b);
        glVertex3f(THICKNESS*0.5f, FONT_HEIGHT - THICKNESS, 0);
        glVertex3f(-THICKNESS*0.5f, FONT_HEIGHT - THICKNESS, 0);
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(-THICKNESS*0.5f, 0, 0);
        glVertex3f(THICKNESS*0.5f, 0, 0);
    glEnd();

    //lower part color gradiant
    glBegin(GL_POLYGON);
        glColor3f(cCenter.r, cCenter.g, cCenter.b);
        glVertex3f(-THICKNESS*0.5f, 0, 0);
        glVertex3f(THICKNESS*0.5f, 0, 0);
        glColor3f(cLower.r, cLower.g, cLower.b);
        glVertex3f(THICKNESS*0.5f, -FONT_HEIGHT + THICKNESS, 0);
        glVertex3f(-THICKNESS*0.5f, -FONT_HEIGHT + THICKNESS, 0);
    glEnd();

    //lower part fix color
    glColor3f(cLower.r, cLower.g, cLower.b);
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
    float translateOriginal = -2.0f;
    float tempX;
    static int cnt = 0;

    glScalef(0.5f, 0.5f, 1.0f);

    glPushMatrix();
    glTranslatef( min(translateOriginal, gFontUpdateCnt), 0.0f, 0.0f);
    drawB((gCenterPlaneTranslationX*0.3 > translateOriginal));
    glPopMatrix();
    cnt++;

    if (cnt >= 10)
    {
        tempX = gFontUpdateCnt + translateOriginal;
        translateOriginal += FONT_WIDTH * 2.1f;
        glPushMatrix();
        glTranslatef(min(tempX, translateOriginal), max(0.0f,-tempX) , 0.0f);
        drawH((gCenterPlaneTranslationX*0.28 > translateOriginal));
        glPopMatrix();
        cnt++;
    }

    if (cnt >= 20)
    {
        tempX = gFontUpdateCnt + translateOriginal;
        translateOriginal += FONT_WIDTH * 2.1f;
        glPushMatrix();
        glTranslatef(min(tempX, translateOriginal), min(0.0f,tempX) , 0.0f);
        drawA((gCenterPlaneTranslationX*0.26 > translateOriginal));
        glPopMatrix();
        cnt++;
    }

    if (cnt >= 30)
    {
        tempX = gFontUpdateCnt + translateOriginal;
        translateOriginal += FONT_WIDTH * 2.1f;
        glPushMatrix();
        glTranslatef(translateOriginal, min(0.0f,tempX), 0.0f);
        drawR((gCenterPlaneTranslationX*0.23 > translateOriginal));
        glPopMatrix();
        cnt++;
    }

    if (cnt >= 40)
    {
        tempX = gFontUpdateCnt + translateOriginal;
        translateOriginal += FONT_WIDTH * 2.1f;
        glPushMatrix();
        glTranslatef(max(translateOriginal, -tempX), max(0.0f, -tempX), 0.0f);
        drawA((gCenterPlaneTranslationX*0.20 > translateOriginal));
        glPopMatrix();
        cnt++;
    }

    if (cnt >= 500)
    {
        tempX = gFontUpdateCnt + translateOriginal;
        translateOriginal += FONT_WIDTH * 2.1f;
        glPushMatrix();
        glTranslatef(max(translateOriginal, -2.0f*gFontUpdateCnt), 0.0f, 0.0f);
        drawT((gCenterPlaneTranslationX*0.28 > translateOriginal));
        glPopMatrix();
    }
}

#define PLANE_BODY_WIDTH (0.25f)
#define PLANE_BODY_HEGHT  (0.7f)
#define PLANE_NOSE_HEIGHT (PLANE_BODY_HEGHT + 0.4f)
#define PLANE_WINGS_WIDTH (1.0f)

void drawPlane(color cSmoke)
{
    // variable declaration
    point pStart, pEnd, pControl, pTemp;
    color cNoseColor = {0.275f, 0.510f, 0.706f};
    color cBodyColorBase = {0.000f, 0.545f, 0.545f};
    color cTailColor = {0.561, 0.737, 0.561};
    color cShadowColor = {0.000, 0.502, 0.502};
    color cOrange = {1.0f, 0.6f, 0.2f};
    color cGreen = {0.0745f, 0.5333f, 0.0314f};
    color cWhite = {1.0f, 1.0f, 1.0f};

    // draw  nose
    glBegin(GL_POLYGON);

        //left
        pStart.cords.x = -PLANE_BODY_WIDTH;
        pStart.cords.y = PLANE_BODY_HEGHT;
        pStart.cords.z = 0.0f;
        pStart.colors = cNoseColor;

        pEnd.cords.x = 0.0f;
        pEnd.cords.y = PLANE_NOSE_HEIGHT;
        pEnd.cords.z = 0.0f;    
        pEnd.colors = cNoseColor;

        pControl.cords.x = -PLANE_BODY_WIDTH;
        pControl.cords.y = PLANE_BODY_HEGHT + PLANE_BODY_WIDTH;
        pControl.cords.z = 0.0f;
        pControl.colors = cNoseColor;     
        draw2DBezierQuadratic(pStart, pEnd, pControl, 0.01);

        // right
        pTemp = pStart;
        pStart = pEnd;
        pEnd = pTemp;
        pEnd.cords.x = -pEnd.cords.x;
        pControl.cords.x = -pControl.cords.x ;
        draw2DBezierQuadratic(pStart, pEnd, pControl, 0.01);

    glEnd();

    // draw central square


    glBegin(GL_POLYGON);
        pStart.colors = cBodyColorBase;
        pEnd.colors = cBodyColorBase;
        pControl.colors = cBodyColorBase;
        pStart = pEnd;

        pControl.cords.x = 0.0f;
        pControl.cords.y = PLANE_BODY_HEGHT + (PLANE_BODY_WIDTH*0.33f);
        pEnd.cords.x = -pEnd.cords.x;
        // upper curve
        draw2DBezierQuadratic(pStart, pEnd, pControl, 0.01);
        // rest cords
        glVertex3f(-PLANE_BODY_WIDTH, PLANE_BODY_HEGHT, 0.0f);
        glVertex3f(-PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT, 0.0f);
        glVertex3f(PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT, 0.0f);
    glEnd();

    // draw Shadow

    glBegin(GL_POLYGON);

        //upper left
        pStart.cords.x = -PLANE_BODY_WIDTH*0.8;
        pStart.cords.y = PLANE_BODY_HEGHT*0.5;
        pStart.cords.z = 0.0f;
        pStart.colors = cShadowColor;

        pEnd.cords.x = 0.0f;
        pEnd.cords.y = PLANE_BODY_HEGHT*1.05f;
        pEnd.cords.z = 0.0f;    
        pEnd.colors = cShadowColor;

        pControl.cords.x = -PLANE_BODY_WIDTH*0.8;
        pControl.cords.y = PLANE_BODY_HEGHT*1.1f;
        pControl.cords.z = 0.0f;
        pControl.colors = cShadowColor;     
        draw2DBezierQuadratic(pStart, pEnd, pControl, 0.01);


        // upper right
        pTemp = pStart;
        pStart = pEnd;
        pEnd = pTemp;
        pEnd.cords.x = -pEnd.cords.x;
        pControl.cords.x = -pControl.cords.x ;
        draw2DBezierQuadratic(pStart, pEnd, pControl, 0.01);

        // lower 
        glVertex3f(pEnd.cords.x, -PLANE_BODY_HEGHT, 0.0f);
        glVertex3f(-PLANE_BODY_WIDTH*0.8f, -PLANE_BODY_HEGHT, 0.0f);

    glEnd();



    //elipse on the plane
    float faRadius[2] = {PLANE_BODY_WIDTH*0.8, PLANE_BODY_HEGHT*0.4};
    point pOrigin = {.colors = cNoseColor, .cords.x = 0.0f, .cords.y = 0.3f, .cords.z = 0.0f};
    glBegin(GL_TRIANGLE_FAN);
        drawSemiEllipse(faRadius, pOrigin, 0.1f, 0.0f, 2.0f * M_PI);
    glEnd();

    // draw tail
    //left    
    pStart.cords.x = 0.0f;
    pStart.cords.y = -PLANE_BODY_HEGHT - 0.4f;
    pStart.cords.z = 0.0f;
    pStart.colors = cTailColor;

    pEnd.cords.x = 0.0f;
    pEnd.cords.y = -PLANE_BODY_HEGHT + 0.3f;
    pEnd.cords.z = 0.0f;
    pEnd.colors = cNoseColor;

    pControl.cords.x = -PLANE_BODY_WIDTH;
    pControl.cords.y = -PLANE_BODY_HEGHT + 0.3f;
    pControl.cords.z = 0.0f;
    pControl.colors = cNoseColor;

    glBegin(GL_POLYGON);
        draw2DBezierQuadratic(pStart, pEnd, pControl, 0.01);
    glEnd();

    // right
    pControl.cords.x = -pControl.cords.x;
    glBegin(GL_POLYGON);
        draw2DBezierQuadratic(pStart, pEnd, pControl, 0.01);
    glEnd();

    // draw Wings

    //left
    glColor3f(cTailColor.r, cTailColor.g, cTailColor.b);
    glBegin(GL_POLYGON);
        glVertex3f(-PLANE_BODY_WIDTH, PLANE_BODY_HEGHT*0.5f, 0.0f);
        glVertex3f(-PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.30f, 0.0f);
        glVertex3f(-PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
        glVertex3f(-PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
    glEnd();

    glColor3f(cBodyColorBase.r, cBodyColorBase.g, cBodyColorBase.b);
    glBegin(GL_POLYGON);
        glVertex3f(-PLANE_BODY_WIDTH, PLANE_BODY_HEGHT*0.45f, 0.0f);
        glVertex3f(-PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.35f, 0.0f);
        glVertex3f(-PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
        glVertex3f(-PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
    glEnd();


    glColor3f(cShadowColor.r, cShadowColor.g, cShadowColor.b);
    glBegin(GL_POLYGON);
        glVertex3f(-PLANE_BODY_WIDTH, PLANE_BODY_HEGHT*0.45f, 0.0f);
        glVertex3f(-PLANE_BODY_WIDTH - PLANE_WINGS_WIDTH*0.05f, PLANE_BODY_HEGHT*0.41f, 0.0f);
        glVertex3f(-PLANE_BODY_WIDTH - PLANE_WINGS_WIDTH*0.05f, -PLANE_BODY_HEGHT*0.5f, 0.0f);
        glVertex3f(-PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-PLANE_BODY_WIDTH,  -PLANE_BODY_HEGHT*0.27f, 0.0f);
        glVertex3f(-PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.27f, 0.0f);
        glVertex3f(-PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
        glVertex3f(-PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
    glEnd();

    // borders on left 
    glColor3f(cNoseColor.r, cNoseColor.g, cNoseColor.b);
    glBegin(GL_POLYGON);
        glVertex3f(-PLANE_BODY_WIDTH,  -PLANE_BODY_HEGHT*0.27f, 0.0f);
        glVertex3f(-PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.27f, 0.0f);
        glVertex3f(-PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.35f, 0.0f);
        glVertex3f(-PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT*0.35f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-PLANE_WINGS_WIDTH*0.5,  -PLANE_BODY_HEGHT*0.27f, 0.0f);
        glVertex3f(-PLANE_WINGS_WIDTH*0.55, -PLANE_BODY_HEGHT*0.27f, 0.0f);
        glVertex3f(-PLANE_WINGS_WIDTH*0.55, -PLANE_BODY_HEGHT*0.5f, 0.0f);
        glVertex3f(-PLANE_WINGS_WIDTH*0.5, -PLANE_BODY_HEGHT*0.5f, 0.0f);
    glEnd();

    // draw flag colored circle
    // orange 

    faRadius[0] = PLANE_WINGS_WIDTH * 0.1;
    faRadius[1] = PLANE_WINGS_WIDTH * 0.1;
    pOrigin.colors = cOrange;
    pOrigin.cords.x = -PLANE_WINGS_WIDTH * 0.5f;
    pOrigin.cords.y = -0.05f;
    pOrigin.cords.z = 0.0f;

    glBegin(GL_TRIANGLE_FAN);
        drawSemiEllipse(faRadius, pOrigin, 0.1f, 0.0f, 2.0f * M_PI);
    glEnd();

    faRadius[0] = faRadius[0] * 0.6f;
    faRadius[1] = faRadius[1] * 0.6f;
    pOrigin.colors = cWhite;

    glBegin(GL_TRIANGLE_FAN);
        drawSemiEllipse(faRadius, pOrigin, 0.1f, 0.0f, 2.0f * M_PI);
    glEnd();

    faRadius[0] = faRadius[0] * 0.6f;
    faRadius[1] = faRadius[1] * 0.6f;
    pOrigin.colors = cGreen;

    glBegin(GL_TRIANGLE_FAN);
        drawSemiEllipse(faRadius, pOrigin, 0.1f, 0.0f, 2.0f * M_PI);
    glEnd();

    // draw left missile
    glBegin(GL_POLYGON);

        pStart.cords.x = -PLANE_WINGS_WIDTH - (PLANE_WINGS_WIDTH*0.2f);
        pStart.cords.y = -PLANE_BODY_HEGHT*0.7f;
        pStart.cords.z = 0.0f;
        pStart.colors = cNoseColor;

        pEnd.cords.x = -PLANE_WINGS_WIDTH - (PLANE_WINGS_WIDTH*0.1f);
        pEnd.cords.y = PLANE_BODY_HEGHT*0.6f;
        pEnd.cords.z = 0.0f;    
        pEnd.colors = cShadowColor;

        pControl.cords.x = -PLANE_WINGS_WIDTH - (PLANE_WINGS_WIDTH*0.2f);
        pControl.cords.y = PLANE_BODY_HEGHT*0.5f;
        pControl.cords.z = 0.0f;
        pControl.colors = cNoseColor;     
        draw2DBezierQuadratic(pStart, pEnd, pControl, 0.01);
        pTemp = pStart;
        pStart = pEnd;
        pEnd = pTemp;
        pEnd.cords.x = -PLANE_WINGS_WIDTH;
        pControl.cords.x = -PLANE_WINGS_WIDTH;
        draw2DBezierQuadratic(pStart, pEnd, pControl, 0.01);

    glEnd();

    // right wing

    glColor3f(cTailColor.r, cTailColor.g, cTailColor.b);
    glBegin(GL_POLYGON);
        glVertex3f(PLANE_BODY_WIDTH, PLANE_BODY_HEGHT*0.5f, 0.0f);
        glVertex3f(PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.30f, 0.0f);
        glVertex3f(PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
        glVertex3f(PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
    glEnd();

    glColor3f(cBodyColorBase.r, cBodyColorBase.g, cBodyColorBase.b);
    glBegin(GL_POLYGON);
        glVertex3f(PLANE_BODY_WIDTH, PLANE_BODY_HEGHT*0.45f, 0.0f);
        glVertex3f(PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.35f, 0.0f);
        glVertex3f(PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
        glVertex3f(PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
    glEnd();


    glColor3f(cShadowColor.r, cShadowColor.g, cShadowColor.b);
    glBegin(GL_POLYGON);
        glVertex3f(PLANE_BODY_WIDTH, PLANE_BODY_HEGHT*0.45f, 0.0f);
        glVertex3f(PLANE_BODY_WIDTH + PLANE_WINGS_WIDTH*0.05f, PLANE_BODY_HEGHT*0.41f, 0.0f);
        glVertex3f(PLANE_BODY_WIDTH + PLANE_WINGS_WIDTH*0.05f, -PLANE_BODY_HEGHT*0.5f, 0.0f);
        glVertex3f(PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(PLANE_BODY_WIDTH,  -PLANE_BODY_HEGHT*0.27f, 0.0f);
        glVertex3f(PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.27f, 0.0f);
        glVertex3f(PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
        glVertex3f(PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT*0.5f, 0.0f);
    glEnd();

    // borders on right 
    glColor3f(cNoseColor.r, cNoseColor.g, cNoseColor.b);
    glBegin(GL_POLYGON);
        glVertex3f(PLANE_BODY_WIDTH,  -PLANE_BODY_HEGHT*0.27f, 0.0f);
        glVertex3f(PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.27f, 0.0f);
        glVertex3f(PLANE_WINGS_WIDTH, -PLANE_BODY_HEGHT*0.35f, 0.0f);
        glVertex3f(PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT*0.35f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(PLANE_WINGS_WIDTH*0.5,  -PLANE_BODY_HEGHT*0.27f, 0.0f);
        glVertex3f(PLANE_WINGS_WIDTH*0.55, -PLANE_BODY_HEGHT*0.27f, 0.0f);
        glVertex3f(PLANE_WINGS_WIDTH*0.55, -PLANE_BODY_HEGHT*0.5f, 0.0f);
        glVertex3f(PLANE_WINGS_WIDTH*0.5, -PLANE_BODY_HEGHT*0.5f, 0.0f);
    glEnd();

    // draw flag colored circle
    // orange 

    faRadius[0] = PLANE_WINGS_WIDTH * 0.1;
    faRadius[1] = PLANE_WINGS_WIDTH * 0.1;
    pOrigin.colors = cOrange;
    pOrigin.cords.x = PLANE_WINGS_WIDTH * 0.5f;
    pOrigin.cords.y = -0.05f;
    pOrigin.cords.z = 0.0f;

    glBegin(GL_TRIANGLE_FAN);
        drawSemiEllipse(faRadius, pOrigin, 0.1f, 0.0f, 2.0f * M_PI);
    glEnd();

    faRadius[0] = faRadius[0] * 0.6f;
    faRadius[1] = faRadius[1] * 0.6f;
    pOrigin.colors = cWhite;

    glBegin(GL_TRIANGLE_FAN);
        drawSemiEllipse(faRadius, pOrigin, 0.1f, 0.0f, 2.0f * M_PI);
    glEnd();

    faRadius[0] = faRadius[0] * 0.6f;
    faRadius[1] = faRadius[1] * 0.6f;
    pOrigin.colors = cGreen;

    glBegin(GL_TRIANGLE_FAN);
        drawSemiEllipse(faRadius, pOrigin, 0.1f, 0.0f, 2.0f * M_PI);
    glEnd();

    // draw right missile
    glBegin(GL_POLYGON);

        pStart.cords.x = PLANE_WINGS_WIDTH + (PLANE_WINGS_WIDTH*0.2f);
        pStart.cords.y = -PLANE_BODY_HEGHT*0.7f;
        pStart.cords.z = 0.0f;
        pStart.colors = cNoseColor;

        pEnd.cords.x = PLANE_WINGS_WIDTH + (PLANE_WINGS_WIDTH*0.1f);
        pEnd.cords.y = PLANE_BODY_HEGHT*0.6f;
        pEnd.cords.z = 0.0f;    
        pEnd.colors = cShadowColor;

        pControl.cords.x = PLANE_WINGS_WIDTH + (PLANE_WINGS_WIDTH*0.2f);
        pControl.cords.y = PLANE_BODY_HEGHT*0.5f;
        pControl.cords.z = 0.0f;
        pControl.colors = cNoseColor;     
        draw2DBezierQuadratic(pStart, pEnd, pControl, 0.01);
        pTemp = pStart;
        pStart = pEnd;
        pEnd = pTemp;
        pEnd.cords.x = PLANE_WINGS_WIDTH;
        pControl.cords.x = PLANE_WINGS_WIDTH;
        draw2DBezierQuadratic(pStart, pEnd, pControl, 0.01);

    glEnd();

    // draw tail and smoke
    glBegin(GL_POLYGON);
        glColor3f(cNoseColor.r, cNoseColor.g, cNoseColor.b);
        glVertex3f(PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT, 0.0f);
        glVertex3f(-PLANE_BODY_WIDTH, -PLANE_BODY_HEGHT, 0.0f);
        glVertex3f(-PLANE_BODY_WIDTH + (PLANE_BODY_WIDTH * 0.2) , -PLANE_BODY_HEGHT - (PLANE_BODY_HEGHT * 0.2), 0.0f);
        glVertex3f(PLANE_BODY_WIDTH - (PLANE_BODY_WIDTH * 0.2) , -PLANE_BODY_HEGHT - (PLANE_BODY_HEGHT * 0.2), 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor4f(cSmoke.r, cSmoke.g, cSmoke.b, 0.9f);
        glVertex3f(PLANE_BODY_WIDTH - (PLANE_BODY_WIDTH * 0.2) , -PLANE_BODY_HEGHT - (PLANE_BODY_HEGHT * 0.2), 0.0f);
        glVertex3f(-PLANE_BODY_WIDTH + (PLANE_BODY_WIDTH * 0.2) , -PLANE_BODY_HEGHT - (PLANE_BODY_HEGHT * 0.2), 0.0f);
        glVertex3f(-PLANE_BODY_WIDTH*1.5f, -PLANE_BODY_HEGHT - (PLANE_BODY_HEGHT * 0.8), 0.0f);
        glVertex3f(PLANE_BODY_WIDTH*1.5f, -PLANE_BODY_HEGHT - (PLANE_BODY_HEGHT * 0.8), 0.0f);
    glEnd();

}