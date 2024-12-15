#include <stdio.h>

int main(void)
{
    // variable declarations
    int vva_iArray[] = {9, 30, 6, 12, 98, 20, 23, 2, 45};
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

    int vva_index;

    //code
    //**** vva_iArray[] ********
    printf("\n\n");
    printf("In-line initialization and loop (for) display of elements of array 'vva_iArrayp[]' : \n\n");

    vva_int_size = sizeof(int);
    vva_iArray_size = sizeof(vva_iArray);
    vva_iArray_num_elements = vva_iArray_size / vva_int_size;

    for (vva_index = 0; vva_index < vva_iArray_num_elements; vva_index++)
    {
        printf("vva_iArray[%d] (Element %d) = %d\n", vva_index, (vva_index + 1), vva_iArray[vva_index]);
    }

    printf("Size of data type 'int'                               = %d bytes\n", vva_int_size);
    printf("Number of elements in 'int' Array 'vva_iArray[]'      = %d elements\n", vva_iArray_num_elements);
    printf("Size of array 'vva_iArray[]' (%d Elements * %d bytes) = %d bytes\n\n", vva_iArray_num_elements, vva_int_size, vva_iArray_size);

    //**** vva_fArray[] ********
    printf("\n\n");
    printf("In-line initialization and loop (while) display of elements of array 'vva_fArrayp[]' : \n\n");

    
    vva_float_size = sizeof(float);
    vva_fArray_size = sizeof(vva_fArray);
    vva_fArray_num_elements = vva_fArray_size / vva_float_size;

    vva_index = 0;

    while (vva_index < vva_fArray_num_elements)
    {
        printf("vva_fArray[%d] (Element %d) = %f\n", vva_index, (vva_index + 1), vva_fArray[vva_index]);
        vva_index++;
    }

    printf("Size of data type 'float'                            = %d bytes\n", vva_float_size);
    printf("Number of elements in 'float' Array 'vva_fArray[]'   = %d elements\n", vva_fArray_num_elements);
    printf("Size of array 'vva_fArray[]' (%d Elements * %d bytes) = %d bytes\n\n", vva_fArray_num_elements, vva_float_size, vva_fArray_size);


    // ************** vva_cArray[] ***************
    printf("\n\n");
    printf("Inline initialisation and loop (for) display of elements of array vva_cArray[] : \n\n");

    vva_char_size = sizeof(char);
    vva_cArray_size = sizeof(vva_cArray);
    vva_cArray_num_elements = vva_cArray_size / vva_char_size;

    for (vva_index = 0; vva_index < vva_cArray_num_elements; vva_index++)
    {
        printf("vva_cArray[%d] (Element %d) = %c\n", vva_index, (vva_index + 1), vva_cArray[vva_index]);
    }

    printf("Size of data type 'char'                              = %d bytes\n", vva_char_size);
    printf("Number of elements in 'char' Array 'vva_cArray[]'     = %d elements\n", vva_cArray_num_elements);
    printf("Size of array 'vva_cArray[]' (%d Elements * %d bytes) = %d bytes\n\n", vva_cArray_num_elements, vva_char_size, vva_cArray_size);

    return (0);
}