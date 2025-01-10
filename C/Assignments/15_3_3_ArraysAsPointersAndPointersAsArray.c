#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vvaArray[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *ptr_i_vvaArray = NULL; // integer pointer
    
    // code
    // using array name as pointer get values and address of each element
    printf("\n\n");
    printf("*** Using Array name as pointer to access array elements and their address ***\n\n");
    printf("Integer array elements and the address they occupy are as follows : \n\n");
    printf("*(i_vvaArray + 0) = %d \t at address (i_vvaArray + 0) : %p \n", *(i_vvaArray + 0), (i_vvaArray +0));
    printf("*(i_vvaArray + 1) = %d \t at address (i_vvaArray + 1) : %p \n", *(i_vvaArray + 1), (i_vvaArray +1));
    printf("*(i_vvaArray + 2) = %d \t at address (i_vvaArray + 2) : %p \n", *(i_vvaArray + 2), (i_vvaArray +2));
    printf("*(i_vvaArray + 3) = %d \t at address (i_vvaArray + 3) : %p \n", *(i_vvaArray + 3), (i_vvaArray +3));
    printf("*(i_vvaArray + 4) = %d \t at address (i_vvaArray + 4) : %p \n", *(i_vvaArray + 4), (i_vvaArray +4));
    printf("*(i_vvaArray + 5) = %d \t at address (i_vvaArray + 5) : %p \n", *(i_vvaArray + 5), (i_vvaArray +5));
    printf("*(i_vvaArray + 6) = %d \t at address (i_vvaArray + 6) : %p \n", *(i_vvaArray + 6), (i_vvaArray +6));
    printf("*(i_vvaArray + 7) = %d \t at address (i_vvaArray + 7) : %p \n", *(i_vvaArray + 7), (i_vvaArray +7));
    printf("*(i_vvaArray + 8) = %d \t at address (i_vvaArray + 8) : %p \n", *(i_vvaArray + 8), (i_vvaArray +8));
    printf("*(i_vvaArray + 9) = %d \t at address (i_vvaArray + 9) : %p \n", *(i_vvaArray + 9), (i_vvaArray +9));

    // assigning base address of i_vvaArray to integer pointer ptr_i_vvaArray
    // name if the array is its base address
    ptr_i_vvaArray = i_vvaArray; // same as ptr_i_vvaArray = &i_vvaArray[0]

    printf("\n\n");
    printf("*** Using pointer as array name to access array elements and their address ***\n\n");
    printf("Integer array elements and the address they occupy are as follows : \n\n");
    printf("ptr_i_vvaArray[0] = %d \t at address &ptr_i_vvaArray[0] : %p \n", ptr_i_vvaArray[0], &ptr_i_vvaArray[0]);
    printf("ptr_i_vvaArray[1] = %d \t at address &ptr_i_vvaArray[1] : %p \n", ptr_i_vvaArray[1], &ptr_i_vvaArray[1]);
    printf("ptr_i_vvaArray[2] = %d \t at address &ptr_i_vvaArray[2] : %p \n", ptr_i_vvaArray[2], &ptr_i_vvaArray[2]);
    printf("ptr_i_vvaArray[3] = %d \t at address &ptr_i_vvaArray[3] : %p \n", ptr_i_vvaArray[3], &ptr_i_vvaArray[3]);
    printf("ptr_i_vvaArray[4] = %d \t at address &ptr_i_vvaArray[4] : %p \n", ptr_i_vvaArray[4], &ptr_i_vvaArray[4]);
    printf("ptr_i_vvaArray[5] = %d \t at address &ptr_i_vvaArray[5] : %p \n", ptr_i_vvaArray[5], &ptr_i_vvaArray[5]);
    printf("ptr_i_vvaArray[6] = %d \t at address &ptr_i_vvaArray[6] : %p \n", ptr_i_vvaArray[6], &ptr_i_vvaArray[6]);
    printf("ptr_i_vvaArray[7] = %d \t at address &ptr_i_vvaArray[7] : %p \n", ptr_i_vvaArray[7], &ptr_i_vvaArray[7]);
    printf("ptr_i_vvaArray[8] = %d \t at address &ptr_i_vvaArray[8] : %p \n", ptr_i_vvaArray[8], &ptr_i_vvaArray[8]);
    printf("ptr_i_vvaArray[9] = %d \t at address &ptr_i_vvaArray[9] : %p \n", ptr_i_vvaArray[9], &ptr_i_vvaArray[9]);

    return (0);
}