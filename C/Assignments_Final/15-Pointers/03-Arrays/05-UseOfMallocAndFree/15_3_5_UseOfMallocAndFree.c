#include <stdio.h>
#include <stdlib.h> // conyains prototypes of malloc() and free()

int main(void)
{
    //variable declaration
    int *vva_ptr_iArray = NULL; // it is good practice to initialise any pointer with NULL, so later we can easily check success and failure of memory allocation ( malloc())
    unsigned int iArrayLength_vva = 0;
    int i_vva;

    //code
    printf("\n\n");
    printf("Enter the number of elements you want in your integer array : ");
    scanf("%d", &iArrayLength_vva);
    // ** allocating as much memory required for the integer array ***
    // ** memory required for integer array = size in bytes of 1 integer number * number of integers to ne stored in array
    // ** to allocate said amount of memory, function malloc() will be used ***
    // ** malloc() will allocate said amount of memory and return the starting address of allocated memory else return NULL
    // ** using this base address, integer array can be accessed

    vva_ptr_iArray = (int *)malloc(sizeof(int) * iArrayLength_vva);
    if (vva_ptr_iArray == NULL) // if vva_ptr_iArray is still NULL, even after malloc(), that means malloc has failed to allocate the memory
    {
        printf("\n\n");
        printf("Memory allocation for integer array failed !!! Exiting now...");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("Memory allocation for integer allocation is succeeded !!!\n\n");
        printf("Memory addresses from %p to %p have been allocated to integer array !!!\n\n", vva_ptr_iArray, (vva_ptr_iArray + (iArrayLength_vva - 1)));
    }

    printf("\n\n");
    printf("Enter %d elements for integer array : \n\n", iArrayLength_vva);
    for (i_vva = 0; i_vva < iArrayLength_vva; i_vva++)
    {
        scanf("%d", (vva_ptr_iArray + i_vva));
    }

    printf("\n\n");
    printf("The integer array entered by you, consisting of %d elements :\n\n", iArrayLength_vva);
    for (i_vva = 0; i_vva < iArrayLength_vva; i_vva++)
    {
        printf("vva_ptr_iArray[%d] = %d \t\t at address &vva_ptr_iArray[%d] : %p\n",i_vva, vva_ptr_iArray[i_vva], i_vva, &vva_ptr_iArray[i_vva]);
    }

    for (i_vva = 0; i_vva < iArrayLength_vva; i_vva++)
    {
        printf("*(vva_ptr_iArray + %d) = %d \t\t at address (vva_ptr_iArray + %d) : %p\n",i_vva, *(vva_ptr_iArray + i_vva), i_vva, (vva_ptr_iArray + i_vva));
    }

    // ** checking memory is still allocated by checking validity of base address vva_ptr_iArray ****
    // ** if memory is still allocated then free it using free() ***
    // once memory is freed then clean the base address ( assign NULL)

    if (vva_ptr_iArray)
    {
        free(vva_ptr_iArray);
        vva_ptr_iArray = NULL;

        printf("\n\n");
        printf("Memory allocated for integer array has been successfully freed !!!\n\n");
    }

    return (0);
}
