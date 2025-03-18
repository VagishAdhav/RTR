/* ---------------------------------------------- */

/* Windows System */
#include <Windows.h>
#include <math.h>

/* openGL Headers */
//#include <gl/GL.h>
/* #include <gl/GLU.h> */

/* FreeGlut Header */
#include "GL/freeglut.h"

/* ---------------------------------------------- */

#define GL_PI 3.145
#define DEG_TO_RAD(deg) (deg * (GL_PI / 180.0))
/* ---------------------------------------------- */

void SetupRC(void);
void ChangeSize(GLsizei, GLsizei);
void RenderScene(void);
void TimerFunc(int n);
void SpecialKeys(int key, int x, int y);
void KeyBoardFunc(unsigned char key, int x, int y);

/* Global variables */
#define MY_PI 3.14159265359
#define PRECISION 100
#define TIMER 100
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

GLboolean render = FALSE;

GLfloat r1 = 1.0f, g1 = 0.0f, b1 = 0.0f;
GLfloat r2 = 0.0f, g2 = 1.0f, b2 = 0.0f;
GLfloat r3 = 0.0f, g3 = 0.0f, b3 = 1.0f;

GLfloat aspectRatio;
/*
int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("CPU Cabinet");
    glutFullScreen();
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutKeyboardFunc(KeyBoardFunc);
    glutDisplayFunc(RenderScene);
    glutTimerFunc(TIMER, TimerFunc, 0);
    SetupRC();
    glutMainLoop();
    return (0);
}

void SetupRC(void){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    r1 = 1.0f;
    g1 = 0.0f;
    b1 = 0.0f;

    r2 = 0.0f;
    g2 = 1.0f;
    b2 = 0.0f;

    r3 = 0.0f;
    g3 = 0.0f;
    b3 = 1.0f;

    glShadeModel(GL_SMOOTH);
}

void ChangeSize(GLsizei w, GLsizei h){
    if(h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /* 
        To validate/confirm the working of viewing volume, just change the z values in glOrtho and see how it works
        For example, my model coordinate system is : 
            x: -50 to 50
            y: -50 to 50
            z: -50 to 50
        Now if I have my glOrtho set to -25 to 25 for z axis, then you can observe the animation, concluding only what is drawn is inside viewing volume
    

    aspectRatio = (GLfloat)w / (GLfloat)h;
    if(w <= h){
        glOrtho(-100.0, 100.0, -100.0 / aspectRatio, 100.0 / aspectRatio, -100.0f, 100.f);
    }
    else{
        glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, -100.0f, 100.f);
    }
    

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void SpecialKeys(int key, int x, int y){
    if (key == GLUT_KEY_DOWN)
        render = TRUE;
    glutPostRedisplay();
}

void KeyBoardFunc(unsigned char key, int x, int y){
    if(key == VK_ESCAPE){
        exit(0);
    }
}
*/


void drawCPU(void){
    void drawFan(GLfloat, GLfloat, GLfloat);
    void drawCabinet(GLfloat cabinetTop, GLfloat cabinetBottom);
    void drawPowerButtonAndIOPorts(GLfloat);
    
    GLfloat x = 0.0f;
    GLfloat y = 0.0f;
    GLfloat radius = 20.0f;
    GLfloat cabinetTop = 85.0f;
    GLfloat cabinetBottom = -75.0f;

    glPushMatrix();
    drawCabinet(cabinetTop, cabinetBottom);
    glPopMatrix();

    glPushMatrix();
    drawPowerButtonAndIOPorts(cabinetTop);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 50.0f, 0.0f);
    drawFan(x, y, radius);
    glPopMatrix();

    glPushMatrix();
    drawFan(x, y, radius);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -50.0f, 0.0f);
    drawFan(x, y, radius);
    glPopMatrix();

}

void TimerFuncCPU(int n){

    if(r1 == 1.0f){
        r1 = 0.0f;
        g1 = 1.0f;
        b1 = 0.0f;
    }
    else if(g1 == 1.0f){
        r1 = 0.0f;
        g1 = 0.0f;
        b1 = 1.0f;
    }
    else if(b1 == 1.0f){
        r1 = 1.0f;
        g1 = 0.0f;
        b1 = 0.0f;
    }

    if(r2 == 1.0f){
        r2 = 0.0f;
        g2 = 1.0f;
        b2 = 0.0f;
    }
    else if(g2 == 1.0f){
        r2 = 0.0f;
        g2 = 0.0f;
        b2 = 1.0f;
    }
    else if(b2 == 1.0f){
        r2 = 1.0f;
        g2 = 0.0f;
        b2 = 0.0f;
    }

    if(r3 == 1.0f){
        r3 = 0.0f;
        g3 = 1.0f;
        b3 = 0.0f;
    }
    else if(g3 == 1.0f){
        r3 = 0.0f;
        g3 = 0.0f;
        b3 = 1.0f;
    }
    else if(b3 == 1.0f){
        r3 = 1.0f;
        g3 = 0.0f;
        b3 = 0.0f;
    }
}

void drawFan(GLfloat x, GLfloat y, GLfloat radius){
    GLint angle;

    radius = 20.0f;
    glEnable(GL_BLEND);
    glBlendFunc(GL_DST_ALPHA, GL_SRC_ALPHA);
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(x, y, 0.0f);

        glColor4f(r1, g1, b1, 1.0f);
		for(angle = 0 ; angle <= (120); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(x, y, 0.0f);

        glColor4f(r2, g2,b2, 1.0f);
		for(angle = 120 ; angle <= (240); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(x, y, 0.0f);

        glColor4f(r3, g3, b3, 1.0f);
		for(angle = 240 ; angle <= (360); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();
    glDisable(GL_BLEND);

    /* */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(x, y, 0.0f);

        glColor4f(r1, g1, b1, 1.0f);
		for(angle = 60 ; angle <= (180); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(x, y, 0.0f);

        glColor4f(r2, g2,b2, 1.0f);
		for(angle = 180 ; angle <= (300); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(x, y, 0.0f);

        glColor4f(r3, g3, b3, 1.0f);
		for(angle = 300 ; angle <= (420); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();
    glDisable(GL_BLEND);
    /*  */

    radius = 15.0f;
    glEnable(GL_BLEND);
    glBlendFunc(GL_DST_ALPHA, GL_SRC_ALPHA);
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
        glVertex3f(x, y, 0.0f);
        for(angle = 0 ; angle <= (360); angle = angle + 10){
            glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
        }
    glEnd();
    glDisable(GL_BLEND);
    
    radius = 10.0f;
    glEnable(GL_BLEND);
    glBlendFunc(GL_DST_ALPHA, GL_SRC_ALPHA);
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(x, y, 0.0f);

        glColor4f(r3, g3, b3, 1.0f);
		for(angle = 0 ; angle <= (120); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(x, y, 0.0f);

        glColor4f(r1, g1, b1, 1.0f);
		for(angle = 120 ; angle <= (240); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(x, y, 0.0f);

        glColor4f(r2, g2, b2, 1.0f);
		for(angle = 240 ; angle <= (360); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();
    glDisable(GL_BLEND);

    /* */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(x, y, 0.0f);

        glColor4f(r1, g1, b1, 1.0f);
		for(angle = 60 ; angle <= (180); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(x, y, 0.0f);

        glColor4f(r2, g2,b2, 1.0f);
		for(angle = 180 ; angle <= (300); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(x, y, 0.0f);

        glColor4f(r3, g3, b3, 1.0f);
		for(angle = 300 ; angle <= (420); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();
    glDisable(GL_BLEND);
    /*  */
    radius = 5.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(x, y, 0.0f);
        for(angle = 0 ; angle <= (360); angle = angle + 10){
            glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
        }
    glEnd();
}

void drawCabinet(GLfloat cabinetTop, GLfloat cabinetBottom){
    cabinetBottom = -cabinetBottom;
    /* Central black */
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex3f(-25.0f, cabinetTop, 0.0f);
        glVertex3f(-25.0f, -cabinetBottom, 0.0f);
        glVertex3f(25.0f, -cabinetBottom, 0.0f);
        glVertex3f(25.0f, cabinetTop, 0.0f);
    glEnd();

    /* Top Gray Line */
    glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
        glVertex3f(-25.0f, cabinetTop, 0.0f);
        glVertex3f(-25.0f, cabinetTop - 3.0f, 0.0f);
        glVertex3f(25.0f, cabinetTop - 3.0f, 0.0f);
        glVertex3f(25.0f, cabinetTop, 0.0f);
    glEnd();
    glDisable(GL_BLEND);

    /* Bottom Gray Line */
    glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
        glVertex3f(-25.0f, -cabinetBottom, 0.0f);
        glVertex3f(-25.0f, -(cabinetBottom - 3.0f), 0.0f);
        glVertex3f(25.0f, -(cabinetBottom - 3.0f), 0.0f);
        glVertex3f(25.0f, -cabinetBottom, 0.0f);
    glEnd();
    glDisable(GL_BLEND);

    /* Left Gray Line */
    glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
        glVertex3f(-25.0f, cabinetTop, 0.0f);
        glVertex3f(-25.0f, -cabinetBottom, 0.0f);
        glVertex3f(-22.0f, -cabinetBottom, 0.0f);
        glVertex3f(-22.0f, cabinetTop, 0.0f);
    glEnd();
    glDisable(GL_BLEND);

    /* Right Gray Line */
    glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
        glVertex3f(25.0f, cabinetTop, 0.0f);
        glVertex3f(22.0f, cabinetTop, 0.0f);
        glVertex3f(22.0f, -cabinetBottom, 0.0f);
        glVertex3f(25.0f, -cabinetBottom, 0.0f);
    glEnd();
    glDisable(GL_BLEND);

    /* Top Top */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
        glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
        glVertex3f(-25.0f, cabinetTop, 0.0f);
        glColor4f(0.2f, 0.2f, 0.2f, 0.5f);
        glVertex3f(-28.0f, cabinetTop + 3.0f, 0.0f);
        glColor4f(0.2f, 0.2f, 0.2f, 0.5f);
        glVertex3f(28.0f, cabinetTop + 3.0f, 0.0f);
        glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
        glVertex3f(25.0f, cabinetTop, 0.0f);
    glEnd();
    glDisable(GL_BLEND);

    /* Bottom Bottom */
    /* glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
        glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
        glVertex3f(-25.0f, -75.0f, 0.0f);
        glColor4f(0.2f, 0.2f, 0.2f, 0.5f);
        glVertex3f(-28.0f, -78.0f, 0.0f);
        glColor4f(0.2f, 0.2f, 0.2f, 0.5f);
        glVertex3f(28.0f, -78.0f, 0.0f);
        glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
        glVertex3f(25.0f, -75.0f, 0.0f);
    glEnd();
    glDisable(GL_BLEND); */

    /* Left Left */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
        glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
        glVertex3f(-25.0f, cabinetTop, 0.0f);
        glColor4f(0.2f, 0.2f, 0.2f, 0.5f);
        glVertex3f(-28.0f, cabinetTop + 3.0f, 0.0f);
        glColor4f(0.2f, 0.2f, 0.2f, 0.5f);
        glVertex3f(-28.0f, -(cabinetBottom - 3.0f), 0.0f);
        glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
        glVertex3f(-25.0f, -cabinetBottom, 0.0f);
    glEnd();
    glDisable(GL_BLEND);

    /* Right Right */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
        glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
        glVertex3f(25.0f, cabinetTop, 0.0f);
        glColor4f(0.2f, 0.2f, 0.2f, 0.5f);
        glVertex3f(28.0f, cabinetTop + 3.0f, 0.0f);
        glColor4f(0.2f, 0.2f, 0.2f, 0.5f);
        glVertex3f(28.0f, -(cabinetBottom - 3.0f), 0.0f);
        glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
        glVertex3f(25.0f, -cabinetBottom, 0.0f);
    glEnd();
    glDisable(GL_BLEND);

    /* Top Left Line */
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor4f(0.8f, 0.8f, 0.8f, 1.0f);
        glVertex3f(-25.0f, cabinetTop, 0.0f);
        glVertex3f(-28.0f, cabinetTop + 3.0f, 0.0f);
    glEnd();

    /* Top Right Line */
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor4f(0.8f, 0.8f, 0.8f, 1.0f);
        glVertex3f(25.0f, cabinetTop, 0.0f);
        glVertex3f(28.0f, cabinetTop + 3.0f, 0.0f);
    glEnd();
}

void drawPowerButtonAndIOPorts(GLfloat cabinetTop){
    GLfloat x, y, radius, angle;
    x = -15.0f;
    y = 77.0f;

    /* White Circle */
    radius = 2.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(x, y, 0.0f);
		for(angle = 0 ; angle <= (360); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();

    /* Black Circle within white circle */
    radius = 1.8f;
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(x, y, 0.0f);
		for(angle = 0 ; angle <= (360); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();

    /* Quad above black circle to cut white circle for line */
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(x - 1, y, 0.0f);
    glVertex3f(x + 1, y, 0.0f);
    glVertex3f(x + 1, y + 2, 0.0f);
    glVertex3f(x - 1, y + 2, 0.0f);
    glEnd();

    /* Power button line drawn using quad */
    glColor4f(0.8f, 0.2f, 0.1f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(x - 0.2, y, 0.0f);
    glVertex3f(x + 0.2, y, 0.0f);
    glVertex3f(x + 0.2, y + 2, 0.0f);
    glVertex3f(x - 0.2, y + 2, 0.0f);
    glEnd();

    /* USB 1 */
    glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(x + 5, y + 1, 0.0f);
    glVertex3f(x + 5, y - 1, 0.0f);
    glVertex3f(x + 10, y - 1, 0.0f);
    glVertex3f(x + 10, y + 1, 0.0f);
    glEnd();

    glColor4f(0.3f, 0.4f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(x + 5.5, y + 0.8, 0.0f);
    glVertex3f(x + 5.5, y, 0.0f);
    glVertex3f(x + 9.5, y, 0.0f);
    glVertex3f(x + 9.5, y + 0.8, 0.0f);
    glEnd();

    /* USB 2 */
    glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(x + 15, y + 1, 0.0f);
    glVertex3f(x + 15, y - 1, 0.0f);
    glVertex3f(x + 20, y - 1, 0.0f);
    glVertex3f(x + 20, y + 1, 0.0f);
    glEnd();

    glColor4f(0.3f, 0.4f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(x + 15.5, y + 0.8, 0.0f);
    glVertex3f(x + 15.5, y, 0.0f);
    glVertex3f(x + 19.5, y, 0.0f);
    glVertex3f(x + 19.5, y + 0.8, 0.0f);
    glEnd();

    /* Draw Audio 1 */
    x = 12.0f;
    y = 77.0f;
    radius = 1.8f;
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(0.7f, 0.9f, 0.1f, 1.0f);
        glVertex3f(x, y, 0.0f);
		for(angle = 0 ; angle <= (360); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();
    radius = 1.3f;
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(x, y, 0.0f);
		for(angle = 0 ; angle <= (360); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();

    /* Draw Audio 2 */
    /* Draw Audio 1 */
    x = 18.0f;
    y = 77.0f;
    radius = 1.8f;
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(0.7f, 0.4f, 0.6f, 1.0f);
        glVertex3f(x, y, 0.0f);
		for(angle = 0 ; angle <= (360); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();
    radius = 1.3f;
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(x, y, 0.0f);
		for(angle = 0 ; angle <= (360); angle = angle + 10){
			glVertex3f(x + (radius * cos(DEG_TO_RAD(angle))), y + (radius * sin(DEG_TO_RAD(angle))), 0.0f);
		}
	glEnd();
}