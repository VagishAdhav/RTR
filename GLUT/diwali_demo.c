// header files
#include "GL/freeglut.h"

// global variable declarations
BOOL bFullScreen = FALSE;

#define RED_CODE  1.0f, 0.0f, 0.0f
#define GREEN_CODE 0.0f, 1.0f, 0.0f
#define BLUE_CODE 0.0f, 0.0f, 1.0f
#define YELLOW_CODE 1.0f, 1.0f, 0.0f
#define ORANGE_CODE 1.0f, 0.74f, 0.0f
#define PINK_CODE 0.87f, 0.19f, 0.38f
#define BLACK_CODE 0.0f, 0.0f, 0.0f
#define WHITE_CODE 1.0f, 1.0f, 1.0f

// Initialise co-ordinates and size of various shapes used in drawing 
#define FOUNTAIN_ORIGIN_X (-0.75f)
#define FOUNTAIN_ORIGIN_Y (-0.70f)
float fountain_base_origin[2] = {FOUNTAIN_ORIGIN_X, FOUNTAIN_ORIGIN_Y};
float fountain_base_size[2] = {0.05f, 0.20f}; //  0- width, 1- height

#define NUM_SPARKLES 8
#define NUM_POINTS_ON_SPARKLE 4
#define SPARKLE_HEIGHT 1.0f
#define SPARKLE_WIDTH  0.3f

//assuming half sparkles on each side
// equally dividing the height

#define SPARKLE_1_WIDTH (SPARKLE_WIDTH/NUM_SPARKLES)
#define SPARKLE_2_WIDTH (SPARKLE_WIDTH/NUM_SPARKLES)
#define SPARKLE_1_HEIGHT (FOUNTAIN_ORIGIN_Y + SPARKLE_HEIGHT)
#define SPARKLE_2_HEIGHT (FOUNTAIN_ORIGIN_Y + SPARKLE_HEIGHT)

#define SPARKLE_3_WIDTH (SPARKLE_1_WIDTH*2)
#define SPARKLE_4_WIDTH (SPARKLE_1_WIDTH*2)
#define SPARKLE_3_HEIGHT ( SPARKLE_1_HEIGHT - (SPARKLE_HEIGHT * 0.25))
#define SPARKLE_4_HEIGHT ( SPARKLE_1_HEIGHT - (SPARKLE_HEIGHT * 0.25))


#define SPARKLE_5_WIDTH (SPARKLE_1_WIDTH*3)
#define SPARKLE_6_WIDTH (SPARKLE_1_WIDTH*3)
#define SPARKLE_5_HEIGHT ( SPARKLE_1_HEIGHT - (SPARKLE_HEIGHT * 0.50))
#define SPARKLE_6_HEIGHT ( SPARKLE_1_HEIGHT - (SPARKLE_HEIGHT * 0.50))

#define SPARKLE_7_WIDTH (SPARKLE_1_WIDTH*4)
#define SPARKLE_8_WIDTH (SPARKLE_1_WIDTH*4)
#define SPARKLE_7_HEIGHT ( SPARKLE_1_HEIGHT - (SPARKLE_HEIGHT * 0.80))
#define SPARKLE_8_HEIGHT ( SPARKLE_1_HEIGHT - (SPARKLE_HEIGHT * 0.80))

/*
	float P1[4][2] = { { 0.0f,-0.5f }, { -0.15f,-0.3f }, { -0.2f,-0.2f }, { -0.25f,-0.45f } }, rgb1[3] = { 0.929, 0.89, 0.349 };
	float P2[4][2] = { { 0.0f,-0.5f }, { -0.05f,-0.25f }, { -0.15f,-0.20f }, { -0.25f,-0.15f } }, rgb2[3] = { 0.929, 0.89, 0.349 };
    float P3[4][2] = { { 0.0f,-0.5f }, { 0.0f,-0.3f }, { -0.15f,0.1f }, { -0.25f,0.25f } }, rgb3[3] = { 0.929, 0.89, 0.349 };
	
	float P4[4][2] = { { 0.0f,-0.5f }, { 0.0f,-0.3f }, { 0.15f,0.1f }, { 0.25f,0.25f } }, rgb4[3] = { 1.0f, 1.0f, 0.0f };
	float P5[4][2] = { { 0.0f,-0.5f }, { 0.05f,-0.25f }, { 0.15f,-0.20f }, { 0.25f,-0.15f } }, rgb5[3] = { 1.0f, 1.0f, 0.0f };
	float P6[4][2] = { { 0.0f,-0.5f }, { 0.15f,-0.3f }, { 0.25f,-0.2f }, { 0.25f,-0.45f } }, rgb6[3] = { 1.0f, 1.0f, 0.0f };

	float P7[4][2] = { { 0.0f,-0.5f }, { 0.0f,-0.15f }, { -0.05f,0.4f }, { -0.1f,0.55f } }, rgb7[3] = { 0.929, 0.89, 0.349 };
	float P8[4][2] = { { 0.0f,-0.5f }, { 0.0f,-0.15f }, { 0.05f,0.4f }, { 0.1f,0.55f } }, rgb8[3] = { 0.929, 0.89, 0.349 };
	*/

float sparkle_coordinates[NUM_SPARKLES][NUM_POINTS_ON_SPARKLE][2] = { \

	{ { FOUNTAIN_ORIGIN_X, FOUNTAIN_ORIGIN_Y }, { FOUNTAIN_ORIGIN_X,SPARKLE_1_HEIGHT - (SPARKLE_HEIGHT*0.80)}, {FOUNTAIN_ORIGIN_X - (SPARKLE_1_WIDTH / 4) , SPARKLE_1_HEIGHT- (SPARKLE_HEIGHT*0.30)}, { FOUNTAIN_ORIGIN_X - SPARKLE_1_WIDTH, SPARKLE_1_HEIGHT } }, \
	{ { FOUNTAIN_ORIGIN_X, FOUNTAIN_ORIGIN_Y }, { FOUNTAIN_ORIGIN_X,SPARKLE_1_HEIGHT - (SPARKLE_HEIGHT*0.80)}, { FOUNTAIN_ORIGIN_X + (SPARKLE_2_WIDTH / 4) , SPARKLE_1_HEIGHT - (SPARKLE_HEIGHT*0.30) }, { FOUNTAIN_ORIGIN_X + SPARKLE_2_WIDTH, SPARKLE_2_HEIGHT} }, \
    
   	{ { FOUNTAIN_ORIGIN_X, FOUNTAIN_ORIGIN_Y }, { FOUNTAIN_ORIGIN_X,SPARKLE_2_HEIGHT - (SPARKLE_HEIGHT*0.80)}, {FOUNTAIN_ORIGIN_X - (SPARKLE_3_WIDTH / 4) , SPARKLE_2_HEIGHT - (SPARKLE_HEIGHT*0.30)}, { FOUNTAIN_ORIGIN_X - SPARKLE_3_WIDTH, SPARKLE_3_HEIGHT } }, \
	{ { FOUNTAIN_ORIGIN_X, FOUNTAIN_ORIGIN_Y }, { FOUNTAIN_ORIGIN_X,SPARKLE_2_HEIGHT - (SPARKLE_HEIGHT*0.80)}, { FOUNTAIN_ORIGIN_X + (SPARKLE_4_WIDTH / 4) ,SPARKLE_2_HEIGHT - (SPARKLE_HEIGHT*0.30) }, { FOUNTAIN_ORIGIN_X + SPARKLE_4_WIDTH, SPARKLE_4_HEIGHT} }, \
    
   	{ { FOUNTAIN_ORIGIN_X, FOUNTAIN_ORIGIN_Y }, { FOUNTAIN_ORIGIN_X,SPARKLE_3_HEIGHT - (SPARKLE_HEIGHT*0.80)}, {FOUNTAIN_ORIGIN_X - (SPARKLE_5_WIDTH / 4) , SPARKLE_3_HEIGHT - (SPARKLE_HEIGHT*0.30)}, { FOUNTAIN_ORIGIN_X - SPARKLE_5_WIDTH, SPARKLE_5_HEIGHT } }, \
	{ { FOUNTAIN_ORIGIN_X, FOUNTAIN_ORIGIN_Y }, { FOUNTAIN_ORIGIN_X,SPARKLE_3_HEIGHT - (SPARKLE_HEIGHT*0.80)}, { FOUNTAIN_ORIGIN_X + (SPARKLE_6_WIDTH / 4) , SPARKLE_3_HEIGHT - (SPARKLE_HEIGHT*0.30) }, { FOUNTAIN_ORIGIN_X + SPARKLE_6_WIDTH, SPARKLE_6_HEIGHT } }, \
    
   	{ { FOUNTAIN_ORIGIN_X, FOUNTAIN_ORIGIN_Y }, { FOUNTAIN_ORIGIN_X,SPARKLE_4_HEIGHT - (SPARKLE_HEIGHT*0.80)}, {FOUNTAIN_ORIGIN_X - (SPARKLE_7_WIDTH / 4) , SPARKLE_4_HEIGHT - (SPARKLE_HEIGHT*0.30)}, { FOUNTAIN_ORIGIN_X - SPARKLE_7_WIDTH, SPARKLE_7_HEIGHT } }, \
	{ { FOUNTAIN_ORIGIN_X, FOUNTAIN_ORIGIN_Y }, { FOUNTAIN_ORIGIN_X,SPARKLE_4_HEIGHT - (SPARKLE_HEIGHT*0.80)}, { FOUNTAIN_ORIGIN_X + (SPARKLE_8_WIDTH / 4), SPARKLE_4_HEIGHT - (SPARKLE_HEIGHT*0.30) }, { FOUNTAIN_ORIGIN_X + SPARKLE_8_WIDTH, SPARKLE_8_HEIGHT } }, \
};

float sparkle_colors[NUM_SPARKLES][3]  = { \
    ORANGE_CODE,ORANGE_CODE,YELLOW_CODE,YELLOW_CODE,ORANGE_CODE,YELLOW_CODE,YELLOW_CODE,YELLOW_CODE };


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
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("RTR-6 Diwali Demo");

	initialize();

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

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

void draw2dTriangle(float* x, float* y, float color[3][3])
{
    // triangle top
    glColor3f(color[0][0], color[0][1], color[0][2]);
    glVertex3f(x[0], y[0], 0.0f);

    glColor3f(color[1][0], color[1][1], color[1][2]);
    glVertex3f(x[1], y[1], 0.0f);

    glColor3f(color[2][0], color[2][1], color[2][2]);
    glVertex3f(x[2], y[2], 0.0f);
}

void drawFountain(void)
{
    float baseColor[3][3] = {{RED_CODE},{RED_CODE},{RED_CODE}};
    float base_vertex_x[3];
    float base_vertex_y[3];
    // fountain traingle
	glBegin(GL_TRIANGLES);

    // x co-ordinates
    base_vertex_x[0] = fountain_base_origin[0];
    base_vertex_x[1] = fountain_base_origin[0] - fountain_base_size[0]/2.0f;
    base_vertex_x[2] = fountain_base_origin[0] + fountain_base_size[0]/2.0f;

    // y-coordinates
    base_vertex_y[0] = fountain_base_origin[1];
    base_vertex_y[1] = fountain_base_origin[1] - fountain_base_size[1];
    base_vertex_y[2] = fountain_base_origin[1] - fountain_base_size[1];

    draw2dTriangle(base_vertex_x, base_vertex_y, baseColor);
	glEnd();

	// code for fountain sparkles
    for (int sparkle = 0; sparkle < NUM_SPARKLES; sparkle++)
    {
        bezier(sparkle_coordinates[sparkle][0], sparkle_coordinates[sparkle][1], sparkle_coordinates[sparkle][2], sparkle_coordinates[sparkle][3], sparkle_colors[sparkle]);
    }
}

void display(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT);

    drawFountain();
	
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
