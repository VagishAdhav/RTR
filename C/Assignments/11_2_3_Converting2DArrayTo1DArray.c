#include <stdio.h>

#define num_vva_ROWS 5
#define num_vva_COLUMNS 3

int main(void)
{
    // variable declaration 
    int i_vvaArray_2D[num_vva_ROWS][num_vva_COLUMNS]; // Total number of elements = num_vva_ROWS * num_vva_COLS
    int i_vvaArray_1D[num_vva_COLUMNS * num_vva_COLUMNS];

    int i_vva, vva_j;
    int vva_num_vva;

    //code
    printf("Enter elements of your choice to fill up integer 2D array : \n\n");

    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        printf("For row number %d : \n", (i_vva + 1));
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
        {
            printf("Enter element number = %d : \n", (vva_j + 1));
            scanf("%d", &vva_num_vva);
            i_vvaArray_2D[i_vva][vva_j] = vva_num_vva;
        }
        printf("\n\n");
    }

    // ** Display of 2D array ***
    printf("\n\n");
    printf("Two dimensional (2D) array of integers : \n\n");
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        printf("********** ROW %d ************\n", (i_vva + 1));
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
        {
            printf("i_vvaArray_2D[%d][%d] = %d\n", i_vva, vva_j, i_vvaArray_2D[i_vva][vva_j]);
        }
        printf("\n\n");
    }

    // **** Converting 2d integer array to 1d integer array
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
        {
            i_vvaArray_1D[(i_vva * num_vva_COLUMNS) + vva_j] = i_vvaArray_2D[i_vva][vva_j];
        }
    }

    // *** Printing 1D array *****
    printf("\n\n");
    printf("One dimensional 1D array of integers : \n\n");
    for ( i_vva = 0; i_vva < (num_vva_COLUMNS * num_vva_ROWS); i_vva++)
    {
        printf("i_vvaArray1D[%d] = %d\n", i_vva, i_vvaArray_1D[i_vva]);
    }

    printf("\n\n");

    return (0);
}
