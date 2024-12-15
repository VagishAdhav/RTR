#include <stdio.h>
#include <ctype.h> // for toupper()

#define MAX_STRING_LENGTH 512

#define SPACE ' '
#define FULLSTOP '.'
#define COMMA ','
#define EXCLAMATION '!'
#define QUESTION_MARK '?'

int main(void)
{
    // function prototype
    int vva_MyStrlen(char[]);
    char vva_MyToUpper(char);



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
        else if (vva_chArray[vva_i] == SPACE) // first letter if every word in the sentence must be a capital letter, words are separated by space
        {
            vva_chArray_CapitalFirstLetterOfEveryWord[vva_j] = vva_chArray[vva_i];
            vva_chArray_CapitalFirstLetterOfEveryWord[vva_j + 1] = toupper(vva_chArray[vva_i + 1]);

            // since already two characters copied in this block , are extra incrementing vva_i and vva_j by 1
            vva_i++;
            vva_j++;
        }
        else if (vva_chArray[vva_i] == FULLSTOP || vva_chArray[vva_i] == COMMA || vva_chArray[vva_i] == EXCLAMATION \
                 || (vva_chArray[vva_i] ==  QUESTION_MARK))
        {
            // first letter of every word after punctuation mark, in the sentence must be a capital letter. Words are separated by punctuations
            vva_chArray_CapitalFirstLetterOfEveryWord[vva_j] = vva_chArray[vva_i];
            vva_chArray_CapitalFirstLetterOfEveryWord[vva_j + 1] = SPACE;
            vva_chArray_CapitalFirstLetterOfEveryWord[vva_j + 2] = vva_MyToUpper(vva_chArray[vva_i + 1]);

            // since already two characters copied in this block from source , are extra incrementing vva_i by 1
            // since already three characters considered in destination (additional space) , are extra incrementing vva_j by 2
            vva_j = vva_j + 2;
            vva_i++;
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

char vva_MyToUpper(char ch)
{
    // variable declaration
    int vva_num;
    int vva_c;

    //code
    // ASCII value of 'a' (97) - ASCII value of 'A' (65) = 32, can be added to lower case character to make it upper case

    vva_num = 'a' - 'A';
    if (ch >= 'a' && ch <= 'z')
    {
        vva_c = (int)ch - vva_num;
        return((int)vva_c);
    }

    return ch;

}