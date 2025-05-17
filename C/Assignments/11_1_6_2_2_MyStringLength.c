#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // function prototype
    int vvaStrlen(char[]);

    // variable declaration
    char c_vvahArray[MAX_STRING_LENGTH]; //a character array is a string
    int i_vvasStringLength = 0;

    //code 

    // *** STRING INPUT ****
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(c_vvahArray, MAX_STRING_LENGTH);

    // *** STRING OUTPUT ****
    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", c_vvahArray);

    // *** STRING LENGTH ***
    printf("\n\n");
    i_vvasStringLength = vvaStrlen(c_vvahArray);
    printf("Length of string is = %d characters !!!\n\n", i_vvasStringLength);

    return (0);
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
