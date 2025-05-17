#include <stdio.h>

int main(void)
{
    // variable declaration
    double num_vva;
    double *vva_ptr = NULL; // declaration method 1, *vva_ptr is a variable of type double

    //code
    num_vva = 2.34343434f;
    
    printf("\n\n");

    printf("***** BEFORE vva_ptr = &num_vva *******\n\n");
    printf("Value of 'num_vva'              = %lf\n\n", num_vva);
    printf("Address of 'num_vva'            = %p\n\n", &num_vva);
    printf("Values at address of 'num_vva'  = %lf\n\n", *(&num_vva));

    // assigning address of variable 'num_vva' to a pointer variable 'vva_ptr'
    // vva_ptr now contains address of 'num_vva' 
    vva_ptr = &num_vva;

    printf("\n\n");

    printf("***** AFTER vva_ptr = &num_vva *******\n\n");
    printf("Value of 'num_vva'              = %lf\n\n", num_vva);
    printf("Address of 'num_vva'            = %p\n\n", vva_ptr);
    printf("Values at address of 'num_vva'  = %lf\n\n", *vva_ptr);

    return (0);
}