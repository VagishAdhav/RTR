
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES (1)
#include <math.h>
#include "Camera.h"

#define DEG_TO_RAD(deg) ((deg) * M_PI / 180.0)

void cameraSet(std::vector<CameraPos> *pos,
    float eyeX,
    float eyeY,
    float eyeZ,
    float centerX,
    float centerY,
    float centerZ,
    CameraUp up)

{
    CameraPos tempPos;
    tempPos.eyeX = eyeX;
    tempPos.eyeY = eyeY;
    tempPos.eyeZ = eyeZ;
    tempPos.centerX = centerX;
    tempPos.centerY = centerY;
    tempPos.centerZ = centerZ;
    tempPos.upX = (float)(up == UP_X);
    tempPos.upY = (float)(up == UP_Y);
    tempPos.upZ = (float)(up == UP_Z);
    pos->push_back(tempPos);
}

void cameraRevolvAroundX(std::vector<CameraPos> *CamPos, float angle, float speed)
{
    float dir = (angle > 0.0f) ? 1.0f : -1.0f;
    // find the radius
    for (float temp_angle = 0.0f; temp_angle <= fabs(angle); temp_angle += speed)
    {
        double angle_rad = DEG_TO_RAD(dir * speed);
        CameraPos current = CamPos->back();
        // vector from eye to center
        float deltaY= current.eyeY - current.centerY;
        float deltaZ = current.eyeZ - current.centerZ;

        current.eyeY = current.centerX + (deltaY * cos(angle_rad) - deltaZ * sin(angle_rad));
        current.eyeZ = current.centerZ + (deltaY * sin(angle_rad) + deltaZ * cos(angle_rad));
        CamPos->push_back(current);
    }
}

void cameraRevolvAroundY(std::vector<CameraPos> *CamPos, float angle, float speed)
{
    float dir = (angle >= 0.0f) ? 1.0f : -1.0f;
    // find the radius
    for (float temp_angle = 0.0f; temp_angle <= fabs(angle); temp_angle += speed)
    {
        double angle_rad = DEG_TO_RAD(dir * speed);
        CameraPos current = CamPos->back();
        // vector from eye to center
        float deltaX = current.eyeX - current.centerX;
        float deltaZ = current.eyeZ - current.centerZ;

        current.eyeX = current.centerX + (deltaX * cos(angle_rad) - deltaZ * sin(angle_rad));
        current.eyeZ = current.centerZ + (deltaX * sin(angle_rad) + deltaZ * cos(angle_rad));
        CamPos->push_back(current);
    }
}

void cameraRevolvAroundZ(std::vector<CameraPos> *CamPos, float angle, float speed)
{
    float dir = (angle > 0.0f) ? 1.0f : -1.0f;
    // find the radius
    for (float temp_angle = 0.0f; temp_angle <= fabs(angle); temp_angle += speed)
    {
        double angle_rad = DEG_TO_RAD(dir * speed);
        CameraPos current = CamPos->back();
        // find the radius
        float deltaX = current.eyeX - current.centerX;
        float deltaY = current.eyeY - current.centerY;

        current.eyeX = current.centerX + (deltaX * cos(angle_rad) - deltaY * sin(angle_rad));
        current.eyeZ = current.centerZ + (deltaX * sin(angle_rad) + deltaY * cos(angle_rad));
        CamPos->push_back(current);
    }
}

void cameraRotateX(std::vector<CameraPos> *CamPos, float angle, float speed)
{
    float dir = (angle > 0.0f) ? 1.0f : -1.0f;
    // find the radius
    for (float temp_angle = 0.0f; temp_angle <= fabs(angle); temp_angle += speed)
    {
        double angle_rad = DEG_TO_RAD(dir * speed);
        CameraPos current = CamPos->back();
        // vector from eye to center
        float deltaY = current.centerY - current.eyeY;
        float deltaZ = current.centerZ - current.eyeZ;

        current.centerY = current.eyeX + (deltaY * cos(angle_rad) - deltaZ * sin(angle_rad));
        current.centerZ = current.eyeZ + (deltaY * sin(angle_rad) + deltaZ * cos(angle_rad));
        CamPos->push_back(current);
    }
}

void cameraRotateY(std::vector<CameraPos> *CamPos, float angle, float speed)
{
    float dir = (angle > 0.0f) ? 1.0f : -1.0f;
    for (float temp_angle = 0.0f; temp_angle <= fabs(angle); temp_angle += speed)
    {
        double angle_rad = DEG_TO_RAD(dir * speed);
        CameraPos current = CamPos->back();
        // vector from eye to center
        float deltaX = current.centerX - current.eyeX;
        float deltaZ = current.centerZ - current.eyeZ;

        current.centerX = current.eyeX + (deltaX * cos(angle_rad) - deltaZ * sin(angle_rad));
        current.centerZ = current.eyeZ + (deltaX * sin(angle_rad) + deltaZ * cos(angle_rad));
        CamPos->push_back(current);
    }
}

void cameraRotateZ(std::vector<CameraPos> *CamPos, float angle, float speed)
{
    float dir = (angle > 0.0f) ? 1.0f : -1.0f;
    for (float temp_angle = 0.0f; temp_angle <= fabs(angle); temp_angle += speed)
    {
        double angle_rad = DEG_TO_RAD(dir * speed);
        CameraPos current = CamPos->back();
        // vector from eye to center
        float deltaX = current.centerX - current.eyeX;
        float deltaY = current.centerY - current.eyeY;

        current.centerX = current.eyeX + (deltaX * cos(angle_rad) - deltaY * sin(angle_rad));
        current.centerY = current.eyeZ + (deltaX * sin(angle_rad) + deltaY * cos(angle_rad));
        CamPos->push_back(current);
    }
}

void cameraMove(std::vector<CameraPos> *CamPos, unsigned int direction, float distance, float speed, BOOL fixCenter)
{
    for (float step = 0.0f; step <= distance; step += speed)
    {
        CameraPos current = CamPos->back();

        if (direction & (MOVE_FORWARD))
        {
            current.eyeZ -= speed;
        }
        else if (direction & (MOVE_BACKWARD))
        {
            current.eyeZ += speed;
        }

        if (direction & (MOVE_LEFT))
        {
            current.eyeX -= speed;
        }
        else if (direction & (MOVE_RIGHT))
        {
            current.eyeX += speed;
        }

        if (direction & (MOVE_DOWN))
        {
            current.eyeY -= speed;
        }
        else if (direction & (MOVE_UP))
        {
            current.eyeY += speed;
        }

        if (fixCenter == FALSE)
        {
            if (direction & (MOVE_FORWARD))
            {
                current.centerZ =  current.eyeZ;
            }
            else if (direction & (MOVE_BACKWARD))
            {
                current.centerZ = current.eyeZ;
            }

            if (direction & (MOVE_LEFT))
            {
                current.centerX = current.eyeX;
            }
            else if (direction & (MOVE_RIGHT))
            {
                current.centerX = current.eyeX;
            }

            if (direction & (MOVE_DOWN))
            {
                current.centerY = current.eyeY;
            }
            else if (direction & (MOVE_UP))
            {
                current.centerY =  current.eyeY;
            }
        }
        CamPos->push_back(current);
    }
}


void cameraCurve(std::vector<CameraPos> *pos, float controlPoints[4][3], float speed, BOOL fixCenter)
{

    for (float t = 0.0f; t <= 1.0f; t += speed)
    {
        CameraPos tempPos = pos->back();
        tempPos.eyeX = pow((1-t), 3) * controlPoints[0][0] +
                    3 * pow((1-t), 2) * t * controlPoints[1][0] + 
                    3 * (1-t) * pow(t, 2) * controlPoints[2][0] +
                    pow(t, 3) * controlPoints[3][0];

        tempPos.eyeY = pow((1-t), 3) * controlPoints[0][1] +
                    3 * pow((1-t), 2) * t * controlPoints[1][1] + 
                    3 * (1-t) * pow(t, 2) * controlPoints[2][1] +
                    pow(t, 3) * controlPoints[3][1];

        tempPos.eyeZ = pow((1-t), 3) * controlPoints[0][2] +
                    3 * pow((1-t), 2) * t * controlPoints[1][2] + 
                    3 * (1-t) * pow(t, 2) * controlPoints[2][2] +
                    pow(t, 3) * controlPoints[3][2];

        
        if (fixCenter == false)
        {
            float t1 = t + speed;
            tempPos.centerX = pow((1-t1), 3) * controlPoints[0][0] +
                        3 * pow((1-t), 2) * t1 * controlPoints[1][0] + 
                        3 * (1-t1) * pow(t1, 2) * controlPoints[2][0] +
                        pow(t1, 3) * controlPoints[3][0];

            tempPos.centerY = pow((1-t1), 3) * controlPoints[0][1] +
                        3 * pow((1-t1), 2) * t * controlPoints[1][1] + 
                        3 * (1-t1) * pow(t1, 2) * controlPoints[2][1] +
                        pow(t1, 3) * controlPoints[3][1];

            tempPos.centerZ = pow((1-t1), 3) * controlPoints[0][2] +
                        3 * pow((1-t1), 2) * t1 * controlPoints[1][2] + 
                        3 * (1-t1) * pow(t1, 2) * controlPoints[2][2] +
                        pow(t1, 3) * controlPoints[3][2];   
        }
        pos->push_back(tempPos);
    }
}