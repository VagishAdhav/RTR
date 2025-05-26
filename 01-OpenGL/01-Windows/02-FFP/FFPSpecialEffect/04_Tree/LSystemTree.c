#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

#define _USE_MATH_DEFINES (1)
#include <math.h>

#include "LSystemTree.h"

// OpenGL related header files
#include <gl/GL.h>
#include <gl/GLU.h>


GLUquadric *trunk;


int expandTree(LSystemTree **obj, float length, float width,  float angleZ, float angleY, BOOL straight)
{    

    int random = 0;
    int chance = 90;
    char *newBranch[2][2] = {{"[llTL][rTL]", "[llTL]T[rTL]"},
                             {"[lTL][rrTL]", "[lTL]T[rrTL]"}};
    

    srand(time(NULL));

    if (*obj == NULL)
    {
        *obj = (LSystemTree *)malloc(sizeof(LSystemTree));
        (*obj)->trunk_length  = length;
        (*obj)->trunk_width  = width;
        (*obj)->angleY  = angleY;
        (*obj)->angleZ  = angleZ;
        (*obj)->depth = 1;
        (*obj)->pattern = (char *)malloc(20480);
        strcpy((*obj)->pattern, "TL");
    }
    else
    {
        int index = 0;
        char *pattern = (*obj)->pattern;
        char * temp_pattern = (char *)calloc(20480, sizeof(char));
        (*obj)->depth++;
        while (*pattern)
        {
            switch(*pattern)
            {
                case 'T':
                    random = rand();
                    if ((random % 100) < max(chance, 30))
                    {
                        strcpy(&temp_pattern[index], "TT");
                        index += 2;
                    }
                    else
                    {
                        strcpy(&temp_pattern[index], "T");
                        index += 1;
                    }
                    chance -= 20;
                    break;

                case 'L':
                    random = rand();   
                    strcpy(&temp_pattern[index], newBranch[((random % 100) < 50)][straight]);
                    index += strlen(&temp_pattern[index]);
                    break;


                default:
                    temp_pattern[index] = *pattern;
                    index++;
                    break;              
            }
            pattern++;
        }

        strcpy((*obj)->pattern, temp_pattern);
        free(temp_pattern);
        temp_pattern = NULL;
    }
    return 0;
}

int displayTree(LSystemTree *obj)
{
    char *pattern = obj->pattern;
    float TranslateY = obj->trunk_length;
    float pointSize = 0.5f;
    float trunkWidth = obj->trunk_width;

    glPushMatrix();
    while (*pattern)
    {
        switch(*pattern)
        {
            case 'T':
                glColor3f(0.698f, 0.133f, 0.133f);
                glLineWidth(trunkWidth);
                glBegin(GL_LINES);
                    glVertex3f(0.0f, 0.0f, 0.0f);
                    glVertex3f(0.0f, obj->trunk_length, 0.0f);
                glEnd();
                glTranslatef(0.0f,TranslateY, 0.0f);
                break;
            
            case '[':
                glPushMatrix();
                trunkWidth -= 2.0f;
                pointSize += 0.6f;
                break;
            
            case 'l':
                glRotatef(obj->angleZ, 0.0f, 0.0f, 1.0f);
                glRotatef(obj->angleY, 0.0f, 1.0f, 0.0f);
                break;

            case 'r':
                glRotatef(-obj->angleZ, 0.0f, 0.0f, 1.0f);
                glRotatef(obj->angleY, 0.0f, 1.0f, 0.0f);
                break;

            case ']':
                glPopMatrix();
                trunkWidth += 2.0f;
                pointSize -= 0.6f;
                break;

            case 'L':
                glPointSize(pointSize);
                glColor3f(1.000f, 0.412f, 0.706f);
                glBegin(GL_POINTS);
                    glVertex3f(0.0f, 0.0f, 0.0f);
                glEnd();
                break;

            default:
                break;           
        }
        pattern++;
    }
    glPopMatrix();
    return 0;

}

