#include "GL/freeglut.h"

#include "math.h"

#define MY_PI   (3.14159265358979323846264338327950288)

extern GLfloat fRange;

static void drawBorder(void);
static void drawCircle(float, float, float);

void drawBottomCabinet(void)
{
    glColor3f(1.0f, 0.894f, 0.710f);
    glBegin(GL_QUADS);
        glVertex3f(-20.0f, -30.0f, 0.0f);               // front
        glVertex3f(-20.0f, 30.0f, 0.0f);
        glVertex3f(20.0f, 30.0f, 0.0f);
        glVertex3f(20.0f, -30.0f, 0.0f);

        glColor3f(0.980f,0.980f, 0.804f);               // top
        glVertex3f(-20.0f, 30.0f, 0.0f);
        glVertex3f(-15.0f, 35.0f, 0.0f);
        glVertex3f(25.0f, 35.0f, 0.0f);
        glVertex3f(20.0f, 30.0f, 0.0f);
//
        glVertex3f(20.0f, -30.0f, 0.0f);                // side right
        glVertex3f(20.0f, 30.0f, 0.0f);
        glVertex3f(25.0f, 35.0f, 0.0f);
        glVertex3f(25.0f, -25.0f, 0.0f);
//
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(7.0f, -30.0f, 0.0f);                 // bottom stand right
        glVertex3f(13.0f, -30.0f, 0.0f);
        glVertex3f(12.0f, -33.0f, 0.0f);
        glVertex3f(8.0f, -33.0f, 0.0f);
//
        glVertex3f(-7.0f, -30.0f, 0.0f);                // bottom stand left
        glVertex3f(-13.0f, -30.0f, 0.0f);
        glVertex3f(-12.0f, -33.0f, 0.0f);
        glVertex3f(-8.0f, -33.0f, 0.0f);

    glEnd();

    drawBorder();                                       // border and middle lines

    glBegin(GL_QUADS);                                  // 3 rectangles
        glColor3f(1.0f, 0.973f, 0.863f);
        glVertex3f(-15.0f, 12.5f, 0.0f);
        glVertex3f(-15.0f, 25.0f, 0.0f);
        glVertex3f(15.0f, 25.0f, 0.0f);
        glVertex3f(15.0f, 12.5f, 0.0f);
//
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-4.5f, 21.0f, 0.0f);
        glVertex3f(4.5f, 21.0f, 0.0f);
        glVertex3f(4.5f, 16.0f, 0.0f);
        glVertex3f(-4.5f, 16.0f, 0.0f);
//
        glVertex3f(-12.0f, 21.0f, 0.0f);
        glVertex3f(-7.0f, 21.0f, 0.0f);
        glVertex3f(-7.0f, 16.0f, 0.0f);
        glVertex3f(-12.0f, 16.0f, 0.0f);
        
        glVertex3f(12.0f, 21.0f, 0.0f);
        glVertex3f(7.0f, 21.0f, 0.0f);
        glVertex3f(7.0f, 16.0f, 0.0f);
        glVertex3f(12.0f, 16.0f, 0.0f);
        
    glEnd();

    drawCircle(9.0f, -19.0f, 6.0f);                    // bottom circles
    drawCircle(-9.0f, -19.0f, 6.0f);
    glColor3f(0.824f, 0.706f, 0.549f);
    drawCircle(-9.0f, -19.0f, 4.0f);
    glColor3f(1.0f, 0.894f, 0.710f);
    drawCircle(9.0f, -19.0f, 4.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(9.0f, -19.0f, 2.0f);
//
    glEnable(GL_POINT_SMOOTH);
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    glVertex3f(-17.5f, -27.5f, 0.0f);
    glEnd();
    glPointSize(1.0f);
    glDisable(GL_POINT_SMOOTH);

}

static void drawBorder(void)
{
    glLineWidth(6.0f);

    glBegin(GL_LINE_LOOP);
        glVertex3f(-20.0f, -30.0f, 0.0f);               // front
        glVertex3f(-20.0f, 30.0f, 0.0f);
        glVertex3f(20.0f, 30.0f, 0.0f);
        glVertex3f(20.0f, -30.0f, 0.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3f(-20.0f, 30.0f, 0.0f);                // top
        glVertex3f(-15.0f, 35.0f, 0.0f);
        glVertex3f(25.0f, 35.0f, 0.0f);
        glVertex3f(20.0f, 30.0f, 0.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);        
        glVertex3f(20.0f, -30.0f, 0.0f);                // side right
        glVertex3f(20.0f, 30.0f, 0.0f);
        glVertex3f(25.0f, 35.0f, 0.0f);
        glVertex3f(25.0f, -25.0f, 0.0f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-15.0f, 12.5f, 0.0f);
        glVertex3f(-15.0f, 25.0f, 0.0f);
        glVertex3f(15.0f, 25.0f, 0.0f);
        glVertex3f(15.0f, 12.5f, 0.0f);
    glEnd();

    glLineWidth(9.0f);

    glBegin(GL_LINES);                                  // lines at center
        glVertex3f(-13.0f, 7.5f, 0.0f);
        glVertex3f(13.0f, 7.5f, 0.0f);

        glVertex3f(-13.0f, 2.5f, 0.0f);
        glVertex3f(13.0f, 2.5f, 0.0f);

        glVertex3f(-13.0f, -7.5f, 0.0f);
        glVertex3f(13.0f, -7.5f, 0.0f);

        glVertex3f(-13.0f, -2.5f, 0.0f);
        glVertex3f(13.0f, -2.5f, 0.0f);
        
    glEnd();
}

static void drawCircle(float x, float y, float r)
{
	glBegin(GL_TRIANGLES);
		for(float angle = 0.0f ; angle <= 2 * MY_PI; angle = angle + 0.05f) {
			glVertex3f(x, y, 0.0f);
			glVertex3f(x + (r * sin(angle)), y + (r * cos(angle)), 0.0f);
			glVertex3f(x + (r * sin(angle + 0.05)), y +(r * cos(angle + 0.05)), 0.0f);
		}
	glEnd();
}

