
// custome header files
#include "OGL.h"
#include "LSystemTree.h"
#include "Camera.h"

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

#define BOY_POS_X (1.0f)
#define BOY_POS_Y (0.0f)
#define BOY_POS_Z (-1.0f)

// moldel related structures
#pragma pack(1)
typedef struct 
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
}Vertex;

typedef Vertex Normal;

typedef struct
{
    GLfloat u;
    GLfloat v;
}TexCords;

typedef struct 
{
    int vertex;
    int textCords;
    int normal;
}Faces;
#pragma pack()

typedef struct 
{
    Vertex *VectVertex;
    unsigned int vertexCount;
    Normal *VectNormal;
    unsigned int normalCount;
    TexCords *VectTexCords;
    unsigned int texCordsCount;
    Faces *VectFaces;
    unsigned int faceCount;
    GLuint texture;
} DecodedObjModel;

GLuint textureBoy;
GLuint textureBridge;
GLuint textureFantasy;
GLuint textureOffice;

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

// light related variables
GLfloat lightAmbient[] = {0.5f, 0.5f, 0.5f, 1.0f};
GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat lightPosition[] = {0.0f, 0.0f, 2.0f};
BOOL bLight = FALSE;

// model related variables
DecodedObjModel Boy = {0};
DecodedObjModel Bridge = {0};
DecodedObjModel Terrain = {0};
DecodedObjModel Fantasy = {0};
DecodedObjModel Office = {0};

// wood platform related variables
GLuint texturePlatform;

// grass related variables
GLuint textureDryGrass;

//side sky related variables
GLuint textureSideSky;

// dry lake related variables
GLuint textureDryLake;

//  texture terrain
GLuint textureTerrain;

// Tree related variables
LSystemTree *tree1 = NULL;
LSystemTree *tree2 = NULL;
GLfloat treeRotationY = 0.0f;
GLUquadric *trunkQuadric = NULL;
GLuint textureTrunk, textureLeafs;


// camera angle and scenes

BOOL Scene1 = FALSE;

float controlPointsScene1[4][3] = {
        {0.0f, 1.0f, 30.0f},
        {25.0f, 1.0f, 20.0f},
        {-25.0f, 1.0f, 10.0f},
        {0.0f, 1.0f, 0.0f},
        };

Vertex scene1RoomPos = {1.0f, 0.0f, -25.0f};
Vertex scene1BookPos = {-18.0f, 25.3f, -68.0f};

std::vector<CameraPos> scene1Camera;

BOOL Scene2 = FALSE;

float controlPointsScene2[4][3] = {
        {0.0f, 1.0f, 30.0f},
        {25.0f, 1.0f, 20.0f},
        {-25.0f, 1.0f, 10.0f},
        {0.0f, 1.0f, 0.0f},
        };

std::vector<CameraPos> scene2Camera;

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
        fprintf(gpFile, "Initialise function failed\n");
        DestroyWindow(hwnd);
        hwnd = NULL;
    }
    else
    {
        fprintf(gpFile, "Initialise function completed successfully\n");
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
            //if(gbActiveWindow == TRUE)
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
                bLight = !bLight;
                if (bLight == TRUE)
                {
                    glEnable(GL_LIGHTING);
                }
                else
                {
                    glDisable(GL_LIGHTING);
                }
                break;

            case 'D':
            case 'd':
                fprintf(gpFile, "x: %f, y: %f, z: %f\n", scene1Camera.back().eyeX, scene1Camera.back().eyeY, scene1Camera.back().eyeZ);
                fflush(gpFile);
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

            case VK_RIGHT:
                cameraMove(&scene1Camera, MOVE_RIGHT, 0.2f, 0.1f, TRUE);
                break;

            case VK_LEFT:
                cameraMove(&scene1Camera, MOVE_LEFT, 0.2f, 0.1f, TRUE);
                break;

            case VK_UP:
                // translate cube up
                cameraMove(&scene1Camera, MOVE_UP, 0.2f, 0.1f, TRUE);
                break;
            
            case VK_DOWN:
                // translate cube down
                cameraMove(&scene1Camera, MOVE_DOWN, 0.2f, 0.1f, TRUE);
                break;

            case VK_ADD:
                cameraMove(&scene1Camera, MOVE_FORWARD, 0.2f, 0.1f, TRUE);
                break;

            case VK_SUBTRACT:
                //zoom out
                cameraMove(&scene1Camera, MOVE_BACKWARD, 0.2f, 0.1f, TRUE);
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
    int loadObj(char *fileName, DecodedObjModel* decodedObj);
    void debugObj(DecodedObjModel* decodedObj);
    void drawTrunk(float width, float length);
    void drawLeaf(float width, float length);
    BOOL loadGLTexture(GLuint *texture, TCHAR imageResourceID[], unsigned int channels);

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

    // load obj file
    loadObj("./Models/Child.obj", &Boy);
    loadObj("./Models/Terrain.obj", &Terrain);
    loadObj("./Models/WoodenBridge.obj", &Bridge);
    loadObj("./Models/FantasyBook.obj", &Fantasy);
    loadObj("./Models/Office.obj", &Office);

    //debugObj(&Fantasy);

    // load textures
    if (loadGLTexture(&textureBoy, MAKEINTRESOURCE(ID_BITMAP_BOY), 4) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_BOY\n");
        return -7;
    }

    Boy.texture = textureBoy;

    if (loadGLTexture(&texturePlatform, MAKEINTRESOURCE(ID_BITMAP_PLATFORM), 3) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_PLATFORM\n");
        return -8;
    }

    
    if (loadGLTexture(&textureDryGrass, MAKEINTRESOURCE(ID_BITMAP_DRY_GRASS), 3) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_DRY_GRASS\n");
        return -9;
    }

    if (loadGLTexture(&textureSideSky, MAKEINTRESOURCE(ID_BITMAP_SIDE_SKY), 3) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_SIDE_SKY\n");
        return -10;
    }

    if (loadGLTexture(&textureDryLake, MAKEINTRESOURCE(ID_BITMAP_DRY_LAKE), 3) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_DRY_LAKE\n");
        return -11;
    }

    if (loadGLTexture(&textureDryLake, MAKEINTRESOURCE(ID_BITMAP_DRY_LAKE), 3) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_DRY_LAKE\n");
        return -12;
    }

    if (loadGLTexture(&textureTerrain, MAKEINTRESOURCE(ID_BITMAP_TERRAIN), 3) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_TERRAIN\n");
        return -12;
    }
        // load textures
    if (loadGLTexture(&textureTrunk, MAKEINTRESOURCE(ID_BITMAP_TRUNK), 3) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_TRUNK\n");
        return -13;
    }

    if (loadGLTexture(&textureLeafs, MAKEINTRESOURCE(ID_BITMAP_LEAFS), 4) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_LEAFS\n");
        return -14;
    }

    if (loadGLTexture(&textureBridge, MAKEINTRESOURCE(ID_BITMAP_BRIDGE), 4) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_BRIDGE\n");
        return -15;
    }

    Bridge.texture = textureBridge;

    if (loadGLTexture(&textureFantasy, MAKEINTRESOURCE(ID_BITMAP_FANTASY_BOOK), 3) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_FANTASY_BOOK\n");
        return -16;
    }

    Fantasy.texture = textureFantasy;    

    if (loadGLTexture(&textureOffice, MAKEINTRESOURCE(ID_BITMAP_OFFICE), 4) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture failed for ID_BITMAP_OFFICE\n");
        return -17;
    }

    Office.texture = textureOffice; 

    // create tree object
    createTree(&tree1, 0.4f, 0.2f, 40.0f, 40.0f, FALSE, drawTrunk, drawLeaf);

    Terrain.texture = textureTerrain;


    // setup camera for scene 1
    Scene1 = TRUE;
    // create camera object
    //cameraSet(&scene2Camera, 0.0f, 1.0f, 5.0f, 0.0f, 0.0f, 0.0f, UP_Y);
    cameraSet(&scene1Camera, 0.0f, 35.0f, 50.0f, 0.0f, 35.0f, -100.0f, UP_Y);
    cameraMove(&scene1Camera, (MOVE_FORWARD), 30.0f, 0.09f, TRUE);
    cameraRotateY(&scene1Camera, 50.0f, 0.1f);
    cameraRotateY(&scene1Camera, -50.0f, 0.1f);
    cameraMove(&scene1Camera, (MOVE_FORWARD), 60.0f, 0.09f, TRUE);
    cameraRotateY(&scene1Camera, 10.0f, 0.09f);
    cameraRotateY(&scene1Camera, -10.0f, 0.09f);
    cameraRotateY(&scene1Camera, -15.0f, 0.09f);
    cameraMove(&scene1Camera, (MOVE_FORWARD | MOVE_LEFT), 2.0f, 0.09f, TRUE);

    // setup camera for scene 2
    Scene2 = FALSE;
    // create camera object
    //cameraSet(&scene2Camera, 0.0f, 1.0f, 5.0f, 0.0f, 0.0f, 0.0f, UP_Y);
    cameraSet(&scene2Camera, 0.0f, 10.0f, 30.0f, 0.0f, 0.0f, 0.0f, UP_Y);
    // move forward and down
    cameraMove(&scene2Camera, (MOVE_DOWN | MOVE_FORWARD), 10.0f, 0.09f, TRUE);
    cameraMove(&scene2Camera, (MOVE_FORWARD), 3.0f, 0.09f, TRUE);
    // now revolve around Y
    cameraRevolvAroundY(&scene2Camera, 180.0f, 0.1f);
    //cameraRotateX(&scene2Camera, 180.0f, 0.1f);
    //cameraCurve(&scene2Camera, controlPointsScene2, 0.001f, FALSE);

    //from here onwards opengl code starts

    // depth related code
    glShadeModel(GL_SMOOTH); // tell opengl to use smoothness whilde shading
    glClearDepth(1.0f); // depth buffer to 1.0
    glEnable(GL_DEPTH_TEST); // enable depth test
    glDepthFunc(GL_LEQUAL); // pass the fragments whose values are less than are equal to glClear depth
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // whenever some shapes are deterioted due to prespective projection and depth, give them nicest appearance

    //Light configuration
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    //glEnable(GL_LIGHT0);

    // enable texturing
    glEnable(GL_TEXTURE_2D);

    // Preparation for Tree drawing
    trunkQuadric = gluNewQuadric();
    gluQuadricTexture(trunkQuadric, GL_TRUE); // Enable texture capability
    gluQuadricNormals(trunkQuadric, GLU_SMOOTH);  // Smooth shading
    gluQuadricDrawStyle(trunkQuadric, GLU_FILL);  // Solid cylinder


    // GLfloat fogColor[4] = {0.6f, 0.7f, 0.8f, 1.0f}; // Light bluish-gray fog
    // glClearColor(fogColor[0], fogColor[1], fogColor[2], fogColor[3]); // Match fog color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

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

BOOL loadGLTexture(GLuint *texture, TCHAR imageResourceID[], unsigned int no_channels)
{
    //variable declarations
    HBITMAP hBitmap = NULL;
    BITMAP bmp;
    BOOL bResult = FALSE;

    //code
    //load the bitmap as image
    hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), imageResourceID, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
    if (hBitmap)
    {
        bResult = TRUE;
        GLenum format = (no_channels == 4) ? GL_BGRA_EXT : GL_BGR_EXT;

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
 
        gluBuild2DMipmaps(GL_TEXTURE_2D, no_channels, bmp.bmWidth, bmp.bmHeight, format, GL_UNSIGNED_BYTE, (void *)bmp.bmBits);

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
    gluPerspective(45.0f, (GLdouble)width/(GLdouble)height, 0.1f, 200.0f);

    // frustrun
    //double H = tan((45.0/2.0)/ 180*3.14)*0.1f;
    //double W = H *  (GLdouble)width/(GLdouble)height;
    //glFrustum(-W, W, -H, H, -0.1, 100.0f);

}

void display(void)
{
    // function declaration
    void drawScene1(void);
    void drawScene2(void);


    //code
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set matrix model view mode
    glMatrixMode(GL_MODELVIEW);

    // set  to identity matrix
    glLoadIdentity();

    if (Scene1)
    {
        drawScene1();
    }

    if (Scene2)
    {
        drawScene2();
    }

    SwapBuffers(ghdc);
}

void drawScene1(void)
{
    void drawObj(DecodedObjModel* decodedObj);
    void drawFog(void);

    static int cameraPos = 0;

    gluLookAt(scene1Camera[cameraPos].eyeX, scene1Camera[cameraPos].eyeY, scene1Camera[cameraPos].eyeZ,
              scene1Camera[cameraPos].centerX, scene1Camera[cameraPos].centerY, scene1Camera[cameraPos].centerZ,
              scene1Camera[cameraPos].upX, scene1Camera[cameraPos].upY, scene1Camera[cameraPos].upZ);


    if (cameraPos < (scene1Camera.size() - 1))
    {
        cameraPos++;
    }

    //drawFog();
    glPushMatrix();
    glTranslatef(scene1RoomPos.x, scene1RoomPos.y, scene1RoomPos.z);
    glScalef(0.5f, 0.5f, 0.5f); 
    drawObj(&Office);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(scene1BookPos.x, scene1BookPos.y, scene1BookPos.z);
    glScalef(0.12f, 0.12f, 0.12f); 
    drawObj(&Fantasy);
    glPopMatrix();
}

void drawFog(void)
{
    void drawCube(void);
    glEnable(GL_FOG);
    glFogi(GL_FOG_MODE, GL_LINEAR);

    GLfloat fogColor[4] = {0.6f, 0.7f, 0.8f, 1.0f};
    glFogfv(GL_FOG_COLOR, fogColor);

    glFogf(GL_FOG_START, 10.0f);
    glFogf(GL_FOG_END, 100.0f);

    glHint(GL_FOG_HINT, GL_NICEST);


     // Draw multiple cubes at different depths
    for (int i = 0; i < 5; ++i) {
        glPushMatrix();
        glTranslatef((i - 2) * 2.5f, 0.0f, -i * 5.0f); // spread in Z
        glColor3f(1.0f - 0.2f * i, 0.2f * i, 0.3f);    // varied colors
        drawCube();
        glPopMatrix();
    }
}

void drawBridge(void)
{
    void drawObj(DecodedObjModel* decodedObj);
    glPushMatrix();

    // glTranslatef(BOY_POS_X, 0.0f, -1.0f);
    glTranslatef(BOY_POS_X + 30.0f, BOY_POS_Y - 1.6f, BOY_POS_Z - 6.2f);
    glScalef(1.0f, 1.0f, 1.2f); 
    glRotatef(-17.0f, 0.0f, 1.0f, 0.0f);
    drawObj(&Bridge);
    glPopMatrix();
}


void drawScene2(void)
{
    // function declaration
    void drawBoy(void);
    void drawRamp(void);
    void drawGrass(GLuint *texture);
    void drawSideSky(void);
    void drawDryLake(void);
    void drawTerrain(void);
    void drawTree(GLfloat x, GLfloat y, GLfloat z);
    void drawBridge(void);

    // code 
    static int cameraPos = 0;


    gluLookAt(scene2Camera[cameraPos].eyeX, scene2Camera[cameraPos].eyeY, scene2Camera[cameraPos].eyeZ,
              scene2Camera[cameraPos].centerX, scene2Camera[cameraPos].centerY, scene2Camera[cameraPos].centerZ,
              scene2Camera[cameraPos].upX, scene2Camera[cameraPos].upY, scene2Camera[cameraPos].upZ);
    if (cameraPos < scene2Camera.size() - 1)
    {
        cameraPos++;
    }
    else
    {
        cameraPos = 0;
    }

    drawBoy();
    drawRamp();
    drawGrass(&textureDryGrass);
    drawSideSky();
    drawDryLake();
    drawTerrain();
    drawTree(BOY_POS_X+1.0f, BOY_POS_Y, BOY_POS_Z+1.0f);
    drawTree(BOY_POS_X+1.0f, BOY_POS_Y - 1.0f, BOY_POS_Z+1.0f);
    drawBridge();


}
void drawTree(GLfloat x, GLfloat y, GLfloat z)
{
    glPushMatrix();
        glTranslatef(x, y, z);
        displayTree(tree1);
    glPopMatrix();
}

void drawBoy(void)
{
    void drawObj(DecodedObjModel* decodedObj);
    glPushMatrix();

    // glTranslatef(BOY_POS_X, 0.0f, -1.0f);
    glTranslatef(BOY_POS_X, BOY_POS_Y, BOY_POS_Z);
    glScalef(1.0f, 1.0f, 1.0f); 
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

    drawObj(&Boy);
    glPopMatrix();
}

void drawTerrain(void)
{
    void drawObj(DecodedObjModel* decodedObj);
    void drawQuad(void);
    glPushMatrix();

    glTranslatef(0.0f, -2.0f, -13.7f);
    glScalef(20.0f, 9.5f, 1.0f); 
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

    drawObj(&Terrain);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.0f, -13.4f);
    glScalef(1.0f, 0.9f, 1.0f); 
    glColor3f(0.2f, 0.2f, 0.2f);
    drawQuad();
    glTranslatef(-7.0f, 0.0f, 0.0f);
    drawQuad();
    glColor3f(1.0f, 1.0f, 1.0f);
    glPopMatrix();

}

void drawGrass(GLuint *texture)
{
    void drawQuadWithTexture(GLuint *texture , unsigned int repeat);

    glPushMatrix();
    glTranslatef(0.0f, -1.2f, 22.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glScalef(48.0f, 20.0f, 1.0f);
    drawQuadWithTexture(texture, 8);
    glPopMatrix();
}

void drawSideSky(void)
{
    void drawCubeWithTexture(GLuint *texture, unsigned int repeat);

    glPushMatrix();

    glScalef(49.0f, 49.0f, 49.0f);
    drawCubeWithTexture(&textureSideSky, 2);
    glPopMatrix();
}

void drawDryLake(void)
{
    void drawQuadWithTexture(GLuint *texture , unsigned int repeat);

    glPushMatrix();
    glTranslatef(0.0f, -1.5f, 11.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glScalef(48.0f, 25.0f, 1.0f);
    drawQuadWithTexture(&textureDryLake, 16);
    glPopMatrix();
}


void drawRamp(void)
{
    /// function declaration
    void drawCubeWithTexture(GLuint *texture, unsigned int repeat);

    // variable declaration
    GLfloat xShift = -1.0f;
    GLfloat xShiftOffset = 1.2f;
    glPushMatrix();
    glTranslatef(0.0f, -1.1f,xShift);
    glRotatef(89.0f, 1.0f, 0.0f, 0.0f);
    glScalef(2.5f, 2.0f, 0.1f);
    drawCubeWithTexture(&texturePlatform, 1);
    glPopMatrix();

    xShift += xShiftOffset;
    glPushMatrix();
    glTranslatef(0.0f, -1.1f, xShift);
    glRotatef(89.0f, 1.0f, 0.0f, 0.0f);
    glScalef(1.0f, 0.50f, 0.1f);
    drawCubeWithTexture(&texturePlatform, 1);
    glPopMatrix();

    xShift += xShiftOffset;
    glPushMatrix();
    glTranslatef(0.0f, -1.1f, xShift);
    glRotatef(89.0f, 1.0f, 0.0f, 0.0f);
    glScalef(1.0f, 0.50f, 0.1f);
    drawCubeWithTexture(&texturePlatform, 1);
    glPopMatrix();

    xShift += xShiftOffset;
    glPushMatrix();
    glTranslatef(0.0f, -1.1f, xShift);
    glRotatef(89.0f, 1.0f, 0.0f, 0.0f);
    glScalef(1.0f, 0.50f, 0.1f);
    drawCubeWithTexture(&texturePlatform, 1);
    glPopMatrix();

    
    xShift += xShiftOffset;
    glPushMatrix();
    glTranslatef(0.0f, -1.1f, xShift);
    glRotatef(89.0f, 1.0f, 0.0f, 0.0f);
    glScalef(1.0f, 0.50f, 0.1f);
    drawCubeWithTexture(&texturePlatform, 1);
    glPopMatrix();

        
    xShift += xShiftOffset;
    glPushMatrix();
    glTranslatef(0.0f, -1.1f, xShift);
    glRotatef(89.0f, 1.0f, 0.0f, 0.0f);
    glScalef(1.0f, 0.50f, 0.1f);
    drawCubeWithTexture(&texturePlatform, 1);
    glPopMatrix();

        
    xShift += xShiftOffset;
    glPushMatrix();
    glTranslatef(0.0f, -1.1f, xShift);
    glRotatef(89.0f, 1.0f, 0.0f, 0.0f);
    glScalef(1.0f, 0.50f, 0.1f);
    drawCubeWithTexture(&texturePlatform, 1);
    glPopMatrix();

}

void drawLeaf(float length, float width)
{
    void drawQuadWithTexture(GLuint *texture , unsigned int repeat);
    glDepthMask(GL_FALSE);      
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //sglBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
    glPushMatrix();
        glRotatef(90.0f, 1.0f, 1.0f, 0.0f);
        drawQuadWithTexture(&textureLeafs, 1);
    glPopMatrix();
    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);  
}
 
void drawTrunk(float length, float width)
{
    static unsigned int red = 1;
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
        glLoadIdentity();
        //glRotatef(-90, 0, 0, 1);  // Rotate 90° counter-clockwise
        glScalef(length / width,1.0f, 1.0f);  // Repeat vertically
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glBindTexture(GL_TEXTURE_2D, textureTrunk);
    glPushMatrix();
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(trunkQuadric, width, width, length, 32, 32);
    glPopMatrix();
    glTranslatef(0.0f,length, 0.0f);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void update(void)
{
    //code
}

int loadObj(char *fileName, DecodedObjModel* decodedObj)
{
    FILE *objFile = fopen(fileName, "r");
    char line[128];
    char *token;
    int lineNumber = 0;

    if (objFile == NULL)
    {
        fprintf(gpFile, "Cant open obj file : %s\n", fileName);
        return -1;
    }

    // iterate through file and extract vertex, normals, texcords and faces count
    while (fgets(&line[0], sizeof(line), objFile))
    {
        // count vertex
        if (strncmp(line, "v ", 2) == 0)
        {
            decodedObj->vertexCount++;
        }

        // count normal
        if (strncmp(line, "vn ", 3) == 0)
        {
            decodedObj->normalCount++;
        }

        // count texcords
        if (strncmp(line, "vt ", 3) == 0)
        {
            decodedObj->texCordsCount++;
        }

        // count faces
        if (strncmp(line, "f ", 2) == 0)
        {
            decodedObj->faceCount++;
        }

        lineNumber++;
    }

    fprintf(gpFile, "%d %d %d %d\n", decodedObj->vertexCount, decodedObj->texCordsCount, decodedObj->normalCount,  decodedObj->faceCount);
    fflush(gpFile);

    // allocate corresponding memory
    decodedObj->VectVertex = (Vertex *)malloc(sizeof(Vertex) * decodedObj->vertexCount);
    decodedObj->VectNormal = (Normal *)malloc(sizeof(Normal) * decodedObj->normalCount);
    decodedObj->VectTexCords = (TexCords *)malloc(sizeof(TexCords) * decodedObj->texCordsCount);
    decodedObj->VectFaces = (Faces *)malloc(sizeof(Faces) * decodedObj->faceCount * 3);

    if (!decodedObj->VectVertex || !decodedObj->VectNormal || !decodedObj->VectTexCords  || !decodedObj->VectFaces)
    {
        fprintf(gpFile, "Not enough memory\n");
        fflush(gpFile);
        return -2;
    }


    // read the data now
    rewind(objFile); 
    Vertex *tempVertex = decodedObj->VectVertex;
    Normal *tempNormal = decodedObj->VectNormal;
    TexCords *tempTex = decodedObj->VectTexCords;
    Faces *tempFaces = decodedObj->VectFaces;

    char* facesToken[3] = {NULL, NULL, NULL};

     
    while (fgets(&line[0], sizeof(line), objFile))
    {
        // store vertex
        if (strncmp(line, "v ", 2) == 0)
        {
            token = strtok(&line[2], " ");
            tempVertex->x = atof(token);
            token = strtok(0, " ");
            tempVertex->y = atof(token);
            token = strtok(0, " ");
            tempVertex->z = atof(token);
            tempVertex++;
        }

        // store normal
        if (strncmp(line, "vn ", 3) == 0)
        {
            token = strtok(&line[3], " ");
            tempNormal->x = atof(token);
            token = strtok(0, " ");
            tempNormal->y = atof(token);
            token = strtok(0, " ");
            tempNormal->z = atof(token);
            tempNormal++;
        }

        // stores texcords
        if (strncmp(line, "vt ", 3) == 0)
        {
            token = strtok(&line[3], " ");
            tempTex->u = atof(token);
            token = strtok(0, " ");
            tempTex->v = atof(token);
            token = strtok(0, " ");
            tempTex++;
        }

        // store faces
        if (strncmp(line, "f ", 2) == 0)
        {
            facesToken[0] = strtok(&line[2], " ");
            facesToken[1] = strtok(0, " ");
            facesToken[2] = strtok(0, " ");

            for (int index = 0; index < 3; index++)
            {
                token = strtok(facesToken[index], "/");
                tempFaces->vertex = atoi(token) - 1;
                token = strtok(0, "/");
                tempFaces->textCords = atoi(token) - 1;
                token = strtok(0, "/");
                tempFaces->normal = atoi(token) - 1;
                tempFaces++;
            }
        }
    }

    return 0;
}

void debugObj(DecodedObjModel* decodedObj)
{
    Vertex tempVertex;
    fprintf(gpFile, "===================DEBUG OBJ DATA====================\n");
    fflush(gpFile);
    for (int face = 0; face < decodedObj->faceCount*3; face++)
    {
        fprintf(gpFile, "sub entry : %d ", face);
        fprintf(gpFile, "vertex: %d ", decodedObj->VectFaces[face].vertex);
        fprintf(gpFile, "textCords: %d ", decodedObj->VectFaces[face].textCords);
        fprintf(gpFile, "normal: %d \n", decodedObj->VectFaces[face].normal);
        tempVertex = decodedObj->VectVertex[decodedObj->VectFaces[face].vertex] ;  
        fprintf(gpFile, "X: %f Y : %f Z : %f\n",  tempVertex.x, tempVertex.y, tempVertex.z);
    }
    fflush(gpFile);    
}

void drawObj(DecodedObjModel* decodedObj)
{
    Vertex tempVertex;
    Normal tempNormal;
    TexCords tempTex;


    glBindTexture(GL_TEXTURE_2D, decodedObj->texture);
    glBegin(GL_TRIANGLES);
    for (int face = 0; face < decodedObj->faceCount*3; face++)
    {
        tempVertex = decodedObj->VectVertex[decodedObj->VectFaces[face].vertex];
        tempNormal = decodedObj->VectNormal[decodedObj->VectFaces[face].normal];
        tempTex = decodedObj->VectTexCords[decodedObj->VectFaces[face].textCords];  
        glNormal3f(tempNormal.x, tempNormal.y, tempNormal.z);
        glTexCoord2f(tempTex.u, tempTex.v);
        glVertex3f(tempVertex.x, tempVertex.y, tempVertex.z);
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
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
