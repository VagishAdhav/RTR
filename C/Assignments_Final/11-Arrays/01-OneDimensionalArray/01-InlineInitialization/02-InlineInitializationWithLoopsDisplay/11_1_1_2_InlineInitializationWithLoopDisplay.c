#include <stdio.h>

int main(void)
{
    // variable declarations
    int iArray_vva[] = {9, 30, 6, 12, 98, 20, 23, 2, 45};
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

    int i_vvandex;

    //code
    //**** iArray_vva[] ********
    printf("\n\n");
    printf("In-line initialization and loop (for) display of elements of array 'iArray_vvap[]' : \n\n");

    int_size_vva = sizeof(int);
    iArray_size_vva = sizeof(iArray_vva);
    iArray_num_elements_vva = iArray_size_vva / int_size_vva;

    for (i_vvandex = 0; i_vvandex < iArray_num_elements_vva; i_vvandex++)
    {
        printf("iArray_vva[%d] (Element %d) = %d\n", i_vvandex, (i_vvandex + 1), iArray_vva[i_vvandex]);
    }

    printf("Size of data type 'int'                               = %d bytes\n", int_size_vva);
    printf("number of elements in 'int' Array 'iArray_vva[]'      = %d elements\n", iArray_num_elements_vva);
    printf("Size of array 'iArray_vva[]' (%d Elements * %d bytes) = %d bytes\n\n", iArray_num_elements_vva, int_size_vva, iArray_size_vva);

    //**** fArray_vva[] ********
    printf("\n\n");
    printf("In-line initialization and loop (while) display of elements of array 'f_vvaArrayp[]' : \n\n");

    
    float_size_vva = sizeof(float);
    fArray_size_vva = sizeof(fArray_vva);
    fvvaArray_num_vva_elements = fArray_size_vva / float_size_vva;

    i_vvandex = 0;

    while (i_vvandex < fvvaArray_num_vva_elements)
    {
        printf("fArray_vva[%d] (Element %d) = %f\n", i_vvandex, (i_vvandex + 1), fArray_vva[i_vvandex]);
        i_vvandex++;
    }

    printf("Size of data type 'float'                            = %d bytes\n", float_size_vva);
    printf("number of elements in 'float' Array 'fArray_vva[]'   = %d elements\n", fvvaArray_num_vva_elements);
    printf("Size of array 'fArray_vva[]' (%d Elements * %d bytes) = %d bytes\n\n", fvvaArray_num_vva_elements, float_size_vva, fArray_size_vva);


    // ************** cArray_vva[] ***************
    printf("\n\n");
    printf("Inline initialisation and loop (for) display of elements of array cArray_vva[] : \n\n");

    char_size_vva = sizeof(char);
    cArray_size_vva = sizeof(cArray_vva);
    cArray_num_elements_vva = cArray_size_vva / char_size_vva;

    for (i_vvandex = 0; i_vvandex < cArray_num_elements_vva; i_vvandex++)
    {
        printf("cArray_vva[%d] (Element %d) = %c\n", i_vvandex, (i_vvandex + 1), cArray_vva[i_vvandex]);
    }

    printf("Size of data type 'char'                              = %d bytes\n", char_size_vva);
    printf("number of elements in 'char' Array 'cArray_vva[]'     = %d elements\n", cArray_num_elements_vva);
    printf("Size of array 'cArray_vva[]' (%d Elements * %d bytes) = %d bytes\n\n", cArray_num_elements_vva, char_size_vva, cArray_size_vva);

    return (0);
}