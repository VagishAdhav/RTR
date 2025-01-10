#include <stdio.h>

int main(void)
{
    //variable declaration
    float f_vvaArray[10];
    float *ptr_f_vvaArray = NULL;
    int i_vva;

    //code
    for (i_vva = 0; i_vva < 10; i_vva++)
        f_vvaArray[i_vva] = (float)(i_vva + 1) * 1.5f;

    // Name of an array address is its base address 
    // assigning base of address of float array to float pointer

    ptr_f_vvaArray = f_vvaArray; // ptr_f_vvaArray = &f_vvaArray[0];

    printf("\n\n");
    printf("Elements of the float array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("f_vvaArray[%d] = %f \n", i_vva, *(ptr_f_vvaArray + i_vva));

    printf("\n\n");
    printf("Elements of the float array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("f_vvaArray[%d] = %f \t Address = %p\n", i_vva, *(ptr_f_vvaArray + i_vva), (ptr_f_vvaArray + i_vva));

    printf("\n\n");

    return (0);
    
}