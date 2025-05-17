#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    void vvaStrrev(char[], char[]);
    // variable declaration
    char chArray_Original_vva[MAX_STRING_LENGTH], chArray_Reversed_vva[MAX_STRING_LENGTH]; // a char array is string

    // code

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(chArray_Original_vva, MAX_STRING_LENGTH);

    // ** STRING REVERSE ***
    vvaStrrev(chArray_Reversed_vva, chArray_Original_vva);

    // *** STRING OUTPUT ****
    printf("\n\n");
    printf("The original string enterred by you (i.e. : 'chArray_Original_vva) \n\n");
    printf("%s\n", chArray_Original_vva);

    printf("\n\n");
    printf("The reversed string (i.e. 'chArray_Reversed_vva') is : \n\n");
    printf("%s\n", chArray_Reversed_vva);

    return (0);
}

void vvaStrrev(char str_destination[], char str_source[])
{
    // function prototype 
    int vvaStrlen(char[]);

    //variable declaration
    int iStringLength_vva = 0;
    int i_vva, j_vva, vva_len;

    //code
    iStringLength_vva = vvaStrlen(str_source);

    // array index begin from 0 , hence last index will be length-1
    vva_len = iStringLength_vva - 1;

    // put character from last index to first index, second last index to second index and so on
    for (i_vva = 0, j_vva = vva_len; i_vva < iStringLength_vva, j_vva >= 0; i_vva++, j_vva--)
    {
        str_destination[i_vva] = str_source[j_vva];
    }

    str_destination[i_vva] = '\0';

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