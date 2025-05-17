#include <stdio.h>

int main(void)
{
    // variable declaration
    int iArray_vva[] = {12, 24, 36, 48, 60, 72, 84, 96, 108, 120};
    float fArray_vva[] = {9.8f, 8.7f, 7.6f, 6.5f, 5.4f};
    double dArray_vva[] = {1.222222, 2.333333, 3.444444 };
    char cArray_vva[] = {'A','S','T','R','O','M','E','D','I','C','O','M','P','\0'};

    // code
    printf("\n\n");
    printf("Integer array elements and the address they occupy are as follows : \n\n");
    printf("iArray_vva[0] = %d \t at address : %p \n", *(iArray_vva + 0), (iArray_vva + 0));
    printf("iArray_vva[1] = %d \t at address : %p \n", *(iArray_vva + 1), (iArray_vva + 1));
    printf("iArray_vva[2] = %d \t at address : %p \n", *(iArray_vva + 2), (iArray_vva + 2));
    printf("iArray_vva[3] = %d \t at address : %p \n", *(iArray_vva + 3), (iArray_vva + 3));
    printf("iArray_vva[4] = %d \t at address : %p \n", *(iArray_vva + 4), (iArray_vva + 4));
    printf("iArray_vva[5] = %d \t at address : %p \n", *(iArray_vva + 5), (iArray_vva + 5));
    printf("iArray_vva[6] = %d \t at address : %p \n", *(iArray_vva + 6), (iArray_vva + 6));
    printf("iArray_vva[7] = %d \t at address : %p \n", *(iArray_vva + 7), (iArray_vva + 7));
    printf("iArray_vva[8] = %d \t at address : %p \n", *(iArray_vva + 8), (iArray_vva + 8));
    printf("iArray_vva[9] = %d \t at address : %p \n", *(iArray_vva + 9), (iArray_vva + 9));

    printf("\n\n");
    printf("Float array elements and the address they occupy are as follows : \n\n");
    printf("fArray_vva[0] = %f \t at address : %p \n", *(fArray_vva + 0), (fArray_vva + 0));
    printf("fArray_vva[1] = %f \t at address : %p \n", *(fArray_vva + 1), (fArray_vva + 1));
    printf("fArray_vva[2] = %f \t at address : %p \n", *(fArray_vva + 2), (fArray_vva + 2));
    printf("fArray_vva[3] = %f \t at address : %p \n", *(fArray_vva + 3), (fArray_vva + 3));
    printf("fArray_vva[4] = %f \t at address : %p \n", *(fArray_vva + 4), (fArray_vva + 4));
    
    printf("\n\n");
    printf("Double array elements and the address they occupy are as follows : \n\n");
    printf("dArray_vva[0] = %lf \t at address : %p \n", *(dArray_vva + 0), (dArray_vva + 0));
    printf("dArray_vva[1] = %lf \t at address : %p \n", *(dArray_vva + 1), (dArray_vva + 1));
    printf("dArray_vva[2] = %lf \t at address : %p \n", *(dArray_vva + 2), (dArray_vva + 2));

    printf("\n\n");
    printf("Character array elements and the address they occupy are as follows : \n\n");
    printf("cArray_vva[0] = %c \t at address : %p \n", *(cArray_vva + 0), (cArray_vva + 0));
    printf("cArray_vva[1] = %c \t at address : %p \n", *(cArray_vva + 1), (cArray_vva + 1));
    printf("cArray_vva[2] = %c \t at address : %p \n", *(cArray_vva + 2), (cArray_vva + 2));
    printf("cArray_vva[3] = %c \t at address : %p \n", *(cArray_vva + 3), (cArray_vva + 3));
    printf("cArray_vva[4] = %c \t at address : %p \n", *(cArray_vva + 4), (cArray_vva + 4));
    printf("cArray_vva[5] = %c \t at address : %p \n", *(cArray_vva + 5), (cArray_vva + 5));
    printf("cArray_vva[6] = %c \t at address : %p \n", *(cArray_vva + 6), (cArray_vva + 6));
    printf("cArray_vva[7] = %c \t at address : %p \n", *(cArray_vva + 7), (cArray_vva + 7));
    printf("cArray_vva[8] = %c \t at address : %p \n", *(cArray_vva + 8), (cArray_vva + 8));
    printf("cArray_vva[9] = %c \t at address : %p \n", *(cArray_vva + 9), (cArray_vva + 9));
    printf("cArray_vva[10] = %c \t at address : %p \n", *(cArray_vva + 10), (cArray_vva + 10));
    printf("cArray_vva[11] = %c \t at address : %p \n", *(cArray_vva + 11), (cArray_vva + 11));
    printf("cArray_vva[12] = %c \t at address : %p \n", *(cArray_vva + 12), (cArray_vva + 12));
    printf("cArray_vva[13] = %c \t at address : %p \n", *(cArray_vva + 13), (cArray_vva + 13));

    return (0);
}