#include <stdio.h>

int main(void)
{
    //variable declaration
    int iArray_vva[10];
    int *ptr_iArray_vva = NULL;
    int i_vva;

    //code
    for (i_vva = 0; i_vva < 10; i_vva++)
        iArray_vva[i_vva] = (i_vva + 1) * 3;

    // Name of an array address is its base address 
    // assigning base of address of integer array to integer pointer

    ptr_iArray_vva = iArray_vva; // ptr_a_vvarray = &iArray_vva[0];

    printf("\n\n");
    printf("Elements of the integer array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("iArray_vva[%d] = %d \n", i_vva, *(ptr_iArray_vva + i_vva));

    printf("\n\n");
    printf("Elements of the integer array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("iArray_vva[%d] = %d \t Address = %p\n", i_vva, *(ptr_iArray_vva + i_vva), (ptr_iArray_vva + i_vva));

    printf("\n\n");

    return (0);
    
}