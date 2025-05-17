#include <stdio.h>
#include <string.h> // for strrev()

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variable declaration
    char c_vvahArray_Original[MAX_STRING_LENGTH]; // a char array is string

    // code

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(c_vvahArray_Original, MAX_STRING_LENGTH);

    // *** STRING OUTPUT ****
    printf("\n\n");
    printf("The original string enterred by you (i.e. : 'c_vvahArray_Original) \n\n");
    printf("%s\n", c_vvahArray_Original);

    printf("\n\n");
    printf("The reversed string (i.e. 'c_vvahArray' reversed) is : \n\n");
    printf("%s\n", strrev(c_vvahArray_Original));

    return (0);
}