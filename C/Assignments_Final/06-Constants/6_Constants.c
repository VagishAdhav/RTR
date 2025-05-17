#include <stdio.h>

#define VVA_PI  3.1415926535897932

#define AMC_STRING "AstroMediComp RTR-6"

// if first enum is not assigned values then it is assumed to be 0 i.e SUNDAY will be 0
// rest of the enum constants are assigned consecutive integer values from 0 onwards
// i.e. MONDAY will be 1, TUESDAY will be 2 and so on

// un-named enum_vvas 
enum
{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

enum
{
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

// named enum_vvas
enum numbers
{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE = 5,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN
};

enum boolean
{
    TRUE = 1,
    FALSE = 0
};

int main(void)
{
    // local constant declaration 
    const double epsilon_vva = 0.000001;

    //code
    printf("\n\n");
    printf("Local constant epsilon_vva = %lf\n\n", epsilon_vva);

    printf("Sunday is day number = %d\n", SUNDAY);
    printf("Monday is day number = %d\n", MONDAY);
    printf("Tuesday is day number = %d\n", TUESDAY);
    printf("Wednesday is day number = %d\n", WEDNESDAY);
    printf("Thursday is day number = %d\n", THURSDAY);
    printf("Friday is day number = %d\n", FRIDAY);
    printf("Saturday is day number = %d\n\n", SATURDAY);

    printf("One is enum number = %d\n", ONE);
    printf("Two is enum number = %d\n", TWO);
    printf("Three is Enum_vva number = %d\n", THREE);
    printf("Four is enum number = %d\n", FOUR);
    printf("Five is enum number = %d\n", FIVE);
    printf("Six is enum number = %d\n", SIX);
    printf("Seven is enum number = %d\n", SEVEN);
    printf("Eight is enum number = %d\n", EIGHT);
    printf("Nine is enum number = %d\n", NINE);
    printf("Ten is enum number = %d\n\n", TEN);

    printf("January is month number = %d\n", JANUARY);
    printf("February is month number = %d\n", FEBRUARY);
    printf("March is month number = %d\n", MARCH);
    printf("April is month number =  %d\n", APRIL);
    printf("May is month number = %d\n", MAY);
    printf("June is month number = %d\n", JUNE);
    printf("July is month number = %d\n", JULY);
    printf("August is month number = %d\n", AUGUST);
    printf("September is month number = %d\n", SEPTEMBER);
    printf("October is month number = %d\n", OCTOBER);
    printf("November is month number = %d\n", NOVEMBER);
    printf("December is month number = %d\n\n", DECEMBER);

    printf("Value of TRUE is = %d\n", TRUE);
    printf("Value of FALSE is = %d\n", FALSE);

    printf("VVA_PI macro value is = %.10f\n\n", VVA_PI);
    printf("Area of circle of radius 3 units = %f\n\n", (VVA_PI * 3.0f * 3.0f ));// area = pi*r*r

    printf("\n\n");

    printf(AMC_STRING);
    printf("\n\n");    

    printf("AMC_STRING is : %s\n", AMC_STRING);
    printf("\n\n");
}


