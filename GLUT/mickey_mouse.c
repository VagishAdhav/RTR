// header files
#include "GL/freeglut.h"
#include <math.h>
#include "stdlib.h"

int page_number = 1;

// global variable declarations
BOOL bFullScreen = FALSE;

#define M_PI   3.14159265358979323846264338327950288

#define RED_CODE  1.0f, 0.0f, 0.0f
#define GREEN_CODE 0.0f, 1.0f, 0.0f
#define BLUE_CODE 0.0f, 0.0f, 1.0f
#define YELLOW_CODE 1.0f, 1.0f, 0.0f
#define ORANGE_CODE 1.0f, 0.74f, 0.0f
#define PINK_CODE 0.87f, 0.19f, 0.38f
#define BLACK_CODE 0.0f, 0.0f, 0.0f
#define WHITE_CODE 1.0f, 1.0f, 1.0f
#define CYAN_CODE  0.0f, 1.0f, 1.0f
#define BROWN_CODE 0.67f, 0.43f, 0.33f
#define PURPLE_CODE 0.5f, 0.0f, 0.5f

#define SKIN_CODE  1.00f, 0.85f,0.67f
//#define SKY_SHADE_1 0.05f, 0.07f, 0.033f
//#define SKY_SHADE_2  0.0745f,0.094f,0.038f

#define SKY_SHADE_1 PINK_CODE
#define SKY_SHADE_2  PINK_CODE

#define SKY_SHADE_3 PINK_CODE
#define SKY_SHADE_4  PINK_CODE

#define MICKEY_ORIGIN 0.0f, 0.0f
#define MICKEY_RADIUS 0.5f


// entry-point function
int main(int argc, char* argv[])
{
	// local function declarations
	int initialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	void uninitialize(void);

	// code
    //code
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mickey");

/*
   	glutGameModeString("1920x1080:32");
	// enter full screen
	if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE))
		glutEnterGameMode();
	else {
		printf("The select mode is not available\n");
		exit(1);
	}
    */

	initialize();

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

    // OpenGL init
    //glEnable( GL_POINT_SPRITE ); // GL_POINT_SPRITE_ARB if you're
                                 // using the functionality as an extension.

	glutMainLoop();

	return(0);
}


int initialize(void)
{
    // code
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    return(0);
}

void resize(int width, int height)
{
	// code
	glViewport(0, 0, width, height);
}

void bezier(float P1[2], float P2[2], float P3[2], float P4[2], float RGB[3])
{
	
	glBegin(GL_LINES);
	for (float t = 0.0; t < 1; t = t + 0.001)
	{
		// cubic bezier curve

		float Q1[2] = { 0.0f ,0.0f }, Q2[2] = { 0.0f, 0.0f }, Q3[2] = { 0.0f, 0.0f }, Q4[2] = { 0.0f, 0.0f }, Q5[2] = { 0.0f, 0.0f }, C[2] = { 0.0f, 0.0f };
		
		//prev
		//Q1 is the percent point between P1 and P2
		Q1[0] = (1 - t) * P1[0] + t * P2[0];
		Q1[1] = (1 - t) * P1[1] + t * P2[1];

		//Q2 is the percent point between P2 and P3
		Q2[0] = (1 - t) * P2[0] + t * P3[0];
		Q2[1] = (1 - t) * P2[1] + t * P3[1];

		//Q3 is the percent point between P3 and P4
		Q3[0] = (1 - t) * P3[0] + t * P4[0];
		Q3[1] = (1 - t) * P3[1] + t * P4[1];

		//Q4 is the percent point between Q1 and Q2
		Q4[0] = (1 - t) * Q1[0] + t * Q2[0];
		Q4[1] = (1 - t) * Q1[1] + t * Q2[1];

		//Q5 is the percent point between Q3 and Q4
		Q5[0] = (1 - t) * Q2[0] + t * Q3[0];
		Q5[1] = (1 - t) * Q2[1] + t * Q3[1];

		//C is the percent point between Q4 and Q5
		C[0] = (1 - t) * Q4[0] + t * Q5[0];
		C[1] = (1 - t) * Q4[1] + t * Q5[1];
		glColor3f(RGB[0], RGB[1], RGB[2]);
		glVertex2f(C[0], C[1]);

		//later
		t = t + 0.01;

		//Q1
		Q1[0] = (1 - t) * P1[0] + t * P2[0];
		Q1[1] = (1 - t) * P1[1] + t * P2[1];
		//glColor3f(1.0f, 0.0f, 0.0f);
		//glVertex2f(Q1[0], Q1[1]);

		//Q2
		Q2[0] = (1 - t) * P2[0] + t * P3[0];
		Q2[1] = (1 - t) * P2[1] + t * P3[1];

		//
		Q3[0] = (1 - t) * P3[0] + t * P4[0];
		Q3[1] = (1 - t) * P3[1] + t * P4[1];

		//
		Q4[0] = (1 - t) * Q1[0] + t * Q2[0];
		Q4[1] = (1 - t) * Q1[1] + t * Q2[1];

		//
		Q5[0] = (1 - t) * Q2[0] + t * Q3[0];
		Q5[1] = (1 - t) * Q2[1] + t * Q3[1];


		//C
		C[0] = (1 - t) * Q4[0] + t * Q5[0];
		C[1] = (1 - t) * Q4[1] + t * Q5[1];
		glColor3f(RGB[0], RGB[1], RGB[2]);
		glVertex2f(C[0], C[1]);

	}
	glEnd();
}

void draw2dTriangle(float vertex[3][2], float color[3][3])
{
    // triangle top
    glColor3f(color[0][0], color[0][1], color[0][2]);
    glVertex3f(vertex[0][0], vertex[0][1], 0.0f);

    glColor3f(color[1][0], color[1][1], color[1][2]);
    glVertex3f(vertex[1][0], vertex[1][1], 0.0f);

    glColor3f(color[2][0], color[2][1], color[2][2]);
    glVertex3f(vertex[2][0], vertex[2][1], 0.0f);
}

void drawEllipse(float radius[2], float origin[2], float color[3][3], float step)
{
    for (float angle = 0.0; angle <= 360.0; angle += step)
    {
        // triangle top
        glColor3f(color[0][0], color[0][1], color[0][2]);
        glVertex3f(origin[0], origin[1], 0.0f);

        float x = origin[0] + (radius[0] * cos(angle));
        float y = origin[1] + (radius[1] * sin(angle));

        glColor3f(color[1][0], color[1][1], color[1][2]);
        glVertex3f(x, y, 0.0f);
//
        x = origin[0] + (radius[0] * cos(angle+step));
        y = origin[1] + (radius[1] * sin(angle+step));


        glColor3f(color[2][0], color[2][1], color[2][2]);
        glVertex3f(x, y, 0.0f);
    }
}


void drawSemiEllipse(float radius[2], float origin[2], float color[3][3], float step, float start, float end)
{
	int count = 0;
    for (float angle = start; angle <= end; angle += step)
    {
           // triangle top
        glColor3f(color[0][0], color[0][1], color[0][2]);
        glVertex3f(origin[0], origin[1], 0.0f);

        float x = origin[0] + (radius[0] * cos(angle));
        float y = origin[1] + (radius[1] * sin(angle));

        glColor3f(color[1][0], color[1][1], color[1][2]);
        glVertex3f(x, y, 0.0f);
//
        x = origin[0] + (radius[0] * cos(angle + step));
        y = origin[1] + (radius[1] * sin(angle + step));

        glColor3f(color[2][0], color[2][1], color[2][2]);
        glVertex3f(x, y, 0.0f);

    }
}

void drawSky(void)
{

    glBegin(GL_QUADS);

	// top left
    glColor3f(SKY_SHADE_1);     
    glVertex3f(-1.0f, 1.0f, 0.0f);  
	// bottom left
    glColor3f(SKY_SHADE_2);
    glVertex3f(-1.0f, -0.2f, 0.0f); 
	//bottom right
    glColor3f(SKY_SHADE_2);
    glVertex3f(1.0f, -0.2f, 0.0f);
	// top right
	glColor3f(SKY_SHADE_1);
    glVertex3f(1.0f, 1.0f, 0.0f);

/*

	// top left
    glColor3f(SKY_SHADE_2);     
    glVertex3f(-1.0f, 0.5f, 0.0f);  
	// bottom left
    glColor3f(SKY_SHADE_3);
    glVertex3f(-1.0f, -0.2f, 0.0f); 
	//bottom right
    glColor3f(SKY_SHADE_3);
    glVertex3f(1.0f, -0.2f, 0.0f);
	// top right
	glColor3f(SKY_SHADE_2);
    glVertex3f(1.0f, 0.5f, 0.0f);

*/
    glEnd();

}

void drawGround()
{
	//#define GRASS_SHADE_1 0.211f, 0.27f, 0.11f
	//#define GRASS_SHADE_2  0.192f,0.23f,0.1137f

    #define GRASS_SHADE_1 PINK_CODE
    #define GRASS_SHADE_2  PINK_CODE
	
	glBegin(GL_QUADS);

	// top left
    glColor3f(GRASS_SHADE_1);     
    glVertex3f(-1.0f, -0.2f, 0.0f);  
	// bottom left
    glColor3f(BLACK_CODE);
    glVertex3f(-1.0f, -1.0f, 0.0f); 
	//bottom right
    glColor3f(BLACK_CODE);
    glVertex3f(1.0f, -1.0f, 0.0f);
	// top right
	glColor3f(GRASS_SHADE_1);
    glVertex3f(1.0f, -0.2f, 0.0f);

	glEnd();
}

void drawMickey(void)
{
    const float step = 0.01;
    // draw face
    float flaRadius[2] = {MICKEY_RADIUS-0.1, MICKEY_RADIUS};
    float flaOrigin[2] = {MICKEY_ORIGIN};
    // color array
    float flaBaseColor[3][3] = {{BLACK_CODE}, {BLACK_CODE}, {BLACK_CODE}};

    glBegin(GL_TRIANGLES);
    //// draw outer circle 
    drawEllipse(flaRadius, flaOrigin, flaBaseColor,step);
   
    //------------------------------------------------
    // draw left ear
    float flaEarRadius[2] = {flaRadius[0]*0.5, flaRadius[1]*0.5};
    float flaEarOrigin[2] = {flaOrigin[0]-flaRadius[0], \
                             flaOrigin[1]+flaRadius[1]};
    drawEllipse(flaEarRadius, flaEarOrigin, flaBaseColor, step);

    // draw right ear
    flaEarOrigin[0] = flaEarOrigin[0]*-1;
    drawEllipse(flaEarRadius, flaEarOrigin, flaBaseColor, step);

    //------------------------------------
    // draw forehead
    float flaForeHeadRadius[2] = {flaRadius[0]*0.40, flaRadius[1]*0.65};
    float flaForeHeadOrigin[2] = {flaOrigin[0]-(flaRadius[0]*0.35), \
                                 flaOrigin[1]+(flaRadius[1]*0.20)};

    float flaSkinColor[3][3] = {{SKIN_CODE}, {SKIN_CODE}, {SKIN_CODE}};
    drawEllipse(flaForeHeadRadius, flaForeHeadOrigin, flaSkinColor,step);
    flaForeHeadOrigin[0] = flaForeHeadOrigin[0]*-1;
    drawEllipse(flaForeHeadRadius, flaForeHeadOrigin, flaSkinColor, step);

    //---------------------------------------------------
    //draw Chick
    float flaChickRadius[2] = {flaRadius[0]*0.9, flaRadius[1]*0.5};
    float flaChickOrigin[2] = {flaOrigin[0], flaOrigin[1]-(flaRadius[1]*0.5)};

    drawEllipse(flaChickRadius, flaChickOrigin, flaSkinColor, step);

    //---------------------------------------------------
    //draw Chin

    float flaChinRadius[2] = {flaRadius[0]*0.55, flaRadius[1]*0.5};
    float flaChinOrigin[2] = {flaOrigin[0], flaOrigin[1]-(flaRadius[1]*0.65)};

    drawEllipse(flaChinRadius, flaChinOrigin, flaSkinColor, step);
    //---------------------------------------------------
    //draw Eyes
    float flaEyesRadius[2] = {flaRadius[0]*0.20, flaRadius[1]*0.35};
    float flaEyesOrigin[2] = {flaOrigin[0]-(flaRadius[0]*0.25), \
                                 flaOrigin[1]+(flaRadius[1]*0.20)};

    float flaEyesColor[3][3] = {{WHITE_CODE}, {WHITE_CODE}, {WHITE_CODE}};
    drawEllipse(flaEyesRadius, flaEyesOrigin, flaEyesColor, step);
    flaEyesOrigin[0] = flaEyesOrigin[0]*-1;
    drawEllipse(flaEyesRadius, flaEyesOrigin, flaEyesColor, step);

    //---------------------------------------------------
    //draw Pupils
    float flaPupilRadius[2] = {flaRadius[0]*0.10, flaRadius[1]*0.18};
    float flaPupilOrigin[2] = {flaOrigin[0]-(flaRadius[0]*0.20), \
                                 flaOrigin[1]+(flaRadius[1]*0.10)};

    float flaPupilColor[3][3] = {{BLACK_CODE}, {BLACK_CODE}, {BLACK_CODE}};


	// look around
	if (page_number % 2 == 0)
	{
		flaPupilOrigin[0] = flaPupilOrigin[0]-flaPupilRadius[0];
		drawEllipse(flaPupilRadius, flaPupilOrigin, flaPupilColor, step);
		flaPupilOrigin[0] = flaPupilOrigin[0]*-1;
		drawEllipse(flaPupilRadius, flaPupilOrigin, flaPupilColor, step);
	}
	else
	{
		drawEllipse(flaPupilRadius, flaPupilOrigin, flaPupilColor, step);
		flaPupilOrigin[0] = flaPupilOrigin[0]*-1;
		drawEllipse(flaPupilRadius, flaPupilOrigin, flaPupilColor, step);
	}

	// close the eyes
	if (page_number % 3 == 0)
	{
		drawEllipse(flaEyesRadius, flaEyesOrigin, flaSkinColor, step);
    	flaEyesOrigin[0] = flaEyesOrigin[0]*-1;
    	drawEllipse(flaEyesRadius, flaEyesOrigin, flaSkinColor, step);

		flaEyesRadius[0] = flaEyesRadius[1]*0.8;
		flaEyesRadius[1] = flaEyesRadius[1]*0.5;
		drawSemiEllipse(flaEyesRadius, flaEyesOrigin, flaBaseColor, step, 8*M_PI/6, 10*M_PI/6);

		flaEyesOrigin[0] = flaEyesOrigin[0]*-1;
    	drawSemiEllipse(flaEyesRadius, flaEyesOrigin, flaBaseColor, step, 8*M_PI/6, 10*M_PI/6);

		flaEyesOrigin[0] = flaEyesOrigin[0]*-1;

		flaEyesRadius[1] = flaEyesRadius[1]*0.95;
		drawSemiEllipse(flaEyesRadius, flaEyesOrigin, flaSkinColor, step, 8*M_PI/6, 10*M_PI/6);

		flaEyesOrigin[0] = flaEyesOrigin[0]*-1;
    	drawSemiEllipse(flaEyesRadius, flaEyesOrigin, flaSkinColor, step, 8*M_PI/6, 10*M_PI/6);
	}

    //---------------------------------------------------
    //draw outer nose
    float flaONoseRadius[2] = {flaRadius[0]*0.5, flaRadius[1]*0.35};
    float flaONoseOrigin[2] = {flaOrigin[0], flaOrigin[1]-(flaRadius[1]*0.39)};

    drawSemiEllipse(flaONoseRadius, flaONoseOrigin, flaBaseColor, step, M_PI/4, 3*M_PI/4);
	flaONoseRadius[0] = 0.95*flaONoseRadius[0];
	flaONoseRadius[1] = 0.95*flaONoseRadius[1];

	float flaONoseFillColor[3][3] = {{SKIN_CODE}, {SKIN_CODE}, {SKIN_CODE}};
	drawSemiEllipse(flaONoseRadius, flaONoseOrigin, flaONoseFillColor, step, M_PI/4, 3*M_PI/4);

	//---------------------------------------------------
    //draw lower lips
    float flaLLipsRadius[2] = {flaRadius[0]*0.45, flaRadius[1]*0.75};
    float flaLLipsOrigin[2] = {flaOrigin[0], flaOrigin[1]-(flaRadius[1]*0.15)};

    float flaLLipsColor[3][3] = {{SKIN_CODE}, {BLACK_CODE}, {BLACK_CODE}};
    drawSemiEllipse(flaLLipsRadius, flaLLipsOrigin, flaLLipsColor, step, 7*M_PI/6, 11*M_PI/6);

	float flaLLipsFillColor[3][3] = {{SKIN_CODE}, {PINK_CODE}, {RED_CODE}};
	flaLLipsRadius[0] = 0.95*flaLLipsRadius[0];
	flaLLipsRadius[1] = 0.95*flaLLipsRadius[1];
    drawSemiEllipse(flaLLipsRadius, flaLLipsOrigin, flaLLipsFillColor, step, 7*M_PI/6, 11*M_PI/6);	// close the eyes
	if (page_number % 3 == 0)
	{
		drawSemiEllipse(flaLLipsRadius, flaLLipsOrigin, flaSkinColor, step, 7*M_PI/6, 11*M_PI/6);
	}



	//---------------------------------------------------
    //draw upper lips
    float flaULipsRadius[2] = {flaRadius[0]*0.85, flaRadius[1]*0.60};
    float flaULipsOrigin[2] = {flaOrigin[0], flaOrigin[1]-(flaRadius[1]*0.10)};

    float flaULipsColor[3][3] = {{BLACK_CODE}, {BLACK_CODE}, {BLACK_CODE}};
    drawSemiEllipse(flaULipsRadius, flaULipsOrigin, flaULipsColor, step, 7*M_PI/6, 11*M_PI/6);
	flaULipsRadius[0] = 0.95*flaULipsRadius[0];
	flaULipsRadius[1] = 0.95*flaULipsRadius[1];

	float flaULipsFillColor[3][3] = {{SKIN_CODE}, {SKIN_CODE}, {SKIN_CODE}};
	drawSemiEllipse(flaULipsRadius, flaULipsOrigin, flaULipsFillColor, step, 7*M_PI/6, 11*M_PI/6);


    //---------------------------------------------------
    //draw nose

    float flaNoseRadius[2] = {flaRadius[0]*0.30, flaRadius[1]*0.20};
    float flaNoseOrigin[2] = {flaOrigin[0], flaOrigin[1]-(flaRadius[1]*0.35)};

    drawEllipse(flaNoseRadius, flaNoseOrigin, flaBaseColor, step);
	/// light on the nose
	float flaLightColor[3][3] = {WHITE_CODE, BLACK_CODE, BLACK_CODE};
	flaNoseRadius[0] = flaNoseRadius[0]*0.3;
	flaNoseRadius[1] = flaNoseRadius[1]*0.3;
	flaNoseOrigin[0] = flaNoseOrigin[0] - flaNoseRadius[0]*0.5;
	drawEllipse(flaNoseRadius, flaNoseOrigin, flaLightColor, step);
	

    glEnd();

}

void display(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT);

	drawSky();

	drawGround();
	//drawSunrise();

    drawMickey();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	// code
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if (bFullScreen == FALSE)
		{
			glutFullScreen();
			bFullScreen = TRUE;
		}
		else
		{
			glutLeaveFullScreen();
			bFullScreen = FALSE;
		}
		break;

	case 'd':
	case 'D':
		page_number++;
		glutPostRedisplay();
		break;

	default:
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	// code
	switch (button)
	{
	case GLUT_RIGHT_BUTTON:
		//glutLeaveMainLoop();
		break;
	
	case GLUT_LEFT_BUTTON:
		break;
	default:
		break;
	}
}

void uninitialize(void)
{
	// code
}
