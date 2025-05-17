#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vva, j_vva;


    // code
    printf("\n\n");

    for (i_vva = 1; i_vva <=10; i_vva++)
    {
        printf("i = %d\n", i_vva);
        printf("-----------\n\n");

        for (j_vva = 1; j_vva <=5; j_vva++)
        {
            printf("\tj = %d\n", j_vva);
        }
        printf("\n\n");
    }

    return (0);
}