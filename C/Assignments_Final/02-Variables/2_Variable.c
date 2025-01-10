#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vva = 5;
    float f_vva = 3.9f;
    double d_vva = 8.041997;
    char c_vva = 'A';

    // code
    printf("\n\n");

    printf("i = %d\n", i_vva);
    printf("f = %f\n", f_vva);
    printf("d = %lf\n", d_vva);
    printf("c = %c\n", c_vva);

    printf("\n\n");

    i_vva = 43;
    f_vva = 6.54;
    d_vva = 26.1294;
    c_vva = 'P';

    printf("i = %d\n", i_vva);
    printf("f = %f\n", f_vva);
    printf("d = %lf\n", d_vva);
    printf("c = %c\n", c_vva);

    printf("\n\n");    
    
    return (0);
}
