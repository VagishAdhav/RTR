#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variable declarations
    char vva_chArray_Original[MAX_STRING_LENGTH], vva_chArray_Copy[MAX_STRING_LENGTH]; //char array is string

    //code 

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(vva_chArray_Original, MAX_STRING_LENGTH);

    // *** STRING COPY ****
    strcpy(vva_chArray_Copy, vva_chArray_Original);

    // ** STRING OUTPUT ***
    printf("\n\n");
    printf("Original string entered by you (i.e. : 'vva_chaArray_Original[]') is : \n\n");
    printf("%s\n", vva_chArray_Original);

    printf("\n\n");
    printf("The copied string (i.e. : 'vva_chArray_Copy[]') is : \n\n");
    printf("%s\n", vva_chArray_Copy);

    return(0);
}