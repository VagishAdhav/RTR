#include <stdio.h>

int main(void)
{
    //variable declaration
    char c_vvaArray[10];
    int i_vva;

    //code
    for (i_vva = 0; i_vva < 10; i_vva++)
        c_vvaArray[i_vva] = (char)(i_vva + 65);

    printf("\n\n");
    printf("Elements of the character array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("c_vvaArray[%d] = %c \n", i_vva, c_vvaArray[i_vva]);

    printf("\n\n");
    printf("Elements of the character array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("c_vvaArray[%d] = %c \t Address = %p\n", i_vva, c_vvaArray[i_vva], &c_vvaArray[i_vva]);

    printf("\n\n");

    return (0);
    
}