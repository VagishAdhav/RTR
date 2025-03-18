// Header files
#include "GL/freeglut.h"
#include <math.h>

// Global variable declarations 
extern GLfloat fRange; 
#define MY_PI 3.14159265359

/* Yogeshwar Sir's Drawing Functions For Letters */
static GLfloat flMargin = 5.0f; 

void drawCircularArc(GLfloat Xc, GLfloat Yc, GLfloat R, GLfloat thetaStart, GLfloat thetaEnd){
	// variables 
	const GLfloat thetaIncrement = 0.01f; 
	GLfloat theta;
	GLfloat x, y; 

	// code 
	glBegin(GL_POINTS); 
		for(theta = thetaStart; theta <= thetaEnd; theta += thetaIncrement)
		{
			x = Xc + R * cos(theta); 
			y = Yc + R * sin(theta);
			glVertex3f(x, y, 0.0f); 
		}
	glEnd(); 
}

void drawEllipticArc(GLfloat Xc, GLfloat Yc, GLfloat a, GLfloat b, GLfloat thetaStart, GLfloat thetaEnd){
	// variables 
	const GLfloat thetaIncrement = 0.01f; 
	GLfloat theta;
	GLfloat x, y; 

	// code 
	glBegin(GL_POINTS); 
		for(theta = thetaStart; theta <= thetaEnd; theta += thetaIncrement)
		{
			x = Xc + a * cos(theta); 
			y = Yc + b * sin(theta);
			glVertex3f(x, y, 0.0f); 
		}
	glEnd(); 
}


void drawA(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	glBegin(GL_LINES); 
		glVertex3f(Xbox+0.0f, Ybox+0.0f, 0.0f); 
		glVertex3f(Xbox+xL/2, Ybox+xL, 0.0f); 

		glVertex3f(Xbox+xL/2, Ybox+xL, 0.0f); 
		glVertex3f(Xbox+xL, Ybox+0.0f, 0.0f); 

		glVertex3f(Xbox+xL/4, Ybox+xL/2, 0.0f);
		glVertex3f(Xbox+(3.0f * xL)/4, Ybox+xL/2, 0.0f); 
	glEnd(); 
} 

void drawB(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// functions 
	void drawEllipticArc(GLfloat Xc, GLfloat Yc, GLfloat a, GLfloat b, GLfloat thetaStart, 
		GLfloat thetaEnd); 

	// code 
	glBegin(GL_LINES); 
		glVertex3f(Xbox, Ybox, 0.0f); 
		glVertex3f(Xbox, Ybox + xL, 0.0f); 
	glEnd(); 
	drawEllipticArc(Xbox, Ybox + xL/4, xL, xL/4, -MY_PI/2, MY_PI/2); 
	drawEllipticArc(Xbox, Ybox + (3*xL)/4, xL, xL/4, -MY_PI/2, MY_PI/2);
}

void drawC(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// function declarations 
	void drawEllipticArc(GLfloat Xc, GLfloat Yc, GLfloat a, GLfloat b, GLfloat thetaStart, 
		GLfloat thetaEnd); 

	// code 
	drawEllipticArc(Xbox + xL, Ybox + xL/2, xL, xL/2, MY_PI/2, (3*MY_PI)/2); 
	
	glBegin(GL_LINES); 
		glVertex3f(Xbox + xL, Ybox + 1.0f, 0.0f); 
		glVertex3f(Xbox + xL, Ybox - 1.0f, 0.0f); 
	glEnd();
	
	glBegin(GL_LINES); 
		glVertex3f(Xbox + xL, Ybox + xL + 1.0f, 0.0f); 
		glVertex3f(Xbox + xL, Ybox + xL - 1.0f, 0.0f); 
	glEnd(); 
}

void drawD(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// function declarations 
	void drawEllipticArc(GLfloat Xc, GLfloat Yc, GLfloat a, GLfloat b, GLfloat thetaStart, 
		GLfloat thetaEnd); 

	// code 
	glBegin(GL_LINES); 
		glVertex3f(Xbox, Ybox, 0.0f); 
		glVertex3f(Xbox,  Ybox + xL, 0.0f); 
	glEnd(); 

	drawEllipticArc(Xbox, Ybox + xL/2, xL, xL/2, (-MY_PI)/2, MY_PI/2); 
}

void drawE(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	glBegin(GL_LINES); 
		glVertex3f(Xbox, Ybox, 0.0f); 
		glVertex3f(Xbox,  Ybox + xL, 0.0f); 

		glVertex3f(Xbox, Ybox, 0.0f); 
		glVertex3f(Xbox + xL, Ybox, 0.0f);

		glVertex3f(Xbox, Ybox + xL/2, 0.0f); 
		glVertex3f(Xbox + xL, Ybox + xL/2, 0.0f);

		glVertex3f(Xbox, Ybox + xL, 0.0f); 
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 
	glEnd(); 
}

void drawF(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	glBegin(GL_LINES); 
		glVertex3f(Xbox, Ybox, 0.0f); 
		glVertex3f(Xbox,  Ybox + xL, 0.0f); 

		glVertex3f(Xbox, Ybox + xL/2, 0.0f); 
		glVertex3f(Xbox + xL, Ybox + xL/2, 0.0f);

		glVertex3f(Xbox, Ybox + xL, 0.0f); 
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 
	glEnd(); 
}

void drawG(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// function declarations 
	void drawEllipticArc(GLfloat Xc, GLfloat Yc, GLfloat a, GLfloat b, GLfloat thetaStart, 
		GLfloat thetaEnd); 

	drawEllipticArc(Xbox + xL, Ybox + xL/2, xL, xL/2, (MY_PI)/2, (3*MY_PI)/2); 

	glBegin(GL_LINES); 
		glVertex3f(Xbox + xL, Ybox, 0.0f); 
		glVertex3f(Xbox + xL, Ybox + flMargin, 0.0f); 

		glVertex3f(Xbox + xL - flMargin/2, Ybox + flMargin, 0.0f); 
		glVertex3f(Xbox + xL + flMargin/2, Ybox + flMargin, 0.0f); 

		glVertex3f(Xbox + xL, Ybox + xL - 1.0f, 0.0f); 
		glVertex3f(Xbox + xL, Ybox + xL + 1.0f, 0.0f); 
	glEnd();
}

void drawH(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	glBegin(GL_LINES); 
		glVertex3f(Xbox, Ybox, 0.0f); 
		glVertex3f(Xbox, Ybox + xL, 0.0f);

		glVertex3f(Xbox + xL, Ybox, 0.0f); 
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 

		glVertex3f(Xbox, Ybox + xL/2, 0.0f);
		glVertex3f(Xbox + xL, Ybox + xL/2, 0.0f);  
	glEnd(); 
}

void drawI(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	glBegin(GL_LINES);
		glVertex3f(Xbox + xL/2, Ybox, 0.0f); 
		glVertex3f(Xbox + xL/2, Ybox + xL, 0.0f);

		glVertex3f(Xbox + xL/2 - flMargin, Ybox, 0.0f);  
		glVertex3f(Xbox + xL/2 + flMargin, Ybox, 0.0f);

		glVertex3f(Xbox + xL/2 - flMargin, Ybox + xL, 0.0f);  
		glVertex3f(Xbox + xL/2 + flMargin, Ybox + xL, 0.0f);
	glEnd();  
}

void drawJ(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	void drawCircularArc(GLfloat Xc, GLfloat Yc, GLfloat R, 
		GLfloat thetaStart, GLfloat thetaEnd); 

	glBegin(GL_LINES);
		glVertex3f(Xbox + xL, Ybox, 0.0f); 
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 
	
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 
		glVertex3f(Xbox + xL - flMargin, Ybox + xL, 0.0f); 
	glEnd();  

	drawCircularArc(Xbox + xL, Ybox + flMargin, flMargin, 
			(8*MY_PI)/7, (3*MY_PI)/2); 
}

void drawK(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	glBegin(GL_LINES);
		glVertex3f(Xbox, Ybox, 0.0f); 
		glVertex3f(Xbox, Ybox + xL, 0.0f);

		glVertex3f(Xbox, Ybox + xL/2, 0.0f);  
		glVertex3f(Xbox + 3*xL/4, Ybox + xL, 0.0f); 

		glVertex3f(Xbox, Ybox + xL/2, 0.0f); 
		glVertex3f(Xbox + 3*xL/4, Ybox, 0.0f);  
	glEnd();  
}

void drawL(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	glBegin(GL_LINES);
		glVertex3f(Xbox, Ybox, 0.0f); 
		glVertex3f(Xbox, Ybox + xL, 0.0f);

		glVertex3f(Xbox, Ybox, 0.0f); 
		glVertex3f(Xbox + 3*xL/4, Ybox, 0.0f); 
	glEnd(); 
}

void drawM(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	glBegin(GL_LINES); 
		glVertex3f(Xbox, Ybox, 0.0f); 
		glVertex3f(Xbox, Ybox + xL, 0.0f); 

		glVertex3f(Xbox + xL, Ybox, 0.0); 
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 

		glVertex3f(Xbox, Ybox + xL, 0.0f); 
		glVertex3f(Xbox + xL/2, Ybox + xL/2, 0.0f); 

		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 
		glVertex3f(Xbox + xL/2, Ybox + xL/2, 0.0f); 
	glEnd(); 
}

void drawN(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	glBegin(GL_LINES); 
		glVertex3f(Xbox, Ybox, 0.0f); 
		glVertex3f(Xbox, Ybox + xL, 0.0f); 

		glVertex3f(Xbox + xL, Ybox, 0.0); 
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 

		glVertex3f(Xbox, Ybox + xL, 0.0f); 
		glVertex3f(Xbox + xL, Ybox, 0.0f);
	glEnd(); 
}

void drawO(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	void drawCircularArc(GLfloat Xc, GLfloat Yc, GLfloat R, GLfloat thetaStart, GLfloat thetaEnd); 

	drawCircularArc(Xbox + xL/2, Ybox + xL/2, xL/2, 0.0f, 2 * MY_PI); 
}

void drawP(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// function declarations 
	void drawEllipticArc(GLfloat Xc, GLfloat Yc, GLfloat a, GLfloat b, GLfloat thetaStart, GLfloat thetaEnd); 

	// code 
	glBegin(GL_LINES);
		glVertex3f(Xbox, Ybox, 0.0f);
		glVertex3f(Xbox, Ybox + xL, 0.0f);  
	glEnd(); 

	drawEllipticArc(Xbox, Ybox + 3*xL/4, xL/2, xL/4, (-MY_PI)/2, MY_PI/2); 
}

void drawQ(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// Function declarations 
	void drawCircularArc(GLfloat Xc, GLfloat Yc, GLfloat R, GLfloat thetaStart, GLfloat thetaEnd); 

	// code 
	drawCircularArc(Xbox + xL/2, Ybox + xL/2, xL/2, 0.0f, 2 * MY_PI); 
	glBegin(GL_LINES);
		glVertex3f(Xbox + xL/2, Ybox + xL/2, 0.0f); 
		glVertex3f(Xbox + xL, Ybox, 0.0f); 
	glEnd();  
}

void drawR(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// function declarations 
	void drawEllipticArc(GLfloat Xc, GLfloat Yc, GLfloat a, GLfloat b, GLfloat thetaStart, GLfloat thetaEnd); 

	// code 
	glBegin(GL_LINES);
		glVertex3f(Xbox, Ybox, 0.0f);
		glVertex3f(Xbox, Ybox + xL, 0.0f);  

		glVertex3f(Xbox, Ybox + xL/2, 0.0f); 
		glVertex3f(Xbox + xL/2, Ybox, 0.0f); 

		glVertex3f(Xbox + xL/2, Ybox, 0.0f);
		glVertex3f(Xbox + xL/2 + 1.0f, Ybox + 1.0f, 0.0f);

	glEnd(); 

	drawEllipticArc(Xbox, Ybox + 3*xL/4, xL/2, xL/4, (-MY_PI)/2, MY_PI/2); 
}

void drawS(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	void drawEllipticArc(GLfloat Xc, GLfloat Yc, GLfloat a, GLfloat b, GLfloat thetaStart, GLfloat thetaEnd); 

	// code 
	drawEllipticArc(Xbox, Ybox + xL/4, xL, xL/4, (3*MY_PI)/2, 2 * MY_PI);
	drawEllipticArc(Xbox + xL, Ybox + 3*xL/4, xL, xL/4, (MY_PI)/2, MY_PI);

	glBegin(GL_LINES); 
		glVertex3f(Xbox, Ybox + 3*xL/4, 0.0); 
		glVertex3f(Xbox + xL, Ybox + xL/4, 0.0f); 

		glVertex3f(Xbox, Ybox - 1.0f, 0.0); 
		glVertex3f(Xbox, Ybox + 1.0f, 0.0); 

		glVertex3f(Xbox + xL, Ybox + xL - 1.0f, 0.0); 
		glVertex3f(Xbox + xL, Ybox + xL + 1.0f, 0.0);
	glEnd(); 
}

void drawT(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	glBegin(GL_LINES);
		glVertex3f(Xbox + xL/2, Ybox, 0.0f); 
		glVertex3f(Xbox + xL/2, Ybox + xL, 0.0f);

		glVertex3f(Xbox, Ybox + xL, 0.0f); 
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 

		glVertex3f(Xbox, Ybox + xL, 0.0f);
		glVertex3f(Xbox - 1.0f, Ybox + xL - 1.0f, 0.0) ; 

		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 
		glVertex3f(Xbox + xL + 1.0f, Ybox + xL - 1.0f, 0.0f); 
	glEnd();  
}

void drawU(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// function declarations 
	void drawEllipticArc(GLfloat Xc, GLfloat Yc, GLfloat a, GLfloat b, GLfloat thetaStart, 
		GLfloat thetaEnd); 

	glBegin(GL_LINES); 
		glVertex3f(Xbox, Ybox + 0.3 * xL, 0.0f); 
		glVertex3f(Xbox, Ybox + xL, 0.0f); 

		glVertex3f(Xbox + xL, Ybox + 0.3 * xL, 0.0f); 
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 
	glEnd(); 

	drawEllipticArc(Xbox + xL/2, Ybox + 0.3 * xL, xL/2, 0.3*xL, 
		MY_PI, 2 * MY_PI); 
}

void drawV(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	glBegin(GL_LINES); 
		glVertex3f(Xbox, Ybox + xL, 0.0f); 
		glVertex3f(Xbox + xL/2, Ybox, 0.0f);

		glVertex3f(Xbox + xL/2, Ybox, 0.0f);  
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 
	glEnd(); 
}

void drawW(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	glBegin(GL_LINES); 
		glVertex3f(Xbox, Ybox + xL, 0.0f);
		glVertex3f(Xbox + 0.15 * xL, Ybox, 0.0); 
		
		glVertex3f(Xbox + 0.15 * xL, Ybox, 0.0); 
		glVertex3f(Xbox + xL/2, Ybox + xL/2, 0.0f); 

		glVertex3f(Xbox + xL/2, Ybox + xL/2, 0.0f);
		glVertex3f(Xbox + 0.85f * xL, Ybox, 0.0f);

		glVertex3f(Xbox + 0.85f * xL, Ybox, 0.0f);
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 
	glEnd(); 
}

void drawX(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	glBegin(GL_LINES); 
		glVertex3f(Xbox, Ybox, 0.0f); 
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 

		glVertex3f(Xbox, Ybox + xL, 0.0f); 
		glVertex3f(Xbox + xL, Ybox, 0.0f); 
	glEnd(); 
}

void drawY(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	glBegin(GL_LINES);
		glVertex3f(Xbox, Ybox + xL, 0.0f); 
		glVertex3f(Xbox + xL/2, Ybox + xL/2, 0.0f);

		glVertex3f(Xbox + xL, Ybox + xL, 0.0f); 
		glVertex3f(Xbox + xL/2, Ybox + xL/2, 0.0f);

		glVertex3f(Xbox + xL/2, Ybox + xL/2, 0.0f);
		glVertex3f(Xbox + xL/2, Ybox, 0.0f);  
	glEnd(); 
}

void drawZ(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// code 
	glBegin(GL_LINES);
		glVertex3f(Xbox, Ybox, 0.0f); 
		glVertex3f(Xbox + xL, Ybox, 0.0f);

		glVertex3f(Xbox, Ybox + xL, 0.0f); 
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f);

		glVertex3f(Xbox, Ybox, 0.0f);
		glVertex3f(Xbox + xL, Ybox + xL, 0.0f);  
	glEnd(); 
}
