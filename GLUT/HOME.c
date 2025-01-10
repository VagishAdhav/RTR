// header files
#include<gl/freeglut.h>

// global variable declarations
BOOL bFullScreen = TRUE;

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

	// code
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Abhijit Manohar Mane");

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
	glClearColor(0.831f, 1.0f, 0.918f, 1.0f);
	glutFullScreen();
	return(0);
}

void resize(int width, int height)
{
	// code
	glViewport(0, 0, width, height);
}

void display(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);

	//Top L
	// glColor3f(0.4f, 0.008f, 0.008f);
	// glVertex3f(0.43f, 0.4f, 0.0f);
	// glColor3f(0.4f, 0.008f, 0.008f);
	// glVertex3f(0.35f, 0.075f, 0.0f);
	// glColor3f(0.4f, 0.008f, 0.008f);
	// glVertex3f(0.95f, 0.075f, 0.0f);
	//R
	glColor3f(0.4f, 0.008f, 0.008f);
	glVertex3f(0.87f, 0.4f, 0.0f);
	glColor3f(0.4f, 0.008f, 0.008f);
	glVertex3f(0.43f, 0.4f, 0.0f);
	glColor3f(0.4f, 0.008f, 0.008f);
	glVertex3f(0.95f, 0.075f, 0.0f);

	//Top outer Triangle
	glColor3f(1.0f, 0.423f, 0.302f);
	glVertex3f(0.65f, 0.35f, 0.0f);
	glColor3f(1.0f, 0.423f, 0.302f);
	glVertex3f(0.55f, 0.1f, 0.0f);
	glColor3f(1.0f, 0.423f, 0.302f);
	glVertex3f(0.75f, 0.1f, 0.0f);

	//Top Inner Triangle
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.65f, 0.25f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.61f, 0.13f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.69f, 0.13f, 0.0f);

	//Rectrangle L
	glColor3f(1.0f, 0.824f, 0.0f);
	glVertex3f(0.4f, 0.1f, 0.0f);
	glColor3f(1.0f, 0.824f, 0.0f);
	glVertex3f(0.4f, -0.4f, 0.0f);
	glColor3f(1.0f, 0.824f, 0.0f);
	glVertex3f(0.9f, -0.4f, 0.0f);
	//R
	glColor3f(1.0f, 0.824f, 0.0f);
	glVertex3f(0.9f, 0.1f, 0.0f);
	glColor3f(1.0f, 0.824f, 0.0f);
	glVertex3f(0.4f, 0.1f, 0.0f);
	glColor3f(1.0f, 0.824f, 0.0f);
	glVertex3f(0.9f, -0.4f, 0.0f);

	//Door Inner Rectrangle L
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.6f, -0.13f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.6f, -0.4f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.7f, -0.4f, 0.0f);
	//R
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.7f, -0.13f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.6f, -0.13f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.7f, -0.4f, 0.0f);

	//L Door Rectrangle L
	glColor3f(0.49f, 0.0f, 0.0f);
	glVertex3f(0.6f, -0.13f, 0.0f);
	glColor3f(0.49f, 0.0f, 0.0f);
	glVertex3f(0.6f, -0.4f, 0.0f);
	glColor3f(0.49f, 0.0f, 0.0f);
	glVertex3f(0.645f, -0.4f, 0.0f);
	//R
	glColor3f(0.49f, 0.0f, 0.0f);
	glVertex3f(0.645f, -0.13f, 0.0f);
	glColor3f(0.49f, 0.0f, 0.0f);
	glVertex3f(0.6f, -0.13f, 0.0f);
	glColor3f(0.49f, 0.0f, 0.0f);
	glVertex3f(0.645f, -0.4f, 0.0f);

	//R Door Rectrangle L
	glColor3f(0.49f, 0.0f, 0.0f);
	glVertex3f(0.655f, -0.13f, 0.0f);
	glColor3f(0.49f, 0.0f, 0.0f);
	glVertex3f(0.655f, -0.4f, 0.0f);
	glColor3f(0.49f, 0.0f, 0.0f);
	glVertex3f(0.7f, -0.4f, 0.0f);
	//R
	glColor3f(0.49f, 0.0f, 0.0f);
	glVertex3f(0.7f, -0.13f, 0.0f);
	glColor3f(0.49f, 0.0f, 0.0f);
	glVertex3f(0.655f, -0.13f, 0.0f);
	glColor3f(0.49f, 0.0f, 0.0f);
	glVertex3f(0.7f, -0.4f, 0.0f);

	//Window Rectrangle L
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.75f, -0.05f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.75f, -0.2f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.85f, -0.2f, 0.0f);
	//R
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.85f, -0.05f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.75f, -0.05f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.85f, -0.2f, 0.0f);

	//L Window Rectrangle L
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.75f, -0.05f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.75f, -0.2f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.778f, -0.2f, 0.0f);
	//R
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.778f, -0.05f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.75f, -0.05f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.778f, -0.2f, 0.0f);
	//M Window Rectrangle L
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.786f, -0.05f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.786f, -0.2f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.814f, -0.2f, 0.0f);
	//R
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.814f, -0.05f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.786f, -0.05f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.814f, -0.2f, 0.0f);
	//R Window Rectrangle L
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.822f, -0.05f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.822f, -0.2f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.85f, -0.2f, 0.0f);
	//R
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.85f, -0.05f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.822f, -0.05f, 0.0f);
	glColor3f(0.0f, 0.702f, 1.0f);
	glVertex3f(0.85f, -0.2f, 0.0f);

	glEnd();

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