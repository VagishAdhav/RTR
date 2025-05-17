#include <stdio.h>

int main(void)
{
    //function prototype
    void PrintBinaryFormOfnumber_vva(unsigned int);

    //variable declaration
    unsigned int a_vva;
    unsigned int numbits_vva;
    unsigned int result_vva;

    //code 
    printf("\n\n") ;
    printf("Enter an integer = ");
    scanf("%u", &a_vva);

    printf("\n\n");
    printf("By how many bits do you want to shift A = %d to left ? ", a_vva);
    scanf("%u", &numbits_vva);

    result_vva = a_vva << numbits_vva;
    printf("\n\n\n\n");
    printf("Bitwise left shift by %d bits of A = %d gives the result = %d(Decimal).\n\n", a_vva, numbits_vva, result_vva);

    PrintBinaryFormOfnumber_vva(a_vva);
    PrintBinaryFormOfnumber_vva(result_vva);

    return(0);

}

void PrintBinaryFormOfnumber_vva(unsigned int decimal_number_vva)
{
    //variable declaration
    unsigned int vva_quotient_vva, vva_remainder;
    unsigned int num_vva;
    unsigned int binary_array_vva[8];
    int i;

    //code 
    for (i = 0; i < 8; i++)
    {
        binary_array_vva[i] = 0;
    }
    printf("The binary form of decimal integer %d is \t=\t", decimal_number_vva);

    num_vva = decimal_number_vva;
    i = 7;
    while (num_vva != 0)
    {
        vva_quotient_vva = num_vva / 2;
        vva_remainder = num_vva % 2;
        binary_array_vva[i] = vva_remainder;
        num_vva = vva_quotient_vva;
        i--;
    }

    for ( i = 0; i < 8; i++)
        printf("%u", binary_array_vva[i]);

    printf("\n\n");

}   
