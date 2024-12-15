#include <stdio.h>
#include <string.h> // for strrev()

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variable declaration
    char vva_chArray_Original[MAX_STRING_LENGTH]; // a char array is string

    // code

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(vva_chArray_Original, MAX_STRING_LENGTH);

    // *** STRING OUTPUT ****
    printf("\n\n");
    printf("The original string enterred by you (i.e. : 'vva_chArray_Original) \n\n");
    printf("%s\n", vva_chArray_Original);

    printf("\n\n");
    printf("The reversed string (i.e. 'vva_chArray' reversed) is : \n\n");
    printf("%s\n", strrev(vva_chArray_Original));

    return (0);
}