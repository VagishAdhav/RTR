#include <stdio.h>

int main(void)
{
    // variable declaration
    int vva_i, vva_j;


    // code
    printf("\n\n");

    for (vva_i = 1; vva_i <=10; vva_i++)
    {
        printf("i = %d\n", vva_i);
        printf("-----------\n\n");

        for (vva_j = 1; vva_j <=5; vva_j++)
        {
            printf("\tj = %d\n", vva_j);
        }
        printf("\n\n");
    }

    return (0);
}