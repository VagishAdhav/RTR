#include <stdio.h>


int main(void)
{
    // variable declaration
    int iArray_vva[] = {9, 30, 6, 12, 98, 95, 20, 23, 2, 45};
    int int_size_vva;
    int iArray_size_vva;
    int iArray_num_elements_vva;

    float fArray_vva[] = {1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f};
    int float_size_vva;
    int fArray_size_vva;
    int fvvaArray_num_vva_elements;

    char cArray_vva[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P'};
    int char_size_vva;
    int cArray_size_vva;
    int cArray_num_elements_vva;

    //code

    // ************** iArray_vva[] ***************
    printf("\n\n");
    printf("Inline initialisation and Piece-meal display of elements of array iArray_vva[] : \n\n");

    printf("iArray_vva[0] (1st Element) = %d\n", iArray_vva[0]);
    printf("iArray_vva[1] (2nd Element) = %d\n", iArray_vva[1]);
    printf("iArray_vva[2] (3rd Element) = %d\n", iArray_vva[2]);
    printf("iArray_vva[3] (4th Element) = %d\n", iArray_vva[3]);
    printf("iArray_vva[4] (5th Element) = %d\n", iArray_vva[4]);
    printf("iArray_vva[5] (6th Element) = %d\n", iArray_vva[5]);
    printf("iArray_vva[6] (7th Element) = %d\n", iArray_vva[6]);
    printf("iArray_vva[7] (8th Element) = %d\n", iArray_vva[7]);
    printf("iArray_vva[8] (9th Element) = %d\n", iArray_vva[8]);
    printf("iArray_vva[9] (10th Element) = %d\n\n", iArray_vva[9]);

    int_size_vva = sizeof(int);
    iArray_size_vva = sizeof(iArray_vva);
    iArray_num_elements_vva = iArray_size_vva / int_size_vva;

    printf("Size of data type 'int'                               = %d bytes\n", int_size_vva);
    printf("number of elements in 'int' Array 'iArray_vva[]'      = %d elements\n", iArray_num_elements_vva);
    printf("Size of array 'iArray_vva[]' (%d Elements * %d bytes) = %d bytes\n\n", iArray_num_elements_vva, int_size_vva, iArray_size_vva);


    // ************** fArray_vva[] ***************
    printf("\n\n");
    printf("Inline initialisation and Piece-meal display of elements of array fArray_vva[] : \n\n");

    printf("fArray_vva[0] (1st Element) = %f\n", fArray_vva[0]);
    printf("fArray_vva[1] (2nd Element) = %f\n", fArray_vva[1]);
    printf("fArray_vva[2] (3rd Element) = %f\n", fArray_vva[2]);
    printf("fArray_vva[3] (4th Element) = %f\n", fArray_vva[3]);
    printf("fArray_vva[4] (5th Element) = %f\n", fArray_vva[4]);
    printf("fArray_vva[5] (6th Element) = %f\n", fArray_vva[5]);
    printf("fArray_vva[6] (7th Element) = %f\n", fArray_vva[6]);
    printf("fArray_vva[7] (8th Element) = %f\n", fArray_vva[7]);
    printf("fArray_vva[8] (9th Element) = %f\n", fArray_vva[8]);
    printf("fArray_vva[9] (10th Element) = %f\n\n", fArray_vva[9]);

    float_size_vva = sizeof(float);
    fArray_size_vva = sizeof(fArray_vva);
    fvvaArray_num_vva_elements = fArray_size_vva / float_size_vva;

    printf("Size of data type 'float'                            = %d bytes\n", float_size_vva);
    printf("number of elements in 'float' Array 'fArray_vva[]'   = %d elements\n", fvvaArray_num_vva_elements);
    printf("Size of array 'fArray_vva[]' (%d Elements * %d bytes) = %d bytes\n\n", fvvaArray_num_vva_elements, float_size_vva, fArray_size_vva);


    // ************** cArray_vva[] ***************
    printf("\n\n");
    printf("Inline initialisation and Piece-meal display of elements of array cArray_vva[] : \n\n");

    printf("cArray_vva[0] (1st Element) = %c\n", cArray_vva[0]);
    printf("cArray_vva[1] (2nd Element) = %c\n", cArray_vva[1]);
    printf("cArray_vva[2] (3rd Element) = %c\n", cArray_vva[2]);
    printf("cArray_vva[3] (4th Element) = %c\n", cArray_vva[3]);
    printf("cArray_vva[4] (5th Element) = %c\n", cArray_vva[4]);
    printf("cArray_vva[5] (6th Element) = %c\n", cArray_vva[5]);
    printf("cArray_vva[6] (7th Element) = %c\n", cArray_vva[6]);
    printf("cArray_vva[7] (8th Element) = %c\n", cArray_vva[7]);
    printf("cArray_vva[8] (9th Element) = %c\n", cArray_vva[8]);
    printf("cArray_vva[9] (10th Element) = %c\n", cArray_vva[9]);
    printf("cArray_vva[10] (11th Element) = %c\n", cArray_vva[10]);
    printf("cArray_vva[11] (12th Element) = %c\n", cArray_vva[11]);
    printf("cArray_vva[12] (13th Element) = %c\n\n", cArray_vva[12]);

    char_size_vva = sizeof(char);
    cArray_size_vva = sizeof(cArray_vva);
    cArray_num_elements_vva = cArray_size_vva / char_size_vva;

    printf("Size of data type 'char'                              = %d bytes\n", char_size_vva);
    printf("number of elements in 'char' Array 'cArray_vva[]'     = %d elements\n", cArray_num_elements_vva);
    printf("Size of array 'cArray_vva[]' (%d Elements * %d bytes) = %d bytes\n\n", cArray_num_elements_vva, char_size_vva, cArray_size_vva);

    return (0);    
}