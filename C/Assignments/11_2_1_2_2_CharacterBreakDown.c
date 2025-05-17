#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    int vva_MyStrlen(char[]);

    // variable declaration 

    // *** A 'STRING' is an array of characters so char[] is a char array and hence char[] is a string ***
    // *** An array of char array is an array of strings !!!****
    // *** hence char[] is one char array and hence is one string 
    // *** hence char[][] is an array of char array and hence an array of strings

    // Here, the string array can allow a maximum number of 10 strings(10 rows) and each of these 10 strings can have only upto 15 characters (15 columns)
    char vva_strArray[10][15] = {"Hello!", "Welcome", "To", "Real", "Time", "Rendering", "Batch", "(2024-25)", "Of", "ASTROMEDICOMP."}; // in-line initialisation

    int i_vvaStrLengths[10]; // 1d integer array stores lengths of all strings in i_vvaStrArray,
    // e.g. i_vvaStrLength[0] will hold length of string i_vvaString[0] and so o.
    int vva_strArray_size;
    int vva_strArray_num_vva_rows;
    int i_vva, vva_j;

    //code
    vva_strArray_size = sizeof(vva_strArray);
    vva_strArray_num_vva_rows = vva_strArray_size / sizeof(vva_strArray[0]);

    // storing lengths of all the strings..
    for (i_vva = 0; i_vva < vva_strArray_num_vva_rows; i_vva++)
    {
       i_vvaStrLengths[i_vva] = vva_MyStrlen(vva_strArray[i_vva]);
       printf("Length %d, ", i_vvaStrLengths[i_vva]);
    }

    printf("\n\n");
    printf("The entire string array : \n\n");
    for (i_vva = 0; i_vva < vva_strArray_num_vva_rows; i_vva++)
        printf("%s ", vva_strArray[i_vva]);

    printf("\n\n");
    printf("String in the 2d array : \n\n");

    // Since char[][] is an array of strings, referencing only by the row number (first []) will give the row of the string
    // The column number (second []) is the particular character in that string / row

    for (i_vva = 0; i_vva < vva_strArray_num_vva_rows; i_vva++)
    {
        printf("\nString number %d => %s\n", (i_vva + 1), vva_strArray[i_vva]);
        for (vva_j = 0; vva_j < i_vvaStrLengths[i_vva]; vva_j++)
        {
            printf("Character %d = %c\n", (vva_j + 1), vva_strArray[i_vva][vva_j]);
        }
    }

    return (0);
}

int vva_MyStrlen(char str[])
{
    //variable declarations
    int vva_j;
    int vva_string_length = 0;

    //code 
    // ** determining exact length of the string by deciding the first occurrence of null terminating character (\o) ***
    for (vva_j = 0; vva_j < MAX_STRING_LENGTH; vva_j++)
    {
        if (str[vva_j] == '\0')
            break;
        else
            vva_string_length++;
    }

    return(vva_string_length);
}