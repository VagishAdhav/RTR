#include <stdio.h>

int main(void)
{
    //variable declaration
    int i_vvaArray[10];
    int i_vva;

    //code
    for (i_vva = 0; i_vva < 10; i_vva++)
        i_vvaArray[i_vva] = (i_vva + 1) * 3;

    printf("\n\n");
    printf("Elements of the integer array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("i_vvaArray[%d] = %d \n", i_vva, i_vvaArray[i_vva]);

    printf("\n\n");
    printf("Elements of the integer array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("i_vvaArray[%d] = %d \t Address = %p\n", i_vva, i_vvaArray[i_vva], &i_vvaArray[i_vva]);

    printf("\n\n");

    return (0);
    
}