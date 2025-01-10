#include <stdio.h> // for printf()
#include <conio.h> // for getch()

//ASCII values for 'A' to 'Z' => 65 to 90
#define CHAR_ALPHABET_UPPER_CASE_BEGINNING 65
#define CHAR_ALPHABET_UPPER_CASE_ENDING 90

// ASCII values for 'a' to 'z' => 97 to 122
#define CHAR_ALPHABET_LOWER_CASE_BEGINNING 97
#define CHAR_ALPHABET_LOWER_CASE_ENDING 122

// ASCII values for '0' to '9' => 48 to 57
#define CHAR_DIGIT_BEGINNING 48
#define CHAR_DIGIT_ENDING    57

int main(void)
{
    // variable declaration
    char ch_vva;
    int ch_value_vva;

    //code
    printf("\n\n");

    printf("Enter character : ");
    ch_vva = getch();

    printf("\n\n");

    if (ch_vva == 'A' || ch_vva == 'a' ||\
        ch_vva == 'O' || ch_vva == 'o' ||\
        ch_vva == 'I' || ch_vva == 'i' ||\
        ch_vva == 'E' || ch_vva == 'e' ||\
        ch_vva == 'U' || ch_vva == 'u')
    {
        printf("Character \'%c\' entered by you is a VOWEL character from the english alphabet !!! \n\n", ch_vva);
    }
    else
    {
        ch_value_vva = (int)ch_vva;
        
        //if the character has ASCII value between 65 and 90 or between 97 and 122,
        // it is still A letter of the alphabet but it is a 'CONSONANT' and not 'VOWEL'

        if ((ch_value_vva >= CHAR_ALPHABET_UPPER_CASE_BEGINNING ) && (ch_value_vva <= CHAR_ALPHABET_UPPER_CASE_ENDING) ||
            (ch_value_vva >= CHAR_ALPHABET_LOWER_CASE_BEGINNING ) && (ch_value_vva <= CHAR_ALPHABET_LOWER_CASE_ENDING))
        {
            printf("Character \'%c\' entered by you is a CONSTANT character from the english alphabet !!! \n\n", ch_vva);
        }
        else if (ch_value_vva >= CHAR_DIGIT_BEGINNING && ch_value_vva <= CHAR_DIGIT_ENDING)
        {
            printf("Character \'%c\' entered by you is a DIGIT character !!! \n\n", ch_vva);
        }
        else
        {
            printf("Character \'%c\' entered by you is SPECIAL character !!! \n\n", ch_vva);
        }
    }

    return (0);
}
