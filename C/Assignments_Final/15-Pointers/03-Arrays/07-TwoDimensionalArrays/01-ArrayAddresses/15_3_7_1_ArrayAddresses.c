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
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
            iArray_vva[i_vva][j_vva] = (i_vva + 1) * (j_vva + 1);
    }

    printf("\n\n");
    printf("2D integer array elements along with addresses : \n\n");
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
        {
            printf("iArray_vva[%d][%d] = %d \t at address : %p\n", i_vva, j_vva, iArray_vva[i_vva][j_vva], &iArray_vva[i_vva][j_vva]);
        }
        printf("\n\n");
    }

    return(0);
}