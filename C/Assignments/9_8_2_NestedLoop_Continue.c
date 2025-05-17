#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vva, vva_j;

    //code
    printf("\n\n");

    printf("Outer loop prints odd number between 1 to 10 \n\n");
    printf("Outer loop prints even number between 1 to 10 for every even number printed by outer loop \n\n");

    //condition for a number to be even number - division of number by 2 leaves no remainder_vva ( remainder_vva = 0)
    //condition for a number to be odd number - division of number by 2 leaves remainder_vva 1 (usually)

    for (i_vva = 1; i_vva <= 10; i_vva++)
    {
        if (i_vva % 2 != 0) // if number i_vva is ODD
        {
            printf("i_vva = %d\n", i_vva);
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