#include <stdio.h>

int main(void)
{
    //variable declarations
    int num_vva;

    //code
    printf("\n\n");

    printf("Enter value for 'num_vva' : ");
    scanf("%d", &num_vva);

    // if else if ladder begins from here..
    if (num_vva < 0)
        printf("num_vva = %d is less than 0 (NEGATIVE) !!! \n\n", num_vva);
    else if ((num_vva > 000) && (num_vva <= 100))
        printf("num_vva = %d is between 000 and 100 !!! \n\n", num_vva);
    else if ((num_vva > 100) && (num_vva <= 200))
        printf("num_vva = %d is between 100 and 200 !!! \n\n", num_vva);
    else if ((num_vva > 200) && (num_vva <= 300))
        printf("num_vva = %d is between 200 and 300 !!! \n\n", num_vva);
    else if ((num_vva > 300) && (num_vva <= 400))
        printf("num_vva = %d is between 300 and 400 !!! \n\n", num_vva);
    else if ((num_vva > 400) && (num_vva <= 500))
        printf("num_vva = %d is between 400 and 500 !!! \n\n", num_vva);
    else if (num_vva > 500)
        printf("num_vva = %d is greater than 500 !!! \n\n", num_vva);
    else // this is the terminating 'else' of this if-else if-else ladder.
        printf("Invalid value entered !!!\n\n");

    return (0);    
}