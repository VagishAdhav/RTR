#include <stdio.h>

union MyUnion
{
    int i;
    float f;
    double d;
    char c;
};


int main(void)
{
    //variable declaration
    union MyUnion u1_vva, u2_vva;

    //code
    // *** MyUnion U1 ***
    printf("\n\n");
    printf("Members of union u1_vva are : \n\n");

    u1_vva.i = 6;
    u1_vva.f = 1.2f;
    u1_vva.d = 8.33333;
    u1_vva.c = 'S';

    printf("u1_vva.i = %d\n\n", u1_vva.i);
    printf("u1_vva.f = %f\n\n", u1_vva.f);
    printf("u1_vva.d = %lf\n\n", u1_vva.d);
    printf("u1_vva.c = %c\n\n", u1_vva.c);

    printf("Addresses of the members of the union u1_vva are : \n\n");
    printf("&u1_vva.i = %p\n\n", &u1_vva.i);
    printf("&u1_vva.f = %p\n\n", &u1_vva.f);
    printf("&u1_vva.d = %p\n\n", &u1_vva.d);
    printf("&u1_vva.c = %p\n\n", &u1_vva.c);

    printf("My Union &u1_vva = %p\n\n", &u1_vva);

    // **** My union U2 *********
    printf("\n\n");
    printf("Members of union u2_vva are : \n\n");

    u2_vva.i = 3;
    printf("u2_vva.i = %d\n\n", u2_vva.i);

    u2_vva.f = 4.5f;
    printf("u2_vva.f = %f\n\n", u2_vva.f);

    u2_vva.d = 5.12764;
    printf("u2_vva.f = %lf\n\n", u2_vva.f);

    u2_vva.c = 'A';
    printf("u2_vva.c = %c\n\n", u2_vva.c);

    printf("Addresses of the members of the union u2_vva are : \n\n");
    printf("&u2_vva.i = %p\n\n", &u2_vva.i);
    printf("&u2_vva.f = %p\n\n", &u2_vva.f);
    printf("&u2_vva.d = %p\n\n", &u2_vva.d);
    printf("&u2_vva.c = %p\n\n", &u2_vva.c);

    printf("My Union &u2_vva = %p\n\n", &u2_vva);

    return (0);
}