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
    char c_vvah;
    int c_vvah_value;

    //code
    printf("\n\n");

    printf("Enter character : ");
    c_vvah = getch();

    printf("\n\n");

    if (c_vvah == 'A' || c_vvah == 'a' ||\
        c_vvah == 'O' || c_vvah == 'o' ||\
        c_vvah == 'I' || c_vvah == 'i' ||\
        c_vvah == 'E' || c_vvah == 'e' ||\
        c_vvah == 'U' || c_vvah == 'u')
    {
        printf("Character \'%c\' entered by you is a VOWEL character from the english alphabet !!! \n\n", c_vvah);
    }
    else
    {
        c_vvah_value = (int)c_vvah;
        
        //if the character has ASCII value between 65 and 90 or between 97 and 122,
        // it is still A letter of the alphabet but it is a 'CONSONANT' and not 'VOWEL'

        if ((c_vvah_value >= CHAR_ALPHABET_UPPER_CASE_BEGINNING ) && (c_vvah_value <= CHAR_ALPHABET_UPPER_CASE_ENDING) ||
            (c_vvah_value >= CHAR_ALPHABET_LOWER_CASE_BEGINNING ) && (c_vvah_value <= CHAR_ALPHABET_LOWER_CASE_ENDING))
        {
            printf("Character \'%c\' entered by you is a CONSTANT character from the english alphabet !!! \n\n", c_vvah);
        }
        else if (c_vvah_value >= CHAR_DIGIT_BEGINNING && c_vvah_value <= CHAR_DIGIT_ENDING)
        {
            printf("Character \'%c\' entered by you is a DIGIT character !!! \n\n", c_vvah);
        }
        else
        {
            printf("Character \'%c\' entered by you is SPECIAL character !!! \n\n", c_vvah);
        }
    }

    return (0);
}
