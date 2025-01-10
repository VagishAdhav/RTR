#include <stdio.h>

// defining struct 
struct MyPoint
{
    int x;
    int y;
}point_vva; //declaring a single variable of type 'struct MyPoint' globally

//defining struct 
struct MyPointProperties
{
    int quadrant;
    char axis_location[10];
}point_properties_vva; //declaring a single variable of type 'struct MyPointProperties' globally

int main(void)
{
    //code
    // user input for the data member of struct MyPoint variable point_A_vva;
    printf("\n\n");
    printf("Enter X-coordinate for A point : ");
    scanf("%d", &point_vva.x);
    printf("Enter Y coordinates for A point : ");
    scanf("%d", &point_vva.y);

    printf("\n\n");
    printf("Point co-ordinates (x, y) are : (%d, %d) !!!\n\n", point_vva.x, point_vva.y);

    if (point_vva.x == 0 && point_vva.y == 0)
    {
        printf("The point is the origin (%d, %d) !!!\n", point_vva.x, point_vva.y);
    }
    // Atleast one of the two values is non zero
    else if (point_vva.x == 0) // If 'X' is zero then 'Y' is the non zero value
    {
        if (point_vva.y < 0) // Y is -ve
            strcpy(point_properties_vva.axis_location, "Negative Y");
        if (point_vva.y > 0) // Y is +ve
            strcpy(point_properties_vva.axis_location, "Positive Y");

        point_properties_vva.quadrant = 0; // point on any axis is not in any quadrant
        printf("The point lies on %s Axis !!!\n\n", point_properties_vva.axis_location);
    }
    else if (point_vva.y == 0) // If 'Y' is zero then 'X' is the non zero value
    {
        if (point_vva.x < 0) // X is -ve
            strcpy(point_properties_vva.axis_location, "Negative X");
        if (point_vva.x > 0) // X is +ve
            strcpy(point_properties_vva.axis_location, "Positive X");

        point_properties_vva.quadrant = 0; // point on any axis is not in any quadrant
        printf("The point lies on %s Axis !!!\n\n", point_properties_vva.axis_location);
    }
    else // BOTH X and Y are non zero
    {
        point_properties_vva.axis_location[0] = '\0'; // A point lying in any of the 4 quadrants cannot be lying on any of the co-ordinate axis

        if (point_vva.x > 0 && point_vva.y > 0) // X and Y positive
            point_properties_vva.quadrant = 1;
        if (point_vva.x < 0 && point_vva.y > 0) // X is negative  and Y is positive
            point_properties_vva.quadrant = 2;
        if (point_vva.x < 0 && point_vva.y < 0) // X and Y negative
            point_properties_vva.quadrant = 3;            
        if (point_vva.x > 0 && point_vva.y < 0) // X is positive and Y is negative
            point_properties_vva.quadrant = 4; 
        
        printf("The point lies in quadrant number %d!!!\n\n", point_properties_vva.quadrant);
        
    }

    return (0);
}
