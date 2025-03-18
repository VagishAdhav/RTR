#include "GL/freeglut.h"
#include <math.h>

#define placement 6.0f

void drawMug(void)
{
    //variables
    const float PI = 3.14f;


    #define CUP_WIDTH (10)
    #define CUP_HEIGHT (12)

   glBegin(GL_QUADS);
   glColor3f(0.502, 0.502, 0.000);
   glVertex3f( CUP_WIDTH/2.0f, CUP_HEIGHT/2.0f, 0.0f);  // top left
   glVertex3f( -CUP_WIDTH/2.0f, CUP_HEIGHT/2.0f, 0.0f);
   glVertex3f( -CUP_WIDTH/2.0f, -CUP_HEIGHT/2.0f, 0.0f);
   glVertex3f( CUP_WIDTH/2.0f, -CUP_HEIGHT/2.0f, 0.0f);
   glEnd();

   
   glLineWidth(3.0f);
   glBegin(GL_LINES);
   // top horizontal
   glVertex3f( CUP_WIDTH/2.0f, (CUP_HEIGHT/2.0f)*0.7f, 0.0f);  
   glVertex3f( (CUP_WIDTH/2.0f)*1.2f, (CUP_HEIGHT/2.0f)*0.7f, 0.0f); 
   glEnd();

    glBegin(GL_LINES);
   // Vertical
   glVertex3f( (CUP_WIDTH/2.0f)*1.2f, (CUP_HEIGHT/2.0f)*0.7f, 0.0f); 
   glVertex3f( (CUP_WIDTH/2.0f)*1.2f, -(CUP_HEIGHT/2.0f)*0.2f, 0.0f);  
   glEnd();

   glBegin(GL_LINES);
   // bottom horizontal
   glVertex3f( CUP_WIDTH/2.0f, -(CUP_HEIGHT/2.0f)*0.2f, 0.0f);  
   glVertex3f( (CUP_WIDTH/2.0f)*1.2f, -(CUP_HEIGHT/2.0f)*0.2f, 0.0f); 
   glEnd();
//
    glLineWidth(1.0f);

    //draw 2
    //glPointSize(5.0f);
    //glBegin(GL_POINTS);
    //for (float angle = 0.0f; angle < 2.0f * PI; angle = angle + 0.01f)
    //{
    //    //glVertex3f((cos(angle) + 0.05f)/8 + placement, (sin(angle) + 0.05f) / 8, 0.0f);
    //    glVertex3f((cos(angle) + 0.05f) /12 + placement, (sin(angle) + 0.05f) / 12, 0.0f);
    //}
    //glEnd();
    //glPointSize(1.0f);
}


