#include <stdio.h>
int main(void)
{
    // variable declaration
    //in line initialization

    int iArray_vva[5][3][2] = \
        {  { {9, 18}, {27, 36}, {45, 54} },
           { {8, 16}, {24, 32}, {40, 48} },
           { {7, 14}, {21, 28}, {35, 42} },
           { {6, 12}, {18, 24}, {30, 36} },
           { {5, 10}, {15, 20}, {25, 30} }  };


    int int_size_vva;
    int iArray_size_vva;
    int iArray_num_elements_vva, iArray_width_vva, iArray_height_vva, iArray_depth_vva;
    int i_vva, j_vva, k_vva;

    //code
    printf("\n\n");

    int_size_vva = sizeof(int);

    iArray_size_vva = sizeof(iArray_vva);
    printf("Size of three dimensional (3D) integer array is = %d\n\n", iArray_size_vva);

    iArray_height_vva = iArray_size_vva / sizeof(iArray_vva[0]);
    printf("number of rows (height) in three dimensional (3D) integer array is = %d\n\n", iArray_height_vva);

    iArray_width_vva = sizeof(iArray_vva[0]) / sizeof(iArray_vva[0][0]);
    printf("number of columns(width) in three dimensional (3D) integer array is = %d\n\n", iArray_width_vva);

    iArray_depth_vva = sizeof(iArray_vva[0][0]) / int_size_vva;
    printf("Depth in three dimensional (3D) integer array is = %d\n\n", iArray_depth_vva);

    iArray_num_elements_vva = iArray_width_vva * iArray_height_vva * iArray_depth_vva;
    printf("number of elements in three dimensional (3D) integer array is = %d\n\n", iArray_num_elements_vva);

    printf("\n\n");
    printf("Elements in integer 3D array : \n\n");

    for (i_vva = 0; i_vva < iArray_height_vva; i_vva++)
    {
        printf("**** ROW %d****\n", (i_vva + 1));
        for (j_vva = 0; j_vva < iArray_width_vva; j_vva++)
        {
            printf("***** COLUMN %d ******\n", (j_vva + 1));
            for (k_vva = 0; k_vva < iArray_depth_vva; k_vva++)
            {
                printf("iArray_vva[%d][%d][%d] = %d\n", i_vva, j_vva, k_vva, iArray_vva[i_vva][j_vva][k_vva]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    return (0);
}

