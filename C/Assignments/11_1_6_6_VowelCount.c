#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    //function prototype
    int vva_MyStrlen(char[]);

    // variable declaration
    char c_vvahArray[MAX_STRING_LENGTH]; // A character array is a string
    int i_vvaStringLength;
    int c_vvaount_A = 0, c_vvaount_E = 0, c_vvaount_I = 0, c_vvaount_O = 0, c_vvaount_U = 0; // initial counts = 0;
    int i_vva;

    //code

    // **** STRING INPUT *********
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(c_vvahArray, MAX_STRING_LENGTH);

    // ** STRING_OUTPUT *****
    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", c_vvahArray);

    i_vvaStringLength = vva_MyStrlen(c_vvahArray);

    for (i_vva = 0; i_vva < i_vvaStringLength; i_vva++)
    {
        switch(c_vvahArray[i_vva])
        {
            case 'A':
            case 'a':
                c_vvaount_A++;
                break;
            case 'E':
            case 'e':
                c_vvaount_E++;
                break;
            case 'I':
            case 'i':
                c_vvaount_I++;
                break;
            case 'O':
            case 'o':
                c_vvaount_O++;
                break;
            case 'U':
            case 'u':
                c_vvaount_U++;
                break;
            default:
                break;
        }
    }

    printf("\n\n");
    printf("In the string entered by you , the vowels and their number of occurrences are as follows: \n\n");
    printf("'A' has occurred = %d times !!!\n\n", c_vvaount_A);
    printf("'E' has occurred = %d times !!!\n\n", c_vvaount_E);
    printf("'I' has occurred = %d times !!!\n\n", c_vvaount_I);
    printf("'O' has occurred = %d times !!!\n\n", c_vvaount_O);
    printf("'U' has occurred = %d times !!!\n\n", c_vvaount_U);

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