#include <stdio.h>

int main(void)
{
    //variable declarations
    int vva_num_vva;
    int *vva_ptr = NULL;
    int a_vvans;

    //code
    vva_num_vva = 5;
    vva_ptr = &vva_num_vva;

    printf("\n\n");
    printf("  vva_num_vva       = %d\n", vva_num_vva);
    printf("  &vva_num_vva      = %p\n", &vva_num_vva);
    printf("  *(&vva_num_vva)   = %d\n", *(&vva_num_vva));
    printf("  vva_ptr       = %p\n", vva_ptr);
    printf("  *vva_ptr      = %d\n", *vva_ptr);

    printf("\n\n");

    // Add 10 to 'vva_ptr' which is the address of 'vva_num_vva'
    // hence 10 will be added to address of num_vva and resultant will be displayed
    printf("Answer of (vva_ptr + 10) = %p\n", (vva_ptr + 10));

    // Add 10 to 'vva_ptr' which is the address of 'vva_num_vva'
    // hence 10 will be added to address of num_vva and resultant value will be displayed
    printf("Answer of *(vva_ptr + 10) = %d\n", *(vva_ptr + 10));

    // Add 10 to '*vva_ptr' which is the value at address of 'vva_num_vva' i.e. 5
    // hence 10 will be added to *vva_ptr (vva_num_vva = 5) and resultant value will be displayed ( 5 + 10 = 15)
    printf("Answer of (*vva_ptr + 10) = %d\n\n", (*vva_ptr + 10));

    // *** ASSOCIATIVITY OF '*' ( de-reference) and ++,-- is from right to left
    // (RIGHT TO LEFT) consider value *vva_ptr .. pre-increment *vva_ptr.. that is value at address 'vav_ptr' i.e. *vav_ptr is pre-incremented  (++*vav_ptr)
    ++*vva_ptr; // after execution of this statement *ptr will be 6
    printf("Answer of ++*vva_ptr : %d\n", *vva_ptr);


    // (RIGHT TO LEFT) Post increment address of vva_ptr .. That is, address 'vva_ptr' i.e.'  i.e. 'vva_ptr' is post-incremented ( vva_ptr++) and then the value at new address is accessed (*vva_ptr++)
    *vva_ptr++; // incorrect method of post incrementing a value using pointer
    printf("Answer of *vva_ptr++ : %d\n", *vva_ptr); // notice brackets required for post increment/decrement

    // (RIGHT TO LEFT) Post increment *vva_ptr .. That is, value at address 'vva_ptr i.e. *vva_ptr is post incremented *(vva_ptr)++
    vva_ptr = &vva_num_vva;
    (*vva_ptr)++; // correct method of post incrementing a value using pointer, result will be 7
    printf("Answer of (*vva_ptr)++ : %d\n", (*vva_ptr)++); // notice brackets required for post increment/decrement

    return (0);

}