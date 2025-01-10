#include <stdio.h>

int main(void)
{
    //code
    printf("\n\n");
    printf("***********************************************************");
    printf("\n\n");

    printf("Hello World !!! \n\n");

    int a_vva = 13;
    printf("Integer decimal value of 'a_vva' = %d\n",a_vva);
    printf("Integer octal value of 'a_vva' = %o\n", a_vva);
    printf("Integer hexadecimal Value of 'a_vva' (hexadecimal letters in lower case) = %x\n", a_vva);
    printf("Integer hexadecimal value of 'a_vva' (hexadecimal letters in upper case) = %X\n\n", a_vva);

    char ch_vva = 'A';
    printf("Character ch = %c\n", ch_vva);
    char str[] = "AstriMediComp's Real Time Rendering Batch 6";
    printf("String str = %s\n\n", str);

    long num_vva = 30121995L;
    printf("Long Integer = %ld\n\n", num_vva);

    unsigned int b_vva = 7;
    printf("Unsigned Integer = 'b' = %u\n\n", b_vva);

    float f_num_vva_vva = 3012.1995f;
    printf("Floating point number with just %%f 'f_num_vva_vva' = %f\n", f_num_vva_vva);
    printf("Floating point number with %%4.2f 'f_num_vva_vva' = %4.2f\n", f_num_vva_vva);
    printf("Floating point number with %%6.5f 'f_num_vva_vva' = %6.5f\n", f_num_vva_vva);

    float d_pi_vva = 3.14159265358979323846;
    printf("Double precision floating point number without exponential = %g\n", d_pi_vva);
    printf("Double precision floating point number with exponential (lower case) = %e\n", d_pi_vva);
    printf("Double precision floating point number with exponential (upper case) = %E\n\n", d_pi_vva);
    printf("Double hexadecimal value of 'd_pi_vva' (hexadecimal letters in lower case) = %a_vva\n", d_pi_vva);
    printf("Double hexadecimal value of 'd_pi_vva' (hexadecimal letters in upper case) = %A\n\n", d_pi_vva);

    printf("***********************************************************");
    printf("\n\n");

    return (0);
}   


