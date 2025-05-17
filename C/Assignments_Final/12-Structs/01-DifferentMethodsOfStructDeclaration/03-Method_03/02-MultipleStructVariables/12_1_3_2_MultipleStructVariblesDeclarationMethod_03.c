#include <stdio.h>

int main(void)
{
    // variable declarations
    // defining struct
    struct MyPoint
    {
        int x;
        int y;
    }point_A_vva, point_B_vva, point_C_vva, point_D_vva, point_E_vva; // declaring 5 struct variables of type 'struct MyPoint' locally

    //code
    // Assigning data values to the data members of struct 'My Point' variable 'point_A'
    point_A_vva.x = 3;
    point_A_vva.y = 0;

    // Assigning data values to the data members of 'stuct MyPoint' variable 'point_B'
    point_B_vva.x = 1;
    point_B_vva.y = 2;

    // Assigning data values to the data members of 'stuct MyPoint' variable 'point_C'
    point_C_vva.x = 9;
    point_C_vva.y = 6;

    // Assigning data values to the data members of 'stuct MyPoint' variable 'point_D'
    point_D_vva.x = 8;
    point_D_vva.y = 2;

    // Assigning data values to the data members of 'stuct MyPoint' variable 'point_E'
    point_E_vva.x = 11;
    point_E_vva.y = 8;

    // Displaying data members of 'struct MyPoint' ( all variables)
    printf("\n\n");
    printf("Co-ordinates (x, y) of Point 'A' are : (%d, %d)\n\n", point_A_vva.x, point_A_vva.y);
    printf("Co-ordinates (x, y) of Point 'B' are : (%d, %d)\n\n", point_B_vva.x, point_B_vva.y);
    printf("Co-ordinates (x, y) of Point 'C' are : (%d, %d)\n\n", point_C_vva.x, point_C_vva.y);
    printf("Co-ordinates (x, y) of Point 'D' are : (%d, %d)\n\n", point_D_vva.x, point_D_vva.y);
    printf("Co-ordinates (x, y) of Point 'E' are : (%d, %d)\n\n", point_E_vva.x, point_E_vva.y);

    return (0);
}