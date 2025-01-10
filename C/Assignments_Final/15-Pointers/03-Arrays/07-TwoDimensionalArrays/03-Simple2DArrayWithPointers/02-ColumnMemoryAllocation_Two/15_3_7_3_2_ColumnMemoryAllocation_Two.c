#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define num_vva_COLUMNS_ONE 3
#define num_vva_COLUMNS_TWO 8

int main(void)
{
    // variable declarations
    int *iArray_vva[NUM_ROWS]; // A 2d array which will have 5 rows and number of columns can be decided later on ..
    int i_vva, j_vva;

    // code

    // *** ONE (ALLOCATING MEMORY FOR AN ARRAY OF 3 INTEGERS PER ROW) ******
    printf("\n\n");
    printf("************* FIRST MEMORY ALLOCATION TO 2D INTEGER ARRAY *******\n\n");
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        iArray_vva[i_vva] = (int *)malloc(num_vva_COLUMNS_ONE * sizeof(int));
        if (iArray_vva[i_vva] == NULL)
        {
            printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXISTING NOW...\n\n", i_vva);
            exit(0);
        }
        else
            printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_vva);
    }

    // ASSIGNING VALUES TO 2D ARRAY
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < num_vva_COLUMNS_ONE; j_vva++)
        {
            iArray_vva[i_vva][j_vva] = (i_vva + 1) * (j_vva + 1);
        }
    }

    // DISPLAYING 2D ARRAY
    printf("\n\n");
    printf("DISPLAYING 2D ARRAY : \n\n");
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < num_vva_COLUMNS_ONE; j_vva++)
        {
            printf("iArray_vva[%d][%d] = %d\n", i_vva, j_vva, iArray_vva[i_vva][j_vva]);
        }
        printf("\n\n");
    }
    printf("\n\n");

    // FREEING MEMORY TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER)
    for (i_vva = (NUM_ROWS -1 ); i_vva >= 0; i_vva--)
    {
        free(iArray_vva[i_vva]);
        iArray_vva[i_vva] = NULL;
        printf("MEMORY ALLOCATED TO ROW %d OF 2D INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n\n", i_vva);
    }


    // *** TWO (ALLOCATING MEMORY FOR AN ARRAY OF 8 INTEGERS PER ROW) ******
    printf("\n\n");
    printf("************* SECOND MEMORY ALLOCATION TO 2D INTEGER ARRAY *******\n\n");
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        iArray_vva[i_vva] = (int *)malloc(num_vva_COLUMNS_TWO * sizeof(int));
        if (iArray_vva[i_vva] == NULL)
        {
            printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXISTING NOW...\n\n", i_vva);
            exit(0);
        }
        else
            printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_vva);
    }

    // ASSIGNING VALUES TO 2D ARRAY
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < num_vva_COLUMNS_TWO; j_vva++)
        {
            iArray_vva[i_vva][j_vva] = (i_vva + 1) * (j_vva + 1);
        }
    }

    // DISPLAYING 2D ARRAY
    printf("\n\n");
    printf("DISPLAYING 2D ARRAY : \n\n");
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < num_vva_COLUMNS_TWO; j_vva++)
        {
            printf("iArray_vva[%d][%d] = %d\n", i_vva, j_vva, iArray_vva[i_vva][j_vva]);
        }
        printf("\n\n");
    }
    printf("\n\n");

    // FREEING MEMORY TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER)
    for (i_vva = (NUM_ROWS -1 ); i_vva >= 0; i_vva--)
    {
        free(iArray_vva[i_vva]);
        iArray_vva[i_vva] = NULL;
        printf("MEMORY ALLOCATED TO ROW %d OF 2D INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n\n", i_vva);
    }
    return (0);
}