#include <stdio.h>
#include <stdlib.h>

#define num_vva_ROWS 5
#define num_vva_COLUMNS 3

int main(void)
{
    // variable declarations
    int i_vva, vva_j;
    int **ptr_i_vvaArray = NULL;

    // code
    // *** Every row of a 2d array is an integer array itself comprising of num_vva_COLUMNS integer elements ***
    // ** There are 5 rows and 3 columns in a 2d integer array, each of the 5 rows is a 1d array of 3 integers
    // ** hence each of these 5 rows themselves being arrays, will be the base addresses of their respective rows ***
    printf("\n\n");

    // ** MEMORY ALLOCATION **
    ptr_i_vvaArray = (int **)malloc(num_vva_ROWS * sizeof(int *));
    // ptr_iArray is the name and base addresses pf 1D array containing 5 integers pointers to 5 integer arrays..so it is an array containing elements of data type (int *)

    if (ptr_i_vvaArray == NULL)
    {
        printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS FAILED !!! EXITING NOW...\n\n", num_vva_ROWS);
        exit(0);
    }
    else
    {
        printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS HAS SUCCEEDED !!! \n\n", num_vva_ROWS);
    }

    // ** ALLOCATING MEMORY TO EACH ROW ***
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
         ptr_i_vvaArray[i_vva] = (int *)malloc(num_vva_ROWS * sizeof(int));
        // ptr_iArray[i_vva] is the name and base address of the ith row

        if (ptr_i_vvaArray == NULL)
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
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
        {
            *(*(ptr_i_vvaArray + i_vva) + vva_j) = (i_vva + 1) * (vva_j + 1); // ptr_i_vvaArray[i_vva][vva_j] = (i_vva + 1) * (vva_j + 1)
        }
    }

    // ** Displaying values
    printf("\n\n");
    printf("2D integer array elements along with addresses : \n\n");
    for (i_vva = 0; i_vva < num_vva_ROWS; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_COLUMNS; vva_j++)
        {
            printf("ptr_i_vvaArray[%d][%d] = %d \t at address &ptr_i_vvaArray[%d][%d] : %p\n", i_vva, vva_j, ptr_i_vvaArray[i_vva][vva_j], i_vva, vva_j, &ptr_i_vvaArray[i_vva][vva_j]);
        }
        printf("\n\n");
    }

    //*** FREEING ALLOCATED MEMORY **
    //*** FREEING MEMORY OF EACH ROW**

    for (i_vva = (num_vva_ROWS - 1); i_vva >= 0; i_vva--)
    {
        if (*(ptr_i_vvaArray + i_vva)) // if (vva_ptr_iArray[i_vva])
        {
            free(*(ptr_i_vvaArray + i_vva)); // free(vva_ptr_iArray[i_vva])
            *(ptr_i_vvaArray + i_vva) = NULL; // ptr_i_vvaArray[i_vva] = NULL;
            printf("MEMORY ALLOCATED TO ROW %d HAS BEEN SUCCESSFULLY FREED !!! \n\n", i_vva);
        }
    }

    // ** FREEING MEMORY OF ptr_i_vvaArray which is the array of 5 integer pointers 
    if (ptr_i_vvaArray)
    {
        free(ptr_i_vvaArray);
        ptr_i_vvaArray = NULL;
        printf("MEMORY ALLOCATED TO ptr_i_vvaArray HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }

    return (0);
}
