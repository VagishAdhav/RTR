#include <stdio.h>

int main(void)
{
    //variable declaration
    int vva_a;
    int vva_b;
    int vva_x;

    //code 
    printf("\n\n");
    printf("Enter a number : ");
    scanf("%d", &vva_a);

    printf("\n\n");
    printf("Enter another number : ");
    scanf("%d", &vva_b);
    printf("\n\n");

    // since in all the following 5 cases , the operand on the left 'vva_a' is
    // getting repeated immediately on the right ( e.g vva_a = vva_a + vva_b)
    // We are using compound assignment operators +=, -=, /= and %= 

    // since vva_a will be assigned the value of vva_a + vva_b at the expression
    // vva_a += vva_b, we should save value of original 'vva_a' to other variable 
    // so that we can print in later
    vva_x = vva_a;
    vva_a += vva_b;
    printf("Addition of A = %d and B = %d gives %d.\n", vva_x, vva_b, vva_a);

    // value of vva_a is altered in above expression is used here
    // since vva_a will be assigned the result of vva_a - vva_b at vva_a -= vva_b
    // we must save vva_a in another variable so we cant print it later
    vva_x = vva_a;
    vva_a -= vva_b;
    printf("Subtraction of A = %d and B = %d gives %d.\n", vva_x, vva_b, vva_a);

    // updated value of vva_a in above expression is used here
    // since vva_a will be assigned the result of vva_a * vva_b 
    // at the expression vva_a *= vva_b, we must store original value of vva_a to another variable
    vva_x = vva_a;
    vva_a *= vva_b;
    printf("Multiplication of A = %d and B = %d gives %d.\n", vva_x, vva_b, vva_a);

    // altered values of vva_a in above step is used here
    // since vva_a will be assigned the value of vva_a / vva_b
    // at the expression vva_a /= vva_b, we must store original
    // vva_a to a new variable so that we can print it later
    vva_x = vva_a;
    vva_a /= vva_b;
    printf("Division of A = %d and B = %d gives quotient %d.\n", vva_x, vva_b, vva_a);

    // altered value of vva_a in above step is used here
    // since vva_a will be assigned the value of vva_a % vva_b
    // at the expression vva_a %= vva_b, we must save the original vva_a to another variable
    vva_x = vva_a;
    vva_a %= vva_b;
    printf("Division of A = %d and B = %d gives reminder %d.\n", vva_x, vva_b, vva_a);

    printf("\n\n");

    return(0);


}