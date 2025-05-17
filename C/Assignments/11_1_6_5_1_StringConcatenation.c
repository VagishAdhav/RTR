#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // variable declarations
    char c_vvahArray_One[MAX_STRING_LENGTH], c_vvahArray_Two[MAX_STRING_LENGTH]; // a character array is a string

    //code

    // *** STRING INPUT ****
    printf("\n\n");
    printf("Enter first string : \n\n");
    gets_s(c_vvahArray_One, MAX_STRING_LENGTH);

    printf("\n\n");
    printf("Enter second string : \n\n");
    gets_s(c_vvahArray_Two, MAX_STRING_LENGTH);

    // *** STRING CONCAT ***
    printf("\n\n");
    printf("****** BEFORE CONCATENATION**************");
    printf("\n\n");
    printf("The original first string entered by you (i.e. : 'c_vvahArray_one[]) is : \n\n");
    printf("%s\n", c_vvahArray_One);

    printf("\n\n");
    printf("The original second string entered by you (i.e. : 'c_vvahArray_Two[]) is : \n\n");
    printf("%s\n", c_vvahArray_Two);

    strcat(c_vvahArray_One, c_vvahArray_Two);

    printf("\n\n");
    printf("****** AFTER CONCATENATION *********");
    printf("\n\n");
    printf("'c_vvahArray_One[]' is : \n\n");
    printf("%s\n", c_vvahArray_One);

    printf("\n\n");
    printf("'c_vvahArray_Two[]' is : \n\n");
    printf("%s\n", c_vvahArray_Two);

    return (0);
}