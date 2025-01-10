#include <stdio.h>
#include <stdlib.h>

#define num_vva_ROWS 5
#define num_vva_COLUMNS 3

int main(void)
{
    // variable declaration
    int *i_vvaArray[num_vva_ROWS]; // A 2d array which will have 5 rows and number of columns can be decides later on..
    int i_vva, vva_j;

    //code 
    printf("\n\n");
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        i_vvaArray[i_vva] = (int *)malloc(num_vva_COLUMNS * sizeof(int));
        if (i_vvaArray[i_vva] == NULL)
        {
            printf("FAILED TO ALLOCATE MEMORY TO ROW %d of 2D integer array !!! EXITING NOW \n\n", i_vva);
            exit(0);
        }
        else
            printf("MEMORY ALLOCATIOn TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_vva);
    }

    // Assigning values of to 2d arrays
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
        {
            i_vvaArray[i_vva][vva_j] = (i_vva + 1) * (vva_j + 1);
        }
    }

    // Displaying 2d array...
    printf("\n\n");
    printf("DISPLAYING 2D ARRAY : \n\n");
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
        {
            printf("i_vvaArray[%d][%d] = %d\n", i_vva, vva_j, i_vvaArray[i_vva][vva_j]);
        }
        printf("\n\n");
    }
    printf("\n\n");

    // FREEING MEMORY ASSIGNED TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER)
    for (i_vva = (num_vva_ROWS - 1); i_vva >= 0; i_vva--)
    {
        free(i_vvaArray[i_vva]);
        i_vvaArray[i_vva] = NULL;
        printf("MEMORY ALLOCATED TO ROW %d OF 2D INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n", i_vva);
    }

    return (0);
}