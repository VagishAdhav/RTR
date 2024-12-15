// ** THIS PROGRAM REPLACES ALL VOWELS IN THE INPUT STRING WITH THE * (asterisk) SYMBOL **
// ** FOR EXAMPLE, ORIGINAL STRING 'Dr. Vijay Dattatray Gokhale ASTROMEDICOMP' WILL BECOME  'Dr. V*j*y D*tt*tr*y G*kh*l* *STR*M*D*C*MP

#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    int vva_MyStrlen(char[]);
    void vva_MyStrcpy(char [], char[]);


    // variable declaration
    char vva_chArray_Original[MAX_STRING_LENGTH], vva_chArray_VowelReplaced[MAX_STRING_LENGTH]; // A character array is a string
    int vva_iStringLength;
    int vva_i;

    //code

    // **** STRING INPUT *********
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(vva_chArray_Original, MAX_STRING_LENGTH);

    // ** VOWELS_REPLACE *****
    vva_MyStrcpy(vva_chArray_VowelReplaced, vva_chArray_Original);
    
    vva_iStringLength = vva_MyStrlen(vva_chArray_VowelReplaced);

    for (vva_i = 0; vva_i < vva_iStringLength; vva_i++)
    {
        switch(vva_chArray_VowelReplaced[vva_i])
        {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
                vva_chArray_VowelReplaced[vva_i] = '*';
            default:
                break;
        }
    }

    // ** STRING_OUTPUT *****
    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", vva_chArray_Original);

    printf("\n\n");
    printf("String after replacement of vowels by * is : \n\n");
    printf("%s\n", vva_chArray_VowelReplaced);

    return(0);
}

int vva_MyStrlen(char str[])
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

void vva_MyStrcpy(char str_destination[], char str_source[])
{
    // function prototype
    int vva_MyStrlen(char[]);

    // variable declaration
    int vva_iStringLength = 0;
    int vva_j;

    //code
    vva_iStringLength = vva_MyStrlen(str_source);
    for (vva_j = 0; vva_j < vva_iStringLength; vva_j++)
        str_destination[vva_j] = str_source[vva_j];

    str_destination[vva_j] = '\0';
}

