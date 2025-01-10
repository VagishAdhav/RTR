#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // variable declarations
    int **ptr_iArray_vva = NULL; // A pointer to pointer to an integer .. but can also hold base address of a 2D array which will can have any number of rows and any number of columns..
    int i_vva, j_vva;
    int num_rows_vva, num_columns_vva;

    //code

    // ** ACCEPT NUMBER OF ROWS 'num_vva_rows' FROM USER ***
    printf("\n\n");
    printf("Enter number of rows : ");
    scanf("%d", &num_rows_vva);

    // ** ACCEPT NUMBER OF 'num_vva_columns' FROM USER ***
    printf("\n\n");
    printf("Enter number of columns: ");
    scanf("%d", &num_columns_vva);

    // *** ALLOCATING MEMORY TO 1D ARRAY CONSISTING OF BASE ADDRESS OF ROWS ****
    printf("\n\n");
    printf("******* MEMORY ALLOCATION TO 2D INTEGER ARRAY *****\n\n");
    ptr_iArray_vva = (int **)malloc(num_rows_vva * sizeof(int *));
    if (ptr_iArray_vva == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY TO %d ROWS OF 2D INTEGER ARRAY !!! EXISTING NOW ...\n\n", num_rows_vva);
        exit(0);
    }
    else 
    {
        printf("MEMORY ALLOCATION TO %d ROWS OF 2D INTEGER ARRAY SUCCEEDED !!! \n\n", num_rows_vva);
    }

    //*** ALLOCATING MEMORY TO EACH ROW WHICH IS 1D ARRAY CONTAINING CONSISTING OF COLUMNS WHICH CONTAINS THE ACTUAL INTEGERS **
    for (i_vva = 0; i_vva < num_rows_vva; i_vva++)
    {
        ptr_iArray_vva[i_vva] = (int *)malloc(num_columns_vva * sizeof(int)); //ALLOCATING MEMORY (number of columns * size of 'int') TO ROW i
        if (ptr_iArray_vva[i_vva] == NULL) // ROW 'i_vva' MEMORY ALLOCATED
        {
            printf("FAILED TO ALLOCATE MEMORY TO COLUMNS OF ROW %d OF 2D INTEGER ARRAY !!! EXITING NOW..\n\n", i_vva);
            return (0);
        }
        else
            printf("MEMORY ALLOCATION TO COLUMNS OF ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_vva);

    }

    // ** FILLING UP VALUES ***
    for (i_vva = 0; i_vva < num_rows_vva; i_vva++)
    {
        for (j_vva = 0; j_vva < num_columns_vva; j_vva++)
        {
            ptr_iArray_vva[i_vva][j_vva] = (i_vva * 1) + (j_vva * 1); //can also use : *(*(ptr_iArray_vva + i) + j) = (i_vva * 1) + (j_vva * 1);
        }
    }

    // **** DISPLAYING VALUES ***
    for (i_vva = 0; i_vva < num_rows_vva; i_vva++)
    {
        printf("Base address of row %d : ptr_iArray_vva[%d] = %p \t at address : %p\n", i_vva, i_vva, ptr_iArray_vva[i_vva], &ptr_iArray_vva[i_vva]);
    }

    printf("\n\n");

    for (i_vva = 0; i_vva < num_rows_vva; i_vva++)
    {
       for (j_vva = 0; j_vva < num_columns_vva; j_vva++)
       {
            printf("ptr_iArray_vva[%d][%d] = %d \t At address : %p\n", i_vva, j_vva, ptr_iArray_vva[i_vva][j_vva], &ptr_iArray_vva[i_vva][j_vva]);
            // can also use *(*(ptr_iArray_vva + i) + j) for values and *(ptr_iArray_vva + i) _ j for address
       }
       printf("\n");
    }

    // ** FREEING MEMORY ALLOCATED TO EACH ROW ***
    for (i_vva = (num_rows_vva - 1); i_vva >= 0; i_vva--)
    {
        if (ptr_iArray_vva[i_vva])
        {
            free(ptr_iArray_vva[i_vva]);
            ptr_iArray_vva[i_vva] = NULL;
            printf("MEMORY ALLOCATED TO ROW %d HAS BEEN SUCCESSFULLY FREED !!!\n\n", i_vva);
        }
    }

    // ** FREEING MEMORY ALLOCATED TO 1D ARRAY CONSISTING OF BASE ADDRESSES OF ROWS **
    if (ptr_iArray_vva)
    {
        free(ptr_iArray_vva);
        ptr_iArray_vva = NULL;
        printf("MEMORY ALLOCATED TO ptr_iArray_vva HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }
    return(0);
}