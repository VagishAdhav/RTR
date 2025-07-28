#pragma once
#include <vector>


typedef struct 
{
    float eyeX;
    float eyeY;
    float eyeZ;
    float centerX;
    float centerY;
    float centerZ;  
    float upX;
    float upY;
    float upZ;   
}CameraPos;

typedef enum
{
    MOVE_FORWARD = 0x1,
    MOVE_BACKWARD = 0x2,
    MOVE_UP = 0x4,
    MOVE_DOWN = 0x8,
    MOVE_LEFT = 0x10,
    MOVE_RIGHT = 0x20,
}CameraDir;

typedef enum
{
    UP_X,
    UP_Y,
    UP_Z
}CameraUp;

void cameraSet(std::vector<CameraPos> *pos,
    float eyeX,
    float eyeY,
    float eyeZ,
    float centerX,
    float centerY,
    float centerZ,
    CameraUp up);

void cameraRevolvAroundX(std::vector<CameraPos> *pos, float angle, float speed);
void cameraRevolvAroundY(std::vector<CameraPos> *pos, float angle, float speed);
void cameraRevolvAroundZ(std::vector<CameraPos> *pos, float angle, float speed);

void cameraRotateX(std::vector<CameraPos> *pos, float angle, float speed);
void cameraRotateY(std::vector<CameraPos> *pos, float angle, float speed);
void cameraRotateZ(std::vector<CameraPos> *pos, float angle, float speed);

void cameraMove(std::vector<CameraPos> *pos, unsigned int direction, float distance, float speed, BOOL fixCenter);

void cameraCurve(std::vector<CameraPos> *pos, float controlPoints[4][3], float speed, BOOL fixCenter);

void cameraFix(std::vector<CameraPos> *pos, unsigned int time);

void setScene1Camera(std::vector<CameraPos> *pos, float speed);

void setScene2Camera(std::vector<CameraPos> *pos, float speed);

void setScene3Camera(std::vector<CameraPos> *pos, float speed);