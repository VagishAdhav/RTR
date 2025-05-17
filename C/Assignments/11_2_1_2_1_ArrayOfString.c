#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // function prototype
    int vva_MyStrlen(char[]);

    // variable declaration

    // *** A string is an array of characters.. so char[] is a char array and hence, char[] is a 'STRING' ***
    // *** An array of character array is an array of strings !!! ****
    // *** hence char[] is one char array and hence, is one string ***
    // *** hence char[][] is an array of char arrays and hence, is an array of strings ***


    // here, the string array can allow a maximum number of 10 strings (10 rows) and each of these 10 strings can have only upto 15 characters maximum (15 columns)

    char vva_strArray[10][15] = {"Hello!", "Welcome", "To", "Real", "Time", "Rendering", "Batch", "(2024-25)", "Of", "ASTROMEDICOMP."}; // in-line initialisation

    int c_vvahar_size;
    int vva_strArray_size;
    int vva_strArray_num_vva_elements, vva_strArray_num_vva_rows, vva_strArray_num_vva_columns;
    int vva_strActual_num_vva_chars = 0;
    int i_vva;

    // code
    printf("\n\n");

    c_vvahar_size = sizeof(char);
    
    vva_strArray_size = sizeof(vva_strArray);
    printf("Size of two dimensional (2D) character array (string array) is = %d\n\n", vva_strArray_size);

    vva_strArray_num_vva_rows = vva_strArray_size / sizeof(vva_strArray[0]);
    printf("number of rows(strings) in two dimensional (2D) character array (String array) is = %d\n\n", vva_strArray_num_vva_rows);

    vva_strArray_num_vva_columns = sizeof(vva_strArray[0]) / c_vvahar_size;
    printf("number of columns in two dimensional (2D) character array (String Array) is = %d\n\n", vva_strArray_num_vva_columns);

    vva_strArray_num_vva_elements = vva_strArray_num_vva_rows * vva_strArray_num_vva_columns;
    printf("Maximum number of elements (characters) in two dimensional (2D) character array (string array) is = %d\n\n", vva_strArray_num_vva_elements);

    for (i_vva = 0; i_vva < vva_strArray_num_vva_rows; i_vva++)
    {
        vva_strActual_num_vva_chars = vva_strActual_num_vva_chars + vva_MyStrlen(vva_strArray[i_vva]);
    }
    printf("Actual number of elements (characters) in two dimensional (2d) character array (string array) is = %d\n\n", vva_strActual_num_vva_chars);

    printf("\n\n");
    printf("Strings in the 2d array : \n\n");

    // print each row of the array 
    printf("%s ", vva_strArray[0]);
    printf("%s ", vva_strArray[1]);
    printf("%s ", vva_strArray[2]);
    printf("%s ", vva_strArray[3]);
    printf("%s ", vva_strArray[4]);
    printf("%s ", vva_strArray[5]);
    printf("%s ", vva_strArray[6]);
    printf("%s ", vva_strArray[7]);
    printf("%s ", vva_strArray[8]);
    printf("%s \n\n", vva_strArray[9]);

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