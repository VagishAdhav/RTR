#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    //function prototype
    int vva_MyStrlen(char[]);

    // variable declaration
    char vva_chArray[MAX_STRING_LENGTH]; // A character array is a string
    int vva_iStringLength;
    int vva_i;
    int vva_word_count = 0, vva_space_count = 0;

    //code

    // *** STRING_OUTPUT ****
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(vva_chArray, MAX_STRING_LENGTH);

    vva_iStringLength = vva_MyStrlen(vva_chArray);

    for (vva_i = 0; vva_i < vva_iStringLength; vva_i++)
    {
        switch (vva_chArray[vva_i])
        {
            case ' ':
                vva_space_count++;
                break;
            default:
                break;
        }
    }

    vva_word_count = vva_space_count + 1;

    // ***  STRING OUTPUT ****
    printf("\n\n");
    printf("String entered by you : \n\n");
    printf("%s\n", vva_chArray);

    printf("\n\n");
    printf("Number of spaces in the input string = %d\n\n", vva_space_count);
    printf("Number of words in the input string = %d\n\n", vva_word_count);

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