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
    // *** name of an array itself is its base address **
    // ** Hence iArray_vva is the base address of 2d integer array iArray_vva[][]

    // iArray_vva[5][3] => iArray_vva is a 2D array having 5 rows and 3 columns, each of these 5 rows is a 1d array of 3 integers
    // iArray_vva[0] => is the 0th row, is the base address of row 0
    // iArray_vva[1] => is the 1st row, is the base address of row 1
    // iArray_vva[4] => is the 5th row, is the base address of row 4

    // (iArray_vva[0] + 0) => Address of 0th integer from base address of row 0 (iArray_vva[0][0])
    // (iArray_vva[0] + 1) => Address of 1st integer from base address of row 0 (iArray_vva[0][1])
    // (iArray_vva[0] + 2) => Address of 2nd integer from base address of row 0 (iArray_vva[0][2])
    
    // (iArray_vva[1] + 0) => Address of 0th integer from base address of row 1 (iArray_vva[1][0])
    // (iArray_vva[1] + 1) => Address of 1st integer from base address of row 1 (iArray_vva[1][1])
    // (iArray_vva[1] + 2) => Address of 2nd integer from base address of row 1 (iArray_vva[1][2])

    // iArray_vva[0], iArray_vva[1] are 1D integer arrays and hence can be treated as 1d integer arrays using pointers
    // (*(iArray_vva + 0) + 0) = (iArray_vva[0] + 0) = (Address of 0the element from base address of 0the row = (iArray_vva[0] + 0) = (iArray_vva[0][0]))
    // (*(iArray_vva + 0) + 1) = (iArray_vva[0] + 1) = (Address of 1st element from base address of 0the row = (iArray_vva[0] + 1) = (iArray_vva[0][1]))
    // (*(iArray_vva + 0) + 2) = (iArray_vva[0] + 2) = (Address of 2nd element from base address of 0the row = (iArray_vva[0] + 2) = (iArray_vva[0][2]))

    // (*(iArray_vva + 1) + 0) = (iArray_vva[1] + 0) = (Address of 0the element from base address of 1st row = (iArray_vva[1] + 0) = (iArray_vva[1][0]))
    // (*(iArray_vva + 1) + 0) = (iArray_vva[1] + 1) = (Address of 1st element from base address of 1st row = (iArray_vva[1] + 1) = (iArray_vva[1][1]))
    // (*(iArray_vva + 1) + 0) = (iArray_vva[1] + 2) = (Address of 2the element from base address of 1st row = (iArray_vva[1] + 2) = (iArray_vva[1][2]))

    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
            *(*(iArray_vva + i_vva) + j_vva) = (i_vva + 1) * (j_vva + 1); // iArray_vva[i_vva] can be treated as 1D array using pointers
    }

    printf("\n\n");
    printf("2D integer array elements along with addresses : \n\n");
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
        {
            printf("*(*(iArray_vva + %d) + %d) = %d \t at address (*(iArray_vva + %d) + %d) : %p\n", i_vva, j_vva, *(*(iArray_vva + i_vva) + j_vva), i_vva, j_vva, (*(iArray_vva + 1) + j_vva) );
        }
        printf("\n\n");
    }

    return(0);
}