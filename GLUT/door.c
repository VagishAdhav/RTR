// Header files
#include "GL/freeglut.h"
#include <math.h>

void drawDoorLeft(void)
{
	// Left door frame
	glLineWidth(10);

	glBegin(GL_LINES);
	//glColor3f(1.0f, 0.0f, 0.0f); 
	glColor3f(0.53f, 0.302f, 0.102f); // Brown
	glVertex2f(-90, 30);
	glVertex2f(-60, 27);
	glVertex2f(-60, 28.5);
	glVertex2f(-60, -43);
	glVertex2f(-90, -40);
	glVertex2f(-90, 32);
	glEnd();

	// Left door 1st box
	glBegin(GL_POLYGON);
	//glColor3f(0.0f, 0.2f, 0.9f); // 
	glVertex2f(-88, 27.5);
	glVertex2f(-75, 26.5);
	glVertex2f(-75, -3);
	glVertex2f(-88, -3);
	glEnd();

	// Left door 3rd box
	glBegin(GL_POLYGON);
	//glColor3f(0.0f, 0.2f, 0.9f); // 
	glVertex2f(-88, -4);
	glVertex2f(-75, -4);
	glVertex2f(-75, -38);
	glVertex2f(-88, -38);
	glEnd();

	// Left door inside room
	//glBegin(GL_POLYGON);
	//glColor3f(1.0f, 1.0f, 1.0f); // Black 
	//glVertex2f(-74.5, 27);
	//glVertex2f(-61, 26);
	//glVertex2f(-61, -40);
	//glVertex2f(-74.5, -40);
	glEnd();

	// Mechanical String above Left Door
	glColor3f(1.0f, 1.0f, 1.0f); //
	glRasterPos2f(-100.0, 50.0); //define position on the screen
	char* string1 = "MECHANICAL";
	while (*string1) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string1++);
	}
	
	glLineWidth(1.0f);
}

void drawDoorRight(void)
{

	// Computer String above Right Door
	glColor3f(1.0f, 1.0f, 1.0f); //
	glRasterPos2f(60.0, 50.0); //define position on the screen
	char* string2 = "COMPUTER";
	while (*string2) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string2++);
	}

	// Right door frame 
	glLineWidth(10);
	glBegin(GL_LINES);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glColor3f(0.53f, 0.302f, 0.102f); // Brown
	glVertex2f(90, 30);
	glVertex2f(60, 27);
	glVertex2f(60, 28.5);
	glVertex2f(60, -43);
	glVertex2f(90, -40);
	glVertex2f(90, 32);
	glEnd();

	// Right door 1st box
	glBegin(GL_POLYGON);
	//glColor3f(0.0f, 0.2f, 0.9f); // 
	glVertex2f(88, 27.5);
	glVertex2f(75, 26.5);
	glVertex2f(75, -3);
	glVertex2f(88, -3);
	glEnd();

	// Right door 3rd box
	glBegin(GL_POLYGON);
	//glColor3f(0.0f, 0.2f, 0.9f); // 
	glVertex2f(88, -4);
	glVertex2f(75, -4);
	glVertex2f(75, -38);
	glVertex2f(88, -38);
	glEnd();

	// Right door inside room
	//glBegin(GL_POLYGON);
	//glColor3f(1.0f, 1.0f, 1.0f); // Black 
	//glVertex2f(74.5, 27);
	//glVertex2f(61, 26);
	//glVertex2f(61, -40);
	//glVertex2f(74.5, -40);
	//glEnd();
	glLineWidth(1.0f);
}