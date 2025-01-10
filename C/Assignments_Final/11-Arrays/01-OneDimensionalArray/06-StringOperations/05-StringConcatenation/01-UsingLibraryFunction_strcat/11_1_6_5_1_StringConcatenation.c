#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // variable declarations
    char chArray_One_vva[MAX_STRING_LENGTH], chArray_Two_vva[MAX_STRING_LENGTH]; // a character array is a string

    //code

    // *** STRING INPUT ****
    printf("\n\n");
    printf("Enter first string : \n\n");
    gets_s(chArray_One_vva, MAX_STRING_LENGTH);

    printf("\n\n");
    printf("Enter second string : \n\n");
    gets_s(chArray_Two_vva, MAX_STRING_LENGTH);

    // *** STRING CONCAT ***
    printf("\n\n");
    printf("****** BEFORE CONCATENATION**************");
    printf("\n\n");
    printf("The original first string entered by you (i.e. : 'chArray_one[]) is : \n\n");
    printf("%s\n", chArray_One_vva);

    printf("\n\n");
    printf("The original second string entered by you (i.e. : 'chArray_Two_vva[]) is : \n\n");
    printf("%s\n", chArray_Two_vva);

    strcat(chArray_One_vva, chArray_Two_vva);

    printf("\n\n");
    printf("****** AFTER CONCATENATION *********");
    printf("\n\n");
    printf("'chArray_One_vva[]' is : \n\n");
    printf("%s\n", chArray_One_vva);

    printf("\n\n");
    printf("'chArray_Two_vva[]' is : \n\n");
    printf("%s\n", chArray_Two_vva);

    return (0);
}