#include <stdio.h>

int main(void)
{
    //function prototypes
    void PrintBinaryFormOfnumber_vva(unsigned int);

    //variable declarations 
    unsigned int a_vva;
    unsigned int b_vva;
    unsigned int result_vva;

    //code
    printf("\n\n");
    printf("Enter an integer = ");
    scanf("%i=u", &a_vva);

    printf("\n\n");
    printf("Enter another integer = ");
    scanf("%u", &b_vva);

    printf("\n\n\n\n");
    result_vva = a_vva ^ b_vva;
    printf("Bitwise XOR-ing of \nA = %d (Decimal) and B = %d (Decimal) gives result %d (Decimal).\n\n", a_vva, b_vva, result_vva);

    PrintBinaryFormOfnumber_vva(a_vva);
    PrintBinaryFormOfnumber_vva(b_vva);
    PrintBinaryFormOfnumber_vva(result_vva);

    return (0);
}

void PrintBinaryFormOfnumber_vva(unsigned int d_vvaecimal_num_vvaber)
{
    // variable declarations
    unsigned int vva_quotient_vva, vva_remainder_vva;
    unsigned int vva_num_vva;
    unsigned int binary_array_vva[8];
    int i_vva;

    for (i_vva = 0; i_vva < 8; i_vva++)
        binary_array_vva[i_vva] = 0;

    printf("The binary form of the decimal integer %d is \t=\t", d_vvaecimal_num_vvaber);
    vva_num_vva = d_vvaecimal_num_vvaber;
    i_vva = 7;
    while (vva_num_vva != 0)
    {
        vva_quotient_vva = vva_num_vva / 2;
        vva_remainder_vva = vva_num_vva % 2;
        binary_array_vva[i_vva] = vva_remainder_vva;
        vva_num_vva = vva_quotient_vva;
        i_vva--;
    }
    for (i_vva = 0; i_vva < 8; i_vva++)
        printf("%u", binary_array_vva[i_vva]);
    
    printf("\n\n");
}