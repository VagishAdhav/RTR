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

// esc key related variable
BOOL gbEscKeyIsPressed = FALSE;

// rotation angles
GLdouble gldAngleCube = 0.0f;

// texture related global variables
GLuint textureKundali;

GLfloat cubeTexcoords[] =
{
	// front
	1.0f, 1.0f, // top-right of front
	0.0f, 1.0f, // top-left of front
	0.0f, 0.0f, // bottom-left of front
	1.0f, 0.0f, // bottom-right of front

	// right
	1.0f, 1.0f, // top-right of right
	0.0f, 1.0f, // top-left of right
	0.0f, 0.0f, // bottom-left of right
	1.0f, 0.0f, // bottom-right of right

	// back
	1.0f, 1.0f, // top-right of back
	0.0f, 1.0f, // top-left of back
	0.0f, 0.0f, // bottom-left of back
	1.0f, 0.0f, // bottom-right of back

	// left
	1.0f, 1.0f, // top-right of left
	0.0f, 1.0f, // top-left of left
	0.0f, 0.0f, // bottom-left of left
	1.0f, 0.0f, // bottom-right of left

	// top
	1.0f, 1.0f, // top-right of top
	0.0f, 1.0f, // top-left of top
	0.0f, 0.0f, // bottom-left of top
	1.0f, 0.0f, // bottom-right of top

	// bottom
	1.0f, 1.0f, // top-right of bottom
	0.0f, 1.0f, // top-left of bottom
	0.0f, 0.0f, // bottom-left of bottom
	1.0f, 0.0f, // bottom-right of bottom
};


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
    if (loadGLTexture(&textureKundali, MAKEINTRESOURCE(ID_BITMAP_KUNDALI)) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_KUNDALI\n");
        return -7;
    }

    // enable texturing
    glEnable(GL_TEXTURE_2D);


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
        //(glTexImage2D + glGeneratemimap)
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

    // frustrun
    //double H = tan((45.0/2.0)/ 180*3.14)*0.1f;
    //double W = H *  (GLdouble)width/(GLdouble)height;
    //glFrustum(-W, W, -H, H, -0.1, 100.0f);

}

void display(void)
{
    //code
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set matrix model view mode
    glMatrixMode(GL_MODELVIEW);

    // set  to identity matrix
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -8.0f);
    
    glRotatef(gldAngleCube, 1.0f, 1.0f, 1.0f);

    glBindTexture(GL_TEXTURE_2D, textureKundali);
    //glRotatef(gldAngleCube, 0.0f, 1.0f, 0.0f);
    //glRotatef(gldAngleCube, 0.0f, 0.0f, 1.0f);
    // draw the front face
    glBegin(GL_QUADS);

        //glColor3f(1.0f, 1.0f, 1.0f);
        
        // top right
        glTexCoord2f(cubeTexcoords[0], cubeTexcoords[1]);
        glVertex3f(1.0f, 1.0f, 1.0f);
        
        // top left
        glTexCoord2f(cubeTexcoords[2], cubeTexcoords[3]);
        glVertex3f(-1.0f, 1.0f, 1.0f);

        // bottom left
        glTexCoord2f(cubeTexcoords[4], cubeTexcoords[5]);
        glVertex3f(-1.0f, -1.0f, 1.0f);

        // bottom right
        glTexCoord2f(cubeTexcoords[6], cubeTexcoords[7]);
        glVertex3f(1.0f, -1.0f, 1.0f);

    glEnd();

    // draw the back face
    glBegin(GL_QUADS);

        // top right
        glTexCoord2f(cubeTexcoords[8], cubeTexcoords[9]);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        
        // top left
        glTexCoord2f(cubeTexcoords[10], cubeTexcoords[11]);
        glVertex3f(1.0f, 1.0f, -1.0f);
        
        // bottom left
         glTexCoord2f(cubeTexcoords[12], cubeTexcoords[13]);
        glVertex3f(1.0f, -1.0f, -1.0f);

        // bottom right
        glTexCoord2f(cubeTexcoords[14], cubeTexcoords[15]);
        glVertex3f(-1.0f, -1.0f, -1.0f);

    glEnd();

        // draw the right face
    glBegin(GL_QUADS);

       
        // top right
        glTexCoord2f(cubeTexcoords[16], cubeTexcoords[17]);
        glVertex3f(1.0f, 1.0f, -1.0f);
        
        // top left
        glTexCoord2f(cubeTexcoords[18], cubeTexcoords[19]);
        glVertex3f(1.0f, 1.0f, 1.0f);

        // bottom left
        glTexCoord2f(cubeTexcoords[20], cubeTexcoords[21]);
        glVertex3f(1.0f, -1.0f, 1.0f);

        // bottom right
        glTexCoord2f(cubeTexcoords[22], cubeTexcoords[23]);
        glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();

    // draw the left face
    glBegin(GL_QUADS);

        // top right
        glTexCoord2f(cubeTexcoords[24], cubeTexcoords[25]);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        
        // top left
        glTexCoord2f(cubeTexcoords[26], cubeTexcoords[27]);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        

        // bottom left
        glTexCoord2f(cubeTexcoords[28], cubeTexcoords[29]);
        glVertex3f(-1.0f, -1.0f, -1.0f);

        // bottom right
        glTexCoord2f(cubeTexcoords[30], cubeTexcoords[31]);
        glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();


    // draw Top face

    glBegin(GL_QUADS);

        // top right
        glTexCoord2f(cubeTexcoords[32], cubeTexcoords[33]);
        glVertex3f(1.0f, 1.0f, -1.0f);
        
        // top left
        glTexCoord2f(cubeTexcoords[34], cubeTexcoords[35]);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        

        // bottom left
        glTexCoord2f(cubeTexcoords[36], cubeTexcoords[37]);
        glVertex3f(-1.0f, 1.0f, 1.0f);

        // bottom right
        glTexCoord2f(cubeTexcoords[38], cubeTexcoords[39]);
        glVertex3f(1.0f, 1.0f, 1.0f);

    glEnd();

  
    // draw Bottom face
    glBegin(GL_QUADS);

        // top right
        glTexCoord2f(cubeTexcoords[40], cubeTexcoords[41]);
        glVertex3f(1.0f, -1.0f, -1.0f);
        
        // top left
        glTexCoord2f(cubeTexcoords[42], cubeTexcoords[43]);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        

        // bottom left
        glTexCoord2f(cubeTexcoords[44], cubeTexcoords[45]);
        glVertex3f(-1.0f, -1.0f, 1.0f);

        // bottom right
        glTexCoord2f(cubeTexcoords[46], cubeTexcoords[47]);
        glVertex3f(1.0f, -1.0f, 1.0f);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);

    SwapBuffers(ghdc);
}

void update(void)
{
    //code
    
    gldAngleCube = gldAngleCube - 2.0f;
    if (gldAngleCube <= 0)
    {
        gldAngleCube = 360.0f;
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

    if (textureKundali)
    {
        glDeleteTextures(1, &textureKundali);
        textureKundali = 0;
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