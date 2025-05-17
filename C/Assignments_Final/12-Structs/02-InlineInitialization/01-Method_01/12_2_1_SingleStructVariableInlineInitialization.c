#include <stdio.h>

// DEFINING STRUCT
struct MyData{
    int i;
    float f;
    double d;
    char c;
} data_vva = {30, 4.5f, 11.451995, 'A'}; // inline initialisation of struct variable 'data_vva'

int main(void)
{
    //code
    // Displaying values of the data members of struct MyData
    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData' ARE: \n\n");
    printf("i = %d\n", data_vva.i);
    printf("f = %f\n", data_vva.f);
    printf("d = %lf\n", data_vva.d);
    printf("c = %c\n\n", data_vva.c);

    return (0);
}