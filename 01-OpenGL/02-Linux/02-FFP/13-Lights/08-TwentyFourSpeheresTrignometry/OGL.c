// standard header files
#include <stdio.h>  // for printf
#include <stdlib.h> // for exit
#include <memory.h> // for memset
#include <math.h>

//xlib related header files
#include <X11/Xlib.h>   // equivalent windows.h for all xlib APIs
#include <X11/Xutil.h>  // for visual info related API
#include <X11/XKBlib.h> // for keyboard related APIs

// opengl related headers file
#include <GL/gl.h>  // for OpenGL
#include <GL/glu.h>
#include <GL/glx.h> // for bridging APIs

// macros
#define WIN_WIDTH (800)
#define WIN_HEIGHT (600)

#define NO_OF_LIGHTS (2)

// global variables
Display *gpDisplay = NULL; // data structure which is an interface betwene Xserver and Xclient (has 77 members)
XVisualInfo *visualInfo = NULL; // similar to dc (device context)
Window window;   // window object ( hwnd)
Colormap colormap; // colors arrangement in graphics card memory map ( hardware data structure)


// variable related to full screen
Bool bFullScreen = False;
Bool bActiveWindow = False;

// variable related file op
char gLogFileName[] = "Log.txt";
FILE *gpFile = NULL;

// opengl related variables
GLXContext glxContext = NULL; // similar to hglrc

// sphere system related variables
GLUquadric *quadric = NULL;

GLfloat lightAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat lightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat lightPosition[] = {0.0f, 0.0f, 0.0f, 1.0f};

GLfloat lightModelAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat lightModelLocalViewer[] = {0.0f};

GLfloat angleForRotation = 0.0f;
GLfloat angleForYRotation = 0.0f;
GLfloat angleForZRotation = 0.0f;

GLint keyPressed = -1;

Bool bLight = False;


int main(void)
{
    // function declarations
    int initialise(void);
    void resize(int, int);
    void display(void);
    void update(void);
    void uninitialise(void);
    void toggleFullScreen(void);

    // variable declarations
    int defaultScreen;
    int defaultDepth;
    Status status;
    XSetWindowAttributes windowAttributes;
    Atom windowManagerDeleteAtom;
    XEvent event;
    Screen *screen = NULL;
    int screenWidth, screenHeight;
    KeySym keysym;
    char keys[26]; // although we need only 0th index conventionaly array size is equal to size of alphabets either CAPITAL, SMALL or both
    int framebufferAttributes[] =  /*SIMILAR TO PFD */
                    {
                        GLX_DOUBLEBUFFER,
                        GLX_RGBA,
                        GLX_RED_SIZE, 8,
                        GLX_GREEN_SIZE, 8,
                        GLX_BLUE_SIZE, 8,
                        GLX_ALPHA_SIZE, 8,
                        GLX_DEPTH_SIZE, 24,
                        None
                    };
    Bool bDone = False;

    //code
    // create log file
    gpFile = fopen(gLogFileName, "w");
    if (gpFile == NULL)
    {
        printf("Log File Creation Failed - File IO Error\n");
        exit(0);
    }
    else
    {
        fprintf(gpFile, "Program Started Successfully\n");
    }
    gpDisplay = XOpenDisplay(NULL); // step 1 . client opens connection with server

    if (gpDisplay == NULL)
    {
        fprintf(gpFile, "xOPenDisplay faied to connect with server\n");
        uninitialise();
        exit(EXIT_FAILURE);
    }

    // create the default screen object
    defaultScreen =  XDefaultScreen(gpDisplay);

    //get default depth
    defaultDepth = XDefaultDepth(gpDisplay, defaultScreen);

    // get visual info
    visualInfo = glXChooseVisual(gpDisplay, defaultScreen, framebufferAttributes);

    if (visualInfo == NULL)
    {
        fprintf(gpFile,"glXChooseVisual failed\n");
        uninitialise();
        exit(EXIT_FAILURE);
    }

    // set window attributes
    memset(&windowAttributes, 0, sizeof(XSetWindowAttributes));
    windowAttributes.border_pixel = 0;  // 0 means default
    windowAttributes.background_pixmap = 0; // 0 means no image at backgrounds
    windowAttributes.background_pixel = XBlackPixel(gpDisplay, visualInfo->screen); // black color background, visualInfo->screen is same as defaultScreen
    windowAttributes.colormap = XCreateColormap( gpDisplay, 
                                                 XRootWindow(gpDisplay, visualInfo->screen),
                                                 visualInfo->visual,
                                                 AllocNone); // no memory for color map


    // MAPNOTIFY  <--> WM_CREATE
    // KeyPressMask <--> WM_KEYDOWN
    // ButtonPress <--> WM_L
    // focusIn, FocusOut  FocusChangeMask <--> SET_FOCUS
    // eXpose <--> WM_PAINT
    // destriyNotify <--> WM_DESTROY
    // StructureNotifyMask <--> WM_RESIZE
    // pointerMotionMasl <--> WM_MOUSE_MOVE
    // visibilityChangeMask <--> window hide and show

    windowAttributes.event_mask = KeyPressMask | ButtonPressMask | StructureNotifyMask | FocusChangeMask | ExposureMask;

    colormap = windowAttributes.colormap;

                

    // craete the window
    window = XCreateWindow(gpDisplay,
                           XRootWindow(gpDisplay, visualInfo->screen),
                           0,
                           0,
                           WIN_WIDTH,
                           WIN_HEIGHT,
                           0,
                           visualInfo->depth,
                           InputOutput,
                           visualInfo->visual,
                           CWBorderPixel | CWBackPixel | CWEventMask | CWColormap,
                           &windowAttributes);
    if (!window)
    {
        fprintf(gpFile, "XCreateWindow failed\n");
        uninitialise();
        exit(EXIT_FAILURE);
    }

    // create atom for window manager to destroy the window
    windowManagerDeleteAtom = XInternAtom(gpDisplay, "WM_DELETE_WINDOW", True);
    XSetWMProtocols(gpDisplay, window, &windowManagerDeleteAtom, 1);

    // set window title
    XStoreName(gpDisplay, window, "VVA:XWindow");

    // map the window to display to show it
    XMapWindow(gpDisplay, window);

    // cenetring of window
    screen = XScreenOfDisplay(gpDisplay, visualInfo->screen);
    screenWidth = XWidthOfScreen(screen);
    screenHeight = XHeightOfScreen(screen);
    // changing x and y in xcreatewindow function like we did in createWindows(windows) will not work here
    // because position of window is governed by window manager
    // so let the window manager decide the position, we will center it by using XMovewWindow Xlib API
    XMoveWindow(gpDisplay, window, (screenWidth - WIN_WIDTH)/2, (screenHeight - WIN_HEIGHT)/2);

    // initialise
    int iResult = initialise();

    if (iResult != 0)
    {
        fprintf(gpFile, "Initialise function failed");
        uninitialise();
        exit(EXIT_FAILURE);
    }

    //game loop
    while (bDone == False)
    {
        while (XPending(gpDisplay))
        {
            XNextEvent(gpDisplay, &event);
            switch (event.type)
            {
                case MapNotify:

                    break;

                case FocusIn:
                    bActiveWindow = True;
                    break;

                case FocusOut:
                    bActiveWindow = False;
                    break;

                case ConfigureNotify:
                    resize(event.xconfigure.width, event.xconfigure.height);
                    break;

                case KeyPress:
                    // for escape key
                    keysym = XkbKeycodeToKeysym(gpDisplay, event.xkey.keycode, 0, 0);
                    switch (keysym)
                    {
                        case XK_Escape:
                            bDone = True;
                            break;                  
                        
                        default:
                            break;
                    }

                    // for alphabetic key press
                    // 4th parameter is to save the state of look up string if ZlookupSctring is used across multiple messages
                    // 5th Xcompose staus, if we have to forward the message
                    XLookupString(&event.xkey, keys, sizeof(keys), NULL, NULL);
                    switch (keys[0])
                    {
                        case 'F':
                        case 'f':
                            bFullScreen = !bFullScreen;
                            toggleFullScreen();
                            break;

                        case 'L':
                        case 'l':
                            bLight = !bLight;
                            if (bLight == True)
                            {
                                glEnable(GL_LIGHTING);
                            }
                            else
                            {
                                glDisable(GL_LIGHTING);
                            }
                            break;

                            case 'X':
                            case 'x':
                                keyPressed = 1;
                                angleForRotation = 0.0f; //resetting angle
                                break;

                            case 'Y':
                            case 'y':
                                keyPressed = 2;
                                angleForRotation = 0.0f; //resetting angle
                                break;

                            
                            case 'Z':
                            case 'z':
                                keyPressed = 3;
                                angleForRotation = 0.0f; //resetting angle
                                break; 
                        
                        default:
                            break;
                        
                    }
                    break;

                case ButtonPress:

                    switch(event.xbutton.button)
                    {
                        case 1:
                            break;

                        case 2:
                            break;

                        case 3:   
                            break;

                        default:
                            break;

                    }
                    break;

                case 33:   // destroy message
                    bDone = True;
                    break;

                default:

                    break;
            }
        }

        // rendering
        if (bActiveWindow == True)
        {
            display();
            update();
        }
    }
    
    // uninitialise
    uninitialise();
    return 0;
}

void toggleFullScreen(void)
{
    //code
    Atom windowManagerNormalStateAtom = XInternAtom(gpDisplay, "_NET_WM_STATE", False);
    Atom windowManagerFullScreenStateAtom = XInternAtom(gpDisplay, "_NET_WM_STATE_FULLSCREEN", False);
    XEvent event;
    memset((void*)&event, 0, sizeof(XEvent));

    event.type = ClientMessage;
    event.xclient.window = window;
    event.xclient.message_type = windowManagerNormalStateAtom;
    event.xclient.format = 32;
    event.xclient.data.l[0] = bFullScreen ? 0 : 1;
    event.xclient.data.l[1] = windowManagerFullScreenStateAtom;

    // send above event to Xserver
    XSendEvent(gpDisplay,    
               XRootWindow(gpDisplay, visualInfo->screen),
               False,
               SubstructureNotifyMask,
               &event);

}

int initialise(void)
{
    // function declarations
    void printGLInfo(void);
    void resize(int width, int height);

    //code 
    glxContext = glXCreateContext(gpDisplay, visualInfo, NULL, True);
    if (glxContext == NULL)
    {
        fprintf(gpFile, "glXCreateContext failed to create OpenGL context\n");
        return -1;
    }

    glXMakeCurrent(gpDisplay, window, glxContext);

    // printf GL info
    printGLInfo();
    
    // depth related code
    glShadeModel(GL_SMOOTH); // tell opengl to use smoothness whilde shading
    glClearDepth(1.0f); // depth buffer to 1.0
    glEnable(GL_DEPTH_TEST); // enable depth test
    glDepthFunc(GL_LEQUAL); // pass the fragments whose values are less than are equal to glClear depth
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // whenever some shapes are deterioted due to prespective projection and depth, give them nicest appearance

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
  

    //clear color
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

void resize(int width, int height)
{
    //code
    if (height <= 0)
    {
        height = 1;
    }

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

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
        // Rotate around x axix
        lightPosition[0] = -15.0f;
        lightPosition[1] = 20.0f * sin(angleForRotation);
        lightPosition[2] = 20.0f * cos(angleForRotation);
    }
    else if (keyPressed == 2)
    {
        // Rotate around y axix
        lightPosition[0] = 25.0f * cos(angleForRotation);
        lightPosition[1] = 7.0f;
        lightPosition[2] = 20.0f * sin(angleForRotation);
    }
    else if (keyPressed == 3)
    {
         // Rotate around z axix
        lightPosition[0] = -15 + 15.0f * cos(angleForRotation);
        lightPosition[1] = 15.0f * sin(angleForRotation);
        lightPosition[2] = 5.0f;
    }

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);

    // draw 24 spheres
    draw24Speheres();  


    glXSwapBuffers(gpDisplay, window);
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
    
    angleForRotation = angleForRotation + 0.06f;
}

void uninitialise(void)
{
    GLXContext currentContext = glXGetCurrentContext();

    if (quadric)
    {
        gluDeleteQuadric(quadric);
        quadric = NULL;
    }

    if (currentContext && (currentContext == glxContext))
    {
        glXMakeCurrent(gpDisplay, 0, 0);
    }

    if (glxContext)
    {
        glXDestroyContext(gpDisplay, glxContext);
        glxContext = NULL;
    }

    if (visualInfo)
    {
        free(visualInfo);
        visualInfo = NULL;
    }
    
    // close the log file
    if (gpFile)
    {
        fprintf(gpFile,"Program terminated Successfully\n");
        fflush(gpFile);
        fclose(gpFile);
        gpFile = NULL;
    }

    if(window)
    {
        XDestroyWindow(gpDisplay, window);
    }

    // color map should be freed as it is a HW resource
    if(colormap)
    {
        XFreeColormap(gpDisplay, colormap);
    }

    if (gpDisplay)
    {
        XCloseDisplay(gpDisplay);
        gpDisplay = NULL;
    }
}

