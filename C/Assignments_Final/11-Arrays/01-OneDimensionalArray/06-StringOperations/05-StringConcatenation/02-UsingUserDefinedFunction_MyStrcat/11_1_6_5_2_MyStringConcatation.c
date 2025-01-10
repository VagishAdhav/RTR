#include <stdio.h>

#define MAX_STRING_LENGTH (512)

int main(void)
{
    // function prototype
    void vvaStrcat(char[], char[]);

    // variable declarations
    char chArray_One_vva[MAX_STRING_LENGTH], chArray_Two_vva[MAX_STRING_LENGTH]; // a character array is a string

    //code

    // *** STRING INPUT ****
    printf("\n\n");
    printf("Enter first string : \n\n");
    gets_s(chArray_One_vva, MAX_STRING_LENGTH);

    printf("\n\n");
    printf("Enter second string : \n\n");
    gets_s(chArray_Two_vva, MAX_STRING_LENGTH);

    // *** STRING CONCAT ***
    printf("\n\n");
    printf("****** BEFORE CONCATENATION**************");
    printf("\n\n");
    printf("The original first string entered by you (i.e. : 'chArray_one[]) is : \n\n");
    printf("%s\n", chArray_One_vva);

    printf("\n\n");
    printf("The original second string entered by you (i.e. : 'chArray_Two_vva[]) is : \n\n");
    printf("%s\n", chArray_Two_vva);

    vvaStrcat(chArray_One_vva, chArray_Two_vva);

    printf("\n\n");
    printf("****** AFTER CONCATENATION *********");
    printf("\n\n");
    printf("'chArray_One_vva[]' is : \n\n");
    printf("%s\n", chArray_One_vva);

    printf("\n\n");
    printf("'chArray_Two_vva[]' is : \n\n");
    printf("%s\n", chArray_Two_vva);

    return (0);
}

void vvaStrcat(char str_destination[], char str_source[])
{
    // function prototype 
    int vvaStrlen(char[]);

    // variable declaration
    int iStringLength_Source_vva = 0, iStringLength_Destination_vva = 0;
    int i_vva, j_vva;

    //code
    iStringLength_Source_vva = vvaStrlen(str_source);
    iStringLength_Destination_vva = vvaStrlen(str_destination);

    // last valid index of an array is length-1, as index begins from 0,
    // concatenation of second array must begin from length of the first array
    // which means we start with copying first index for str_source into the last index + 1 of str_destination
    for (i_vva = iStringLength_Destination_vva, j_vva = 0; j_vva < iStringLength_Source_vva; i_vva++, j_vva++)
    {
        str_destination[i_vva] = str_source[j_vva];
    }

    str_destination[i_vva] = '\0';
}


int vvaStrlen(char str_vva[])
{
    // variable declarations 
    int j_vva;
    int vva_string_length = 0;

    // code
    // ** DETERMINING EXACT LENGTH OF THE STRING BY DETECTING THE FIRST OCCURRENCE OF NULL TERMINATING CHARACTER (\0) ***
    for (j_vva = 0; j_vva < MAX_STRING_LENGTH; j_vva++)
    {
        if (str_vva[j_vva] == '\0')
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