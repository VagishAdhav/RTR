#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
    // variable declarations
    int i_vva, j_vva;
    int **ptr_iArray_vva = NULL;

    // code
    // *** Every row of a 2d array is an integer array itself comprising of NUM_COLUMNS integer elements ***
    // ** There are 5 rows and 3 columns in a 2d integer array, each of the 5 rows is a 1d array of 3 integers
    // ** hence each of these 5 rows themselves being arrays, will be the base addresses of their respective rows ***
    printf("\n\n");

    // ** MEMORY ALLOCATION **
    ptr_iArray_vva = (int **)malloc(NUM_ROWS * sizeof(int *));
    // ptr_iArray is the name and base addresses pf 1D array containing 5 integers pointers to 5 integer arrays..so it is an array containing elements of data type (int *)

    if (ptr_iArray_vva == NULL)
    {
        printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS FAILED !!! EXITING NOW...\n\n", NUM_ROWS);
        exit(0);
    }
    else
    {
        printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS HAS SUCCEEDED !!! \n\n", NUM_ROWS);
    }

    // ** ALLOCATING MEMORY TO EACH ROW ***
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
         ptr_iArray_vva[i_vva] = (int *)malloc(NUM_ROWS * sizeof(int));
        // ptr_iArray[i_vva] is the name and base address of the ith row

        if (ptr_iArray_vva == NULL)
        {
            printf("MEMORY ALLOCATION FOR THE COLUMNS OF ROW %d FAILED !!! EXITING NOW...\n\n", i_vva);
            exit(0);
        }
        else
        {
            printf("MEMORY ALLOCATION FOR THE COLUMNS OF ROW %d HAS SUCCEEDED !!! EXITING NOW...\n\n", i_vva);
        }
    }

    // ** Assigning values **
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
        {
            *(*(ptr_iArray_vva + i_vva) + j_vva) = (i_vva + 1) * (j_vva + 1); // ptr_iArray_vva[i_vva][j_vva] = (i_vva + 1) * (j_vva + 1)
        }
    }

    // ** Displaying values
    printf("\n\n");
    printf("2D integer array elements along with addresses : \n\n");
    for (i_vva = 0; i_vva < NUM_ROWS; i_vva++)
    {
        for (j_vva = 0; j_vva < NUM_COLUMNS; j_vva++)
        {
            printf("ptr_iArray_vva[%d][%d] = %d \t at address &ptr_iArray_vva[%d][%d] : %p\n", i_vva, j_vva, ptr_iArray_vva[i_vva][j_vva], i_vva, j_vva, &ptr_iArray_vva[i_vva][j_vva]);
        }
        printf("\n\n");
    }

    //*** FREEING ALLOCATED MEMORY **
    //*** FREEING MEMORY OF EACH ROW**

    for (i_vva = (NUM_ROWS - 1); i_vva >= 0; i_vva--)
    {
        if (*(ptr_iArray_vva + i_vva)) // if (vva_ptr_iArray[i_vva])
        {
            free(*(ptr_iArray_vva + i_vva)); // free(vva_ptr_iArray[i_vva])
            *(ptr_iArray_vva + i_vva) = NULL; // ptr_iArray_vva[i_vva] = NULL;
            printf("MEMORY ALLOCATED TO ROW %d HAS BEEN SUCCESSFULLY FREED !!! \n\n", i_vva);
        }
    }

    // ** FREEING MEMORY OF ptr_iArray_vva which is the array of 5 integer pointers 
    if (ptr_iArray_vva)
    {
        free(ptr_iArray_vva);
        ptr_iArray_vva = NULL;
        printf("MEMORY ALLOCATED TO ptr_iArray_vva HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }

    return (0);
}
