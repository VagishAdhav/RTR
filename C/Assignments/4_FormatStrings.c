#include <stdio.h>

int main(void)
{
    //code
    printf("\n\n");
    printf("***********************************************************");
    printf("\n\n");

    printf("Hello World !!! \n\n");

    int vva_a = 13;
    printf("Integer decimal value of 'a' = %d\n",vva_a);
    printf("Integer octal value of 'a' = %o\n", vva_a);
    printf("Integer hexadecimal Value of 'a' (hexadecimal letters in lower case) = %x\n", vva_a);
    printf("Integer hexadecimal value of 'a' (hexadecimal letters in upper case) = %X\n\n", vva_a);

    char vva_ch = 'A';
    printf("Character ch = %c\n", vva_ch);
    char str[] = "AstriMediComp's Real Time Rendering Batch 6";
    printf("String str = %s\n\n", str);

    long vva_num = 30121995L;
    printf("Long Integer = %ld\n\n", vva_num);

    unsigned int vva_b = 7;
    printf("Unsigned Integer = 'b' = %u\n\n", vva_b);

    float vva_f_num = 3012.1995f;
    printf("Floating point number with just %%f 'vva_f_num' = %f\n", vva_f_num);
    printf("Floating point number with %%4.2f 'vva_f_num' = %4.2f\n", vva_f_num);
    printf("Floating point number with %%6.5f 'vva_f_num' = %6.5f\n", vva_f_num);

    float vva_d_pi = 3.14159265358979323846;
    printf("Double precision floating point number without exponential = %g\n", vva_d_pi);
    printf("Double precision floating point number with exponential (lower case) = %e\n", vva_d_pi);
    printf("Double precision floating point number with exponential (upper case) = %E\n\n", vva_d_pi);
    printf("Double hexadecimal value of 'vva_d_pi' (hexadecimal letters in lower case) = %a\n", vva_d_pi);
    printf("Double hexadecimal value of 'vva_d_pi' (hexadecimal letters in upper case) = %A\n\n", vva_d_pi);

    printf("***********************************************************");
    printf("\n\n");

    return (0);
}   


