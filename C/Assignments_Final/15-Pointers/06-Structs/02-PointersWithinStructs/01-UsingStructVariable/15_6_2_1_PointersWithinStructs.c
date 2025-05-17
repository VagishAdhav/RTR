#include <stdio.h>

//defining structs
struct MyData
{
    int *ptr_i;
    int i;

    float *ptr_f;
    float f;

    double *ptr_d;
    double d;
};

int main(void)
{
    // variable declaration
    struct MyData data_vva;

    // code
    data_vva.i = 9;
    data_vva.ptr_i = &data_vva.i;

    data_vva.f = 11.45f;
    data_vva.ptr_f = &data_vva.f;

    data_vva.d = 30.121995;
    data_vva.ptr_d = &data_vva.d;

    printf("\n\n");
    printf("i = %d\n", *(data_vva.ptr_i));
    printf("Address of 'i' = %p \n", data_vva.ptr_i);

    printf("\n\n");
    printf("f = %f\n", *(data_vva.ptr_f));
    printf("Address of 'f' = %p \n", data_vva.ptr_f);

    printf("\n\n");
    printf("d = %lf\n", *(data_vva.ptr_d));
    printf("Address of 'd' = %p \n", data_vva.ptr_d);

    return (0);
}