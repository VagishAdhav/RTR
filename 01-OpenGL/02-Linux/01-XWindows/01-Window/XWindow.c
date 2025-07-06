// Standard lib files
#include<stdio.h> // becasue we are using printf
#include<stdlib.h> //for exit 
#include<memory.h> // for memset 

// Xlib header files
#include<X11/lib.h> // like earlier windows.h for xlib api 
#include<X11/Xutil.h> // 

// Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// Global variables
Display *gpDisplay=NULL; // structure of 77 members , it is madhyasath between client and server
XVisualInfo visualInfo; // hdc like -- device context of hardware- structure within struct within struct
Window window; // handle to window object 
ColorMap colormap; // graphic card arranges color in certain arrangement and this is called in xlib as colormap 


int main(void)
{
    //function decelrations
    void uninitialise(void);

    // Variable declerations
    int defaultScreen;
    int defaultDepth;
    Status status;
    XSetWindowAttributes windowAttributes;
    Atom windowManagerDeleteAtom;
    XEvent event;



    // code
    // Open the connection with the Xserver
    gpDisplay=XOpenDisplay(NULL); // Client open connection with server with this method, NUL- no name to display 

    if(gpDisplay==NULL)
    {
        printf("Xopen open display failed to connect with the Xserver\n");
        uninitialise();
        exit(EXIT_FAILURE);
    }

    // Create the default screen object
    defaultScreen=XDefaultScreen(gpDisplay); // default screen retrun kr 

    // Get Default Depth
    defaultDepth=XDefaultDepth(gpDisplay, defaultScreen);

    // Get visual Info
    memset((void*)&visualInfo, 0, sizeof(XVisualInfo)); // initialise all object at known initialise state 
    status=XMatchVisualInfo(gpDisplay, defaultScreen, defaultDepth, TrueColor, &visualInfo); // 

    if(status==0)
    {
        printf("Xmatch visual info failed\n");
        uninitialise();
        exit(EXIT_FAILURE);
    }

    // set window attributes
    memset((void*)&windowAttributes, 0, sizeof(XSetWindowAttributes));
    windowAttributes.border_pixel=0;
    windowAttributes.background_pixmap=0;
    windowAttributes.background_pixel=XBlackPixel(gpDisplay, visualInfo.screen);
    windowAttributes.ColorMap=XCreateColorMap(gpDisplay, 
                            XRootWindow(gpDisplay, visualInfo.screen),
                            visualInfo.visual,AllocNone);

    colormap =windowAttributes.colormap;

    // Create window
    window=XCreateWindow(gpDisplay,
                        XRooWindow(gpDisplay, visualInfo.screen),
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
    
    if(!window)
    {
        printf("XCreate window failed\n");
        uninitialise();
        exit(EXIT_FAILURE);
    }


    //Create Atom for Window Manager to destroy the window
    windowManagerDeleteAtom=XInternAtom(gpDisplay, "WM_DELTE_WINDOW", True);

    XSetWMProtols(gpDisplay,window, &windowManagerDeleteAtom, 1);


    // Set window title
    XStoreName(gpDisplay, window, "ARP:XWindow");


    // Mapped the window to show it 
    XMapWindow(gpDisplay, window);

    

    // Message loop
    while(1)
    {
        XNextEvent(gpDisplay, &event);

    

        switch(event.time)
        {
            case 33:
                uninitialise();
                exit(EXIT_SUCCESS);
                break;
            default:
                break;
        }
    }


    uninitialise();

    return(0);

}


void uninitialise(void)
{
    // code
    if(window)
    {
        XDestroyWindow(gpDisplay, window);
    }

    if(colormap)
    {
        XFreeColormap(gpDisplay, colormap);
    }

    if(gpDisplay)
    {
        XCloseDisplay(gpDisplay);
        gpDisplay=NULL;
    }
}


