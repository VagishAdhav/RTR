#include <stdio.h>
#include <stdlib.h>

#define num_vva_ROWS 5
#define num_vva_COLUMNS 3

int main(void)
{
    // variable declaration
    int i_vvaArray[num_vva_ROWS][num_vva_COLUMNS];
    int i_vva, vva_j;

    //code
    // *** name of an array itself is its base address **
    // ** Hence i_vvaArray is the base address of 2d integer array i_vvaArray[][]

    // i_vvaArray[5][3] => i_vvaArray is a 2D array having 5 rows and 3 columns, each of these 5 rows is a 1d array of 3 integers
    // i_vvaArray[0] => is the 0th row, is the base address of row 0
    // i_vvaArray[1] => is the 1st row, is the base address of row 1
    // i_vvaArray[4] => is the 5th row, is the base address of row 4

    // (i_vvaArray[0] + 0) => Address of 0th integer from base address of row 0 (i_vvaArray[0][0])
    // (i_vvaArray[0] + 1) => Address of 1st integer from base address of row 0 (i_vvaArray[0][1])
    // (i_vvaArray[0] + 2) => Address of 2nd integer from base address of row 0 (i_vvaArray[0][2])
    
    // (i_vvaArray[1] + 0) => Address of 0th integer from base address of row 1 (i_vvaArray[1][0])
    // (i_vvaArray[1] + 1) => Address of 1st integer from base address of row 1 (i_vvaArray[1][1])
    // (i_vvaArray[1] + 2) => Address of 2nd integer from base address of row 1 (i_vvaArray[1][2])

    // i_vvaArray[0], i_vvaArray[1] are 1D integer arrays and hence can be treated as 1d integer arrays using pointers
    // (*(i_vvaArray + 0) + 0) = (i_vvaArray[0] + 0) = (Address of 0the element from base address of 0the row = (i_vvaArray[0] + 0) = (i_vvaArray[0][0]))
    // (*(i_vvaArray + 0) + 1) = (i_vvaArray[0] + 1) = (Address of 1st element from base address of 0the row = (i_vvaArray[0] + 1) = (i_vvaArray[0][1]))
    // (*(i_vvaArray + 0) + 2) = (i_vvaArray[0] + 2) = (Address of 2nd element from base address of 0the row = (i_vvaArray[0] + 2) = (i_vvaArray[0][2]))

    // (*(i_vvaArray + 1) + 0) = (i_vvaArray[1] + 0) = (Address of 0the element from base address of 1st row = (i_vvaArray[1] + 0) = (i_vvaArray[1][0]))
    // (*(i_vvaArray + 1) + 0) = (i_vvaArray[1] + 1) = (Address of 1st element from base address of 1st row = (i_vvaArray[1] + 1) = (i_vvaArray[1][1]))
    // (*(i_vvaArray + 1) + 0) = (i_vvaArray[1] + 2) = (Address of 2the element from base address of 1st row = (i_vvaArray[1] + 2) = (i_vvaArray[1][2]))

    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
            *(*(i_vvaArray + i_vva) + vva_j) = (i_vva + 1) * (vva_j + 1); // i_vvaArray[i_vva] can be treated as 1D array using pointers
    }

    printf("\n\n");
    printf("2D integer array elements along with addresses : \n\n");
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
        {
            printf("*(*(i_vvaArray + %d) + %d) = %d \t at address (*(i_vvaArray + %d) + %d) : %p\n", i_vva, vva_j, *(*(i_vvaArray + i_vva) + vva_j), i_vva, vva_j, (*(i_vvaArray + 1) + vva_j) );
        }
        printf("\n\n");
    }

    return(0);
}