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
    struct MyStruct s;
    union MyUnion u;

    //code
    printf("\n\n");
    printf("Sizeof of MyStruct = %zu\n", sizeof(s));
    printf("\n\n");
    printf("Sizeof of MyUnion = %zu\n", sizeof(u));

    return (0);
}