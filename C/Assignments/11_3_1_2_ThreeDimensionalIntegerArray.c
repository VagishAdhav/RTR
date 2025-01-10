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
    int i_vva, vva_j, vva_k;

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

    for (i_vva = 0; i_vva < i_vvaArray_height; i_vva++)
    {
        printf("**** ROW %d****\n", (i_vva + 1));
        for (vva_j = 0; vva_j < i_vvaArray_width; vva_j++)
        {
            printf("***** COLUMN %d ******\n", (vva_j + 1));
            for (vva_k = 0; vva_k < i_vvaArray_depth; vva_k++)
            {
                printf("i_vvaArray[%d][%d][%d] = %d\n", i_vva, vva_j, vva_k, i_vvaArray[i_vva][vva_j][vva_k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    return (0);
}

