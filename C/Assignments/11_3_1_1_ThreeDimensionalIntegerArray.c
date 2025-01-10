#include <stdio.h>


int main(void)
{
    // variable declaration
    //in line initialization

    int i_vvaArray[5][3][2] = \
        {  { {9, 18}, {27, 36}, {45, 54} },
           { {8, 16}, {24, 32}, {40, 48} },
           { {7, 14}, {21, 28}, {35, 42} },
           { {6, 12}, {18, 24}, {30, 36} },
           { {5, 10}, {15, 20}, {25, 30} }  };


    int i_vvant_size;
    int i_vvaArray_size;
    int i_vvaArray_num_vva_elements, i_vvaArray_width, i_vvaArray_height, i_vvaArray_depth;

    //code
    printf("\n\n");

    i_vvant_size = sizeof(int);

    i_vvaArray_size = sizeof(i_vvaArray);
    printf("Size of three dimensional (3D) integer array is = %d\n\n", i_vvaArray_size);

    i_vvaArray_height = i_vvaArray_size / sizeof(i_vvaArray[0]);
    printf("number of rows (height) in three dimensional (3D) integer array is = %d\n\n", i_vvaArray_height);

    i_vvaArray_width = sizeof(i_vvaArray[0]) / sizeof(i_vvaArray[0][0]);
    printf("number of columns(width) in three dimensional (3D) integer array is = %d\n\n", i_vvaArray_width);

    i_vvaArray_depth = sizeof(i_vvaArray[0][0]) / i_vvant_size;
    printf("Depth in three dimensional (3D) integer array is = %d\n\n", i_vvaArray_depth);

    i_vvaArray_num_vva_elements = i_vvaArray_width * i_vvaArray_height * i_vvaArray_depth;
    printf("number of elements in three dimensional (3D) integer array is = %d\n\n", i_vvaArray_num_vva_elements);

    printf("\n\n");
    printf("Elements in integer 3D array : \n\n");

    // *** PIECE-MEAL DISPLAY***
    // *** ROW 1 ***
    printf("**** ROW 1 ******\n");
    printf("****COLUMN 1******\n");
    printf("i_vvaArray[0][0][0] = %d\n", i_vvaArray[0][0][0]);
    printf("i_vvaArray[0][0][1] = %d\n", i_vvaArray[0][0][1]);
    printf("\n");

    printf("****COLUMN 2******\n");
    printf("i_vvaArray[0][1][0] = %d\n", i_vvaArray[0][1][0]);
    printf("i_vvaArray[0][1][1] = %d\n", i_vvaArray[0][1][1]);
    printf("\n");

    printf("****COLUMN 3******\n");
    printf("i_vvaArray[0][2][0] = %d\n", i_vvaArray[0][2][0]);
    printf("i_vvaArray[0][2][1] = %d\n", i_vvaArray[0][2][1]);
    printf("\n");

    // *** ROW 2 ***
    printf("**** ROW 2 ******\n");
    printf("****COLUMN 1******\n");
    printf("i_vvaArray[1][0][0] = %d\n", i_vvaArray[1][0][0]);
    printf("i_vvaArray[1][0][1] = %d\n", i_vvaArray[1][0][1]);
    printf("\n");

    printf("****COLUMN 2******\n");
    printf("i_vvaArray[1][1][0] = %d\n", i_vvaArray[1][1][0]);
    printf("i_vvaArray[1][1][1] = %d\n", i_vvaArray[1][1][1]);
    printf("\n");

    printf("****COLUMN 3******\n");
    printf("i_vvaArray[1][2][0] = %d\n", i_vvaArray[1][2][0]);
    printf("i_vvaArray[1][2][1] = %d\n", i_vvaArray[1][2][1]);
    printf("\n");

    // *** ROW 3 ***
    printf("**** ROW 3 ******\n");
    printf("****COLUMN 1******\n");
    printf("i_vvaArray[2][0][0] = %d\n", i_vvaArray[2][0][0]);
    printf("i_vvaArray[2][0][1] = %d\n", i_vvaArray[2][0][1]);
    printf("\n");

    printf("****COLUMN 2******\n");
    printf("i_vvaArray[2][1][0] = %d\n", i_vvaArray[2][1][0]);
    printf("i_vvaArray[2][1][1] = %d\n", i_vvaArray[2][1][1]);
    printf("\n");

    printf("****COLUMN 3******\n");
    printf("i_vvaArray[2][2][0] = %d\n", i_vvaArray[2][2][0]);
    printf("i_vvaArray[2][2][1] = %d\n", i_vvaArray[2][2][1]);
    printf("\n");

    // *** ROW 4 ***
    printf("**** ROW 4 ******\n");
    printf("****COLUMN 1******\n");
    printf("i_vvaArray[3][0][0] = %d\n", i_vvaArray[3][0][0]);
    printf("i_vvaArray[3][0][1] = %d\n", i_vvaArray[3][0][1]);
    printf("\n");

    printf("****COLUMN 2******\n");
    printf("i_vvaArray[3][1][0] = %d\n", i_vvaArray[3][1][0]);
    printf("i_vvaArray[3][1][1] = %d\n", i_vvaArray[3][1][1]);
    printf("\n");

    printf("****COLUMN 3******\n");
    printf("i_vvaArray[3][2][0] = %d\n", i_vvaArray[3][2][0]);
    printf("i_vvaArray[3][2][1] = %d\n", i_vvaArray[3][2][1]);
    printf("\n");

    // *** ROW 5 ***
    printf("**** ROW 1 ******\n");
    printf("****COLUMN 1******\n");
    printf("i_vvaArray[4][0][0] = %d\n", i_vvaArray[4][0][0]);
    printf("i_vvaArray[4][0][1] = %d\n", i_vvaArray[4][0][1]);
    printf("\n");

    printf("****COLUMN 2******\n");
    printf("i_vvaArray[4][1][0] = %d\n", i_vvaArray[4][1][0]);
    printf("i_vvaArray[4][1][1] = %d\n", i_vvaArray[4][1][1]);
    printf("\n");

    printf("****COLUMN 3******\n");
    printf("i_vvaArray[4][2][0] = %d\n", i_vvaArray[4][2][0]);
    printf("i_vvaArray[4][2][1] = %d\n", i_vvaArray[4][2][1]);
    printf("\n\n");

    return (0);
}

