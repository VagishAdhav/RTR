#include <stdio.h>

#define INT_ARRAY_SIZE 10
#define FLOAT_ARRAY_SIZE 5
#define CHAR_ARRAY_SIZE 26

#define num_vva_STRINGS 10
#define MAX_CHARACTERS_PER_STRING 20

#define ALPHABET_BEGINNING 65 // 'A'

struct MyDataOne
{
    int iArray_vva[INT_ARRAY_SIZE];
    float fArray_vva[FLOAT_ARRAY_SIZE];
};

struct MyDataTwo
{
    char cArray_vva[CHAR_ARRAY_SIZE];
    char vva_strArray[num_vva_STRINGS][MAX_CHARACTERS_PER_STRING];
};

int main(void)
{
    // variable declaration
    struct MyDataOne data_vva_one;
    struct MyDataTwo data_vva_two;
    int i_vva;

    //code
    // ** PIECE MEAL ASSIGNMENT (HARD-CODED) **
    data_vva_one.fArray_vva[0] = 0.1f;
    data_vva_one.fArray_vva[1] = 1.2f;
    data_vva_one.fArray_vva[2] = 2.3f;
    data_vva_one.fArray_vva[3] = 3.4f;
    data_vva_one.fArray_vva[4] = 4.5f;

    // ** Loop Assignment (USER INPUT) ***
    printf("\n\n");
    printf("Enter %d integers : \n\n", INT_ARRAY_SIZE);
    for (i_vva = 0; i_vva < INT_ARRAY_SIZE; i_vva++)
    {
        scanf("%d", &data_vva_one.iArray_vva[i_vva]);
    }

    // ** LOOP Assignment hard coded ***
    for ( i_vva = 0; i_vva < CHAR_ARRAY_SIZE; i_vva++)
    {
        data_vva_two.cArray_vva[i_vva] = (char)(i_vva + ALPHABET_BEGINNING);
    }

    // ** PIECE MEAL ASSIGNMENT (HARD-CODED) **
    strcpy(data_vva_two.vva_strArray[0], "Welcome !!!");
    strcpy(data_vva_two.vva_strArray[1], "This");
    strcpy(data_vva_two.vva_strArray[2], "is");
    strcpy(data_vva_two.vva_strArray[3], "ASTROMEDICOMP's");
    strcpy(data_vva_two.vva_strArray[4], "Real");
    strcpy(data_vva_two.vva_strArray[5], "Time");
    strcpy(data_vva_two.vva_strArray[6], "Rendering");
    strcpy(data_vva_two.vva_strArray[7], "Batch");
    strcpy(data_vva_two.vva_strArray[8], "Of");
    strcpy(data_vva_two.vva_strArray[9], "2024-2025 !!!");

    // ** displaying data members of 'struct DataOne' and their values
    printf("\n\n");
    printf("Members of 'struct data_vva_one' along with their assigned values are : \n\n");

    printf("\n\n");
    printf("Integer array (data_vva_one.iArray_vva[]) : \n\n");
    for (i_vva = 0; i_vva < INT_ARRAY_SIZE; i_vva++)
        printf("data_vva_one.iArray_vva[%d] = %d\n", i_vva, data_vva_one.iArray_vva[i_vva]);

    printf("\n\n");
    printf("Floating-int array (data_vva_one.fArray_vva[]) : \n\n");
    for (i_vva = 0; i_vva < FLOAT_ARRAY_SIZE; i_vva++)
        printf("data_vva_one.fArray_vva[%d] = %f\n", i_vva, data_vva_one.fArray_vva[i_vva]);

    // ** displaying data members of 'struct DataTwo' and their values
    printf("\n\n");
    printf("Members of 'struct data_vva_two' along with their assigned values are : \n\n");

    printf("\n\n");
    printf("Integer array (data_vva_two.cArray_vva[]) : \n\n");
    for (i_vva = 0; i_vva < CHAR_ARRAY_SIZE; i_vva++)
        printf("data_vva_two.cArray_vva[%d] = %c\n", i_vva, data_vva_two.cArray_vva[i_vva]);

    printf("\n\n");
    printf("Sting array (data_vva_two.vva_strArray[]) : \n\n");
    for (i_vva = 0; i_vva < num_vva_STRINGS; i_vva++)
        printf("%s ", data_vva_two.vva_strArray[i_vva]);


    printf("\n\n");
    return 0;   
}