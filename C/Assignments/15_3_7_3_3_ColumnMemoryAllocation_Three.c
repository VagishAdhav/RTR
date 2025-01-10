#include <stdio.h>
#include <stdlib.h>

#define num_vva_ROWS 5
#define num_vva_COLUMNS 5

int main(void)
{
    // variable declaration
    int *i_vvaArray[num_vva_ROWS]; // A 2d array which will have 5 rows and number of columns can be decides later on..
    int i_vva, vva_j;

    //code 
    printf("\n\n");
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        //ROW 0 WILL HAVE (num_vva_COLUMNS - 0) = (5 - 0 ) = 5 COLUMNS..
        //ROW 1 WILL HAVE (num_vva_COLUMNS - 1) = (5 - 1 ) = 4 COLUMNS..
        //ROW 2 WILL HAVE (num_vva_COLUMNS - 2) = (5 - 2 ) = 3 COLUMNS..
        //ROW 3 WILL HAVE (num_vva_COLUMNS - 3) = (5 - 3 ) = 2 COLUMNS..
        //ROW 4 WILL HAVE (num_vva_COLUMNS - 4) = (5 - 4 ) = 1 COLUMN..

        //BECAUSE OF THIS, THERE IS NO CONTIGUOUS MEMORY ALLOCATION ... HENCE,
        // ALTHOUGH WE MAY USE THE DATA AS 2D ARRAY, IT IS NOT REALLY A 2D ARRAY IN MEMORY..

        i_vvaArray[i_vva] = (int *)malloc((num_vva_COLUMNS - 1) * sizeof(int));
        if (i_vvaArray[i_vva] == NULL)
        {
            printf("FAILED TO ALLOCATE MEMORY TO ROW %d of 2D integer array !!! EXITING NOW \n\n", i_vva);
            exit(0);
        }
        else
            printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_vva);
    }

    for (i_vva = 0; i_vva < 5; i_vva++)
    {
        for (vva_j = 0; vva_j < (num_vva_COLUMNS - i_vva); vva_j++)
        {
            i_vvaArray[i_vva][vva_j] = (i_vva + 1) * (vva_j + 1);
        }
    }

    for (i_vva = 0; i_vva < 5; i_vva++)
    {
        for (vva_j = 0; vva_j < (num_vva_COLUMNS - i_vva); vva_j++)
        {
            printf("i_vvaArray[%d][%d] = %d\n", i_vva, vva_j, i_vvaArray[i_vva][vva_j]);
        }
        printf("\n");
    }

    for (i_vva = (num_vva_ROWS - 1); i_vva >= 0; i_vva--)
    {
        free(i_vvaArray[i_vva]);
        i_vvaArray[i_vva] = NULL;
        printf("MEMORY ALLOCATED TO ROW %d HAS BEEN SUCCESSFULLY FREED !!!\n\n", i_vva);
    }

    return (0);
}