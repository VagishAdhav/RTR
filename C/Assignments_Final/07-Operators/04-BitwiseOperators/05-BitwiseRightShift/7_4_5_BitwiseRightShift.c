#include <stdio.h>

int main(void)
{
    //function prototypes
    void PrintBinaryFormOfnumber_vva(unsigned int);

    // variable declaration
    unsigned int a_vva;
    unsigned int vva_num_vva_bits;
    unsigned int result_vva;

    //code 
    printf("\n\n");
    printf("Enter an Integer = ");
    scanf("%u", &a_vva);

    printf("\n\n");
    printf("By how many bits do you want to shift A = %d to right?", a_vva);
    scanf("%u", &vva_num_vva_bits);

    printf("\n\n\n\n");
    result_vva = a_vva >> vva_num_vva_bits;
    printf("Bitwise right shift of A = %d by %d bits gives the result = %d (Decimal).\n\n", a_vva, vva_num_vva_bits, result_vva);

    PrintBinaryFormOfnumber_vva(a_vva);
    PrintBinaryFormOfnumber_vva(result_vva);

    return (0);
}

void PrintBinaryFormOfnumber_vva(unsigned int decimal_number_vva)
{
    //variable declarations 
    unsigned int quotient_vva, remainder;
    unsigned int num_vva;
    unsigned int binary_array_vva[8];
    int i;

    //code
    for (i = 0; i < 8; i++)
        binary_array_vva[i] = 0;

    printf("The binary form of decimal integer %d is \t=\t", decimal_number_vva);
    num_vva = decimal_number_vva;
    i = 7;
    while (num_vva != 0)
    {
        quotient_vva = num_vva/2;
        remainder = num_vva%2;
        binary_array_vva[i] = remainder;
        num_vva = quotient_vva;
        i--;
    }    

    for ( i = 0; i < 8; i++)
        printf("%u", binary_array_vva[i]);

    printf("\n\n");
}