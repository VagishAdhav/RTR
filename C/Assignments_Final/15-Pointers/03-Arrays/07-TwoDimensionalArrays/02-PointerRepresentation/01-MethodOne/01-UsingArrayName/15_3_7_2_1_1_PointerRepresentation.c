#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
    // variable declaration
    int iArray_vva[NUM_ROWS][NUM_COLUMNS];
    int i_vva, j_vva;

    //code
    // every row of 2d array is a 1D array itself containing 'NUM_COLUMNS' integer elements
    // there are 5 rows and 3 columns in a 2d integer array, each of these 5 rows is a 1d array of 3 integers
    // hence each of these 5 rows themselves begin arrays, will be base address of their respective rows

    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
            *(iArray_vva[i_vva] + j_vva) = (i_vva + 1) * (j_vva + 1); // iArray_vva[i_vva] can be treated as 1D array using pointers
    }

    printf("\n\n");
    printf("2D integer array elements along with addresses : \n\n");
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
        {
            printf("*(iArray_vva[%d] + %d) = %d \t at address (iArray_vva[i] + j) : %p\n", i_vva, j_vva, *(iArray_vva[i_vva] + j_vva) , (iArray_vva[i_vva] + j_vva) );
        }
        printf("\n\n");
    }

    return(0);
}