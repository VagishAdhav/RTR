#pragma once


typedef void (*drawTreePart)(float length, float width);

typedef struct 
{
    int depth;
    float trunk_length;
    float trunk_width;
    float angleZ;
    float angleY;
    BOOL straight;
    char *pattern;
    drawTreePart drawTrunk;
    drawTreePart drawLeaf;
}LSystemTree;

int createTree(LSystemTree **obj, float length, float width, float angleZ, float angleY, BOOL straight, drawTreePart drawTrunk, drawTreePart drawLeaf);

int expandTree(LSystemTree **obj, unsigned int maxDepth);

int displayTree(LSystemTree *obj);



