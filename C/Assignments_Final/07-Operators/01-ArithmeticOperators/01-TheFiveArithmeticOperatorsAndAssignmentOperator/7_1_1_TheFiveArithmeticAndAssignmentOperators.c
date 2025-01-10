#include <stdio.h>

int main(void)
{
    // variable declaration
    int a_vva;
    int b_vva;
    int result_vva;

    //code 
    printf("\n\n");
    printf("Enter a_vva number : ");
    scanf("%d", &a_vva);

    printf("\n\n");
    printf("Enter another number : ");
    scanf("%d", &b_vva);

    printf("\n\n");

    // *** Following are th e5 arithmetic operators +, -, *, / and % ***
    // *** The resultants of the operations in all the below five cases 
    // have been assigned to the variable 'result_vva' using the assignment operator (=) ***

    result_vva = a_vva + b_vva;
    printf("Addition of A = %d and B = %d gives %d. \n", a_vva, b_vva, result_vva);
    result_vva = a_vva - b_vva;
    printf("Subtraction of A = %d and B = %d gives %d. \n", a_vva, b_vva, result_vva);
    result_vva = a_vva / b_vva;
    printf("Division of A = %d and B = %d gives quotient_vva%d. \n", a_vva, b_vva, result_vva);
    result_vva = a_vva % b_vva;
    printf("Division of A = %d and B = %d gives reminder %d.\n", a_vva, b_vva, result_vva);
    result_vva = a_vva * b_vva;
    printf("multiplication of A = %d and B = %d gives %d.\n", a_vva, b_vva, result_vva);

    printf("\n\n");
    return(0);
}