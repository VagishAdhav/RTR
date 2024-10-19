// header files
#include "GL/freeglut.h"
#include "math.h"

// global variable declarations
BOOL bFullScreen = FALSE;

// Entry-point function
int main(int argc, char *argv[])
{
    // local function declarations
    int initialize(void);
    void resize(int, int);
    void display(void);
    void keyboard(unsigned char, int, int);
    void mouse(int, int, int, int);
    void uninitialize(void);
    void timer(int time);

    //code
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Vagish @ RTR6");

    initialize();
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutCloseFunc(uninitialize);
    glutTimerFunc(1, timer, 10);

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

int i = 0;

float colorArray[3][3] = {{1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}};
float origin[2] = {0, 0};

// store width and height
float rectangle[2] = {0.1, 0.3};

void draw2dTriangle(float* x, float* y)
{
    // triangle top
    glColor3f(colorArray[0][i%3], colorArray[0][(i + 1)%3], colorArray[0][(i + 2)%3]);
    glVertex3f(x[0], y[0], 0.0f);

    glColor3f(colorArray[1][i%3], colorArray[1][(i + 1)%3], colorArray[1][(i + 2)%3]);
    glVertex3f(x[1], y[1], 0.0f);

    glColor3f(colorArray[2][i%3], colorArray[2][(i + 1)%3], colorArray[2][(i + 2)%3]);
    glVertex3f(x[2], y[2], 0.0f);
}


void drawRectangle(float height, float width, float* origin)
{
    // assuming left bottom as origin
    // draw wo triangles
    /*  ___w_____
        |\     |
        |  \   | 
        |    \ |h
        |_____\|
    */

    float x[3], y[3];
     // consider apex at bottom left for first triangle
    x[0] = origin[0];
    y[0] = origin[1];

    x[1] = x[0];
    y[1] = y[0] + height;

    x[2] = x[0] + width;
    y[2] = y[0];

    draw2dTriangle(x, y);

    // apex of second rectangle is at opposite 
    x[0] = origin[0] + width;
    y[0] = origin[1] + height;

    x[1] = x[0];
    y[1] = y[0] - height;

    x[2] = x[0] - width;
    y[2] = y[0];
    
    draw2dTriangle(x, y);
}

void display(void)
{

    float new_origin[2];

    //code 
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);

    drawRectangle(rectangle[0], rectangle[1], origin);

    glEnd();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    //code 
    switch (key)
    {
    case 27:
        glutLeaveMainLoop();
        break;

    case 'd':
    case 'D':
        origin[0] += 0.05; 
        break;

    case 'a':
    case 'A':
        origin[0] -= 0.05; 
        break;

    case 'F':
    case 'f':
        if (bFullScreen == FALSE)
        {
            glutFullScreen();
            bFullScreen = TRUE;
        }
    default:
        break;
    }

    // take care of boundry
    if (origin[0] < -1.0) {
        origin[0] = -1.0;
    }

    if (origin[0] > (1.0 - rectangle[1])) {
        origin[0] = 1.0 - rectangle[1];
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    // code


    switch (button)
    {
        case GLUT_RIGHT_BUTTON:
            glutLeaveMainLoop();
            break;

        case GLUT_LEFT_BUTTON:
            i++;
            //printf("Here are x : %d and y : %d\n",x, y);
            //origin[0] = ((float)x - 400)/400.0;
            //origin[1] = (300- (float)y)/300.0;
            //printf("Here modified x : %f and y : %f\n",origin[0] , origin[1] );
            break;

        default:
            break;
    }
}

void timer(int time)
{
    printf("Timer\n");

}

void uninitialize(void)
{
    //code
}