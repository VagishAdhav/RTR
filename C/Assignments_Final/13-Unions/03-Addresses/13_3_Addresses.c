#include <stdio.h>

struct MyStruct
{
    int i;
    float f;
    double d;
    char c;
};

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
    struct MyStruct s_vva;
    union MyUnion u_vva;

    //code
    printf("\n\n");
    printf("Members of structare : \n\n");

    s_vva.i = 9;
    s_vva.f = 8.7f;
    s_vva.d = 1.233422;
    s_vva.c = 'P';

    printf("s_vva.i = %d\n\n", s_vva.i);
    printf("s_vva.f = %f\n\n", s_vva.f);
    printf("s_vva.d = %lf\n\n", s_vva.d);
    printf("s_vva.c = %c\n\n", s_vva.c);

    printf("Addresses of the members of struct are : \n\n");
    printf("&s_vva.i = %p\n\n", &s_vva.i);
    printf("&s_vva.f = %p\n\n", &s_vva.f);
    printf("&s_vva.d = %p\n\n", &s_vva.d);
    printf("&s_vva.c = %p\n\n", &s_vva.c);

    printf("MyStruct &s_vva = %p\n\n", &s_vva);


    printf("\n\n");
    printf("Members of union are : \n\n");

    u_vva.i = 3;
    printf("u_vva.i = %d\n\n", u_vva.i);

    u_vva.f = 4.5f;
    printf("u_vva.f = %f\n\n", u_vva.f);

    u_vva.d = 5.12764;
    printf("u_vva.f = %lf\n\n", u_vva.f);

    u_vva.c = 'A';
    printf("u_vva.c = %c\n\n", u_vva.c);

    printf("Addresses of the members of the union  are : \n\n");
    printf("&u_vva.i = %p\n\n", &u_vva.i);
    printf("&u_vva.f = %p\n\n", &u_vva.f);
    printf("&u_vva.d = %p\n\n", &u_vva.d);
    printf("&u_vva.c = %p\n\n", &u_vva.c);

    printf("My Union &u_vva = %p\n\n", &u_vva);

    return (0);
}