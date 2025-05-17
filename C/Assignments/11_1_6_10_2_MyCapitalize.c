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
        else if (c_vvahArray[i_vva] == SPACE) // first letter if every word in the sentence must be a capital letter, words are separated by space
        {
            c_vvahArray_CapitalFirstLetterOfEveryWord[vva_j] = c_vvahArray[i_vva];
            c_vvahArray_CapitalFirstLetterOfEveryWord[vva_j + 1] = toupper(c_vvahArray[i_vva + 1]);

            // since already two characters copied in this block , are extra incrementing i_vva and vva_j by 1
            i_vva++;
            vva_j++;
        }
        else if (c_vvahArray[i_vva] == FULLSTOP || c_vvahArray[i_vva] == COMMA || c_vvahArray[i_vva] == EXCLAMATION \
                 || (c_vvahArray[i_vva] ==  QUESTION_MARK))
        {
            // first letter of every word after punctuation mark, in the sentence must be a capital letter. Words are separated by punctuations
            c_vvahArray_CapitalFirstLetterOfEveryWord[vva_j] = c_vvahArray[i_vva];
            c_vvahArray_CapitalFirstLetterOfEveryWord[vva_j + 1] = SPACE;
            c_vvahArray_CapitalFirstLetterOfEveryWord[vva_j + 2] = vva_MyToUpper(c_vvahArray[i_vva + 1]);

            // since already two characters copied in this block from source , are extra incrementing i_vva by 1
            // since already three characters considered in destination (additional space) , are extra incrementing vva_j by 2
            vva_j = vva_j + 2;
            i_vva++;
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

char vva_MyToUpper(char ch)
{
    // variable declaration
    int vva_num_vva;
    int c_vva;

    //code
    // ASCII value of 'a' (97) - ASCII value of 'A' (65) = 32, can be added to lower case character to make it upper case

    vva_num_vva = 'a' - 'A';
    if (ch >= 'a' && ch <= 'z')
    {
        c_vva = (int)ch - vva_num_vva;
        return((int)c_vva);
    }

    return ch;

}