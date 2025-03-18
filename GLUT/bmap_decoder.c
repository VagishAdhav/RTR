// Header files
#include "GL/freeglut.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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
imgInfo_t gImageInfoCodeText;
imgInfo_t gImageInfoQuestion;
imgInfo_t gImageInfoFactory;
imgInfo_t gImageInfoHadoop;
imgInfo_t gImageInfoAMC;
imgInfo_t gImageInfPlaceHolder;
imgInfo_t gImageInfoCSE;
imgInfo_t gImageInfoGears;
imgInfo_t gImageInfoChange;

extern GLfloat fRange; 


static void loadImageRawData(char *imageName, imgInfo_t* imgInfo)
{
		// variable declaration
	BMHdr_t BitmapHeader;
    DIBHdr_t DIBHeader;

	// code 
	//load the bitmap file

    FILE *fp = fopen(imageName, "rb");

    // read bitmap header
    fread(&BitmapHeader, sizeof(BMHdr_t), 1, fp);

    if ((BitmapHeader.magic[0] != 'B') || (BitmapHeader.magic[1] != 'M'))
	{
        printf("Invalid image. exiting ...\n");
        return;
    }

    // read DIB header
    fread(&DIBHeader, sizeof(DIBHdr_t), 1, fp);
    if (DIBHeader.compressionMethod != 0)
	{
        printf("Invalid compression, please provide uncompressed image. exiting ...\n");
        return;
    }

    // store width, height and bits per pixel for future use
    imgInfo->imgWidth = DIBHeader.imgWidth;
    imgInfo->imgHeight = DIBHeader.imgHeight;
    imgInfo->bytesPerPixel = DIBHeader.bitPerPixel/8;

    // allocate memory to copy raw data
    imgInfo->pRawData = (uint8_t *)calloc(sizeof(uint8_t), (imgInfo->imgWidth * imgInfo->imgHeight * imgInfo->bytesPerPixel));

    if (!imgInfo->pRawData)
	{
        printf("Not enough memory. Image too large. exiting ...\n");
        return;
    }

    // read raw image data
    fseek(fp, BitmapHeader.startOffset, SEEK_SET);
    fread(imgInfo->pRawData, 1, (imgInfo->imgWidth * imgInfo->imgHeight * imgInfo->bytesPerPixel), fp);

    // printf image info 
    printf("Image Width : %d, Image Height : %d, Bytes Per Pixel : %d\n", imgInfo->imgWidth, imgInfo->imgHeight, imgInfo->bytesPerPixel);

    // close the file 
    fclose(fp);

}

static void displayBitmapImage(imgInfo_t* imgInfo)
{
	glBegin(GL_POINTS); 

	// iterate through rows
	//printf("____________________________________________________________________");
	for (uint32_t row = 0; row < imgInfo->imgHeight; row += 1)
	{
		// iterate through each element in row
		GLfloat glColor[3];
		for (uint32_t col = 0; col < imgInfo->imgWidth; col += 1)
		{
			// image is inverted so start with last row
			//uint32_t uIndex = ((imgInfo->imgHeight - 1 - row) * imgInfo->imgWidth + col) * imgInfo->bytesPerPixel;
			uint32_t uIndex = (row * imgInfo->imgWidth + col) * imgInfo->bytesPerPixel;
			// normlise row and col into x and y cords into fRange
			//printf("uIndex : %d\n", uIndex);

			GLfloat x = (col) * fRange/(imgInfo->imgHeight - 1);
			GLfloat y = (row) * fRange/(imgInfo->imgWidth - 1);

			//printf("uIndex : %d, x : %f, y : %f\n", uIndex, x, y);
			glColor[0] = imgInfo->pRawData[uIndex + 2] / 255.0f; // read red color
			glColor[1] = imgInfo->pRawData[uIndex + 1] / 255.0f; // read green color
			glColor[2] = imgInfo->pRawData[uIndex] / 255.0f; // read blue color
			glColor3f(glColor[0], glColor[1], glColor[2]);
			glVertex2f(x, y);
		}
	}

	glEnd(); 

}

void imageDecoderInitialize(void) 
{
	loadImageRawData("./Images/code_text.bmp", &gImageInfoCodeText);
	loadImageRawData("./Images/question.bmp", &gImageInfoQuestion);
    loadImageRawData("./Images/Factory.bmp", &gImageInfoFactory);
    loadImageRawData("./Images/hadoop-logo.bmp", &gImageInfoHadoop);
    loadImageRawData("./Images/AMC.bmp", &gImageInfoAMC);
    //loadImageRawData("./Images/PlaceHolder.bmp", &gImageInfPlaceHolder);
    loadImageRawData("./Images/CSE.bmp", &gImageInfoCSE);
    loadImageRawData("./Images/Gears.bmp", &gImageInfoGears);
    loadImageRawData("./Images/Change.bmp", &gImageInfoChange);
}


void displayCodeImage(void)
{
	displayBitmapImage(&gImageInfoCodeText);
}

void displayQuestionImage(void)
{
	displayBitmapImage(&gImageInfoQuestion);
}

void displayFactoryImage(void)
{
	displayBitmapImage(&gImageInfoFactory);
}

void displayHadoopImage(void)
{
	displayBitmapImage(&gImageInfoHadoop);
}

void displayAMCImage(void)
{
	displayBitmapImage(&gImageInfoAMC);
}

void displayPlaceHolder(void)
{
    displayBitmapImage(&gImageInfPlaceHolder);
}

void displayCSEImage(void)
{
    displayBitmapImage(&gImageInfoCSE);
}

void displayGearsImage(void)
{
    displayBitmapImage(&gImageInfoGears);
}

void displayChangeImage(void)
{
    displayBitmapImage(&gImageInfoChange);
}


void imageDecoderUninitialize(void)
{
	// code 
    if (gImageInfoCodeText.pRawData)
    {
	    free(gImageInfoCodeText.pRawData);
    }

    if (gImageInfoQuestion.pRawData)
    {
        free(gImageInfoQuestion.pRawData);
    }

    if (gImageInfoAMC.pRawData)
    {
        free(gImageInfoAMC.pRawData);
    }

    if (gImageInfoHadoop.pRawData)
    {
        free(gImageInfoHadoop.pRawData);
    }

    if (gImageInfoFactory.pRawData)
    {
        free(gImageInfoFactory.pRawData);
    }
}

