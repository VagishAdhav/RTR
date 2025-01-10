#include <stdio.h>
#include <string.h> // for strrev()

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variable declaration
    char chArray_Original_vva[MAX_STRING_LENGTH]; // a char array is string

    // code

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(chArray_Original_vva, MAX_STRING_LENGTH);

    // *** STRING OUTPUT ****
    printf("\n\n");
    printf("The original string enterred by you (i.e. : 'chArray_Original_vva) \n\n");
    printf("%s\n", chArray_Original_vva);

    printf("\n\n");
    printf("The reversed string (i.e. 'chArray_vva' reversed) is : \n\n");
    printf("%s\n", strrev(chArray_Original_vva));

    return (0);
}