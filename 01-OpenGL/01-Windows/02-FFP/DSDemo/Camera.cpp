
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES (1)
#include <math.h>
#include "Camera.h"

#define DEG_TO_RAD(deg) ((deg) * M_PI / 180.0)

#define MS_TO_SAMPLES(ms) (((double)ms)/(double)FRAME_RATE_MS)

#define MS_TO_SPEED(ms) ((double)(FRAME_PER_SECONDS) / MS_TO_SAMPLES(ms))


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

        current.centerY = current.eyeY + (deltaY * cos(angle_rad) - deltaZ * sin(angle_rad));
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
        current.centerY = current.eyeY + (deltaX * sin(angle_rad) + deltaY * cos(angle_rad));
        CamPos->push_back(current);
    }
}

void cameraMove(std::vector<CameraPos> *CamPos, unsigned int direction, float distance, float speed, BOOL fixCenter)
{
    for (double step = 0.0f; step <= distance; step += speed)
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

        // TODO: This is wrong, we need a vector calculus here
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

        
        if (fixCenter == FALSE)
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

void cameraFix(std::vector<CameraPos> *pos, unsigned int time)
{
    CameraPos tempPos = pos->back();
    for (unsigned int index = 0; index < time; index++)
    {
        pos->push_back(tempPos);
    }
}

void debugCamera(std::vector<CameraPos> *pos, FILE* gpFile)
{
    for (unsigned int index = 0; index < pos->size(); index++)
    {
        fprintf(gpFile, "Index : %d, eyeX:%f, eyeY:%f, eyeZ:%f\n", index, pos->at(index).eyeX, pos->at(index).eyeY, pos->at(index).eyeZ);
    }
}

// setup scene one camera
void setScene1Camera(std::vector<CameraPos> *pos)
{
    

    // total duration of first frame is 1 minute (60,000ms)
    //setup camera position
    cameraSet(pos, 0.0f, 35.0f, 50.0f, 0.0f, 35.0f, -100.0f, UP_Y);

    // fix at starting position for 2000ms
    cameraFix(pos, MS_TO_SPEED(2000.0f));

    //move forward 5000ms (//elapsed 7000)
    cameraMove(pos, (MOVE_FORWARD), 30.0f, MS_TO_SPEED(5000.0f), TRUE);

    // rotate couner clockwise and show the logo 5 seconds (//elapsed 12000)
    cameraRotateY(pos, -50.0f, MS_TO_SPEED(5000.0f));
    // rotate back to ceneter (//elapsed 17000)
    cameraRotateY(pos, 50.0f, MS_TO_SPEED(5000.0f));
    // show the clock (//elapsed 25000)
    cameraRotateY(pos, 50.0f, MS_TO_SPEED(4000.0f));
    cameraRotateY(pos, -50.0f, MS_TO_SPEED(4000.0f));
    // move towards table (//elapsed 33000)
    cameraMove(pos, (MOVE_FORWARD), 60.0f, MS_TO_SPEED(8000.0f), TRUE);
    // rotate towards montitor // elapsed 36000
    cameraRotateY(pos, 10.0f, MS_TO_SPEED(3000.0f));
    // wait for 2 seconds here  // elapsed 38000
    cameraFix(pos, MS_TO_SPEED(2000.0f));
    // back to table center // // elapsed 41000
    cameraRotateY(pos, -10.0f, MS_TO_SPEED(3000.0f));

   // rotate towards book // elapsed 45000
    cameraRotateY(pos, -35.0f, MS_TO_SPEED(3000.0f)); 

   // move forward // elapsed 49000
    cameraMove(pos, (MOVE_FORWARD), 10.0f, MS_TO_SPEED(4000.0f), TRUE);
    // rotate down towards book //elapsed 54000
    cameraRotateX(pos, -35.0f, MS_TO_SPEED(5000.0f));
    // rotate down towards book //elapsed 60000
    cameraMove(pos, (MOVE_FORWARD | MOVE_LEFT), 5.0f, MS_TO_SPEED(5900.0f), TRUE);
}

// setup scene one camera
void setScene2Camera(std::vector<CameraPos> *pos, float speed)
{

    float controlPoints[4][3] = {
        {0.0f, 10.0f, 40.0f},
        {-30.0f, 10.0f, 20.0f},
        {30.0f, 10.0f, -15.0f},
        {0.0f, 25.0f, -40.0f},
        };


    cameraSet(pos, 0.0f, 50.0f, 70.0f, 0.0f, 5.0f, -100.0f, UP_Y);
    cameraFix(pos, 10);
    // rotate down
    cameraRotateX(pos, -20.0f, speed);
    // move downwards
    cameraMove(pos, (MOVE_FORWARD | MOVE_DOWN), 30.0f, speed, TRUE);
    cameraRotateX(pos, 18.0f, speed+0.1);
    // fix for while
    cameraFix(pos, 50);

    cameraMove(pos, (MOVE_LEFT), 2.0f, speed, TRUE);
    // bazier
    cameraCurve(pos, controlPoints, 0.0005f, TRUE);

    cameraRotateY(pos, 359.0f, speed + 0.2f);

    cameraRotateX(pos, 10.0f, speed + 0.2f);
}

void setScene3Camera(std::vector<CameraPos> *pos, float speed)
{
    cameraSet(pos, 0.0f, 0.0f, 10.0f, 0.0f, 0.0f, -100.0f, UP_Y);
    cameraFix(pos, 2000.0f);
}

void setScene4Camera(std::vector<CameraPos> *pos, float speed)
{
    // create camera object
    //cameraSet(pos, 0.0f, 1.0f, 5.0f, 0.0f, 0.0f, 0.0f, UP_Y);
    cameraSet(pos, 0.0f, 10.0f, 30.0f, 0.0f, 0.0f, 0.0f, UP_Y);
    // move forward and down
    cameraMove(pos, (MOVE_DOWN | MOVE_FORWARD), 10.0f, 0.09f, TRUE);
    cameraMove(pos, (MOVE_FORWARD), 3.0f, 0.09f, TRUE);
    // now revolve around Y
    cameraRevolvAroundY(pos, 180.0f, 0.1f);
    //cameraRotateX(pos, 180.0f, 0.1f);
    //cameraCurve(pos, controlPointsScene4, 0.001f, FALSE);
}

