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

float colorArray[3][3] = {{1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}};
float origin[2] = {0.0, 0.0};

// The general formula for a circle centered at (h, k) with radius r is (x-h)^2 + (y-k)^2 = r^2.
// idea is to calculate y with increments in x
// (y-k)^2 = r^2 - (x-h)^2
// y = sqrt(r^2 - (x-h)^2) - k
void drawCircle(float radius, float* origin)
{
    float const STEP = 0.1;
    for (float angle = 0.0; angle <= 360.0; angle += STEP)
    {
        // triangle top
        glColor3f(colorArray[0][i%3], colorArray[0][(i + 1)%3], colorArray[0][(i + 2)%3]);
        glVertex3f(origin[0], origin[1], 0.0f);

        float x = origin[0] + (radius * cos(angle));
        float y = origin[1] + (radius * sin(angle));

        glColor3f(colorArray[1][i%3], colorArray[1][(i + 1)%3], colorArray[1][(i + 2)%3]);
        glVertex3f(x, y, 0.0f);

        x += STEP; 

        x = origin[0] + (radius * cos(angle));
        y = origin[1] + (radius * sin(angle));

        glColor3f(colorArray[1][i%3], colorArray[1][(i + 1)%3], colorArray[1][(i + 2)%3]);
        glVertex3f(x, y, 0.0f);

        glColor3f(colorArray[2][i%3], colorArray[2][(i + 1)%3], colorArray[2][(i + 2)%3]);
        glVertex3f(x, y, 0.0f);
    }
}

void display(void)
{
    float new_origin[2];
    //code 
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);

    drawCircle(0.2, &origin[0]);
    new_origin[0] = -1.0  * origin[0];
    new_origin[1] =  -1.0 * origin[1];
    drawCircle(0.2, &new_origin[0]);
    new_origin[0] =  1.0  * origin[0];
    new_origin[1] =  -1.0 * origin[1];
    drawCircle(0.2, &new_origin[0]);
    new_origin[0] =  -1.0  * origin[0];
    new_origin[1] =  1.0 * origin[1];
    drawCircle(0.2, &new_origin[0]);
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
            printf("Here are x : %d and y : %d\n",x, y);
            origin[0] = ((float)x - 400)/400.0;
            origin[1] = (300- (float)y)/300.0;
            printf("Here modified x : %f and y : %f\n",origin[0] , origin[1] );
            break;

        default:
            break;
    }
}

void uninitialize(void)
{
    //code
}