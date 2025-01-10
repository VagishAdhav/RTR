#include <stdio.h>

int main(void)
{
    //variable declaration
    double d_vvaArray[10];
    int i_vva;

    //code
    for (i_vva = 0; i_vva < 10; i_vva++)
        d_vvaArray[i_vva] = (i_vva + 1) * 3;

    printf("\n\n");
    printf("Elements of the double array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("d_vvaArray[%d] = %lf \n", i_vva, d_vvaArray[i_vva]);

    printf("\n\n");
    printf("Elements of the double array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("d_vvaArray[%d] = %lf \t Address = %p\n", i_vva, d_vvaArray[i_vva], &d_vvaArray[i_vva]);

    printf("\n\n");

    return (0);
    
}