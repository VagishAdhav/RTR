#include "OGL.h"
#define _USE_MATH_DEFINES (1)
#include <math.h>

#define DEG_TO_RAD(deg) ((deg) * M_PI / 180.0)

GLfloat cubeTexcoords[] =
{
	// front
	1.0f, 1.0f, // top-right of front
	0.0f, 1.0f, // top-left of front
	0.0f, 0.0f, // bottom-left of front
	1.0f, 0.0f, // bottom-right of front

	// right
	1.0f, 1.0f, // top-right of right
	0.0f, 1.0f, // top-left of right
	0.0f, 0.0f, // bottom-left of right
	1.0f, 0.0f, // bottom-right of right

	// back
	1.0f, 1.0f, // top-right of back
	0.0f, 1.0f, // top-left of back
	0.0f, 0.0f, // bottom-left of back
	1.0f, 0.0f, // bottom-right of back

	// left
	1.0f, 1.0f, // top-right of left
	0.0f, 1.0f, // top-left of left
	0.0f, 0.0f, // bottom-left of left
	1.0f, 0.0f, // bottom-right of left

	// top
	1.0f, 1.0f, // top-right of top
	0.0f, 1.0f, // top-left of top
	0.0f, 0.0f, // bottom-left of top
	1.0f, 0.0f, // bottom-right of top

	// bottom
	1.0f, 1.0f, // top-right of bottom
	0.0f, 1.0f, // top-left of bottom
	0.0f, 0.0f, // bottom-left of bottom
	1.0f, 0.0f, // bottom-right of bottom
};

void drawCube(void)
{
     // draw the front face
    glBegin(GL_QUADS);

        //glColor3f(1.0f, 1.0f, 1.0f);
        
        // top right
        glVertex3f(1.0f, 1.0f, 1.0f);
        
        // top left
        glVertex3f(-1.0f, 1.0f, 1.0f);

        // bottom left
        glVertex3f(-1.0f, -1.0f, 1.0f);

        // bottom right
        glVertex3f(1.0f, -1.0f, 1.0f);

    glEnd();

    // draw the back face
    glBegin(GL_QUADS);

        // top right
        glVertex3f(-1.0f, 1.0f, -1.0f);
        
        // top left
        glVertex3f(1.0f, 1.0f, -1.0f);
        
        // bottom left
        glVertex3f(1.0f, -1.0f, -1.0f);

        // bottom right
        glVertex3f(-1.0f, -1.0f, -1.0f);

    glEnd();

        // draw the right face
    glBegin(GL_QUADS);

       
        // top right
        glVertex3f(1.0f, 1.0f, -1.0f);
        
        // top left
        glVertex3f(1.0f, 1.0f, 1.0f);

        // bottom left
        glVertex3f(1.0f, -1.0f, 1.0f);

        // bottom right
        glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();

    // draw the left face
    glBegin(GL_QUADS);

        // top right
        glVertex3f(-1.0f, 1.0f, 1.0f);
        
        // top left
        glVertex3f(-1.0f, 1.0f, -1.0f);
        

        // bottom left
        glVertex3f(-1.0f, -1.0f, -1.0f);

        // bottom right
;
        glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();


    // draw Top face

    glBegin(GL_QUADS);

        // top right
        glVertex3f(1.0f, 1.0f, -1.0f);
        
        // top left
        glVertex3f(-1.0f, 1.0f, -1.0f);
        

        // bottom left
        glVertex3f(-1.0f, 1.0f, 1.0f);

        // bottom right
        glVertex3f(1.0f, 1.0f, 1.0f);

    glEnd();

  
    // draw Bottom face
    glBegin(GL_QUADS);

        // top right
        glVertex3f(1.0f, -1.0f, -1.0f);
        
        // top left
        glVertex3f(-1.0f, -1.0f, -1.0f);
        

        // bottom left
        glVertex3f(-1.0f, -1.0f, 1.0f);

        // bottom right
        glVertex3f(1.0f, -1.0f, 1.0f);

    glEnd();
}

void drawCubeWithTexture(GLuint *texture, unsigned int repeat)
{
    glBindTexture(GL_TEXTURE_2D, *texture);

    // draw the front face
    glBegin(GL_QUADS);

        //glColor3f(1.0f, 1.0f, 1.0f);
        
        // top right
        glTexCoord2f(cubeTexcoords[0] * repeat, cubeTexcoords[1] * repeat);
        glVertex3f(1.0f, 1.0f, 1.0f);
        
        // top left
        glTexCoord2f(cubeTexcoords[2] * repeat, cubeTexcoords[3] * repeat);
        glVertex3f(-1.0f, 1.0f, 1.0f);

        // bottom left
        glTexCoord2f(cubeTexcoords[4] * repeat, cubeTexcoords[5] * repeat);
        glVertex3f(-1.0f, -1.0f, 1.0f);

        // bottom right
        glTexCoord2f(cubeTexcoords[6] * repeat, cubeTexcoords[7] * repeat);
        glVertex3f(1.0f, -1.0f, 1.0f);

    glEnd();

    // draw the back face
    glBegin(GL_QUADS);

        // top right
        glTexCoord2f(cubeTexcoords[8] * repeat, cubeTexcoords[9] * repeat);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        
        // top left
        glTexCoord2f(cubeTexcoords[10] * repeat, cubeTexcoords[11] * repeat);
        glVertex3f(1.0f, 1.0f, -1.0f);
        
        // bottom left
         glTexCoord2f(cubeTexcoords[12] * repeat, cubeTexcoords[13] * repeat);
        glVertex3f(1.0f, -1.0f, -1.0f);

        // bottom right
        glTexCoord2f(cubeTexcoords[14] * repeat, cubeTexcoords[15] * repeat);
        glVertex3f(-1.0f, -1.0f, -1.0f);

    glEnd();

        // draw the right face
    glBegin(GL_QUADS);

       
        // top right
        glTexCoord2f(cubeTexcoords[16] * repeat, cubeTexcoords[17] * repeat);
        glVertex3f(1.0f, 1.0f, -1.0f);
        
        // top left
        glTexCoord2f(cubeTexcoords[18] * repeat, cubeTexcoords[19] * repeat);
        glVertex3f(1.0f, 1.0f, 1.0f);

        // bottom left
        glTexCoord2f(cubeTexcoords[20] * repeat, cubeTexcoords[21] * repeat);
        glVertex3f(1.0f, -1.0f, 1.0f);

        // bottom right
        glTexCoord2f(cubeTexcoords[22] * repeat, cubeTexcoords[23] * repeat);
        glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();

    // draw the left face
    glBegin(GL_QUADS);

        // top right
        glTexCoord2f(cubeTexcoords[24] * repeat, cubeTexcoords[25] * repeat);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        
        // top left
        glTexCoord2f(cubeTexcoords[26] * repeat, cubeTexcoords[27] * repeat);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        

        // bottom left
        glTexCoord2f(cubeTexcoords[28] * repeat, cubeTexcoords[29] * repeat);
        glVertex3f(-1.0f, -1.0f, -1.0f);

        // bottom right
        glTexCoord2f(cubeTexcoords[30] * repeat, cubeTexcoords[31] * repeat);
        glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();


    // draw Top face

    glBegin(GL_QUADS);

        // top right
        glTexCoord2f(cubeTexcoords[32] * repeat, cubeTexcoords[33] * repeat);
        glVertex3f(1.0f, 1.0f, -1.0f);
        
        // top left
        glTexCoord2f(cubeTexcoords[34] * repeat, cubeTexcoords[35] * repeat);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        

        // bottom left
        glTexCoord2f(cubeTexcoords[36] * repeat, cubeTexcoords[37] * repeat);
        glVertex3f(-1.0f, 1.0f, 1.0f);

        // bottom right
        glTexCoord2f(cubeTexcoords[38] * repeat, cubeTexcoords[39] * repeat);
        glVertex3f(1.0f, 1.0f, 1.0f);

    glEnd();

  
    // draw Bottom face
    glBegin(GL_QUADS);

        // top right
        glTexCoord2f(cubeTexcoords[40] * repeat, cubeTexcoords[41] * repeat);
        glVertex3f(1.0f, -1.0f, -1.0f);
        
        // top left
        glTexCoord2f(cubeTexcoords[42] * repeat, cubeTexcoords[43] * repeat);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        

        // bottom left
        glTexCoord2f(cubeTexcoords[44] * repeat, cubeTexcoords[45] * repeat);
        glVertex3f(-1.0f, -1.0f, 1.0f);

        // bottom right
        glTexCoord2f(cubeTexcoords[46] * repeat, cubeTexcoords[47] * repeat);
        glVertex3f(1.0f, -1.0f, 1.0f);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);

}


void drawQuadWithTexture(GLuint *texture , unsigned int repeat)
{
    glBindTexture(GL_TEXTURE_2D, *texture);

    // draw the front face
    glBegin(GL_QUADS);

        // top right
        glTexCoord2f(cubeTexcoords[0] * repeat, cubeTexcoords[1] * repeat);
        glVertex3f(1.0f, 1.0f, 0.0f);
        
        // top left
        glTexCoord2f(cubeTexcoords[2] * repeat, cubeTexcoords[3] * repeat);
        glVertex3f(-1.0f, 1.0f, 0.0f);

        // bottom left
        glTexCoord2f(cubeTexcoords[4] * repeat, cubeTexcoords[5] * repeat);
        glVertex3f(-1.0f, -1.0f, 0.0f);

        // bottom right
        glTexCoord2f(cubeTexcoords[6] * repeat, cubeTexcoords[7] * repeat);
        glVertex3f(1.0f, -1.0f, 0.0f);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}

void drawQuad(void)
{
    glBegin(GL_QUADS);
        // top right
        glVertex3f(1.0f, 1.0f, 0.0f);
        
        // top left
        glVertex3f(-1.0f, 1.0f, 0.0f);

        // bottom left
        glVertex3f(-1.0f, -1.0f, 0.0f);

        // bottom right
        glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();
}

void drawCircle(float startAngle, float endAngle)
{
    for (float fAngle = startAngle; fAngle <= endAngle; fAngle += 0.01f)
    {
        float angle = DEG_TO_RAD(fAngle);
        glBegin(GL_TRIANGLES);
        // triangle top
        glVertex3f(0.0f, 0.0f, 0.0f);

        float fX = cos(angle);
        float fY = sin(angle);

        glVertex3f(fX, fY, 0.0f);
        fX = cos(angle + 0.01f);
        fY = sin(angle + 0.01f);

        glVertex3f(fX, fY, 0.0f);
        glEnd();
    }
}

void drawCircleLine(float startAngle, float endAngle)
{
    glBegin(GL_LINE_LOOP);
    for (float fAngle = startAngle; fAngle <= endAngle; fAngle += 0.01f)
    {
        float angle = DEG_TO_RAD(fAngle);
        float fX = cos(angle);
        float fY = sin(angle);
        glVertex3f(fX, fY, 0.0f);
    }
    glEnd();
}