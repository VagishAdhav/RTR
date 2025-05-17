#include <stdio.h>

int main(void)
{
    //variable declaration
    int i_vva, j_vva, k_vva;

    //code
    printf("\n\n");

    for (int i_vva = 1; i_vva <= 10; i_vva++)
    {
        printf("i = %d\n", i_vva);
        printf("-----------------\n\n");

        for (j_vva = 1; j_vva <= 5; j_vva++)
        {
            printf("\tj = %d\n", j_vva);
            printf("\t-----------------\n\n");

            for (k_vva = 1; k_vva <= 3; k_vva++)
            {
                printf("\t\tk = %d\n", k_vva);
            }

            printf("\n\n");

        }
        printf("\n\n");
    }

    return (0);
}