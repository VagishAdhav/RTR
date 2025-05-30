#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // variable declarations

    // *** A string is an array of characters .. so char[] is a char array and hence, char[] is a string
    // ** An array of char is a array of string !!! ***
    // *** Hence, char[] is one char array i.e. a string
    // *** Hence char[][] is an array of char arrays and hence array of strings ***

    // Here, the string array can allow a maximum number of 5 strings (5 rows) and each of these strings can have only upto 10 characters(max 10 columns)
    char vva_strArray[5][10]; // 5 rows (0,1,2,3,4,5) -> 5 strings (each string can have a maximum of 20 characters)
    int c_vvahar_size;
    int vva_strArray_size;
    int vva_strArray_num_vva_elements, vva_strArray_num_vva_rows, vva_strArray_num_vva_columns;
    int i_vva;

    //code
    printf("\n\n");
    c_vvahar_size = sizeof(char);

    vva_strArray_size = sizeof(vva_strArray);
    printf("Size of two dimensional (2d) character array (string array) is= %d \n\n", vva_strArray_size);

    vva_strArray_num_vva_rows = vva_strArray_size / sizeof(vva_strArray[0]);
    printf("number of rows(strings) in two dimensional character array (string array) is = %d\n\n", vva_strArray_num_vva_rows);

    vva_strArray_num_vva_columns = sizeof(vva_strArray[0]) / c_vvahar_size;
    printf("number of columns in two dimensional (2D) character array (string array) is - %d\n\n", vva_strArray_num_vva_columns);

    vva_strArray_num_vva_elements = vva_strArray_num_vva_rows * vva_strArray_num_vva_columns;
    printf("Maximum number of elements (character) in two dimensional (2D) character array (string array) is = %d\n\n", vva_strArray_num_vva_elements);

    // **PIECE-MEAL ASSIGNMENT ******
    // ***** ROW 1 /STRING 1 ******
    vva_strArray[0][0] = 'M';
    vva_strArray[0][1] = 'y';
    vva_strArray[0][2] = '\0'; // NULL Terminating character

    // *** *ROW 2 / STRING 2 ******
    vva_strArray[1][0] = 'n';
    vva_strArray[1][1] = 'a';
    vva_strArray[1][2] = 'm';
    vva_strArray[1][3] = 'e';
    vva_strArray[1][4] = '\0'; // NULL Terminating character

    // *** ROW3 / String 3
    vva_strArray[2][0] = 'i';
    vva_strArray[2][1] = 's';
    vva_strArray[2][2] = '\0'; // NULL Terminating character


    // *** *ROW 4 / STRING 4 ******
    vva_strArray[3][0] = 'V';
    vva_strArray[3][1] = 'a';
    vva_strArray[3][2] = 'g';
    vva_strArray[3][3] = 'i';
    vva_strArray[3][4] = 's';
    vva_strArray[3][5] = 'h';
    vva_strArray[3][6] = '\0'; // NULL Terminating character

    // *** *ROW 5 / STRING 5 ******
   vva_strArray[4][0] = 'A';
   vva_strArray[4][1] = 'd';
   vva_strArray[4][2] = 'h';
   vva_strArray[4][3] = 'a';
   vva_strArray[4][4] = 'v';
   vva_strArray[4][5] = '\0'; // NULL Terminating character
    
    printf("\n\n");
    printf("The string is the 2d character array are : \n\n");

    for (i_vva = 0; i_vva < vva_strArray_num_vva_rows; i_vva++)
    {
        printf("%s ", vva_strArray[i_vva]);
    }

    printf("\n\n");

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