#include <stdio.h>

int main(void)
{
    // variable declarations
    int i_vvaArray[5][3] = {{1, 2, 3}, {2, 4, 6}, {3, 6, 9}, {4, 8, 12}, {5, 10, 15}}; // in line initialisation
    int i_vvant_size;
    int i_vvaArray_size;
    int i_vvaArray_num_vva_elements, i_vvaArray_num_vva_rows, i_vvaArray_num_vva_columns;
    int i_vva, vva_j;

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

   for (i_vva = 0; i_vva < i_vvaArray_num_vva_rows; i_vva++)
   {
        printf("****** ROW %d ********\n", (i_vva + 1));
        for (vva_j = 0; vva_j < i_vvaArray_num_vva_columns; vva_j++)
        {
            printf("i_vvaArray[%d][%d] = %d\n", i_vva, vva_j, i_vvaArray[i_vva][vva_j]);
        }
        printf("\n\n");
   }

    return(0);
}