#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    void vvaStrcpy(char[], char[]);
    // variable declarations
    char vva_chArray_Original[MAX_STRING_LENGTH], vva_chArray_Copy[MAX_STRING_LENGTH]; //char array is string

    //code 

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(vva_chArray_Original, MAX_STRING_LENGTH);

    // *** STRING COPY ****
    vvaStrcpy(vva_chArray_Copy, vva_chArray_Original);

    // ** STRING OUTPUT ***
    printf("\n\n");
    printf("Original string entered by you (i.e. : 'vva_chaArray_Original[]') is : \n\n");
    printf("%s\n", vva_chArray_Original);

    printf("\n\n");
    printf("The copied string (i.e. : 'vva_chArray_Copy[]') is : \n\n");
    printf("%s\n", vva_chArray_Copy);

    return(0);
}

void vvaStrcpy(char str_destination[], char str_source[])
{
    // function prototype
    int vvaStrlen(char[]);

    // variable declaration
    int vva_iStringLength = 0;
    int vva_j;

    //code
    vva_iStringLength = vvaStrlen(str_source);
    for (vva_j = 0; vva_j < vva_iStringLength; vva_j++)
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