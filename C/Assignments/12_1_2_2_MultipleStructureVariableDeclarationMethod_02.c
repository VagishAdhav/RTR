#include <stdio.h>

// defining struct
struct MyPoint
{
    int x;
    int y;
};

struct MyPoint vva_point_A, vva_point_B, vva_point_C, vva_point_D, vva_point_E; // declaring 5 struct variables of type 'struct MyPoint' globally

int main(void)
{
    //code
    // Assigning data values to the data members of struct 'My Point' variable 'point_A'
    vva_point_A.x = 3;
    vva_point_A.y = 9;

    // Assigning data values to the data members of 'stuct MyPoint' variable 'point_B'
    vva_point_B.x = 1;
    vva_point_B.y = 2;

    // Assigning data values to the data members of 'stuct MyPoint' variable 'point_C'
    vva_point_C.x = 5;
    vva_point_C.y = 6;

    // Assigning data values to the data members of 'stuct MyPoint' variable 'point_D'
    vva_point_D.x = 8;
    vva_point_D.y = 2;

    // Assigning data values to the data members of 'stuct MyPoint' variable 'point_E'
    vva_point_E.x = 11;
    vva_point_E.y = 8;

    // Displaying data members of 'struct MyPoint' ( all variables)
    printf("\n\n");
    printf("Co-ordinates (x, y) of Point 'A' are : (%d, %d)\n\n", vva_point_A.x, vva_point_A.y);
    printf("Co-ordinates (x, y) of Point 'B' are : (%d, %d)\n\n", vva_point_B.x, vva_point_B.y);
    printf("Co-ordinates (x, y) of Point 'C' are : (%d, %d)\n\n", vva_point_C.x, vva_point_C.y);
    printf("Co-ordinates (x, y) of Point 'D' are : (%d, %d)\n\n", vva_point_D.x, vva_point_D.y);
    printf("Co-ordinates (x, y) of Point 'E' are : (%d, %d)\n\n", vva_point_E.x, vva_point_E.y);

    return (0);
}