// Header files
#include <GL/freeglut.h> 
#include <math.h>
#include <Mmsystem.h>

#pragma comment(lib, "winmm.lib")  

#define MY_PI 3.14159265358979323846264338327950288

#define NO_OF_SCENES 3

#define TIMER 10
#define PEACOCK_ANIMATION_TIMER 1000
#define PEACOCK_FEATHER_COUNT 4
#define LANDSCAPE_SCREEN_TIMER 12500
#define CLOUD_SPEED_TIMER 25
#define TRANSISTION_TIMER_1 3000
#define TRANSISTION_TIMER_2 36000
#define LIGHT_TIMER 24200
#define FINISH_TIME 45000

typedef enum SCENE{
    INTRO_SCENE = 0,
    SCENE_1,
    OUTRO_SCENE
}SCENE;

SCENE currentScene = INTRO_SCENE;

// General : Global variable declarations 
BOOL bFullScreen = FALSE; 
GLfloat fRange = 100.0f; 

typedef struct Point{
    GLint x, y;
} Point;

Point points[3];

/* Yogeshwar Sir Global Variables */
GLfloat flMargin = 5.0f; 

/* Room Light */
BOOLEAN lightsOn = FALSE;

/* All Animation Variables */
GLfloat xTransCloudOne = -150.0f;
GLfloat xTransCloudTwo = 50.0f;

GLint peacockFanCount = 0;
GLint elapsedTimePeacockAnimation = 0;
GLint elapsedTimeSunAnimation = 0;
GLint elapsedTimeTransistionSeconds = 0;
GLint elapsedTimeCloudSeconds = 0;
GLint elapsedTransistionTimer1 = 0;
GLint elapsedTransistionTimer2 = 0;
GLint elapsedTransistionTimer3 = 0;
GLint elapsedLightTimer = 0;
GLfloat zoomFactor = 1.0f;

BOOL startTransisition = FALSE;
BOOL landscapeAnimation = TRUE;
BOOL startSpanningRoom = TRUE;
BOOL animatedSun = TRUE;
BOOL doFirstTimer = TRUE;
BOOL doSecondTimer = TRUE;

/* Transitition Animation Variables */
GLfloat transistionZoomFactor = 10.0f;
GLfloat xTransRoom = 60.0f;
GLfloat yTransRoom = -20.0f;

GLfloat xTransRoomReset = 60.0f;
GLfloat yTransRoomReset = -20.0f;

GLfloat yTransSun = 0.0f;

// Entry-point function 
int main(int argc, char* argv[]){
	// local function declarations 
	int initialize(void);
	void resize(int, int); 
	void display(void); 
	void keyboard(unsigned char, int, int); 
	void mouse(int, int, int, int); 
	void uninitialize(void); 
    void SpecialKeys(int key, int x, int y);
    void update(int value);

	// Code 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("Sirs Gift");; 
    glutFullScreen();

	initialize(); 
	
	glutReshapeFunc(resize); 
	glutDisplayFunc(display); 
	glutKeyboardFunc(keyboard);
    glutSpecialFunc(SpecialKeys);
    glutTimerFunc(TIMER, update, 0);
	glutMouseFunc(mouse); 
	glutCloseFunc(uninitialize); 

	glutMainLoop(); 

	return (0); 
}

int initialize(void){
	// code 
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    PlaySound(TEXT("croppedsong.wav"), NULL, SND_ASYNC);
	return (0); 
}

void resize(int iWidth, int iHeight){
	GLfloat aspectRatio; 

	if(iHeight == 0)
		iHeight = 1; 
	glViewport(0, 0, (GLsizei)iWidth, (GLsizei)iHeight); 

    aspectRatio = (GLfloat)iWidth / (GLfloat)iHeight; 

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    if(iWidth <= iHeight)
        glOrtho(-fRange, fRange, -fRange / aspectRatio, fRange / aspectRatio, 1.0f, -1.0f); 
    else 
        glOrtho(-fRange * aspectRatio, fRange * aspectRatio, -fRange, fRange, 1.0f, -1.0f); 

    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
}

void display(void){
	// code 
	glClear(GL_COLOR_BUFFER_BIT); 
	void drawGroundVagish();
	void drawBackgrounSkyAkash();
    void drawMountainAkash();
    void drawSunNeha();
    void drawTreeVagish(void);
    void drawRiver(void);
    void drawCloudSandesh();
    void drawPeacockLalit();
    void drawClouds();
    void drawIntroScreen();
    void drawOutroScreen();
    void drawRoomFrame();
    void drawLandscape();

    glutSetCursor(GLUT_CURSOR_NONE);

    if(currentScene == INTRO_SCENE){
        glPushMatrix();
        drawIntroScreen();
        glPopMatrix();
    }
    else if(currentScene == SCENE_1){
        if(transistionZoomFactor == 1.0f){
            glPushMatrix();
                glLoadIdentity();
                glScalef(transistionZoomFactor, transistionZoomFactor, 1.0f);
                glTranslatef(xTransRoomReset, yTransRoomReset, 0.0f);
                drawRoomFrame();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(xTransRoomReset - 60, yTransRoomReset + 20.0f, 0.0f);
                glScalef(transistionZoomFactor / 10.0f, transistionZoomFactor / 10.0f, 1.0f);
            drawLandscape();
            glPopMatrix();
        }
        else{
            glPushMatrix();
                glScalef(transistionZoomFactor, transistionZoomFactor, 1.0f);
                glTranslatef(xTransRoom, yTransRoom, 0.0f);
                drawRoomFrame();
            glPopMatrix();
            glPushMatrix();
                glLoadIdentity();
                glScalef(transistionZoomFactor / 10.0f, transistionZoomFactor / 10.0f, 1.0f);
                drawLandscape();
            glPopMatrix();
        }   
    }
    else if(currentScene == OUTRO_SCENE){
        glPushMatrix();
        glTranslatef(60.0f, -50.0f, 0.0f);
        glScalef(1.5f, 1.5f, 0.0f);
        drawOutroScreen();
        glPopMatrix();
    }
	glutSwapBuffers(); 
}

void drawLandscape(){
    /* Sky */
    glPushMatrix();
    drawBackgrounSkyAkash();
    glPopMatrix();
    
    /* Cloud 1 : Left Cloud */
    glPushMatrix();
    glTranslatef(xTransCloudOne, 50.0f, 0.0f);
    glScalef(0.4f, 0.4f, 0.0f);
    drawCloudSandesh();
    glPopMatrix();

    /* Sun */
    glPushMatrix();
    glTranslatef(-20.0f, yTransSun, 0.0f);
    drawSunNeha();
    glPopMatrix();

    /* Ground/Terrain */
    glPushMatrix();
    drawMountainAkash();
    drawGroundVagish();
    glPopMatrix();

    /* Draw River*/
    drawRiver();    

    /* Tree 1, Left Side */
    glPushMatrix();
    glTranslatef(-fRange * 1.3f, -fRange * 0.5f, 0.0f);
    glScalef(0.8f, 0.8f, 0.0f);
    drawTreeVagish();
    glPopMatrix();

    /* Cloud 2 : Right Cloud */
    glPushMatrix();
    glTranslatef(xTransCloudTwo, 50.0f, 0.0f);
    glScalef(0.4f, 0.4f, 0.0f);
    drawCloudSandesh();
    glPopMatrix();

    /* Tree 2, Right Side */
    glPushMatrix();
    glTranslatef(fRange * 1.3f, -fRange * 0.2f, 0.0f);
    glScalef(0.4f, 0.4f, 0.0f);
    drawTreeVagish();
    glPopMatrix();
    
    /* Peacock */
    if(animatedSun == FALSE){
        glPushMatrix();
        glScalef(0.8f, 0.8f, 0.0f);
        glTranslatef(100.0f, -80.0f, 0.0f);
        drawPeacockLalit();
        glPopMatrix();
    }
}

void update(int value) {
    elapsedTransistionTimer1 = elapsedTransistionTimer1 + TIMER;
    elapsedTransistionTimer2 = elapsedTransistionTimer2 + TIMER;
    elapsedTransistionTimer3 = elapsedTransistionTimer3 + TIMER;
    elapsedLightTimer = elapsedLightTimer + TIMER;

    if(elapsedTransistionTimer1 > TRANSISTION_TIMER_1 && doFirstTimer){
        elapsedTransistionTimer1 = 0;
        doFirstTimer = FALSE;
        currentScene = (currentScene + 1) % 3;
    }
    if(elapsedTransistionTimer2 > TRANSISTION_TIMER_2 && doSecondTimer){
        elapsedTransistionTimer2 = 0;
        currentScene = (currentScene + 1) % 3;
    }

    if(elapsedLightTimer >= LIGHT_TIMER){
        elapsedLightTimer = 0;
        lightsOn = TRUE;
    }

    if(elapsedTransistionTimer3 >= FINISH_TIME){
        glutSetCursor(GLUT_CURSOR_INHERIT);
        ExitProcess(0);
    }

    if(currentScene == SCENE_1){
        elapsedTimeTransistionSeconds = elapsedTimeTransistionSeconds + TIMER;
        if(landscapeAnimation){
            elapsedTimeSunAnimation = elapsedTimeSunAnimation + TIMER;
            elapsedTimeCloudSeconds = elapsedTimeCloudSeconds + TIMER;

            if(elapsedTimeCloudSeconds >= CLOUD_SPEED_TIMER){
                elapsedTimeCloudSeconds = 0;
                xTransCloudOne = xTransCloudOne + 0.4f;
                xTransCloudTwo = xTransCloudTwo + 0.4f;

                if(xTransCloudOne >= fRange * 1.8f){
                    xTransCloudOne = -fRange * 2.0f;
                }

                if(xTransCloudTwo >= fRange * 1.8f){
                    xTransCloudTwo = -fRange * 2.0f;
                }
            }
            if(animatedSun == FALSE){
                elapsedTimePeacockAnimation = elapsedTimePeacockAnimation + TIMER;
                if(elapsedTimePeacockAnimation >= PEACOCK_ANIMATION_TIMER){
                    elapsedTimePeacockAnimation = 0;
                    peacockFanCount = peacockFanCount + 1;
                    if(peacockFanCount >= PEACOCK_FEATHER_COUNT){
                        peacockFanCount = PEACOCK_FEATHER_COUNT;
                    }
                }
            }

            if(elapsedTimeSunAnimation >= 100){
                elapsedTimeSunAnimation = 0;
                if(animatedSun){
                    yTransSun = yTransSun + 1.0f;
                    if(yTransSun >= 75.0f){
                        yTransSun = 75.0f;
                        animatedSun = FALSE;
                    }
                }
            }
        }
        
        if(elapsedTimeTransistionSeconds >= (LANDSCAPE_SCREEN_TIMER)){
            elapsedTimeTransistionSeconds = 0;
            startTransisition = TRUE;
        }

        if(startTransisition){
            landscapeAnimation = FALSE;
            transistionZoomFactor = transistionZoomFactor - 0.02f;
            if(transistionZoomFactor <= 1.0f){
                transistionZoomFactor = 1.0f;
                if(startSpanningRoom){
                    xTransRoomReset = xTransRoomReset - 0.5f;
                    yTransRoomReset = yTransRoomReset + 0.3f;
                    if(xTransRoomReset <= 5.0f){
                        startSpanningRoom = FALSE;
                    }
                }
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(TIMER, update, 0);
}

void keyboard(unsigned char key, int x, int y){
	// code 
	switch (key){
        case 27: 
            glutLeaveMainLoop(); 
            break; 

        case 'F': 
        case 'f': 
            if (bFullScreen == FALSE){
                glutFullScreen(); 
                bFullScreen = TRUE; 
            }
            else{
                glutLeaveFullScreen(); 
                bFullScreen = FALSE; 
            }
            break; 
        default: 
            break; 
	}
}

void SpecialKeys(int key, int x, int y){
    if (key == GLUT_KEY_DOWN)
        currentScene = (currentScene + 1) % NO_OF_SCENES;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
	// code 
	switch (button){
	/* case GLUT_LEFT_BUTTON: 
		glutLeaveMainLoop(); 
		break;  */
	default: 
		break; 
	}
}

void uninitialize(void){
	// code 
}

void drawGroundVagish(){
	#define GRASS_SHADE_1 0.211f, 0.27f, 0.11f
	#define GRASS_SHADE_2  0.192f,0.23f,0.1137f

    glBegin(GL_QUADS);

	// top left
    glColor3f(GRASS_SHADE_1);     
    glVertex3f(-fRange * 1.8f, -fRange*0.1f, 0.0f);
	// bottom left
    glColor3ub(106, 114, 90);
    glVertex3f(-fRange * 1.8f, -fRange, 0.0f); 
	//bottom right
    glColor3ub(106, 114, 90);
    glVertex3f(fRange * 1.8f, -fRange, 0.0f);
	// top right
	glColor3f(GRASS_SHADE_1);
    glVertex3f(fRange * 1.8f, -fRange*0.1f, 0.0f);

	glEnd();
}

void drawBackgrounSkyAkash(){
    #define SKY_SHADE_BLUE_1 255, 255, 255
	#define SKY_SHADE_BLUE_2  155, 226, 255

    #define SKY_SHADE_ORANGE_1 255, 255, 255
	#define SKY_SHADE_ORANGE_2  247, 180, 117
    
    glBegin(GL_QUADS);

    static GLfloat red = 247.0f;
    static GLfloat green = 180.0f;
    static GLfloat blue = 117.0f;
    
    GLubyte redColor = (GLubyte)((1 - yTransSun/75.0f) * red + (yTransSun / 75.0f) * 155);
    GLubyte greenColor = (GLubyte)((1 - yTransSun/75.0f) * green + (yTransSun / 75.0f) * 226);
    GLubyte blueColor = (GLubyte)((1 - yTransSun/75.0f) * blue + (yTransSun / 75.0f) * 255);

    glColor3ub(redColor, greenColor, blueColor);     
    glVertex3f(-fRange * 1.8f, fRange, 0.0f);
    
    glColor3ub(SKY_SHADE_ORANGE_1);
    glVertex3f(-fRange * 1.8f, -fRange, 0.0f); 
    
    glColor3ub(SKY_SHADE_ORANGE_1);
    glVertex3f(fRange * 1.8f, -fRange, 0.0f);
    
    glColor3ub(redColor, greenColor, blueColor);     
    glVertex3f(fRange * 1.8f, fRange, 0.0f);

	glEnd();
}

void drawMountainAkash(){
    #define  LARGE_MOUNTAIN_SHADE 192, 132, 49
	#define  SMALL_MOUNTAIN_SHADE 231, 187, 141
	
    /* BG Mountain Left 1 */
    glBegin(GL_TRIANGLES);
    glColor3ub(SMALL_MOUNTAIN_SHADE);
    glVertex3f(-fRange * 1.2f,  -fRange*0.1f, 0.0f);
    glColor3ub(SMALL_MOUNTAIN_SHADE);
    glVertex3f(-fRange * 0.5f, fRange * 0.5f, 0.0f);
    glColor3ub(220, 224, 228);
    glVertex3f(-fRange * 0.1f,  -fRange*0.1f, 0.0f);
	glEnd();

    /* BG Mountain Left 2 */
    glBegin(GL_TRIANGLES);
    glColor3ub(220, 224, 228);
    glVertex3f(fRange * 0.1f,  -fRange*0.1f, 0.0f);
    glColor3ub(SMALL_MOUNTAIN_SHADE);
    glVertex3f(fRange * 0.7f, fRange * 0.4f, 0.0f);
    glColor3ub(SMALL_MOUNTAIN_SHADE);
    glVertex3f(fRange * 1.2f,  -fRange*0.1f, 0.0f);
	glEnd();

    /* Dark Mountain Left 1 */
	glBegin(GL_TRIANGLES);
    glColor3ub(LARGE_MOUNTAIN_SHADE);
    glVertex3f(-fRange * 1.8f,  -fRange*0.1f, 0.0f);
    glColor3ub(216, 163, 65);
    glVertex3f(-fRange * 1.2f, fRange * 0.7f, 0.0f);
    glColor3ub(LARGE_MOUNTAIN_SHADE);
    glVertex3f(-fRange * 0.5f,  -fRange*0.1f, 0.0f);
	glEnd();
    
    /* Dark Mountain Left 2 */
    glBegin(GL_TRIANGLES);
    glColor3ub(LARGE_MOUNTAIN_SHADE);
    glVertex3f(-fRange * 0.4f,  -fRange*0.1f, 0.0f);
    glColor3ub(216, 163, 65);
    glVertex3f(fRange * 0.2f, fRange * 0.5f, 0.0f);
    glColor3ub(LARGE_MOUNTAIN_SHADE);
    glVertex3f(fRange * 0.7f,  -fRange*0.1f, 0.0f);
	glEnd();

    /* Dark Mountain Left 3 */
    glBegin(GL_TRIANGLES);
    glColor3ub(LARGE_MOUNTAIN_SHADE);
    glVertex3f(fRange * 0.7f,  -fRange*0.1f, 0.0f);
    glColor3ub(216, 163, 65);
    glVertex3f(fRange * 1.3f, fRange * 0.7f, 0.0f);
    glColor3ub(LARGE_MOUNTAIN_SHADE);
    glVertex3f(fRange * 1.8f,  -fRange*0.1f, 0.0f);
	glEnd();

}

void drawSunNeha(){
    #define POINT_SIZE 4.0f

    glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.6f, 0.0f);
	for (GLfloat angle = 0.0f; angle <= 2 * MY_PI; angle = angle + 0.3f)
	{
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(20.64f * sin(angle), 20.12f * cos(angle), 0.0f);
		glVertex3f(20.64f * sin(angle + 3.0f),20.12f * cos(angle + 3.0f), 0.0f);
	}
	glEnd();

	glPointSize(POINT_SIZE);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.5f, 0.0f);		//red
	for (GLfloat angle = 0.0f; angle <= 2 * MY_PI; angle = angle + 0.01f)
	{
		glVertex3f((10.16f * sin(angle)), (10.3f * cos(angle)), 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 0.0f);
	for (float angle = 0.0f; angle <= (2 * MY_PI); angle += 0.02f)
	{
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(10.14f * sin(angle), 10.14f * cos(angle), 0.0f);
		glVertex3f(10.14f * sin(angle + 0.02f), 10.14f * cos(angle + 0.02f), 0.0f);
	}
	glEnd();
}

void drawRiver(void)
{
    #define HORIZON_SCALE 0.1f
    // local functions
	void plotBezierCurveVagish(float faP1[2], float faP2[2], float faP3[2], float faP4[2], float faColor[3], int iLineSizeIncreaseStep);
	#define RIVER_SHADE_1 0.12f, 0.65f, 0.85f
	float faRiverStart[2] = {fRange*0.7f, -fRange*HORIZON_SCALE};
	float faRiverMid[2] = {fRange*0.9f, -fRange*0.65f};
	float faRiverMid1[2] = {-fRange*0.5, -fRange*0.75f};
	float faRiverEnd[2] = {-fRange, -fRange};
	float faRiverColor[3] = {RIVER_SHADE_1};
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINES);
	plotBezierCurveVagish(faRiverStart, faRiverMid, faRiverMid1, faRiverEnd,faRiverColor, 3);
	glEnd();
}

void drawTreeVagish(){
    #define M_PI   3.14159265358979323846264338327950288

	// local functions
	void plotBezierCurveVagish(float faP1[2], float faP2[2], float faP3[2], float faP4[2], float faColor[3], int iLineSizeIncreaseStep);
	void drawSemiEllipseVagish(float faRadius[2], float faOrigin[2], float faaColor[3][3], float fStep, float fStart, float fEnd);
    void draw2dTriangle(float vertex[3][2], float color[3][3]);
	// constant declaration
	#define TREE_ORIGIN {0, 0}
	#define TREE_HEIGHT (fRange)
	#define TREE_WIDTH  (fRange)

	#define RED_CODE    {1.0f, 0.0f, 0.0f}
	#define GREEN_CODE  {0.0f, 1.0f, 0.0f}
	#define BLUE_CODE   {0.0f, 0.0f, 1.0f}
	#define YELLOW_CODE {1.0f, 1.0f, 0.0f}
	#define ORANGE_CODE {1.0f, 0.74f, 0.0}
	#define PINK_CODE   {0.87f, 0.19f, 0.38}
	#define BLACK_CODE  {0.0f, 0.0f, 0.0f}
	#define WHITE_CODE  {1.0f, 1.0f, 1.0f}
	#define CYAN_CODE   {0.0f, 1.0f, 1.0f}
	#define DARK_BROWN_CODE  {0.5f, 0.22f, 0.09f}
	#define BROWN_CODE  {0.67f, 0.43f, 0.09f}
	#define CHOCOLATY_CODE {0.32f, 0.098f, 0.0313f}
	#define PURPLE_CODE {0.5f, 0.0f, 0.5f}


	#define X_POS (0)
	#define Y_POS (1)

    float faRadiusShadow[] = {TREE_WIDTH*0.4, TREE_WIDTH*0.2};
    float faOriginShadow[] = {0.0f, -60.0f};
    float faaShadowColor[3][3] = {{0.5f, 0.5f, 0.5f},{0.5f, 0.5f, 0.5f}, {0.5f, 0.5f, 0.5f}};

    /* glBegin(GL_TRIANGLES);
    drawSemiEllipseVagish(faRadiusShadow, faOriginShadow, faaShadowColor, 0.1, 0, 2*M_PI);
    glEnd(); */

	// variable declaration
    float faTreeOrigin[2] = TREE_ORIGIN;
    float faRadius[] = {TREE_WIDTH*0.45, TREE_WIDTH*0.45};
    float faOrigin[] = {faTreeOrigin[X_POS], faTreeOrigin[Y_POS] + TREE_HEIGHT*0.4};
    float faaLeafColor[3][3] = {{0.34, 0.49, 0.37},{0.37, 0.57, 0.41}, {0.37, 0.57, 0.41}};
	// draw leaves
    // draw background cic=rcle
    glBegin(GL_TRIANGLES);
    drawSemiEllipseVagish(faRadius, faOrigin, faaLeafColor, 0.1, 0, 2*M_PI);
    // first bush at right 
    faRadius[X_POS] = faRadius[X_POS]*0.5;
    faRadius[Y_POS] = faRadius[Y_POS]*0.5;
    faOrigin[X_POS] = faOrigin[X_POS] + TREE_WIDTH*0.40;
    drawSemiEllipseVagish(faRadius, faOrigin, faaLeafColor, 0.1, 9*M_PI/6, 15*M_PI/6);

    faOrigin[Y_POS] = faTreeOrigin[Y_POS] + TREE_HEIGHT * 0.2 ;
    drawSemiEllipseVagish(faRadius, faOrigin, faaLeafColor, 0.1, 8*M_PI/6, 13*M_PI/6);

    faRadius[X_POS] = TREE_WIDTH*0.3;
    faRadius[Y_POS] = TREE_WIDTH*0.4;
    faOrigin[X_POS] = faTreeOrigin[X_POS] - TREE_WIDTH*0.35;
    drawSemiEllipseVagish(faRadius, faOrigin, faaLeafColor, 0.1, 0, 2*M_PI);
    faOrigin[X_POS] = faTreeOrigin[X_POS] + TREE_WIDTH*0.35;
    drawSemiEllipseVagish(faRadius, faOrigin, faaLeafColor, 0.1, 0, 2*M_PI);

    faRadius[X_POS] = TREE_WIDTH*0.5;
    faRadius[Y_POS] = TREE_WIDTH*0.4;
    faOrigin[X_POS] = faTreeOrigin[X_POS];
    faOrigin[Y_POS] = faTreeOrigin[Y_POS] + TREE_HEIGHT*0.5;
    drawSemiEllipseVagish(faRadius, faOrigin, faaLeafColor, 0.1, 0, 2*M_PI);
    glEnd();

    float fTrunkWidth = TREE_WIDTH * 0.15f;
    float fTrunkHeight = TREE_HEIGHT * 0.5f;
    float faTrunkCenter[2] = {faTreeOrigin[X_POS], faTreeOrigin[Y_POS] - (fTrunkHeight * 0.5)};
    float faaTrunkColor[4][3] = {CHOCOLATY_CODE, DARK_BROWN_CODE, BROWN_CODE, BROWN_CODE};
    float faTopLeft[] = {faTreeOrigin[X_POS] - (fTrunkWidth)/2, faTreeOrigin[Y_POS]};
    float faBottomLeft[] = {faTreeOrigin[X_POS] - (fTrunkWidth)/2 , (faTreeOrigin[Y_POS] - fTrunkHeight)};
    float faTopRight[] = {faTreeOrigin[X_POS] + (fTrunkWidth)/2, (faTreeOrigin[Y_POS] - fTrunkHeight)};
    float faBottomRight[] = {faTreeOrigin[X_POS] + (fTrunkWidth)/2, faTreeOrigin[Y_POS]};

    // draw left bend
    glColor3f(faaTrunkColor[1][0], faaTrunkColor[1][1], faaTrunkColor[1][2]);
    glPointSize(5);
    glBegin(GL_POLYGON);
    glVertex3f(faTrunkCenter[X_POS], faTrunkCenter[Y_POS], 0);

    // draw curve (4 POINT BAZIER)
    float faP1[2] = {faTopLeft[X_POS] - fTrunkWidth*0.6f, faTopLeft[Y_POS] +  fTrunkHeight * 0.3f};
    float faP2[2] = {faTopLeft[X_POS] - fTrunkWidth*0.2f, faTopLeft[Y_POS] -  fTrunkHeight * 0.3f};
    float faP3[2] = {faBottomLeft[X_POS] - fTrunkWidth*0.3f, faTopLeft[Y_POS] -  fTrunkHeight * 0.5f};
    float faP4[2] = {faBottomLeft[X_POS] - fTrunkWidth, faBottomLeft[Y_POS] -  fTrunkHeight * 0.2f};
    plotBezierCurveVagish(faP1, faP2, faP3, faP4, faaTrunkColor[0], 0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(faaTrunkColor[1][0], faaTrunkColor[1][1], faaTrunkColor[1][2]);
    glVertex3f(faTrunkCenter[X_POS], faTrunkCenter[Y_POS], 0);

    // draw roots
    float faR1[2] = {faP4[X_POS] - fTrunkWidth/2, faP4[Y_POS] - fTrunkHeight * 0.2f};
    float faR2[2] = {faTrunkCenter[X_POS], faBottomLeft[Y_POS]};
    float faR3[2] = {faR1[X_POS] + fTrunkWidth, faR1[Y_POS]}; 
    float faR4[2] = {faR3[X_POS], faR1[Y_POS]- fTrunkHeight * 0.2f}; 
    plotBezierCurveVagish(faR1, faR2, faR3, faR4, faaTrunkColor[0], 0);

    faR3[X_POS] = faR3[X_POS] + fTrunkWidth/2;
    faR2[X_POS] = faR2[X_POS] + fTrunkWidth/2;
    faR1[X_POS] = faTopRight[X_POS] + fTrunkWidth*2;
    plotBezierCurveVagish(faR4, faR3, faR2, faR1, faaTrunkColor[2], 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(faaTrunkColor[1][0], faaTrunkColor[1][1], faaTrunkColor[1][2]);
    glVertex3f(faTrunkCenter[X_POS], faTrunkCenter[Y_POS], 0);

    // draw right bend
    faP1[X_POS] = faTopRight[X_POS] + fTrunkWidth*0.6f;
    faP2[X_POS] = faTopRight[X_POS] + fTrunkWidth*0.2f;
    faP3[X_POS] = faBottomRight[X_POS] + fTrunkWidth*0.3f;
    faP4[X_POS] = faBottomRight[X_POS] + fTrunkWidth;
    plotBezierCurveVagish(faP4, faP3, faP2, faP1, faaTrunkColor[3], 0);

    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(faaTrunkColor[1][0], faaTrunkColor[1][1], faaTrunkColor[1][2]);

    glVertex3f(faTrunkCenter[X_POS], faTrunkCenter[Y_POS], 0);

    // draw upper branches
    glVertex3f(faP1[X_POS], faP1[Y_POS], 0);
    glVertex3f(faP1[X_POS] - fTrunkWidth*0.25f, faP1[Y_POS] + fTrunkHeight * 0.3f, 0);
    glVertex3f(faTrunkCenter[X_POS], faTrunkCenter[Y_POS] + fTrunkHeight * 0.5f, 0);
    glVertex3f(faTopLeft[X_POS], faTopLeft[Y_POS] + fTrunkHeight * 0.4f, 0);
    glVertex3f(faTopLeft[X_POS] - fTrunkWidth*0.6f, faTopLeft[Y_POS] +  fTrunkHeight * 0.3f, 0);
    
    glEnd();
    
	// draw grass 
	float fGrassHeight = fTrunkHeight*0.15;
	float fGrassYPos = faR3[Y_POS];
	float fGRassWidth = fRange*0.015;

	glBegin(GL_TRIANGLES);
	float faaGrassVertex[3][2] = {{faR3[X_POS], fGrassYPos}, {faR3[X_POS] - fGRassWidth , fGrassYPos + fGrassHeight}, {faR3[X_POS] + fGRassWidth , fGrassYPos}};
	float faaGrasscolor[3][3] = {{0.192f,0.23f,0.1137f},{faaLeafColor[0][0], faaLeafColor[0][1], faaLeafColor[0][2]}, {0.192f,0.23f,0.1137}};
	draw2dTriangle(faaGrassVertex, faaGrasscolor);


	faaGrassVertex[0][X_POS] += fGRassWidth;
	faaGrassVertex[1][X_POS] += fGRassWidth*2;
	faaGrassVertex[2][X_POS] += fGRassWidth*2;
	draw2dTriangle(faaGrassVertex, faaGrasscolor);

	faaGrassVertex[0][X_POS] += fGRassWidth*2;
	faaGrassVertex[1][X_POS] += fGRassWidth*2.5;
	faaGrassVertex[1][Y_POS] += fGrassHeight*2;
	faaGrassVertex[2][X_POS] += fGRassWidth*3;
	draw2dTriangle(faaGrassVertex, faaGrasscolor);

	faaGrassVertex[0][X_POS] += fGRassWidth*3;
	faaGrassVertex[1][X_POS] += fGRassWidth*3.5;
	faaGrassVertex[1][Y_POS] -= fGrassHeight;
	faaGrassVertex[2][X_POS] += fGRassWidth*3.5;
	draw2dTriangle(faaGrassVertex, faaGrasscolor);

	faaGrassVertex[0][X_POS] = faP4[X_POS];
	faaGrassVertex[1][X_POS] = faP4[X_POS] - fGRassWidth;
	faaGrassVertex[2][X_POS] = faP4[X_POS] + fGRassWidth;
	draw2dTriangle(faaGrassVertex, faaGrasscolor);

	faaGrassVertex[0][X_POS] += fGRassWidth*2;
	faaGrassVertex[1][X_POS] += fGRassWidth*2.5;
	faaGrassVertex[1][Y_POS] += fGrassHeight*2;
	faaGrassVertex[2][X_POS] += fGRassWidth*3;
	draw2dTriangle(faaGrassVertex, faaGrasscolor);

	faaGrassVertex[0][X_POS] += fGRassWidth*3;
	faaGrassVertex[1][X_POS] += fGRassWidth*3.5;
	faaGrassVertex[1][Y_POS] -= fGrassHeight;
	faaGrassVertex[2][X_POS] += fGRassWidth*3.5;
	draw2dTriangle(faaGrassVertex, faaGrasscolor);
	glEnd();
}

void plotBezierCurveVagish(float faP1[2], float faP2[2], float faP3[2], float faP4[2], float faColor[3], int iLineSizeIncreaseStep){
	
	int iLoopCount = 0;
	float fLineWidth = 1;
    glLineWidth(fLineWidth);
	for (float t = 0.0; t < 1; t = t + 0.001)
	{
		// cubic Bezier curve

		float Q1[2] = { 0.0f ,0.0f }, Q2[2] = { 0.0f, 0.0f }, Q3[2] = { 0.0f, 0.0f }, Q4[2] = { 0.0f, 0.0f }, Q5[2] = { 0.0f, 0.0f }, C[2] = { 0.0f, 0.0f };
		
		//prev
		//Q1 is the percent point between faP1 and faP2
		Q1[0] = (1 - t) * faP1[0] + t * faP2[0];
		Q1[1] = (1 - t) * faP1[1] + t * faP2[1];

		//Q2 is the percent point between faP2 and faP3
		Q2[0] = (1 - t) * faP2[0] + t * faP3[0];
		Q2[1] = (1 - t) * faP2[1] + t * faP3[1];

		//Q3 is the percent point between faP3 and faP4
		Q3[0] = (1 - t) * faP3[0] + t * faP4[0];
		Q3[1] = (1 - t) * faP3[1] + t * faP4[1];

		//Q4 is the percent point between Q1 and Q2
		Q4[0] = (1 - t) * Q1[0] + t * Q2[0];
		Q4[1] = (1 - t) * Q1[1] + t * Q2[1];

		//Q5 is the percent point between Q3 and Q4
		Q5[0] = (1 - t) * Q2[0] + t * Q3[0];
		Q5[1] = (1 - t) * Q2[1] + t * Q3[1];

		//C is the percent point between Q4 and Q5
		C[0] = (1 - t) * Q4[0] + t * Q5[0];
		C[1] = (1 - t) * Q4[1] + t * Q5[1];
		glColor3f(faColor[0], faColor[1], faColor[2]);
		glVertex2f(C[0], C[1]);

		//later
		t = t + 0.01;

		//Q1
		Q1[0] = (1 - t) * faP1[0] + t * faP2[0];
		Q1[1] = (1 - t) * faP1[1] + t * faP2[1];

		//Q2
		Q2[0] = (1 - t) * faP2[0] + t * faP3[0];
		Q2[1] = (1 - t) * faP2[1] + t * faP3[1];

		//
		Q3[0] = (1 - t) * faP3[0] + t * faP4[0];
		Q3[1] = (1 - t) * faP3[1] + t * faP4[1];

		//
		Q4[0] = (1 - t) * Q1[0] + t * Q2[0];
		Q4[1] = (1 - t) * Q1[1] + t * Q2[1];

		//
		Q5[0] = (1 - t) * Q2[0] + t * Q3[0];
		Q5[1] = (1 - t) * Q2[1] + t * Q3[1];


		//C
		C[0] = (1 - t) * Q4[0] + t * Q5[0];
		C[1] = (1 - t) * Q4[1] + t * Q5[1];
		glColor3f(faColor[0], faColor[1], faColor[2]);
		glVertex2f(C[0], C[1]);
		iLoopCount++;
		if (iLoopCount == iLineSizeIncreaseStep)
		{
			glEnd();
			glLineWidth(fLineWidth++);
			glEnable(GL_LINE_SMOOTH);
			glBegin(GL_LINES);

			iLoopCount = 0;
		}
	}
}

void drawSemiEllipseVagish(float faRadius[2], float faOrigin[2], float faaColor[3][3], float fStep, float fStart, float fEnd){
    for (float fAngle = fStart; fAngle <= fEnd; fAngle += fStep){
        // triangle top
        glColor3f(faaColor[0][0], faaColor[0][1], faaColor[0][2]);
        glVertex3f(faOrigin[0], faOrigin[1], 0.0f);

        float x = faOrigin[0] + (faRadius[0] * cos(fAngle));
        float y = faOrigin[1] + (faRadius[1] * sin(fAngle));

        glColor3f(faaColor[1][0], faaColor[1][1], faaColor[1][2]);
        glVertex3f(x, y, 0.0f);

        x = faOrigin[0] + (faRadius[0] * cos(fAngle + fStep));
        y = faOrigin[1] + (faRadius[1] * sin(fAngle + fStep));

        glColor3f(faaColor[2][0], faaColor[2][1], faaColor[2][2]);
        glVertex3f(x, y, 0.0f);
    }
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

void drawCloudSandesh(){
	void drawCircleSandesh(GLfloat origin_x, GLfloat origin_y, GLfloat circle_radius);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
	drawCircleSandesh(70.0, 40.0, 25);
	drawCircleSandesh(40.0, 40.0, 15);
    glEnable(GL_BLEND);
	drawCircleSandesh(20.0, 40.0, 10);
    glDisable(GL_BLEND);
	drawCircleSandesh(100.0, 40.0, 20);
    glEnable(GL_BLEND);
	drawCircleSandesh(115.0, 40.0, 15);
    glDisable(GL_BLEND);
}

void drawCircleSandesh(GLfloat origin_x, GLfloat origin_y, GLfloat circle_radius){
	glBegin(GL_TRIANGLES);
		glColor4ub(146,182,240, 200);		// green color
		for(GLfloat angle = 0.0f ; angle <= 2 * MY_PI; angle = angle + 0.05f)
		{
			glVertex3f(origin_x, origin_y, 0.0f);
			glVertex3f(origin_x + (circle_radius * sin(angle)), origin_y + (circle_radius * cos(angle)), 0.0f);
			glVertex3f(origin_x + (circle_radius * sin(angle + 0.05)), origin_y +(circle_radius * cos(angle + 0.05)), 0.0f);
		}

	glEnd();
}

void drawPeacockLalit(){
    #define GL_PI 3.1415f

    // green
    //glColor3f(0.0f, 1.0f, 0.0f);                    
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    int n = 0;
    float x = cos((11 * GL_PI) / 6);
    float y = sin((11 * GL_PI) / 6);

    //Feather Fill
    glBegin(GL_TRIANGLES);
        for(float angle = GL_PI / 2.0f; n < peacockFanCount; angle -= (GL_PI / 6), ++n) {
            glColor3ub(11, 105, 2);
            glVertex3f(0.0f, 0.0f, 0.0f);
            x = cos(angle) * 50;
            y = sin(angle) * 50;
            glColor3ub(27, 145, 16);
            glVertex3f(x, y, 0.0f);

            x = cos(angle - (GL_PI / 6)) * 50;
            y = sin(angle - (GL_PI / 6)) * 50;
            glColor3ub(27, 145, 16);
            glVertex3f(x, y, 0.0f);

            glColor3ub(11, 105, 2);
            glVertex3f(0.0f, 0.0f, 0.0f);
            x = cos(GL_PI-angle) * 50;
            y = sin(GL_PI-angle) * 50;
            glColor3ub(27, 145, 16);
            glVertex3f(x, y, 0.0f);

            x = cos(GL_PI-(angle - (GL_PI / 6))) * 50;
            y = sin(GL_PI-(angle - (GL_PI / 6))) * 50;
            glColor3ub(27, 145, 16);
            glVertex3f(x, y, 0.0f);
        }
    glEnd();
    
    //Feather Outline
    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f); 
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    n = 0;
    x = cos((11 * GL_PI) / 6);
    y = sin((11 * GL_PI) / 6);
    glBegin(GL_TRIANGLES);
        for(float angle = GL_PI / 2.0f; n < peacockFanCount; angle -= (GL_PI / 6), ++n) {
            glVertex3f(0.0f, 0.0f, 0.0f);
            x = cos(angle) * 50;
            y = sin(angle) * 50;
            glVertex3f(x, y, 0.0f);

            x = cos(angle - (GL_PI / 6)) * 50;
            y = sin(angle - (GL_PI / 6)) * 50;
            glVertex3f(x, y, 0.0f);

            glVertex3f(0.0f, 0.0f, 0.0f);
            x = cos(GL_PI-angle) * 50;
            y = sin(GL_PI-angle) * 50;
            glVertex3f(x, y, 0.0f);

            x = cos(GL_PI-(angle - (GL_PI / 6))) * 50;
            y = sin(GL_PI-(angle - (GL_PI / 6))) * 50;
            glVertex3f(x, y, 0.0f);
        }
    glEnd();

    x = cos(((11 * GL_PI) / 6) + (GL_PI / 18)) * 40;
    y = sin(((11 * GL_PI) / 6) + (GL_PI / 18)) * 40;
    float z1 = (2.0944) + ((11 * GL_PI) / 6) + (GL_PI / 18);
    float z2 = (2.0944) +((11 * GL_PI) / 6) + (GL_PI / 12);
    float z3 = (GL_PI / 2) + ((11 * GL_PI) / 6) + (GL_PI / 18);
    float z4 = (GL_PI / 2) +((11 * GL_PI) / 6) + (GL_PI / 12);
    
    glEnable(GL_POINT_SMOOTH);
    // Dots
    for(n = 0; n < peacockFanCount; ++n) {            
        glBegin(GL_LINE_STRIP);
            glColor3f(0.0f, 1.0f, 0.0f);
            for(float angle = z1; angle <= (z1 + (GL_PI / 18)); angle += 0.01f) {
                x = cos(angle) * 40;
                y = sin(angle) * 40;
                glVertex3f(x, y, 0.0f);
            }
        glEnd();

        glPointSize(7.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glBegin(GL_POINTS);
            glVertex3f((cos(z2) * 38), (sin(z2) * 38), 0.0f);
        glEnd();
        glColor3f(0.0f, 1.0f, 0.0f);
        glPointSize(1.0f);

        z1 += (GL_PI / 6);
        z2 += (GL_PI / 6);

        glBegin(GL_LINE_STRIP);
            glColor3f(0.0f, 1.0f, 0.0f);
            for(float angle = z3; angle <= (z3 + (GL_PI / 18)); angle += 0.01f) {
                x = cos(angle) * 40;
                y = sin(angle) * 40;
                glVertex3f(x, y, 0.0f);
            }
        glEnd();

        glPointSize(7.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glBegin(GL_POINTS);
            glVertex3f((cos(z4) * 38), (sin(z4) * 38), 0.0f);
        glEnd();
        glColor3f(0.0f, 1.0f, 0.0f);
        glPointSize(1.0f);

        z3 -= (GL_PI / 6);
        z4 -= (GL_PI / 6);
    }

    glDisable(GL_POINT_SMOOTH);

    // blue
    glColor3f(0.0f, 0.0f, 1.0f);                    

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    x = (GL_PI) * 9;
    y = 0.0f;   
    // lower body
    glBegin(GL_TRIANGLE_FAN);               
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x * 9, y * 9, 0.0f);

        for(float angle = (GL_PI); angle <= (2 * GL_PI); angle += 0.02f) {
            x = cos(angle) * 9;
            y = sin(angle) * 9;
            glVertex3f(x, y, 0.0f);
        }
    glEnd();

    // Middle triangle
    glBegin(GL_TRIANGLES);                  
        glVertex3f(4.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 24.0f, 0.0f);
        glVertex3f(-4.0f, 0.0f, 0.0f);
    glEnd();

    x = 0;
    y = 18.0f;
    // head
    glBegin(GL_TRIANGLE_FAN);                   
        glVertex3f(0.0f, 21.0f, 0.0f);

        for(float angle = 0.0f; angle <= (2 * GL_PI); angle += 0.02f) {
            x = cos(angle) * 2.5f;
            y = sin(angle) * 2.5f + 21;
            glVertex3f(x, y, 0.0f);
        }
    glEnd();

    // legs
    glLineWidth(3.0f);             
    glBegin(GL_LINE_STRIP);
        glVertex3f(-4.0f, -1.0f, 0.0f);
        glVertex3f(-4.0f, -15.0f, 0.0f);
        glVertex3f(-8.0f, -20.0f, 0.0f);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex3f(4.0f, -1.0f, 0.0f);
        glVertex3f(4.0f, -15.0f, 0.0f);
        glVertex3f(8.0f, -20.0f, 0.0f);
    glEnd();
    glLineWidth(1.0f);

    // beak
    glColor3f(0.0f, 0.0f, 1.0f);            
    glBegin(GL_TRIANGLES);                     
        glVertex3f(1.5f, 19.5f, 0.0f);
        glVertex3f(4.0f, 20.5f, 0.0f);
        glVertex3f(1.5f, 22.5f, 0.0f);
    glEnd();

    // eyes
    glEnable(GL_POINT_SMOOTH);              
    glPointSize(4.5f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);                     
        glVertex3f(1.2f, 21.0f, 0.0f);
        glVertex3f(-1.2f, 21.0f, 0.0f);
    glEnd();
    glPointSize(1.0f);
    glDisable(GL_POINT_SMOOTH);

    //Shadow below legs
    glColor3ub(32, 32, 32);
    //rgb(29, 32, 19)
    glLineWidth(5.0f);             
    glBegin(GL_LINES);
        glVertex3f(-10.0f, -20.0f, 0.0f);
        glVertex3f(-5.0f, -20.0f, 0.0f);    
        glVertex3f(10.0f, -20.0f, 0.0f);
        glVertex3f(5.0f, -20.0f, 0.0f);        
    glEnd();
    glLineWidth(1.0f);
}

void drawIntroScreen(){
    void drawAstroMediComp();
    void drawFragmentGroup();
    void drawPresents();
    void drawArambhAkash();

    //ASTROMEDICOMP
    glPushMatrix();
    glScalef(1.1f, 1.1f, 0.0f);
    drawAstroMediComp();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15.0f, 25.0f, 0.0f);
    drawFragmentGroup();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80.0f, 10.0f, 0.0f);
    drawPresents();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 0, 0);
    glLineWidth(10.0f);
    glTranslatef(50.0f, -50.0f, 0.0f);
    glScalef(2.0f, 2.0f, 0.0f);
    drawArambhAkash();
    glLineWidth(1.0f);
    glEnd();
}

void drawOutroScreen(){
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

    glColor3ub(255, 128, 0);
    /* Thank you */
    drawT(-120.0f, 50.0f, 10.0f);
    drawH(-100.0f, 50.0f, 10.0f);
    drawA(-80.0f, 50.0f, 10.0f);
    drawN(-60.0f, 50.0f, 10.0f);
    drawK(-40.0f, 50.0f, 10.0f);
    
    drawY(0.0f, 50.0f, 10.0f);
    drawO(20.0f, 50.0f, 10.0f);
    drawU(40.0f, 50.0f, 10.0f);
    
    glLineWidth(1.0f);
    glPointSize(1.0f);
}

void drawAstroMediComp(){

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

    void apostrophe_symbol(GLfloat Xbox, GLfloat Ybox);

    glLineWidth(8.0f);
    glPointSize(8.0f);

    glColor3ub(255, 128, 0);
    /* ASTROMEDICOMP */
    drawA(-120.0f, 50.0f, 10.0f);
    drawS(-100.0f, 50.0f, 10.0f);
    drawT(-80.0f, 50.0f, 10.0f);
    drawR(-60.0f, 50.0f, 10.0f);
    drawO(-40.0f, 50.0f, 10.0f);
    drawM(-20.0f, 50.0f, 10.0f);
    drawE(0.0f, 50.0f, 10.0f);
    drawD(20.0f, 50.0f, 10.0f);
    drawI(40.0f, 50.0f, 10.0f);
    drawC(60.0f, 50.0f, 10.0f);
    drawO(80.0f, 50.0f, 10.0f);
    drawM(100.0f, 50.0f, 10.0f);
    drawP(120.0f, 50.0f, 10.0f);

    apostrophe_symbol(130.f, 60.f);
    
    drawS(135.0f, 50.0f, 10.0f);

    glLineWidth(1.0f);
    glPointSize(1.0f);
}

void apostrophe_symbol(GLfloat x, GLfloat y){
	// function declarations
	glBegin(GL_QUADS);
		glVertex3f(x + 0.0, y + 0.0, 0.0f);
		glVertex3f(x +1.0, y +4.0, 0.0f);
		glVertex3f(x +3.0, y +4.0, 0.0f);
		glVertex3f(x +1.0, y +0.0, 0.0f);
	glEnd();
}

void drawFragmentGroup(){
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

    glColor3ub(255, 255, 255);
    drawF(-140.0f, 0.0f, 10.0f);
    drawR(-120.0f, 0.0f, 10.0f);
    drawA(-100.0f, 0.0f, 10.0f);
    drawG(-80.0f, 0.0f, 10.0f);
    drawM(-60.0f, 0.0f, 10.0f);
    drawE(-40.0f, 0.0f, 10.0f);
    drawN(-20.0f, 0.0f, 10.0f);
    drawT(0.0f, 0.0f, 10.0f);


    drawG(40.0f, 0.0f, 10.0f);
    drawR(60.0f, 0.0f, 10.0f);
    drawO(80.0f, 0.0f, 10.0f);
    drawU(100.0f, 0.0f, 10.0f);
    drawP(120.0f, 0.0f, 10.0f);

    glLineWidth(1.0f);
    glPointSize(1.0f);
}

void drawPresents(){
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

    glColor3ub(0, 255, 0);
    drawP(-140.0f, -20.0f, 10.0f);
    drawR(-120.0f, -20.0f, 10.0f);
    drawE(-100.0f, -20.0f, 10.0f);
    drawS(-80.0f, -20.0f, 10.0f);
    drawE(-60.0f, -20.0f, 10.0f);
    drawN(-40.0f, -20.0f, 10.0f);
    drawT(-20.0f, -20.0f, 10.0f);
    drawS(0.0f, -20.0f, 10.0f);

    glLineWidth(1.0f);
    glPointSize(1.0f);
}

void drawArambhAkash(){
    glBegin(GL_LINES); 
    /* Top Line */
    glVertex3f(-50.0f, 0.0f, 0.0f);
	glVertex3f(20.0f, 0.0f, 0.0f);
	glEnd(); 

    glBegin(GL_LINES);
    glVertex3f(-50.0f, -2.0f, 0.0f);
    glVertex3f(-40.0f, -2.0f, 0.0f);

    glVertex3f(-40.0f, -2.0f, 0.0f);
    glVertex3f(-40.0f, -10.0f, 0.0f);

    glVertex3f(-40.0f, -10.0f, 0.0f);
    glVertex3f(-50.0f, -10.0f, 0.0f);

    glVertex3f(-40.0f, -10.0f, 0.0f);
    glVertex3f(-30.0f, -10.0f, 0.0f);

    glVertex3f(-40.0f, -10.0f, 0.0f);
    glVertex3f(-40.0f, -20.0f, 0.0f);

    glVertex3f(-40.0f, -20.0f, 0.0f);
    glVertex3f(-50.0f, -20.0f, 0.0f);

    glVertex3f(-30.0f, 0.0f, 0.0f);
    glVertex3f(-30.0f, -22.0f, 0.0f);

    glVertex3f(-25.0f, 0.0f, 0.0f);
    glVertex3f(-25.0f, -22.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-15.0f, 0.0f, 0.0f);
    glVertex3f(-8.0f, -6.0f, 0.0f);

    glVertex3f(-8.0f, -6.0f, 0.0f);
    glVertex3f(-15.0f, -15.0f, 0.0f);

    glVertex3f(-15.0f, -15.0f, 0.0f);
    glVertex3f(-8.0f, -22.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(5.0f, -2.0f, 0.0f);
    glVertex3f(10.0f, -2.0f, 0.0f);

    glVertex3f(10.0f, -2.0f, 0.0f);
    glVertex3f(10.0f, -7.0f, 0.0f);

    glVertex3f(10.0f, -7.0f, 0.0f);
    glVertex3f(5.0f, -7.0f, 0.0f);

    glVertex3f(5.0f, -7.0f, 0.0f);
    glVertex3f(5.0f, -2.0f, 0.0f);

    glVertex3f(10.0f, -7.0f, 0.0f);
    glVertex3f(10.0f, -22.0f, 0.0f);

    glVertex3f(10.0f, -22.0f, 0.0f);
    glVertex3f(5.0f, -22.0f, 0.0f);

    glVertex3f(5.0f, -22.0f, 0.0f);
    glVertex3f(5.0f, -12.0f, 0.0f);

    glVertex3f(5.0f, -12.0f, 0.0f);
    glVertex3f(15.0f, -12.0f, 0.0f);

    glVertex3f(15.0f, 0.0f, 0.0f);
    glVertex3f(15.0f, -22.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-15.0f, 10.0f, 0.0f);
    glVertex3f(-10.0f, 10.0f, 0.0f);

    glVertex3f(-10.0f, 10.0f, 0.0f);
    glVertex3f(-10.0f, 5.0f, 0.0f);

    glVertex3f(-10.0f, 5.0f, 0.0f);
    glVertex3f(-15.0f, 5.0f, 0.0f);

    glVertex3f(-15.0f, 5.0f, 0.0f);
    glVertex3f(-15.0f, 10.0f, 0.0f);
    glEnd();
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

/* Room Scene Functions */
void drawRoomFrame(){
    void drawCircle(float x, float y, float radius);
    void drawFrontFacingStudent(GLint bodyColor[3]);
    void drawLeftFacingStudent(GLint bodyColor[3]);
    void drawRightFacingStudent(GLint bodyColor[3]);
    void drawRoom();
    void drawTeacher();
    void drawTeacherAbhilash(void);
    void drawBoard();
    void drawShree();
    void drawShreeAshish();
    void drawChair(void);

    static GLint bodyColor[3];

    glPushMatrix();
    //glScalef(zoomFactor, zoomFactor, 0.0f);

    /* Room and Board */
    glPushMatrix();
    drawRoom();
    drawBoard();
    glPopMatrix();

    glPushMatrix();
    if(lightsOn){
        glTranslatef(0.0f, 15.0f, 0.0f);
        glScalef(10.0f, 10.0f, 0.0f);
        drawShreeAshish();
    }
    glPopMatrix();


    /* Teacher */
    glPushMatrix();
    glTranslatef(40.0f, -20.0f, 0.0f);
    glScalef(0.7, 0.7, 0.0f);
    //drawTeacher();
    drawTeacherAbhilash();
    glPopMatrix();

    /* Chair Placement */
    glPushMatrix();
    glTranslatef(-75.0f, -45.0f, 0.0f);
    glScalef(30.0f, 30.0f, 0.0f);
    drawChair();
    glPopMatrix();

    /* Front Students */
    glPushMatrix();
    glScalef(0.4, 0.4, 0.0f);

    glTranslatef(-100.0f, -170.0f, 0.0f);
    bodyColor[0] = 237;
    bodyColor[1] = 101;
    bodyColor[2] = 97;
    
    drawRightFacingStudent(bodyColor);

    glTranslatef(200.0f, 0.0f, 0.0f);
    bodyColor[0] = 41;
    bodyColor[1] = 128;
    bodyColor[2] = 155;
    drawLeftFacingStudent(bodyColor);
    glPopMatrix();

    /* Back Students */
    glPushMatrix();
    glScalef(0.5, 0.5, 0.0f);

    glTranslatef(-150.0f, -150.0f, 0.0f);
    bodyColor[0] = 41;
    bodyColor[1] = 128;
    bodyColor[2] = 155;
    drawRightFacingStudent(bodyColor);
    glTranslatef(150.0f, -0.0f, 0.0f);

    bodyColor[0] = 117;
    bodyColor[1] = 164;
    bodyColor[2] = 84;
    drawFrontFacingStudent(bodyColor);


    glTranslatef(150.0f, 0.0f, 0.0f);
    bodyColor[0] = 237;
    bodyColor[1] = 101;
    bodyColor[2] = 97;
    drawLeftFacingStudent(bodyColor);
    glPopMatrix();

    /* Lights */
    if(lightsOn){
        glPushMatrix();
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glBegin(GL_TRIANGLES);
        glColor4ub(255,255,197, 255);
        glVertex3f(0, 60.0f, 0.0f);
        glColor4ub(128,128,128, 100);
        glVertex3f(-30, 10.0f, 0.0f);
        glColor4ub(128,128,128, 100);
        glVertex3f(30, 10.0f, 0.0f);
        glEnd();
        glDisable(GL_BLEND);
        glPopMatrix();
    }
    
    glPopMatrix();
}

void drawCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 100; i++) {
        float angle = i * 2.0f * 3.14159f / 100;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void drawFrontFacingStudent(GLint bodyColor[3]){
    /* Right Hand */
    glColor3f(253.0f/255.0f, 246.0f/255.0f, 214.0f/255.0f);
    glBegin(GL_QUADS);
        glVertex2f(8.0f, -8.0f);
        glVertex2f(8.0f, -18.0f);
        glVertex2f(18.0f, -28.0f);
        glVertex2f(18.0f, -18.0f);
    glEnd();

    glBegin(GL_POLYGON);
    points[0].x = 18.0f;
    points[0].y = -28.0f;
    points[1].x = 18.0f;
    points[1].y = -18.0f;

    /* Control Point */
    points[2].x = 22.0f;
    points[2].y = -25.0f;
    for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
        if(t <= 1.0f){
            GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
            GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
            glVertex2f(x, y);
        }
    }
    glEnd();

    /* Left Hand */
    glColor3f(253.0f/255.0f, 246.0f/255.0f, 214.0f/255.0f);
    glBegin(GL_QUADS);
        glVertex2f(-8.0f, -8.0f);
        glVertex2f(-8.0f, -18.0f);
        glVertex2f(-18.0f, -28.0f);
        glVertex2f(-18.0f, -18.0f);
    glEnd();

    glBegin(GL_POLYGON);
    points[0].x = -18.0f;
    points[0].y = -28.0f;
    points[1].x = -18.0f;
    points[1].y = -18.0f;

    /* Control Point */
    points[2].x = -22.0f;
    points[2].y = -25.0f;
    for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
        if(t <= 1.0f){
            GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
            GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
            glVertex2f(x, y);
        }
    }
    glEnd();


    /* Legs */
    glColor3f(0.0f,0.0f,0.0f);
    glRectf(-15.0f, -25.0f, 15.0f, -39.0f);

    glColor3f(0.0f,0.0f,0.0f);
    drawCircle(15.0f, -32.0f, 7.0f);

    glColor3f(0.0f,0.0f,0.0f);
    drawCircle(-15.0f, -32.0f, 7.0f);

    /* Back Green */
    glColor4ub(bodyColor[0], bodyColor[1], bodyColor[2], 255);
    glBegin(GL_POLYGON);
        glVertex3f(-8.0f, -8.0f, 0.0f);
        glVertex3f(8.0f, -8.0f, 0.0f);
        
        points[0].x = -8.0f;
        points[0].y = -8.0f;
        points[1].x = 8.0f;
        points[1].y = -8.0f;

        /* Control Point */
        points[2].x = -4.0f;
        points[2].y = -4.0f;
        for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
            if(t <= 1.0f){
                GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
                GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
                glVertex2f(x, y);
            }
        }

        glVertex3f(8.0f, -35.0f, 0.0f);
        glVertex3f(-8.0f, -35.0f, 0.0f);
        
        points[0].x = 8.0f;
        points[0].y = -35.0f;
        points[1].x = -8.0f;
        points[1].y = -35.0f;

        /* Control Point */
        points[2].x = -0.0f;
        points[2].y = -42.0f;
        for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
            if(t <= 1.0f){
                GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
                GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
                glVertex2f(x, y);
            }
        }
        
    glEnd();

    /* Head */
    glColor3f(253.0f/255.0f, 246.0f/255.0f, 214.0f/255.0f);
    drawCircle(0.0f, 0.0f, 10.0f);

    /* Shadow */
    glColor3f(0.3f,0.3f,0.3f);
    glRectf(-28.0f, -39.0f, 28.0f, -40.0f);

}

void drawLeftFacingStudent(GLint bodyColor[3]){
    /* Left Hand */
    glColor3f(253.0f/255.0f, 246.0f/255.0f, 214.0f/255.0f);
    glBegin(GL_QUADS);
        glVertex2f(-8.0f, -8.0f);
        glVertex2f(-8.0f, -18.0f);
        glVertex2f(-18.0f, -28.0f);
        glVertex2f(-18.0f, -18.0f);
    glEnd();

    glBegin(GL_POLYGON);
    points[0].x = -18.0f;
    points[0].y = -28.0f;
    points[1].x = -18.0f;
    points[1].y = -18.0f;

    /* Control Point */
    points[2].x = -22.0f;
    points[2].y = -25.0f;
    for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
        if(t <= 1.0f){
            GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
            GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
            glVertex2f(x, y);
        }
    }
    glEnd();


    /* Legs */
    glColor3f(0.0f,0.0f,0.0f);
    glRectf(-15.0f, -25.0f, 9.0f, -39.0f);

    glColor3f(0.0f,0.0f,0.0f);
    drawCircle(9.0f, -32.0f, 7.0f);

    glColor3f(0.0f,0.0f,0.0f);
    drawCircle(-15.0f, -32.0f, 7.0f);


    /* Back Red */
    glPointSize(2.0f);
    glColor3ub(bodyColor[0], bodyColor[1], bodyColor[2]);

    glBegin(GL_POLYGON);
    glVertex3f(-8.0f, -8.0f, 0.0f);
    glVertex3f(6.0f, -8.0f, 0.0f);
    glVertex3f(8.0f, -12.0f, 0.0f);
    
    points[0].x = 6.0f;
    points[0].y = -8.0f;
    points[1].x = 8.0f;
    points[1].y = -12.0f;

    /* Control Point */
    points[2].x = 8.0f;
    points[2].y = -8.0f;
    for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
        if(t <= 1.0f){
            GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
            GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
            glVertex2f(x, y);
        }
    }

    glVertex3f(8.0f, -28.0f, 0.0f);
    glVertex3f(2.0f, -38.0f, 0.0f);
    points[0].x = 8.0f;
    points[0].y = -28.0f;
    points[1].x = 2.0f;
    points[1].y = -38.0f;

    /* Control Point */
    points[2].x = 9.0f;
    points[2].y = -36.0f;
    for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
        if(t <= 1.0f){
            GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
            GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
            glVertex2f(x, y);
        }
    }

    glVertex3f(-8.0f, -38.0f, 0.0f);

    glEnd();

    /* Head */
    glColor3f(253.0f/255.0f, 246.0f/255.0f, 214.0f/255.0f);
    drawCircle(0.0f, 0.0f, 10.0f);

    /* Shadow */
    glColor3f(0.3f,0.3f,0.3f);
    glRectf(-20.0f, -39.0f, 25.0f, -40.0f);

}

void drawRightFacingStudent(GLint bodyColor[3]){
    /* Right Hand */
    glColor3f(253.0f/255.0f, 246.0f/255.0f, 214.0f/255.0f);
    glBegin(GL_QUADS);
        glVertex2f(8.0f, -8.0f);
        glVertex2f(8.0f, -18.0f);
        glVertex2f(18.0f, -28.0f);
        glVertex2f(18.0f, -18.0f);
    glEnd();

    glBegin(GL_POLYGON);
    points[0].x = 18.0f;
    points[0].y = -28.0f;
    points[1].x = 18.0f;
    points[1].y = -18.0f;

    /* Control Point */
    points[2].x = 22.0f;
    points[2].y = -25.0f;
    for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
        if(t <= 1.0f){
            GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
            GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
            glVertex2f(x, y);
        }
    }
    glEnd();

    /* Legs */
    glColor3f(0.0f,0.0f,0.0f);
    glRectf(-9.0f, -25.0f, 15.0f, -39.0f);

    glColor3f(0.0f,0.0f,0.0f);
    drawCircle(15.0f, -32.0f, 7.0f);

    glColor3f(0.0f,0.0f,0.0f);
    drawCircle(-9.0f, -32.0f, 7.0f);

    /* Back Blue */
    glPointSize(2.0f);
    glColor3ub(bodyColor[0], bodyColor[1], bodyColor[2]);
    glPointSize(2.0f);
    glBegin(GL_POLYGON);
    
    glVertex3f(8.0f, -8.0f, 0.0f);

    glVertex3f(-6.0f, -8.0f, 0.0f);
    glVertex3f(-8.0f, -12.0f, 0.0f);
    points[0].x = -6.0f;
    points[0].y = -8.0f;
    points[1].x = -8.0f;
    points[1].y = -12.0f;

    /* Control Point */
    points[2].x = -7.0f;
    points[2].y = -9.0f;
    for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
        if(t <= 1.0f){
            GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
            GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
            glVertex2f(x, y);
        }
    }

    glVertex3f(-8.0f, -32.0f, 0.0f);
    glVertex3f(-4.0f, -38.0f, 0.0f);
    points[0].x = -8.0f;
    points[0].y = -32.0f;
    points[1].x = -4.0f;
    points[1].y = -38.0f;

    /* Control Point */
    points[2].x = -8.0f;
    points[2].y = -36.0f;
    for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
        if(t <= 1.0f){
            GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
            GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
            glVertex2f(x, y);
        }
    }

    glVertex3f(8.0f, -38.0f, 0.0f);

    glEnd();

    /* Head */
    glColor3f(253.0f/255.0f, 246.0f/255.0f, 214.0f/255.0f);
    drawCircle(0.0f, 0.0f, 10.0f);

    /* Shadow */
    glColor3f(0.3f,0.3f,0.3f);
    glRectf(-20.0f, -39.0f, 25.0f, -40.0f);

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

}

void drawTeacher(){
    /* Legs */
    glBegin(GL_QUADS);
        glColor3ub(0.0f, 0.0f, 0.0f);

        glVertex3f(8.0f, -35.0f, 0.0f);
        glVertex3f(8.0f, -65.0f, 0.0f);
        glVertex3f(0.3f, -65.0f, 0.0f);
        glVertex3f(0.3f, -35.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(0.0f, 0.0f, 0.0f);
        glVertex3f(-8.0f, -35.0f, 0.0f);
        glVertex3f(-8.0f, -65.0f, 0.0f);
        glVertex3f(-0.3f, -65.0f, 0.0f);
        glVertex3f(-0.3f, -35.0f, 0.0f);
    glEnd();

    /* Body */
    glColor3f(117.0f/255.0f,164.0f/255.0f,84.0f/255.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-8.0f, -8.0f, 0.0f);
        glVertex3f(8.0f, -8.0f, 0.0f);
        
        points[0].x = -8.0f;
        points[0].y = -8.0f;
        points[1].x = 8.0f;
        points[1].y = -8.0f;

        /* Control Point */
        points[2].x = -4.0f;
        points[2].y = -4.0f;
        for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
            if(t <= 1.0f){
                GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
                GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
                glVertex2f(x, y);
            }
        }

        glVertex3f(8.0f, -35.0f, 0.0f);
        glVertex3f(-8.0f, -35.0f, 0.0f);

        points[0].x = 8.0f;
        points[0].y = -35.0f;
        points[1].x = -8.0f;
        points[1].y = -35.0f;

        /* Control Point */
        points[2].x = -0.0f;
        points[2].y = -38.0f;
        for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
            if(t <= 1.0f){
                GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
                GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
                glVertex2f(x, y);
            }
        }
    glEnd();

    /* Right Hand */
    glColor3f(253.0f/255.0f, 246.0f/255.0f, 214.0f/255.0f);
    glBegin(GL_POLYGON);
        glVertex3f(8.0f, -8.0f, 0.0f);
        glVertex3f(12.0f, -12.0f, 0.0f);

        points[0].x = 8.0f;
        points[0].y = -8.0f;
        points[1].x = 12.0f;
        points[1].y = -12.0f;

        /* Control Point */
        points[2].x = 10.0f;
        points[2].y = -8.0f;
        for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
            if(t <= 1.0f){
                GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
                GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
                glVertex2f(x, y);
            }
        }

        glVertex3f(12.0f, -35.0f, 0.0f);
        glVertex3f(8.0f, -35.0f, 0.0f);

        points[0].x = 12.0f;
        points[0].y = -35.0f;
        points[1].x = 8.0f;
        points[1].y = -35.0f;

        /* Control Point */
        points[2].x = 10.0f;
        points[2].y = -37.0f;
        for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
            if(t <= 1.0f){
                GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
                GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
                glVertex2f(x, y);
            }
        }
    glEnd();

    /* Bicep */
    glBegin(GL_POLYGON);
        glVertex3f(-8.0f, -8.0f, 0.0f);
        glVertex3f(-8.0f, -14.0f, 0.0f);
        glVertex3f(-15.0f, -17.0f, 0.0f);
        glVertex3f(-15.0f, -12.0f, 0.0f);
    glEnd();
    
    /* Arm */
    glPushMatrix();
    glBegin(GL_POLYGON); 
        glVertex3f(-15.0f, -17.0f, 0.0f);

        glVertex3f(-25.0f, -10.0f, 0.0f);
        glVertex3f(-22.0f, -8.0f, 0.0f);

        points[0].x = -25.0f;
        points[0].y = -10.0f;
        points[1].x = -22.0f;
        points[1].y = -8.0f;

        /* Control Point */
        points[2].x = -25.0f;
        points[2].y = -6.0f;
        for(GLfloat t = 0.0f; t <= 1.0f; t = t + 0.01f){
            if(t <= 1.0f){
                GLfloat x = ((1 - t) * (1 - t) * points[0].x) + (2 * (1 - t) * t * points[2].x) + (t * t * points[1].x);
                GLfloat y = ((1 - t) * (1 - t) * points[0].y) + (2 * (1 - t) * t * points[2].y) + (t * t * points[1].y); 
                glVertex2f(x, y);
            }
        }

        glVertex3f(-15.0f, -12.0f, 0.0f);
    glEnd();
    glPopMatrix();

    /* Stick */
    glColor3ub(0, 0, 0);
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glVertex3f(-26.0f, -8.0f, 0.0f);
    glVertex3f(-36.0f, 2.0f, 0.0f);
    glEnd();

    drawCircle(-36.0f, 2.0f, 1.0f);

    /* Head */
    glColor3f(253.0f/255.0f, 246.0f/255.0f, 214.0f/255.0f);
    drawCircle(0.0f, -0.5f, 8.0f);

    /* Shadow */
    glColor3f(0.3f,0.3f,0.3f);
    glRectf(-10.0f, -65.0f, 10.0f, -66.0f);

}

void drawTeacherAbhilash(void){

	//Head
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.937f, 0.835f); // PapayaWhip color
	for (float angle = 0.0f; angle <= (2 * MY_PI); angle += 0.4f)
	{
		glVertex3f(0.0f, 21.0f, 0.0f);
		glVertex3f(11.0f * sin(angle), (11.0f * cos(angle)) + 21.0f, 0.0f);
		glVertex3f(11.0f * sin(angle + 0.4f), (11.0f * cos(angle + 0.4f)) + 21.0f, 0.0f);
	}
	glEnd();

	// Shoulder
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.937f, 0.835f); // PapayaWhip color
	for (float angle = 2 * MY_PI; angle <= (3 * MY_PI); angle += 0.4f)
	{
		glVertex3f(0.0f, 21.0f, 0.0f);
		glVertex3f(11.0f * sin(angle), (11.0f * cos(angle)) + 21.0f, 0.0f);
		glVertex3f(11.0f * sin(angle + 0.4f), (11.0f * cos(angle + 0.4f)) + 21.0f, 0.0f);
	}
	glEnd();
	
	//body
	glColor3f(0.565f, 0.933f, 0.565f); // LightGreen color for the rectangle
	glBegin(GL_QUADS);
		glVertex3f(-10.0f, 10.0f, 0.0f); // Top-left corner
		glVertex3f(10.0f, 10.0f, 0.0f);  // Top-right corner
		glVertex3f(10.0f, -20.0f, 0.0f); // Bottom-right corner
		glVertex3f(-10.0f, -20.0f, 0.0f); // Bottom-left corner
	glEnd();

	//bend hand
	glColor3f(0.565f, 0.933f, 0.565f);
	glBegin(GL_QUADS);
		glVertex3f(-25.5f, -4.5f, 0.0f);
		glVertex3f(-10.0f, 10.0f, 0.0f);
		glVertex3f(-10.0f, 4.5f, 0.0f);
		glVertex3f(-19.0f, -4.5f, 0.0f);
	glEnd();

	glColor3f(0.565f, 0.933f, 0.565f);
	glBegin(GL_QUADS);
		glVertex3f(-39.0f, 4.5f, 0.0f);
		glVertex3f(-39.0f, 10.0f, 0.0f);
		glVertex3f(-19.0f, -4.5f, 0.0f);
		glVertex3f(-21.75f, -6.5f, 0.0f);
	glEnd();

	// Wrist
	glColor3f(1.0f, 0.937f, 0.835f); // PapayaWhip color (skin color)
	glBegin(GL_TRIANGLES);
	for (float angle = 0.0f; angle <= (2 * MY_PI); angle += 0.4f)
	{
		glVertex3f(-39.0f, 7.5f, 0.0f);
		glVertex3f((2.50f * sin(angle)) - 39.0f, (2.50f * cos(angle)) + 7.5f, 0.0f);
		glVertex3f((2.50f * sin(angle + 0.4f)) - 39.0f, (2.50f * cos(angle + 0.4f)) + 7.5f, 0.0f);
	}
	glEnd();

	// Stick
	glColor3f(1.0f, 0.937f, 0.835f); // PapayaWhip color for the rectangle
	glBegin(GL_QUADS);
		glVertex3f(-78.0f, 33.0f, 0.0f);
		glVertex3f(-78.0f, 34.5f, 0.0f);
		glVertex3f(-39.0f, 8.25f, 0.0f);
		glVertex3f(-39.0f, 6.75f, 0.0f);
	glEnd();

	glColor3f(1.0f, 0.937f, 0.835f);
	glBegin(GL_TRIANGLES);
	for (float angle = 0.0f; angle <= (2 * MY_PI); angle += 0.4f)
	{
		glVertex3f(-78.0f, 33.75f, 0.0f);
		glVertex3f((2.0f * sin(angle)) - 78.0f, (2.0f * cos(angle)) + 33.75f, 0.0f);
		glVertex3f((2.0f * sin(angle + 0.4f)) - 78.0f, (2.0f * cos(angle + 0.4f)) + 33.75f, 0.0f);
	}
	glEnd();

	//tie
	glColor3f(0.133f, 0.545f, 0.133f); // ForestGreen color for the rectangle
	glBegin(GL_QUADS);
		glVertex3f(-2.0f, 10.0f, 0.0f);
		glVertex3f(2.0f, 10.0f, 0.0f);
		glVertex3f(2.0f, -13.0f, 0.0f);
		glVertex3f(-2.0f, -13.0f, 0.0f);
	glEnd();

	glColor3f(0.133f, 0.545f, 0.133f);
	glBegin(GL_TRIANGLES);
		glVertex3f(2.0f, -13.0f, 0.0f);
		glVertex3f(-2.0f, -13.0f, 0.0f);
		glVertex3f(0.0f, -15.0f, 0.0f);
	glEnd();

	// Shoulder
	glColor3f(0.565f, 0.933f, 0.565f); // LightGreen color for the rectangle
	glBegin(GL_TRIANGLES);

	for (float angle = 2 * MY_PI; angle <= (3 * MY_PI); angle += 0.4f)
	{
		glVertex3f(10.0f, 5.5f, 0.0f);
		glVertex3f((4.5f * sin(angle)) + 10.0f, (4.5f * cos(angle)) + 5.5f, 0.0f);
		glVertex3f((4.5f * sin(angle + 0.4f)) + 10.0f, (4.5f * cos(angle + 0.4f)) + 5.5f, 0.0f);
	}
	glEnd();

	//HAND
	glColor3f(0.565f, 0.933f, 0.565f); // LightGreen color for the rectangle
	glBegin(GL_QUADS);
		glVertex3f(10.5f, 5.5f, 0.0f);
		glVertex3f(14.6f, 5.5f, 0.0f);
		glVertex3f(14.7f, -30.0f, 0.0f);
		glVertex3f(10.2f, -30.0f, 0.0f);
	glEnd();

	// Wrist
	glColor3f(1.0f, 0.937f, 0.835f); // PapayaWhip color for the rectangle
	glBegin(GL_TRIANGLES);
	for (float angle = 0.0f; angle <= (2 * MY_PI); angle += 0.4f)
	{
		glVertex3f(12.35f, -30.0f, 0.0f);
		glVertex3f((2.25f * sin(angle)) + 12.35f, (2.25f * cos(angle)) -30.0f, 0.0f);
		glVertex3f((2.25f * sin(angle + 0.4f)) + 12.35f, (2.25f * cos(angle + 0.4f)) -30.0f, 0.0f);
	}
	glEnd();

	// legs
	glColor3f(0.184f, 0.310f, 0.310f); // DarkSlateGray color for the rectangle
	glBegin(GL_QUADS);
		glVertex3f(-10.0f, -20.0f, 0.0f);
		glVertex3f(-0.4f, -20.0f, 0.0f);
		glVertex3f(-0.4f, -60.0f, 0.0f);
		glVertex3f(-10.0f, -60.0f, 0.0f);
	glEnd();

	glColor3f(0.184f, 0.310f, 0.310f);
	glBegin(GL_QUADS);
		glVertex3f(0.4f, -20.0f, 0.0f);
		glVertex3f(10.0f, -20.0f, 0.0f);
		glVertex3f(10.0f, -60.0f, 0.0f);
		glVertex3f(0.4f, -60.0f, 0.0f);
	glEnd();

	// Belt
	glColor3f(0.333f, 0.420f, 0.184f); // DarkOliveGreen color for the rectangle
	glBegin(GL_QUADS);
		glVertex3f(-10.0f, -20.0f, 0.0f);
		glVertex3f(10.0f, -20.0f, 0.0f);
		glVertex3f(10.0f, -22.0f, 0.0f);
		glVertex3f(-10.0f, -22.0f, 0.310f);
	glEnd();

	glColor3f(0.439f, 0.502f, 0.565f); // SlateGray color for the rectangle
	glBegin(GL_QUADS);
		glVertex3f(-1.61f, -19.40f, 0.0f);
		glVertex3f(1.61f, -19.40f, 0.0f);
		glVertex3f(1.61f, -22.60f, 0.0f);
		glVertex3f(-1.61f, -22.60f, 0.310f);
	glEnd();

    /* Shadow */
    glColor3f(0.3f,0.3f,0.3f);
    glRectf(-12.0f, -60.0f, 12.0f, -61.0f);
}

void drawBoard(){
    glColor4ub(132,36,12, 100);
    glBegin(GL_QUADS);
    glVertex3f(-40.0f, 30.0f, 0.0f);
    glVertex3f(40.0f, 30.0f, 0.0f);
    glVertex3f(40.0f, -30.0f, 0.0f);
    glVertex3f(-40.0f, -30.0f, 0.0f);
    glEnd();

    glColor4ub(128,128,128, 100);
    glBegin(GL_QUADS);
    glVertex3f(-35.0f, 25.0f, 0.0f);
    glVertex3f(35.0f, 25.0f, 0.0f);
    glVertex3f(35.0f, -25.0f, 0.0f);
    glVertex3f(-35.0f, -25.0f, 0.0f);
    glEnd();
}

void drawShree(){
    glColor3ub(255, 255, 255);
    glLineWidth(5.0f);
    glBegin(GL_LINES);
        /* Top line */
        glVertex3f(-20.0f, 14.0f, 0.0f);
        glVertex3f(40.0f, 14.0f, 0.0f);

        /* 4 lines */
        glVertex3f(-20.0f, -30.0f, 0.0f);
        glVertex3f(10.0f, 10.0f, 0.0f);
        glVertex3f(10.0f, 10.0f, 0.0f);
        glVertex3f(-10.0f, 10.0f, 0.0f);
        glVertex3f(-10.0f, 10.0f, 0.0f);
        glVertex3f(20.0f, -30.0f, 0.0f);

        /* 1 line */
        glVertex3f(20.0f, 14.0f, 0.0f);
        glVertex3f(20.0f, -40.0f, 0.0f);

        /* 1 line */
        glVertex3f(30.0f, 14.0f, 0.0f);
        glVertex3f(30.0f, -40.0f, 0.0f);

        /* Top Curve */
        glVertex3f(20.0f, 10.0f, 0.0f);
        glVertex3f(20.0f, 30.0f, 0.0f);
        glVertex3f(20.0f, 30.0f, 0.0f);
        glVertex3f(30.0f, 30.0f, 0.0f);
        glVertex3f(30.0f, 30.0f, 0.0f);
        glVertex3f(30.0f, 10.0f, 0.0f);

        /* Left lines */
        glVertex3f(-30.0f, 30.0f, 0.0f);
        glVertex3f(-30.0f, -40.0f, 0.0f);
        glVertex3f(-40.0f, 30.0f, 0.0f);
        glVertex3f(-40.0f, -40.0f, 0.0f);

        /* Right lines */
        glVertex3f(50.0f, 30.0f, 0.0f);
        glVertex3f(50.0f, -40.0f, 0.0f);
        glVertex3f(60.0f, 30.0f, 0.0f);
        glVertex3f(60.0f, -40.0f, 0.0f);

    glEnd();
}

void drawShreeAshish(){
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    for (GLfloat angle = 0.0f; angle <= GL_PI; angle = angle + 0.001f){
        glVertex3f((0.1f * cos(angle)) + 0.0f, (0.1f * sin(angle)) + 0.6f, 0.0f);
    }
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.1f, 0.2f);
        glVertex2f(0.1f, 0.6f);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-0.1f, 0.2f);
        glVertex2f(-0.1f, 0.6f);
    glEnd();

        // 2nd circle touching line
    glBegin(GL_LINES);
        glVertex2f(-0.1f, 0.3f);
        glVertex2f(-0.3f, 0.5f);
    glEnd();

        // both line of shree
    glBegin(GL_LINES);
        glVertex2f(-0.2f, 0.4f);
        glVertex2f(-0.4f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-0.6f, 0.2f);
        glVertex2f(-0.3f, 0.5f);
    glEnd();

    // 2nd circle
    glBegin(GL_LINE_LOOP);
    for (GLfloat angle = 0.0f; angle <= 2 * GL_PI; angle = angle + 0.001f){
        glVertex3f((0.1f * cos(angle)) - 0.3f, (0.1f * sin(angle)) + 0.6f, 0.0f);
    }
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.15f, 0.55f);
        glVertex2f(-0.2f, 0.55f);
    glEnd();

    // both side line 
    glBegin(GL_LINES);
        glVertex2f(0.25f, 0.1f);
        glVertex2f(0.25f, 0.7f);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.35f, 0.1f);
        glVertex2f(0.35f, 0.7f);
    glEnd();

    // left side 
    glBegin(GL_LINES);
        glVertex2f(-0.65f, 0.1f);
        glVertex2f(-0.65f, 0.7f);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-0.75f, 0.1f);
        glVertex2f(-0.75f, 0.7f);
    glEnd();
}

void drawChair(void){
	// ----- Top chair Head rectangle -----
	glBegin(GL_QUADS);
	glColor3f(0.231f, 0.133f, 0.063f); // Brown
	glVertex2f(0.0, 0.13);
	glVertex2f(0.5, 0.13);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.0, 0.5);
	glEnd();

	// ----- Top linked Left Leg -----
	glBegin(GL_QUADS);
	glVertex2f(0.0, 0.52);
	glVertex2f(0.0, -0.70);
	glVertex2f(0.04, -0.70);
	glVertex2f(0.04, 0.52);
	glEnd();

	// ----- Top linked Right Leg -----
	glBegin(GL_QUADS);
	glVertex2f(0.5, 0.52);
	glVertex2f(0.5, -0.70);
	glVertex2f(0.46, -0.70);
	glVertex2f(0.46, 0.52);
	glEnd();

	// ----- Seat -----
	glBegin(GL_QUADS);
	glVertex2f(0.0, -0.2);
	glVertex2f(0.5, -0.2);
	glVertex2f(0.38, -0.4);
	glVertex2f(-0.12, -0.4);
	glEnd();

	// ----- Seat linked Left Leg -----
	glBegin(GL_QUADS);
	glVertex2f(-0.12, -0.4);
	glVertex2f(-0.12, -0.85);
	glVertex2f(-0.08, -0.85);
	glVertex2f(-0.08, -0.4);
	glEnd();

	// ----- Seat linked Right Leg -----
	glBegin(GL_QUADS);
	glVertex2f(0.38, -0.4);
	glVertex2f(0.38, -0.85);
	glVertex2f(0.34, -0.85);
	glVertex2f(0.34, -0.4);
	glEnd();

	// ----- Seat Bottom -----
	glBegin(GL_QUADS);
	glVertex2f(-0.12, -0.4);
	glVertex2f(0.38, -0.4);
	glVertex2f(0.38, -0.45);
	glVertex2f(-0.12, -0.45);
	glEnd();

	// Seat Bottom Right
	glBegin(GL_QUADS);
	glVertex2f(0.38, -0.4);
	glVertex2f(0.5, -0.2);
	glVertex2f(0.5, -0.25);
	glVertex2f(0.38, -0.45);
	glEnd();


	/* // ----- Text at the head of chair -----
	glColor3f(1.0f, 1.0f, 1.0f); // White
	//glColor3f(0.0f, 0.0f, 0.0f); // Black
	glRasterPos2f(0.05f, 0.3f); //define position on the screen
	char* string1 = "Master";
	while (*string1) {
     // glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string1++); // Font
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *string1++); // Font
	} */
}