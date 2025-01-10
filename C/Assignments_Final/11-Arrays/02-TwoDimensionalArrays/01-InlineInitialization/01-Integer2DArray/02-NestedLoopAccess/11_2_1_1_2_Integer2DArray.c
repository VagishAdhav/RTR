#include <stdio.h>

int main(void)
{
    // variable declarations
    int iArray_vva[5][3] = {{1, 2, 3}, {2, 4, 6}, {3, 6, 9}, {4, 8, 12}, {5, 10, 15}}; // in line initialisation
    int int_size_vva;
    int iArray_size_vva;
    int iArray_num_elements_vva, iArray_num_rows_vva, iArray_num_columns_vva;
    int i_vva, j_vva;

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

   for (i_vva = 0; i_vva < iArray_num_rows_vva; i_vva++)
   {
        printf("****** ROW %d ********\n", (i_vva + 1));
        for (j_vva = 0; j_vva < iArray_num_columns_vva; j_vva++)
        {
            printf("iArray_vva[%d][%d] = %d\n", i_vva, j_vva, iArray_vva[i_vva][j_vva]);
        }
        printf("\n\n");
   }

    return(0);
}