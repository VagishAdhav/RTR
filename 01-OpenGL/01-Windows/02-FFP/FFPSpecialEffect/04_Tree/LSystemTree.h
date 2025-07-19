#pragma once


typedef void (*drawTree)(float length, float width);

typedef struct 
{
    int depth;
    float trunk_length;
    float trunk_width;
    float angleZ;
    float angleY;
    BOOL straight;
    char *pattern;
    drawTree drawTrunk;
    drawTree drawLeaf;
}LSystemTree;

int createTree(LSystemTree **obj, float length, float width, float angleZ, float angleY, BOOL straight, drawTree drawTrunk, drawTree drawLeaf);

int expandTree(LSystemTree **obj, unsigned int maxDepth);

int displayTree(LSystemTree *obj);



