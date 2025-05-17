#include <stdio.h>

struct MyData{
    int i;
    float f;
    double d;
    char c;
};

int main(void)
{
    // variable declaration 
    struct MyData data_vva;


    //code
    //Assigning data values to the data members of struct MyData
    data_vva.i = 30;
    data_vva.f = 11.45f;
    data_vva.d = 1.2995;
    data_vva.c = 'A';
    
    // Displaying values of the data members of struct MyData
    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData' ARE: \n\n");
    printf("i = %d\n", data_vva.i);
    printf("f = %f\n", data_vva.f);
    printf("d = %lf\n", data_vva.d);
    printf("c = %c\n\n", data_vva.c);

    printf("\n\n");
    printf("ADDRESSES OF DATA MEMBERS OF 'struct MyData' ARE : \n\n");
    printf("'i' occupies addresses from %p\n", &data_vva.i);
    printf("'f' occupies addresses from %p\n", &data_vva.f);
    printf("'d' occupies addresses from %p\n", &data_vva.d);
    printf("'c' occupies addresses %p\n", &data_vva.c);

    printf("Starting address of 'struct Mydata' variable 'data_vva' = %p\n\n", &data_vva);
    return (0);
}