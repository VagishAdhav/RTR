
#include "Shape_library.h"
#include "GL/freeglut.h"
#include <math.h>

#define M_PI   (3.14159265358979323846264338327950288)

/**
 * @brief Draw Rectangle with smooth corners
 * 
 * @details This function plots rectangle with smooth corners
 * @note OpenGL primtive must imitiated before calling this API
 * @param pTopLeft 
 * @param pTopRight 
 * @param pBottomRight
 * @param pBottomLeft 
 * @param fSmoothFactor percentage between 0 to 1 ( e.g 0.2 for 20%)
 * 
 * @return none
 */
void drawSmoothRectangle(point pTopLeft, point pTopRight, point pBottomRight, point pBottomLeft, float fSmoothFactor)
{
	// variable declaration
	point pCurveTopLeftStart, pCurveTopLeftEnd, pCurveTopLeftControl;
	point pCurveTopRightStart, pCurveTopRightEnd, pCurveTopRightControl;
	point pCurveBottomRightStart, pCurveBottomRightEnd, pCurveBottomRightControl;
	point pCurveBottomLeftStart, pCurveBottomLeftEnd, pCurveBottomLeftControl;


	//code

	// calculate co-ordinates for curve

	float fOffsetX = ((pTopRight.cords.x - pTopLeft.cords.x)*fSmoothFactor);
	float fOffsetY = ((pTopLeft.cords.y - pBottomLeft.cords.y)*fSmoothFactor);

	// top left
	pCurveTopLeftStart = pTopLeft;
	pCurveTopLeftStart.cords.y = pTopLeft.cords.y - fOffsetY;
	pCurveTopLeftEnd = pTopLeft;
	pCurveTopLeftEnd.cords.x = pTopLeft.cords.x + fOffsetX;
	pCurveTopLeftControl = pTopLeft;

	// top right
	pCurveTopRightStart = pTopRight;
	pCurveTopRightStart.cords.x = pTopRight.cords.x - fOffsetX;
	pCurveTopRightEnd = pTopRight;
	pCurveTopRightEnd.cords.y = pTopRight.cords.y - fOffsetY;
	pCurveTopRightControl = pTopRight;

	// bottom right
	pCurveBottomRightStart = pBottomRight;
	pCurveBottomRightStart.cords.y = pBottomRight.cords.y + fOffsetY;
	pCurveBottomRightEnd = pBottomRight;
	pCurveBottomRightEnd.cords.x = pBottomRight.cords.x - fOffsetX;
	pCurveBottomRightControl = pBottomRight;


	// bottom left
	pCurveBottomLeftStart = pBottomLeft;
	pCurveBottomLeftStart.cords.x = pBottomLeft.cords.x + fOffsetX;
	pCurveBottomLeftEnd = pBottomLeft;
	pCurveBottomLeftEnd.cords.y = pBottomLeft.cords.y + fOffsetY;
	pCurveBottomLeftControl = pBottomLeft;

	// start drawing from top left -> top right -> bottom right -> bottom left

	draw2DBezierQuadratic(pCurveTopLeftStart, pCurveTopLeftEnd, pCurveTopLeftControl, 0.01);
	draw2DBezierQuadratic(pCurveTopRightStart, pCurveTopRightEnd, pCurveTopRightControl, 0.01);
	draw2DBezierQuadratic(pCurveBottomRightStart, pCurveBottomRightEnd, pCurveBottomRightControl, 0.01);
	draw2DBezierQuadratic(pCurveBottomLeftStart, pCurveBottomLeftEnd, pCurveBottomLeftControl, 0.01);

}

/**
 * @brief Plot quadratic bezier curve
 * 
 * @details This API calculates point on the curve using following linear interpolation formula for the given x and y coordinates 
 *          B(t) = (1 - t)Start Point + t(End Point)
 * 
 * @note OpenGL primtive must imitiated before calling this API
 * @param pStart Start point of curve 
 * @param pEnd  Start point of curve 
 * @param pControl Control point of the curve
 * @param fStep Step increment between t = 0 to 1
 * @return none
 */
void draw2DBezierQuadratic(point pStart, point pEnd, point pControl, float fStep)
{
	// variable declaration
	point pStartToControl, pControlToEnd, pFinal;

	//code 
	for (float t = 0; t <= 1; t+= fStep)
	{
		// calculate interpolation between pStart and PControl
		pStartToControl.cords.x = (1 - t)*pStart.cords.x + (t * pControl.cords.x);
		pStartToControl.cords.y = (1 - t)*pStart.cords.y + (t * pControl.cords.y);
		pStartToControl.colors.r = (1 - t)*pStart.colors.r + (t * pControl.colors.r);
		pStartToControl.colors.g = (1 - t)*pStart.colors.g + (t * pControl.colors.g);
		pStartToControl.colors.b = (1 - t)*pStart.colors.b + (t * pControl.colors.b);

		// calculate interpolation between Control and PEnd
		pControlToEnd.cords.x = (1 - t)*pControl.cords.x + (t * pEnd.cords.x);
		pControlToEnd.cords.y = (1 - t)*pControl.cords.y + (t * pEnd.cords.y);
		pControlToEnd.colors.r = (1 - t)*pControl.colors.r + (t * pEnd.colors.r);
		pControlToEnd.colors.g = (1 - t)*pControl.colors.g + (t * pEnd.colors.g);
		pControlToEnd.colors.b = (1 - t)*pControl.colors.b + (t * pEnd.colors.b);

		// calculate interpolation between above two interpolated points

		pFinal.cords.x = (1 - t)*pStartToControl.cords.x + (t * pControlToEnd.cords.x);
		pFinal.cords.y = (1 - t)*pStartToControl.cords.y + (t * pControlToEnd.cords.y);
		pFinal.colors.r = (1 - t)*pStartToControl.colors.r + (t * pControlToEnd.colors.r);
		pFinal.colors.g = (1 - t)*pStartToControl.colors.g + (t * pControlToEnd.colors.g);
		pFinal.colors.b = (1 - t)*pStartToControl.colors.b + (t * pControlToEnd.colors.b);

		// plot the final point

		glColor3f(pFinal.colors.r, pFinal.colors.g, pFinal.colors.b);
		glVertex3f(pFinal.cords.x, pFinal.cords.y, 0);
	}
}

/**
 * @brief Plots the ellipse over given range
 * @details This function implements following equation to plot ellipse on x,y plane
 * 			x = XOrigin + a cos(Angle)
 *  		y = YOrigin + b sin(Angle)
 * 			Where Angle varies from 0 to 2*PI
 * 			a = Radius along X 
 * 			b = Radius along Y
 * 			If a=b then this function plots the circle.
 * @note OpenGL primtive must imitiated before calling this API
 * @param faRadius Radius along X and Y Axis
 * @param pOrigin Coordinates of Origin
 * @param fStep Step increment to plot. Smaller the number smoother the plot
 * @param fStart Start radian of the ellipse
 * @param fEnd End radian of the ellipse
 */
void drawSemiEllipse(float faRadius[2], point pOrigin, float fStep, float fStart, float fEnd)
{
    for (float fAngle = fStart; fAngle <= fEnd; fAngle += fStep)
    {
        // triangle top
        glColor3f(pOrigin.colors.r, pOrigin.colors.g, pOrigin.colors.b);
        glVertex3f(pOrigin.cords.x, pOrigin.cords.y, 0.0f);

        float fX = pOrigin.cords.x + (faRadius[0] * cos(fAngle));
        float fY = pOrigin.cords.y + (faRadius[1] * sin(fAngle));

        glColor3f(pOrigin.colors.r, pOrigin.colors.g, pOrigin.colors.b);
        glVertex3f(fX, fY, 0.0f);
        fX = pOrigin.cords.x + (faRadius[0] * cos(fAngle + fStep));
        fY = pOrigin.cords.y + (faRadius[1] * sin(fAngle + fStep));

        glColor3f(pOrigin.colors.r, pOrigin.colors.g, pOrigin.colors.b);
        glVertex3f(fX, fY, 0.0f);
    }
}

/**
 * @brief Plots the sine wave with given parameters
 * 
 * @details This function implements below sine wave formula for  2D plane 
 * 			y=Asin(B(x−C))+D
 * 			A - Amplitude
 * 			B - Frequency ( Number of Cycles over a given period)
 * 			C - Phase shift
 * 			D - Y Offset
 * 		Formula for Frequncy over T is B = ((2*PI)*Num of Cycles)/T.
 * 		In our case it will be fFrequency = (2*M_PI*fNumCycles)/(fXEnd - fXStart)
 * 		
 * @note OpenGL primtive and color must imitiated before calling this API
 * @param fXStart X coordinate for start of the plot area
 * @param fXEnd X coordinate for end of the plot area
 * @param fCycles Number of Cycles in the plot area
 * @param fPhaseShift Phase shift along X axis
 * @param fAmplitude Amlitude of the wave
 * @param fYMid Y Coordinate of the wave
 */
void drawSineWave(float fXStart, float fXEnd, float fNumCycles, float fPhaseShift, float fAmplitude, float fYMid)
{
	float fFrequency = (2*M_PI*fNumCycles)/(fXEnd - fXStart);

	for (float fX = fXStart; fX <= fXEnd; fX += 0.01)
	{
		float fY =  fAmplitude * (sin(fFrequency * (fX - fPhaseShift))) + fYMid;
		glVertex3f(fX, fY, 0);
	}
}