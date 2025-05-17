#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // variable declaration
    char c_vvahArray[MAX_STRING_LENGTH]; //a character array is a string
    int i_vvasStringLength = 0;

    //code 

    // *** STRING INPUT ****
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(c_vvahArray, MAX_STRING_LENGTH);

    // *** STRING OUTPUT ****
    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", c_vvahArray);

    // *** STRING LENGTH ***
    printf("\n\n");
    i_vvasStringLength = strlen(c_vvahArray);
    printf("Length of string is = %d characters !!!\n\n", i_vvasStringLength);

    return (0);
}