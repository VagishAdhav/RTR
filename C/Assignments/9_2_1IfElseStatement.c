#include <stdio.h>

int main(void)
{
    //variable declaration
    int a_vva, b_vva, vva_p;

    // code
    a_vva = 9;
    b_vva = 30;
    vva_p = 30;

    // First if else pair
    printf("\n\n");
    if (a_vva < b_vva)
    {
        printf("Entering first if-block..\n\n");
        printf("A is less than B !!! \n\n");
    }
    else
    {
        printf("Entering first else block\n\n");
        printf("A is not less than B !!! \n\n");
    }

    // second if else pair
    printf("\n\n");
    if (b_vva != vva_p)
    {
        printf("Entering second if-block.. \n\n");
        printf("B is NOT equal to P !!!\n\n");
    }
    else
    {
        printf("Entering second else-block...\n\n");
        printf("B is equal to P !!!\n\n");
    }

    return (0);
}