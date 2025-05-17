#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // variable declaration
    char chArray_vva[MAX_STRING_LENGTH]; //a character array is a string
    int iStringLength_vva = 0;

    //code 

    // *** STRING INPUT ****
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(chArray_vva, MAX_STRING_LENGTH);

    // *** STRING OUTPUT ****
    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", chArray_vva);

    // *** STRING LENGTH ***
    printf("\n\n");
    iStringLength_vva = strlen(chArray_vva);
    printf("Length of string is = %d characters !!!\n\n", iStringLength_vva);

    return (0);
}