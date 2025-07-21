#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

#define _USE_MATH_DEFINES (1)
#include <math.h>

#include "LSystemTree.h"

extern FILE *gpFile;
// OpenGL related header files
#include <gl/GL.h>
#include <gl/GLU.h>


int createTree(LSystemTree **obj, float length, float width,  float angleZ, float angleY, BOOL straight, drawTreePart drawTrunk, drawTreePart drawLeaf)
{
    if (*obj == NULL)
    {
        *obj = (LSystemTree *)malloc(sizeof(LSystemTree));
        (*obj)->trunk_length  = length;
        (*obj)->trunk_width  = width;
        (*obj)->angleY  = angleY;
        (*obj)->angleZ  = angleZ;
        (*obj)->straight = straight;
        (*obj)->drawLeaf = drawLeaf;
        (*obj)->drawTrunk = drawTrunk;
        (*obj)->depth = 1;
        (*obj)->pattern = (char *)calloc(20480, sizeof(char));
        //strcpy((*obj)->pattern, "TL");
        strcpy((*obj)->pattern, "TTTTTTTTTTTTTTT[llTT[llTTT[lTT[llTTT[lT[llTL][rTL]][rrT[llTL][rTL]]][rTT[llTT[llTL][rTL]][rTT[llTL][rTL]]]][rrT[lTT[lT[lTL][rrTL]][rrT[llTL][rTL]]][rrTT[llT[lTL][rrTL]][rT[lTL][rrTL]]]]][rTTTT[llTTTT[llT[llT[lTL][rrTL]][rTT[lTL][rrTL]]][rTT[lTT[llTL][rTL]][rrT[llTL][rTL]]]][rTTTT[llT[llT[llTL][rTL]][rT[lTL][rrTL]]][rTT[llT[llTL][rTL]][rT[lTL][rrTL]]]]]][rTT[lTT[lT[lTTT[llT[lTL][rrTL]][rTT[llTL][rTL]]][rrTT[lT[llTL][rTL]][rrTT[lTL][rrTL]]]][rrTT[lTT[llT[llTL][rTL]][rT[llTL][rTL]]][rrTT[lT[lTL][rrTL]][rrTT[llTL][rTL]]]]][rrTTT[llTTT[lTT[lTT[llTL][rTL]][rrT[lTL][rrTL]]][rrT[lTT[lTL][rrTL]][rrTT[llTL][rTL]]]][rTTTT[llT[llT[llTL][rTL]][rT[llTL][rTL]]][rT[lT[lTL][rrTL]][rrTT[lTL][rrTL]]]]]]");
        return 0;
    }

    return -1;
}

int expandTree(LSystemTree **obj, unsigned int maxDepth)
{    

    int random = 0;
    int chance = 90;
    char *newBranch[2][2] = {{"[llTL][rTL]", "[llTL]T[rTL]"},
                             {"[lTL][rrTL]", "[lTL]T[rrTL]"}};

    char *temp_pattern = (char *)calloc(20480, sizeof(char));

    strcpy((*obj)->pattern, "TL");

    while ((*obj)->depth < maxDepth)
    {
        (*obj)->depth++;
        
        char *pattern = (*obj)->pattern;

        srand(time(NULL));
        int index = 0;

        while (*pattern)
        {
            switch(*pattern)
            {
                case 'T':
                    random = rand();
                    if (((random % 100) < max(chance, 30)) || (index == 0))
                    {
                        strcpy(&temp_pattern[index], "TT");
                        index += 2;
                    }
                    else
                    {
                        strcpy(&temp_pattern[index], "T");
                        index += 1;
                    }
                    chance -= 50;
                    break;

                case 'L':
                    random = rand();   
                    strcpy(&temp_pattern[index], newBranch[((random % 100) < 50)][(*obj)->straight]);
                    index += strlen(&temp_pattern[index]);

                    break;

                default:

                    temp_pattern[index] = *pattern;
                    index++;
                    break;              
            }
            pattern++;
        }
        strncpy((*obj)->pattern, temp_pattern, index);
        memset(&temp_pattern[0], 0, sizeof(temp_pattern));
    }

    fprintf(gpFile, "Expanded tree : %s\n", (*obj)->pattern);


    free(temp_pattern);
    temp_pattern = NULL;

    return 0;
}

int displayTree(LSystemTree *obj)
{
    char *pattern = obj->pattern;
    float TranslateY = obj->trunk_length;
    float trunkWidth = obj->trunk_width;
    float widthReduction = 0.2f;

    while (*pattern)
    {
        switch(*pattern)
        {
            case 'T':
                // glLineWidth(trunkWidth);
                // glBegin(GL_LINES);
                //     glVertex3f(0.0f, 0.0f, 0.0f);
                //     glVertex3f(0.0f, obj->trunk_length, 0.0f);
                // glEnd();
                // glTranslatef(0.0f,TranslateY, 0.0f);
                //
                obj->drawTrunk(obj->trunk_length, trunkWidth);
                break;
            
            case '[':
                glPushMatrix();
                trunkWidth = trunkWidth * (1 - widthReduction) ;
                break;
            
            case 'l':
                glRotatef(obj->angleZ, 1.0f, 0.0f, 1.0f);
                glRotatef(obj->angleY, 0.0f, 1.0f, 0.0f);
                break;

            case 'r':
                glRotatef(-obj->angleZ, 1.0f, 0.0f, 1.0f);
                glRotatef(-obj->angleY, 0.0f, 1.0f, 0.0f);
                break;

            case ']':
                glPopMatrix();
                trunkWidth = trunkWidth / (1 - widthReduction);
                break;

            case 'L':
                // glPointSize(pointSize);
                // glColor3f(1.000f, 0.412f, 0.706f);
                // glBegin(GL_POINTS);
                //     glVertex3f(0.0f, 0.0f, 0.0f);
                // glEnd();
                obj->drawLeaf(obj->trunk_length, trunkWidth);
                break;

            default:
                break;           
        }
        pattern++;
    }
    return 0;

}

