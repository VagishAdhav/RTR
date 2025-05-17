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
    struct MyData data;

    // code
    data.i = 9;
    data.ptr_i = &data.i;

    data.f = 11.45f;
    data.ptr_f = &data.f;

    data.d = 30.121995;
    data.ptr_d = &data.d;

    printf("\n\n");
    printf("i = %d\n", *(data.ptr_i));
    printf("Address of 'i' = %p \n", data.ptr_i);

    printf("\n\n");
    printf("f = %f\n", *(data.ptr_f));
    printf("Address of 'f' = %p \n", data.ptr_f);

    printf("\n\n");
    printf("d = %lf\n", *(data.ptr_d));
    printf("Address of 'd' = %p \n", data.ptr_d);

    return (0);
}