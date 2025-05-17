#include <stdio.h>

int main(void)
{
    // variable declaration
    float f_vva;
    float f_num_vva = 1.7f; // change this value to get different outputs

    //code 
    printf("\n\n");

    printf("Printing numbers %f to %f : \n\n", f_num_vva, (f_num_vva * 10.0f));

    f_vva = f_num_vva;
    
    do
    {
        printf("\t%f\n", f_vva);
        f_vva = f_vva + f_num_vva;
    }while(f_vva <= (f_num_vva * 10.0f));

    printf("\n\n");

    return (0);
}
