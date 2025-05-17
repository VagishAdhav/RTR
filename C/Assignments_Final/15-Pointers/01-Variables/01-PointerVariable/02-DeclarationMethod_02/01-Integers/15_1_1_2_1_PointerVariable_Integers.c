#include <stdio.h>

int main(void)
{
    // variable declaration
    int num_vva;
    int* vva_ptr = NULL; // declaration method 2, vva_ptr is a variable of type integer pointer (int*)

    //code
    num_vva = 10;
    
    printf("\n\n");

    printf("***** BEFORE vva_ptr = &num_vva *******\n\n");
    printf("Value of 'num_vva'              = %d\n\n", num_vva);
    printf("Address of 'num_vva'            = %p\n\n", &num_vva);
    printf("Values at address of 'num_vva'  = %d\n\n", *(&num_vva));

    // assigning address of variable 'num_vva' to a pointer variable 'vva_ptr'
    // vva_ptr now contains address of 'num_vva' 
    vva_ptr = &num_vva;

    printf("\n\n");

    printf("***** AFTER vva_ptr = &num_vva *******\n\n");
    printf("Value of 'num_vva'              = %d\n\n", num_vva);
    printf("Address of 'num_vva'            = %p\n\n", vva_ptr);
    printf("Values at address of 'num_vva'  = %d\n\n", *vva_ptr);

    return (0);
}