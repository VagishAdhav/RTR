#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variable declarations
    char c_vvahArray_Original[MAX_STRING_LENGTH], c_vvahArray_Copy[MAX_STRING_LENGTH]; //char array is string

    //code 

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(c_vvahArray_Original, MAX_STRING_LENGTH);

    // *** STRING COPY ****
    strcpy(c_vvahArray_Copy, c_vvahArray_Original);

    // ** STRING OUTPUT ***
    printf("\n\n");
    printf("Original string entered by you (i.e. : 'c_vvahaArray_Original[]') is : \n\n");
    printf("%s\n", c_vvahArray_Original);

    printf("\n\n");
    printf("The copied string (i.e. : 'c_vvahArray_Copy[]') is : \n\n");
    printf("%s\n", c_vvahArray_Copy);

    return(0);
}