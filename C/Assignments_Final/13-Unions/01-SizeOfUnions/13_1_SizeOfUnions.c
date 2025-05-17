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
    printf("Sizeof of MyStruct = %zu\n", sizeof(s_vva));
    printf("\n\n");
    printf("Sizeof of MyUnion = %zu\n", sizeof(u_vva));

    return (0);
}