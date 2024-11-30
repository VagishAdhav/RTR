#include <stdio.h>

int main(void)
{
    //variable declaration
    int vva_a, vva_b, vva_p;

    // code
    vva_a = 9;
    vva_b = 30;
    vva_p = 30;

    // First if else pair
    printf("\n\n");
    if (vva_a < vva_b)
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
    if (vva_b != vva_p)
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