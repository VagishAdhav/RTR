#include <stdio.h>

int main(void)
{
    // variable declaration
    int vva_i = 5;
    float vva_f = 3.9f;
    double vva_d = 8.041997;
    char vva_c = 'A';

    // code
    printf("\n\n");

    printf("vva_i = %d\n", vva_i);
    printf("vva_f = %f\n", vva_f);
    printf("vva_d = %lf\n", vva_d);
    printf("vva_c = %c\n", vva_c);

    printf("\n\n");

    vva_i = 43;
    vva_f = 6.54;
    vva_d = 26.1294;
    vva_c = 'P';

    printf("i = %d\n", vva_i);
    printf("f = %f\n", vva_f);
    printf("d = %lf\n", vva_d);
    printf("c = %c\n", vva_c);

    printf("\n\n");    
    
    return (0);
}
