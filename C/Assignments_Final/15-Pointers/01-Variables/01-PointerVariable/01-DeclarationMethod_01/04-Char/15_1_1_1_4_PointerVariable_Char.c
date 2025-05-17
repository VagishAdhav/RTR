#include <stdio.h>

int main(void)
{
    // variable declaration
    char ch_vva;
    char *vva_ptr = NULL; // declaration method 1, *vva_ptr is a variable of type char

    //code
    ch_vva = 'A';
    
    printf("\n\n");

    printf("***** BEFORE vva_ptr = &ch_vva *******\n\n");
    printf("Value of 'ch_vva'              = %c\n\n", ch_vva);
    printf("Address of 'ch_vva'            = %p\n\n", &ch_vva);
    printf("Values at address of 'ch_vva'  = %c\n\n", *(&ch_vva));

    // assigning address of variable 'ch_vva' to a pointer variable 'vva_ptr'
    // vva_ptr now contains address of 'ch_vva' 
    vva_ptr = &ch_vva;

    printf("\n\n");

    printf("***** AFTER vva_ptr = &ch_vva *******\n\n");
    printf("Value of 'ch_vva'              = %c\n\n", ch_vva);
    printf("Address of 'ch_vva'            = %p\n\n", vva_ptr);
    printf("Values at address of 'ch_vva'  = %c\n\n", *vva_ptr);

    return (0);
}