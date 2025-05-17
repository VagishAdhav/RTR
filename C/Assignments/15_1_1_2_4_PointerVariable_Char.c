#include <stdio.h>

int main(void)
{
    // variable declaration
    char c_vvah;
    char* vva_ptr = NULL; // declaration method 2, vva_ptr is a variable of type char*

    //code
    c_vvah = 'Z';
    
    printf("\n\n");

    printf("***** BEFORE vva_ptr = &c_vvah *******\n\n");
    printf("Value of 'c_vvah'              = %c\n\n", c_vvah);
    printf("Address of 'c_vvah'            = %p\n\n", &c_vvah);
    printf("Values at address of 'c_vvah'  = %c\n\n", *(&c_vvah));

    // assigning address of variable 'c_vvah' to a pointer variable 'vva_ptr'
    // vva_ptr now contains address of 'c_vvah' 
    vva_ptr = &c_vvah;

    printf("\n\n");

    printf("***** AFTER vva_ptr = &c_vvah *******\n\n");
    printf("Value of 'c_vvah'              = %c\n\n", c_vvah);
    printf("Address of 'c_vvah'            = %p\n\n", vva_ptr);
    printf("Values at address of 'c_vvah'  = %c\n\n", *vva_ptr);

    return (0);
}