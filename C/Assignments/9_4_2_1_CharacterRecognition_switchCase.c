#include <stdio.h> // for printf
#include <conio.h> // for getch

// ASCII values for 'A' to 'Z' => 65 to 90
#define CHAR_ALPHABET_UPPER_CASE_BEGINNING 65
#define CHAR_ALPHABET_UPPER_CASE_ENDING    90

//ASCII values for 'a' to 'z' = > 97 to 122
#define CHAR_ALPHABET_LOWER_CASE_BEGINNING 97
#define CHAR_ALPHABET_LOWER_CASE_ENDING 57

// ASCII values for '0' to '9' => 48 to 57
#define CHAR_DIGIT_BEGINNING 48
#define CHAR_DIGIT_ENDING 57

int main(void)
{
    //variable declaration 
    char vva_ch;
    int vva_ch_value;

    //code 
    printf("\n\n");

    printf("Enter character : ");
    vva_ch = getch();

    printf("\n\n");

    switch (vva_ch)
    {
        case 'A':
        case 'a':

        case 'E':
        case 'e':

        case 'I':
        case 'i':

        case 'O':
        case 'o':

        case 'U':
        case 'u':
            printf("Character \'%c\' entered by you is a VOWEL character from english alphabet !!! \n\n", vva_ch);
            break;

        default:
            vva_ch_value = (int)vva_ch;

        // if the character has ASCII value between 65 AND 90 OR between 97 AND 122, it is still a letter of the alphabet, 
        // but it is a CONSONANT and NOT a VOWEL

        if ((vva_ch_value >= CHAR_ALPHABET_UPPER_CASE_BEGINNING && \
             vva_ch_value <= CHAR_ALPHABET_UPPER_CASE_ENDING) || \
            (vva_ch_value >= CHAR_ALPHABET_LOWER_CASE_BEGINNING && \
             vva_ch_value <= CHAR_ALPHABET_LOWER_CASE_ENDING)) 

        {
            printf("Character \'%c\' entered bt you is a CONSONANT character !!! \n\n", vva_ch);
        }
        else if (vva_ch_value >= CHAR_DIGIT_BEGINNING && \
                 vva_ch_value <= CHAR_DIGIT_ENDING)
        {
            printf("Character \'%c\' entered by you is a DIGIT character !!! \n\n", vva_ch);
        }
        else
        {
            printf("Character \'%c\' entered by you is SPECIAL character !!! \n\n", vva_ch);
        }
    }

    printf("Switch case block complete !!!\n");

    return (0);
}
