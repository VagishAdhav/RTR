#include <stdio.h>

int main(void)
{
    //variable declaration
    double d_vvaArray[10];
    double *ptr_d_vvaArray = NULL;
    int i_vva;

    //code
    for (i_vva = 0; i_vva < 10; i_vva++)
        d_vvaArray[i_vva] = (i_vva + 1) * 3;

    // Name of an array address is its base address 
    // assigning base of address of double array to double pointer

    ptr_d_vvaArray = d_vvaArray; // ptr_d_vvaArray = &d_vvaArray[0];

    printf("\n\n");
    printf("Elements of the double array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("d_vvaArray[%d] = %lf \n", i_vva, *(ptr_d_vvaArray + i_vva));

    printf("\n\n");
    printf("Elements of the double array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("d_vvaArray[%d] = %lf \t Address = %p\n", i_vva, *(ptr_d_vvaArray + i_vva), (ptr_d_vvaArray + i_vva));

    printf("\n\n");

    return (0);
    
}