#include <stdio.h>

enum
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
    int a_vva;
    int b_vva;
    int answer_vva, ret_vva;

    // code
    printf("\n\n");
    printf("Enter value of 'A' : ");
    scanf("%d", &a_vva);

    printf("\n\n");
    printf("Enter value of 'B' : ");
    scanf("%d", &b_vva);

    ret_vva = Difference(a_vva, b_vva, &answer_vva);

    printf("\n\n");
    printf("Difference of %d and %d = %d\n\n", a_vva, b_vva, answer_vva);

    if (ret_vva == POSITIVE)
        printf("The difference of %d and %d is positive !!! \n\n", a_vva, b_vva);
    else if (ret_vva == NEGATIVE)
        printf("The difference of %d and %d is negative !!! \n\n", a_vva, b_vva);
    else
        printf("The difference of %d and %d is zero !!! \n\n", a_vva, b_vva);

    return (0);   
}

// we want out function to perform two jobs..
// one is to subtract input numbers (y_vva from x_vva) and second is to tell whether the difference is positive, negative or zero 
// but any functions has only one return value, then how can we manage to return two values to the calling function?
// This is where parameterized return value comes into picture
// actual difference is returned as parameterized return value and status (+ve, -ve equal) is returned as return value to the function


int Difference(int x_vva, int y_vva, int *diff_vva)
{
    //code
    *diff_vva = x_vva - y_vva;
    if (*diff_vva > 0)
        return (POSITIVE);
    else if (*diff_vva < 0)
        return (NEGATIVE);
    else
        return (ZERO);
}


