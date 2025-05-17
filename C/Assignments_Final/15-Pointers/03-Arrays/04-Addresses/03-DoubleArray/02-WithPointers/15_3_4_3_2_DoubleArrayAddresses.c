#include <stdio.h>

int main(void)
{
    //variable declaration
    double dArray_vva[10];
    double *ptr_dArray_vva = NULL;
    int i_vva;

    //code
    for (i_vva = 0; i_vva < 10; i_vva++)
        dArray_vva[i_vva] = (i_vva + 1) * 3;

    // Name of an array address is its base address 
    // assigning base of address of double array to double pointer

    ptr_dArray_vva = dArray_vva; // ptr_dArray_vva = &dArray_vva[0];

    printf("\n\n");
    printf("Elements of the double array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("dArray_vva[%d] = %lf \n", i_vva, *(ptr_dArray_vva + i_vva));

    printf("\n\n");
    printf("Elements of the double array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("dArray_vva[%d] = %lf \t Address = %p\n", i_vva, *(ptr_dArray_vva + i_vva), (ptr_dArray_vva + i_vva));

    printf("\n\n");

    return (0);
    
}