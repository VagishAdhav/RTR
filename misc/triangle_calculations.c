#include <stdio.h>
#include <stdint.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct {
    double x;
    double y;
}point;

typedef struct {
    point ptA;
    point ptB;
    point ptC;
    double lenAB;
    double lenAC;
    double lenBC;
    double angleA;
    double angleB;
    double angleC;
}triangle;

int main (void) {
    
    // variable declarations
    triangle T1;

    double temp_length = 0;
    double temp_slopeAB, temp_slopeBC;

    // read coordinates of point A

    printf("Enter X and Y co-ordinate for FIRST Vertex (A) of the triangle\n");
    scanf("%lf %lf", &T1.ptA.x,  &T1.ptA.y);

    //printf("Enter Y co-ordinate for FIRST Vertex (A) of the triangle\n");
    //scanf("%lf", &T1.ptA.y);

    printf("Enter X and Y co-ordinate for SECOND Vertex (B) of the triangle\n");
    scanf("%lf %lf", &T1.ptB.x, &T1.ptB.y);

    //printf("Enter Y co-ordinate for SECOND Vertex (B) of the triangle\n");
    //scanf("%lf", &T1.ptB.y);

    printf("Enter X and Y co-ordinate for THIRD Vertex (C) of the triangle\n");
    scanf("%lf %lf", &T1.ptC.x, &T1.ptC.y);

    //printf("Enter Y co-ordinate for THIRD Vertex (A) of the triangle\n");
    //scanf("%lf", &T1.ptC.y);

    // validate input 
    // make sure all three points are NOT on collinear
    // slope from line A->B and line B->c should not be same
    // ((y2-y1)/ (x2-x1)) != ((y3-y2)/(x3-x2)) 

    // use cross multiplication to avoid divide by zero
    if ((T1.ptB.y - T1.ptA.y) * (T1.ptC.x - T1.ptB.x) == ((T1.ptC.y - T1.ptB.y) * (T1.ptB.x - T1.ptA.x))) {
        printf("Invalid input, all three points are on same line. Exiting .....\n");
        return 0;
    }

    // calculate length
    T1.lenAB = sqrt((pow((T1.ptB.x - T1.ptA.x), 2) + pow((T1.ptB.y - T1.ptA.y), 2)));
    T1.lenAC = sqrt((pow((T1.ptC.x - T1.ptA.x), 2) + pow((T1.ptC.y - T1.ptA.y), 2)));
    T1.lenBC = sqrt((pow((T1.ptC.x - T1.ptB.x), 2) + pow((T1.ptC.y - T1.ptB.y), 2)));

    // calculat angle

    /* To calculate angle lets draw a perpandicular from point C on line AB
       Lets call the intersection as point 'D'
       So now line AB is AB->DB
           C
          /|\
         / | \
        /  |  \
       A---D---B

       by applying pythagoras formula we can derive following formula for length DB

    */
    temp_length = (pow(T1.lenAB, 2) + pow(T1.lenBC, 2) - pow(T1.lenAC, 2)) / (2 * T1.lenAB); 

    T1.angleB =  acos(temp_length/T1.lenBC);
    T1.angleB = T1.angleB * (180/M_PI);

    // calculate Anngle A using length AD
    temp_length = T1.lenAB - temp_length;
    T1.angleA =  acos(temp_length/T1.lenAC);
    T1.angleA = T1.angleA * (180/M_PI);

    // calculate angle c
    T1.angleC = 180 - T1.angleA - T1.angleB;

    // print the results
    printf("Length AB = %lf\n", T1.lenAB);
    printf("Length AC = %lf\n", T1.lenAC);
    printf("Length BC = %lf\n\n", T1.lenBC);

    printf("Angle A = %lf\n", T1.angleA);
    printf("Angle B = %lf\n", T1.angleB);
    printf("Angle C = %lf\n", T1.angleC);


    return 0;
}