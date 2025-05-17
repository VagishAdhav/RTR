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
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
            i_vvaArray[i_vva][vva_j] = (i_vva + 1) * (vva_j + 1);
    }

    printf("\n\n");
    printf("2D integer array elements along with addresses : \n\n");
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
        {
            printf("i_vvaArray[%d][%d] = %d \t at address : %p\n", i_vva, vva_j, i_vvaArray[i_vva][vva_j], &i_vvaArray[i_vva][vva_j]);
        }
        printf("\n\n");
    }

    return(0);
}