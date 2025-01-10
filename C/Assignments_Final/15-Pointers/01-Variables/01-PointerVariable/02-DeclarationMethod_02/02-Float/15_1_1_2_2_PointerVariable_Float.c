#include <stdio.h>

int main(void)
{
    // variable declaration
    float num_vva;
    float* vva_ptr = NULL; // declaration method 2, vva_ptr is a variable of type float*

    //code
    num_vva = 6.9f;
    
    printf("\n\n");

    printf("***** BEFORE vva_ptr = &num_vva *******\n\n");
    printf("Value of 'num_vva'              = %f\n\n", num_vva);
    printf("Address of 'num_vva'            = %p\n\n", &num_vva);
    printf("Values at address of 'num_vva'  = %f\n\n", *(&num_vva));

    // assigning address of variable 'num_vva' to a pointer variable 'vva_ptr'
    // vva_ptr now contains address of 'num_vva' 
    vva_ptr = &num_vva;

    printf("\n\n");

    printf("***** AFTER vva_ptr = &num_vva *******\n\n");
    printf("Value of 'num_vva'              = %f\n\n", num_vva);
    printf("Address of 'num_vva'            = %p\n\n", vva_ptr);
    printf("Values at address of 'num_vva'  = %f\n\n", *vva_ptr);

    return (0);
}