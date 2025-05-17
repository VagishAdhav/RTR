#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vva;

    //code 
    printf("\n\n");

    printf("Printing even numbers from 0 to 100 : \n\n");

    for (i_vva = 0; i_vva <= 100; i_vva++)
    {
        // condition for a number to be even number - division of number by 2 leaves no remainder_vva (= 0)
        // if remainder_vva is not 0 the number is odd number
        if (i_vva % 2 != 0)
        {
            continue;
        }
        else
        {
            printf("\t%d\n", i_vva);
        }
    }

    printf("\n\n");


    return (0);
}