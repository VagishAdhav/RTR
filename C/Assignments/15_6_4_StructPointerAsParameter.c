#include <stdio.h>
#include <stdlib.h>

// defining struct 
struct MyData
{
    int i;
    float f;
    double d;
};

int main(void)
{
    // function prototype
    void ChangeValues(struct MyData *);

    // variable declarations
    struct MyData *pData = NULL;

    //code
    printf("\n\n");

    pData = (struct MyData *)malloc(sizeof(struct MyData));
    if (pData == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY TO 'struct MyData' !!! EXITING NOW ...\n\n");
        exit(0);
    }
    else
    {
        printf("SUCCESSFULLY ALLOCATED MEMORY TO 'struct Mydata' !!!\n\n");
    }

    // Assigning data values to the data members of 'struct MyData'
    pData->i = 30;
    pData->f = 11.45f;
    pData->d = 1.2995;

    // Displaying values of the data members of struct MyData
    printf("\n\n");
    printf("DATA MEMBERS OF struct MyData ARE : \n\n");
    printf("i = %d\n", pData->i);
    printf("f = %f\n", pData->f);
    printf("d = %lf\n", pData->d);

    ChangeValues(pData);

    // Displaying values of the data members of struct MyData
    printf("\n\n");
    printf("CHANGED DATA MEMBERS OF struct MyData ARE : \n\n");
    printf("i = %d\n", pData->i);
    printf("f = %f\n", pData->f);
    printf("d = %lf\n\n", pData->d);

    if (pData)
    {
        free(pData);
        pData = NULL;
        printf("MEMORY ALLOCATED TO 'struct MyData' HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }

    return (0);
}


void ChangeValues(struct MyData *pParam_Data)
{
    // code
    pParam_Data->i = 9;
    pParam_Data->f = 8.2f;
    pParam_Data->d = 6.1998;

    // CAN ALSO DO THIS ..
/*    
    (*pParam_Data).i = 9;
    (*pParam_Data).f = 8.2f;
    (*pParam_Data).d = 6.1998;
*/
}