#include <stdio.h>

int main(void)
{
    //variable declaration
    int i_vva, vva_j, vva_k;

    //code
    printf("\n\n");

    for (int i_vva = 1; i_vva <= 10; i_vva++)
    {
        printf("i = %d\n", i_vva);
        printf("-----------------\n\n");

        for (vva_j = 1; vva_j <= 5; vva_j++)
        {
            printf("\tj = %d\n", vva_j);
            printf("\t-----------------\n\n");

            for (vva_k = 1; vva_k <= 3; vva_k++)
            {
                printf("\t\tk = %d\n", vva_k);
            }

            printf("\n\n");

        }
        printf("\n\n");
    }

    return (0);
}