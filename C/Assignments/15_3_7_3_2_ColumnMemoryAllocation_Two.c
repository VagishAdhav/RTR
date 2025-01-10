#include <stdio.h>
#include <stdlib.h>

#define num_vva_ROWS 5
#define num_vva_COLUMNS_ONE 3
#define num_vva_COLUMNS_TWO 8

int main(void)
{
    // variable declarations
    int *i_vvaArray[num_vva_ROWS]; // A 2d array which will have 5 rows and number of columns can be decided later on ..
    int i_vva, vva_j;

    // code

    // *** ONE (ALLOCATING MEMORY FOR AN ARRAY OF 3 INTEGERS PER ROW) ******
    printf("\n\n");
    printf("************* FIRST MEMORY ALLOCATION TO 2D INTEGER ARRAY *******\n\n");
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        i_vvaArray[i_vva] = (int *)malloc(num_vva_COLUMNS_ONE * sizeof(int));
        if (i_vvaArray[i_vva] == NULL)
        {
            printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXISTING NOW...\n\n", i_vva);
            exit(0);
        }
        else
            printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_vva);
    }

    // ASSIGNING VALUES TO 2D ARRAY
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS_ONE; vva_j++)
        {
            i_vvaArray[i_vva][vva_j] = (i_vva + 1) * (vva_j + 1);
        }
    }

    // DISPLAYING 2D ARRAY
    printf("\n\n");
    printf("DISPLAYING 2D ARRAY : \n\n");
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS_ONE; vva_j++)
        {
            printf("i_vvaArray[%d][%d] = %d\n", i_vva, vva_j, i_vvaArray[i_vva][vva_j]);
        }
        printf("\n\n");
    }
    printf("\n\n");

    // FREEING MEMORY TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER)
    for (i_vva = (num_vva_ROWS -1 ); i_vva >= 0; i_vva--)
    {
        free(i_vvaArray[i_vva]);
        i_vvaArray[i_vva] = NULL;
        printf("MEMORY ALLOCATED TO ROW %d OF 2D INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n\n", i_vva);
    }


    // *** TWO (ALLOCATING MEMORY FOR AN ARRAY OF 8 INTEGERS PER ROW) ******
    printf("\n\n");
    printf("************* SECOND MEMORY ALLOCATION TO 2D INTEGER ARRAY *******\n\n");
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        i_vvaArray[i_vva] = (int *)malloc(num_vva_COLUMNS_TWO * sizeof(int));
        if (i_vvaArray[i_vva] == NULL)
        {
            printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXISTING NOW...\n\n", i_vva);
            exit(0);
        }
        else
            printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_vva);
    }

    // ASSIGNING VALUES TO 2D ARRAY
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS_TWO; vva_j++)
        {
            i_vvaArray[i_vva][vva_j] = (i_vva + 1) * (vva_j + 1);
        }
    }

    // DISPLAYING 2D ARRAY
    printf("\n\n");
    printf("DISPLAYING 2D ARRAY : \n\n");
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS_TWO; vva_j++)
        {
            printf("i_vvaArray[%d][%d] = %d\n", i_vva, vva_j, i_vvaArray[i_vva][vva_j]);
        }
        printf("\n\n");
    }
    printf("\n\n");

    // FREEING MEMORY TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER)
    for (i_vva = (num_vva_ROWS -1 ); i_vva >= 0; i_vva--)
    {
        free(i_vvaArray[i_vva]);
        i_vvaArray[i_vva] = NULL;
        printf("MEMORY ALLOCATED TO ROW %d OF 2D INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n\n", i_vva);
    }
    return (0);
}