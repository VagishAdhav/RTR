#include <stdio.h>
#include <ctype.h> // for toupper()

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    int vva_MyStrlen(char[]);

    // variable declaration
    char c_vvahArray[MAX_STRING_LENGTH], c_vvahArray_CapitalFirstLetterOfEveryWord[MAX_STRING_LENGTH]; // character array is a string
    int i_vvaStringLength;
    int i_vva, vva_j;

    // code
    // ** STRING INPUT ** 
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(c_vvahArray, MAX_STRING_LENGTH);

    i_vvaStringLength = vva_MyStrlen(c_vvahArray);
    vva_j = 0;
    for (i_vva = 0; i_vva < i_vvaStringLength; i_vva++)
    {
        if (i_vva == 0)
        {
            c_vvahArray_CapitalFirstLetterOfEveryWord[vva_j] = toupper(c_vvahArray[i_vva]);
        }
        else if (c_vvahArray[i_vva] == ' ')
        {
            c_vvahArray_CapitalFirstLetterOfEveryWord[vva_j] = c_vvahArray[i_vva];
            c_vvahArray_CapitalFirstLetterOfEveryWord[vva_j + 1] = toupper(c_vvahArray[i_vva + 1]);

            // since already teo characters copied in this block , are extra incrementing i_vva and vva_j by 1
            i_vva++;
            vva_j++;
        }
        else
        {
            c_vvahArray_CapitalFirstLetterOfEveryWord[vva_j] = c_vvahArray[i_vva];
        }
        vva_j++;
    }

    c_vvahArray_CapitalFirstLetterOfEveryWord[vva_j] = '\0';

    
    // ** STRING OUTPUT ****
    printf("\n\n");
    printf("String entered by you is: \n\n");
    printf("%s\n", c_vvahArray);

    printf("\n\n");
    printf("String after capitalizing first letter of every world is : \n\n");
    printf("%s\n", c_vvahArray_CapitalFirstLetterOfEveryWord);

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