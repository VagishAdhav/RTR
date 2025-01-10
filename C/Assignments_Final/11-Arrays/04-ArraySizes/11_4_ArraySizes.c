#include <stdio.h>

int main(void)
{
    // variable declaration
    int iArray_vva_One[5];
    int iArray_vva_Two[5][3];
    int iArray_vva_Three[100][100][5];

    int num_rows_vva_2D;
    int num__columns_vva_2D;
    
    int vva_num_vva_rows_3D;
    int vva_num_vva_columns_3D;
    int d_vvaepth_3D;

    //code
    printf("\n\n");
    printf("Size of 1D integer array iArray_vva_One = %zu\n", sizeof(iArray_vva_One));
    printf("number of elements in 1-D integer array iArray_vva_One = %zu\n", (sizeof(iArray_vva_One)/ sizeof(int)));

    printf("\n\n");
    printf("Size of 2D integer array iArray_vva_Two = %zu\n", sizeof(iArray_vva_Two));
    
    printf("number of rows in 2D integer iArray_vva_Two = %zu\n", (sizeof(iArray_vva_Two)/sizeof(iArray_vva_Two[0])));
    num_rows_vva_2D = sizeof(iArray_vva_Two) / sizeof(iArray_vva_Two[0]);

    printf("number of elements (columns) in each row in 2-D integer array iArray_vva_Two = %zu\n", (sizeof(iArray_vva_Two[0])/sizeof(iArray_vva_Two[0][0])));
    num__columns_vva_2D = sizeof(iArray_vva_Two[0]) / sizeof(iArray_vva_Two[0][0]);

    printf("number of elements in total in 2D array iArray_vva_Two = %d\n", (num_rows_vva_2D * num__columns_vva_2D));

    printf("\n\n");
    printf("Size of 3D integer array iArray_vva_Three = %zu\n", sizeof(iArray_vva_Three));

    printf("number of rows in 3D integer array iArray_vva_Three = %zu\n", (sizeof(iArray_vva_Three) / sizeof(iArray_vva_Three[0])));
    vva_num_vva_rows_3D = (sizeof(iArray_vva_Three) / sizeof(iArray_vva_Three[0]));

    printf("number of elements(columns) in one row in 3-D integer array iArray_vva_Three = %zu\n", (sizeof(iArray_vva_Three[0]) / sizeof(iArray_vva_Three[0][0])));
    vva_num_vva_columns_3D = (sizeof(iArray_vva_Three[0]) / sizeof(iArray_vva_Three[0][0]));

    printf("number of elements(depth) in one columns in on row in 3D integer array iArray_vva_Three = %zu\n", ((sizeof(iArray_vva_Three[0][0]) / sizeof(iArray_vva_Three[0][0][0]))));
    d_vvaepth_3D = (sizeof(iArray_vva_Three[0][0]) / sizeof(iArray_vva_Three[0][0][0]));

    printf("number of elements in total in 3D array iArray_vva_Three = %d\n", (vva_num_vva_rows_3D * vva_num_vva_columns_3D * d_vvaepth_3D));

    printf("\n\n");

    return (0);

}