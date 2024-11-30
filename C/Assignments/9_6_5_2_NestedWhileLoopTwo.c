#include <stdio.h>

int main()
{
    // variable declaration

    int vva_i, vva_j, vva_k;

    //code
    printf("\n\n");

    vva_i = 1;

    while (vva_i <= 10)
    {
        printf("i = %d \n", vva_i);
        printf("---------------------\n\n");

        vva_j = 1;
        while (vva_j <= 5)
        {
            printf("\t j = %d\n", vva_j);
            printf("\t----------------------\n\n");

            vva_k = 1;
            while (vva_k <= 3)
            {
                printf("\t\tk = %d\n", vva_k);
                vva_k++;
            }
            printf("\n\n");
            vva_j++;            
        }
        printf("\n\n");
        vva_i++;  
    }

    return (0);
}