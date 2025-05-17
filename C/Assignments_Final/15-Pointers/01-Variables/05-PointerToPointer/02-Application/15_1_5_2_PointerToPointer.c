#include <stdio.h>

int main(void)
{
    // variable declaration
    int num_vva;
    int *vva_ptr = NULL;
    int **vva_pptr = NULL; // declaration method 1 : **pptr is a variable of type pointer to pointer to integer

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

    // assigning address of variable 'vva_ptr ' to pointer to pointer variable 'pptr'
    // 'vva_pptr' now contains address of vva_ptr which in turn contains address of num_vva

    vva_pptr = &vva_ptr;

    printf("\n\n");

    printf("***** AFTER vva_pptr = &num_vva *******\n\n");
    printf("Value of 'num_vva'              = %d\n\n", num_vva);
    printf("Address of 'num_vva' (vva_ptr)   = %p\n\n", vva_ptr);
    printf("Address of 'vva_ptr' (vva_pptr)   = %p\n\n", vva_pptr);
    printf("Values at address of 'ptr' (*pptr)  = %p\n\n", *vva_pptr);
    printf("Values at address of 'num_vva' (**pptr)  = %d\n\n", **vva_pptr);

    return (0);
}