#include <stdio.h>

int main(void)
{
    // function declaration
    void Swapnum_vvabers(int, int);

    // variable declaration
    int a;
    int b;

    //code
    printf("\n\n");
    printf("Enter value for 'A' : ");
    scanf("%d", &a);

    
    printf("\n\n");
    printf("Enter value for 'B' : ");
    scanf("%d", &b);

    printf("\n\n");
    printf("*********BEFORE SWAPPING***********\n\n");
    printf("Value of 'A' = %d\n\n", a);
    printf("Value of 'B' = %d\n\n", b);

    Swapnum_vvabers(a, b); // *** ARGUMENTS PASSED BY VALUE **** //

    printf("\n\n");
    printf("*********AFTER SWAPPING***********\n\n");
    printf("Value of 'A' = %d\n\n", a);
    printf("Value of 'B' = %d\n\n", b);

    return (0);
}

void Swapnum_vvabers(int x, int y) // value of a copied into x and value of b is copied into y swapping takes place between x and y not between a and b
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