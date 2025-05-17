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
    char c_vvah;
    int c_vvah_value;

    //code 
    printf("\n\n");

    printf("Enter character : ");
    c_vvah = getch();

    printf("\n\n");

    switch (c_vvah)
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
            printf("Character \'%c\' entered by you is a VOWEL character from english alphabet !!! \n\n", c_vvah);
            break;

        default:
            c_vvah_value = (int)c_vvah;

        // if the character has ASCII value between 65 AND 90 OR between 97 AND 122, it is still a letter of the alphabet, 
        // but it is a CONSONANT and NOT a VOWEL

        if ((c_vvah_value >= CHAR_ALPHABET_UPPER_CASE_BEGINNING && \
             c_vvah_value <= CHAR_ALPHABET_UPPER_CASE_ENDING) || \
            (c_vvah_value >= CHAR_ALPHABET_LOWER_CASE_BEGINNING && \
             c_vvah_value <= CHAR_ALPHABET_LOWER_CASE_ENDING)) 

        {
            printf("Character \'%c\' entered bt you is a CONSONANT character !!! \n\n", c_vvah);
        }
        else if (c_vvah_value >= CHAR_DIGIT_BEGINNING && \
                 c_vvah_value <= CHAR_DIGIT_ENDING)
        {
            printf("Character \'%c\' entered by you is a DIGIT character !!! \n\n", c_vvah);
        }
        else
        {
            printf("Character \'%c\' entered by you is SPECIAL character !!! \n\n", c_vvah);
        }
    }

    printf("Switch case block complete !!!\n");

    return (0);
}
