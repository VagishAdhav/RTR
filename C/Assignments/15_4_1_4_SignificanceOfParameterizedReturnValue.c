#include <stdio.h>

enum_vva
{
    NEGATIVE = -1,
    ZERO,
    POSITIVE
};

int main(void)
{
    // function declarations
    int Difference(int, int, int *);

    // variable declaration
    int a;
    int b;
    int answer, ret;

    // code
    printf("\n\n");
    printf("Enter value of 'A' : ");
    scanf("%d", &a);

    printf("\n\n");
    printf("Enter value of 'B' : ");
    scanf("%d", &b);

    ret = Difference(a, b, &answer);

    printf("\n\n");
    printf("Difference of %d and %d = %d\n\n", a, b, answer);

    if (ret == POSITIVE)
        printf("The difference of %d and %d is positive !!! \n\n", a, b);
    else if (ret == NEGATIVE)
        printf("The difference of %d and %d is negative !!! \n\n", a, b);
    else
        printf("The difference of %d and %d is zero !!! \n\n", a, b);

    return (0);   
}

// we want out function to perform two jobs..
// one is to subtract input num_vvabers (y from x) and second is to tell whether the difference is positive, negative or zero 
// but any functions has only one return value, then how can we manage to return two values to the calling function?
// This is where parameterized return value comes into picture
// actual difference is returned as parameterized return value and status (+ve, -ve equal) is returned as return value to the function


int Difference(int x, int y, int *diff)
{
    //code
    *diff = x - y;
    if (*diff > 0)
        return (POSITIVE);
    else if (*diff < 0)
        return (NEGATIVE);
    else
        return (ZERO);
}


