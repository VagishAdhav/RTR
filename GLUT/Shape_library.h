
#pragma once

// structure declarations

typedef struct
{
	float x;
	float y;
	float z;
}cord;

typedef struct
{
	float r;
	float g;
	float b;
}color;

typedef struct
{
	cord cords;
	color colors;
}point;


#define MY_PI 3.14159265358979323846264338327950288


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
void drawSemiEllipse(float faRadius[2], point pOrigin, float fStep, float fStart, float fEnd);

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
void draw2DBezierQuadratic(point pStart, point pEnd, point pControl, float fStep);

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
void drawSmoothRectangle(point pTopLeft, point pTopRight, point pBottomRight, point pBottomLeft, float fSmoothFactor);

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
void drawSineWave(float fXStart, float fXEnd, float fNumCycles, float fPhaseShift, float fAmplitude, float fYMid);