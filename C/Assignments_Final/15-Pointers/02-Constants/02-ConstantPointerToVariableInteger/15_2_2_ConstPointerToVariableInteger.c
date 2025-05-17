#include <stdio.h>

int main(void)
{
    // variable declaration
    int num_vva = 5;
    int* const vva_ptr = &num_vva; // read this line from right to left => "vva_ptr is a constant pointer to integer"

    // code
    printf("\n");
    printf("Current value of 'num_vva' = %d\n", num_vva);
    printf("Current 'vva_ptr' (Address of 'num_vva')  = %p\n", vva_ptr);

    // the following line does NOT give error .. as we are modifying the value of the variable individually
    num_vva++;
    printf("\n\n");
    printf("After num_vva++, value of 'num_vva' = %d\n", num_vva);

    // the following line give error so commented out
    // we cannot alter the value of vva_ptr as it is a constant
    // uncomment ot see the error

    // vva_ptr++;

    // The following line does not give error
    // we do not get error becaus we are changing the value pointed by the constant pointer which is not constant
    // the pointer is constant. The value to which the pointer points is not constant
    (*vva_ptr)++;

    printf("\n\n");
    printf("After (*vva_ptr)++ value of 'vva_ptr' = %p\n", vva_ptr);
    printf("Value at this new 'vva_ptr' = %d\n", *vva_ptr);
    printf("\n");

    return (0);
}