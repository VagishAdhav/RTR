#include <math.h>
#include "GL/freeglut.h"
#include "Drawings.h"

#define MY_PI 3.14159265359

void drawPhotoFrame(void)
{

	glColor3f(0.0f, 0.0f, 1.0f);
	
	glBegin(GL_QUADS);
		glVertex3f(-125.0f, 65.0f, 0.0f);
		glVertex3f(130.0f, 65.0f, 0.0f);
		glVertex3f(130.0f, -55.0f, 0.0f);
		glVertex3f(-125.0f, -55.0f, 0.0f);

		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-120.0f, 60.0f, 0.0f);
		glVertex3f(125.0f, 60.0f, 0.0f);
		glVertex3f(125.0f, -50.0f, 0.0f);
		glVertex3f(-120.0f, -50.0f, 0.0f);

	glEnd();

	glEnable(GL_POINT_SMOOTH);
	glPointSize(2.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POINTS);
        for(float angle = 0.0f; angle <= (MY_PI); angle += 0.02f) {
            float x = cos(angle) * 15.0f + 5;
            float y = sin(angle) * 15.0f + 65;
            glVertex3f(x, y, 0.0f);
        }
    glEnd();

    glDisable(GL_POINT_SMOOTH);

    glPointSize(0.1f);
    glLineWidth(0.1f);

	glColor3f(0.0f, 1.0f, 0.0f);

    drawK(-90.0f, 30.0f, 15.0f);
	drawN(-70.0f, 30.0f, 15.0f);
	drawO(-50.0f, 30.0f, 15.0f);
	drawW(-30.0f, 30.0f, 15.0f);
	drawL(-10.0f, 30.0f, 15.0f);
	drawE(10.0f, 30.0f, 15.0f);
	drawD(30.0f, 30.0f, 15.0f);
	drawG(50.0f, 30.0f, 15.0f);
	drawE(70.0f, 30.0f, 15.0f);

	drawI(-10.0f, 0.0f, 15.0f);
	drawS(10.0f, 0.0f, 15.0f);
	
	drawI(-110.0f, -30.0f, 15.0f);
	drawN(-90.0f, -30.0f, 15.0f);
	drawT(-70.0f, -30.0f, 15.0f);
	drawE(-50.0f, -30.0f, 15.0f);
	drawR(-30.0f, -30.0f, 15.0f);
	drawR(-15.0f, -30.0f, 15.0f);
	drawE(0.0f, -30.0f, 15.0f);
	drawL(20.0f, -30.0f, 15.0f);
	drawA(35.0f, -30.0f, 15.0f);
	drawT(55.0f, -30.0f, 15.0f);
	drawE(75.0f, -30.0f, 15.0f);
	drawD(95.0f, -30.0f, 15.0f);    
}