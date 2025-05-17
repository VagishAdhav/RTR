#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    void vvaStrcpy(char[], char[]);
    // variable declarations
    char chArray_Original_vva[MAX_STRING_LENGTH], chArray_Copy_vva[MAX_STRING_LENGTH]; //char array is string

    //code 

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(chArray_Original_vva, MAX_STRING_LENGTH);

    // *** STRING COPY ****
    vvaStrcpy(chArray_Copy_vva, chArray_Original_vva);

    // ** STRING OUTPUT ***
    printf("\n\n");
    printf("Original string entered by you (i.e. : 'chaArray_Original[]') is : \n\n");
    printf("%s\n", chArray_Original_vva);

    printf("\n\n");
    printf("The copied string (i.e. : 'chArray_Copy_vva[]') is : \n\n");
    printf("%s\n", chArray_Copy_vva);

    return(0);
}

void vvaStrcpy(char str_destination[], char str_source[])
{
    // function prototype
    int vvaStrlen(char[]);

    // variable declaration
    int iStringLength_vva = 0;
    int j_vva;

    //code
    iStringLength_vva = vvaStrlen(str_source);
    for (j_vva = 0; j_vva < iStringLength_vva; j_vva++)
        str_destination[j_vva] = str_source[j_vva];

    str_destination[j_vva] = '\0';
}

int vvaStrlen(char str_vva[])
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