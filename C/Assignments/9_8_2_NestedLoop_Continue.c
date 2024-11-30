#include <stdio.h>

int main(void)
{
    // variable declaration
    int vva_i, vva_j;

    //code
    printf("\n\n");

    printf("Outer loop prints odd number between 1 to 10 \n\n");
    printf("Outer loop prints even number between 1 to 10 for every even number printed by outer loop \n\n");

    //condition for a number to be even number - division of number by 2 leaves no remainder ( remainder = 0)
    //condition for a number to be odd number - division of number by 2 leaves remainder 1 (usually)

    for (vva_i = 1; vva_i <= 10; vva_i++)
    {
        if (vva_i % 2 != 0) // if number vva_i is ODD
        {
            printf("vva_i = %d\n", vva_i);
            printf("----------------------\n");
            for (vva_j = 1; vva_j <= 10; vva_j++)
            {
                if (vva_j % 2 == 0) // if number vva_j i even
                {
                    printf("\tvva_j = %d\n", vva_j);
                }
                else // if vva_j is odd
                {
                    continue;
                }
            }
            printf("\n\n");
        }
        else
        {
            continue;
        }
    }

    printf("\n\n");

    return (0);
}