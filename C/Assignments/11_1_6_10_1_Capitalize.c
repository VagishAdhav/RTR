#include <stdio.h>
#include <ctype.h> // for toupper()

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    int vva_MyStrlen(char[]);

    // variable declaration
    char vva_chArray[MAX_STRING_LENGTH], vva_chArray_CapitalFirstLetterOfEveryWord[MAX_STRING_LENGTH]; // character array is a string
    int vva_iStringLength;
    int vva_i, vva_j;

    // code
    // ** STRING INPUT ** 
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(vva_chArray, MAX_STRING_LENGTH);

    vva_iStringLength = vva_MyStrlen(vva_chArray);
    vva_j = 0;
    for (vva_i = 0; vva_i < vva_iStringLength; vva_i++)
    {
        if (vva_i == 0)
        {
            vva_chArray_CapitalFirstLetterOfEveryWord[vva_j] = toupper(vva_chArray[vva_i]);
        }
        else if (vva_chArray[vva_i] == ' ')
        {
            vva_chArray_CapitalFirstLetterOfEveryWord[vva_j] = vva_chArray[vva_i];
            vva_chArray_CapitalFirstLetterOfEveryWord[vva_j + 1] = toupper(vva_chArray[vva_i + 1]);

            // since already teo characters copied in this block , are extra incrementing vva_i and vva_j by 1
            vva_i++;
            vva_j++;
        }
        else
        {
            vva_chArray_CapitalFirstLetterOfEveryWord[vva_j] = vva_chArray[vva_i];
        }
        vva_j++;
    }

    vva_chArray_CapitalFirstLetterOfEveryWord[vva_j] = '\0';

    
    // ** STRING OUTPUT ****
    printf("\n\n");
    printf("String entered by you is: \n\n");
    printf("%s\n", vva_chArray);

    printf("\n\n");
    printf("String after capitalizing first letter of every world is : \n\n");
    printf("%s\n", vva_chArray_CapitalFirstLetterOfEveryWord);

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