#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // variable declarations
    char vva_chArray_One[MAX_STRING_LENGTH], vva_chArray_Two[MAX_STRING_LENGTH]; // a character array is a string

    //code

    // *** STRING INPUT ****
    printf("\n\n");
    printf("Enter first string : \n\n");
    gets_s(vva_chArray_One, MAX_STRING_LENGTH);

    printf("\n\n");
    printf("Enter second string : \n\n");
    gets_s(vva_chArray_Two, MAX_STRING_LENGTH);

    // *** STRING CONCAT ***
    printf("\n\n");
    printf("****** BEFORE CONCATENATION**************");
    printf("\n\n");
    printf("The original first string entered by you (i.e. : 'vva_chArray_one[]) is : \n\n");
    printf("%s\n", vva_chArray_One);

    printf("\n\n");
    printf("The original second string entered by you (i.e. : 'vva_chArray_Two[]) is : \n\n");
    printf("%s\n", vva_chArray_Two);

    strcat(vva_chArray_One, vva_chArray_Two);

    printf("\n\n");
    printf("****** AFTER CONCATENATION *********");
    printf("\n\n");
    printf("'vva_chArray_One[]' is : \n\n");
    printf("%s\n", vva_chArray_One);

    printf("\n\n");
    printf("'vva_chArray_Two[]' is : \n\n");
    printf("%s\n", vva_chArray_Two);

    return (0);
}