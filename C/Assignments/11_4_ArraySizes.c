#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vvaArray_One[5];
    int i_vvaArray_Two[5][3];
    int i_vvaArray_Three[100][100][5];

    int vva_num_vva_rows_2D;
    int vva_num_vva_columns_2D;
    
    int vva_num_vva_rows_3D;
    int vva_num_vva_columns_3D;
    int d_vvaepth_3D;

    //code
    printf("\n\n");
    printf("Size of 1D integer array i_vvaArray_One = %zu\n", sizeof(i_vvaArray_One));
    printf("number of elements in 1-D integer array i_vvaArray_One = %zu\n", (sizeof(i_vvaArray_One)/ sizeof(int)));

    printf("\n\n");
    printf("Size of 2D integer array i_vvaArray_Two = %zu\n", sizeof(i_vvaArray_Two));
    
    printf("number of rows in 2D integer i_vvaArray_Two = %zu\n", (sizeof(i_vvaArray_Two)/sizeof(i_vvaArray_Two[0])));
    vva_num_vva_rows_2D = sizeof(i_vvaArray_Two) / sizeof(i_vvaArray_Two[0]);

    printf("number of elements (columns) in each row in 2-D integer array i_vvaArray_Two = %zu\n", (sizeof(i_vvaArray_Two[0])/sizeof(i_vvaArray_Two[0][0])));
    vva_num_vva_columns_2D = sizeof(i_vvaArray_Two[0]) / sizeof(i_vvaArray_Two[0][0]);

    printf("number of elements in total in 2D array i_vvaArray_Two = %d\n", (vva_num_vva_rows_2D * vva_num_vva_columns_2D));

    printf("\n\n");
    printf("Size of 3D integer array i_vvaArray_Three = %zu\n", sizeof(i_vvaArray_Three));

    printf("number of rows in 3D integer array i_vvaArray_Three = %zu\n", (sizeof(i_vvaArray_Three) / sizeof(i_vvaArray_Three[0])));
    vva_num_vva_rows_3D = (sizeof(i_vvaArray_Three) / sizeof(i_vvaArray_Three[0]));

    printf("number of elements(columns) in one row in 3-D integer array i_vvaArray_Three = %zu\n", (sizeof(i_vvaArray_Three[0]) / sizeof(i_vvaArray_Three[0][0])));
    vva_num_vva_columns_3D = (sizeof(i_vvaArray_Three[0]) / sizeof(i_vvaArray_Three[0][0]));

    printf("number of elements(depth) in one columns in on row in 3D integer array i_vvaArray_Three = %zu\n", ((sizeof(i_vvaArray_Three[0][0]) / sizeof(i_vvaArray_Three[0][0][0]))));
    d_vvaepth_3D = (sizeof(i_vvaArray_Three[0][0]) / sizeof(i_vvaArray_Three[0][0][0]));

    printf("number of elements in total in 3D array i_vvaArray_Three = %d\n", (vva_num_vva_rows_3D * vva_num_vva_columns_3D * d_vvaepth_3D));

    printf("\n\n");

    return (0);

}