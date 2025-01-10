#include <stdio.h>

int main(void)
{
    // variable declaration
    int iArray_vva[3][5]; // 3 rows (0, 1 ,2) and 5 columns ( 0,1,2,3,4)
    int int_size_vva;
    int iArray_size_vva;
    int iArray_num_elements_vva, iArray_num_rows_vva, iArray_num_columns_vva;
    int i_vva, j_vva;

    // code 
    printf("\n\n");

    int_size_vva = sizeof(int);

    iArray_size_vva = sizeof(iArray_vva);
    printf("Size of a two dimensional (2D) integer array i s= %d\n\n", iArray_size_vva);

    iArray_num_rows_vva = sizeof(iArray_vva)/ sizeof (iArray_vva[0]);
    printf("number of rows in two dimensional (2D) integer array i s= %d\n\n", iArray_num_rows_vva);

    iArray_num_columns_vva = sizeof(iArray_vva[0])/int_size_vva;
    printf("number of columns in two dimensional (2D) integer array is = %d \n\n", iArray_num_columns_vva);

    iArray_num_elements_vva = iArray_num_rows_vva * iArray_num_columns_vva;
    printf("number of elements in two dimensional (2D) integer array is = %d\n\n", iArray_num_elements_vva);

    printf("\n\n");
    printf("Elements in 2D array : \n\n");

    // *** PIECE MEAL ASSIGNMENT ********
    // *********ROW1****************
    iArray_vva[0][0] = 21;
    iArray_vva[0][1] = 42;
    iArray_vva[0][2] = 63;
    iArray_vva[0][3] = 84;
    iArray_vva[0][4] = 105;


    // *********ROW2****************
    iArray_vva[1][0] = 22;
    iArray_vva[1][1] = 44;
    iArray_vva[1][2] = 66;
    iArray_vva[1][3] = 88;
    iArray_vva[1][4] = 110;

    // *********ROW3****************
    iArray_vva[2][0] = 23;
    iArray_vva[2][1] = 46;
    iArray_vva[2][2] = 69;
    iArray_vva[2][3] = 92;
    iArray_vva[2][4] = 115;

    // **** DISPLAY************
    for (int i_vva = 0; i_vva < iArray_num_rows_vva; i_vva++)
    {
        printf("******* ROW %d*************\n", (i_vva + 1));
        for (j_vva = 0; j_vva < iArray_num_columns_vva; j_vva++)
        {
            printf("iArray_vva[%d][%d] = %d\n", i_vva, j_vva, iArray_vva[i_vva][j_vva]);
        }
        printf("\n\n");
    }

    return (0);
}