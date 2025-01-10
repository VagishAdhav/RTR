#include <stdio.h>

int main(void)
{
    //function prototype
    void PrintBinaryFormOfnumber_vva(unsigned int);

    //variable declaration
    unsigned int a;
    unsigned int numbits_vva;
    unsigned int result;

    //code 
    printf("\n\n") ;
    printf("Enter an integer = ");
    scanf("%u", &a);

    printf("\n\n");
    printf("By how many bits do you want to shift A = %d to left ? ", a);
    scanf("%u", &numbits_vva);

    result = a << numbits_vva;
    printf("\n\n\n\n");
    printf("Bitwise left shift by %d bits of A = %d gives the result = %d(Decimal).\n\n", a, numbits_vva, result);

    PrintBinaryFormOfnumber_vva(a);
    PrintBinaryFormOfnumber_vva(result);

    return(0);

}

void PrintBinaryFormOfnumber_vva(unsigned int d_vvaecimal_num_vvaber)
{
    //variable declaration
    unsigned int vva_quotient_vva, vva_remainder_vva;
    unsigned int vva_num_vva;
    unsigned int binary_array_vva[8];
    int i;

    //code 
    for (i = 0; i < 8; i++)
    {
        binary_array_vva[i] = 0;
    }
    printf("The binary form of decimal integer %d is \t=\t", d_vvaecimal_num_vvaber);

    vva_num_vva = d_vvaecimal_num_vvaber;
    i = 7;
    while (vva_num_vva != 0)
    {
        vva_quotient_vva = vva_num_vva / 2;
        vva_remainder_vva = vva_num_vva % 2;
        binary_array_vva[i] = vva_remainder_vva;
        vva_num_vva = vva_quotient_vva;
        i--;
    }

    for ( i = 0; i < 8; i++)
        printf("%u", binary_array_vva[i]);

    printf("\n\n");

}   
