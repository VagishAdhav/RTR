#include <stdio.h>

// MACRO CONST USED AS ARRAY SIZE IN SUBSCRIPT AND AS ARRAY LENGTH.
// HENCE, THIS PROGRAM'S ARRAY SIZE CAN BE SIMPLY CHANGED BY CHANGING THESE
// FOLLOWING THREE GLOBAL MACRO CONST VALUES, BEFORE COMPILING, LINKING AND EXECUTING THE PROGRAM !!!


#define INT_ARRAY_num_vva_ELEMENTS 5
#define FLOAT_ARRAY_num_vva_ELEMENTS 3
#define CHAR_ARRAY_num_vva_ELEMENTS 15

int main(void)
{
    // variable declaration 
    int i_vvaArray[INT_ARRAY_num_vva_ELEMENTS];
    float f_vvaArray[FLOAT_ARRAY_num_vva_ELEMENTS];
    char c_vvaArray[CHAR_ARRAY_num_vva_ELEMENTS];
    int i_vva, vva_num_vva;

    // code 
    // *** Array elements input ****
    printf("\n\n");
    printf("Enter elements for 'integer' array : \n");
    for (i_vva = 0; i_vva < INT_ARRAY_num_vva_ELEMENTS; i_vva++)
    {
        scanf("%d", &i_vvaArray[i_vva]);
    }

    printf("\n\n");
    printf("Enter elements for 'floating point' array : \n");
    for (i_vva = 0; i_vva < FLOAT_ARRAY_num_vva_ELEMENTS; i_vva++)
    {
        scanf("%f", &f_vvaArray[i_vva]);
    }

    printf("\n\n");
    printf("Enter elements for 'character' array : \n");
    for (i_vva = 0; i_vva < CHAR_ARRAY_num_vva_ELEMENTS; i_vva++)
    {
        scanf("%c", &c_vvaArray[i_vva]);
    }


    // *** Array elements output
    printf("Integer array entered by you: \n\n");
    for (i_vva = 0; i_vva < INT_ARRAY_num_vva_ELEMENTS; i_vva++)
    {
        printf("%d\n", i_vvaArray[i_vva]);
    }

    printf("\n\n");
    printf("Floating-point array entered by you: : \n");
    for (i_vva = 0; i_vva < FLOAT_ARRAY_num_vva_ELEMENTS; i_vva++)
    {
        printf("%f\n", f_vvaArray[i_vva]);
    }

    printf("\n\n");
    printf("Character array entered by you: : \n");
    for (i_vva = 0; i_vva < CHAR_ARRAY_num_vva_ELEMENTS; i_vva++)
    {
        printf("%c\n", c_vvaArray[i_vva]);
    }

    return (0);


}

