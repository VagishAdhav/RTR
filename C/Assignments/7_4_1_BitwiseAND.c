#include <stdio.h>

int main(void)
{
    //function prototypes
    void PrintBinaryFormOfNumber(unsigned int);

    // variable declaration
    unsigned int vva_a;
    unsigned int vva_b;
    unsigned int vva_result;

    //code 
    printf("\n\n");
    printf("Enter an integer = ");
    scanf("%u", &vva_a);

    printf("\n\n");
    printf("Enter another integer = ");
    scanf("%u", &vva_b);

    printf("\n\n\n\n");
    vva_result = vva_a & vva_b;

    printf("Bitwise AND of \nA = %d (Decimal) and B = %d (Decimal) gives result %d (Decimal). \n\n", vva_a, vva_b, vva_result);

    PrintBinaryFormOfNumber(vva_a);
    PrintBinaryFormOfNumber(vva_b);
    PrintBinaryFormOfNumber(vva_result);

    return (0);
}

void PrintBinaryFormOfNumber(unsigned int vva_decimal_number)
{
    unsigned int vva_quotient, vva_remainder;
    unsigned int vva_num;
    unsigned int vva_binary_array[8];
    int vva_i;
    
    //code
    for (vva_i = 0; vva_i < 8; vva_i++)
        vva_binary_array[vva_i] = 0;

    printf("The binary form of the decimal integer %d is \t=\t", vva_decimal_number);
    vva_num = vva_decimal_number;
    vva_i = 7;
    while (vva_num != 0)
    {
        vva_quotient = vva_num /2;
        vva_remainder = vva_num % 2;
        vva_binary_array[vva_i] = vva_remainder;
        vva_num = vva_quotient;
        vva_i--;
    }

    for (vva_i = 0; vva_i < 8; vva_i++)
        printf("%u", vva_binary_array[vva_i]);

    printf("\n\n");
}