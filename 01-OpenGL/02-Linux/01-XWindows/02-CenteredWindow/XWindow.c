// standard header files
#include <stdio.h>  // for printf
#include <stdlib.h> // for exit
#include <memory.h> // for memset

//xlib related header files
#include <X11/Xlib.h>   // equivalent windows.h for all xlib APIs
#include <X11/Xutil.h>  

// macros
#define WIN_WIDTH (800)
#define WIN_HEIGHT (600)

// global variables
Display *gpDisplay = NULL; // data structure which is an interface betwene Xserver and Xclient (has 77 members)
XVisualInfo visualInfo; // similar to dc (device context)
Window window;   // window object ( hwnd)
Colormap colormap; // colors arrangement in graphics card memory map ( hardware data structure)

int main(void)
{
    // function declarations
    void uninitialise(void);

    // variable declarations
    int defaultScreen;
    int defaultDepth;
    Status status;
    XSetWindowAttributes windowAttributes;
    Atom windowManagerDeleteAtom;
    XEvent event;
    Screen *screen = NULL;
    int screenWidth, screenHeight;


    //code
    gpDisplay = XOpenDisplay(NULL); // step 1 . client opens connection with server

    if (gpDisplay == NULL)
    {
        printf("xOPenDisplay faied to connect with server\n");
        uninitialise();
        exit(EXIT_FAILURE);
    }

    // create the default screen object
    defaultScreen =  XDefaultScreen(gpDisplay);

    //get default depth
    defaultDepth = XDefaultDepth(gpDisplay, defaultScreen);

    // get visual info
    memset(&visualInfo, 0, sizeof(XVisualInfo));
    status = XMatchVisualInfo(gpDisplay, defaultScreen, defaultDepth, TrueColor, &visualInfo); // matching the pixel format

    if (status == 0)
    {
        printf("XMatchVisualInfo failed\n");
        uninitialise();
        exit(EXIT_FAILURE);
    }

    // set window attributes
    memset(&windowAttributes, 0, sizeof(XSetWindowAttributes));
    windowAttributes.border_pixel = 0;  // 0 means default
    windowAttributes.background_pixmap = 0; // 0 means no image at backgrounds
    windowAttributes.background_pixel = XBlackPixel(gpDisplay, visualInfo.screen); // black color background, visualInfo.screen is same as defaultScreen
    windowAttributes.colormap = XCreateColormap( gpDisplay, 
                                                 XRootWindow(gpDisplay, visualInfo.screen),
                                                 visualInfo.visual,
                                                 AllocNone); // no memory for color map

    colormap = windowAttributes.colormap;

    // craete the window
    window = XCreateWindow(gpDisplay,
                           XRootWindow(gpDisplay, visualInfo.screen),
                           0,
                           0,
                           WIN_WIDTH,
                           WIN_HEIGHT,
                           0,
                           visualInfo.depth,
                           InputOutput,
                           visualInfo.visual,
                           CWBorderPixel | CWBackPixel | CWEventMask | CWColormap,
                           &windowAttributes);
    if (!window)
    {
        printf("XCreateWindow failed\n");
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

    /*// cenetring of window
    screen = XScreenOfDisplay(gpDisplay, visualInfo.screen);
    screenWidth = XWidthOfScreen(screen);
    screenHeight = XHeightOfScreen(screen);*/
    screen = XDefaultScreenOfDisplay(gpDisplay);
    screenWidth = XDisplayWidth(gpDisplay, defaultScreen);
    screenHeight = XDisplayHeight(gpDisplay, defaultScreen);
    int x = (screenWidth - WIN_WIDTH) / 2;
    int y = (screenHeight - WIN_HEIGHT) / 2;
    // changing x and y in xcreatewindow function like we did in createWindows(windows) will not work here
    // because position of window is governed by window manager
    // so let the window manager decide the position, we will center it by using XMovewWindow Xlib API
    XMoveWindow(gpDisplay, window, (screenWidth - WIN_WIDTH)/2, (screenHeight - WIN_HEIGHT)/2);

    //message loop
    while(1)
    {
        XNextEvent(gpDisplay, &event);
        switch (event.type)
        {
            case 33:   // destroy message
                uninitialise();
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("event.type : %d", event.type);
                break;
        }
    }


    return 0;
}

void uninitialise(void)
{
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

