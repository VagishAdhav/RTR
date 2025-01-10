#include <stdio.h>

int main(void)
{
    // variable declaration
    int iArray_vva[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *ptr_iArray_vva = NULL; // integer pointer
    
    // code
    // using array name to get values and address of each element
    printf("\n\n");
    printf("*** Using Array name to access array elements and their address ***\n\n");
    printf("Integer array elements and their address are as follows : \n\n");
    printf("iArray_vva[0] = %d \t at address &iArray_vva[0] : %p \n", iArray_vva[0], &iArray_vva[0]);
    printf("iArray_vva[1] = %d \t at address &iArray_vva[1] : %p \n", iArray_vva[1], &iArray_vva[1]);
    printf("iArray_vva[2] = %d \t at address &iArray_vva[2] : %p \n", iArray_vva[2], &iArray_vva[2]);
    printf("iArray_vva[3] = %d \t at address &iArray_vva[3] : %p \n", iArray_vva[3], &iArray_vva[3]);
    printf("iArray_vva[4] = %d \t at address &iArray_vva[4] : %p \n", iArray_vva[4], &iArray_vva[4]);
    printf("iArray_vva[5] = %d \t at address &iArray_vva[5] : %p \n", iArray_vva[5], &iArray_vva[5]);
    printf("iArray_vva[6] = %d \t at address &iArray_vva[6] : %p \n", iArray_vva[6], &iArray_vva[6]);
    printf("iArray_vva[7] = %d \t at address &iArray_vva[7] : %p \n", iArray_vva[7], &iArray_vva[7]);
    printf("iArray_vva[8] = %d \t at address &iArray_vva[8] : %p \n", iArray_vva[8], &iArray_vva[8]);
    printf("iArray_vva[9] = %d \t at address &iArray_vva[9] : %p \n", iArray_vva[9], &iArray_vva[9]);

    // assigning base address of iArray_vva to integer pointer ptr_iArray_vva
    // name if the array is its base address
    ptr_iArray_vva = iArray_vva; // same as ptr_iArray_vva = &iArray_vva[0]

    printf("\n\n");
    printf("*** Using pointer to access array elements and their address ***\n\n");
    printf("Integer array elements and their address are as follows : \n\n");;
    printf("*(ptr_iArray_vva + 0) = %d \t at address (ptr_iArray_vva + 0) : %p \n", *(ptr_iArray_vva + 0), (ptr_iArray_vva + 0));
    printf("*(ptr_iArray_vva + 1) = %d \t at address (ptr_iArray_vva + 1) : %p \n", *(ptr_iArray_vva + 1), (ptr_iArray_vva + 1));
    printf("*(ptr_iArray_vva + 2) = %d \t at address (ptr_iArray_vva + 2) : %p \n", *(ptr_iArray_vva + 2), (ptr_iArray_vva + 2));
    printf("*(ptr_iArray_vva + 3) = %d \t at address (ptr_iArray_vva + 3) : %p \n", *(ptr_iArray_vva + 3), (ptr_iArray_vva + 3));
    printf("*(ptr_iArray_vva + 4) = %d \t at address (ptr_iArray_vva + 4) : %p \n", *(ptr_iArray_vva + 4), (ptr_iArray_vva + 4));
    printf("*(ptr_iArray_vva + 5) = %d \t at address (ptr_iArray_vva + 5) : %p \n", *(ptr_iArray_vva + 5), (ptr_iArray_vva + 5));
    printf("*(ptr_iArray_vva + 6) = %d \t at address (ptr_iArray_vva + 6) : %p \n", *(ptr_iArray_vva + 6), (ptr_iArray_vva + 6));
    printf("*(ptr_iArray_vva + 7) = %d \t at address (ptr_iArray_vva + 7) : %p \n", *(ptr_iArray_vva + 7), (ptr_iArray_vva + 7));
    printf("*(ptr_iArray_vva + 8) = %d \t at address (ptr_iArray_vva + 8) : %p \n", *(ptr_iArray_vva + 8), (ptr_iArray_vva + 8));
    printf("*(ptr_iArray_vva + 9) = %d \t at address (ptr_iArray_vva + 9) : %p \n", *(ptr_iArray_vva + 9), (ptr_iArray_vva + 9));

    return (0);
}