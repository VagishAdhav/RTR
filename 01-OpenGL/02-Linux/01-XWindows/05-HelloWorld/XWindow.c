// standard header files
#include <stdio.h>  // for printf
#include <stdlib.h> // for exit
#include <memory.h> // for memset

//xlib related header files
#include <X11/Xlib.h>   // equivalent windows.h for all xlib APIs
#include <X11/Xutil.h>  // for visual info related API
#include <X11/XKBlib.h> // for keyboard related APIs

// macros
#define WIN_WIDTH (800)
#define WIN_HEIGHT (600)

// global variables
Display *gpDisplay = NULL; // data structure which is an interface betwene Xserver and Xclient (has 77 members)
XVisualInfo visualInfo; // similar to dc (device context)
Window window;   // window object ( hwnd)
Colormap colormap; // colors arrangement in graphics card memory map ( hardware data structure)

Bool bFullScreen = False;

int main(void)
{
    // function declarations
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

    // hello world related variables
    static XFontStruct *pFontStruct = NULL;
    static int winWidth, winHeight;
    static GC gc; // graphic context ( same as DC)
    XGCValues xgcValues;
    XColor color;
    int strLength;
    int strWidth;
    int fontHeight;
    char str[] = "Hello World!!!";

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

    // cenetring of window
    screen = XScreenOfDisplay(gpDisplay, visualInfo.screen);
    screenWidth = XWidthOfScreen(screen);
    screenHeight = XHeightOfScreen(screen);
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
            case MapNotify:
                pFontStruct = XLoadQueryFont(gpDisplay, "fixed");
                break;

            case FocusIn:
                break;

            case FocusOut:
                break;

            case ConfigureNotify:
                winWidth = event.xconfigure.width;
                winHeight = event.xconfigure.height;
                break;

            case KeyPress:
                // for escape key
                keysym = XkbKeycodeToKeysym(gpDisplay, event.xkey.keycode, 0, 0);
                switch (keysym)
                {
                    case XK_Escape:
                        XUnloadFont(gpDisplay, pFontStruct->fid);
                        XFreeGC(gpDisplay, gc);
                        uninitialise();
                        exit(EXIT_SUCCESS);
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

            case Expose:
                gc = XCreateGC(gpDisplay, window, 0, &xgcValues);
                // set font in this gc
                XSetFont(gpDisplay, gc, pFontStruct->fid);
                // get green color for our foreground
                XAllocNamedColor(gpDisplay, colormap, "green", &color, &color);
                // set the foreground color in current GC
                XSetForeground(gpDisplay, gc, color.pixel);

                // find the length of the string
                strLength = strlen(str);
                strWidth = XTextWidth(pFontStruct, str, strLength);
                fontHeight = pFontStruct->ascent + pFontStruct->descent;

                // draw the text
                XDrawString(gpDisplay, window, gc, winWidth/2 - strWidth/2, winHeight/2 - fontHeight/2, str, strLength);
                break;

            case 33:   // destroy message
                XUnloadFont(gpDisplay, pFontStruct->fid);
                XFreeGC(gpDisplay, gc);
                uninitialise();
                exit(EXIT_SUCCESS);
                break;

            default:

                break;
        }
    }


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
               XRootWindow(gpDisplay, visualInfo.screen),
               False,
               SubstructureNotifyMask,
               &event);

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

