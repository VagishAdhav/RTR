#include <stdio.h>

// MACRO CONST USED AS ARRAY SIZE IN SUBSCRIPT AND AS ARRAY LENGTH.
// HENCE, THIS PROGRAM'S ARRAY SIZE CAN BE SIMPLY CHANGED BY CHANGING THESE
// FOLLOWING THREE GLOBAL MACRO CONST VALUES, BEFORE COMPILING, LINKING AND EXECUTING THE PROGRAM !!!


#define INT_ARRAY_NUM_ELEMENTS 5
#define FLOAT_ARRAY_NUM_ELEMENTS 3
#define CHAR_ARRAY_NUM_ELEMENTS 15

int main(void)
{
    // variable declaration 
    int vva_iArray[INT_ARRAY_NUM_ELEMENTS];
    float vva_fArray[FLOAT_ARRAY_NUM_ELEMENTS];
    char vva_cArray[CHAR_ARRAY_NUM_ELEMENTS];
    int vva_i, vva_num;

    // code 
    // *** Array elements input ****
    printf("\n\n");
    printf("Enter elements for 'integer' array : \n");
    for (vva_i = 0; vva_i < INT_ARRAY_NUM_ELEMENTS; vva_i++)
    {
        scanf("%d", &vva_iArray[vva_i]);
    }

    printf("\n\n");
    printf("Enter elements for 'floating point' array : \n");
    for (vva_i = 0; vva_i < FLOAT_ARRAY_NUM_ELEMENTS; vva_i++)
    {
        scanf("%f", &vva_fArray[vva_i]);
    }

    printf("\n\n");
    printf("Enter elements for 'character' array : \n");
    for (vva_i = 0; vva_i < CHAR_ARRAY_NUM_ELEMENTS; vva_i++)
    {
        scanf("%c", &vva_cArray[vva_i]);
    }


    // *** Array elements output
    printf("Integer array entered by you: \n\n");
    for (vva_i = 0; vva_i < INT_ARRAY_NUM_ELEMENTS; vva_i++)
    {
        printf("%d\n", vva_iArray[vva_i]);
    }

    printf("\n\n");
    printf("Floating-point array entered by you: : \n");
    for (vva_i = 0; vva_i < FLOAT_ARRAY_NUM_ELEMENTS; vva_i++)
    {
        printf("%f\n", vva_fArray[vva_i]);
    }

    printf("\n\n");
    printf("Character array entered by you: : \n");
    for (vva_i = 0; vva_i < CHAR_ARRAY_NUM_ELEMENTS; vva_i++)
    {
        printf("%c\n", vva_cArray[vva_i]);
    }

    return (0);


}

