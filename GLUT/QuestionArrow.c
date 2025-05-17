// Header files
#include "GL/freeglut.h"
#include "Shape_library.h"

extern GLfloat fRange; 
extern unsigned int guiTicks;
extern GLfloat gfAspectRatio; 


void drawQuestion(void)
{

    point pOrigin;

	color RedColor = {1.0f, 0.0f, 0.0f};
    color BlackColor = {0.0f, 0.0f, 0.0f};
	float faRadius[2] = {20, 20};

    // outer red circle
	pOrigin.cords.x = 0;
	pOrigin.cords.y = 50.0f;
	pOrigin.colors = RedColor;

	glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*MY_PI);
	glEnd();

    // inner black circle
    faRadius[0] *= 0.8f;
    faRadius[1] *= 0.8f;
    pOrigin.colors = BlackColor;

	glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*MY_PI);
	glEnd();

    // QM outer red circle 
	pOrigin.cords.y = 55.0f;
    faRadius[0] *= 0.5f;
    faRadius[1] *= 0.5f;
    pOrigin.colors = RedColor;
    glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, -MY_PI/2.0f,  3.0f * MY_PI/4.0f);
	glEnd();

    // QM inner black circle 
    faRadius[0] *= 0.8f;
    faRadius[1] *= 0.8f;
    pOrigin.colors = BlackColor;
    glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, -MY_PI/2.0f, 3.0f * MY_PI/4.0f);
    glEnd();


    point pTopLeft = {.cords.x = 1.0f, .cords.y = 48.5f, .cords.z = 0, .colors = RedColor};
    point pTopRight = {.cords.x = -1.0f, .cords.y = 48.5f, .cords.z = 0, .colors = RedColor};
    point pBottomRight = {.cords.x = -1.0f, .cords.y = 40.0f, .cords.z = 0, .colors = RedColor};
    point pBottomLeft = {.cords.x = 1.0f, .cords.y = 40.0f, .cords.z = 0, .colors = RedColor};
    glBegin(GL_POLYGON);
    drawSmoothRectangle(pTopLeft, pTopRight, pBottomRight, pBottomLeft, 0.01);
    glEnd();

	pOrigin.cords.y = 37.0f;
    faRadius[0] *= 0.25f;
    faRadius[1] *= 0.23f;
    pOrigin.colors = RedColor;
    glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0,  2.0f * MY_PI);
    glEnd();

}

void drawArrow(void)
{

    #define ARROW_WIDTH (50)
    #define ARROW_HEIGHT (10)

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( ARROW_WIDTH/2.0f, ARROW_HEIGHT/2.0f, 0.0f);  // top left
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f( -ARROW_WIDTH/2.0f, ARROW_HEIGHT/2.0f, 0.0f);
    glVertex3f( -ARROW_WIDTH/2.0f, -ARROW_HEIGHT/2.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( ARROW_WIDTH/2.0f, -ARROW_HEIGHT/2.0f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( ARROW_WIDTH/2.0f, ARROW_HEIGHT/2.0f + ARROW_HEIGHT * 0.2f, 0.0f);  // appex
    glVertex3f( ARROW_WIDTH/2.0f, - (ARROW_HEIGHT/2.0f + ARROW_HEIGHT * 0.2f), 0.0f); 
    glVertex3f( ARROW_WIDTH/2.0f + ARROW_WIDTH*0.2f, 0.0f, 0.0f); 
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f( -ARROW_WIDTH/2.0f, ARROW_HEIGHT/2.0f + ARROW_HEIGHT * 0.2f, 0.0f);  // appex
    glVertex3f( -ARROW_WIDTH/2.0f, - (ARROW_HEIGHT/2.0f + ARROW_HEIGHT * 0.2f), 0.0f); 
    glVertex3f( -(ARROW_WIDTH/2.0f + ARROW_WIDTH*0.2f), 0.0f, 0.0f); 
    glEnd();

}

