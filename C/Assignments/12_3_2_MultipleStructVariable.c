#include <stdio.h>


struct MyPoint
{
    int x;
    int y;
};

int main(void)
{
    // variable declarations
    struct MyPoint vva_point_A, vva_point_B, vva_point_C, vva_point_D, vva_point_E; // declaring 5 struct variables


    //code
    // Use input for the data members of struct 'My Point' variable 'point_A'
    printf("\n\n");
    printf("Enter X-coordinates for point 'A' : ");
    scanf("%d", &vva_point_A.x);
    printf("Enter Y-coordinates for point 'A' : ");
    scanf("%d", &vva_point_A.y);

    // Use input for the data members of 'stuct MyPoint' variable 'point_B'
    printf("\n\n");
    printf("Enter X-coordinates for point 'B' : ");
    scanf("%d", &vva_point_B.x);
    printf("Enter Y-coordinates for point 'B' : ");
    scanf("%d", &vva_point_B.y);

    // Use input for the data members of 'stuct MyPoint' variable 'point_C'
    printf("\n\n");
    printf("Enter X-coordinates for point 'C' : ");
    scanf("%d", &vva_point_C.x);
    printf("Enter Y-coordinates for point 'C' : ");
    scanf("%d", &vva_point_C.y);

    // Use input for thedata members of 'stuct MyPoint' variable 'point_D'
    printf("\n\n");
    printf("Enter X-coordinates for point 'D' : ");
    scanf("%d", &vva_point_D.x);
    printf("Enter Y-coordinates for point 'D' : ");
    scanf("%d", &vva_point_D.y);

    // Use input for the data members of 'stuct MyPoint' variable 'point_E'
    printf("\n\n");
    printf("Enter X-coordinates for point 'E' : ");
    scanf("%d", &vva_point_E.x);
    printf("Enter Y-coordinates for point 'E' : ");
    scanf("%d", &vva_point_E.y);

    // Displaying data members of 'struct MyPoint' ( all variables)
    printf("\n\n");
    printf("Co-ordinates (x, y) of Point 'A' are : (%d, %d)\n\n", vva_point_A.x, vva_point_A.y);
    printf("Co-ordinates (x, y) of Point 'B' are : (%d, %d)\n\n", vva_point_B.x, vva_point_B.y);
    printf("Co-ordinates (x, y) of Point 'C' are : (%d, %d)\n\n", vva_point_C.x, vva_point_C.y);
    printf("Co-ordinates (x, y) of Point 'D' are : (%d, %d)\n\n", vva_point_D.x, vva_point_D.y);
    printf("Co-ordinates (x, y) of Point 'E' are : (%d, %d)\n\n", vva_point_E.x, vva_point_E.y);

    return (0);
}