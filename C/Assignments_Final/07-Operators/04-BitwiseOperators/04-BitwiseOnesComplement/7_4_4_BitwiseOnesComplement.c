#include <stdio.h>

int main(void)
{
    //function prototypes 
    void PrintBinaryFormOfnumber_vva(unsigned int);

    //variable declarations
    unsigned int a_vva;
    unsigned int result_vva;

    //code
    printf("\n\n");
    printf("Enter an integer = ");
    scanf("%u", &a_vva);

    printf("\n\n\n\n");
    result_vva = ~a_vva;
    printf("Bitwise Complementing of \nA = %d (Decimal) gives result %d (Decimal). \n\n", a_vva, result_vva);
    PrintBinaryFormOfnumber_vva(a_vva);
    PrintBinaryFormOfnumber_vva(result_vva);

    return (0);
}

void PrintBinaryFormOfnumber_vva(unsigned int decimal_number_vva)
{
    //variable declaration
    unsigned int vva_quotient_vva, vva_remainder;
    unsigned int num_vva;
    unsigned int binary_array_vva[8];
    unsigned int i_vva;

    for (i_vva = 0; i_vva < 8; i_vva++)
        binary_array_vva[i_vva] = 0;

    printf("The binary form of the decimal integer %d is \t=\t", decimal_number_vva);
    num_vva = decimal_number_vva;
    i_vva = 7;

    while (num_vva != 0)
    {
        vva_quotient_vva = num_vva / 2;
        vva_remainder = num_vva % 2;
        binary_array_vva[i_vva] = vva_remainder;
        num_vva = vva_quotient_vva;
        i_vva--;    
    }

    for (i_vva = 0; i_vva < 8; i_vva++)
        printf("%u", binary_array_vva[i_vva]);

    printf("\n\n");
}