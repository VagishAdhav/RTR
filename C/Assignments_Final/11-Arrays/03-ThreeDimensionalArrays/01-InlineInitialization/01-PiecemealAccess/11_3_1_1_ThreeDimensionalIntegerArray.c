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

    // *** PIECE-MEAL DISPLAY***
    // *** ROW 1 ***
    printf("**** ROW 1 ******\n");
    printf("****COLUMN 1******\n");
    printf("iArray_vva[0][0][0] = %d\n", iArray_vva[0][0][0]);
    printf("iArray_vva[0][0][1] = %d\n", iArray_vva[0][0][1]);
    printf("\n");

    printf("****COLUMN 2******\n");
    printf("iArray_vva[0][1][0] = %d\n", iArray_vva[0][1][0]);
    printf("iArray_vva[0][1][1] = %d\n", iArray_vva[0][1][1]);
    printf("\n");

    printf("****COLUMN 3******\n");
    printf("iArray_vva[0][2][0] = %d\n", iArray_vva[0][2][0]);
    printf("iArray_vva[0][2][1] = %d\n", iArray_vva[0][2][1]);
    printf("\n");

    // *** ROW 2 ***
    printf("**** ROW 2 ******\n");
    printf("****COLUMN 1******\n");
    printf("iArray_vva[1][0][0] = %d\n", iArray_vva[1][0][0]);
    printf("iArray_vva[1][0][1] = %d\n", iArray_vva[1][0][1]);
    printf("\n");

    printf("****COLUMN 2******\n");
    printf("iArray_vva[1][1][0] = %d\n", iArray_vva[1][1][0]);
    printf("iArray_vva[1][1][1] = %d\n", iArray_vva[1][1][1]);
    printf("\n");

    printf("****COLUMN 3******\n");
    printf("iArray_vva[1][2][0] = %d\n", iArray_vva[1][2][0]);
    printf("iArray_vva[1][2][1] = %d\n", iArray_vva[1][2][1]);
    printf("\n");

    // *** ROW 3 ***
    printf("**** ROW 3 ******\n");
    printf("****COLUMN 1******\n");
    printf("iArray_vva[2][0][0] = %d\n", iArray_vva[2][0][0]);
    printf("iArray_vva[2][0][1] = %d\n", iArray_vva[2][0][1]);
    printf("\n");

    printf("****COLUMN 2******\n");
    printf("iArray_vva[2][1][0] = %d\n", iArray_vva[2][1][0]);
    printf("iArray_vva[2][1][1] = %d\n", iArray_vva[2][1][1]);
    printf("\n");

    printf("****COLUMN 3******\n");
    printf("iArray_vva[2][2][0] = %d\n", iArray_vva[2][2][0]);
    printf("iArray_vva[2][2][1] = %d\n", iArray_vva[2][2][1]);
    printf("\n");

    // *** ROW 4 ***
    printf("**** ROW 4 ******\n");
    printf("****COLUMN 1******\n");
    printf("iArray_vva[3][0][0] = %d\n", iArray_vva[3][0][0]);
    printf("iArray_vva[3][0][1] = %d\n", iArray_vva[3][0][1]);
    printf("\n");

    printf("****COLUMN 2******\n");
    printf("iArray_vva[3][1][0] = %d\n", iArray_vva[3][1][0]);
    printf("iArray_vva[3][1][1] = %d\n", iArray_vva[3][1][1]);
    printf("\n");

    printf("****COLUMN 3******\n");
    printf("iArray_vva[3][2][0] = %d\n", iArray_vva[3][2][0]);
    printf("iArray_vva[3][2][1] = %d\n", iArray_vva[3][2][1]);
    printf("\n");

    // *** ROW 5 ***
    printf("**** ROW 1 ******\n");
    printf("****COLUMN 1******\n");
    printf("iArray_vva[4][0][0] = %d\n", iArray_vva[4][0][0]);
    printf("iArray_vva[4][0][1] = %d\n", iArray_vva[4][0][1]);
    printf("\n");

    printf("****COLUMN 2******\n");
    printf("iArray_vva[4][1][0] = %d\n", iArray_vva[4][1][0]);
    printf("iArray_vva[4][1][1] = %d\n", iArray_vva[4][1][1]);
    printf("\n");

    printf("****COLUMN 3******\n");
    printf("iArray_vva[4][2][0] = %d\n", iArray_vva[4][2][0]);
    printf("iArray_vva[4][2][1] = %d\n", iArray_vva[4][2][1]);
    printf("\n\n");

    return (0);
}

