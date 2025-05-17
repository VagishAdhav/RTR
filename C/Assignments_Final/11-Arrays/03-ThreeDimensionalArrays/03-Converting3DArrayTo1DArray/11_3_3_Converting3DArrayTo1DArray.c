#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3
#define DEPTH 2

int main(void)
{
    // variable declaration
    //in line initialization

    int iArray_vva[NUM_ROWS][NUM_COLUMNS][DEPTH] = \
        {  { {9, 18}, {27, 36}, {45, 54} },
           { {8, 16}, {24, 32}, {40, 48} },
           { {7, 14}, {21, 28}, {35, 42} },
           { {6, 12}, {18, 24}, {30, 36} },
           { {5, 10}, {15, 20}, {25, 30} }  };


    int i_vva, j_vva, k_vva;

    int iArray_1D_vva[NUM_ROWS * NUM_COLUMNS * DEPTH]; // 5x3x2 = 30 elements in 1d array

    //code 

    // *** Display 3d array ***
    printf("\n\n");
    printf("Elements in the 3d array : \n\n");

    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        printf("****** ROW %d ******\n", (i_vva + 1));
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
        {
            printf("******** COLUMN %d *********\n", (j_vva + 1));
            for (k_vva = 0; k_vva < DEPTH; k_vva++)
            {
                printf("iArray_vva[%d][%d][%d] = %d\n", i_vva, j_vva, k_vva, iArray_vva[i_vva][j_vva][k_vva]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // **** Converting 3d to 1d array 
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
        {
            for (k_vva = 0; k_vva < DEPTH; k_vva++)
            {
               iArray_1D_vva[(i_vva * NUM_COLUMNS * DEPTH) + (j_vva * DEPTH) + k_vva] = iArray_vva[i_vva][j_vva][k_vva];
            }
        }
    }

    // ** Display 1D array 
    printf("\n\n\n\n");
    printf("Elements in the 1D array : \n\n");
    for (i_vva = 0; i_vva < (NUM_ROWS * NUM_COLUMNS * DEPTH); i_vva++)
    {
        printf("iArray_1D_vva[%d] = %d\n", i_vva, iArray_1D_vva[i_vva]);
    }

    return (0);

}