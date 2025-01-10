#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    //function prototype
    int vva_MyStrlen(char[]);

    // variable declaration
    char chArray_vva[MAX_STRING_LENGTH]; // A character array is a string
    int iStringLength_vva;
    int i_vva;
    int vva_word_count = 0, vva_space_count = 0;

    //code

    // *** STRING_OUTPUT ****
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(chArray_vva, MAX_STRING_LENGTH);

    iStringLength_vva = vva_MyStrlen(chArray_vva);

    for (i_vva = 0; i_vva < iStringLength_vva; i_vva++)
    {
        switch (chArray_vva[i_vva])
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
    printf("%s\n", chArray_vva);

    printf("\n\n");
    printf("number of spaces in the input string = %d\n\n", vva_space_count);
    printf("number of words in the input string = %d\n\n", vva_word_count);

    return(0);
}

int vva_MyStrlen(char str_vva[])
{
    // variable declarations 
    int j_vva;
    int vva_string_length = 0;

    // code
    // ** DETERMINING EXACT LENGTH OF THE STRING BY DETECTING THE FIRST OCCURRENCE OF NULL TERMINATING CHARACTER (\0) ***
    for (j_vva = 0; j_vva < MAX_STRING_LENGTH; j_vva++)
    {
        if (str_vva[j_vva] == '\0')
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