#include <stdio.h>

int main(void)
{
    //function prototype
    void PrintBinaryFormOfNumber(unsigned int);

    //variable declaration
    unsigned int a;
    unsigned int num_bits;
    unsigned int result;

    //code 
    printf("\n\n") ;
    printf("Enter an integer = ");
    scanf("%u", &a);

    printf("\n\n");
    printf("By how many bits do you want to shift A = %d to left ? ", a);
    scanf("%u", &num_bits);

    result = a << num_bits;
    printf("\n\n\n\n");
    printf("Bitwise left shift by %d bits of A = %d gives the result = %d(Decimal).\n\n", a, num_bits, result);

    PrintBinaryFormOfNumber(a);
    PrintBinaryFormOfNumber(result);

    return(0);

}

void PrintBinaryFormOfNumber(unsigned int vva_decimal_number)
{
    //variable declaration
    unsigned int vva_quotient, vva_remainder;
    unsigned int vva_num;
    unsigned int vva_binary_array[8];
    int i;

    //code 
    for (i = 0; i < 8; i++)
    {
        vva_binary_array[i] = 0;
    }
    printf("The binary form of decimal integer %d is \t=\t", vva_decimal_number);

    vva_num = vva_decimal_number;
    i = 7;
    while (vva_num != 0)
    {
        vva_quotient = vva_num / 2;
        vva_remainder = vva_num % 2;
        vva_binary_array[i] = vva_remainder;
        vva_num = vva_quotient;
        i--;
    }

    for ( i = 0; i < 8; i++)
        printf("%u", vva_binary_array[i]);

    printf("\n\n");

}   
