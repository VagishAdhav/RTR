#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    //function prototype
    int vva_MyStrlen(char[]);

    // variable declaration
    char chArray_vva[MAX_STRING_LENGTH]; // A character array is a string
    int iStringLength_vva;
    int count_A_vva = 0, count_E_vva = 0, count_I_vva = 0, count_O_vva = 0, count_U_vva = 0; // initial counts = 0;
    int i_vva;

    //code

    // **** STRING INPUT *********
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(chArray_vva, MAX_STRING_LENGTH);

    // ** STRING_OUTPUT *****
    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", chArray_vva);

    iStringLength_vva = vva_MyStrlen(chArray_vva);

    for (i_vva = 0; i_vva < iStringLength_vva; i_vva++)
    {
        switch(chArray_vva[i_vva])
        {
            case 'A':
            case 'a':
                count_A_vva++;
                break;
            case 'E':
            case 'e':
                count_E_vva++;
                break;
            case 'I':
            case 'i':
                count_I_vva++;
                break;
            case 'O':
            case 'o':
                count_O_vva++;
                break;
            case 'U':
            case 'u':
                count_U_vva++;
                break;
            default:
                break;
        }
    }

    printf("\n\n");
    printf("In the string entered by you , the vowels and their number of occurrences are as follows: \n\n");
    printf("'A' has occurred = %d times !!!\n\n", count_A_vva);
    printf("'E' has occurred = %d times !!!\n\n", count_E_vva);
    printf("'I' has occurred = %d times !!!\n\n", count_I_vva);
    printf("'O' has occurred = %d times !!!\n\n", count_O_vva);
    printf("'U' has occurred = %d times !!!\n\n", count_U_vva);

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