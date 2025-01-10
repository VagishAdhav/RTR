#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 5

int main(void)
{
    // variable declaration
    int *iArray_vva[NUM_ROWS]; // A 2d array which will have 5 rows and number of columns can be decides later on..
    int i_vva, j_vva;

    //code 
    printf("\n\n");
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        //ROW 0 WILL HAVE (NUM_COLUMNS - 0) = (5 - 0 ) = 5 COLUMNS..
        //ROW 1 WILL HAVE (NUM_COLUMNS - 1) = (5 - 1 ) = 4 COLUMNS..
        //ROW 2 WILL HAVE (NUM_COLUMNS - 2) = (5 - 2 ) = 3 COLUMNS..
        //ROW 3 WILL HAVE (NUM_COLUMNS - 3) = (5 - 3 ) = 2 COLUMNS..
        //ROW 4 WILL HAVE (NUM_COLUMNS - 4) = (5 - 4 ) = 1 COLUMN..

        //BECAUSE OF THIS, THERE IS NO CONTIGUOUS MEMORY ALLOCATION ... HENCE,
        // ALTHOUGH WE MAY USE THE DATA AS 2D ARRAY, IT IS NOT REALLY A 2D ARRAY IN MEMORY..

        iArray_vva[i_vva] = (int *)malloc((NUM_COLUMNS - 1) * sizeof(int));
        if (iArray_vva[i_vva] == NULL)
        {
            printf("FAILED TO ALLOCATE MEMORY TO ROW %d of 2D integer array !!! EXITING NOW \n\n", i_vva);
            exit(0);
        }
        else
            printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_vva);
    }

    for (i_vva = 0; i_vva < 5; i_vva++)
    {
        for (j_vva = 0; j_vva < (NUM_COLUMNS - i_vva); j_vva++)
        {
            iArray_vva[i_vva][j_vva] = (i_vva + 1) * (j_vva + 1);
        }
    }

    for (i_vva = 0; i_vva < 5; i_vva++)
    {
        for (j_vva = 0; j_vva < (NUM_COLUMNS - i_vva); j_vva++)
        {
            printf("iArray_vva[%d][%d] = %d\n", i_vva, j_vva, iArray_vva[i_vva][j_vva]);
        }
        printf("\n");
    }

    for (i_vva = (NUM_ROWS - 1); i_vva >= 0; i_vva--)
    {
        free(iArray_vva[i_vva]);
        iArray_vva[i_vva] = NULL;
        printf("MEMORY ALLOCATED TO ROW %d HAS BEEN SUCCESSFULLY FREED !!!\n\n", i_vva);
    }

    return (0);
}