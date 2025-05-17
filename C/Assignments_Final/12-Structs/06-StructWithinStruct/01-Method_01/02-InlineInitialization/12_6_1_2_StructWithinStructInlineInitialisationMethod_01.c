#include <stdio.h>

struct Rectangle
{
    struct MyPoint
    {
        int x;
        int y;
    } point_01, point_02;

} rect_vva = {{2, 3}, {5,6 }};

int main(void)
{
    // variable declarations
    int length_vva, breadth_vva, area_vva;

    //code
    length_vva = rect_vva.point_02.y - rect_vva.point_01.y;
    if (length_vva < 0)
        length_vva = length_vva * -1;

    breadth_vva = rect_vva.point_02.x - rect_vva.point_01.x;
    if (breadth_vva < 0)
        breadth_vva = breadth_vva * -1;

    area_vva = breadth_vva * length_vva;

    printf("\n\n");
    printf("Length of rectangle = %d\n\n", length_vva);
    printf("Breadth of rectangle = %d\n\n", breadth_vva);
    printf("Area of rectangle = %d\n\n", area_vva);

    return (0);
}