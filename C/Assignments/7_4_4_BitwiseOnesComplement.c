#include <stdio.h>

int main(void)
{
    //function prototypes 
    void PrintBinaryFormOfNumber(unsigned int);

    //variable declarations
    unsigned int vva_a;
    unsigned int vva_result;

    //code
    printf("\n\n");
    printf("Enter an integer = ");
    scanf("%u", &vva_a);

    printf("\n\n\n\n");
    vva_result = ~vva_a;
    printf("Bitwise Complementing of \nA = %d (Decimal) gives result %d (Decimal). \n\n", vva_a, vva_result);
    PrintBinaryFormOfNumber(vva_a);
    PrintBinaryFormOfNumber(vva_result);

    return (0);
}

void PrintBinaryFormOfNumber(unsigned int decimal_number)
{
    //variable declaration
    unsigned int quotient, remainder;
    unsigned int num;
    unsigned int binary_array[8];
    int i;
    for (i = 0; i < 8; i++)
        binary_array[i] = 0;

    printf("The binary form of decimal integer is %d \t=\t", decimal_number);
    num = decimal_number;
    i = 7;
    while (num != 0)
    {
        quotient = num /2;
        remainder = num % 2;
        binary_array[i] = remainder;
        num = quotient;
        i--;
    }

    for (i = 0; i < 8; i++)
        printf("%u", binary_array[i]);

    printf("\n\n");
}