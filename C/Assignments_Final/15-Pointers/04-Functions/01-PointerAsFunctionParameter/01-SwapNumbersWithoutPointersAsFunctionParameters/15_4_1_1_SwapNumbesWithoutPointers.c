#include <stdio.h>

int main(void)
{
    // function declaration
    void Swapnum_vvabers(int, int);

    // variable declaration
    int a_vva;
    int b_vva;

    //code
    printf("\n\n");
    printf("Enter value for 'A' : ");
    scanf("%d", &a_vva);

    
    printf("\n\n");
    printf("Enter value for 'B' : ");
    scanf("%d", &b_vva);

    printf("\n\n");
    printf("*********BEFORE SWAPPING***********\n\n");
    printf("Value of 'A' = %d\n\n", a_vva);
    printf("Value of 'B' = %d\n\n", b_vva);

    Swapnum_vvabers(a_vva, b_vva); // *** ARGUMENTS PASSED BY VALUE **** //

    printf("\n\n");
    printf("*********AFTER SWAPPING***********\n\n");
    printf("Value of 'A' = %d\n\n", a_vva);
    printf("Value of 'B' = %d\n\n", b_vva);

    return (0);
}

void Swapnum_vvabers(int x, int y) // value of a_vva copied into x and value of b_vva is copied into y swapping takes place between x and y not between a_vva and b_vva
{
    // variable declaration
    int temp;

    //code
    printf("\n\n");
    printf("*********BEFORE SWAPPING***********\n\n");
    printf("Value of 'X' = %d\n\n", x);
    printf("Value of 'Y' = %d\n\n", y);

    temp = x;
    x = y;
    y = temp;

    printf("\n\n");
    printf("*********AFTER SWAPPING***********\n\n");
    printf("Value of 'X' = %d\n\n", x);
    printf("Value of 'Y' = %d\n\n", y);
}