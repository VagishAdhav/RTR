#include <stdio.h>

int main(void)
{
    //variable declaration
    int a_vva;
    int b_vva;
    int result_vva;

    // code
    printf("\n\n");
    printf("Enter One integer : ");
    scanf("%d", &a_vva);

    printf("\n\n");
    printf("Enter another integer : ");
    scanf("%d", &b_vva);

    printf("\n\n");
    printf("If answer = 0, is is 'FALSE'\n");
    printf("If answer = 1, is is 'TRUE'\n");

    result_vva = (a_vva < b_vva);
    printf("(a_vva < b_vva) A = %d is less than B = %d  \t Answer = %d\n", a_vva, b_vva, result_vva);

    result_vva = (a_vva > b_vva);
    printf("(a_vva > b_vva) A = %d is greater than B = %d  \t Answer = %d\n", a_vva, b_vva, result_vva);

    result_vva = (a_vva <= b_vva);
    printf("(a_vva <= b_vva) A = %d is less than or equal to B = %d  \t Answer = %d\n", a_vva, b_vva, result_vva);

    result_vva = (a_vva >= b_vva);
    printf("(a_vva >= b_vva) A = %d is greater than or equal to B = %d  \t Answer = %d\n", a_vva, b_vva, result_vva);

    result_vva = (a_vva == b_vva);
    printf("(a_vva < b_vva) A = %d is equal to B = %d  \t Answer = %d\n", a_vva, b_vva, result_vva);

    result_vva = (a_vva != b_vva);
    printf("(a_vva < b_vva) A = %d is NOT equal B = %d  \t Answer = %d\n", a_vva, b_vva, result_vva);

    return (0);
}