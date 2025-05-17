#include <stdio.h>


int main(void)
{
    // variable declaration
    int i_vvaArray[] = {9, 30, 6, 12, 98, 95, 20, 23, 2, 45};
    int i_vvant_size;
    int i_vvaArray_size;
    int i_vvaArray_num_vva_elements;

    float f_vvaArray[] = {1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f};
    int f_vvaloat_size;
    int f_vvaArray_size;
    int f_vvaArray_num_vva_elements;

    char c_vvaArray[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P'};
    int c_vvahar_size;
    int c_vvaArray_size;
    int c_vvaArray_num_vva_elements;

    //code

    // ************** i_vvaArray[] ***************
    printf("\n\n");
    printf("Inline initialisation and Piece-meal display of elements of array i_vvaArray[] : \n\n");

    printf("i_vvaArray[0] (1st Element) = %d\n", i_vvaArray[0]);
    printf("i_vvaArray[1] (2nd Element) = %d\n", i_vvaArray[1]);
    printf("i_vvaArray[2] (3rd Element) = %d\n", i_vvaArray[2]);
    printf("i_vvaArray[3] (4th Element) = %d\n", i_vvaArray[3]);
    printf("i_vvaArray[4] (5th Element) = %d\n", i_vvaArray[4]);
    printf("i_vvaArray[5] (6th Element) = %d\n", i_vvaArray[5]);
    printf("i_vvaArray[6] (7th Element) = %d\n", i_vvaArray[6]);
    printf("i_vvaArray[7] (8th Element) = %d\n", i_vvaArray[7]);
    printf("i_vvaArray[8] (9th Element) = %d\n", i_vvaArray[8]);
    printf("i_vvaArray[9] (10th Element) = %d\n\n", i_vvaArray[9]);

    i_vvant_size = sizeof(int);
    i_vvaArray_size = sizeof(i_vvaArray);
    i_vvaArray_num_vva_elements = i_vvaArray_size / i_vvant_size;

    printf("Size of data type 'int'                               = %d bytes\n", i_vvant_size);
    printf("number of elements in 'int' Array 'i_vvaArray[]'      = %d elements\n", i_vvaArray_num_vva_elements);
    printf("Size of array 'i_vvaArray[]' (%d Elements * %d bytes) = %d bytes\n\n", i_vvaArray_num_vva_elements, i_vvant_size, i_vvaArray_size);


    // ************** f_vvaArray[] ***************
    printf("\n\n");
    printf("Inline initialisation and Piece-meal display of elements of array f_vvaArray[] : \n\n");

    printf("f_vvaArray[0] (1st Element) = %f\n", f_vvaArray[0]);
    printf("f_vvaArray[1] (2nd Element) = %f\n", f_vvaArray[1]);
    printf("f_vvaArray[2] (3rd Element) = %f\n", f_vvaArray[2]);
    printf("f_vvaArray[3] (4th Element) = %f\n", f_vvaArray[3]);
    printf("f_vvaArray[4] (5th Element) = %f\n", f_vvaArray[4]);
    printf("f_vvaArray[5] (6th Element) = %f\n", f_vvaArray[5]);
    printf("f_vvaArray[6] (7th Element) = %f\n", f_vvaArray[6]);
    printf("f_vvaArray[7] (8th Element) = %f\n", f_vvaArray[7]);
    printf("f_vvaArray[8] (9th Element) = %f\n", f_vvaArray[8]);
    printf("f_vvaArray[9] (10th Element) = %f\n\n", f_vvaArray[9]);

    f_vvaloat_size = sizeof(float);
    f_vvaArray_size = sizeof(f_vvaArray);
    f_vvaArray_num_vva_elements = f_vvaArray_size / f_vvaloat_size;

    printf("Size of data type 'float'                            = %d bytes\n", f_vvaloat_size);
    printf("number of elements in 'float' Array 'f_vvaArray[]'   = %d elements\n", f_vvaArray_num_vva_elements);
    printf("Size of array 'f_vvaArray[]' (%d Elements * %d bytes) = %d bytes\n\n", f_vvaArray_num_vva_elements, f_vvaloat_size, f_vvaArray_size);


    // ************** c_vvaArray[] ***************
    printf("\n\n");
    printf("Inline initialisation and Piece-meal display of elements of array c_vvaArray[] : \n\n");

    printf("c_vvaArray[0] (1st Element) = %c\n", c_vvaArray[0]);
    printf("c_vvaArray[1] (2nd Element) = %c\n", c_vvaArray[1]);
    printf("c_vvaArray[2] (3rd Element) = %c\n", c_vvaArray[2]);
    printf("c_vvaArray[3] (4th Element) = %c\n", c_vvaArray[3]);
    printf("c_vvaArray[4] (5th Element) = %c\n", c_vvaArray[4]);
    printf("c_vvaArray[5] (6th Element) = %c\n", c_vvaArray[5]);
    printf("c_vvaArray[6] (7th Element) = %c\n", c_vvaArray[6]);
    printf("c_vvaArray[7] (8th Element) = %c\n", c_vvaArray[7]);
    printf("c_vvaArray[8] (9th Element) = %c\n", c_vvaArray[8]);
    printf("c_vvaArray[9] (10th Element) = %c\n", c_vvaArray[9]);
    printf("c_vvaArray[10] (11th Element) = %c\n", c_vvaArray[10]);
    printf("c_vvaArray[11] (12th Element) = %c\n", c_vvaArray[11]);
    printf("c_vvaArray[12] (13th Element) = %c\n\n", c_vvaArray[12]);

    c_vvahar_size = sizeof(char);
    c_vvaArray_size = sizeof(c_vvaArray);
    c_vvaArray_num_vva_elements = c_vvaArray_size / c_vvahar_size;

    printf("Size of data type 'char'                              = %d bytes\n", c_vvahar_size);
    printf("number of elements in 'char' Array 'c_vvaArray[]'     = %d elements\n", c_vvaArray_num_vva_elements);
    printf("Size of array 'c_vvaArray[]' (%d Elements * %d bytes) = %d bytes\n\n", c_vvaArray_num_vva_elements, c_vvahar_size, c_vvaArray_size);

    return (0);    
}