#include <stdio.h>

int main(void)
{
    // variable declaration
    int vva_a;
    int vva_b;
    int vva_result;

    //code 
    printf("\n\n");
    printf("Enter a number : ");
    scanf("%d", &vva_a);

    printf("\n\n");
    printf("Enter another number : ");
    scanf("%d", &vva_b);

    printf("\n\n");

    // *** Following are th e5 arithmetic operators +, -, *, / and % ***
    // *** The resultants of the operations in all the below five cases 
    // have been assigned to the variable 'result' using the assignment operator (=) ***

    vva_result = vva_a + vva_b;
    printf("Addition of A = %d and B = %d gives %d. \n", vva_a, vva_b, vva_result);
    vva_result = vva_a - vva_b;
    printf("Subtraction of A = %d and B = %d gives %d. \n", vva_a, vva_b, vva_result);
    vva_result = vva_a / vva_b;
    printf("Division of A = %d and B = %d gives quotient%d. \n", vva_a, vva_b, vva_result);
    vva_result = vva_a % vva_b;
    printf("Division of A = %d and B = %d gives reminder %d.\n", vva_a, vva_b, vva_result);
    vva_result = vva_a * vva_b;
    printf("multiplication of A = %d and B = %d gives %d.\n", vva_a, vva_b, vva_result);

    printf("\n\n");
    return(0);
}