// Header files
#include "GL/freeglut.h"
#include <math.h>

// Global variable declarations 

extern GLfloat fRange; 

#define M_PI   3.14159265358979323846264338327950288

/* Yogeshwar Sir Global Variables */
GLfloat flMargin = 5.0f; 

typedef struct Mycolor 
{
	float red;
	float green;
	float blue;
}Mycolor;

void drawLastScene(void)
{
	// function declarations
	void drawBithdayCake(void);
	void drawBallon(void);
	void drawHappy();
	void drawBirthday();
	void drawSagar();
	void drawTopBorder();

	// code
	glPushMatrix();
    glTranslatef(90.0f, 0.0f, 0.0f);
    glScalef(1.0f, 1.0f, 0.0f);
	drawBithdayCake();
    glPopMatrix();

	drawHappy();
	drawBirthday();
	drawSagar();
}

void drawBithdayCake(void)
{	
	// variable declarations
	float y = 0.0f;
	
	// code

	// Draw Base
	// rgb(255, 255, 255)
	glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
		glVertex3f(-60.0f, 0.0f, 0.0f);
		glVertex3f(-60.0f, 5.0f, 0.0f);
		glVertex3f(60.0f, 5.0f, 0.0f);
		glVertex3f(60.0f, 0.0f, 0.0f);
    glEnd();


	// Draw 1st Layer 
	y = 5.0f;  
	// rgb(101, 8, 8)
	glColor3ub(101, 8, 8);
    glBegin(GL_QUADS);
		glVertex3f(-50.0f, 0.0f + y, 0.0f);
		glVertex3f(-50.0f, 20.0f + y, 0.0f);
		glVertex3f(50.0f, 20.0f + y, 0.0f);
		glVertex3f(50.0f, 0.0f + y, 0.0f);
    glEnd();

	// Draw 2nd Layer 
	y = 20.0f + y;  
	// rgb(237, 233, 14)
	glColor3ub(237, 233, 14);
    glBegin(GL_QUADS);
		glVertex3f(-30.0f, 0.0f + y, 0.0f);
		glVertex3f(-30.0f, 20.0f + y, 0.0f);
		glVertex3f(30.0f, 20.0f + y, 0.0f);
		glVertex3f(30.0f, 0.0f + y, 0.0f);
	glEnd();

	// Draw Candle 
	y = 20.0f + y;  
	glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
		glVertex3f(-3.0f, 0.0f + y, 0.0f);
		glVertex3f(-3.0f, 30.0f + y, 0.0f);
		glVertex3f(3.0f, 30.0f + y, 0.0f);
		glVertex3f(3.0f, 0.0f + y, 0.0f);
	glEnd();

	// Draw Candle light
	y = 30.0f + y;  
	// rgb(237, 233, 14)
	glColor3ub(237, 233, 14);
    glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.0f + y, 0.0f);
		glVertex3f(1.0f, 4.0f + y, 0.0f);
		glVertex3f(0.0f, 8.0f + y, 0.0f);
		glVertex3f(-1.0f, 4.0f + y, 0.0f);
	glEnd();
	
}

void drawBallon(void)
{
	// function declarations
	static void drawCircle(GLfloat origin_x, GLfloat origin_y, GLfloat circle_radius, struct Mycolor mycolor);

	// variable declarations
	Mycolor mycolor;

	// green color
	mycolor.red = 0.0f,
	mycolor.green = 1.0f,
	mycolor.blue = 0.0f,
	drawCircle(-80.0f, -20.0f, 10.0f, mycolor);

	// red color
	mycolor.red = 1.0f,
	mycolor.green = 0.0f,
	mycolor.blue = 0.0f,
	drawCircle(-50.0f, -20.0f, 10.0f, mycolor);

	// blue color
	mycolor.red = 0.0f,
	mycolor.green = 0.0f,
	mycolor.blue = 1.0f,
	drawCircle(-20.0f, -20.0f, 10.0f, mycolor);


	// yellow color
	mycolor.red = 1.0f,
	mycolor.green = 1.0f,
	mycolor.blue = 0.0f,
	drawCircle(10.0f, -20.0f, 10.0f, mycolor);

	// purple color
	mycolor.red = 0.5f,
	mycolor.green = 0.0f,
	mycolor.blue = 1.0f,
	drawCircle(40.0f, -20.0f, 10.0f, mycolor);

	// purple color
	mycolor.red = 1.0f,
	mycolor.green = 0.0f,
	mycolor.blue = 1.0f,
	drawCircle(70.0f, -20.0f, 10.0f, mycolor);

}


static void drawCircle(GLfloat origin_x, GLfloat origin_y, GLfloat circle_radius, struct Mycolor mycolor)
{
	// code
	#define MY_PI	3.14151617

	// draw baloon circle
	glBegin(GL_TRIANGLES);
		glColor3f(mycolor.red, mycolor.green, mycolor.blue);
		for(GLfloat angle = 0.0f ; angle <= 2 * MY_PI; angle = angle + 0.05f)
		{
			glVertex3f(origin_x, origin_y, 0.0f);
			glVertex3f(origin_x + (circle_radius * sin(angle)), origin_y + (circle_radius * cos(angle)), 0.0f);
			glVertex3f(origin_x + (circle_radius * sin(angle + 0.05)), origin_y +(circle_radius * cos(angle + 0.05)), 0.0f);
		}

	glEnd();

	// draw baloon rope
	glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(origin_x, (origin_y - circle_radius), 0.0f);
			glVertex3f(origin_x, (origin_y - circle_radius - 30.0f) , 0.0f);
	glEnd();
}


void drawHappy()
{
    void drawA(GLfloat Xbox, GLfloat Ybox, GLfloat xL); 
    void drawB(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawC(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawD(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawE(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawF(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawG(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawH(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawI(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawJ(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawK(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawL(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawM(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawN(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawO(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawP(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawQ(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawR(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawS(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawT(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawU(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawV(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawW(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawX(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawY(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawZ(GLfloat Xbox, GLfloat Ybox, GLfloat xL);

    glLineWidth(4.0f);
    glPointSize(4.0f);

    glColor3ub(24, 6, 180);
    /* HAPPY */
    drawH(-120.0f, 50.0f, 10.0f);
    drawA(-100.0f, 50.0f, 10.0f);
    drawP(-80.0f, 50.0f, 10.0f);
    drawP(-60.0f, 50.0f, 10.0f);
    drawY(-40.0f, 50.0f, 10.0f);

    glLineWidth(1.0f);
    glPointSize(1.0f);
}


void drawBirthday()
{

    void drawA(GLfloat Xbox, GLfloat Ybox, GLfloat xL); 
    void drawB(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawC(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawD(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawE(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawF(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawG(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawH(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawI(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawJ(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawK(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawL(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawM(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawN(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawO(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawP(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawQ(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawR(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawS(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawT(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawU(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawV(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawW(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawX(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawY(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawZ(GLfloat Xbox, GLfloat Ybox, GLfloat xL);

    glLineWidth(4.0f);
    glPointSize(4.0f);

	glColor3ub(24, 6, 180);
    /* BIRTHDAY */
    drawB(-120.0f, 50.0f - 20.0f, 10.0f);
    drawI(-100.0f, 50.0f - 20.0f, 10.0f);
    drawR(-80.0f, 50.0f - 20.0f, 10.0f);
    drawT(-60.0f, 50.0f - 20.0f, 10.0f);
    drawH(-40.0f, 50.0f - 20.0f, 10.0f);
    drawD(-20.0f, 50.0f - 20.0f, 10.0f);
    drawA(0.0f, 50.0f - 20.0f, 10.0f);
    drawY(20.0f, 50.0f - 20.0f, 10.0f);

    glLineWidth(1.0f);
    glPointSize(1.0f);
}


void drawSagar()
{

    void drawA(GLfloat Xbox, GLfloat Ybox, GLfloat xL); 
    void drawB(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawC(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawD(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawE(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawF(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawG(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawH(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawI(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawJ(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawK(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawL(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawM(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawN(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawO(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawP(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawQ(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawR(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawS(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawT(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawU(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawV(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawW(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawX(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawY(GLfloat Xbox, GLfloat Ybox, GLfloat xL);
    void drawZ(GLfloat Xbox, GLfloat Ybox, GLfloat xL);

    glLineWidth(5.0f);
    glPointSize(5.0f);

	// rgb(241, 230, 12)

    glColor3ub(241, 230, 12);
    /* SAGAR */
    drawS(-120.0f, 50.0f - 20.0f - 20.0f, 10.0f);
    drawA(-100.0f, 50.0f - 20.0f - 20.0f, 10.0f);
    drawG(-80.0f, 50.0f - 20.0f - 20.0f, 10.0f);
    drawA(-60.0f, 50.0f - 20.0f - 20.0f, 10.0f);
    drawR(-40.0f, 50.0f - 20.0f - 20.0f, 10.0f);

    glLineWidth(1.0f);
    glPointSize(1.0f);
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
	drawEllipticArc(Xbox, Ybox + xL/4, xL, xL/4, -M_PI/2, M_PI/2); 
	drawEllipticArc(Xbox, Ybox + (3*xL)/4, xL, xL/4, -M_PI/2, M_PI/2);
}

void drawC(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// function declarations 
	void drawEllipticArc(GLfloat Xc, GLfloat Yc, GLfloat a, GLfloat b, GLfloat thetaStart, 
		GLfloat thetaEnd); 

	// code 
	drawEllipticArc(Xbox + xL, Ybox + xL/2, xL, xL/2, M_PI/2, (3*M_PI)/2); 
	
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

	drawEllipticArc(Xbox, Ybox + xL/2, xL, xL/2, (-M_PI)/2, M_PI/2); 
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

	drawEllipticArc(Xbox + xL, Ybox + xL/2, xL, xL/2, (M_PI)/2, (3*M_PI)/2); 

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
			(8*M_PI)/7, (3*M_PI)/2); 
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

	drawCircularArc(Xbox + xL/2, Ybox + xL/2, xL/2, 0.0f, 2 * M_PI); 
}

void drawP(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// function declarations 
	void drawEllipticArc(GLfloat Xc, GLfloat Yc, GLfloat a, GLfloat b, GLfloat thetaStart, GLfloat thetaEnd); 

	// code 
	glBegin(GL_LINES);
		glVertex3f(Xbox, Ybox, 0.0f);
		glVertex3f(Xbox, Ybox + xL, 0.0f);  
	glEnd(); 

	drawEllipticArc(Xbox, Ybox + 3*xL/4, xL/2, xL/4, (-M_PI)/2, M_PI/2); 
}

void drawQ(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	// Function declarations 
	void drawCircularArc(GLfloat Xc, GLfloat Yc, GLfloat R, GLfloat thetaStart, GLfloat thetaEnd); 

	// code 
	drawCircularArc(Xbox + xL/2, Ybox + xL/2, xL/2, 0.0f, 2 * M_PI); 
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

	drawEllipticArc(Xbox, Ybox + 3*xL/4, xL/2, xL/4, (-M_PI)/2, M_PI/2); 
}

void drawS(GLfloat Xbox, GLfloat Ybox, GLfloat xL){
	void drawEllipticArc(GLfloat Xc, GLfloat Yc, GLfloat a, GLfloat b, GLfloat thetaStart, GLfloat thetaEnd); 

	// code 
	drawEllipticArc(Xbox, Ybox + xL/4, xL, xL/4, (3*M_PI)/2, 2 * M_PI);
	drawEllipticArc(Xbox + xL, Ybox + 3*xL/4, xL, xL/4, (M_PI)/2, M_PI);

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
		M_PI, 2 * M_PI); 
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