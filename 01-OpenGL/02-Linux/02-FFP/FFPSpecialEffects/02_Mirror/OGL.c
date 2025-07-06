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


// load texture related header file
#include <SOIL/SOIL.h>


// macros
#define WIN_WIDTH (800)
#define WIN_HEIGHT (600)

#define MAX_LIMIT_CUBE_TRANSLATE_X (8.0f)
#define MIN_LIMIT_CUBE_TRANSLATE_X (-8.0f)

#define MAX_LIMIT_CUBE_TRANSLATE_Y (4.0f)
#define MIN_LIMIT_CUBE_TRANSLATE_Y (-4.0f)

#define CLOSEST_LIMIT_CUBE_TRANSLATE_Z (5.0f)
#define FARTHEST_LIMIT_CUBE_TRANSLATE_Z (0.3f)

#define INCREMENT (0.05f)
#define DECREMENT (0.05f)

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

// rotation angles
GLdouble gldAngleCube = 0.0f;

// light related variables
GLfloat lightAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat lightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat lightPosition[] = {0.0f, 5.0f, 10.0f, 1.0f};

GLfloat materialAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat materialDiffuse[] = {1.0f, 0.0f, 0.0f, 1.0f};
GLfloat materialSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat materialShininess = 128.0f;

// special effect related global variables
GLuint textureMirror;
GLfloat translateCubeX = 0.0f;
GLfloat translateCubeY = 0.0f;
GLfloat translateCubeZ = 0.3f;
GLfloat cubeScale = 0.25f;

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
                            
                        case XK_Left:
                            // to translate cube on negative X axis
                            if (translateCubeX > MIN_LIMIT_CUBE_TRANSLATE_X)
                            {
                                translateCubeX -= DECREMENT;
                            }
                            break;

                        case XK_Right:
                            // to translate cube on positive X axis
                            if (translateCubeX < MAX_LIMIT_CUBE_TRANSLATE_X)
                            {
                                translateCubeX += INCREMENT;
                            }
                            break;

                        case XK_Up:
                            // translate cube up
                            if (translateCubeY < MAX_LIMIT_CUBE_TRANSLATE_Y)
                            {
                                translateCubeY += INCREMENT;
                            }
                            break;

                        case XK_Down:
                            // translate cube down
                            if (translateCubeY > MIN_LIMIT_CUBE_TRANSLATE_Y)
                            {
                                translateCubeY -= DECREMENT;    
                            }
                            break;

                        case XK_KP_Add:
                            // zoom in
                            if (translateCubeZ < CLOSEST_LIMIT_CUBE_TRANSLATE_Z)
                            {
                                translateCubeZ += INCREMENT;
                            }
                            break;

                        case XK_KP_Subtract:
                            //zoom out
                            if (translateCubeZ > FARTHEST_LIMIT_CUBE_TRANSLATE_Z)
                            {
                                translateCubeZ -= DECREMENT;
                            }
                        
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
    Bool loadGLTexture(GLuint *texture, const char* path);

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

    //Light configuration
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glEnable(GL_LIGHT0);

    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    // material configuration
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
    glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

    // tell openGl to choose the color to clear the screen
    //glClearColor(0.902f, 0.902f, 0.980f, 1.0f);
    glClearColor(0.0, 0.0, 0.0, 1.0f);

    // load textures
    if (loadGLTexture(&textureMirror, "Mirror.bmp") == False)
    {
        fprintf(gpFile, "loadGLTexture failed for Mirror.bmp\n");
        return -2;
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

Bool loadGLTexture(GLuint *texture, const char * path)
{
   //variable declarations
   int width,height;
   unsigned char * image_data = NULL;

   //code
   image_data = SOIL_load_image(path, &width, &height, NULL, SOIL_LOAD_RGBA);


    if(image_data == NULL)
    {
        fprintf(gpFile, "SOIL_load_image failed\n");
        return False;
    }

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
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, image_data);

    // unbind
    glBindTexture(GL_TEXTURE_2D, 0);

    // delete object
    SOIL_free_image_data(image_data);




   return True;
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
  // function declaration
    void drawLitCube(void);
    void drawMirror(void);
    void drawUnitCircleAroundOrigin(void);
    //code
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // set matrix model view mode
    glMatrixMode(GL_MODELVIEW);

    // set  to identity matrix
    glLoadIdentity();

    // setup camera
    gluLookAt(0.0f, 0.0f, 8.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); 

    // render the actual cube
    // pushing camera matrix set above
    glPushMatrix();
        glTranslatef(translateCubeX, translateCubeY, translateCubeZ);
        glScalef(cubeScale, cubeScale, cubeScale);
        glRotatef(gldAngleCube, 1.0f, 0.0f, 0.0f);
        glRotatef(gldAngleCube, 0.0f, 1.0f, 0.0f);
        glRotatef(gldAngleCube, 0.0f, 0.0f, 1.0f);
        drawLitCube();
    glPopMatrix();

    //define your mirror as stencil
    // since we are defining our floor as stencil lets disable depth testing, because for some we are not drawing anything
    glDisable(GL_DEPTH_TEST);
    // mask out all color componants
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    //enable stencil test
    glEnable(GL_STENCIL_TEST);
    // always pass the stencil test
    glStencilFunc(GL_ALWAYS, 1, 1);
    // waht should we do when stencil test passes
    //1. what should we do if stencil test fails
    //2. what should we do if stencil test passes but depth fails
    //3. what should we do if stencil test passes and  depth also passes
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    // this call will not render the floor, this is defination of stencil described above
    // it defines the stencil limits
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, -2.0f);
    glScalef(2.9f, 2.9f, 0.0f);
    drawUnitCircleAroundOrigin();
    // drawMirror();
    // as we want to start redering again , re-enable depth test
    glEnable(GL_DEPTH_TEST);
    // unmask all the four colors
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    // draw only where 1 stored in stencil buffer
    glStencilFunc(GL_EQUAL, 1, 1);

    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

    glPopMatrix();

    // render the reflected cube
    // pushing camera matrix set above
    glPushMatrix();
        glScalef(1.0f, 1.0f, -1.0f);
        glTranslatef(translateCubeX, translateCubeY, translateCubeZ);
        glScalef(cubeScale, cubeScale, cubeScale);
        glRotatef(gldAngleCube, 1.0f, 0.0f, 0.0f);
        glRotatef(gldAngleCube, 0.0f, 1.0f, 0.0f);
        glRotatef(gldAngleCube, 0.0f, 0.0f, 1.0f);
        drawLitCube();
    glPopMatrix();

    glDisable(GL_STENCIL_TEST);

    // render the mirror
    // glPushMatrix();
    // glEnable(GL_BLEND);
    // glColor4f(1.0f, 1.0f, 1.0f, 0.7f);
    // glTranslatef(0.0f, 0.0f, -2.0f);
    // glScalef(3.0f, 3.0f, 0.0f);
    // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // drawMirror();
    // glDisable(GL_BLEND);
    // glPopMatrix();

    glPushMatrix();
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        drawMirror();
        glDisable(GL_BLEND);
    glPopMatrix();

    glXSwapBuffers(gpDisplay, window);
}


void drawLitCube(void)
{
    //code

    glEnable(GL_LIGHTING);
    // draw the front face
    glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 1.0f);
        
        glNormal3f(0.0f, 0.0f, 1.0f);
        //glNormal3f(0.0f, 1.0f, 0.0f);
        // top right
        glVertex3f(1.0f, 1.0f, 1.0f);
        
        // top left
        glVertex3f(-1.0f, 1.0f, 1.0f);

        // bottom left
        glVertex3f(-1.0f, -1.0f, 1.0f);

        // bottom right
        glVertex3f(1.0f, -1.0f, 1.0f);

    glEnd();

    // draw the back face
    glBegin(GL_QUADS);

        glNormal3f(0.0f, 0.0f, -1.0f);

        // top right
        glVertex3f(-1.0f, 1.0f, -1.0f);
        
        // top left
        glVertex3f(1.0f, 1.0f, -1.0f);
        
        // bottom left
        glVertex3f(1.0f, -1.0f, -1.0f);

        // bottom right
        glVertex3f(-1.0f, -1.0f, -1.0f);

    glEnd();

        // draw the right face
    glBegin(GL_QUADS);

        glNormal3f(1.0f, 0.0f, 0.0f);
        // top right
        glVertex3f(1.0f, 1.0f, -1.0f);
        
        // top left
        glVertex3f(1.0f, 1.0f, 1.0f);

        // bottom left
        glVertex3f(1.0f, -1.0f, 1.0f);

        // bottom right
        glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();

    // draw the left face
    glBegin(GL_QUADS);

        glNormal3f(-1.0f, 0.0f, 0.0f);
        // top right
        glVertex3f(-1.0f, 1.0f, 1.0f);
        
        // top left
        glVertex3f(-1.0f, 1.0f, -1.0f);
        

        // bottom left
        glVertex3f(-1.0f, -1.0f, -1.0f);

        // bottom right
        glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();


    // draw Top face

    glBegin(GL_QUADS);

        glNormal3f(0.0f, 1.0f, 0.0f);
        // top right
        glVertex3f(1.0f, 1.0f, -1.0f);
        
        // top left
        glVertex3f(-1.0f, 1.0f, -1.0f);
        

        // bottom left
        glVertex3f(-1.0f, 1.0f, 1.0f);

        // bottom right
        glVertex3f(1.0f, 1.0f, 1.0f);

    glEnd();

  
    // draw Bottom face
    glBegin(GL_QUADS);

        glNormal3f(0.0f, -1.0f, 0.0f);
        // top right
        glVertex3f(1.0f, -1.0f, -1.0f);
        
        // top left
        glVertex3f(-1.0f, -1.0f, -1.0f);
        

        // bottom left
        glVertex3f(-1.0f, -1.0f, 1.0f);

        // bottom right
        glVertex3f(1.0f, -1.0f, 1.0f);

    glEnd();

    glDisable(GL_LIGHTING);
}

void drawMirror(void)
{
    //code
    // pushing the camera matrix set in display
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glScalef(5.0f, 5.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, textureMirror);
    glBegin(GL_QUADS);
        // right top
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 0.0f);
        
        // left top
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 0.0f);
        
        // left bottom
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);

        // right bottom
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();
}

void drawUnitCircleAroundOrigin(void)
{
	 // variable declaration
    float x, y;

    glBegin(GL_LINES);
    for(float angle = 0.0f; angle < 2 * M_PI; angle += 0.001f)
    {
        x = cos(angle);
        y = sin(angle);
        glVertex3f(0, 0, 0.0f);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
}

void update(void)
{
    //code
    gldAngleCube = gldAngleCube - 1.0f;
}

void uninitialise(void)
{
    GLXContext currentContext = glXGetCurrentContext();

     
    if (textureMirror)
    {
        glDeleteTextures(1, &textureMirror);
        textureMirror = 0;
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

