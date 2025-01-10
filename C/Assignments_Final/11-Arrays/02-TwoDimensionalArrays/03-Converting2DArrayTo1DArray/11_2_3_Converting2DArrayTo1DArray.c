#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
    // variable declaration 
    int iArray_2D_vva[NUM_ROWS][NUM_COLUMNS]; // Total number of elements = NUM_ROWS * num_vva_COLS
    int iArray_1D_vva[NUM_COLUMNS * NUM_COLUMNS];

    int i_vva, j_vva;
    int num_vva;

    //code
    printf("Enter elements of your choice to fill up integer 2D array : \n\n");

    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        printf("For row number %d : \n", (i_vva + 1));
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
        {
            printf("Enter element number = %d : \n", (j_vva + 1));
            scanf("%d", &num_vva);
            iArray_2D_vva[i_vva][j_vva] = num_vva;
        }
        printf("\n\n");
    }

    // ** Display of 2D array ***
    printf("\n\n");
    printf("Two dimensional (2D) array of integers : \n\n");
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        printf("********** ROW %d ************\n", (i_vva + 1));
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
        {
            printf("iArray_2D_vva[%d][%d] = %d\n", i_vva, j_vva, iArray_2D_vva[i_vva][j_vva]);
        }
        printf("\n\n");
    }

    // **** Converting 2d integer array to 1d integer array
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
        {
            iArray_1D_vva[(i_vva * NUM_COLUMNS) + j_vva] = iArray_2D_vva[i_vva][j_vva];
        }
    }

    // *** Printing 1D array *****
    printf("\n\n");
    printf("One dimensional 1D array of integers : \n\n");
    for ( i_vva = 0; i_vva < (NUM_COLUMNS * NUM_ROWS); i_vva++)
    {
        printf("iArray_vva1D[%d] = %d\n", i_vva, iArray_1D_vva[i_vva]);
    }

    printf("\n\n");

    return (0);
}
