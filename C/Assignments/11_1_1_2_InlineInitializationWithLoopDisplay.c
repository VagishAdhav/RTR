#include <stdio.h>

int main(void)
{
    // variable declarations
    int i_vvaArray[] = {9, 30, 6, 12, 98, 20, 23, 2, 45};
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

    int i_vvandex;

    //code
    //**** i_vvaArray[] ********
    printf("\n\n");
    printf("In-line initialization and loop (for) display of elements of array 'i_vvaArrayp[]' : \n\n");

    i_vvant_size = sizeof(int);
    i_vvaArray_size = sizeof(i_vvaArray);
    i_vvaArray_num_vva_elements = i_vvaArray_size / i_vvant_size;

    for (i_vvandex = 0; i_vvandex < i_vvaArray_num_vva_elements; i_vvandex++)
    {
        printf("i_vvaArray[%d] (Element %d) = %d\n", i_vvandex, (i_vvandex + 1), i_vvaArray[i_vvandex]);
    }

    printf("Size of data type 'int'                               = %d bytes\n", i_vvant_size);
    printf("number of elements in 'int' Array 'i_vvaArray[]'      = %d elements\n", i_vvaArray_num_vva_elements);
    printf("Size of array 'i_vvaArray[]' (%d Elements * %d bytes) = %d bytes\n\n", i_vvaArray_num_vva_elements, i_vvant_size, i_vvaArray_size);

    //**** f_vvaArray[] ********
    printf("\n\n");
    printf("In-line initialization and loop (while) display of elements of array 'f_vvaArrayp[]' : \n\n");

    
    f_vvaloat_size = sizeof(float);
    f_vvaArray_size = sizeof(f_vvaArray);
    f_vvaArray_num_vva_elements = f_vvaArray_size / f_vvaloat_size;

    i_vvandex = 0;

    while (i_vvandex < f_vvaArray_num_vva_elements)
    {
        printf("f_vvaArray[%d] (Element %d) = %f\n", i_vvandex, (i_vvandex + 1), f_vvaArray[i_vvandex]);
        i_vvandex++;
    }

    printf("Size of data type 'float'                            = %d bytes\n", f_vvaloat_size);
    printf("number of elements in 'float' Array 'f_vvaArray[]'   = %d elements\n", f_vvaArray_num_vva_elements);
    printf("Size of array 'f_vvaArray[]' (%d Elements * %d bytes) = %d bytes\n\n", f_vvaArray_num_vva_elements, f_vvaloat_size, f_vvaArray_size);


    // ************** c_vvaArray[] ***************
    printf("\n\n");
    printf("Inline initialisation and loop (for) display of elements of array c_vvaArray[] : \n\n");

    c_vvahar_size = sizeof(char);
    c_vvaArray_size = sizeof(c_vvaArray);
    c_vvaArray_num_vva_elements = c_vvaArray_size / c_vvahar_size;

    for (i_vvandex = 0; i_vvandex < c_vvaArray_num_vva_elements; i_vvandex++)
    {
        printf("c_vvaArray[%d] (Element %d) = %c\n", i_vvandex, (i_vvandex + 1), c_vvaArray[i_vvandex]);
    }

    printf("Size of data type 'char'                              = %d bytes\n", c_vvahar_size);
    printf("number of elements in 'char' Array 'c_vvaArray[]'     = %d elements\n", c_vvaArray_num_vva_elements);
    printf("Size of array 'c_vvaArray[]' (%d Elements * %d bytes) = %d bytes\n\n", c_vvaArray_num_vva_elements, c_vvahar_size, c_vvaArray_size);

    return (0);
}