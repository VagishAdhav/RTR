#pragma once


typedef struct 
{
    int depth;
    float trunk_length;
    float trunk_width;
    float angleZ;
    float angleY;
    char *pattern;
}LSystemTree;

int expandTree(LSystemTree **obj, float length, float width, float angleZ, float angleY,  BOOL straight);

int displayTree(LSystemTree *obj);



