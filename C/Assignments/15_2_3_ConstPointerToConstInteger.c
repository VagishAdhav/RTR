#include <stdio.h>

int main(void)
{
    // variable declaration
    int vva_num_vva = 5;
    const int* const vva_ptr = &vva_num_vva; // read this line from right to left => "vva_ptr is a constant pointer to a constant integer"

    // code
    printf("\n");
    printf("Current value of 'num_vva' = %d\n", vva_num_vva);
    printf("Current 'vva_ptr' (Address of 'vva_num_vva')  = %p\n", vva_ptr);

    // the following line does NOT give error .. as we are modifying the value of the variable individually
    vva_num_vva++;
    printf("\n\n");
    printf("After vva_num_vva++, value of 'vva_num_vva' = %d\n", vva_num_vva);

    // the following line give error so commented out
    // we cannot alter the value of vva_ptr as it is a constant
    // uncomment ot see the error

    // vva_ptr++;

    // the following line give error so commented out
    // we cannot alter the value stored in location where pointer to constant integer points.
    // uncomment ot see the error

    // /(*vva_ptr)++;

    return (0);
}