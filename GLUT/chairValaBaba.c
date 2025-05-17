// Header files
#include "GL/freeglut.h"
#include <math.h>
#include "Shape_library.h"

// Global variable declarations 

extern GLfloat fRange; 


void drawChairWithPerson(void)
{
	color SkinColor = {1.0f, 0.894f, 0.769f};  //Bisque color
	//Neck
	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.894f, 0.769f);
		glVertex3f(-4.0f, 27.0f, 0.0f); // Top-left corner
		glColor3f(1.0f, 0.894f, 0.769f);
		glVertex3f(4.0f, 27.0f, 0.0f);  // Top-right corner
		glColor3f(1.0f, 0.894f, 0.769f); 
		glVertex3f(4.0f, 17.0f, 0.0f); // Bottom-right corner
		glColor3f(1.0f, 0.894f, 0.769f); 
		glVertex3f(-4.0f, 17.0f, 0.0f); // Bottom-left corner
	glEnd();

	// ears
	// left
	glPushMatrix();
		glTranslatef(-6.2f, 25.0f, 0.0f);
		glRotatef(100.0f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_POLYGON);
			glColor3f(1.0f, 0.894f, 0.769f);
			glVertex3f(-2.6f, 0.0f, 0.0f); 
			drawSineWave(-2.4f, 2.4f, 1, 0, 0.3, 1.2f);
			glVertex3f(2.6f, 0.0f, 0.0f); 
		glEnd();

	glPopMatrix();

	// Right
	glPushMatrix();
		glTranslatef(6.2f, 25.0f, 0.0f);
		glRotatef(-100.0f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_POLYGON);
			glColor3f(1.0f, 0.894f, 0.769f);
			glVertex3f(-2.6f, 0.0f, 0.0f); 
			drawSineWave(-2.4f, 2.4f, 1, 2, 0.3, 1.2f);
			glVertex3f(2.6f, 0.0f, 0.0f); 
		glEnd();

	glPopMatrix();

	//Head
	point pOrigin;

	color HairColor = {0.1f, 0.1f, 0.1f};
	float faRadius[2] = {7.3f, 8.5f};

	pOrigin.cords.x = 0;
	pOrigin.cords.y = 27.0f;
	pOrigin.colors = HairColor;

	glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, -MY_PI/3, 4*MY_PI/3);
	glEnd();

	// hairs
	glBegin(GL_POLYGON);
	glVertex3f(-4.0f, 27.0f, 0.0f); // Top-right corner
	drawSineWave(-4.0f, 4.0f, 6, 0, 0.3, 18.0f);
	glVertex3f(4.0f, 27.0f, 0.0f); // Top-left corner
	glEnd();

	//collor
	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.549f, 0.0f); // DarkOrange color
		glVertex3f(-5.0f, 17.0f, 0.0f); // Top-left corner
		glColor3f(0.961f, 0.871f, 0.702f); // Wheat color
		glVertex3f(5.0f, 17.0f, 0.0f);  // Top-right corner
		glColor3f(0.961f, 0.871f, 0.702f); // Wheat color
		glVertex3f(5.0f, 13.0f, 0.0f); // Bottom-right corner
		glColor3f(1.0f, 0.549f, 0.0f); // DarkOrange color
		glVertex3f(-5.0f, 13.0f, 0.0f); // Bottom-left corner
	glEnd();
	//chair tekayla
	glColor3f(1.0f, 0.937f, 0.835f); // LightGreen color for the rectangle
	glBegin(GL_QUADS);
		glColor3f(0.855f, 0.647f, 0.376f); // Goldenrod color
		glVertex3f(-17.0f, -1.0f, 0.0f); // Top-left corner
		glColor3f(0.961f, 0.871f, 0.702f); // Wheat color
		glVertex3f(17.0f, -1.0f, 0.0f);  // Top-right corner
		glColor3f(0.961f, 0.871f, 0.702f); // Wheat color
		glVertex3f(17.0f, -18.0f, 0.0f); // Bottom-right corner
		glColor3f(0.855f, 0.647f, 0.376f); // Goldenrod color
		glVertex3f(-17.0f, -18.0f, 0.0f); // Bottom-left corner
	glEnd();
	//shoulder
	glColor3f(0.565f, 0.933f, 0.565f); // LightGreen color for the rectangle
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.549f, 0.0f); // DarkOrange color
		glVertex3f(-18.0f, 8.0f, 0.0f); // Top-left corner
		glColor3f(1.0f, 0.843f, 0.0f); // Gold color
		glVertex3f(0.0f, 14.5f, 0.0f);  //Center
		glColor3f(1.0f, 0.843f, 0.0f); // Gold color
		glVertex3f(18.0f, 8.0f, 0.0f);  // Top-right corner
		glColor3f(1.0f, 0.843f, 0.0f); // Gold color
		glVertex3f(17.0f, -1.0f, 0.0f); // Bottom-right corner
		glColor3f(1.0f, 0.549f, 0.0f); // DarkOrange color
		glVertex3f(-17.0f, -1.0f, 0.0f); // Bottom-left corner
	glEnd();	

	// elbow left
	glBegin(GL_TRIANGLES);
	glColor3f(0.565f, 0.933f, 0.565f); //  LightGreen color for the rectangle
	for (float angle = MY_PI; angle <= (3 * MY_PI); angle += 0.4f)
	{
		glColor3f(1.0f, 0.549f, 0.0f); // DarkOrange color
		glVertex3f(-24.5f, -10.0f, 0.0f);
		glColor3f(1.0f, 0.843f, 0.0f); // Gold color
		glVertex3f(3.5f * sin(angle) - 24.5f, (3.5f * cos(angle)) - 10.0f, 0.0f);
		glVertex3f(3.5f * sin(angle + 0.4f) - 24.5f, (3.5f * cos(angle + 0.4f)) - 10.0f, 0.0f);
	}
	glEnd();
	//hand left
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.549f, 0.0f); // DarkOrange color
		glVertex3f(-18.0f, 8.0f, 0.0f);  // Top
		glColor3f(1.0f, 0.843f, 0.0f); // Gold color
		glVertex3f(-17.0f, -1.0f, 0.0f); // Top-right corner 
		glColor3f(1.0f, 0.843f, 0.0f); // Gold color
		glVertex3f(-17.0f, -6.0f, 0.0f); // Middle
		glColor3f(1.0f, 0.843f, 0.0f); // Gold color
		glVertex3f(-22.0f, -12.0f, 0.0f);// Bottom-right corner 
		glColor3f(1.0f, 0.549f, 0.0f); // DarkOrange color
		glVertex3f(-28.0f, -9.0f, 0.0f); //Bottom-left corner
	glEnd();
	// elbow right
	glBegin(GL_TRIANGLES);
	glColor3f(0.565f, 0.933f, 0.565f); //  LightGreen color for the rectangle
	for (float angle = MY_PI; angle <= (3 * MY_PI); angle += 0.4f)
	{
		glColor3f(1.0f, 0.549f, 0.0f); // DarkOrange color
		glVertex3f(24.5f, -10.0f, 0.0f);
		glColor3f(1.0f, 0.843f, 0.0f); // Gold color
		glVertex3f(3.5f * sin(angle) + 24.5f, (3.5f * cos(angle)) - 10.0f, 0.0f);
		glVertex3f(3.5f * sin(angle + 0.4f) + 24.5f, (3.5f * cos(angle + 0.4f)) - 10.0f, 0.0f);
	}
	glEnd();

	//hand right
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.549f, 0.0f); // DarkOrange color
		glVertex3f(17.0f, -1.0f, 0.0f);  // Top 
		glColor3f(1.0f, 0.843f, 0.0f); // Gold color
		glVertex3f(18.0f, 8.0f, 0.0f);   // Top-left corner
		glColor3f(1.0f, 0.843f, 0.0f); // Gold color
		glVertex3f(28.0f, -9.0f, 0.0f);  // Middle 
		glColor3f(1.0f, 0.843f, 0.0f); // Gold color
		glVertex3f(22.0f, -12.0f, 0.0f); // Bottom-left corner
		glColor3f(1.0f, 0.549f, 0.0f); // DarkOrange color
		glVertex3f(17.0f, -6.0f, 0.0f);  // Bottom-bottom right
	glEnd();

	// knee left
	glBegin(GL_TRIANGLES);
	glColor3f(0.565f, 0.933f, 0.565f); // PapayaWhip color
	for (float angle = MY_PI; angle <= (3 * MY_PI); angle += 0.4f)
	{
		glColor3f(0.878f, 1.0f, 1.0f); // LightCyen color
		glVertex3f(-13.0f, -32.0f, 0.0f);
		glColor3f(0.0f, 0.502f, 0.502f); // Teal color
		glVertex3f(5.0f * sin(angle) - 13, (5.0f * cos(angle)) - 32.0f, 0.0f);
		glVertex3f(5.0f * sin(angle + 0.4f) - 13, (5.0f * cos(angle + 0.4f)) - 32.0f, 0.0f);
	}
	glEnd();
	// knee right
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.749f, 1.0f); // DeepSky Blue color
	for (float angle = MY_PI; angle <= (3 * MY_PI); angle += 0.4f)
	{
		glColor3f(0.878f, 1.0f, 1.0f); // LightCyen color
		glVertex3f(13.0f, -32.0f, 0.0f);
		glColor3f(0.0f, 0.502f, 0.502f); // Teal color
		glVertex3f(5.0f * sin(angle) + 13, (5.0f * cos(angle)) - 32.0f, 0.0f);
		glVertex3f(5.0f * sin(angle + 0.4f) + 13, (5.0f * cos(angle + 0.4f)) - 32.0f, 0.0f);
	}
	glEnd();
	//body - lower
	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.549f, 0.0f); // DarkOrange color
		glVertex3f(-13.0f, -18.0f, 0.0f); // Top-left corner
		glColor3f(1.0f, 0.843f, 0.0f); // Gold color
		glVertex3f(13.0f, -18.0f, 0.0f);  // Top-right corner
		glColor3f(1.0f, 0.843f, 0.0f); // Gold color
		glVertex3f(13.0f, -33.0f, 0.0f); // Bottom-right corner
		glColor3f(1.0f, 0.549f, 0.0f); // DarkOrange color
		glVertex3f(-13.0f, -33.0f, 0.0f); // Bottom-left corner
	glEnd();
	//chair - basayla
	glBegin(GL_QUADS);
		glColor3f(0.855f, 0.647f, 0.376f); // Goldenrod color
		glVertex3f(-22.0f, -33.0f, 0.0f); // Top-left corner
		glColor3f(0.961f, 0.871f, 0.702f); // Wheat color
		glVertex3f(22.0f, -33.0f, 0.0f);  // Top-right corner
		glColor3f(0.961f, 0.871f, 0.702f); // Wheat color
		glVertex3f(22.0f, -37.0f, 0.0f); // Bottom-right corner
		glColor3f(0.855f, 0.647f, 0.376f); // Goldenrod color
		glVertex3f(-22.0f, -37.0f, 0.0f); // Bottom-left corner
	glEnd();	
	//body - left leg
	glBegin(GL_QUADS);
		glColor3f(0.878f, 1.0f, 1.0f); // LightCyen color
		glVertex3f(-17.0f, -37.0f, 0.0f); // Top-left corner
		glColor3f(0.0f, 0.502f, 0.502f); // Teal color
		glVertex3f(-9.0f, -37.0f, 0.0f);  // Top-right corner
		glColor3f(0.0f, 0.502f, 0.502f); // Teal color
		glVertex3f(-9.0f, -68.0f, 0.0f); // Bottom-right corner
		glColor3f(0.878f, 1.0f, 1.0f); // LightCyen color
		glVertex3f(-17.0f, -68.0f, 0.0f); // Bottom-left corner
	glEnd();
	//left shoes - uppper border
	glColor3f(1.0f, 0.937f, 0.835f); // LightGreen color for the rectangle
	glBegin(GL_QUADS);
		glVertex3f(-17.0f, -68.0f, 0.0f); // Top-left corner
		glVertex3f(-9.0f, -68.0f, 0.0f);  // Top-right corner
		glVertex3f(-9.0f, -69.0f, 0.0f); // Bottom-right corner
		glVertex3f(-17.0f, -69.0f, 0.0f); // Bottom-left corner
	glEnd();
	//left shoes
	glColor3f(0.565f, 0.933f, 0.565f); // LightGreen color for the rectangle
	glBegin(GL_QUADS);
		glColor3f(0.627f, 0.322f, 0.176f); // Sienna color
		glVertex3f(-15.5f, -69.0f, 0.0f); // Top-left corner
		glColor3f(0.627f, 0.322f, 0.176f); // Sienna color
		glVertex3f(-10.5f, -69.0f, 0.0f);  // Top-right corner
		glColor3f(0.804f, 0.522f, 0.247f); // Peru color
		glVertex3f(-9.6f, -75.0f, 0.0f); // Bottom-right corner
		glColor3f(0.804f, 0.522f, 0.247f); // Peru color
		glVertex3f(-15.5f, -75.0f, 0.0f); // Bottom-left corner
	glEnd();
	//body - right leg
	glBegin(GL_QUADS);
		glColor3f(0.878f, 1.0f, 1.0f); // LightCyen color
		glVertex3f(9.0f, -37.0f, 0.0f); // Top-left corner
		glColor3f(0.0f, 0.502f, 0.502f); // Teal color
		glVertex3f(17.0f, -37.0f, 0.0f);  // Top-right corner
		glColor3f(0.0f, 0.502f, 0.502f); // Teal color
		glVertex3f(17.0f, -68.0f, 0.0f); // Bottom-right corner
		glColor3f(0.878f, 1.0f, 1.0f); // LightCyen color
		glVertex3f(9.0f, -68.0f, 0.0f); // Bottom-left corner
	glEnd();	
	//right shoes - uppper border
	glColor3f(1.0f, 0.937f, 0.835f); // LightGreen color for the rectangle
	glBegin(GL_QUADS);
		glVertex3f(17.0f, -68.0f, 0.0f); // Top-left corner
		glVertex3f(9.0f, -68.0f, 0.0f);  // Top-right corner
		glVertex3f(9.0f, -69.0f, 0.0f); // Bottom-right corner
		glVertex3f(17.0f, -69.0f, 0.0f); // Bottom-left corner
	glEnd();
	//Right shoes
	glColor3f(0.565f, 0.933f, 0.565f); // LightGreen color for the rectangle
	glBegin(GL_QUADS);
		glColor3f(0.627f, 0.322f, 0.176f); // Sienna color
		glVertex3f(15.5f, -69.0f, 0.0f); // Top-left corner
		glColor3f(0.627f, 0.322f, 0.176f); // Sienna color
		glVertex3f(10.5f, -69.0f, 0.0f);  // Top-right corner
		glColor3f(0.804f, 0.522f, 0.247f); // Peru color
		glVertex3f(9.6f, -75.0f, 0.0f); // Bottom-right corner
		glColor3f(0.804f, 0.522f, 0.247f); // Peru color
		glVertex3f(15.5f, -75.0f, 0.0f); // Bottom-left corner
	glEnd();
	//chair - bottom horizontal
	glBegin(GL_QUADS);
		glColor3f(0.855f, 0.647f, 0.376f); // Goldenrod color
		glVertex3f(-25.0f, -71.0f, 0.0f); // Top-left corner
		glColor3f(0.961f, 0.871f, 0.702f); // Wheat color
		glVertex3f(25.0f, -71.0f, 0.0f);  // Top-right corner
		glColor3f(0.961f, 0.871f, 0.702f); // Wheat color
		glVertex3f(25.0f, -73.5f, 0.0f); // Bottom-right corner
		glColor3f(0.855f, 0.647f, 0.376f); // Goldenrod color
		glVertex3f(-25.0f, -73.5f, 0.0f); // Bottom-left corner
	glEnd();
	//chair 2 middle vertical danda
	glBegin(GL_QUADS);
		glColor3f(0.855f, 0.647f, 0.376f); // Goldenrod color
		glVertex3f(-2.0f, -4.0f, 0.0f); // Top-left corner
		glColor3f(0.961f, 0.871f, 0.702f); // Wheat color
		glVertex3f(2.0f, -4.0f, 0.0f);  // Top-right corner
		glColor3f(0.961f, 0.871f, 0.702f); // Wheat color
		glVertex3f(2.0f, -80.0f, 0.0f); // Bottom-right corner
		glColor3f(0.855f, 0.647f, 0.376f); // Goldenrod color
		glVertex3f(-2.0f, -80.0f, 0.0f); // Bottom-left corner
	glEnd();
	//chair left leg
	glBegin(GL_TRIANGLES);
	glColor3f(0.753f, 0.753f, 0.753f); // PapayaWhip color
	for (float angle = 0.0f; angle <= (2 * MY_PI); angle += 0.4f)
	{
		glVertex3f(-24.0f, -77.0f, 0.0f);
		glColor3f(0.863f, 0.863f, 0.863f); // Gainsboro color
		glVertex3f(4.0f * sin(angle) - 24.0f, (4.0f * cos(angle)) - 77.0f, 0.0f);
		glColor3f(0.502f, 0.502f, 0.502f); // Grey color
		glVertex3f(4.0f * sin(angle + 0.4f) - 24.0f, (4.0f * cos(angle + 0.4f)) - 77.0f, 0.0f);
	}
	glEnd();
	//chair right leg
	glBegin(GL_TRIANGLES);
	glColor3f(0.753f, 0.753f, 0.753f); // PapayaWhip color
	for (float angle = 0.0f; angle <= (2 * MY_PI); angle += 0.4f)
	{
		glVertex3f(25.0f, -77.0f, 0.0f);
		glColor3f(0.863f, 0.863f, 0.863f); // Gainsboro color
		glVertex3f(4.0f * sin(angle) + 24.0f, (4.0f * cos(angle)) - 77.0f, 0.0f);
		glColor3f(0.502f, 0.502f, 0.502f); // Grey color
		glVertex3f(4.0f * sin(angle + 0.4f) + 24.0f, (4.0f * cos(angle + 0.4f)) - 77.0f, 0.0f);
	}
	glEnd();
	//chair middle leg
	glBegin(GL_TRIANGLES);
	glColor3f(0.753f, 0.753f, 0.753f); // PapayaWhip color
	for (float angle = 0.0f; angle <= (2 * MY_PI); angle += 0.4f)
	{
		glVertex3f(0.0f, -80.0f, 0.0f);
		glColor3f(0.863f, 0.863f, 0.863f); // Gainsboro color
		glVertex3f(4.0f * sin(angle), (4.0f * cos(angle)) - 80.0f, 0.0f);
		glColor3f(0.502f, 0.502f, 0.502f); // Grey color
		glVertex3f(4.0f * sin(angle + 0.4f), (4.0f * cos(angle + 0.4f)) - 80.0f, 0.0f);
	}
	glEnd();
}
