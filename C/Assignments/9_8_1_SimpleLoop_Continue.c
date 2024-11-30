#include <stdio.h>

int main(void)
{
    // variable declaration
    int vva_i;

    //code 
    printf("\n\n");

    printf("Printing even numbers from 0 to 100 : \n\n");

    for (vva_i = 0; vva_i <= 100; vva_i++)
    {
        // condition for a number to be even number - division of number by 2 leaves no remainder (= 0)
        // if remainder is not 0 the number is odd number
        if (vva_i % 2 != 0)
        {
            continue;
        }
        else
        {
            printf("\t%d\n", vva_i);
        }
    }

    printf("\n\n");


    return (0);
}