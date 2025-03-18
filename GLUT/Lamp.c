// Header files
#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include <math.h>

// Global variable declarations 
extern GLfloat fRange;

void drawCircle(float radius, float x, float y)
{
	glBegin(GL_POLYGON);

	for (float angle = 0.0f; angle < 2 * M_PI; angle += 0.1f)
	{
		glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
	}

	glEnd();
}


void drawLamp(void)
{
	// code 
	float yOffset = -5.0f;
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(1.0f, yOffset + 10.0f);
	glVertex2f(1.0f, yOffset + -12.0f);
	glVertex2f(-1.0f, yOffset + -12.0f);
	glVertex2f(-1.0f, yOffset + 10.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(5.0f, yOffset + -12.0f);
	glVertex2f(-5.0f, yOffset + -12.0f);
	glVertex2f(-5.0f, yOffset + -14.0f);
	glVertex2f(5.0f, yOffset + -14.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(0.0f, yOffset + 14.0f);
	glVertex2f(-1.0f, yOffset + 12.0f);
	glVertex2f(-14.0f, yOffset + 20.0f);
	glVertex2f(-13.0f, yOffset + 22.0f);
	glEnd();

	glColor3f(0.9922f, 0.9490f, 0.8078f);
	drawCircle(3.8f, -20.0f, 12.5f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(-12.0f, yOffset + 27.0f);
	glVertex2f(-10.0f, yOffset + 25.0f);
	glVertex2f(-17.0f, yOffset + 15.0f);
	glVertex2f(-23.0f, yOffset + 20.0f);
	glEnd();


	glColor3f(0.0f, 0.0f, 0.0f);
	drawCircle(3.0f, 0.0f, 7.0f);

	glColor3f(0.9804f, 0.9922f, 0.9294f);
	drawCircle(2.0f, 0.0f, 7.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	drawCircle(0.5f, 0.0f, 7.0f);

	


}

