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

void PrintBinaryFormOfnumber_vva(unsigned int decimal_num_vvaber)
{
    //variable declaration
    unsigned int quotient_vva, remainder_vva;
    unsigned int num_vva;
    unsigned int binary_array_vva[8];
    int i;
    for (i = 0; i < 8; i++)
        binary_array_vva[i] = 0;

    printf("The binary form of decimal integer is %d \t=\t", decimal_num_vvaber);
    num_vva = decimal_num_vvaber;
    i = 7;
    while (num_vva != 0)
    {
        quotient_vva = num_vva /2;
        remainder_vva = num_vva % 2;
        binary_array_vva[i] = remainder_vva;
        num_vva = quotient_vva;
        i--;
    }

    for (i = 0; i < 8; i++)
        printf("%u", binary_array_vva[i]);

    printf("\n\n");
}