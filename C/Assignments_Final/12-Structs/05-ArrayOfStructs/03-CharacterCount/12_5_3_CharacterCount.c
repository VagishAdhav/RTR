#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

struct CharacterCount
{
    char ch;
    int ch_count;
} character_and_count_vva[] = { {'A', 0}, // character_and_count_vva[0].ch = 'A' & character_and_count_vva[0].ch_count = 0
                            {'B', 0}, // character_and_count_vva[0].ch = 'B' & character_and_count_vva[0].ch_count = 0
                            {'C', 0}, // character_and_count_vva[0].ch = 'C' & character_and_count_vva[0].ch_count = 0
                            {'D', 0}, // character_and_count_vva[0].ch = 'D' & character_and_count_vva[0].ch_count = 0
                            {'E', 0}, // character_and_count_vva[0].ch = 'E' & character_and_count_vva[0].ch_count = 0
                            {'F', 0}, // character_and_count_vva[0].ch = 'F' & character_and_count_vva[0].ch_count = 0
                            {'G', 0}, // character_and_count_vva[0].ch = 'G' & character_and_count_vva[0].ch_count = 0
                            {'H', 0}, // character_and_count_vva[0].ch = 'H' & character_and_count_vva[0].ch_count = 0
                            {'I', 0}, // character_and_count_vva[0].ch = 'I' & character_and_count_vva[0].ch_count = 0
                            {'J', 0}, // character_and_count_vva[0].ch = 'J' & character_and_count_vva[0].ch_count = 0
                            {'K', 0}, // character_and_count_vva[0].ch = 'K' & character_and_count_vva[0].ch_count = 0
                            {'L', 0}, // character_and_count_vva[0].ch = 'L' & character_and_count_vva[0].ch_count = 0
                            {'M', 0}, // character_and_count_vva[0].ch = 'M' & character_and_count_vva[0].ch_count = 0
                            {'N', 0}, // character_and_count_vva[0].ch = 'N' & character_and_count_vva[0].ch_count = 0
                            {'O', 0}, // character_and_count_vva[0].ch = 'O' & character_and_count_vva[0].ch_count = 0
                            {'P', 0}, // character_and_count_vva[0].ch = 'P' & character_and_count_vva[0].ch_count = 0
                            {'Q', 0}, // character_and_count_vva[0].ch = 'Q' & character_and_count_vva[0].ch_count = 0
                            {'R', 0}, // character_and_count_vva[0].ch = 'R' & character_and_count_vva[0].ch_count = 0
                            {'S', 0}, // character_and_count_vva[0].ch = 'S' & character_and_count_vva[0].ch_count = 0
                            {'T', 0}, // character_and_count_vva[0].ch = 'T' & character_and_count_vva[0].ch_count = 0
                            {'U', 0}, // character_and_count_vva[0].ch = 'U' & character_and_count_vva[0].ch_count = 0
                            {'V', 0}, // character_and_count_vva[0].ch = 'V' & character_and_count_vva[0].ch_count = 0
                            {'W', 0}, // character_and_count_vva[0].ch = 'W' & character_and_count_vva[0].ch_count = 0
                            {'X', 0}, // character_and_count_vva[0].ch = 'X' & character_and_count_vva[0].ch_count = 0
                            {'Y', 0}, // character_and_count_vva[0].ch = 'Y' & character_and_count_vva[0].ch_count = 0
                            {'Z', 0} }; // character_and_count_vva[0].ch = 'Z' & character_and_count_vva[0].ch_count = 0

#define SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS sizeof(character_and_count_vva)

#define SIZE_OF_ONE_STRUCT sizeof(character_and_count_vva[0])

#define NUM_ELEMENTS_IN_ARRAY (SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS/SIZE_OF_ONE_STRUCT)

//ENTRY POINT FUNCTIONS
int main(void)
{
    // variable declarations
    char str_vva[MAX_STRING_LENGTH];
    int i_vva, j_vva, actual_string_length_vva = 0;

    //code
    printf("\n\n");
    printf("Enter A string : \n\n");
    gets_s(str_vva, MAX_STRING_LENGTH);

    actual_string_length_vva = strlen(str_vva);

    printf("\n\n");
    printf("The string you have entered i s: \n\n");
    printf("%s\n\n", str_vva);

    for (i_vva = 0; i_vva < actual_string_length_vva; i_vva++)
    {
        for (j_vva = 0; j_vva < NUM_ELEMENTS_IN_ARRAY; j_vva++) // run every character of the string input through the entire alphabet ( A to Z)
        {
            str_vva[i_vva] = toupper(str_vva[i_vva]); // if input character is in lower case, convert it into upper case for comparison

            if (str_vva[i_vva] == character_and_count_vva[j_vva].ch)
                character_and_count_vva[j_vva].ch_count++; // increment its count by 1
        }
    }


    printf("\n\n");
    printf("The number of occurrences of ALL characters from the alphabet are as follows : \n\n");
    for (i_vva = 0; i_vva < NUM_ELEMENTS_IN_ARRAY; i_vva++)
    {
        printf("character %c = %d\n", character_and_count_vva[i_vva].ch, character_and_count_vva[i_vva].ch_count);
    }
    printf("\n\n");

    return (0);
    
}