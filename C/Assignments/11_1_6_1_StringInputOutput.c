#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // variable declaration
    char vva_chArray[MAX_STRING_LENGTH]; //a character array is a string

    //code 
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(vva_chArray, MAX_STRING_LENGTH);

    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", vva_chArray);
    return (0);
}