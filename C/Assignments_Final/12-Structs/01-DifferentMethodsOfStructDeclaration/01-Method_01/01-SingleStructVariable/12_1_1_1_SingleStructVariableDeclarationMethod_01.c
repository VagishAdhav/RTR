#include <stdio.h>

//define struct
struct MyData
{
    int i;
    float f;
    double d;
    char c;
}data_vva; // declaring a single struct variable of type 'MyData' globally

int main(void)
{
    // variable declarations
    int i_vva_size;
    int f_vva_size;
    int d_vva_size;
    int struct_MyData_size_vva;

    //code
    // Assigning data values to the data members of 'struct MyData'
    data_vva.i = 30;
    data_vva.f = 11.45f;
    data_vva.d = 1.2995;

    
    // Displaying  data values to the data members if struct 'MyData'
    printf("\n\n");
    printf("Data members of 'struct MyData' are : \n\n");
    printf("i = %d\n", data_vva.i);
    printf("f = %f\n", data_vva.f);
    printf("d = %lf\n", data_vva.d);

    // calculating size in bytes of the data members of struct MyData
    i_vva_size = sizeof(data_vva.i);
    f_vva_size = sizeof(data_vva.f);
    d_vva_size = sizeof(data_vva.d);

    // displaying size of data members of struct Mydata in bytes
    printf("\n\n");
    printf("Sizes (in bytes) of data members of struct MyData are : \n\n");
    printf("Size of 'i' = %d bytes\n", i_vva_size);
    printf("Size of 'f' = %d bytes\n", f_vva_size);
    printf("Size of 'd' = %d bytes\n", d_vva_size);

    // calculating size in bytes of entire struct MyData
    struct_MyData_size_vva = sizeof(struct MyData); // can also give struct name sizof(data_vva)

    // displaying size of entire struct Mydata
    printf("\n\n");
    printf("Size of'struct MyData : %d bytes \n\n", struct_MyData_size_vva);

    return (0);
}
