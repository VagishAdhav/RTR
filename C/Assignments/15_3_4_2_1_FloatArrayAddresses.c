#include <stdio.h>

int main(void)
{
    //variable declaration
    float f_vvaArray[10];
    int i_vva;

    //code
    for (i_vva = 0; i_vva < 10; i_vva++)
        f_vvaArray[i_vva] = (float)(i_vva + 1) * 1.5f;

    printf("\n\n");
    printf("Elements of the float array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("i_vvaArray[%d] = %f \n", i_vva, f_vvaArray[i_vva]);

    printf("\n\n");
    printf("Elements of the float array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("i_vvaArray[%d] = %f \t Address = %p\n", i_vva, f_vvaArray[i_vva], &f_vvaArray[i_vva]);

    printf("\n\n");

    return (0);
    
}