#include <stdio.h>

int main(void)
{
    //variable declaration
    int a_vva;
    int b_vva;
    int x_vva;

    //code 
    printf("\n\n");
    printf("Enter a_vva number : ");
    scanf("%d", &a_vva);

    printf("\n\n");
    printf("Enter another number : ");
    scanf("%d", &b_vva);
    printf("\n\n");

    // since in all the following 5 cases , the operand on the left 'a_vva' is
    // getting repeated immediately on the right ( e.g a_vva = a_vva + b_vva)
    // We are using compound assignment operators +=, -=, /= and %= 

    // since a_vva will be assigned the value of a_vva + b_vva at the expression
    // a_vva += b_vva, we should save value of original 'a_vva' to other variable 
    // so that we can print in later
    x_vva = a_vva;
    a_vva += b_vva;
    printf("Addition of A = %d and B = %d gives %d.\n", x_vva, b_vva, a_vva);

    // value of a_vva is altered in above expression is used here
    // since a_vva will be assigned the result of a_vva - b_vva at a_vva -= b_vva
    // we must save a_vva in another variable so we cant print it later
    x_vva = a_vva;
    a_vva -= b_vva;
    printf("Subtraction of A = %d and B = %d gives %d.\n", x_vva, b_vva, a_vva);

    // updated value of a_vva in above expression is used here
    // since a_vva will be assigned the result of a_vva * b_vva 
    // at the expression a_vva *= b_vva, we must store original value of a_vva to another variable
    x_vva = a_vva;
    a_vva *= b_vva;
    printf("Multiplication of A = %d and B = %d gives %d.\n", x_vva, b_vva, a_vva);

    // altered values of a_vva in above step is used here
    // since a_vva will be assigned the value of a_vva / b_vva
    // at the expression a_vva /= b_vva, we must store original
    // a_vva to a_vva new variable so that we can print it later
    x_vva = a_vva;
    a_vva /= b_vva;
    printf("Division of A = %d and B = %d gives quotient_vva %d.\n", x_vva, b_vva, a_vva);

    // altered value of a_vva in above step is used here
    // since a_vva will be assigned the value of a_vva % b_vva
    // at the expression a_vva %= b_vva, we must save the original a_vva to another variable
    x_vva = a_vva;
    a_vva %= b_vva;
    printf("Division of A = %d and B = %d gives reminder %d.\n", x_vva, b_vva, a_vva);

    printf("\n\n");

    return(0);


}