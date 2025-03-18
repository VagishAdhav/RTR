// Header files
#include "GL/freeglut.h"
#include <math.h>

// Global variable declarations 
#define MY_PI 3.14159265358979323846264338327950288

void drawBagWithPerson(void)
{
	//face
	//glColor3f(1.0f, 0.894f, 0.769f); // Bisque color
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.894f, 0.769f); // Bisque color
		glVertex3f(4.0f, 16.0f, 0.0f);  //Center
		glVertex3f(7.0f, 9.0f, 0.0f);  // nose
		glVertex3f(5.6f, 9.0f, 0.0f); // nose
		glVertex3f(3.0f, 7.0f, 0.0f); 
		glVertex3f(-4.0f, 7.0f, 0.0f); 
		glVertex3f(-4.0f, 9.0f, 0.0f); 
		glVertex3f(0.5f, 10.0f, 0.0f); 
	glEnd();

	//hair
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.549f, 0.0f); // DarkOrange color
		glVertex3f(0.0f, 18.0f, 0.0f); // Top-left corner
		glVertex3f(4.0f, 16.0f, 0.0f);  //Center
		glVertex3f(3.0f, 13.0f, 0.0f);  // Top-right corner
		glVertex3f(0.5f, 12.5f, 0.0f); // Bottom-right corner
		glVertex3f(0.5f, 10.0f, 0.0f); // Bottom-left corner
		glVertex3f(-4.0f, 9.0f, 0.0f); 
		glVertex3f(-5.5f, 15.5f, 0.0f); 
	glEnd();

	// Upper body
	glBegin(GL_POLYGON);
	glColor3f(0.282f, 0.239f, 0.545f); // DarkSLateBlue color
		glVertex3f(-4.0f, 7.0f, 0.0f); // Top-left corner
		glVertex3f(10.0f, 6.0f, 0.0f);  //Center
		glVertex3f(4.0f, -10.0f, 0.0f);  // Top-right corner
		glVertex3f(-7.0f, -10.0f, 0.0f); // Bottom-right corner
		glVertex3f(-10.0f, 2.0f, 0.0f); // Bottom-left corner
		glVertex3f(-4.0f, 5.5f, 0.0f); 
		glVertex3f(-4.0f, 7.0f, 0.0f); 
	glEnd();

	// lower body
	glBegin(GL_POLYGON);
	glColor3f(0.282f, 0.239f, 0.545f); // DarkSLateBlue color
		glVertex3f(-8.0f, -10.0f, 0.0f); // Top-left corner
		glVertex3f(4.0f, -10.0f, 0.0f);  //Center
		glVertex3f(5.0f, -18.0f, 0.0f);  // Top-right corner
		glVertex3f(-9.0f, -18.0f, 0.0f); // Bottom-right corner
	glEnd();

	// Left thie
	glBegin(GL_POLYGON);
	glColor3f(0.282f, 0.239f, 0.545f); // DarkSLateBlue color
		glVertex3f(-9.0f, -18.0f, 0.0f); // Top-left corner
		glVertex3f(-2.0f, -18.0f, 0.0f);  //Center
		glVertex3f(-4.0f, -28.0f, 0.0f);  // Top-right corner
		glVertex3f(-10.0f, -28.0f, 0.0f); // Bottom-right corner
	glEnd();

	// lower leg
	glBegin(GL_POLYGON);
	glColor3f(0.282f, 0.239f, 0.545f); // DarkSLateBlue color
		glVertex3f(-10.0f, -28.0f, 0.0f); // Top-left corner
		glVertex3f(-4.0f, -28.0f, 0.0f);  //Center
		glVertex3f(-9.0f, -38.0f, 0.0f);  // Top-right corner
		glVertex3f(-14.0f, -38.0f, 0.0f); // Bottom-right corner
	glEnd();

	// upper shoe
	glBegin(GL_POLYGON);
	glColor3f(0.282f, 0.239f, 0.545f); // DarkSLateBlue color
		glVertex3f(-14.0f, -38.0f, 0.0f); // Top-left corner
		glVertex3f(-9.0f, -38.0f, 0.0f);  //Center
		glVertex3f(-11.0f, -41.0f, 0.0f);  // Top-right corner
		glVertex3f(-14.0f, -41.0f, 0.0f); // Bottom-right corner
	glEnd();

	// upper shoe
	glBegin(GL_POLYGON);
	glColor3f(0.627f, 0.322f, 0.176f); // DarkSLateBlue color
		glVertex3f(-14.0f, -41.0f, 0.0f); // Top-left corner
		glVertex3f(-11.0f, -41.0f, 0.0f);  //Center
		glVertex3f(-5.0f, -44.0f, 0.0f);  // Top-right corner
		glVertex3f(-3.0f, -44.0f, 0.0f); // Bottom-right corner
		glVertex3f(-3.0f, -45.5f, 0.0f); 
		glVertex3f(-14.0f, -46.0f, 0.0f); 
	glEnd();

	// Right thie
	glBegin(GL_POLYGON);
	glColor3f(0.282f, 0.239f, 0.545f); // DarkSLateBlue color
		glVertex3f(-2.0f, -18.0f, 0.0f); // Top-left corner
		glVertex3f(16.0f, -16.0f, 0.0f);  //Center
		glVertex3f(12.0f, -21.0f, 0.0f);  // Top-right corner
		glVertex3f(-4.0f, -24.0f, 0.0f); // Bottom-right corner
	glEnd();

	// Right lower leg
	glBegin(GL_POLYGON);
	glColor3f(0.282f, 0.239f, 0.545f); // DarkSLateBlue color
		glVertex3f(12.0f, -20.0f, 0.0f); // Top-left corner
		glVertex3f(16.0f, -16.0f, 0.0f);  //Center
		glVertex3f(13.0f, -34.0f, 0.0f);  // Top-right corner
		glVertex3f(11.0f, -36.0f, 0.0f); // Bottom-right corner
		glVertex3f(9.0f, -36.0f, 0.0f); 
		glVertex3f(9.0f, -26.0f, 0.0f); 
	glEnd();

	// right shoe
	glBegin(GL_POLYGON);
	glColor3f(0.627f, 0.322f, 0.176f); // DarkSLateBlue color
		glVertex3f(9.0f, -36.0f, 0.0f); // Top-left corner
		glVertex3f(11.0f, -36.0f, 0.0f);  //Center
		glVertex3f(16.0f, -39.0f, 0.0f);  // Top-right corner
		glVertex3f(18.0f, -39.0f, 0.0f); // Bottom-right corner
		glVertex3f(18.0f, -41.0f, 0.0f); 
		glVertex3f(9.0f, -41.0f, 0.0f); 
	glEnd();

	// hand
	glBegin(GL_POLYGON);
	glColor3f(0.294f, 0.0f, 0.510f); // Indigo color
		glVertex3f(5.0f, 6.0f, 0.0f); // Top-left corner
		glVertex3f(10.0f, 6.0f, 0.0f);  //Center
		glVertex3f(4.0f, -10.0f, 0.0f);  // Top-right corner
		glVertex3f(4.0f, -22.0f, 0.0f); // Bottom-left corner
		glVertex3f(0.0f, -22.0f, 0.0f); 
		glVertex3f(-1.0f, -10.0f, 0.0f); 
	glEnd();	

	// -----------------Bag
	glBegin(GL_POLYGON);
	glColor3f(0.722f, 0.525f, 0.043f); // Dark Golden Rod color
		glVertex3f(-5.0f, -27.0f, 0.0f); // Top-left corner
		glVertex3f(8.6f, -28.0f, 0.0f);  //Center
		glVertex3f(7.0f, -34.0f, 0.0f);  // Top-right corner
		glVertex3f(-5.6f, -33.0f, 0.0f); // Bottom-left corner
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.804f, 0.522f, 0.247f); // sienna color
		glVertex3f(-7.0f, -26.0f, 0.0f); // Top-left corner
		glVertex3f(-5.0f, -27.0f, 0.0f); // Top-left corner
		glVertex3f(-5.6f, -33.0f, 0.0f); // Bottom-left corner
		glVertex3f(-7.6f, -32.0f, 0.0f); // Bottom-left corner
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.804f, 0.522f, 0.247f); // sienna color
		glVertex3f(-7.0f, -26.0f, 0.0f); // Top-left corner
		glVertex3f(8.6f, -28.0f, 0.0f); // Top-left corner
		glVertex3f(-5.0f, -27.0f, 0.0f); // Bottom-left corner
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.804f, 0.522f, 0.247f); // sienna color
		glVertex3f(1.2f, -23.0f, 0.0f); // Top-left corner
		glVertex3f(2.5f, -23.0f, 0.0f);  //Center
		glVertex3f(-1.2f, -27.0f, 0.0f);  // Top-right corner
		glVertex3f(-2.5f, -27.0f, 0.0f); // Bottom-left corner
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.804f, 0.522f, 0.247f); // sienna color
		glVertex3f(1.2f, -23.0f, 0.0f); // Top-left corner
		glVertex3f(2.5f, -23.0f, 0.0f);  //Center
		glVertex3f(4.2f, -28.0f, 0.0f);  // Top-right corner
		glVertex3f(6.5f, -28.0f, 0.0f); // Bottom-left corner
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.894f, 0.769f); // Bisque color
		glVertex3f(0.4f, -29.0f, 0.0f); // Top-left corner
		glVertex3f(2.5f, -29.5f, 0.0f);  //Center
		glVertex3f(1.6f, -30.5f, 0.0f);  // Top-right corner
		glVertex3f(0.5f, -31.5f, 0.0f); // Bottom-left corner
	glEnd();

	// -------------Bag

	// ----- handle (Panja)
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.894f, 0.769f); // Bisque color
		glVertex3f(-0.5f, -22.0f, 0.0f); // Top-left corner
		glVertex3f(4.5f, -22.0f, 0.0f);  //Center
		glVertex3f(4.6f, -26.0f, 0.0f);  // Top-right corner
		glVertex3f(-1.0f, -26.0f, 0.0f); // Bottom-left corner
	glEnd();
}
