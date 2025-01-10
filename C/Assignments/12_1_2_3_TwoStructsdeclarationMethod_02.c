#include <stdio.h>

// defining struct 
struct MyPoint
{
    int x;
    int y;
};

//defining struct 
struct MyPointProperties
{
    int quadrant;
    char axis_location[10];
}; 

struct MyPoint vva_point; //declaring a single variable of type 'struct MyPoint' globally
struct MyPointProperties vva_point_properties; //declaring a single variable of type 'struct MyPointProperties' globally

int main(void)
{
    //code
    // user input for the data member of struct MyPoint variable vva_point_A;
    printf("\n\n");
    printf("Enter X-coordinate for A point : ");
    scanf("%d", &vva_point.x);
    printf("Enter Y coordinates for A point : ");
    scanf("%d", &vva_point.y);

    printf("\n\n");
    printf("Point co-ordinates (x, y) are : (%d, %d) !!!\n\n", vva_point.x, vva_point.y);

    if (vva_point.x == 0 && vva_point.y == 0)
    {
        printf("The point is the origin (%d, %d) !!!\n", vva_point.x, vva_point.y);
    }
    // Atleast one of the two values is non zero
    else if (vva_point.x == 0) // If 'X' is zero then 'Y' is the non zero value
    {
        if (vva_point.y < 0) // Y is -ve
            strcpy(vva_point_properties.axis_location, "-veY");
        if (vva_point.y > 0) // Y is +ve
            strcpy(vva_point_properties.axis_location, "+ ve Y");

        vva_point_properties.quadrant = 0; // point on any axis is not in any quadrant
        printf("The point lies on %s Axis !!!\n\n", vva_point_properties.axis_location);
    }
    else if (vva_point.y == 0) // If 'Y' is zero then 'X' is the non zero value
    {
        if (vva_point.x < 0) // X is -ve
            strcpy(vva_point_properties.axis_location, "-veX");
        if (vva_point.x > 0) // X is +ve
            strcpy(vva_point_properties.axis_location, "+ ve X");

        vva_point_properties.quadrant = 0; // point on any axis is not in any quadrant
        printf("The point lies on %s Axis !!!\n\n", vva_point_properties.axis_location);
    }
    else // BOTH X and Y are non zero
    {
        vva_point_properties.axis_location[0] = '\0'; // A point lying in any of the 4 quadrants cannot be lying on any of the co-ordinate axis

        if (vva_point.x > 0 && vva_point.y > 0) // X and Y +ve
            vva_point_properties.quadrant = 1;
        if (vva_point.x < 0 && vva_point.y > 0) // X is -ve and Y is +ve
            vva_point_properties.quadrant = 2;
        if (vva_point.x < 0 && vva_point.y < 0) // X and Y negative
            vva_point_properties.quadrant = 3;            
        if (vva_point.x > 0 && vva_point.y < 0) // X is + ve and Y is negative
            vva_point_properties.quadrant = 4; 
        
        printf("The point lies in quadrant number %d!!!\n\n", vva_point_properties.quadrant);
        
    }

    return (0);
}
