#include <stdio.h>

int main(void)
{
    // variable declarations
    int vva_a = 5;
    int vva_b = 10;

    // code
    printf("\n\n");
    printf("A = %d\n", vva_a);
    printf("A = %d\n", vva_a++);
    printf("A = %d\n", vva_a);
    printf("A = %d\n\n", ++vva_a);

    printf("B = %d\n", vva_b);
    printf("B = %d\n", vva_b--);
    printf("B = %d\n", vva_b);
    printf("B = %d\n\n", --vva_b);

    return (0);
}