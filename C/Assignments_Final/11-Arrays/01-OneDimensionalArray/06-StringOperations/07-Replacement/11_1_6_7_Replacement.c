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
    char chArray_Original_vva[MAX_STRING_LENGTH], chArray_VowelReplaced_vva[MAX_STRING_LENGTH]; // A character array is a string
    int iStringLength_vva;
    int i_vva;

    //code

    // **** STRING INPUT *********
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(chArray_Original_vva, MAX_STRING_LENGTH);

    // ** VOWELS_REPLACE *****
    vva_MyStrcpy(chArray_VowelReplaced_vva, chArray_Original_vva);
    
    iStringLength_vva = vva_MyStrlen(chArray_VowelReplaced_vva);

    for (i_vva = 0; i_vva < iStringLength_vva; i_vva++)
    {
        switch(chArray_VowelReplaced_vva[i_vva])
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
                chArray_VowelReplaced_vva[i_vva] = '*';
            default:
                break;
        }
    }

    // ** STRING_OUTPUT *****
    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", chArray_Original_vva);

    printf("\n\n");
    printf("String after replacement of vowels by * is : \n\n");
    printf("%s\n", chArray_VowelReplaced_vva);

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

void vva_MyStrcpy(char str_destination[], char str_source[])
{
    // function prototype
    int vva_MyStrlen(char[]);

    // variable declaration
    int iStringLength_vva = 0;
    int j_vva;

    //code
    iStringLength_vva = vva_MyStrlen(str_source);
    for (j_vva = 0; j_vva < iStringLength_vva; j_vva++)
        str_destination[j_vva] = str_source[j_vva];

    str_destination[j_vva] = '\0';
}

