#include <stdio.h>
#include <stdlib.h>

// defining struct
struct MyData
{
    int i;
    float f;
    double d;
};

int main(void)
{
    // variable declaration
    int i_size_vva;
    int f_size_vva;
    int d_size_vva;
    int strcut_MyData_size_vva;
    int pointer_to_struct_MyData_size_vva;

    struct MyData *pData_vva = NULL;

    //code
    printf("\n\n");
    pData_vva = (struct MyData*)malloc(sizeof(struct MyData));
    if (pData_vva == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY TO struct MyData !!! EXITING NOW\n\n");
        exit(0);
    }
    else
    {
        printf("SUCCESSFULLY ALLOCATED MEMORY TO struct MyData !!!\n\n");
    }

    // assigning data values to the data members of struct MyData
    pData_vva->i = 30;
    pData_vva->f = 11.45f;
    pData_vva->d = 1.2995;

    // displaying values of the data members of struct Mydata
    printf("\n\n");
    printf("DATA MEMBERS OF 'struct Mydata' ARE : \n\n");
    printf("i = %d\n", pData_vva->i);
    printf("f = %f\n", pData_vva->f);
    printf("d = %lf\n", pData_vva->d);

    // Calculating sizes (in bytes) of the data members of struct MyData
    i_size_vva = sizeof(pData_vva->i);
    f_size_vva = sizeof(pData_vva->f);
    d_size_vva = sizeof(pData_vva->d);

    // Displaying sizes (in bytes) of the data members o struct MyData
    printf("\n\n");
    printf("SIZES (in bytes) OF DATA MEMBERS OF 'struct MyData' ARE : \n\n");
    printf("Size of i = %d bytes\n", i_size_vva);
    printf("Size of f = %d bytes\n", f_size_vva);
    printf("Size of d = %d bytes\n", d_size_vva);

    // Calculating size of the entire struct MyData
    strcut_MyData_size_vva = sizeof(struct MyData);
    pointer_to_struct_MyData_size_vva = sizeof(struct Mydata *);

    // Displaying the size of entire struct MyData
    printf("\n\n");
    printf("Size of 'struct MyData' : %d bytes \n\n", strcut_MyData_size_vva);
    printf("Size of pointer to 'struct MyData' : %d bytes \n\n", pointer_to_struct_MyData_size_vva);

    if (pData_vva)
    {
        free(pData_vva);
        pData_vva = NULL;
        printf("MEMORY ALLOCATED TO 'struct MyData' HAS BEEN SUCCESSFULLY FREED !!\n\n");
    }

    return (0);

}
