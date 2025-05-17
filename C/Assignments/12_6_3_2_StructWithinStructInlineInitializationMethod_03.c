#include <stdio.h>

int main(void)
{
    // variable declarations
    int vva_length, b_vvareadth, a_vvarea;

    struct Rectangle
    {
        struct MyPoint
        {
            int x;
            int y;
        } point_01, point_02;
    } vva_rect = {{1, 3}, {5, 6 }};


    //code
    vva_length = vva_rect.point_02.y - vva_rect.point_01.y;
    if (vva_length < 0)
        vva_length = vva_length * -1;

    b_vvareadth = vva_rect.point_02.x - vva_rect.point_01.x;
    if (b_vvareadth < 0)
        b_vvareadth = b_vvareadth * -1;

    a_vvarea = b_vvareadth * vva_length;

    printf("\n\n");
    printf("Length of rectangle = %d\n\n", vva_length);
    printf("Breadth of rectangle = %d\n\n", b_vvareadth);
    printf("Area of rectangle = %d\n\n", a_vvarea);

    return (0);
}