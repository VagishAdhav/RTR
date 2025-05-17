#include <stdio.h>

//define struct
struct MyData
{
    int i;
    float f;
    double d;
    char c;
}d_vvaata; // declaring a single struct variable of type 'MyData' globally

int main(void)
{
    // variable declarations
    int i_vva_size;
    int f_vva_size;
    int d_vva_size;
    int vva_struct_MyData_size;

    //code
    // Assigning data values to the data members of 'struct MyData'
    d_vvaata.i = 30;
    d_vvaata.f = 11.45f;
    d_vvaata.d = 1.2995;

    
    // Displaying  data values to the data members if struct 'MyData'
    printf("\n\n");
    printf("Data members of 'struct MyData' are : \n\n");
    printf("i = %d\n", d_vvaata.i);
    printf("f = %f\n", d_vvaata.f);
    printf("d = %lf\n", d_vvaata.d);

    // calculating size in bytes of the data members of struct MyData
    i_vva_size = sizeof(d_vvaata.i);
    f_vva_size = sizeof(d_vvaata.f);
    d_vva_size = sizeof(d_vvaata.d);

    // displaying size of data members of struct Mydata in bytes
    printf("\n\n");
    printf("Sizes (in bytes) of data members of struct MyData are : \n\n");
    printf("Size of 'i' = %d bytes\n", i_vva_size);
    printf("Size of 'f' = %d bytes\n", f_vva_size);
    printf("Size of 'd' = %d bytes\n", d_vva_size);

    // calculating size in bytes of entire struct MyData
    vva_struct_MyData_size = sizeof(struct MyData); // can also give struct name sizof(d_vvaata)

    // displaying size of entire struct Mydata
    printf("\n\n");
    printf("Size of'struct MyData : %d bytes \n\n", vva_struct_MyData_size);

    return (0);
}
