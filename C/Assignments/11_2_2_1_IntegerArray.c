#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vvaArray[3][5]; // 3 rows (0, 1 ,2) and 5 columns ( 0,1,2,3,4)
    int i_vvant_size;
    int i_vvaArray_size;
    int i_vvaArray_num_vva_elements, i_vvaArray_num_vva_rows, i_vvaArray_num_vva_columns;
    int i_vva, vva_j;

    // code 
    printf("\n\n");

    i_vvant_size = sizeof(int);

    i_vvaArray_size = sizeof(i_vvaArray);
    printf("Size of a two dimensional (2D) integer array i s= %d\n\n", i_vvaArray_size);

    i_vvaArray_num_vva_rows = sizeof(i_vvaArray)/ sizeof (i_vvaArray[0]);
    printf("number of rows in two dimensional (2D) integer array i s= %d\n\n", i_vvaArray_num_vva_rows);

    i_vvaArray_num_vva_columns = sizeof(i_vvaArray[0])/i_vvant_size;
    printf("number of columns in two dimensional (2D) integer array is = %d \n\n", i_vvaArray_num_vva_columns);

    i_vvaArray_num_vva_elements = i_vvaArray_num_vva_rows * i_vvaArray_num_vva_columns;
    printf("number of elements in two dimensional (2D) integer array is = %d\n\n", i_vvaArray_num_vva_elements);

    printf("\n\n");
    printf("Elements in 2D array : \n\n");

    // *** PIECE MEAL ASSIGNMENT ********
    // *********ROW1****************
    i_vvaArray[0][0] = 21;
    i_vvaArray[0][1] = 42;
    i_vvaArray[0][2] = 63;
    i_vvaArray[0][3] = 84;
    i_vvaArray[0][4] = 105;


    // *********ROW2****************
    i_vvaArray[1][0] = 22;
    i_vvaArray[1][1] = 44;
    i_vvaArray[1][2] = 66;
    i_vvaArray[1][3] = 88;
    i_vvaArray[1][4] = 110;

    // *********ROW3****************
    i_vvaArray[2][0] = 23;
    i_vvaArray[2][1] = 46;
    i_vvaArray[2][2] = 69;
    i_vvaArray[2][3] = 92;
    i_vvaArray[2][4] = 115;

    // **** DISPLAY************
    for (int i_vva = 0; i_vva < i_vvaArray_num_vva_rows; i_vva++)
    {
        printf("******* ROW %d*************\n", (i_vva + 1));
        for (vva_j = 0; vva_j < i_vvaArray_num_vva_columns; vva_j++)
        {
            printf("i_vvaArray[%d][%d] = %d\n", i_vva, vva_j, i_vvaArray[i_vva][vva_j]);
        }
        printf("\n\n");
    }

    return (0);
}