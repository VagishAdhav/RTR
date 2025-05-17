#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // variable declarations
    int **ptr_i_vvaArray = NULL; // A pointer to pointer to an integer .. but can also hold base address of a 2D array which will can have any number of rows and any number of columns..
    int i_vva, vva_j;
    int vva_num_vva_rows, vva_num_vva_columns;

    //code

    // ** ACCEPT num_vvaBER OF ROWS 'num_vva_rows' FROM USER ***
    printf("\n\n");
    printf("Enter number of rows : ");
    scanf("%d", &vva_num_vva_rows);

    // ** ACCEPT num_vvaBER OF 'num_vva_columns' FROM USER ***
    printf("\n\n");
    printf("Enter number of columns: ");
    scanf("%d", &vva_num_vva_columns);

    // *** ALLOCATING MEMORY TO 1D ARRAY CONSISTING OF BASE ADDRESS OF ROWS ****
    printf("\n\n");
    printf("******* MEMORY ALLOCATION TO 2D INTEGER ARRAY *****\n\n");
    ptr_i_vvaArray = (int **)malloc(vva_num_vva_rows * sizeof(int *));
    if (ptr_i_vvaArray == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY TO %d ROWS OF 2D INTEGER ARRAY !!! EXISTING NOW ...\n\n", vva_num_vva_rows);
        exit(0);
    }
    else 
    {
        printf("MEMORY ALLOCATION TO %d ROWS OF 2D INTEGER ARRAY SUCCEEDED !!! \n\n", vva_num_vva_rows);
    }

    //*** ALLOCATING MEMORY TO EACH ROW WHICH IS 1D ARRAY CONTAINING CONSISTING OF COLUMNS WHICH CONTAINS THE ACTUAL INTEGERS **
    for (i_vva = 0; i_vva < vva_num_vva_rows; i_vva++)
    {
        ptr_i_vvaArray[i_vva] = (int *)malloc(vva_num_vva_columns * sizeof(int)); //ALLOCATING MEMORY (number of columns * size of 'int') TO ROW i
        if (ptr_i_vvaArray[i_vva] == NULL) // ROW 'i_vva' MEMORY ALLOCATED
        {
            printf("FAILED TO ALLOCATE MEMORY TO COLUMNS OF ROW %d OF 2D INTEGER ARRAY !!! EXITING NOW..\n\n", i_vva);
            return (0);
        }
        else
            printf("MEMORY ALLOCATION TO COLUMNS OF ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_vva);

    }

    // ** FILLING UP VALUES ***
    for (i_vva = 0; i_vva < vva_num_vva_rows; i_vva++)
    {
        for (vva_j = 0; vva_j < vva_num_vva_columns; vva_j++)
        {
            ptr_i_vvaArray[i_vva][vva_j] = (i_vva * 1) + (vva_j * 1); //can also use : *(*(ptr_i_vvaArray + i) + j) = (i_vva * 1) + (vva_j * 1);
        }
    }

    // **** DISPLAYING VALUES ***
    for (i_vva = 0; i_vva < vva_num_vva_rows; i_vva++)
    {
        printf("Base address of row %d : ptr_i_vvaArray[%d] = %p \t at address : %p\n", i_vva, i_vva, ptr_i_vvaArray[i_vva], &ptr_i_vvaArray[i_vva]);
    }

    printf("\n\n");

    for (i_vva = 0; i_vva < vva_num_vva_rows; i_vva++)
    {
       for (vva_j = 0; vva_j < vva_num_vva_columns; vva_j++)
       {
            printf("ptr_i_vvaArray[%d][%d] = %d \t At address : %p\n", i_vva, vva_j, ptr_i_vvaArray[i_vva][vva_j], &ptr_i_vvaArray[i_vva][vva_j]);
            // can also use *(*(ptr_i_vvaArray + i) + j) for values and *(ptr_i_vvaArray + i) _ j for address
       }
       printf("\n");
    }

    // ** FREEING MEMORY ALLOCATED TO EACH ROW ***
    for (i_vva = (vva_num_vva_rows - 1); i_vva >= 0; i_vva--)
    {
        if (ptr_i_vvaArray[i_vva])
        {
            free(ptr_i_vvaArray[i_vva]);
            ptr_i_vvaArray[i_vva] = NULL;
            printf("MEMORY ALLOCATED TO ROW %d HAS BEEN SUCCESSFULLY FREED !!!\n\n", i_vva);
        }
    }

    // ** FREEING MEMORY ALLOCATED TO 1D ARRAY CONSISTING OF BASE ADDRESSES OF ROWS **
    if (ptr_i_vvaArray)
    {
        free(ptr_i_vvaArray);
        ptr_i_vvaArray = NULL;
        printf("MEMORY ALLOCATED TO ptr_i_vvaArray HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }
    return(0);
}