#include <stdio.h>
#include <stdlib.h>

#define num_vva_ROWS 5
#define num_vva_COLUMNS 3

int main(void)
{
    // variable declaration
    int i_vvaArray[num_vva_ROWS][num_vva_COLUMNS];
    int i_vva, vva_j;
    int *ptr_i_vvaArray_row = NULL;

    //code
    // every row of 2d array is a 1D array itself containing 'num_vva_COLUMNS' integer elements
    // there are 5 rows and 3 columns in a 2d integer array, each of these 5 rows is a 1d array of 3 integers
    // hence each of these 5 rows themselves begin arrays, will be base address of their respective rows

    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        ptr_i_vvaArray_row = i_vvaArray[i_vva]; // 'i_vvaArray[i_vva] is the base address of ith row

        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
            *(ptr_i_vvaArray_row + vva_j) = (i_vva + 1) * (vva_j + 1); // ptr_i_vvaArray_row (i_vvaArray[i_vva]) can be treated as 1D array using pointers
    }

    printf("\n\n");
    printf("2D integer array elements along with addresses : \n\n");
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        ptr_i_vvaArray_row = i_vvaArray[i_vva]; 
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
        {
            printf("*(ptr_i_vvaArray_row + %d) = %d \t at address (ptr_i_vvaArray_row + j) : %p\n", vva_j, *(ptr_i_vvaArray_row + vva_j) , (ptr_i_vvaArray_row + vva_j));
        }
        printf("\n\n");
    }

    return(0);
}