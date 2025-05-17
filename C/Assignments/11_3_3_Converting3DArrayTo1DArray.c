#include <stdio.h>

#define num_vva_ROWS 5
#define num_vva_COLUMNS 3
#define DEPTH 2

int main(void)
{
    // variable declaration
    //in line initialization

    int i_vvaArray[num_vva_ROWS][num_vva_COLUMNS][DEPTH] = \
        {  { {9, 18}, {27, 36}, {45, 54} },
           { {8, 16}, {24, 32}, {40, 48} },
           { {7, 14}, {21, 28}, {35, 42} },
           { {6, 12}, {18, 24}, {30, 36} },
           { {5, 10}, {15, 20}, {25, 30} }  };


    int i_vva, vva_j, vva_k;

    int i_vvaArray_1D[num_vva_ROWS * num_vva_COLUMNS * DEPTH]; // 5x3x2 = 30 elements in 1d array

    //code 

    // *** Display 3d array ***
    printf("\n\n");
    printf("Elements in the 3d array : \n\n");

    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        printf("****** ROW %d ******\n", (i_vva + 1));
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
        {
            printf("******** COLUMN %d *********\n", (vva_j + 1));
            for (vva_k = 0; vva_k < DEPTH; vva_k++)
            {
                printf("i_vvaArray[%d][%d][%d] = %d\n", i_vva, vva_j, vva_k, i_vvaArray[i_vva][vva_j][vva_k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // **** Converting 3d to 1d array 
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
        {
            for (vva_k = 0; vva_k < DEPTH; vva_k++)
            {
               i_vvaArray_1D[(i_vva * num_vva_COLUMNS * DEPTH) + (vva_j * DEPTH) + vva_k] = i_vvaArray[i_vva][vva_j][vva_k];
            }
        }
    }

    // ** Display 1D array 
    printf("\n\n\n\n");
    printf("Elements in the 1D array : \n\n");
    for (i_vva = 0; i_vva < (num_vva_ROWS * num_vva_COLUMNS * DEPTH); i_vva++)
    {
        printf("i_vvaArray_1D[%d] = %d\n", i_vva, i_vvaArray_1D[i_vva]);
    }

    return (0);

}