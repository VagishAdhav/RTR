#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

struct CharacterCount
{
    char ch;
    int ch_count;
} character_and_count[] = { {'A', 0}, // character_and_count[0].ch = 'A' & character_and_count[0].ch_count = 0
                            {'B', 0}, // character_and_count[0].ch = 'B' & character_and_count[0].ch_count = 0
                            {'C', 0}, // character_and_count[0].ch = 'C' & character_and_count[0].ch_count = 0
                            {'D', 0}, // character_and_count[0].ch = 'D' & character_and_count[0].ch_count = 0
                            {'E', 0}, // character_and_count[0].ch = 'E' & character_and_count[0].ch_count = 0
                            {'F', 0}, // character_and_count[0].ch = 'F' & character_and_count[0].ch_count = 0
                            {'G', 0}, // character_and_count[0].ch = 'G' & character_and_count[0].ch_count = 0
                            {'H', 0}, // character_and_count[0].ch = 'H' & character_and_count[0].ch_count = 0
                            {'I', 0}, // character_and_count[0].ch = 'I' & character_and_count[0].ch_count = 0
                            {'J', 0}, // character_and_count[0].ch = 'J' & character_and_count[0].ch_count = 0
                            {'K', 0}, // character_and_count[0].ch = 'K' & character_and_count[0].ch_count = 0
                            {'L', 0}, // character_and_count[0].ch = 'L' & character_and_count[0].ch_count = 0
                            {'M', 0}, // character_and_count[0].ch = 'M' & character_and_count[0].ch_count = 0
                            {'N', 0}, // character_and_count[0].ch = 'N' & character_and_count[0].ch_count = 0
                            {'O', 0}, // character_and_count[0].ch = 'O' & character_and_count[0].ch_count = 0
                            {'P', 0}, // character_and_count[0].ch = 'P' & character_and_count[0].ch_count = 0
                            {'Q', 0}, // character_and_count[0].ch = 'Q' & character_and_count[0].ch_count = 0
                            {'R', 0}, // character_and_count[0].ch = 'R' & character_and_count[0].ch_count = 0
                            {'S', 0}, // character_and_count[0].ch = 'S' & character_and_count[0].ch_count = 0
                            {'T', 0}, // character_and_count[0].ch = 'T' & character_and_count[0].ch_count = 0
                            {'U', 0}, // character_and_count[0].ch = 'U' & character_and_count[0].ch_count = 0
                            {'V', 0}, // character_and_count[0].ch = 'V' & character_and_count[0].ch_count = 0
                            {'W', 0}, // character_and_count[0].ch = 'W' & character_and_count[0].ch_count = 0
                            {'X', 0}, // character_and_count[0].ch = 'X' & character_and_count[0].ch_count = 0
                            {'Y', 0}, // character_and_count[0].ch = 'Y' & character_and_count[0].ch_count = 0
                            {'Z', 0} }; // character_and_count[0].ch = 'Z' & character_and_count[0].ch_count = 0

#define SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS sizeof(character_and_count)

#define SIZE_OF_ONE_STRUCT sizeof(character_and_count[0])

#define num_vva_ELEMENTS_IN_ARRAY (SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS/SIZE_OF_ONE_STRUCT)

//ENTRY POINT FUNCTIONS
int main(void)
{
    // variable declarations
    char vva_str[MAX_STRING_LENGTH];
    int i_vva, vva_j, a_vvactual_string_length = 0;

    //code
    printf("\n\n");
    printf("Enter A string : \n\n");
    gets_s(vva_str, MAX_STRING_LENGTH);

    a_vvactual_string_length = strlen(vva_str);

    printf("\n\n");
    printf("The string you have entered i s: \n\n");
    printf("%s\n\n", vva_str);

    for (i_vva = 0; i_vva < a_vvactual_string_length; i_vva++)
    {
        for (vva_j = 0; vva_j < num_vva_ELEMENTS_IN_ARRAY; vva_j++) // run every character of the string input through the entire alphabet ( A to Z)
        {
            vva_str[i_vva] = toupper(vva_str[i_vva]); // if input character is in lower case, convert it into upper case for comparison

            if (vva_str[i_vva] == character_and_count[vva_j].ch)
                character_and_count[vva_j].ch_count++; // increment its count by 1
        }
    }


    printf("\n\n");
    printf("The number of occurrences of ALL characters from the alphabet are as follows : \n\n");
    for (i_vva = 0; i_vva < num_vva_ELEMENTS_IN_ARRAY; i_vva++)
    {
        printf("character %c = %d\n", character_and_count[i_vva].ch, character_and_count[i_vva].ch_count);
    }
    printf("\n\n");

    return (0);
    
}