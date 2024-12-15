#include <stdio.h>


int main(void)
{
    // variable declaration
    int vva_iArray[] = {9, 30, 6, 12, 98, 95, 20, 23, 2, 45};
    int vva_int_size;
    int vva_iArray_size;
    int vva_iArray_num_elements;

    float vva_fArray[] = {1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f};
    int vva_float_size;
    int vva_fArray_size;
    int vva_fArray_num_elements;

    char vva_cArray[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P'};
    int vva_char_size;
    int vva_cArray_size;
    int vva_cArray_num_elements;

    //code

    // ************** vva_iArray[] ***************
    printf("\n\n");
    printf("Inline initialisation and Piece-meal display of elements of array vva_iArray[] : \n\n");

    printf("vva_iArray[0] (1st Element) = %d\n", vva_iArray[0]);
    printf("vva_iArray[1] (2nd Element) = %d\n", vva_iArray[1]);
    printf("vva_iArray[2] (3rd Element) = %d\n", vva_iArray[2]);
    printf("vva_iArray[3] (4th Element) = %d\n", vva_iArray[3]);
    printf("vva_iArray[4] (5th Element) = %d\n", vva_iArray[4]);
    printf("vva_iArray[5] (6th Element) = %d\n", vva_iArray[5]);
    printf("vva_iArray[6] (7th Element) = %d\n", vva_iArray[6]);
    printf("vva_iArray[7] (8th Element) = %d\n", vva_iArray[7]);
    printf("vva_iArray[8] (9th Element) = %d\n", vva_iArray[8]);
    printf("vva_iArray[9] (10th Element) = %d\n\n", vva_iArray[9]);

    vva_int_size = sizeof(int);
    vva_iArray_size = sizeof(vva_iArray);
    vva_iArray_num_elements = vva_iArray_size / vva_int_size;

    printf("Size of data type 'int'                               = %d bytes\n", vva_int_size);
    printf("Number of elements in 'int' Array 'vva_iArray[]'      = %d elements\n", vva_iArray_num_elements);
    printf("Size of array 'vva_iArray[]' (%d Elements * %d bytes) = %d bytes\n\n", vva_iArray_num_elements, vva_int_size, vva_iArray_size);


    // ************** vva_fArray[] ***************
    printf("\n\n");
    printf("Inline initialisation and Piece-meal display of elements of array vva_fArray[] : \n\n");

    printf("vva_fArray[0] (1st Element) = %f\n", vva_fArray[0]);
    printf("vva_fArray[1] (2nd Element) = %f\n", vva_fArray[1]);
    printf("vva_fArray[2] (3rd Element) = %f\n", vva_fArray[2]);
    printf("vva_fArray[3] (4th Element) = %f\n", vva_fArray[3]);
    printf("vva_fArray[4] (5th Element) = %f\n", vva_fArray[4]);
    printf("vva_fArray[5] (6th Element) = %f\n", vva_fArray[5]);
    printf("vva_fArray[6] (7th Element) = %f\n", vva_fArray[6]);
    printf("vva_fArray[7] (8th Element) = %f\n", vva_fArray[7]);
    printf("vva_fArray[8] (9th Element) = %f\n", vva_fArray[8]);
    printf("vva_fArray[9] (10th Element) = %f\n\n", vva_fArray[9]);

    vva_float_size = sizeof(float);
    vva_fArray_size = sizeof(vva_fArray);
    vva_fArray_num_elements = vva_fArray_size / vva_float_size;

    printf("Size of data type 'float'                            = %d bytes\n", vva_float_size);
    printf("Number of elements in 'float' Array 'vva_fArray[]'   = %d elements\n", vva_fArray_num_elements);
    printf("Size of array 'vva_fArray[]' (%d Elements * %d bytes) = %d bytes\n\n", vva_fArray_num_elements, vva_float_size, vva_fArray_size);


    // ************** vva_cArray[] ***************
    printf("\n\n");
    printf("Inline initialisation and Piece-meal display of elements of array vva_cArray[] : \n\n");

    printf("vva_cArray[0] (1st Element) = %c\n", vva_cArray[0]);
    printf("vva_cArray[1] (2nd Element) = %c\n", vva_cArray[1]);
    printf("vva_cArray[2] (3rd Element) = %c\n", vva_cArray[2]);
    printf("vva_cArray[3] (4th Element) = %c\n", vva_cArray[3]);
    printf("vva_cArray[4] (5th Element) = %c\n", vva_cArray[4]);
    printf("vva_cArray[5] (6th Element) = %c\n", vva_cArray[5]);
    printf("vva_cArray[6] (7th Element) = %c\n", vva_cArray[6]);
    printf("vva_cArray[7] (8th Element) = %c\n", vva_cArray[7]);
    printf("vva_cArray[8] (9th Element) = %c\n", vva_cArray[8]);
    printf("vva_cArray[9] (10th Element) = %c\n", vva_cArray[9]);
    printf("vva_cArray[10] (11th Element) = %c\n", vva_cArray[10]);
    printf("vva_cArray[11] (12th Element) = %c\n", vva_cArray[11]);
    printf("vva_cArray[12] (13th Element) = %c\n\n", vva_cArray[12]);

    vva_char_size = sizeof(char);
    vva_cArray_size = sizeof(vva_cArray);
    vva_cArray_num_elements = vva_cArray_size / vva_char_size;

    printf("Size of data type 'char'                              = %d bytes\n", vva_char_size);
    printf("Number of elements in 'char' Array 'vva_cArray[]'     = %d elements\n", vva_cArray_num_elements);
    printf("Size of array 'vva_cArray[]' (%d Elements * %d bytes) = %d bytes\n\n", vva_cArray_num_elements, vva_char_size, vva_cArray_size);

    return (0);    
}