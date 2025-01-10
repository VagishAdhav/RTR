#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
    // variable declaration
    int *iArray_vva[NUM_ROWS]; // A 2d array which will have 5 rows and number of columns can be decides later on..
    int i_vva, j_vva;

    //code 
    printf("\n\n");
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        iArray_vva[i_vva] = (int *)malloc(NUM_COLUMNS * sizeof(int));
        if (iArray_vva[i_vva] == NULL)
        {
            printf("FAILED TO ALLOCATE MEMORY TO ROW %d of 2D integer array !!! EXITING NOW \n\n", i_vva);
            exit(0);
        }
        else
            printf("MEMORY ALLOCATIOn TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_vva);
    }

    // Assigning values of to 2d arrays
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
        {
            iArray_vva[i_vva][j_vva] = (i_vva + 1) * (j_vva + 1);
        }
    }

    // Displaying 2d array...
    printf("\n\n");
    printf("DISPLAYING 2D ARRAY : \n\n");
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
        {
            printf("iArray_vva[%d][%d] = %d\n", i_vva, j_vva, iArray_vva[i_vva][j_vva]);
        }
        printf("\n\n");
    }
    printf("\n\n");

    // FREEING MEMORY ASSIGNED TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER)
    for (i_vva = (NUM_ROWS - 1); i_vva >= 0; i_vva--)
    {
        free(iArray_vva[i_vva]);
        iArray_vva[i_vva] = NULL;
        printf("MEMORY ALLOCATED TO ROW %d OF 2D INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n", i_vva);
    }

    return (0);
}