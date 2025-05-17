#include <stdio.h>

// DEFINING STRUCT
struct MyData{
    int i;
    float f;
    double d;
    char c;
};

struct MyData d_vvaata = {9, 8.2f, 9.61998, 'P'};

int main(void)
{
    //code
    // Displaying values of the data members of struct MyData
    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData' ARE: \n\n");
    printf("i = %d\n", d_vvaata.i);
    printf("f = %f\n", d_vvaata.f);
    printf("d = %lf\n", d_vvaata.d);
    printf("c = %c\n\n", d_vvaata.c);

    return (0);
}