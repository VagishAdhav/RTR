#include <stdio.h>

int main(void)
{
    //variable declaration 
    float vva_f;
    float vva_f_num = 1.7f; // change this value to get different outputs

    //code
    printf("\n\n");

    printf("Printing numbers %f to %f : \n\n", vva_f_num, (vva_f_num * 10.0f));

    for (vva_f = vva_f_num; vva_f <= (vva_f_num * 10.0f); vva_f = vva_f + vva_f_num)
    {
        printf("\t%f\n", vva_f);
    }

    printf("\n\n");

    return (0);
}