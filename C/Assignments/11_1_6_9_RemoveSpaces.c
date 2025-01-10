#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // function prototype
    int vva_MyStrlen(char[]);

    // variable declaration
    char c_vvahArray[MAX_STRING_LENGTH], c_vvahArray_SpacesRemoved[MAX_STRING_LENGTH]; // A character array is a string
    int i_vvaStringLength;
    int i_vva, vva_j;

    //code

    // *** STRING_OUTPUT ****
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(c_vvahArray, MAX_STRING_LENGTH);

    i_vvaStringLength = vva_MyStrlen(c_vvahArray);
    vva_j = 0;
    for (i_vva = 0; i_vva < i_vvaStringLength; i_vva++)
    {
        if (c_vvahArray[i_vva] == ' ')
            continue;
        else{
            c_vvahArray_SpacesRemoved[vva_j] = c_vvahArray[i_vva];
            vva_j++;
        }
    }

    c_vvahArray_SpacesRemoved[vva_j] = '\0';

    // ** STRING OUTPUT ****
    printf("\n\n");
    printf("String entered by you is: \n\n");
    printf("%s\n", c_vvahArray);

    printf("\n\n");
    printf("String after removal of space is : \n\n");
    printf("%s\n", c_vvahArray_SpacesRemoved);

    return (0);
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