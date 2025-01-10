#include <stdio.h>


struct MyPoint
{
    int x;
    int y;
};

int main(void)
{
    // variable declarations
    struct MyPoint point_A_vva, point_B_vva, point_C_vva, point_D_vva, point_E_vva; // declaring 5 struct variables


    //code
    // Use input for the data members of struct 'My Point' variable 'point_A'
    printf("\n\n");
    printf("Enter X-coordinates for point 'A' : ");
    scanf("%d", &point_A_vva.x);
    printf("Enter Y-coordinates for point 'A' : ");
    scanf("%d", &point_A_vva.y);

    // Use input for the data members of 'stuct MyPoint' variable 'point_B'
    printf("\n\n");
    printf("Enter X-coordinates for point 'B' : ");
    scanf("%d", &point_B_vva.x);
    printf("Enter Y-coordinates for point 'B' : ");
    scanf("%d", &point_B_vva.y);

    // Use input for the data members of 'stuct MyPoint' variable 'point_C'
    printf("\n\n");
    printf("Enter X-coordinates for point 'C' : ");
    scanf("%d", &point_C_vva.x);
    printf("Enter Y-coordinates for point 'C' : ");
    scanf("%d", &point_C_vva.y);

    // Use input for thedata members of 'stuct MyPoint' variable 'point_D'
    printf("\n\n");
    printf("Enter X-coordinates for point 'D' : ");
    scanf("%d", &point_D_vva.x);
    printf("Enter Y-coordinates for point 'D' : ");
    scanf("%d", &point_D_vva.y);

    // Use input for the data members of 'stuct MyPoint' variable 'point_E'
    printf("\n\n");
    printf("Enter X-coordinates for point 'E' : ");
    scanf("%d", &point_E_vva.x);
    printf("Enter Y-coordinates for point 'E' : ");
    scanf("%d", &point_E_vva.y);

    // Displaying data members of 'struct MyPoint' ( all variables)
    printf("\n\n");
    printf("Co-ordinates (x, y) of Point 'A' are : (%d, %d)\n\n", point_A_vva.x, point_A_vva.y);
    printf("Co-ordinates (x, y) of Point 'B' are : (%d, %d)\n\n", point_B_vva.x, point_B_vva.y);
    printf("Co-ordinates (x, y) of Point 'C' are : (%d, %d)\n\n", point_C_vva.x, point_C_vva.y);
    printf("Co-ordinates (x, y) of Point 'D' are : (%d, %d)\n\n", point_D_vva.x, point_D_vva.y);
    printf("Co-ordinates (x, y) of Point 'E' are : (%d, %d)\n\n", point_E_vva.x, point_E_vva.y);

    return (0);
}