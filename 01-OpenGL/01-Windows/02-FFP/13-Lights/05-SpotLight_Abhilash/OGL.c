// win32 headers
#include<Windows.h>
#include<stdio.h> // File I/O sathi
#include<stdlib.h> // exit sathi

// OpenGL Directory Header Files
#include<gl/GL.h>  //ithe \ chalel pn sglya os vr / is common 
#include<gl/GLU.h>
// Custom header files
#include "OGL.h"

// OpenGL related libraries
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "GLU32.lib")

// Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// global function declarations/prototype/signature
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
// variable related to fullscreen
BOOL gbFulllScreen = FALSE;   // fullscreen nahiye as manuya
HWND ghwnd = NULL;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;

// variable related to File I/O
char gszLogFileName[] = "Log.txt";
FILE *gbFile = NULL;

// Active window related variable
BOOL gbActiveWindow = FALSE;

// Exit Key Press Related
BOOL gbEscapeKeyIsPressed = FALSE;

// OpenGL related global variables
HDC ghdc = NULL; //global handle to device context
// Handle to Graphics library rendering context = global handle to rendering context
HGLRC ghrc = NULL;

// Rotation angles
//GLfloat angleCube = 0.0f;

// Variables for lights 26April2025
GLfloat lightAmbient[] = {1.0f, 1.0f, 0.0f, 1.0f}; //RGBA - Grey Ambient
GLfloat lightDiffuse[] = {1.0f, 1.0f, 0.0f, 1.0f}; //RGBA - White light Ambient.
GLfloat lightSpecular[] = { 1.0f, 1.0f, 0.0f, 1.0f }; // XYZW
GLfloat lightPosition[] = { 0.0f, 2.5f, -7.5f, 1.0f }; // XYZW
GLfloat spotDirection[] = { 0.0f, -1.0f, 0.0f}; // XYZW - Light jaminivar padayachay
BOOL bLight = FALSE;

// Entry-Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdName, int iCmdShow)
{
	// local function declarations
	int intitialize(void);
	void display(void);
	void update(void);
	void uninitialize(void);

	// variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("RTR6");
	BOOL bDone = FALSE;

	// Create log file
	gbFile = fopen(gszLogFileName, "w"); //r: read w: write a: append +: 
	if (gbFile == NULL)
	{
		MessageBox(NULL, TEXT("Log File creation failed"), TEXT("Error"), MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gbFile, "Program Started Successfully \n");  // file mdhye lihayla
	}

	// window class initialization
	//ya 12 lines ani register class mhnje OGL.c cha glutInit(&argc, argv);
	wndclass.cbSize = sizeof(WNDCLASSEX);
	//wndclass.style = CS_HREDRAW | CS_VREDRAW ;
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; 
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc; //function pointer = Name of the function is itself is its address
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	//wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	// Registration of Window Class
	RegisterClassEx(&wndclass);

	// Width (SM_CXSCREEN) and height (SM_CYSCREEN) of the screen
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);  // SM_CXSCREEN = 0
	int screenHeight = GetSystemMetrics(SM_CYSCREEN); // SM_CYSCREEN = 1

	// create Window Extended vapraych
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
						szAppName,
						TEXT("ABHILASH R. BARI"),
						WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
						//CW_USEDEFAULT,
						//CW_USEDEFAULT,
						//CW_USEDEFAULT,
						//CW_USEDEFAULT,
						(screenWidth - WIN_WIDTH) /2,
						(screenHeight - WIN_HEIGHT) /2,
						WIN_WIDTH,
						WIN_HEIGHT,
						NULL,
						NULL,
						hInstance,
						NULL);

	ghwnd = hwnd;

	 
	// show Window
	ShowWindow(hwnd, iCmdShow);

	// Paint background of the window
	UpdateWindow(hwnd);

	// initialize
	int result = initialize();
	if (result != 0)
	{
		fprintf(gbFile, "Initialize function failed \n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else
	{
		fprintf(gbFile, "Initialize function completed successfully \n");
	}

	// set this window as foreground and active window
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	// Game Loop
	while (bDone == FALSE)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
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
			if (gbActiveWindow == TRUE)
			{
				if (gbEscapeKeyIsPressed == TRUE)
				{
					bDone = TRUE; 
				}
				// Render
				display();
				update();
			}
		}
	}
	
	// uninitialize
	uninitialize();

	return((int)msg.wParam);
}

// Callback function
LRESULT CALLBACK WndProc(HWND hwnd,
						UINT iMsg,
						WPARAM wParam,
						LPARAM lParam)
{
	// local function declaration
	void toggleFullScreen(void);
	void resize(int, int);
	void uninitialize(void);
	//code
	//case WM_DESTROY: he OGL.exe cha (GLUT) glutLeaveMainLoop();
	switch (iMsg)
	{
	case WM_CREATE:
		ZeroMemory((void *)&wpPrev, sizeof(WINDOWPLACEMENT));
		wpPrev.length = sizeof(WINDOWPLACEMENT);
		break;
	case WM_SETFOCUS:
		gbActiveWindow = TRUE;
		break;
	case WM_KILLFOCUS:
		gbActiveWindow = FALSE;
		break;
	case WM_ERASEBKGND:
		return(0);
	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:   //Virtual key code letter anhi mhnun
			gbEscapeKeyIsPressed = TRUE;
			break;
		default:
			break;
		}
		break;
	case WM_CHAR:
		switch (wParam)
		{
		case 'F':
		case 'f':
			if (gbFulllScreen == FALSE)
			{
				toggleFullScreen();
				gbFulllScreen = TRUE;
			}
			else
			{
				toggleFullScreen();
				gbFulllScreen = FALSE;
			}
			break;

		case 'L':
		case 'l':
			if (bLight == FALSE)
			{
				bLight = TRUE;
				glEnable(GL_LIGHTING);
			}
			else
			{
				bLight = FALSE;
				glDisable(GL_LIGHTING);
			}
			break;
		default:
			break;
		}
		break;
	case WM_CLOSE:
		uninitialize();
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void toggleFullScreen(void)
{
	// variable declarations
	MONITORINFO mi;
	// code
	if (gbFulllScreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE); // style ghe
		if (dwStyle & WS_OVERLAPPEDWINDOW) //hich style ahe ka?
		{
			ZeroMemory((void*)&mi, sizeof(MONITORINFO)); 
			mi.cbSize = sizeof(MONITORINFO);
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW); //dwStyle mdhun WS_OVERLAPPEDWINDOW la kadhun taka
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top,
							mi.rcMonitor.right - mi.rcMonitor.left, /*width*/
							mi.rcMonitor.bottom - mi.rcMonitor.top, /*hight*/
							SWP_NOZORDER | SWP_FRAMECHANGED); 
			}
			
		}
		ShowCursor(FALSE); //curson nko dakhavu
	}
	else
	{
		SetWindowPlacement(ghwnd, &wpPrev);  //origional size ve anli window
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);
	}

	// Output mdhye Normal Screen -> F Press kelyave Full Screen -> f Press kelyane normal screen hoil
}

int initialize(void)
{
	// function declarations
	void printGLInfo(void);
	void resize(int, int);

	// variable declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;

	// code
	// pixel format descriptor initialization
	ZeroMemory((void*)&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;  //230325

	// getDC
	ghdc = GetDC(ghwnd);
	if (ghdc == NULL)
	{
		fprintf(gbFile, "GetDC function failed. \n");
		return(-1);  // negative means error
	}

	// get matching pixel format index using HDC and pfd
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		fprintf(gbFile, "Choose pixel format failed. \n");
		return(-2);
	}

	// Select the pixel format of found index
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gbFile, "SetPixelFormat failed. \n");
		return(-3);
	}

	// create rendering context using ghdc, pfd and cosen PixelFormatIndex
	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gbFile, "wglCreateContext failed. \n");
		return(-4);
	}
	
	// make this rendering context as current context
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gbFile, "wglMakeCurrent failed. \n");
		return(-5);
	}

	// Print GLInfo
	printGLInfo();
	// ** Depth related code 230325
	glShadeModel(GL_SMOOTH);  // smoothness
	glClearDepth(1.0f); //depth buffer mdhlya saglyanchi value 1 kr
	glEnable(GL_DEPTH_TEST);  // Depth test enable
	glDepthFunc(GL_LEQUAL);  // code chya value compare kr less than or equal to <= 1 ji value clear depth la dili
	// opengl la hint: perspective projection mule kahi shapes vedewakde disu shaktil, tr tu correct kr
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
	// 88 230325

	// *** From here onwards openGL code starts ****
	// Tell openGL to choose the color to clear the screen
	//glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // blue
	

	// Light Configuration 26April2025
	// param1- Light Type Param2- which property need to configure
	// param3 - Kontya value ne configure kru?
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular); ////21May2025
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	// spotlight
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection); //21May2025
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 60.0f); //21May2025
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 20.0f); //21May2025
	//glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f); //21May2025
	//glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0f); //21May2025
	//glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0f); //21May2025

	
	// ENable light
	glEnable(GL_LIGHT0); // Jya light la values configure kelyat tyala enable kraych

	// enable color material
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // black

	// warm up resize (resize kraychya adhi ek dummy resize jaudet)
	resize(WIN_WIDTH, WIN_HEIGHT);
	return 0;
}

void printGLInfo(void)
{
	// code
	// print openGL information
	fprintf(gbFile, "OpenGL Information \n");
	fprintf(gbFile, "****************** \n");
	fprintf(gbFile, "OpenGL Vendor : %s \n", glGetString(GL_VENDOR));
	fprintf(gbFile, "OpenGL Renderer : %s \n", glGetString(GL_RENDERER));
	fprintf(gbFile, "OpenGL Version : %s \n", glGetString(GL_VERSION));
	fprintf(gbFile, "****************** \n");
}

void resize(int width, int height)
{
	// code
	// if height <= 0 make height 1
	if (height <= 0)
	{
		height = 1;
	}

	// set the viewport
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	// Set Matrix Projection Mode
	glMatrixMode(GL_PROJECTION); // matrix mode projection la thev

	// set to identity matrix
	glLoadIdentity(); // vrvha matrix mode jo set kelay tyacha identity matrix kr

	// set perspective projection
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}

void display(void)
{
	// code
	// variables
	GLfloat x = 0.0f; //21MAY2025
	GLfloat z = 0.0f; //21MAY2025
	
	// clear OpenGL buffers
	//glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //230325

	// set Matrix to Model View Mode
	glMatrixMode(GL_MODELVIEW);

	// set into identity matrix
	glLoadIdentity();

	// Translate traingle backwards by Z
	glTranslatef(0.0f, -1.0f, -5.0f); //21MAY2025  x vr davya bajula ja, z vr mage ja.

	/// //21MAY2025 
	glBegin(GL_QUADS);
	for (x = -3.0f; x < 3.0f; x = x + 0.01f)
	{
		for (z = 0.0f; z > -5.0f; z = z - 0.01f)
		{
			glColor3f(0.5f, 0.5f, 0.5f);
			glNormal3f(0.0f, -0.56491f, 0.0f);
			glVertex3f(x + 0.1f, 0.0f, z);
			glVertex3f(x, 0.0f, z + 0.1f);
			glVertex3f(x, 0.0f, z);
			glVertex3f(x + 0.1f, 0.0f, z);
		}
	}

	glEnd();
	// swap the buffers
	SwapBuffers(ghdc);
}

void update(void)
{
	// code
	//angleCube = angleCube + 0.1f;
	///if (angleCube >= 360.0f)
	//{
	//	angleCube = angleCube - 360.0f;
	//}
	
}

void uninitialize(void)
{
	// function declarations
	void toggleFullScreen(void);

	// code
	// if user is exiting from fullscreen then restore fullscreen back to normal
	if (gbFulllScreen == TRUE)
	{
		toggleFullScreen();
		gbFulllScreen =FALSE;
	}

	// Reverse order mdhye initialise mdhl destruct kraych
	// make hdc as the current context by releasing rendering context as current context
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	// Delete the rendering context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	// release the DC
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	// desroy window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	// close the file
	if (gbFile)
	{
		fprintf(gbFile, "Program terminated Successfully \n");
		fclose(gbFile);
		gbFile = NULL;
	}
}
