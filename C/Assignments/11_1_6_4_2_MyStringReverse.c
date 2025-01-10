#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    void vvaStrrev(char[], char[]);
    // variable declaration
    char c_vvahArray_Original[MAX_STRING_LENGTH], c_vvahArray_Reversed[MAX_STRING_LENGTH]; // a char array is string

    // code

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(c_vvahArray_Original, MAX_STRING_LENGTH);

    // ** STRING REVERSE ***
    vvaStrrev(c_vvahArray_Reversed, c_vvahArray_Original);

    // *** STRING OUTPUT ****
    printf("\n\n");
    printf("The original string enterred by you (i.e. : 'c_vvahArray_Original) \n\n");
    printf("%s\n", c_vvahArray_Original);

    printf("\n\n");
    printf("The reversed string (i.e. 'c_vvahArray_Reversed') is : \n\n");
    printf("%s\n", c_vvahArray_Reversed);

    return (0);
}

void vvaStrrev(char str_destination[], char str_source[])
{
    // function prototype 
    int vvaStrlen(char[]);

    //variable declaration
    int i_vvaStringLength = 0;
    int i_vva, vva_j, vva_len;

    //code
    i_vvaStringLength = vvaStrlen(str_source);

    // array index begin from 0 , hence last index will be length-1
    vva_len = i_vvaStringLength - 1;

    // put character from last index to first index, second last index to second index and so on
    for (i_vva = 0, vva_j = vva_len; i_vva < i_vvaStringLength, vva_j >= 0; i_vva++, vva_j--)
    {
        str_destination[i_vva] = str_source[vva_j];
    }

    str_destination[i_vva] = '\0';

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