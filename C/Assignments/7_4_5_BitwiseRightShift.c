#include <stdio.h>

int main(void)
{
    //function prototypes
    void PrintBinaryFormOfNumber(unsigned int);

    // variable declaration
    unsigned int vva_a;
    unsigned int vva_num_bits;
    unsigned int vva_result;

    //code 
    printf("\n\n");
    printf("Enter an Integer = ");
    scanf("%u", &vva_a);

    printf("\n\n");
    printf("By how many bits do you want to shift A = %d to right?", vva_a);
    scanf("%u", &vva_num_bits);

    printf("\n\n\n\n");
    vva_result = vva_a >> vva_num_bits;
    printf("Bitwise right shift of A = %d by %d bits gives the result = %d (Decimal).\n\n", vva_a, vva_num_bits, vva_result);

    PrintBinaryFormOfNumber(vva_a);
    PrintBinaryFormOfNumber(vva_result);

    return (0);
}

void PrintBinaryFormOfNumber(unsigned int decimal_number)
{
    //variable declarations 
    unsigned int quotient, remainder;
    unsigned int num;
    unsigned int binary_array[8];
    int i;

    //code
    for (i = 0; i < 8; i++)
        binary_array[i] = 0;

    printf("The binary form of decimal integer %d is \t=\t", decimal_number);
    num = decimal_number;
    i = 7;
    while (num != 0)
    {
        quotient = num/2;
        remainder = num%2;
        binary_array[i] = remainder;
        num = quotient;
        i--;
    }    

    for ( i = 0; i < 8; i++)
        printf("%u", binary_array[i]);

    printf("\n\n");
}