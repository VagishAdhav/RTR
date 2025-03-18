// Header files
#include "GL/freeglut.h"
#include <math.h>
#include "Shape_library.h"



// constant macros

#define M_PI   (3.14159265358979323846264338327950288)

// global variable
extern unsigned int guiTicks;

void drawMonitor(void)
{
    #define MONITOR_WIDTH 56
    #define MONITOR_HEIGHT 35

	// variable declaration
	point pTopLeft, pTopRight, pBottomRight, pBottomLeft;
	color cInner = {(float)0/255.0f, (float)0/255.0f, (float)0/255.0f};  // black color
	color cOuter = {(float)128/255.0f, (float)128/255.0f, (float)128/255.0f};  // light grey color

	// code
	// draw outer box
	pTopLeft.cords.x = -(MONITOR_WIDTH/2.0f);
	pTopLeft.cords.y = (MONITOR_HEIGHT/2.0f);
	pTopLeft.colors = cOuter;

	pTopRight.cords.x = (MONITOR_WIDTH/2.0f);
	pTopRight.cords.y = (MONITOR_HEIGHT/2.0f);
	pTopRight.colors = cOuter;

	pBottomRight.cords.x = (MONITOR_WIDTH/2.0f);
	pBottomRight.cords.y = -(MONITOR_HEIGHT/2.0f);
	pBottomRight.colors = cOuter;
	
	pBottomLeft.cords.x = -(MONITOR_WIDTH/2.0f);
	pBottomLeft.cords.y = -(MONITOR_HEIGHT/2.0f);
	pBottomLeft.colors = cOuter;

	glBegin(GL_POLYGON);
	drawSmoothRectangle(pTopLeft, pTopRight, pBottomRight, pBottomLeft, 0.05);
	glEnd();

	// draw screen
	float fReduction = 0.05 * MONITOR_HEIGHT; 

	pTopLeft.cords.x =  pTopLeft.cords.x + fReduction;
	pTopLeft.cords.y =  pTopLeft.cords.y - fReduction;
	pTopLeft.colors = cInner;

	pTopRight.cords.x =  pTopRight.cords.x - fReduction;
	pTopRight.cords.y =  pTopRight.cords.y - fReduction;
	pTopRight.colors = cInner;

	pBottomRight.cords.x =  pBottomRight.cords.x - fReduction;
	pBottomRight.cords.y =  pBottomRight.cords.y + fReduction;
	pBottomRight.colors = cInner;
	
	pBottomLeft.cords.x =  pBottomLeft.cords.x + fReduction;
	pBottomLeft.cords.y =  pBottomLeft.cords.y + fReduction;
	pBottomLeft.colors = cInner;

	glBegin(GL_POLYGON);
	drawSmoothRectangle(pTopLeft, pTopRight, pBottomRight, pBottomLeft, 0.05);
	glEnd();


    // draw task bar
    #define TASK_BAR_HEIGHT 3.0f
    #define TASK_BAR_COLOR 0.878, 1.000, 1.000
    
    glBegin(GL_QUADS);

    glColor3f(TASK_BAR_COLOR);
    glVertex3f(pBottomRight.cords.x, pBottomRight.cords.y + TASK_BAR_HEIGHT, 0.0f);
    glVertex3f(pBottomLeft.cords.x, pBottomLeft.cords.y + TASK_BAR_HEIGHT, 0.0f); // top left
    glVertex3f(pBottomLeft.cords.x, pBottomLeft.cords.y, 0.0f);
    glVertex3f(pBottomRight.cords.x, pBottomRight.cords.y, 0.0f);

    glEnd();

    // draw Windows Logo
    #define LOGO_SHIFT_RIGHT 4.0f
    glBegin(GL_QUADS);

    glColor3f(0.000, 0.749, 1.000);
    // top left

    glVertex3f(pBottomLeft.cords.x + LOGO_SHIFT_RIGHT, pBottomLeft.cords.y + TASK_BAR_HEIGHT - (TASK_BAR_HEIGHT*0.2), 0.0f);
    glVertex3f(pBottomLeft.cords.x + LOGO_SHIFT_RIGHT, pBottomLeft.cords.y + (TASK_BAR_HEIGHT*0.2), 0.0f);
    glVertex3f(pBottomLeft.cords.x + LOGO_SHIFT_RIGHT + TASK_BAR_HEIGHT*0.5, pBottomRight.cords.y + (TASK_BAR_HEIGHT*0.2), 0.0f);
    glVertex3f(pBottomLeft.cords.x + LOGO_SHIFT_RIGHT + TASK_BAR_HEIGHT*0.5, pBottomLeft.cords.y + TASK_BAR_HEIGHT - (TASK_BAR_HEIGHT*0.2), 0.0f);

    glEnd();
}

void drawVSLogo(void)
{
	#define LOGO_WIDTH (5.0f)
	#define LOGO_HEIGHT (5.0f)

	#define LOGO_COLOR_LEFT 0.5, 0.12, 0.83
	#define LOGO_COLOR_INNER 0.53, 0.14, 0.85
	#define LOGO_COLOR_OUTER 0.55, 0.16, 0.87
	#define LOGO_COLOR_RIGHT 0.62, 0.24, 0.96

	// draw left most dark ribbon
	glBegin(GL_QUADS);

    glColor3f(LOGO_COLOR_LEFT);

	// top right
	glVertex3f(-LOGO_WIDTH + 1.0f, LOGO_HEIGHT - 1.5f, 0 );
	// top left
	glVertex3f(-LOGO_WIDTH, LOGO_HEIGHT - 3.0f, 0 );
	// bottom left
	glVertex3f(-LOGO_WIDTH, -LOGO_HEIGHT + 3.0f, 0 );
	// bottom right
	glVertex3f(-LOGO_WIDTH + 1.0f, -LOGO_HEIGHT + 1.5f, 0 );


	// draw bottom inner ribbon
	glColor3f(LOGO_COLOR_INNER);

	// top right
	glVertex3f(LOGO_WIDTH - 1.5f, LOGO_HEIGHT, 0 );
	// top left
	glVertex3f(-LOGO_WIDTH, -LOGO_HEIGHT + 3.0f, 0 );
	// bottom left
	glVertex3f(-LOGO_WIDTH + 1.0f, -LOGO_HEIGHT + 1.5f, 0 );
	// bottom right
	glVertex3f(LOGO_WIDTH - 1.5f, LOGO_HEIGHT - 2.3f, 0 );


	// draw top inner ribbon

	glColor3f(LOGO_COLOR_OUTER);
	// top right
	glVertex3f(LOGO_WIDTH - 1.5f, -(LOGO_HEIGHT - 2.3f), 0 );
	// top left
	glVertex3f(-LOGO_WIDTH + 1.0f, LOGO_HEIGHT - 1.5f, 0 );
	// bottom left
	glVertex3f(-LOGO_WIDTH, LOGO_HEIGHT - 3.0f, 0 );
	// bottom right
	glVertex3f(LOGO_WIDTH - 1.5f, -LOGO_HEIGHT, 0 );

	// draw right ribbon
	glColor3f(LOGO_COLOR_RIGHT);
	// top right
	glVertex3f(LOGO_WIDTH, (LOGO_HEIGHT - 1.0f), 0 );
	// top left
	glVertex3f(LOGO_WIDTH - 1.5f, LOGO_HEIGHT, 0 );
	// bottom left
	glVertex3f(LOGO_WIDTH - 1.5f, -LOGO_HEIGHT, 0 );
	// bottom right
	glVertex3f(LOGO_WIDTH, -(LOGO_HEIGHT - 1.0f), 0 );


	glEnd();
}
