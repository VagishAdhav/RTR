// Header files
#include "GL/freeglut.h"
#include "math.h"


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

// constant macros

#define M_PI   (3.14159265358979323846264338327950288)

// global variabled
extern unsigned int guiTicks;


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
	// function declaration
	void draw2DBezierQuadratic(point pStart, point pEnd, point pControl, float fStep);

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
		float fY =  fAmplitude * (sin(fFrequency * (fX - fPhaseShift))) + fYMid/2.0f;
		glVertex3f(fX, fY, 0);
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

void drawOscilloScope(float fCenterX, float fCenterY, float fWidth, float fHeight)
{
	// function declaration 
	void drawSmoothRectangle(point pTopLeft, point pTopRight, point pBottomRight, point pBottomLeft, float fSmoothFactor);

	// variable declaration
	point pTopLeft, pTopRight, pBottomRight, pBottomLeft;
	color cOuter = {(float)0xED/255.0f, (float)0xE8/255.0f, (float)0xD0/255.0f};  // beige color
	color cInner = {(float)0xD0/255.0f, (float)0xD0/255.0f, (float)0xD0/255.0f};  // light grey color
	color cScreenColor = {0.0f, 0.0f, 0.0f}; //black color

	// code
	// draw outer box
	pTopLeft.cords.x =  fCenterX - (fWidth/2.0f);
	pTopLeft.cords.y =  fCenterY + (fHeight/2.0f);
	pTopLeft.colors = cOuter;

	pTopRight.cords.x =  fCenterX + (fWidth/2.0f);
	pTopRight.cords.y =  fCenterY + (fHeight/2.0f);
	pTopRight.colors = cOuter;

	pBottomRight.cords.x =  fCenterX + (fWidth/2.0f);
	pBottomRight.cords.y =  fCenterY - (fHeight/2.0f);
	pBottomRight.colors = cOuter;
	
	pBottomLeft.cords.x =  fCenterX - (fWidth/2.0f);
	pBottomLeft.cords.y =  fCenterY - (fHeight/2.0f);
	pBottomLeft.colors = cOuter;

	glBegin(GL_POLYGON);
	drawSmoothRectangle(pTopLeft, pTopRight, pBottomRight, pBottomLeft, 0.1);
	glEnd();

	// draw Inner box
	float fReduction = 0.05 * fHeight; 

	pTopLeft.cords.x =  pTopLeft.cords.x + fReduction;
	pTopLeft.cords.y =  pTopLeft.cords.y - fReduction;
	pTopLeft.colors = cInner;

	pTopRight.cords.x =  pTopRight.cords.x - fReduction;
	pTopRight.cords.y =  pTopRight.cords.y - fReduction;
	pTopRight.colors = cInner;

	pBottomRight.cords.x =  pBottomRight.cords.x - fReduction;
	pBottomRight.cords.y =  pBottomRight.cords.y + fReduction;
	pBottomRight.colors = cInner;
	
	pBottomLeft.cords.x =  pBottomLeft.cords.x + fReduction;
	pBottomLeft.cords.y =  pBottomLeft.cords.y + fReduction;
	pBottomLeft.colors = cInner;

	glBegin(GL_POLYGON);
	drawSmoothRectangle(pTopLeft, pTopRight, pBottomRight, pBottomLeft, 0.1);
	glEnd();

	// draw screen 
	float fHeightReduction = (fHeight/2.0f) * 0.7f;

	pTopLeft.cords.x =  pTopLeft.cords.x + fReduction;
	pTopLeft.cords.y =  pTopLeft.cords.y - fReduction;
	pTopLeft.colors = cScreenColor;

	pTopRight.cords.x =  pTopRight.cords.x - fReduction;
	pTopRight.cords.y =  pTopRight.cords.y - fReduction;
	pTopRight.colors = cScreenColor;

	pBottomRight.cords.x =  pBottomRight.cords.x - fReduction;
	pBottomRight.cords.y =  pBottomRight.cords.y + fHeightReduction;
	pBottomRight.colors = cScreenColor;
	
	pBottomLeft.cords.x =  pBottomLeft.cords.x + fReduction;
	pBottomLeft.cords.y =  pBottomLeft.cords.y + fHeightReduction;
	pBottomLeft.colors = cScreenColor;

	glBegin(GL_POLYGON);
	drawSmoothRectangle(pTopLeft, pTopRight, pBottomRight, pBottomLeft, 0.01);
	glEnd();

	// draw grids within screen
	int iRows = 5;
	int iCols = 10;


	// draw coloumns
	float fSpace = (pTopRight.cords.x - pTopLeft.cords.x)/iCols;
	
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.8f, 0.0f);
	for (float fX = pTopLeft.cords.x + fSpace; fX < pTopRight.cords.x; fX += fSpace)
	{
		for (float fY = pTopLeft.cords.y - 1; fY > pBottomLeft.cords.y; fY -= 1)
		{
			glVertex3f(fX, fY, 0);
		}
	}
	glEnd();

	// draw rows
	fSpace = (pTopLeft.cords.y - pBottomLeft.cords.y)/iRows;
	
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.8f, 0.0f);
	for (float fY = pTopLeft.cords.y - fSpace; fY > pBottomLeft.cords.y; fY -= fSpace)
	{
		for (float fX = pTopLeft.cords.x + 1; fX < pTopRight.cords.x; fX += 1)
		{
			glVertex3f(fX, fY, 0);
		}
	}
	glEnd();

	// draw Sine Wave
	// plot a live wave by incrementing right x coordinate
	float fRightX = (pTopLeft.cords.x + (float)guiTicks - 65);
	float fPhaseShift = 0;
	float fNumWaves = 0;

	// check if whole wave is plotted then start phase shift
	if (fRightX > pTopRight.cords.x)
	{
		fRightX = pTopRight.cords.x;
		fPhaseShift = guiTicks;
	}

	// calculate number of waves to plot in the given area
	fSpace = (pTopRight.cords.x - pTopLeft.cords.x)/iCols;
	fNumWaves = ((fRightX - pTopLeft.cords.x)  * 0.5f / fSpace);

	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);

	drawSineWave(pTopLeft.cords.x, fRightX, fNumWaves, fPhaseShift, fHeight*0.2, (pTopLeft.cords.y -  pBottomLeft.cords.y)/2.0f);
	glEnd();


	// draw first connector
	point pOrigin;
	color cConnOuter = {(float)0xFF/255.0f, (float)0xDF/255.0f, (float)0x00/255.0f};  // golden
	float faRadius[2] = {fWidth*0.06f, fWidth*0.06f};

	pOrigin.cords.x = pBottomLeft.cords.x + fWidth * 0.05;
	pOrigin.cords.y = pBottomLeft.cords.y - fHeight * 0.2;
	pOrigin.colors = cConnOuter;

	glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);
	glEnd();

	pOrigin.colors = cScreenColor;
	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];

	glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);
	glEnd();

	pOrigin.colors = cConnOuter;
	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];
	glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);
	glEnd();

	pOrigin.colors = cOuter;
	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];
	glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);
	glEnd();

	pOrigin.colors = cScreenColor;
	faRadius[0] = 0.3f * faRadius[0];
	faRadius[1] = 0.3f * faRadius[1];
	glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);
	glEnd();

	// draw second connector

	faRadius[0] = fWidth*0.06f;
	faRadius[1] = fWidth*0.06f;
	pOrigin.cords.x = pOrigin.cords.x  + fWidth * 0.15;

	pOrigin.colors = cConnOuter;

	glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);
	glEnd();

	pOrigin.colors = cScreenColor;
	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];

	glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);
	glEnd();

	pOrigin.colors = cConnOuter;
	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];
	glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);
	glEnd();

	pOrigin.colors = cOuter;
	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];
	glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);
	glEnd();

	pOrigin.colors = cScreenColor;
	faRadius[0] = 0.3f * faRadius[0];
	faRadius[1] = 0.3f * faRadius[1];
	glBegin(GL_TRIANGLES);
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);
	glEnd();

	// draw knobs
	color cKnobBaseColor = {(float)0x80/255.0f, (float)0x80/255.0f, (float)0x80/255.0f};  // dark grey
	glBegin(GL_TRIANGLES);

	// first knob
	pOrigin.colors = cKnobBaseColor;
	faRadius[0] = fWidth*0.07f;
	faRadius[1] = fWidth*0.07f;
	pOrigin.cords.x = pOrigin.cords.x  + fWidth * 0.20;
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);

	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];
	pOrigin.colors = cScreenColor;
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);

	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];
	pOrigin.colors = cKnobBaseColor;
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);
	
	// second knob
	pOrigin.colors = cKnobBaseColor;
	faRadius[0] = fWidth*0.04f;
	faRadius[1] = fWidth*0.04f;
	pOrigin.cords.x = pOrigin.cords.x  + fWidth * 0.13;
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);

	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];
	pOrigin.colors = cScreenColor;
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);


	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];
	pOrigin.colors = cKnobBaseColor;
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);


	// third knob
	pOrigin.colors = cKnobBaseColor;
	faRadius[0] = fWidth*0.07f;
	faRadius[1] = fWidth*0.07f;
	pOrigin.cords.x = pOrigin.cords.x  + fWidth * 0.17;
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);


	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];
	pOrigin.colors = cScreenColor;
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);


	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];
	pOrigin.colors = cKnobBaseColor;
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);


	// fourth knob
	pOrigin.colors = cKnobBaseColor;
	faRadius[0] = fWidth*0.04f;
	faRadius[1] = fWidth*0.04f;
	pOrigin.cords.x = pOrigin.cords.x  + fWidth * 0.13;
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);


	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];
	pOrigin.colors = cScreenColor;
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);


	faRadius[0] = 0.8f * faRadius[0];
	faRadius[1] = 0.8f * faRadius[1];
	pOrigin.colors = cKnobBaseColor;
	drawSemiEllipse(faRadius, pOrigin, 0.1, 0, 2*M_PI);
	
	glEnd();

}