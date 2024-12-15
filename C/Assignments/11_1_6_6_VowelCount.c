#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    //function prototype
    int vva_MyStrlen(char[]);

    // variable declaration
    char vva_chArray[MAX_STRING_LENGTH]; // A character array is a string
    int vva_iStringLength;
    int vva_count_A = 0, vva_count_E = 0, vva_count_I = 0, vva_count_O = 0, vva_count_U = 0; // initial counts = 0;
    int vva_i;

    //code

    // **** STRING INPUT *********
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(vva_chArray, MAX_STRING_LENGTH);

    // ** STRING_OUTPUT *****
    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", vva_chArray);

    vva_iStringLength = vva_MyStrlen(vva_chArray);

    for (vva_i = 0; vva_i < vva_iStringLength; vva_i++)
    {
        switch(vva_chArray[vva_i])
        {
            case 'A':
            case 'a':
                vva_count_A++;
                break;
            case 'E':
            case 'e':
                vva_count_E++;
                break;
            case 'I':
            case 'i':
                vva_count_I++;
                break;
            case 'O':
            case 'o':
                vva_count_O++;
                break;
            case 'U':
            case 'u':
                vva_count_U++;
                break;
            default:
                break;
        }
    }

    printf("\n\n");
    printf("In the string entered by you , the vowels and their number of occurrences are as follows: \n\n");
    printf("'A' has occurred = %d times !!!\n\n", vva_count_A);
    printf("'E' has occurred = %d times !!!\n\n", vva_count_E);
    printf("'I' has occurred = %d times !!!\n\n", vva_count_I);
    printf("'O' has occurred = %d times !!!\n\n", vva_count_O);
    printf("'U' has occurred = %d times !!!\n\n", vva_count_U);

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