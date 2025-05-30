#include <stdio.h>

int main(void)
{
    // variable declaration
    float vva_num_vva;
    float* vva_ptr = NULL; // declaration method 2, vva_ptr is a variable of type float*

    //code
    vva_num_vva = 6.9f;
    
    printf("\n\n");

    printf("***** BEFORE vva_ptr = &vva_num_vva *******\n\n");
    printf("Value of 'vva_num_vva'              = %f\n\n", vva_num_vva);
    printf("Address of 'vva_num_vva'            = %p\n\n", &vva_num_vva);
    printf("Values at address of 'vva_num_vva'  = %f\n\n", *(&vva_num_vva));

    // assigning address of variable 'vva_num_vva' to a pointer variable 'vva_ptr'
    // vva_ptr now contains address of 'vva_num_vva' 
    vva_ptr = &vva_num_vva;

    printf("\n\n");

    printf("***** AFTER vva_ptr = &vva_num_vva *******\n\n");
    printf("Value of 'vva_num_vva'              = %f\n\n", vva_num_vva);
    printf("Address of 'vva_num_vva'            = %p\n\n", vva_ptr);
    printf("Values at address of 'vva_num_vva'  = %f\n\n", *vva_ptr);

    return (0);
}