#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // variable declaration
    char vva_chArray[MAX_STRING_LENGTH]; //a character array is a string
    int vva_isStringLength = 0;

    //code 

    // *** STRING INPUT ****
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(vva_chArray, MAX_STRING_LENGTH);

    // *** STRING OUTPUT ****
    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", vva_chArray);

    // *** STRING LENGTH ***
    printf("\n\n");
    vva_isStringLength = strlen(vva_chArray);
    printf("Length of string is = %d characters !!!\n\n", vva_isStringLength);

    return (0);
}