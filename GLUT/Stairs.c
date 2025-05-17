// Header files
#include "GL/freeglut.h"

extern GLfloat fRange; 
extern unsigned int guiTicks;
extern GLfloat gfAspectRatio; 


void drawStairs(void)
{


	// draw stage
	glBegin(GL_QUADS);
	glColor3f(0.698, 0.133, 0.133);
	glVertex3f(-13.0f, 11.0f, 0.0f); // top left
	glVertex3f(-fRange*gfAspectRatio, 20.0f, 0.0f); // top right
	glVertex3f(-fRange*gfAspectRatio, -19.0f, 0.0f);  // bottom right
	glVertex3f(-13.0f, -19.0f, 0.0f); //bottom left
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.698, 0.133, 0.133);
	glVertex3f(fRange*gfAspectRatio, 20.0f, 0.0f); // top left
	glVertex3f(13.0f, 11.0f, 0.0f); // top right
	glVertex3f(13.0f, -19.0f, 0.0f); //bottom right
	glVertex3f(fRange*gfAspectRatio, -19.0f, 0.0f);  // bottom left

	glEnd();

	// draw shadow
	glBegin(GL_TRIANGLES);

	glColor3f(0.545, 0.000, 0.000);
	glVertex3f(-13.0f, 11.0f, 0.0f); // top right
	glVertex3f(-60.0f, -7.5f, 0.0f); //bottom right
	glVertex3f(-13.0f, -18.0f, 0.0f); // top left

	glEnd();


	// stage ends here

// top stair box

	glBegin(GL_POLYGON);

	if (guiTicks > 200)
	{
		glColor3f(0.541, 0.169, 0.886);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}


	glVertex3f(-13.0f, 11.0f, 0.0f); // top right
	glVertex3f(-18.0f, 5.0f, 0.0f);  // bottom right
	glVertex3f(18.0f, 5.0f, 0.0f);   // bottom left
	glVertex3f(13.0f, 11.0f, 0.0f);  // top left
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-18.0f, 5.0f, 0.0f);
	glVertex3f(-18.0f, 1.0f, 0.0f);
	glVertex3f(18.0f, 1.0f, 0.0f);
	glVertex3f(18.0f, 5.0f, 0.0f);
	glEnd();
//--------------------------------------------

	glBegin(GL_POLYGON);
	if (guiTicks > 125)
	{
		glColor3f(0.541, 0.169, 0.886);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(-18.0f, 1.0f, 0.0f);
	glVertex3f(-23.0f, -4.0f, 0.0f);
	glVertex3f(23.0f, -4.0f, 0.0f);
	glVertex3f(18.0f, 1.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-23.0f, -4.0f, 0.0f);  // top right
	glVertex3f(-23.0f, -9.0f, 0.0f); // bottom right
	glVertex3f(23.0f, -9.0f, 0.0f);
	glVertex3f(23.0f, -4.0f, 0.0f);
	glEnd();

//------------------------------------------------

	glBegin(GL_POLYGON);
	if (guiTicks > 50)
	{
		glColor3f(0.541, 0.169, 0.886);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(-23.0f, -9.0f, 0.0f);
	glVertex3f(-28.0f, -14.0f, 0.0f);
	glVertex3f(28.0f, -14.0f, 0.0f);
	glVertex3f(23.0f, -9.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-28.0f, -14.0f, 0.0f);  // top right
	glVertex3f(-28.0f, -19.0f, 0.0f); // bottom right
	glVertex3f(28.0f, -19.0f, 0.0f);
	glVertex3f(28.0f, -14.0f, 0.0f);
	glEnd();
//--------------------------------------

}
