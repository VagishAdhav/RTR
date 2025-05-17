#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vva, vva_j;


    // code
    printf("\n\n");

    for (i_vva = 1; i_vva <=10; i_vva++)
    {
        printf("i = %d\n", i_vva);
        printf("-----------\n\n");

        for (vva_j = 1; vva_j <=5; vva_j++)
        {
            printf("\tj = %d\n", vva_j);
        }
        printf("\n\n");
    }

    return (0);
}