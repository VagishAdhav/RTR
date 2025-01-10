#include <stdio.h>

int main(void)
{
    // variable declarations
    int i_vvaArray[5][3] = {{1, 2, 3}, {2, 4, 6}, {3, 6, 9}, {4, 8, 12}, {5, 10, 15}}; // in line initialisation
    int i_vvant_size;
    int i_vvaArray_size;
    int i_vvaArray_num_vva_elements, i_vvaArray_num_vva_rows, i_vvaArray_num_vva_columns;

    // code
    printf("\n\n");

    i_vvant_size = sizeof(int);
    
    i_vvaArray_size = sizeof(i_vvaArray);
    printf("Size of Two dimensional (2D) integer array is = %d\n\n", i_vvaArray_size);

    i_vvaArray_num_vva_rows = i_vvaArray_size / sizeof(i_vvaArray[0]);
    printf("number of rows in two dimensional (2D) integer array is = %d\n\n", i_vvaArray_num_vva_rows);

    i_vvaArray_num_vva_columns = sizeof(i_vvaArray[0]) / i_vvant_size;
    printf("number of columns in two dimensional (2D) integer array is = %d\n\n", i_vvaArray_num_vva_columns);

    i_vvaArray_num_vva_elements = i_vvaArray_num_vva_rows * i_vvaArray_num_vva_columns;
    printf("number of elements in two dimensional (2D) integer array is = %d\n\n", i_vvaArray_num_vva_elements);

    printf("\n\n");
    printf("Elements in the 2D array : \n\n");

    // array indices begin from 0, hence 1st row is actually oth row and 1st column is actually 0th column

    // **** ROW 1****
    printf("********** ROW 1 ************\n");
    printf("i_vvaArray[0][0] = %d\n", i_vvaArray[0][0]); // *** COLUMN 1 *** (0th element)
    printf("i_vvaArray[0][1] = %d\n", i_vvaArray[0][1]); // *** COLUMN 2 *** (1st element)
    printf("i_vvaArray[0][2] = %d\n", i_vvaArray[0][2]); // *** COLUMN 3 *** (2nd element)

    printf("\n\n");

    // **** ROW 2****
    printf("********** ROW 2 ************\n");
    printf("i_vvaArray[1][0] = %d\n", i_vvaArray[1][0]); // *** COLUMN 1 *** (0th element)
    printf("i_vvaArray[1][1] = %d\n", i_vvaArray[1][1]); // *** COLUMN 2 *** (1st element)
    printf("i_vvaArray[1][2] = %d\n", i_vvaArray[1][2]); // *** COLUMN 3 *** (2nd element)

    printf("\n\n");

    // **** ROW 3****
    printf("********** ROW 3 ************\n");
    printf("i_vvaArray[2][0] = %d\n", i_vvaArray[2][0]); // *** COLUMN 1 *** (0th element)
    printf("i_vvaArray[2][1] = %d\n", i_vvaArray[2][1]); // *** COLUMN 2 *** (1st element)
    printf("i_vvaArray[2][2] = %d\n", i_vvaArray[2][2]); // *** COLUMN 3 *** (2nd element)

    printf("\n\n");

    
    // **** ROW 4****
    printf("********** ROW 3 ************\n");
    printf("i_vvaArray[3][0] = %d\n", i_vvaArray[3][0]); // *** COLUMN 1 *** (0th element)
    printf("i_vvaArray[3][1] = %d\n", i_vvaArray[3][1]); // *** COLUMN 2 *** (1st element)
    printf("i_vvaArray[3][2] = %d\n", i_vvaArray[3][2]); // *** COLUMN 3 *** (2nd element)

    printf("\n\n");



    // **** ROW 5****
    printf("********** ROW 3 ************\n");
    printf("i_vvaArray[4][0] = %d\n", i_vvaArray[4][0]); // *** COLUMN 1 *** (0th element)
    printf("i_vvaArray[4][1] = %d\n", i_vvaArray[4][1]); // *** COLUMN 2 *** (1st element)
    printf("i_vvaArray[4][2] = %d\n", i_vvaArray[4][2]); // *** COLUMN 3 *** (2nd element)

    printf("\n\n");

    return(0);
}