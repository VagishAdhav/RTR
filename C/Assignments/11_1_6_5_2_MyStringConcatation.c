#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // function prototype
    void vvaStrcat(char[], char[]);

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

    vvaStrcat(vva_chArray_One, vva_chArray_Two);

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

void vvaStrcat(char str_destination[], char str_source[])
{
    // function prototype 
    int vvaStrlen(char[]);

    // variable declaration
    int vva_iStringLength_Source = 0, vva_iStringLength_Destination = 0;
    int vva_i, vva_j;

    //code
    vva_iStringLength_Source = vvaStrlen(str_source);
    vva_iStringLength_Destination = vvaStrlen(str_destination);

    // last valid index of an array is length-1, as index begins from 0,
    // concatenation of second array must begin from length of the first array
    // which means we start with copying first index for str_source into the last index + 1 of str_destination
    for (vva_i = vva_iStringLength_Destination, vva_j = 0; vva_j < vva_iStringLength_Source; vva_i++, vva_j++)
    {
        str_destination[vva_i] = str_source[vva_j];
    }

    str_destination[vva_i] = '\0';
}


int vvaStrlen(char str[])
{
    // variable declarations 
    int vva_j;
    int vva_string_length = 0;

    // code
    // ** DETERMINING EXACT LENGTH OF THE STRING BY DETECTING THE FIRST OCCURRENCE OF NULL TERMINATING CHARACTER (\0) ***
    for (vva_j = 0; vva_j < MAX_STRING_LENGTH; vva_j++)
    {
        if (str[vva_j] == '\0')
        {
            break;
        }
        else
        {
            vva_string_length++;
        }
    }
    return (vva_string_length);
}