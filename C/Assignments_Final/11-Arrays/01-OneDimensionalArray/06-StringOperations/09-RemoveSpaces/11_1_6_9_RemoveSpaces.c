#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // function prototype
    int vva_MyStrlen(char[]);

    // variable declaration
    char chArray_vva[MAX_STRING_LENGTH], chArray_SpacesRemoved_vva[MAX_STRING_LENGTH]; // A character array is a string
    int iStringLength_vva;
    int i_vva, j_vva;

    //code

    // *** STRING_OUTPUT ****
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(chArray_vva, MAX_STRING_LENGTH);

    iStringLength_vva = vva_MyStrlen(chArray_vva);
    j_vva = 0;
    for (i_vva = 0; i_vva < iStringLength_vva; i_vva++)
    {
        if (chArray_vva[i_vva] == ' ')
            continue;
        else{
            chArray_SpacesRemoved_vva[j_vva] = chArray_vva[i_vva];
            j_vva++;
        }
    }

    chArray_SpacesRemoved_vva[j_vva] = '\0';

    // ** STRING OUTPUT ****
    printf("\n\n");
    printf("String entered by you is: \n\n");
    printf("%s\n", chArray_vva);

    printf("\n\n");
    printf("String after removal of space is : \n\n");
    printf("%s\n", chArray_SpacesRemoved_vva);

    return (0);
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