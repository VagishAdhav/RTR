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
    char chArray_vva[MAX_STRING_LENGTH], chArray_CapitalFirstLetterOfEveryWord_vva[MAX_STRING_LENGTH]; // character array is a string
    int iStringLength_vva;
    int i_vva, j_vva;

    // code
    // ** STRING INPUT ** 
    printf("\n\n");
    printf("Enter a string : \n\n");
    gets_s(chArray_vva, MAX_STRING_LENGTH);

    iStringLength_vva = vva_MyStrlen(chArray_vva);
    j_vva = 0;
    for (i_vva = 0; i_vva < iStringLength_vva; i_vva++)
    {
        if (i_vva == 0)
        {
            chArray_CapitalFirstLetterOfEveryWord_vva[j_vva] = toupper(chArray_vva[i_vva]);
        }
        else if (chArray_vva[i_vva] == SPACE) // first letter if every word in the sentence must be a capital letter, words are separated by space
        {
            chArray_CapitalFirstLetterOfEveryWord_vva[j_vva] = chArray_vva[i_vva];
            chArray_CapitalFirstLetterOfEveryWord_vva[j_vva + 1] = toupper(chArray_vva[i_vva + 1]);

            // since already two characters copied in this block , are extra incrementing i_vva and j_vva by 1
            i_vva++;
            j_vva++;
        }
        else if (chArray_vva[i_vva] == FULLSTOP || chArray_vva[i_vva] == COMMA || chArray_vva[i_vva] == EXCLAMATION \
                 || (chArray_vva[i_vva] ==  QUESTION_MARK))
        {
            // first letter of every word after punctuation mark, in the sentence must be a capital letter. Words are separated by punctuations
            chArray_CapitalFirstLetterOfEveryWord_vva[j_vva] = chArray_vva[i_vva];
            chArray_CapitalFirstLetterOfEveryWord_vva[j_vva + 1] = SPACE;
            chArray_CapitalFirstLetterOfEveryWord_vva[j_vva + 2] = vva_MyToUpper(chArray_vva[i_vva + 1]);

            // since already two characters copied in this block from source , are extra incrementing i_vva by 1
            // since already three characters considered in destination (additional space) , are extra incrementing j_vva by 2
            j_vva = j_vva + 2;
            i_vva++;
        }
        else
        {
            chArray_CapitalFirstLetterOfEveryWord_vva[j_vva] = chArray_vva[i_vva];
        }
        j_vva++;
    }

    chArray_CapitalFirstLetterOfEveryWord_vva[j_vva] = '\0';

    
    // ** STRING OUTPUT ****
    printf("\n\n");
    printf("String entered by you is: \n\n");
    printf("%s\n", chArray_vva);

    printf("\n\n");
    printf("String after capitalizing first letter of every world is : \n\n");
    printf("%s\n", chArray_CapitalFirstLetterOfEveryWord_vva);

    return (0);
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

char vva_MyToUpper(char ch)
{
    // variable declaration
    int num_vva;
    int c_vva;

    //code
    // ASCII value of 'a' (97) - ASCII value of 'A' (65) = 32, can be added to lower case character to make it upper case

    num_vva = 'a' - 'A';
    if (ch >= 'a' && ch <= 'z')
    {
        c_vva = (int)ch - num_vva;
        return((int)c_vva);
    }

    return ch;

}