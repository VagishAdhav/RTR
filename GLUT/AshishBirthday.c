// Header files
#include "GL/freeglut.h"
#include "Drawings.h"
#include "Shape_library.h"

#include <Mmsystem.h>

#pragma comment(lib, "winmm.lib")  

// Global Constant macros
#define TIMER (100)
#define WINDOW_WIDTH (800)
#define WINDOW_HEIGHT (600)


#define SECOND_SCREEN_TICKS (250)
//#define SECOND_SCREEN_TICKS (25)
#define THIRD_SCREEN_TICKS (700)

#define LEFT_MONITOR_IMAGE1_TICKS (SECOND_SCREEN_TICKS)
#define LEFT_MONITOR_IMAGE2_TICKS (SECOND_SCREEN_TICKS + 330)
#define RIGHT_MONITOR_IMAGE1_TICKS (SECOND_SCREEN_TICKS)
#define RIGHT_MONITOR_IMAGE2_TICKS (SECOND_SCREEN_TICKS + 150)
#define RIGHT_MONITOR_IMAGE3_TICKS (SECOND_SCREEN_TICKS + 330)
//#define RIGHT_MONITOR_IMAGE3_TICKS (SECOND_SCREEN_TICKS + 155)

// Global variable declarations 
BOOL bFullScreen = TRUE; 
GLfloat fRange = 100.0f; 
unsigned int guiTicks = 0;
GLfloat gfAspectRatio; 


// Entry-point function 
int main(int argc, char* argv[])
{
	// local function declarations 
	int initialize(void);
	void resize(int, int); 
	void display(void); 
	void keyboard(unsigned char, int, int); 
	void mouse(int, int, int, int); 
	void uninitialize(void); 
	void TimerUpdate(int value);


	// Code 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 
	glutInitWindowPosition(100, 100); 
	glutCreateWindow("Ashish's Gift");
	glutFullScreen();

	
	initialize();
	
	
	glutReshapeFunc(resize); 
	glutDisplayFunc(display); 
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse); 
	glutCloseFunc(uninitialize); 
	glutTimerFunc(TIMER, TimerUpdate, 0);


	glutMainLoop(); 

	return (0); 
}


int initialize(void) 
{
	// code 
	glClearColor(0.0f, 0.8f, 0.9f, 1.0f); 
	PlaySound(TEXT("./Audio/Sunshine.wav"), NULL, SND_ASYNC);
	imageDecoderInitialize();
	return (0); 
}


void resize(int iWidth, int iHeight)
{
	if(iHeight == 0)
		iHeight = 1; 
	glViewport(0, 0, (GLsizei)iWidth, (GLsizei)iHeight); 

    gfAspectRatio = (GLfloat)iWidth / (GLfloat)iHeight; 

    // Reset coordinate system 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    if(iWidth <= iHeight)
        glOrtho(-fRange, fRange, -fRange / gfAspectRatio, fRange / gfAspectRatio, 1.0f, -1.0f); 
    else 
        glOrtho(-fRange * gfAspectRatio, fRange * gfAspectRatio, -fRange, fRange, 1.0f, -1.0f); 

    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
}

void display(void)
{

	// function declaration
	void drawTable(void);
	void DrawBackGround(void);
	void drawRoom(void);

	// code 
	glClear(GL_COLOR_BUFFER_BIT); 

	//printf("guiTicks : %d\t", guiTicks);
	if (guiTicks < SECOND_SCREEN_TICKS)
	{
		DrawBackGround();

		glPushMatrix();
		glTranslatef(-140.0f, -14.0f, 0.0f);
		glScalef(0.3f, 0.66f, 1.0f);
		displayGearsImage();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(110.0f, -14.0f, 0.0f);
		glScalef(0.3f, 0.66f, 1.0f);
		displayCSEImage();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-100.0f, -80.0f, 0.0f);
		glScalef(0.5f, 1.0f, 1.0f);
		displayChangeImage();
		glPopMatrix();


		glPushMatrix();
		glTranslatef(0.0f, 25.0f, 0.0f);
		drawQuestion();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, -30.0f, 0.0f);
		drawStairs();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 40.0f, 0.0f);
		drawArrow();
		glPopMatrix();

		glPushMatrix();
		glScalef(0.6f, 0.6f, 1.0);
		glTranslatef(-30.0f + guiTicks/8, -30.0f + guiTicks/8, 0.0f);
		drawBagWithPerson();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-50.0f, 26.0f, 0.0f);
		drawDoorLeft();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(50.0f, 26.0f, 0.0f);
		drawDoorRight();
		glPopMatrix();

	}
	else if (guiTicks < THIRD_SCREEN_TICKS)
	{

		// // draw Wall
		// drawWall();
		// // draw Floor
		// drawFloor();

		drawRoom();

		glPushMatrix();
		glScalef(0.7f, 0.7f, 1.0f);
		glTranslatef(0.0f, -30.0f, 0.0f);

		// Draw Table
			glPushMatrix();
			glTranslatef(0.0f, -30.0f, 0.0f);
			drawTable();
			glPopMatrix();

			// draw CPU
			glPushMatrix();
			glTranslatef(-75.0f, 50.0f, 0.0f);
			glScalef(0.4f, 0.4f, 1.0f);
			drawCPU();
			glPopMatrix();

			// draw Lamp
			glPushMatrix();
			glTranslatef(85.0f, 39.0f, 0.0f);
			drawLamp();
			glPopMatrix();

			// draw Cabinet
			glPushMatrix();
			glScalef(0.5f, 0.5f, 1.0f);
			glTranslatef(-95.0f, -95.0f, 0.0f);
			drawBottomCabinet();
			glPopMatrix();

			// draw Left Monitor
			glPushMatrix();
			glTranslatef(-30.0f, 55.0f, 0.0f);
			drawMonitor();
			glPopMatrix();

			// show image on left moonitor
			if (guiTicks >= LEFT_MONITOR_IMAGE1_TICKS &&
				guiTicks < LEFT_MONITOR_IMAGE2_TICKS)
			{
				glPushMatrix();
				glTranslatef(-56.0f, 44.0f, 0.0f);
				glScalef(0.4f, 0.35f, 1.0f);
				displayQuestionImage();
				glPopMatrix();
			}
			else
			{
				glPushMatrix();
				glTranslatef(-56.0f, 44.0f, 0.0f);
				glScalef(0.4f, 0.35f, 1.0f);
				displayCodeImage();
				glPopMatrix();
				
				// draw VS logo
				glPushMatrix();
				glTranslatef(-54.0f, 68.0f, 0.0f);
				glScalef(0.3f, 0.3f, 1.0f);
				drawVSLogo();
				glPopMatrix();
			}


			// draw Right Monitor
			glPushMatrix();
			glTranslatef(30.0f, 55.0f, 0.0f);
			drawMonitor();
			glPopMatrix();

			// show image on right moonitor
			if (guiTicks >= RIGHT_MONITOR_IMAGE3_TICKS)
			{
				glPushMatrix();
				glTranslatef(0.0f, 44.0f, 0.0f);
				glScalef(0.375f, 0.35f, 1.0f);
				displayAMCImage();
				glPopMatrix();
				// draw photo frame
				glPushMatrix();
				glTranslatef(80.0f, 90.0f, 0.0f);
				glScalef(0.26, 0.2f, 1.0f);
				drawPhotoFrame();
				glPopMatrix();
			}
			else if (guiTicks >= RIGHT_MONITOR_IMAGE2_TICKS)
			{
				glPushMatrix();
				glTranslatef(0.0f, 44.0f, 0.0f);
				glScalef(0.375f, 0.35f, 1.0f);
				displayHadoopImage();
				glPopMatrix();
			}
			else
			{
				glPushMatrix();
				glTranslatef(0.0f, 44.0f, 0.0f);
				glScalef(0.375f, 0.35f, 1.0f);
				displayFactoryImage();
				glPopMatrix();
			}

			// draw Human with chair
			glPushMatrix();
			glScalef(1.3f, 1.3f, 1.0f);
			glTranslatef(0.0f, 20.0f, 0.0f);
			drawChairWithPerson();
			glPopMatrix();

			// draw Mug
			glPushMatrix();
			//glScalef(1.3f, 1.3f, 1.0f);
			glTranslatef(70.0f, 26.5f, 0.0f);
			drawMug();
			glPopMatrix();

		glPopMatrix();

	}
	else if (guiTicks > THIRD_SCREEN_TICKS)
	{
		DrawBackGround();

		drawLastScene();

		if (guiTicks > THIRD_SCREEN_TICKS + 50)
		{
			glPushMatrix();
			glTranslatef(0.0f, guiTicks-(THIRD_SCREEN_TICKS + 50), 0.0f);
			drawBallon();
			glPopMatrix();
		}
		else
		{
			drawBallon();
		}
	}

	//end
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
	default: 
		break; 
	}
}


void mouse(int button, int state, int x, int y)
{
	// code 
	switch (button)
	{
	case GLUT_LEFT_BUTTON: 
		glutLeaveMainLoop(); 
		break; 
	default: 
		break; 
	}
}


void uninitialize(void)
{
	// code 
}

void TimerUpdate(int value)
{
	guiTicks++;
	TimerFuncCPU(value);
	glutPostRedisplay();

    glutTimerFunc(TIMER, TimerUpdate, 0);
}

void drawTable(void)
{
	#define TABLE_TOP_X 90.0f
	#define TABLE_TOP_Y 50.0f
	#define TABLE_TOP_HEIGHT 10.0f

	#define LEG_X 70.0f
	#define LEG_Y 40.0f
	#define LEG_WIDTH   5.0f
	#define INWARD_LEG_Y_OFFSET 5.0f
	#define INWARD_LEG_X_OFFSET 10.0f



	// top table 
	glBegin(GL_POLYGON);
	glColor3f(0.992f, 0.984f, 0.831f);
	// top right
	glVertex3f(TABLE_TOP_X, TABLE_TOP_Y - TABLE_TOP_HEIGHT, 0.0f);
	// bottom right
	glVertex3f(TABLE_TOP_X, TABLE_TOP_Y, 0.0f);
	glColor3f(0.796f, 0.741f, 0.576f);
	// bottom left
	glVertex3f(-TABLE_TOP_X, TABLE_TOP_Y, 0.0f);
	// top left
	glVertex3f(-TABLE_TOP_X, TABLE_TOP_Y - TABLE_TOP_HEIGHT, 0.0f);
	glEnd();


	// right outword leg // changing 1st right side greey inner side white
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); // grey 
	glVertex3f(LEG_X, LEG_Y, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f); // blackl
	glVertex3f(LEG_X - LEG_WIDTH, LEG_Y, 0.0f);
	glVertex3f(LEG_X - LEG_WIDTH, -LEG_Y, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f); 
	glVertex3f(LEG_X, -LEG_Y, 0.0f);
	glEnd();

	
	// right inward leg
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); // grey
	glVertex3f(LEG_X - INWARD_LEG_X_OFFSET, LEG_Y, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f); //black
	glVertex3f(LEG_X - INWARD_LEG_X_OFFSET - LEG_WIDTH, LEG_Y, 0.0f); 
	glVertex3f(LEG_X - INWARD_LEG_X_OFFSET - LEG_WIDTH, -LEG_Y + INWARD_LEG_Y_OFFSET, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f); 
	glVertex3f(LEG_X - INWARD_LEG_X_OFFSET, -LEG_Y + INWARD_LEG_Y_OFFSET, 0.0f);
	glEnd();

	// left outword leg
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); // grey
	glVertex3f(-LEG_X + LEG_WIDTH, LEG_Y, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f); // black
	glVertex3f(-LEG_X, LEG_Y, 0.0f);
	glVertex3f(-LEG_X, -LEG_Y, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f); 
	glVertex3f(-LEG_X + LEG_WIDTH, -LEG_Y, 0.0f);
	glEnd(); 

	
	// left inward leg
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); // grey 
	glVertex3f(-(LEG_X - INWARD_LEG_X_OFFSET), LEG_Y, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f); // black
	glVertex3f(-(LEG_X - INWARD_LEG_X_OFFSET - LEG_WIDTH), LEG_Y, 0.0f);
	glVertex3f(-(LEG_X - INWARD_LEG_X_OFFSET - LEG_WIDTH),  -LEG_Y + INWARD_LEG_Y_OFFSET, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f); 
	glVertex3f(-(LEG_X - INWARD_LEG_X_OFFSET),  -LEG_Y + INWARD_LEG_Y_OFFSET, 0.0f);
	glEnd();

}
#define FLOOR_DIVISION (7.0f)
void drawWall(void)
{
	#define WALL_SHADE_1 (0.0f/255.0f),(0.0f/255.0f),(0.0f/255.0f)
	#define SKY_SHADE_2 (25.0f/255.0f),(25.0f/255.0f),(112.0f/255.0f)
	#define BLUE_SHADE (25.0f/255.0f),(25.0f/255.0f),(112.0f/255.0f)

    glBegin(GL_QUADS);

	// top left
    glColor3f(BLUE_SHADE);     
    glVertex3f(-fRange*gfAspectRatio, fRange, 0.0f);  
	// bottom left
    glColor3f(WALL_SHADE_1);
    glVertex3f(-fRange*gfAspectRatio,  -fRange, 0.0f); 
	//bottom right
    glColor3f(WALL_SHADE_1);
    glVertex3f(fRange*gfAspectRatio,  -fRange, 0.0f);
	// top right
	glColor3f(BLUE_SHADE);
    glVertex3f(fRange*gfAspectRatio, fRange, 0.0f);

  glEnd();

}

void drawFloor()
{
	#define FLOOR_SHADE_2 (128.0f/255.0f),(128.0f/255.0f),(128.0f/255.0f)
	#define FLOOR_SHADE_1 (64.0f/255.0f),(64.0f/255.0f),(64.0f/255.0f)
	#define GRID_SHADE 0.0f, 0.0f, 0.0f


	glLineWidth(1.0f);
    glBegin(GL_QUADS);

	// top left
    glColor3f(FLOOR_SHADE_2);     
    glVertex3f(-fRange*gfAspectRatio, -fRange/FLOOR_DIVISION, 0.0f);  
	// bottom left
    glColor3f(FLOOR_SHADE_2);
    glVertex3f(-fRange*gfAspectRatio, -fRange, 0.0f); 
	//bottom right
    glColor3f(FLOOR_SHADE_1);
    glVertex3f(fRange*gfAspectRatio, -fRange, 0.0f);
	// top right
	glColor3f(GRID_SHADE);
    glVertex3f(fRange*gfAspectRatio, -fRange/FLOOR_DIVISION, 0.0f);

	glEnd();

	// draw tile grids
	#define NUM_ROWS 4
	#define NUM_COLS 10

	glBegin(GL_LINES);

	glColor3f(GRID_SHADE);

	float fSpace = fRange*gfAspectRatio*2.0f/NUM_COLS;
	float fXShift = fRange*gfAspectRatio*0.30f;
	for (int iCols = 0; iCols < NUM_COLS; iCols++)
	{
		float fXStart = -fRange*gfAspectRatio + (fSpace * (iCols + 1));
		float fYStart = -fRange/FLOOR_DIVISION;

		float fXEnd = -fRange*gfAspectRatio + (fSpace * (iCols + 1));
		float fYEnd = -fRange;

		if (fXStart < 0.0f)
		{
			fXEnd =  fXEnd - fSpace/2.0f - ((NUM_COLS/2 - iCols) * fSpace*0.2);
		}
		else
		{
			fXEnd =  fXEnd + fSpace/2.0f + ((iCols - NUM_COLS/2 ) * fSpace*0.2);
		}
		glVertex2f(fXStart, fYStart);
		glVertex2f(fXEnd, fYEnd);

	}

	for (int iRows = 0; iRows < NUM_COLS; iRows++)
	{
		float fXStart = -fRange*gfAspectRatio;
		float fYStart = -fRange/FLOOR_DIVISION- (fSpace * (iRows + 1));

		float fXEnd = fRange*gfAspectRatio;
		float fYEnd = -fRange/FLOOR_DIVISION- (fSpace * (iRows + 1));

		glVertex2f(fXStart, fYStart);
		glVertex2f(fXEnd, fYEnd);

	}

	glEnd();

}

void drawRoom(){
    glLineWidth(3.0f);
    
    /* Front wall */
    glPointSize(5.0f);
    glBegin(GL_QUADS);
    glColor4ub(189,220,206, 100);
    glVertex3f(-80.0f, 60.0f, 0.0f);

    glColor4ub(189,220,206, 100);
    glVertex3f(80.0f, 60.0f, 0.0f);

    glColor4ub(189,220,206, 100);
    glVertex3f(80.0f, -60.0f, 0.0f);

    glColor4ub(189,220,206, 100);
    glVertex3f(-80.0f, -60.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor4ub(189,220,206, 100);
    glVertex3f(-80.0f, 60.0f, 0.0f);

    glColor4ub(189,220,206, 100);
    glVertex3f(80.0f, 60.0f, 0.0f);

    glColor4ub(107,138,129, 100);
    glVertex3f(80.0f, -60.0f, 0.0f);

    glColor4ub(107,138,129, 100);
    glVertex3f(-80.0f, -60.0f, 0.0f);
    glEnd();

    /* Top */
    glBegin(GL_QUADS);
    glColor4ub(151,159,165, 255);
    glVertex3f(-80.0f, 60.0f, 0.0f);
    glColor4ub(206,217,221, 255);
    glVertex3f(-350.0f, 150.0f, 0.0f);
    glColor4ub(206,217,221, 255);
    glVertex3f(350.0f, 150.0f, 0.0f);
    glColor4ub(151,159,165, 255);
    glVertex3f(80.0f, 60.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor4ub(100,100,100, 255);
    glVertex3f(-80.0f, 60.0f, 0.0f);
    glColor4ub(255,255,255, 255);
    glVertex3f(-350.0f, 150.0f, 0.0f);
    glColor4ub(255,255,255, 255);
    glVertex3f(350.0f, 150.0f, 0.0f);
    glColor4ub(100,100,100, 255);
    glVertex3f(80.0f, 60.0f, 0.0f);
    glEnd();

    /* Left */
    glBegin(GL_QUADS);
    glColor4ub(194, 178, 128, 255);
    glVertex3f(-80.0f, 60.0f, 0.0f);
    glColor4ub(255, 255, 220, 255);
    glVertex3f(-350.0f, 150.0f, 0.0f);
    glColor4ub(255, 255, 220, 255);
    glVertex3f(-350.0f, -150.0f, 0.0f);
    glColor4ub(194, 178, 128, 255);
    glVertex3f(-80.0f, -60.0f, 0.0f);
    glEnd();


    glBegin(GL_QUADS);
    glColor4ub(139, 128, 0, 100);
    glVertex3f(-80.0f, 60.0f, 0.0f);
    glColor4ub(255, 255, 220, 100);
    glVertex3f(-350.0f, 150.0f, 0.0f);
    glColor4ub(255, 255, 220, 100);
    glVertex3f(-350.0f, -150.0f, 0.0f);
    glColor4ub(139, 128, 0, 100);
    glVertex3f(-80.0f, -60.0f, 0.0f);
    glEnd();


    /* Bottom */
    glColor4ub(151,159,165, 100);
    glBegin(GL_QUADS);
    glVertex3f(-80.0f, -60.0f, 0.0f);
    glVertex3f(-350.0f, -150.0f, 0.0f);
    glVertex3f(350.0f, -150.0f, 0.0f);
    glVertex3f(80.0f, -60.0f, 0.0f);
    glEnd();


    /* Right */
    glBegin(GL_QUADS);
    glColor4ub(194, 178, 128, 255);
    glVertex3f(80.0f, -60.0f, 0.0f);
    glColor4ub(255, 255, 220, 255);
    glVertex3f(350.0f, -150.0f, 0.0f);
    glColor4ub(255, 255, 220, 255);
    glVertex3f(350.0f, 150.0f, 0.0f);
    glColor4ub(194, 178, 128, 255);
    glVertex3f(80.0f, 60.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor4ub(139, 128, 0, 100);
    glVertex3f(80.0f, -60.0f, 0.0f);
    glColor4ub(255, 255, 220, 100);
    glVertex3f(350.0f, -150.0f, 0.0f);
    glColor4ub(255, 255, 220, 100);
    glVertex3f(350.0f, 150.0f, 0.0f);
    glColor4ub(139, 128, 0, 100);
    glVertex3f(80.0f, 60.0f, 0.0f);
    glEnd();

	glLineWidth(1.0f);
	glPointSize(1.0f);
}

void DrawBackGround(void)
{
	// background color
	glBegin(GL_QUADS);
		glColor3f(0.7f, 0.9f, 1.0f);
		glVertex3f(-100.0f * gfAspectRatio, 100.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-100.0f * gfAspectRatio, -100.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(100.0f * gfAspectRatio, -100.0f, 0.0f);
		glColor3f(0.7f, 0.4f, 0.6f);
		glVertex3f(100.0f * gfAspectRatio, 100.0f, 0.0f);
	glEnd();
}
