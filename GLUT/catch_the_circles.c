// header files
#include "GL/freeglut.h"
#include "math.h"
#include "my_colors.h"


// global variable declarations
BOOL bFullScreen = FALSE;

int i = 0;

// rect co-ordinates
float rect_origin[2] = {-0.0, -0.8};
float rect_size[2] = {0.1, 0.3};

// circle co-ordinates
float circ_origin[2] = {-0.5, 1.0};
float circ_radius = 0.25;

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


void draw2dTriangle(float* x, float* y, float** color)
{
    // triangle top
    glColor3f(color[0][0], color[0][1], color[0][2]);
    glVertex3f(x[0], y[0], 0.0f);

    glColor3f(color[1][0], color[1][1], color[1][2]);
    glVertex3f(x[1], y[1], 0.0f);

    glColor3f(color[2][0], color[2][1], color[2][2]);
    glVertex3f(x[2], y[2], 0.0f);
}

void drawCircle(float radius, float* origin)
{
    float const STEP = 0.01;
    float colorArray[6][3] = {RED_CODE, GREEN_CODE, BLUE_CODE, YELLOW_CODE, PINK_CODE, ORANGE_CODE};
    for (float angle = 0.0; angle <= 360.0; angle += STEP)
    {
        // triangle top
        glColor3f(colorArray[0][i%3], colorArray[0][(i + 1)%3], colorArray[0][(i + 2)%3]);
        glVertex3f(origin[0], origin[1], 0.0f);

        float x = origin[0] + (radius * cos(angle));
        float y = origin[1] + (radius * sin(angle));

        glColor3f(colorArray[1][i%3], colorArray[1][(i + 1)%3], colorArray[1][(i + 2)%3]);
        glVertex3f(x, y, 0.0f);

        angle += STEP; 
//
        x = origin[0] + (radius * cos(angle));
        y = origin[1] + (radius * sin(angle));


        glColor3f(colorArray[2][i%3], colorArray[2][(i + 1)%3], colorArray[2][(i + 2)%3]);
        glVertex3f(x, y, 0.0f);
    }
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

    // array for x, y co-ordinates of 3 points of triangle
    float x[3], y[3];


    // array for 3 vertex colors
    float clr[3][3] = {{ORANGE_CODE}, {PINK_CODE}, {PINK_CODE}};
     // consider apex at bottom left for first triangle
    x[0] = origin[0];
    y[0] = origin[1];

    x[1] = x[0];
    y[1] = y[0] + height;

    x[2] = x[0] + width;
    y[2] = y[0];

    draw2dTriangle(x, y, clr);

    // apex of second rectangle is at opposite 
    x[0] = origin[0] + width;
    y[0] = origin[1] + height;

    x[1] = x[0];
    y[1] = y[0] - height;

    x[2] = x[0] - width;
    y[2] = y[0];
    
    draw2dTriangle(x, y, clr);
}

void display(void)
{

    float new_origin[2];

    //code 
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);

    drawRectangle(rect_size[0], rect_size[1], rect_origin);
    drawCircle(circ_radius, circ_origin);

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
        rect_origin[0] += 0.05; 
        break;

    case 'a':
    case 'A':
        rect_origin[0] -= 0.05; 
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
    if (rect_origin[0] < -1.0) {
        rect_origin[0] = -1.0;
    }

    if (rect_origin[0] > (1.0 - rect_size[1])) {
        rect_origin[0] = 1.0 - rect_size[1];
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
            break;

        default:
            break;
    }
}

void timer(int time)
{
    printf("Timer\n");
    circ_origin[1] -= 0.01;

    if (circ_origin[1] >= -0.9 ) {
        // flash red 
        circ_origin[1] = 1.0;
    }

    glutTimerFunc(1, timer, 10);
    glutPostRedisplay();

}

void uninitialize(void)
{
    //code
}