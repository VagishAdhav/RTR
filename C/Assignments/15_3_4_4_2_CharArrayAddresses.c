#include <stdio.h>

int main(void)
{
    //variable declaration
    char c_vvaArray[10];
    char *ptr_c_vvaArray = NULL;
    int i_vva;

    //code
    for (i_vva = 0; i_vva < 10; i_vva++)
        c_vvaArray[i_vva] = (char)(i_vva + 65);

    // Name of an array address is its base address 
    // assigning base of address of char array to char pointer

    ptr_c_vvaArray = c_vvaArray; // ptr_c_vvaArray = &c_vvaArray[0];

    printf("\n\n");
    printf("Elements of the character array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("c_vvaArray[%d] = %c \n", i_vva, *(ptr_c_vvaArray + i_vva));

    printf("\n\n");
    printf("Elements of the character array : \n\n");
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("c_vvaArray[%d] = %c \t Address = %p\n", i_vva, *(ptr_c_vvaArray + i_vva), (ptr_c_vvaArray + i_vva));

    printf("\n\n");

    return (0);
    
}