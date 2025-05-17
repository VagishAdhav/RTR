// Header files
#include "GL/freeglut.h"
#include<math.h>
#include "Drawings.h"

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
	void drawAshish();
	void drawTopBorder();
	void drawTriangle();
	void drawRightTriangle();
	void drawGift();
	
	
	// code	
	glPushMatrix();
    glTranslatef(90.0f, 20.0f, 0.0f);
    glScalef(1.0f, 1.0f, 0.0f);
	drawHappy();
	glPopMatrix();
	
	glPushMatrix();
    glTranslatef(60.0f, 10.0f, 0.0f);
    glScalef(1.0f, 1.0f, 0.0f);
	drawBirthday();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(80.0f, 0.0f, 0.0f);
    glScalef(1.0f, 1.0f, 0.0f);
	drawAshish();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0.0f, -60.0f, 0.0f);
    glScalef(0.6f, 0.6f, 0.0f);
	drawBithdayCake();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(-80.0f, -30.0f, 0.0f);
    glScalef(0.3f, 0.3f, 0.0f);
	drawTriangle();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(80.0f, -30.0f, 0.0f);
    glScalef(0.3f, 0.3f, 0.0f);
	drawRightTriangle();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(130.0f, 30.0f, 0.0f);
    glScalef(0.7f, 0.7f, 0.0f);
	drawGift();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(-110.0f, 30.0f, 0.0f);
    glScalef(0.7f, 0.7f, 0.0f);
	drawGift();
    glPopMatrix();
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
	drawCircle(-80.0f, -130.0f, 10.0f, mycolor);

	// red color
	mycolor.red = 1.0f,
	mycolor.green = 0.0f,
	mycolor.blue = 0.0f,
	drawCircle(-50.0f, -130.0f, 10.0f, mycolor);

	// blue color
	mycolor.red = 0.0f,
	mycolor.green = 0.0f,
	mycolor.blue = 1.0f,
	drawCircle(-20.0f, -130.0f, 10.0f, mycolor);

	// yellow color
	mycolor.red = 1.0f,
	mycolor.green = 1.0f,
	mycolor.blue = 0.0f,
	drawCircle(10.0f, -130.0f, 10.0f, mycolor);

	// purple color
	mycolor.red = 0.5f,
	mycolor.green = 0.0f,
	mycolor.blue = 1.0f,
	drawCircle(40.0f, -130.0f, 10.0f, mycolor);

	// purple color
	mycolor.red = 1.0f,
	mycolor.green = 0.0f,
	mycolor.blue = 1.0f,
	drawCircle(70.0f, -130.0f, 10.0f, mycolor);
}


static void drawCircle(GLfloat origin_x, GLfloat origin_y, GLfloat circle_radius, struct Mycolor mycolor)
{
	// variable declarations
	#define MY_PI	3.14151617

	// code
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

	// code
    glLineWidth(4.0f);
    glPointSize(4.0f);

    /* HAPPY */
	// rgb(243, 5, 5);
    glColor3ub(243, 5, 5);
    drawH(-120.0f, 50.0f, 10.0f);

	// rgb(227, 103, 36);
    glColor3ub(227, 103, 36);
    drawA(-100.0f, 50.0f, 10.0f);

	// rgb(24, 6, 180);
    glColor3ub(24, 6, 180);
    drawP(-80.0f, 50.0f, 10.0f);

	// rgb(243, 243, 11);
    glColor3ub(243, 243, 11);
    drawP(-60.0f, 50.0f, 10.0f);

	// rgb(239, 12, 224);
    glColor3ub(239, 12, 224);
    drawY(-40.0f, 50.0f, 10.0f);
	
    glLineWidth(1.0f);
    glPointSize(1.0f);
}


void drawBirthday()
{


	// code
    glLineWidth(4.0f);
    glPointSize(4.0f);


    /* BIRTHDAY */
	// rgb(12, 168, 235);
	glColor3ub(12, 168, 235);
    drawB(-120.0f, 50.0f - 20.0f, 10.0f);

	// rgb(9, 243, 63);
	glColor3ub(9, 243, 63);
    drawI(-100.0f, 50.0f - 20.0f, 10.0f);
    
	// rgb(232, 171, 59);
	glColor3ub(232, 171, 59);
	drawR(-80.0f, 50.0f - 20.0f, 10.0f);
    
	// rgb(151, 26, 26);
	glColor3ub(151, 26, 26);
	drawT(-60.0f, 50.0f - 20.0f, 10.0f);
    
	// rgb(108, 5, 243);
	glColor3ub(108, 5, 243);
	drawH(-40.0f, 50.0f - 20.0f, 10.0f);
    
	// rgb(10, 4, 127);
	glColor3ub(10, 4, 127);
	drawD(-20.0f, 50.0f - 20.0f, 10.0f);
    
	// rgb(11, 222, 229);
	glColor3ub(11, 222, 229);
	drawA(0.0f, 50.0f - 20.0f, 10.0f);
    
	// rgb(245, 201, 5);
	glColor3ub(245, 201, 5);
	drawY(20.0f, 50.0f - 20.0f, 10.0f);

    glLineWidth(1.0f);
    glPointSize(1.0f);
}


void drawAshish()
{


	// code
    glLineWidth(4.0f);
    glPointSize(4.0f);


    /* ASHISH */

	// rgb(255, 0, 0);
	glColor3ub(255, 0, 0);
	drawA(-120.0f, 50.0f - 20.0f - 20.0f, 10.0f);
    
	// rgb(255, 255, 0);
	glColor3ub(255, 255, 0);
	drawS(-100.0f, 50.0f - 20.0f - 20.0f, 10.0f);
    
	// rgb(0, 255, 0);
	glColor3ub(0, 255, 0);
	drawH(-80.0f, 50.0f - 20.0f - 20.0f, 10.0f);
    
	// rgb(255, 127, 0);
	glColor3ub(255, 127, 0);
	drawI(-60.0f, 50.0f - 20.0f - 20.0f, 10.0f);
    
	// rgb(255, 0, 255);
	glColor3ub(255, 0, 255);
	drawS(-40.0f, 50.0f - 20.0f - 20.0f, 10.0f);
    
	// rgb(0, 0, 255);
	glColor3ub(0, 0, 255);
	drawH(-20.0f, 50.0f - 20.0f - 20.0f, 10.0f);

    glLineWidth(1.0f);
    glPointSize(1.0f);
}


void drawRightTriangle()
{
	// Triangle Drawing code
    glBegin(GL_TRIANGLES);

    // Apex
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(0.0f, 50.0f, 0.0f);

    // Left Bottom
	// rgb(255, 0, 0);
	glColor3ub(255, 0, 0);
    glVertex3f(-70.0f, -30.0f, 0.0f);
    

    // Right Bottom
    // rgb(0, 255, 0);
    glColor3ub(0, 255, 0);
    glVertex3f(50.0f, -80.0f, 0.0f);

	glEnd();
}


void drawGift()
{
	// Outer Rectangle
	glBegin(GL_QUADS);

    // Top Right
	// rgb(255, 0, 0);
    glColor3ub(255, 0, 0);
    glVertex3f(30.0f, 20.0f, 0.0f);

	// Top Left
	// rgb(255, 0, 0);
    glColor3ub(255, 0, 0);
    glVertex3f(-30.0f, 20.0f, 0.0f);

	// Bottom Left
	// rgb(255, 0, 0);
    glColor3ub(255, 0, 0);
    glVertex3f(-30.0f, -20.0f, 0.0f);

	// Bottom Right
	// rgb(255, 0, 0);
    glColor3ub(255, 0, 0);
    glVertex3f(30.0f, -20.0f, 0.0f);

	glEnd();


	// Inner Rectangle Verticle
	glBegin(GL_QUADS);

    // Top Right
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(5.0f, 20.0f, 0.0f);

	// Top Left
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(-5.0f, 20.0f, 0.0f);

	// Bottom Left
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(-5.0f, -20.0f, 0.0f);

	// Bottom Right
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(5.0f, -20.0f, 0.0f);

	glEnd();


	// Inner Rectangle Horizontal
	glBegin(GL_QUADS);

    // Top Right
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(30.0f, 5.0f, 0.0f);

	// Top Left
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(-30.0f, 5.0f, 0.0f);

	// Bottom Left
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(-30.0f, -5.0f, 0.0f);

	// Bottom Right
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(30.0f, -5.0f, 0.0f);

	glEnd();

	// Left Triangle
	glBegin(GL_TRIANGLES);

    // Apex
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(0.0f, 20.0f, 0.0f);

	// Top Left
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(-20.0f, 30.0f, 0.0f);

	// Bottom Left
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(-15.0f, 40.0f, 0.0f);

	glEnd();

	// Right Triangle
	glBegin(GL_TRIANGLES);

    // Apex
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(0.0f, 20.0f, 0.0f);

	// Top Left
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(15.0f, 25.0f, 0.0f);

	// Bottom Left
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(10.0f, 35.0f, 0.0f);

	glEnd();

}

void drawTriangle()
{
	// Triangle Drawing code
    glBegin(GL_TRIANGLES);

    // Apex
	// rgb(255, 255, 0);
    glColor3ub(255, 255, 0);
    glVertex3f(0.0f, 50.0f, 0.0f);

    // Left Bottom
	// rgb(255, 0, 0);
	glColor3ub(255, 0, 0);
    glVertex3f(-50.0f, -80.0f, 0.0f);

    // Right Bottom
    // rgb(0, 255, 0);
    glColor3ub(0, 255, 0);
    glVertex3f(70.0f, -30.0f, 0.0f);

	glEnd();
}
