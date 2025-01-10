// header files
#include<GL/freeglut.h>

// global variable declerations
BOOL bFullScreen = FALSE;

#define a 0.5f
#define b 0.6f
#define n 0.05f // letter size/thickness
#define c 0.5f // distance between each letter

// Entry-point function
int main(int argc, char* argv[])
{
	// local function declerations
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
	glutCreateWindow("OMKAR BHALERAO");

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

void display(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	// letter H
		// part 1
			// t1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-a, b, 0.0f);    // appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-a, b-n, 0.0f);// bottom
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a-n) ,b, 0.0f);// rhs
			// t2
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a-n), (b-n), 0.0f);// appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-a, (b-n), 0.0f);// lhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a-n), b, 0.0f);// top
			// t3
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-a, (b-n), 0.0f);// appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-a, (b - 2.0f * n), 0.0f);// bottom
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a-n), (b-n), 0.0f);// rhs
			// t4
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a-n), (b - 2.0f * n), 0.0f);// rhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-a, (b - 2.0f * n), 0.0f);// lhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a-n), (b-n), 0.0f);// top
			// t5
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-a, (b - 2.0f * n), 0.0f);// lhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-a, (b - 3.0f * n), 0.0f);// rhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a-n), (b - 2.0f * n), 0.0f);// bottom
			//t6
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a-n), (b - 3.0f * n), 0.0f);// rhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-a, (b - 3.0f * n), 0.0f);// lhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - n), (b - 2.0f * n), 0.0f);// top
		// part 2
			// t1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a-n), (b - 2.0f * n), 0.0f);// lhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - 2.0f * n), 0.0f);// rhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a-n), (b-n), 0.0f);// top
			// t2
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b-n), 0.0f);// rhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - 2.0f * n), 0.0f);// bottom
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a-n), (b-n), 0.0f);// lhs
		// part 3
			// t1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), b, 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - n), 0.0f);// bottom
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 3.0f * n), b , 0.0f);// rhs
			// t2
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b-n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 3.0f * n), (b - n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 3.0f * n), b, 0.0f);
			// t3
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b-n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - 2.0f *n), 0.0f);// bottom
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 3.0f * n), (b-n), 0.0f);// rhs
			// t4
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 3.0f * n), (b - 2.0f * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - 2.0f * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 3.0f * n), (b-n), 0.0f);
			// t5
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - 2.0f * n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - 3.0f * n), 0.0f);// bottom
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 3.0f * n), (b - 2.0f * n), 0.0f);// rhs
			// t6
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 3.0f * n), (b - 3.0f *n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - 3.0f *n), 0.0f);// bottom
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 3.0f * n), (b - 2.0f * n), 0.0f);// rhs
	// letter A
		// part 1
			// t1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (3.0f + c) * n), (b - 3.0f * n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (4.0 + c) * n), (b - 3.0f * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (4.0f + c ) * n), (b - 2.0f * n), 0.0f);// top
			// t1.1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (4.0f + c) * n), (b - 3.0f * n), 0.0f);// bottom point
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (5.0f + c) * n), (b - 2.0f * n), 0.0f);// appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (4.0f + c) * n), (b - 2.0f * n), 0.0f);
			// t2 // line
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (5.0f + c) * n), (b - 2.0f * n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (5.0 + c) * n), (b - n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (4.0f + c) * n), (b - 2.0f * n), 0.0f);// top
			// t2.1 
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (5.0f + c) * n), (b - 2.0f * n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (6.0f + c) * n), (b - n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (5.0 + c) * n), (b - n), 0.0f); // top
			// t3
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (6.0f + c) * n), (b -  n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (5.0 + c) * n), (b - n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (6.0f + c) * n), b , 0.0f);
			// t4
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (6.0f + c) * n), (b - n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (7.0 + c) * n), (b - n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (6.0f + c) * n), b, 0.0f);
			// t5 // line2
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (7.0f + c) * n), (b - 2.0f * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (7.0 + c) * n), (b - n), 0.0f);//
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (8.0f + c) * n), (b - 2.0f * n), 0.0f);
			// t5.1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (7.0f + c) * n), (b - 2.0f * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (6.0f + c) * n), (b - n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (7.0 + c) * n), (b - n), 0.0f);//
			// t6
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (9.0f + c) * n), (b - 3.0f * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (8.0 + c) * n), (b - 3.0f * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (8.0f + c) * n), (b - 2.0f * n), 0.0f);//
			// t6.1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (8.0f + c) * n), (b - 3.0f * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (7.0f + c) * n), (b - 2.0f * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (8.0f + c) * n), (b - 2.0f * n), 0.0f);//
		// part2
			// t1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (5.0f + c) * n), (b - 2.0f * n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (5.5 + c) * n), (b - 2.5f * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (6.0f + c) * n), (b - 2.0f * n), 0.0f);// top
			// t1.1, t2.1, t2.2
	for (int i = 0; i < 3; i++)
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (5.0f + i+ c) * n), (b - 2.0f * n), 0.0f);//appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (5.5 + i+ c) * n), (b - 2.5f * n), 0.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (4.5f + i +c) * n), (b - 2.5f * n), 0.0f);// top
	}
			// t2
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (6.0f + c) * n), (b - 2.0f * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (6.5 + c) * n), (b - 2.5f * n), 0.0f);// appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (7.0f + c) * n), (b - 2.0f * n), 0.0f);
	// letter P
		// part 1
			// t1,2,3
	for (int i = 0; i < 3; i++)//changes 2.0f *
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (10.0f +(2.0f * c)) * n), (b - (3.0f - i) * n), 0.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((9.0 ) + (2.0f * c)) * n), (b - (3.0f - i) * n), 0.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((9.0f ) + (2.0f * c)) * n), (b - (2.0f - i) * n), 0.0f);
			// t4,5,6
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((10.0f) + (2.0f * c)) * n), (b - (3.0f - i) * n), 0.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((10.0) + (2.0f * c)) * n), (b - (2.0f - i) * n), 0.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((9.0f) + (2.0f * c)) * n), (b - (2.0f - i) * n), 0.0f);
	} 
		// part 2
			// t1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((10.0f) + (2.0f * c)) * n), (b - (1.0f ) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((10.0) + (2.0f * c)) * n), (b - (0.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((11.0f) + (2.0f * c)) * n), (b - (0.0f ) * n), 0.0f);
			// t2
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((10.0f) + (2.0f * c)) * n), (b - (1.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((11.0) + (2.0f * c)) * n), (b - (1.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((11.0f) + (2.0f * c)) * n), (b - (0.0f) * n), 0.0f);
			// t3
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((12.0f) + (2.0f * c)) * n), (b - (1.0f) * n), 0.0f);// along appex rhs 
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((11.0) + (2.0f * c)) * n), (b - (1.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((11.0f) + (2.0f * c)) * n), (b - (0.0f) * n), 0.0f);
			// t4
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((12.0f) + (2.0f * c)) * n), (b - (1.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((11.0) + (2.0f * c)) * n), (b - (1.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((12.0f) + (2.0f * c)) * n), (b - (2.0f) * n), 0.0f);
			// t5
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((10.0f) + (2.0f * c)) * n), (b - (2.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((11.0) + (2.0f * c)) * n), (b - (1.0f) * n), 0.0f);//
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((12.0f) + (2.0f * c)) * n), (b - (2.0f) * n), 0.0f);//
	// Letter p
		//part 1
			// t1,2,3
	for (int i = 0; i < 3; i++)// changes 3.0f *
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((13.0f) + (3.0f * c)) * n), (b - (3.0f - i) * n), 0.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((12.0) + (3.0f * c)) * n), (b - (3.0f - i) * n), 0.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((12.0f) + (3.0f * c)) * n), (b - (2.0f - i) * n), 0.0f);
		// t4,5,6
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((13.0f) + (3.0f * c)) * n), (b - (3.0f - i) * n), 0.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((13.0) + (3.0f * c)) * n), (b - (2.0f - i) * n), 0.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((12.0f) + (3.0f * c)) * n), (b - (2.0f - i) * n), 0.0f);
	}
		// part 2
			// t1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((13.0f) + (3.0f * c)) * n), (b - (1.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((13.0) + (3.0f * c)) * n), (b - (0.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((14.0f) + (3.0f * c)) * n), (b - (0.0f) * n), 0.0f);
			// t2
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((13.0f) + (3.0f * c)) * n), (b - (1.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((14.0) + (3.0f * c)) * n), (b - (1.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((14.0f) + (3.0f * c)) * n), (b - (0.0f) * n), 0.0f);
			// t3
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((15.0f) + (3.0f * c)) * n), (b - (1.0f) * n), 0.0f);// along appex rhs 
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((14.0) + (3.0f * c)) * n), (b - (1.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((14.0f) + (3.0f * c)) * n), (b - (0.0f) * n), 0.0f);
			// t4
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((15.0f) + (3.0f * c)) * n), (b - (1.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((14.0) + (3.0f * c)) * n), (b - (1.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((15.0f) + (3.0f * c)) * n), (b - (2.0f) * n), 0.0f);
			// t5
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((13.0f) + (3.0f * c)) * n), (b - (2.0f) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((14.0) + (3.0f * c)) * n), (b - (1.0f) * n), 0.0f);//
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((15.0f) + (3.0f * c)) * n), (b - (2.0f) * n), 0.0f);//
	// letter Y
		// part 1
	for (int i = 0; i < 2; i++)//chnages 4.0f *
	{
		// t1,t2
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((16.0f) + 4.0f * c) * n), (b - (3.0f - i) * n), 0.0f);// lhs
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((16.0) + 4.0f * c) * n), (b - (2.0f - i) * n), 0.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((17.0f) + 4.0f * c) * n), (b - (2.0f - i) * n), 0.0f);// top right
		// t3,t4
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((16.0f) + 4.0f * c) * n), (b - (3.0f - i) * n), 0.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((17.0) + 4.0f * c) * n), (b - (3.0f - i) * n), 0.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - ((17.0f) + 4.0f * c) * n), (b - (2.0f - i) * n), 0.0f);// top right
	}
		// part 2
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((16.0) + 4.0f * c) * n), (b - (1.0f) * n), 0.0f);// topleft
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((17.0f) + 4.0f * c) * n), (b - (1.0f) * n), 0.0f);// top right
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (16.5f + 4.0f * c) * n), (b - 0.5f * n), 0.0f);// appex
		// part 3
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((16.0) + 4.0f * c) * n), (b - (1.0f) * n), 0.0f);// appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (16.5f + 4.0f * c) * n), (b - 0.5f * n), 0.0f);// top right
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((15.0f) + 4.0f * c) * n), (b - (-0.5f) * n), 0.0f);// long point
		// part 4
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((17.0) + 4.0f * c) * n), (b - (1.0f) * n), 0.0f);// appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (16.5f + 4.0f * c) * n), (b - 0.5f * n), 0.0f);// top right
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - ((18.0f) + 4.0f * c) * n), (b - (-0.5f) * n), 0.0f);// long point
	// letter D
		// part 1
	for (int i = 0; i < 3; i++)
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// lhs point
		// t4,5,6
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - n ), (b - (4.0f + i + 3.0f *  c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - n ), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a ), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// lhs point
	}
		// part 2
			// lower triangle t1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - n), (b - (6.0f + 3.0f * c) * n), 0.0f);// lower point -> appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - n), (b - (5.0f + 3.0f * c) * n), 0.0f);// appex -> top point
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// change -> rhs
			// uppper triangle t3
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - n), (b - (4.0f + 3.0f * c) * n), 0.0f);// lower point -> appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - n), (b - (3.0f + 3.0f * c) * n), 0.0f);// appex -> top point
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - (4.0f + 3.0f * c) * n), 0.0f);// change -> rhs
			// t2
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - (5.0f + 3.0f * c) * n), 0.0f);//  appex -> change(appex)
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - n), (b - (5.0f + 3.0f * c) * n), 0.0f);// top point -> lhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// rhs -> bottom point
			// t4
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - (3.0f + 3.0f * c) * n), 0.0f);// appex-> change(appex)
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - n), (b - (3.0f + 3.0f * c) * n), 0.0f);// top point-> lhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - (4.0f + 3.0f * c) * n), 0.0f);//  rhs-> bottom point
		// part 3
			// t1
	glColor3f(1.0f, 0.5f, 0.0f);//////////////////////////////////////////////////////////////////////////// ignore comments
	glVertex3f(-(a - 2.0f * n), (b - (3.0f + 3.0f * c) * n), 0.0f);// appex -> top point
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 3.0f * n), (b - (3.5f + 3.0f * c) * n), 0.0f);//  lhs -> appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - (4.0f + 3.0f * c) * n), 0.0f);// bottom point -> bottom point
			// t2
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 3.0f * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// top point -> bottom point
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 3.0f * n), (b - (3.5f + 3.0f * c) * n), 0.0f);// appex -> same as above
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - (4.0f + 3.0f * c) * n), 0.0f);//  bottom point -> same as above
			// t3
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 3.0f * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// top point -> bottom point
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// appex -> change
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - 2.0f * n), (b - (4.0f + 3.0f * c) * n), 0.0f);//  bottom point -> same as above
	// letter I
		// part 1
	for (int i = 0; i < 3; i++)
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (5.0f + c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (4.0f + c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (4.0f + c )* n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// lhs point
		// t4,5,6
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (5.0f + c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (5.0f + c) * n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (4.0f + c )* n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// lhs point
	}
		// part 2 above
	for (int i = 0; i < 3; i++)
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a -  (4.0f + c + i) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a -  (3.0f + c + i) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a -  (3.0f +c + i )* n), (b - (3.0f + 3.0f * c) * n), 0.0f);// lhs point
		// t4,5,6
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a -  (4.0f + c  + i) * n), (b - (4.0f  + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a -  (4.0f + c + i) * n), (b - (3.0f  + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a -  (3.0f + c + i) * n), (b - (3.0f  + 3.0f * c) * n), 0.0f);// lhs point
	}
		//part 2 below
	for (int i = 0; i < 3; i++)
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (4.0f + c + i) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (3.0f + c + i) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (3.0f + c + i) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// lhs point
		// t4,5,6
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (4.0f + c  + i) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (4.0f + c + i) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (3.0f + c + i) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// lhs point
	}
	// letter W
		// part 1
	for (int i = 0; i < 3; i++)
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (7.0f + 2.0f * c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (6.0f + 2.0f * c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (6.0f + 2.0f * c) * n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// lhs point
		// t4,5,6
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (7.0f + 2.0f * c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (7.0f + 2.0f * c) * n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (6.0f + 2.0f * c) * n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// lhs point
	}
		// part 3
	for (int i = 0; i < 3; i++)
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (9.0f + 2.0f * c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (8.0f + 2.0f * c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (8.0f + 2.0f * c) * n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// lhs point
		// t4,5,6
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (9.0f + 2.0f * c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (9.0f + 2.0f * c) * n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (8.0f + 2.0f * c) * n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// lhs point
	}
		// part 2
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (8.0f + 2.0f * c) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// rhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (7.0f + 2.0f * c) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// lhs
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (7.5f + 2.0f * c) * n), (b - (4.5f + 3.0f * c) * n), 0.0f);
	// letter A
		// part 1
			// t1//
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (9.0f + 3.0f * c) * n), (b - (6.0f + 3.0f * c)* n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (10.0 + 3.0f * c) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (10.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// top
			// t1.1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (11.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (10.0 + 3.0f * c) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (10.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// top
			// t2 // line
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (11.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (11.0 + 3.0f * c) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (10.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// bottom lhs
			// t2.1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (11.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (11.0 + 3.0f * c) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (12.0f + 3.0f * c) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);
			// t3
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (12.0f + 3.0f * c) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (12.0 + 3.0f * c) * n), (b - (3.0f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (11.0f + 3.0f * c) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);
			// t4
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (13.0f + 3.0f * c) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (12.0 + 3.0f * c) * n), (b - (3.0f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (12.0f + 3.0f * c) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);
			// t5 // line2
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (13.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (13.0 + 3.0f * c) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (14.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// bottom lhs
			// 5.1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (13.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (13.0 + 3.0f * c) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (12.0f + 3.0f * c) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);
			// t6
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (14.0f + 3.0f * c) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (14.0 + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (15.0f + 3.0f * c) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// bottom lhs
			// 6.1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (14.0f + 3.0f * c) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (14.0 + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (13.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);//appex
		// part2
			// t1
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (11.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);//appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (11.5 + 3.0f * c) * n), (b - (5.5f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (12.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// top
			// t1.1, t2.1, t2.2
	for (int i = 0; i < 3; i++)
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (11.0f + i + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);//appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (11.5 + i + 3.0f * c) * n), (b - (5.5f + 3.0f * c) * n), 0.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (10.5f + i + 3.0f * c) * n), (b - (5.5f + 3.0f * c) * n), 0.0f);// top
	}
			// t2
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (12.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (12.5 + 3.0f * c) * n), (b - (5.5f + 3.0f * c) * n), 0.0f);// appex
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-(a - (13.0f + 3.0f * c) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);
	// letter L
		// part 1
	for (int i = 0; i < 3; i++)
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (16.0f + 4.0f * c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (15.0f + 4.0f * c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (15.0f + 4.0f * c) * n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// lhs point
		// t4,5,6
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (16.0f + 4.0f * c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (16.0f + 4.0f * c) * n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (15.0f + 4.0f * c) * n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// lhs point
	}
		// part 2
	for (int i = 0; i < 3; i++)
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (16.0f + 4.0f * c + i) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (15.0f + 4.0f * c + i) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (15.0f + 4.0f * c + i) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// lhs point
		// t4,5,6
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (16.0f + 4.0f * c + i) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (16.0f + 4.0f * c + i) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (15.0f + 4.0f * c + i) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// lhs point
	}
	// letter I
		// part 1
	for (int i = 0; i < 3; i++)
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (20.0f + 5.0f *  c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (19.0f + 5.0f * c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (19.0f + 5.0f * c) * n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// lhs point
		// t4,5,6
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (20.0f + 5.0f * c) * n), (b - (4.0f + i + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (20.0f + 5.0f * c) * n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (19.0f + 5.0f * c) * n), (b - (3.0f + i + 3.0f * c) * n), 0.0f);// lhs point
	}
	// part 2 above
	for (int i = 0; i < 3; i++)
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (18.0f + 5.0f * c + i) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (19.0f + 5.0f * c + i) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (18.0f + 5.0f * c + i) * n), (b - (3.0f + 3.0f * c) * n), 0.0f);// lhs point
		// t4,5,6
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (19.0f + 5.0f * c + i) * n), (b - (4.0f + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (18.0f + 5.0f * c + i) * n), (b - (3.0f + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (19.0f + 5.0f * c + i) * n), (b - (3.0f + 3.0f * c) * n), 0.0f);// lhs point
	}
	//part 2 below
	for (int i = 0; i < 3; i++)
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (18.0f + 5.0f * c + i) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (19.0f + 5.0f * c + i) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (18.0f + 5.0f * c + i) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// lhs point
		// t4,5,6
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (19.0f + 5.0f * c + i) * n), (b - (6.0f + 3.0f * c) * n), 0.0f);// lower point
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (18.0f + 5.0f * c + i) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// appex
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-(a - (19.0f + 5.0f * c + i) * n), (b - (5.0f + 3.0f * c) * n), 0.0f);// lhs point
	}
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

void uninitialize()
{
	// code
}