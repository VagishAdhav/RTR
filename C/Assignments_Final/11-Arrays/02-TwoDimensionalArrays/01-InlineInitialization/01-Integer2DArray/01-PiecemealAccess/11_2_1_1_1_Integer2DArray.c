#include <stdio.h>

int main(void)
{
    // variable declarations
    int iArray_vva[5][3] = {{1, 2, 3}, {2, 4, 6}, {3, 6, 9}, {4, 8, 12}, {5, 10, 15}}; // in line initialisation
    int int_size_vva;
    int iArray_size_vva;
    int iArray_num_elements_vva, iArray_num_rows_vva, iArray_num_columns_vva;

    // code
    printf("\n\n");

    int_size_vva = sizeof(int);
    
    iArray_size_vva = sizeof(iArray_vva);
    printf("Size of Two dimensional (2D) integer array is = %d\n\n", iArray_size_vva);

    iArray_num_rows_vva = iArray_size_vva / sizeof(iArray_vva[0]);
    printf("number of rows in two dimensional (2D) integer array is = %d\n\n", iArray_num_rows_vva);

    iArray_num_columns_vva = sizeof(iArray_vva[0]) / int_size_vva;
    printf("number of columns in two dimensional (2D) integer array is = %d\n\n", iArray_num_columns_vva);

    iArray_num_elements_vva = iArray_num_rows_vva * iArray_num_columns_vva;
    printf("number of elements in two dimensional (2D) integer array is = %d\n\n", iArray_num_elements_vva);

    printf("\n\n");
    printf("Elements in the 2D array : \n\n");

    // array indices begin from 0, hence 1st row is actually oth row and 1st column is actually 0th column

    // **** ROW 1****
    printf("********** ROW 1 ************\n");
    printf("iArray_vva[0][0] = %d\n", iArray_vva[0][0]); // *** COLUMN 1 *** (0th element)
    printf("iArray_vva[0][1] = %d\n", iArray_vva[0][1]); // *** COLUMN 2 *** (1st element)
    printf("iArray_vva[0][2] = %d\n", iArray_vva[0][2]); // *** COLUMN 3 *** (2nd element)

    printf("\n\n");

    // **** ROW 2****
    printf("********** ROW 2 ************\n");
    printf("iArray_vva[1][0] = %d\n", iArray_vva[1][0]); // *** COLUMN 1 *** (0th element)
    printf("iArray_vva[1][1] = %d\n", iArray_vva[1][1]); // *** COLUMN 2 *** (1st element)
    printf("iArray_vva[1][2] = %d\n", iArray_vva[1][2]); // *** COLUMN 3 *** (2nd element)

    printf("\n\n");

    // **** ROW 3****
    printf("********** ROW 3 ************\n");
    printf("iArray_vva[2][0] = %d\n", iArray_vva[2][0]); // *** COLUMN 1 *** (0th element)
    printf("iArray_vva[2][1] = %d\n", iArray_vva[2][1]); // *** COLUMN 2 *** (1st element)
    printf("iArray_vva[2][2] = %d\n", iArray_vva[2][2]); // *** COLUMN 3 *** (2nd element)

    printf("\n\n");

    
    // **** ROW 4****
    printf("********** ROW 3 ************\n");
    printf("iArray_vva[3][0] = %d\n", iArray_vva[3][0]); // *** COLUMN 1 *** (0th element)
    printf("iArray_vva[3][1] = %d\n", iArray_vva[3][1]); // *** COLUMN 2 *** (1st element)
    printf("iArray_vva[3][2] = %d\n", iArray_vva[3][2]); // *** COLUMN 3 *** (2nd element)

    printf("\n\n");



    // **** ROW 5****
    printf("********** ROW 3 ************\n");
    printf("iArray_vva[4][0] = %d\n", iArray_vva[4][0]); // *** COLUMN 1 *** (0th element)
    printf("iArray_vva[4][1] = %d\n", iArray_vva[4][1]); // *** COLUMN 2 *** (1st element)
    printf("iArray_vva[4][2] = %d\n", iArray_vva[4][2]); // *** COLUMN 3 *** (2nd element)

    printf("\n\n");

    return(0);
}