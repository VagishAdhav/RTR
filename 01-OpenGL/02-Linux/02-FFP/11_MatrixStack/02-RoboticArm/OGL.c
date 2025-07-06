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

// robotic arm related variables
int shoulder = 0;
int elbow = 0;
GLUquadric *quadric = NULL;


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

                        case 'S':
                            shoulder = (shoulder + 3) % 360;
                            break;

                        case 's':
                            shoulder = (shoulder - 3) % 360;
                            break;

                        case 'E':
                            elbow = (elbow + 3) % 360;
                            break;

                        case 'e':
                            elbow = (elbow - 3) % 360;
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

    //clear color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //quadric for sphere
    quadric = gluNewQuadric();

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

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set matrix model view mode
    glMatrixMode(GL_MODELVIEW);

    // set  to identity matrix
    glLoadIdentity();

        // both arm and forarm are filled polygon
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // do basic translation common to both arm and forarm
    glTranslatef(0.0f, 0.0f, -12.0f);

    // push this matrix into matrix stack
    glPushMatrix();
    // code for arm

    glRotatef((GLfloat)shoulder, 0.0f, 0.0f, 1.0f);
    glTranslatef(1.0f, 0.0f, 0.0f);
    glPushMatrix();
        glScalef(2.1f, 0.6f, 1.0f);
        glColor3f(0.5f, 0.35f, 0.05f);
        gluSphere(quadric, 0.5f, 10, 10);
    glPopMatrix();

    // code for forarm
    glTranslatef(1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)elbow, 0.0f, 0.0f, 1.0f);
    glTranslatef(1.0f, 0.0f, 0.0f);
    glPushMatrix();
        glScalef(2.1f, 0.6f, 1.0f);
        glColor3f(0.5f, 0.35f, 0.05f);
        gluSphere(quadric, 0.5f, 10, 10);
    glPopMatrix();

    // common to both

    glPopMatrix();


    glXSwapBuffers(gpDisplay, window);
}

void update(void)
{
    //code
}

void uninitialise(void)
{
    GLXContext currentContext = glXGetCurrentContext();

    //code
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

