#include <stdio.h>

int main(void)
{
    //variable declaration
    int num_vva;
    int *vva_ptr = NULL;
    int *copy_ptr = NULL;

    //code
    num_vva = 5;
    vva_ptr = &num_vva;

    printf("\n\n");
    printf("******* BEFORE copy_ptr = vva_ptr ******\n\n");
    printf("  num_vva       = %d\n", num_vva);
    printf("  &num_vva      = %p\n", &num_vva);
    printf("  *(&num_vva)   = %d\n", *(&num_vva));
    printf("  vva_ptr       = %p\n", vva_ptr);
    printf("  *vva_ptr      = %d\n", *vva_ptr);

    // 'vva_ptr' is an integer variable .. that is it can hold address of any integer variable only
    // 'copy_ptr'is another integer pointer variable
    // if vva_ptr = &num_vva...'vva_ptr' will contain address of integer variable 'num_vva'
    // if 'vva_ptr' is assigned to 'copy_ptr', 'copy_ptr' will also contain address of integer variable num_vva

    copy_ptr = vva_ptr;

    printf("\n\n");
    printf("******* AFTER copy_ptr = vva_ptr ******\n\n");
    printf("  num_vva       = %d\n", num_vva);
    printf("  &num_vva      = %p\n", &num_vva);
    printf("  *(&num_vva)   = %d\n", *(&num_vva));
    printf("  vva_ptr       = %p\n", vva_ptr);
    printf("  *vva_ptr      = %d\n", *vva_ptr);
    printf("  copy_ptr       = %p\n", copy_ptr);
    printf("  *copy_ptr      = %d\n", *copy_ptr);

    return (0);
}