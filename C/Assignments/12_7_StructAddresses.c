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
    struct MyData d_vvaata;


    //code
    //Assigning data values to the data members of struct MyData
    d_vvaata.i = 30;
    d_vvaata.f = 11.45f;
    d_vvaata.d = 1.2995;
    d_vvaata.c = 'A';
    
    // Displaying values of the data members of struct MyData
    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData' ARE: \n\n");
    printf("i = %d\n", d_vvaata.i);
    printf("f = %f\n", d_vvaata.f);
    printf("d = %lf\n", d_vvaata.d);
    printf("c = %c\n\n", d_vvaata.c);

    printf("\n\n");
    printf("ADDRESSES OF DATA MEMBERS OF 'struct MyData' ARE : \n\n");
    printf("'i' occupies addresses from %p\n", &d_vvaata.i);
    printf("'f' occupies addresses from %p\n", &d_vvaata.f);
    printf("'d' occupies addresses from %p\n", &d_vvaata.d);
    printf("'c' occupies addresses %p\n", &d_vvaata.c);

    printf("Starting address of 'struct Mydata' variable 'd_vvaata' = %p\n\n", &d_vvaata);
    return (0);
}