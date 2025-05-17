#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    void vvaStrcpy(char[], char[]);
    // variable declarations
    char c_vvahArray_Original[MAX_STRING_LENGTH], c_vvahArray_Copy[MAX_STRING_LENGTH]; //char array is string

    //code 

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(c_vvahArray_Original, MAX_STRING_LENGTH);

    // *** STRING COPY ****
    vvaStrcpy(c_vvahArray_Copy, c_vvahArray_Original);

    // ** STRING OUTPUT ***
    printf("\n\n");
    printf("Original string entered by you (i.e. : 'c_vvahaArray_Original[]') is : \n\n");
    printf("%s\n", c_vvahArray_Original);

    printf("\n\n");
    printf("The copied string (i.e. : 'c_vvahArray_Copy[]') is : \n\n");
    printf("%s\n", c_vvahArray_Copy);

    return(0);
}

void vvaStrcpy(char str_destination[], char str_source[])
{
    // function prototype
    int vvaStrlen(char[]);

    // variable declaration
    int i_vvaStringLength = 0;
    int vva_j;

    //code
    i_vvaStringLength = vvaStrlen(str_source);
    for (vva_j = 0; vva_j < i_vvaStringLength; vva_j++)
        str_destination[vva_j] = str_source[vva_j];

    str_destination[vva_j] = '\0';
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