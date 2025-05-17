#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vvaArray[] = {12, 24, 36, 48, 60, 72, 84, 96, 108, 120};
    float f_vvaArray[] = {9.8f, 8.7f, 7.6f, 6.5f, 5.4f};
    double d_vvaArray[] = {1.222222, 2.333333, 3.444444 };
    char c_vvaArray[] = {'A','S','T','R','O','M','E','D','I','C','O','M','P','\0'};

    // code
    printf("\n\n");
    printf("Integer array elements and the address they occupy are as follows : \n\n");
    printf("i_vvaArray[0] = %d \t at address : %p \n", *(i_vvaArray + 0), (i_vvaArray + 0));
    printf("i_vvaArray[1] = %d \t at address : %p \n", *(i_vvaArray + 1), (i_vvaArray + 1));
    printf("i_vvaArray[2] = %d \t at address : %p \n", *(i_vvaArray + 2), (i_vvaArray + 2));
    printf("i_vvaArray[3] = %d \t at address : %p \n", *(i_vvaArray + 3), (i_vvaArray + 3));
    printf("i_vvaArray[4] = %d \t at address : %p \n", *(i_vvaArray + 4), (i_vvaArray + 4));
    printf("i_vvaArray[5] = %d \t at address : %p \n", *(i_vvaArray + 5), (i_vvaArray + 5));
    printf("i_vvaArray[6] = %d \t at address : %p \n", *(i_vvaArray + 6), (i_vvaArray + 6));
    printf("i_vvaArray[7] = %d \t at address : %p \n", *(i_vvaArray + 7), (i_vvaArray + 7));
    printf("i_vvaArray[8] = %d \t at address : %p \n", *(i_vvaArray + 8), (i_vvaArray + 8));
    printf("i_vvaArray[9] = %d \t at address : %p \n", *(i_vvaArray + 9), (i_vvaArray + 9));

    printf("\n\n");
    printf("Float array elements and the address they occupy are as follows : \n\n");
    printf("f_vvaArray[0] = %f \t at address : %p \n", *(f_vvaArray + 0), (f_vvaArray + 0));
    printf("f_vvaArray[1] = %f \t at address : %p \n", *(f_vvaArray + 1), (f_vvaArray + 1));
    printf("f_vvaArray[2] = %f \t at address : %p \n", *(f_vvaArray + 2), (f_vvaArray + 2));
    printf("f_vvaArray[3] = %f \t at address : %p \n", *(f_vvaArray + 3), (f_vvaArray + 3));
    printf("f_vvaArray[4] = %f \t at address : %p \n", *(f_vvaArray + 4), (f_vvaArray + 4));
    
    printf("\n\n");
    printf("Double array elements and the address they occupy are as follows : \n\n");
    printf("d_vvaArray[0] = %lf \t at address : %p \n", *(d_vvaArray + 0), (d_vvaArray + 0));
    printf("d_vvaArray[1] = %lf \t at address : %p \n", *(d_vvaArray + 1), (d_vvaArray + 1));
    printf("d_vvaArray[2] = %lf \t at address : %p \n", *(d_vvaArray + 2), (d_vvaArray + 2));

    printf("\n\n");
    printf("Character array elements and the address they occupy are as follows : \n\n");
    printf("c_vvaArray[0] = %c \t at address : %p \n", *(c_vvaArray + 0), (c_vvaArray + 0));
    printf("c_vvaArray[1] = %c \t at address : %p \n", *(c_vvaArray + 1), (c_vvaArray + 1));
    printf("c_vvaArray[2] = %c \t at address : %p \n", *(c_vvaArray + 2), (c_vvaArray + 2));
    printf("c_vvaArray[3] = %c \t at address : %p \n", *(c_vvaArray + 3), (c_vvaArray + 3));
    printf("c_vvaArray[4] = %c \t at address : %p \n", *(c_vvaArray + 4), (c_vvaArray + 4));
    printf("c_vvaArray[5] = %c \t at address : %p \n", *(c_vvaArray + 5), (c_vvaArray + 5));
    printf("c_vvaArray[6] = %c \t at address : %p \n", *(c_vvaArray + 6), (c_vvaArray + 6));
    printf("c_vvaArray[7] = %c \t at address : %p \n", *(c_vvaArray + 7), (c_vvaArray + 7));
    printf("c_vvaArray[8] = %c \t at address : %p \n", *(c_vvaArray + 8), (c_vvaArray + 8));
    printf("c_vvaArray[9] = %c \t at address : %p \n", *(c_vvaArray + 9), (c_vvaArray + 9));
    printf("c_vvaArray[10] = %c \t at address : %p \n", *(c_vvaArray + 10), (c_vvaArray + 10));
    printf("c_vvaArray[11] = %c \t at address : %p \n", *(c_vvaArray + 11), (c_vvaArray + 11));
    printf("c_vvaArray[12] = %c \t at address : %p \n", *(c_vvaArray + 12), (c_vvaArray + 12));
    printf("c_vvaArray[13] = %c \t at address : %p \n", *(c_vvaArray + 13), (c_vvaArray + 13));

    return (0);
}