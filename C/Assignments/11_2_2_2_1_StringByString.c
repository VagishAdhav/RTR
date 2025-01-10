#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    // function prototype
    void vva_MyStrcpy(char[], char[]);

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
    vva_MyStrcpy(vva_strArray[0], "My");
    vva_MyStrcpy(vva_strArray[1], "name");
    vva_MyStrcpy(vva_strArray[2], "is");
    vva_MyStrcpy(vva_strArray[3], "Vagish");
    vva_MyStrcpy(vva_strArray[4], "Adhav");
    
    printf("\n\n");
    printf("The string is the 2d character array are : \n\n");

    for (i_vva = 0; i_vva < vva_strArray_num_vva_rows; i_vva++)
    {
        printf("%s ", vva_strArray[i_vva]);
    }

    printf("\n\n");

    return (0);
}


void vva_MyStrcpy(char str_destination[], char str_source[])
{
    // function prototype
    int vva_MyStrlen(char[]);

    // variable declaration
    int i_vvaStringLength = 0;
    int vva_j;

    //code
    i_vvaStringLength = vva_MyStrlen(str_source);
    for (vva_j = 0; vva_j < i_vvaStringLength; vva_j++)
        str_destination[vva_j] = str_source[vva_j];

    str_destination[vva_j] = '\0';
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