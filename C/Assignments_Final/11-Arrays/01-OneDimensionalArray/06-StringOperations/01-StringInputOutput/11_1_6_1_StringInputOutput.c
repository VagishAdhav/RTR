#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // variable declaration
    char chArray_vva[MAX_STRING_LENGTH]; //a character array is a string

    //code 
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(chArray_vva, MAX_STRING_LENGTH);

    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", chArray_vva);
    return (0);
}