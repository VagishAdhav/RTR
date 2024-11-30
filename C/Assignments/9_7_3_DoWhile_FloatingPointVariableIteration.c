#include <stdio.h>

int main(void)
{
    // variable declaration
    float vva_f;
    float vva_f_num = 1.7f; // change this value to get different outputs

    //code 
    printf("\n\n");

    printf("Printing Numbers %f to %f : \n\n", vva_f_num, (vva_f_num * 10.0f));

    vva_f = vva_f_num;
    
    do
    {
        printf("\t%f\n", vva_f);
        vva_f = vva_f + vva_f_num;
    }while(vva_f <= (vva_f_num * 10.0f));

    printf("\n\n");

    return (0);
}
