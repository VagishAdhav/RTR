#include <stdio.h>

int main(void)
{
    // variable declarations
    int a_vva = 5;
    int b_vva = 10;

    // code
    printf("\n\n");
    printf("A = %d\n", a_vva);
    printf("A = %d\n", a_vva++);
    printf("A = %d\n", a_vva);
    printf("A = %d\n\n", ++a_vva);

    printf("B = %d\n", b_vva);
    printf("B = %d\n", b_vva--);
    printf("B = %d\n", b_vva);
    printf("B = %d\n\n", --b_vva);

    return (0);
}