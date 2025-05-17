#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // function prototype
    void vvaStrcat(char[], char[]);

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

    vvaStrcat(c_vvahArray_One, c_vvahArray_Two);

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

void vvaStrcat(char str_destination[], char str_source[])
{
    // function prototype 
    int vvaStrlen(char[]);

    // variable declaration
    int i_vvaStringLength_Source = 0, i_vvaStringLength_Destination = 0;
    int i_vva, vva_j;

    //code
    i_vvaStringLength_Source = vvaStrlen(str_source);
    i_vvaStringLength_Destination = vvaStrlen(str_destination);

    // last valid index of an array is length-1, as index begins from 0,
    // concatenation of second array must begin from length of the first array
    // which means we start with copying first index for str_source into the last index + 1 of str_destination
    for (i_vva = i_vvaStringLength_Destination, vva_j = 0; vva_j < i_vvaStringLength_Source; i_vva++, vva_j++)
    {
        str_destination[i_vva] = str_source[vva_j];
    }

    str_destination[i_vva] = '\0';
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