// Header files
#include "GL/freeglut.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


//global macros
#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (600)

// structure declarations
#pragma pack(1)
// bitmap header
typedef struct BMHdr {
    char magic[2];
    uint32_t fileSize;
    uint32_t reserved;
    uint32_t startOffset;
}BMHdr_t;

typedef struct DIBHdr {
    uint32_t hdrSize;
    uint32_t imgWidth;
    uint32_t imgHeight;
    uint16_t numColorPanes;
    uint16_t bitPerPixel;
    uint32_t compressionMethod; // we support no compression
    uint32_t imgSize;
    uint32_t hResolution;
    uint32_t vResolution;
    uint32_t numColors; // should be zero on windows
    uint32_t impColors; // should be zero on windows
}DIBHdr_t;

#pragma pack()

typedef struct imgInfo{
    uint32_t imgWidth;
    uint32_t imgHeight;
    uint16_t bytesPerPixel;
    uint8_t *pRawData;
}imgInfo_t;



// Global variable declarations 
BOOL bFullScreen = FALSE; 
GLfloat fRange = 100.0f; 
imgInfo_t gImageInfo;

// Entry-point function 
int main(int argc, char* argv[])
{
	// variable declaration
    BMHdr_t BitmapHeader;
    DIBHdr_t DIBHeader;

	// local function declarations 
	int initialize(void);
	void resize(int, int); 
	void display(void); 
	void keyboard(unsigned char, int, int); 
	void mouse(int, int, int, int); 
	void uninitialize(void); 

	// Code 

	if (argc != 2) {
        printf("Please provide the bitmap image file name as command line argument\n");
        return 0;
    }

	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); 
	glutInitWindowPosition(100, 100); 
	glutCreateWindow("Bitmap decoder");; 

	
	initialize(); 
	
	
	glutReshapeFunc(resize); 
	glutDisplayFunc(display); 
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse); 
	glutCloseFunc(uninitialize); 


	//load the bitmap file

    FILE *fp = fopen(argv[1], "rb");

    // read bitmap header
    fread(&BitmapHeader, sizeof(BMHdr_t), 1, fp);

    if ((BitmapHeader.magic[0] != 'B') || (BitmapHeader.magic[1] != 'M'))
	{
        printf("Invalid image. exiting ...\n");
        return 0;
    }

    // read DIB header
    fread(&DIBHeader, sizeof(DIBHdr_t), 1, fp);
    if (DIBHeader.compressionMethod != 0)
	{
        printf("Invalid compression, please provide uncompressed image. exiting ...\n");
        return 0;
    }

    // store width, height and bits per pixel for future use
    gImageInfo.imgWidth = DIBHeader.imgWidth;
    gImageInfo.imgHeight = DIBHeader.imgHeight;
    gImageInfo.bytesPerPixel = DIBHeader.bitPerPixel/8;

    // allocate memory to copy raw data
    gImageInfo.pRawData = (uint8_t *)calloc(sizeof(uint8_t), (gImageInfo.imgWidth * gImageInfo.imgHeight * gImageInfo.bytesPerPixel));

    if (!gImageInfo.pRawData)
	{
        printf("Not enough memory. Image too large. exiting ...\n");
        return 0;
    }

    // read raw image data
    fseek(fp, BitmapHeader.startOffset, SEEK_SET);
    fread(gImageInfo.pRawData, 1, (gImageInfo.imgWidth * gImageInfo.imgHeight * gImageInfo.bytesPerPixel), fp);

    // printf image info 
    printf("Image Width : %d, Image Height : %d, Bytes Per Pixel : %d\n", gImageInfo.imgWidth, gImageInfo.imgHeight, gImageInfo.bytesPerPixel);

    // close the file 
    fclose(fp);

	glutMainLoop(); 



	return (0); 
}


int initialize(void) 
{
	// code 
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	return (0); 
}


void resize(int iWidth, int iHeight)
{
	GLfloat aspectRatio; 

	if(iHeight == 0)
		iHeight = 1; 
	glViewport(0, 0, (GLsizei)iWidth, (GLsizei)iHeight); 

    aspectRatio = (GLfloat)iWidth / (GLfloat)iHeight; 

    // Reset coordinate system 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    if(iWidth <= iHeight)
        glOrtho(-fRange, fRange, -fRange / aspectRatio, fRange / aspectRatio, 1.0f, -1.0f); 
    else 
        glOrtho(-fRange * aspectRatio, fRange * aspectRatio, -fRange, fRange, 1.0f, -1.0f); 

    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
}

void display(void)
{
	// function declaration
	void displayBitmapImage(void);

	// code 
	glClear(GL_COLOR_BUFFER_BIT); 
	displayBitmapImage();

	glutSwapBuffers(); 
}


void keyboard(unsigned char key, int x, int y)
{
	// code 
	switch (key)
	{
	case 27: 
		glutLeaveMainLoop(); 
		break; 

	case 'F': 
	case 'f': 
		if (bFullScreen == FALSE)
		{
			glutFullScreen(); 
			bFullScreen = TRUE; 
		}
		else
		{
			glutLeaveFullScreen(); 
			bFullScreen = FALSE; 
		}
		break; 
	default: 
		break; 
	}
}


void mouse(int button, int state, int x, int y)
{
	// code 
	switch (button)
	{
	case GLUT_LEFT_BUTTON: 
		glutLeaveMainLoop(); 
		break; 
	default: 
		break; 
	}
}


void uninitialize(void)
{
	// code 
}

void displayBitmapImage(void)
{
	// fit the image in -50 to 50
	printf("displayBitmapImage\n");
	GLfloat fWidthIncrement = 100.0f /gImageInfo.imgWidth;
	GLfloat fHeightIncrement = 100.0f/gImageInfo.imgHeight;

	printf("fWidthIncrement : %f, fHeightIncrement : %f, canvas width : %f, canvas height : %f\n",fWidthIncrement, fHeightIncrement, fWidthIncrement*gImageInfo.imgWidth, fHeightIncrement*gImageInfo.imgHeight);

	glBegin(GL_POINTS); 
	uint32_t uRowNumber = 1;

	// iterate through rows
	for (GLfloat y = 50.0f; y > -50.0f; y -= fHeightIncrement)
	{
		uint32_t uIndex = (gImageInfo.imgWidth * gImageInfo.imgHeight * gImageInfo.bytesPerPixel) - (gImageInfo.imgWidth * gImageInfo.bytesPerPixel * uRowNumber); // start with the last row
		//printf("-----------------------\n uIndex : %d, row number : %d\n", uIndex, uRowNumber);
		// iterate through each element in row
		GLfloat glColor[3];
		for (GLfloat x = -50.0f; x < 50.0f; x+= fWidthIncrement)
		{
			//printf("uIndex : %d, x : %f, y : %f\n", uIndex, x, y);
			glColor[0] = gImageInfo.pRawData[uIndex + 2] / 255.0f; // read red color
			glColor[1] = gImageInfo.pRawData[uIndex + 1] / 255.0f; // read green color
			glColor[2] = gImageInfo.pRawData[uIndex] / 255.0f; // read blue color
			uIndex += gImageInfo.bytesPerPixel;
			glColor3f(glColor[0], glColor[1], glColor[2]);
			glVertex2f(x, y);

		}
		uRowNumber +=1;
		if (uRowNumber > gImageInfo.imgHeight)
		{
			break;
		}
	}

	glEnd(); 

}