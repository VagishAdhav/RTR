#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variable declarations
    char chArray_Original_vva[MAX_STRING_LENGTH], chArray_Copy_vva[MAX_STRING_LENGTH]; //char array is string

    //code 

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(chArray_Original_vva, MAX_STRING_LENGTH);

    // *** STRING COPY ****
    strcpy(chArray_Copy_vva, chArray_Original_vva);

    // ** STRING OUTPUT ***
    printf("\n\n");
    printf("Original string entered by you (i.e. : 'chaArray_Original[]') is : \n\n");
    printf("%s\n", chArray_Original_vva);

    printf("\n\n");
    printf("The copied string (i.e. : 'chArray_Copy_vva[]') is : \n\n");
    printf("%s\n", chArray_Copy_vva);

    return(0);
}